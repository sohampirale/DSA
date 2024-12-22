#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
#include<climits>
#include<fstream>
#include<sstream>
#include<list>
#include<filesystem>
#include <csignal>
#include <cstdlib>
#include<unordered_set>

using namespace std;
bool bidirectional=false;

class node{
    public:
        int data;
        bool colored;
        string path="";
        bool traversed=false;
        // vector<node*>connections;
        //            data     addr, dist
        unordered_map<int,pair<node*,int>>connections_map;
        //For Dijekstras
        unordered_map<node*,int>DijekstrasDist;
        int reachedFrom=-1,cost=INT_MAX;

        //For A Star
        unordered_map<node*,int>HeuristicValues;
        int costWithHeuristicValue=INT_MAX;

        node(int data):data(data),colored(false){
            cout<<data<<" created"<<endl;
        }
        
        void connect_to(node*one_node,int dist){
            if(connections_map.find(one_node->data)==connections_map.end()){
                pair<node*,int>temp={one_node,dist};
                connections_map[one_node->data]=temp;
                cout<<this->data<<" is connected with "<<one_node->data<<" with distance : "<<temp.second<<endl;
                if(bidirectional)one_node->connect_to(this,dist);

            } else {
                cout<<"connection of "<<this->data<<" already exists with "<<one_node->data<<endl;
            }
        } 
        
        void display_connections(){
            cout<<this->data<<" is connected with nodes : "<<endl;
            for(auto it = connections_map.begin();it!=connections_map.end();it++){
                cout<<it->second.first->data<<" with distance of "<<it->second.second<<endl;
            }
            cout<<endl;
        }
       
        node* find(vector<node*>&dataset,int data){
            for(auto it=dataset.begin();it!=dataset.end();it++){
                if((*it)->data==data){
                    return *it;
                }
            } 
            return nullptr;
        }
        
        void connect_to_helper(unordered_map<int,node*>&dataset){
            int n;
            cout<<"How many connections does "<<this->data<<" has ? : ";
            cin>>n;
            cout<<"Lets connect "<<this->data<<" with "<<n<<" nodes"<<endl;
            int data,dist;
            for(int i=0;i<n;i++){
                cout<<"Enter data of "<<i+1<<"th connection for "<<this->data<<": ";
                cin>>data;
                cout<<"Enter distance of "<<data<<" from "<<this->data<<" : ";
                cin>>dist;
                node* one_node=dataset[data];
                if(one_node){
                    connect_to(one_node,dist);
                }
            }
        }

        ~node(){
            cout<<"Deleting "<<this->data<<endl;
        }

};

class Graph{
    public:
        class DijekstrasCompare{
            public:     
                bool operator()(const node* n1,const node* n2){
                    return n1->data>n2->data;
                }
        };

        class AStarCompare{
            public:
                bool operator()(const node*n1,const node* n2){
                    return n1->costWithHeuristicValue>n2->costWithHeuristicValue;
                }
        };

        class AStarKIntermediatesCompare{
            public:
                Graph* graphPtr;

                AStarKIntermediatesCompare(Graph *graph){
                    graphPtr=graph;
                }
                bool operator()(node*n1, node* n2){
                    if(graphPtr->source){
                        int n1FromSource=graphPtr->source->HeuristicValues[n1];
                        int n2FromSource=graphPtr->source->HeuristicValues[n2];
                        return n1FromSource<n2FromSource;
                    } 
                    return false;
                }
        };

        class pairIntIntHash{
            public:
                template<class T1,class T2>
                size_t operator()(const pair<T1,T2>p)const{
                    auto h1=hash<T1>{}(p.first);
                    auto h2=hash<T2>{}(p.second);
                    return h1 ^ h2;
                }
        };
        
        unordered_map<int,node*>dataset;
        unordered_map<node*,list<node*>>adjacancy_list;
        unordered_map<node*,unordered_set<node*>>adjacancyList2;
        vector<string>all_paths;
        int min_cost=0;
        string path_with_min_cost;
        node*start=nullptr,*target=nullptr,*intermediate=nullptr;
        static Graph* instance;
        unordered_set<node*>visited;
        unordered_map<node*,string>DijekstrasPath;
        unordered_map<int,unordered_set<int>>visitedPlaces;
        unordered_map<node*,unordered_map<node*,int>>adjacancyMatrixUsingGraph;
        node* destination=nullptr;
        node* source=nullptr;
        vector<vector<int>>matrix;
        bool flag=false;
        friend class AStarKIntermediatesCompare;
        vector<pair<int,int>>fourDirections={{1,0},{-1,0},{0,1},{0,-1}};
        unordered_set<pair<int,int>,pairIntIntHash>visitedLoc;
        unordered_set<pair<int,string>,pairIntIntHash>distinctIslands;
        vector<string>fourDrxn={"d","u","r","l"};

        Graph(){
            signal(SIGSEGV, signalHandler); //  segmentation fault
            signal(SIGTSTP, signalHandler); //  cntl + Z
            instance=this;
        }

        ~Graph(){
            delete_dataset();
        }
       
        static void signalHandler(int signum) {
            cout << "Caught signal " << signum << ". deallocating nodes..." << endl;
            if(instance){
                instance->delete_dataset();
            }
            exit(signum);
        }

        void delete_dataset(){
            cout<<"Deleting Dataset"<<endl;
            for(auto it = this->dataset.begin();it!=dataset.end();it++){
                delete it->second;
            }
        }
        
        void addAddrInQueue(node*&one_node,queue<node*>&loc,queue<int>&costs,int cost){
            if(!one_node)
                return;

            unordered_map<int,pair<node*,int>>&connections_map=one_node->connections_map;

            for(auto it=connections_map.begin();it!=connections_map.end();it++){
                auto add=it->second.first;
                add->path+=("->"+to_string(one_node->data));
                loc.push(add);
                costs.push(cost+it->second.second);
            }
        }

        void BFS_helper(queue<node*>&loc,node*&target,queue<int>&costs,string path="->"){
            if(loc.empty()){
                cout<<"Queue found empty"<<endl;
                return;
            }
            auto it=loc.front();
            string add=to_string(it->data);
            if(it->traversed){
                cout<<"Revisited "<<add<<" via path : "<<it->path+add<<" with cost = "<<costs.front()<<endl;
                return;
            }
            else if(it==target){
                cout<<"Reached target with path : "<<it->path+add<<" & cost = "<<costs.front()<<endl;
                if(costs.front()<min_cost)min_cost=costs.front();
                all_paths.push_back(it->path+add);
                return;
            }
            int size=loc.size();
            for(int i=0;i<size;i++){
                auto front=loc.front();
                addAddrInQueue(front,loc,costs,costs.front());
                if(loc.empty()){
                    it->traversed=false;
                    cout<<"Queue became empty"<<endl;
                    return;
                }
                loc.pop();
                costs.pop();
                BFS_helper(loc,target,costs,it->path+add+"->");
                it->traversed=true;
            }
            it->traversed=false;
        }

        void BFS(node*&start,node*&target){
            min_cost=INT_MAX;
            all_paths.clear();
            queue<node*>loc;
            queue<int>costs;
            costs.push(0);
            loc.push(start);
            start->path="|"+to_string(start->data);
            BFS_helper(loc,target,costs);
            display_all_paths();
            cout<<"For reaching from "<<start->data<<"->"<<target->data<<" : ";
            cout<<"Minimum cost required was : "<<min_cost<<endl;
        }

        void connect_dataset(unordered_map<int,node*>&dataset){
            for(auto it=dataset.begin();it!=dataset.end();it++){
                    it->second->connect_to_helper(dataset);
            }
            cout<<"All nodes connected"<<endl;
        }

        void createGraphManually(unordered_map<int,node*>&dataset){
            int n;
            cout<<"How many nodes you have : ";
            cin>>n;
            vector<int>data(n);
            cout<<"Enter data of "<<n<<" nodes : "<<endl;
            for(int i=0;i<n;i++){
                cin>>data[i];
            }
            for(int i=0;i<n;i++){
                node*one_node=new node(data[i]);
                dataset[data[i]]=one_node;
            }
            cout<<"All nodes created"<<endl;
            this->dataset=dataset;
            connect_dataset(dataset);
            display_all_connections(dataset);
        }

        void extract_data_from_files(unordered_map<int,node*>&dataset){
            fstream file;
            file.open("file_data/first_data.txt",ios::in);
            int n,neighbours,node_data,dist;
            string line;
            if(!file.is_open()){
                cout<<"Error opening the file"<<endl;
                return;
            }
            while(getline(file,line)){
                if(line.empty()||line[0]=='#')continue;
                stringstream ss(line);
                ss>>n;
                cout<<"n = "<<n<<endl;
                break;
            }

            vector<int>data(n);
            cout<<"Data : ";
            while(getline(file,line)){
                if(line.empty()||line[0]=='#')continue;
                stringstream ss(line);
                for(int i=0;i<n;i++){
                    ss>>data[i];
                    cout<<data[i]<<" ";
                }
                cout<<endl;
                break;
            }

            for(int i=0;i<n;i++){
                node*one_node=new node(data[i]);
                dataset[data[i]]=one_node;
            }

            auto connector=dataset.begin();
            while(getline(file,line)){
                if(line.empty()||line[0]=='#')continue;
                stringstream ss(line);
                ss>>neighbours;
                if(neighbours){
                    cout<<"Lets connect "<<connector->first<<" with "<<neighbours<<" neighbours"<<endl;
                    for(int i=0;i<neighbours;i++){
                        ss>>node_data>>dist;
                        node*&one_node=dataset[node_data];
                        connector->second->connect_to(one_node,dist);
                    }
                } else {
                    cout<<connector->first<<" has no neighbours"<<endl;
                }
                connector++;
                if(connector==dataset.end())break;
            }
            cout<<"Extracting file process finished"<<endl;
            file.close();
            this->dataset=dataset;
        }

        void display_all_connections(unordered_map<int,node*>&dataset){
            for(auto node =dataset.begin();node!=dataset.end();node++){
                node->second->display_connections();
            }
        }

        void DFS_helper(stack<node*>&loc,node*target,string path="->",int cost=0){
            if(loc.empty()){
                cout<<"Stack found empty at path : "<<path<<endl;
                all_paths.push_back(path);
                return;
            }
            auto it=loc.top();
            string add=to_string(it->data);
            if(it->traversed){
                // cout<<"revisited "<<add<<" by this path : "<<path+add<<" returnign form here"<<endl;
                all_paths.push_back(path+add);
                return;
            } else if(it==target){
                // cout<<"Found target by path : "<<path+add<<" and with cost = "<<cost<<endl;
                all_paths.push_back(path+add);
                if(cost<min_cost){
                    min_cost=cost;
                    path_with_min_cost=path+add;
                }
                return;
            }
            it->traversed=true;     
            if(!it->connections_map.empty()){
                for(auto front=it->connections_map.begin();front!=it->connections_map.end();front++){
                    loc.push(front->second.first);
                    DFS_helper(loc,target,path+add+"->",cost+front->second.second);
                    loc.pop();
                }
            } else {
                cout<<"Reached dead end at : "<<it->data<<" by path : "<<path+add<<endl;
            }
            it->traversed=false;
        }

        void DFS(node*&start,node*&target){
            min_cost=INT_MAX;
            path_with_min_cost.clear();
            all_paths.clear();
            stack<node*>loc;
            loc.push(start);
            DFS_helper(loc,target);
            // display_all_paths();
            if(min_cost!=INT_MAX){
                cout<<"For reaching from "<<start->data<<"->"<<target->data<<" : ";
                cout<<"Minimum cost required was : "<<min_cost<<endl;
                cout<<"Path with minimum cost is : "<<path_with_min_cost<<endl;
            }
            else cout<<"Not possible to reach "<<target->data<<" from "<<start->data<<endl;
        }

        void display_all_paths(){
            if(all_paths.empty())return;
            for(string str : all_paths){
                cout<<str<<endl;
            }
        }

        int totalGraphsPresent(){
            ifstream total("graphs_data/total_graphs.txt",ios::in);
            int total_graphs;
            if(!total.is_open()){
                cout<<"Error opening the file total_graphs.txt"<<endl;
                return -1;
            }
            total>>total_graphs;
            total.close();
            cout<<"Total grpahs present in the directory currently are : "<<total_graphs<<endl;
            return total_graphs;
        }

        bool isPresent(unordered_map<int,node*>&dataset,int data){
            bool ret= dataset.find(data)!=dataset.end();
            if(!ret)cout<<"No ndoe present in the dataset with data : "<<data<<endl;
            return ret;
        }

        void loadFromFile(ifstream& input,unordered_map<int,node*>&dataset,unordered_map<node*,list<node*>>&map){
            int n,data;
            input>>n;
            for(int i=0;i<n;i++){
                input>>data;
                node* one_node=new node(data);
                dataset[data]=one_node;
                list<node*>temp;
                map[one_node]=temp;
            }
            int mapSize,k,nodeData,neighbourData;
            input>>mapSize;
            for(int i=0;i<mapSize;i++){
                input>>nodeData;
                node* originateNode=dataset[nodeData];
                input>>k;
                for(int j=0;j<k;j++){
                    input>>neighbourData;
                    map[originateNode].push_back(dataset[neighbourData]);
                }
            }
            cout<<"Whole graph loaded from file"<<endl;
        }

        void loadGraph(){
            adjacancy_list.clear();
            delete_dataset();
            visited.clear();
            string path="graphs_data/weighted_graphs/";
            string graphName;
            cout<<"Enter name of the graph to load from "<<path<<" : ";
            cin>>graphName;
            path+=graphName;
            ifstream input(path,ios::in);
            int n,data;
            string line;
            while(getline(input,line)){
                if(line.empty()||line[0]=='/')continue;
                stringstream ss(line);
                ss>>n;
                break;
            }

            while(getline(input,line)){
                if(line.empty()||line[0]=='/')continue;
                stringstream ss(line);
                for(int i=0;i<n;i++){
                    ss>>data;
                    node*one_node=new node(data);
                    dataset[data]=one_node;
                }
                break;
            }
            int k;//no. of neighbours
            int neighbourData,neighbourDist,extra;
            for(int i=0;i<n;i++){
                getline(input,line);
                stringstream ss(line);
                ss>>data;
                ss>>k;
                node*one_node=dataset[data];
                adjacancy_list[one_node];
                adjacancyList2[one_node];
                for(int j=0;j<k;j++){
                    ss>>neighbourData;
                    ss>>neighbourDist;
                    node*neighbour=dataset[neighbourData];
                    adjacancy_list[one_node].push_front(neighbour);
                    adjacancyList2[one_node].insert(neighbour);
                    one_node->connections_map[neighbour->data]={neighbour,neighbourDist};
                }
                cout<<k<<" neighbours connected to node : "<<one_node->data<<endl;
            }
            bool heuristicPresent=true;
            // cout<<"Does this graph have heiristic values? 1 : Yes 0 : No\nYour chocie : ";
            // cin>>heuristicPresent;
            if(heuristicPresent){
                int originData,numberOfNeighbours,neighboursData,heuristicValue;
                for(int t=0;t<dataset.size();t++){
                    getline(input,line);
                    if(line.empty()||line[0]=='#'){
                        t--;
                        continue;
                    }
                    stringstream ss(line);
                    ss>>originData>>numberOfNeighbours;
                    for(int i=0;i<numberOfNeighbours;i++){
                        ss>>neighboursData>>heuristicValue;
                        dataset[originData]->HeuristicValues[dataset[neighboursData]]=heuristicValue;
                    }
                    cout<<dataset[originData]->HeuristicValues.size()<<" values added to the "<<originData<<endl;
                }
            }
            cout<<"Done"<<endl;
            input.close();
        }

        stack<node*>& giveStack(node*&one_node){
            static stack<node*>loc;
            while(!loc.empty())loc.pop();
            loc.push(one_node);
            return loc;
        }

        queue<node*>& giveQueue(node*&one_node){
            static queue<node*>loc;
            while(!loc.empty())loc.pop();
            loc.push(one_node);
            return loc;
        }

        void DFSintermediate(stack<node*>&loc,stack<int>&cost){
            if(loc.empty()){
                cout<<"Stack became empty"<<endl;
                return;
            }
            auto it=loc.top();
            string curr=to_string(it->data);
            if(it->traversed){
                cout<<"Revisited "<<it->data<<" so retunring back"<<endl;
                return;
            } else if(it==intermediate){
                cout<<"Reach intermediate->"<<it->data<<endl;
                bool DFSfirst,changeIntermediate;
                cout<<"Which algorithm to use to reach "<<target->data<<"\n1 : DFS\n0 : BFS\nYour chocie : ";
                cin>>DFSfirst;
                cout<<"DO you want to add any intermediate from "<<it->data<<" to "<<target->data<<"\n1 : Yes 0 : NoY\tYour choice : ";
                cin>>changeIntermediate;

                if(!changeIntermediate){
                    intermediate=nullptr;
                } else {
                    int intermediateData;
                    cout<<"Enter data of the next intermediate : ";
                    cin>>intermediateData;
                    this->intermediate=dataset[intermediateData];
                }

                if(DFSfirst){
                    loc=giveStack(it);
                    stack<int>costs;
                    costs.push(0);
                    DFSintermediate(loc,costs);
                    cout<<"All traversald complete"<<endl;
                    return;
                } else {
                    queue<node*>&loc=giveQueue(it);
                    BFSintermediate(loc);
                     cout<<"All traversald complete"<<endl;
                    return;
                }
            }
            else if(it==target){
                cout<<"Reached the destination -> "<<it->data<<endl;
                return;
            }

            unordered_map<int,pair<node*,int>>&connections_map=it->connections_map;
            int size=connections_map.size();
            int currcost=cost.top();
            loc.pop();
            cout<<"Popping "<<it->data<<" & "<<currcost<<" from stack"<<endl;
            cost.pop();
            it->traversed=true;
            for(auto neighbour=connections_map.begin();neighbour!=connections_map.end();neighbour++){
                loc.push(neighbour->second.first);
                cost.push(neighbour->second.second);
            }
            DFSintermediate(loc,cost);
            it->traversed=false;
        }

        void BFSintermediate(queue<node*>&loc){
            if(loc.empty()){
                cout<<"Queue found empty"<<endl;
                return;
            }
            auto it=loc.front();
            string curr=to_string(it->data);
            if(it->traversed){
                cout<<"Revisited "<<it->data<<" so returning form here"<<endl;
                return;
            } else if(it==intermediate){
                cout<<"Reach intermediate->"<<it->data<<endl;
                bool DFSfirst,changeIntermediate;
                cout<<"Which algorithm to use to reach "<<target->data<<"\n1 : DFS\n0 : BFS\nYour chocie : ";
                cin>>DFSfirst;
                cout<<"DO you want to add any intermediate from "<<it->data<<" to "<<target->data<<"\n1 : Yes 0 : NoY\tYour choice : ";
                cin>>changeIntermediate;

                if(!changeIntermediate){
                    intermediate=nullptr;
                } else {
                    int intermediateData;
                    cout<<"Enter data of the next intermediate : ";
                    cin>>intermediateData;
                    this->intermediate=dataset[intermediateData];
                }

                if(DFSfirst){
                    stack<node*>&loc=giveStack(it);
                    stack<int>cost;
                    cost.push(0);
                    stack<int>costs;
                    costs.push(0);
                    DFSintermediate(loc,costs);
                    cout<<"All traversald complete"<<endl;
                    return;
                } else {
                    queue<int>cost;
                    cost.push(0);
                    loc=giveQueue(it);
                    BFSintermediate(loc);
                    cout<<"All traversald complete"<<endl;
                    return;
                }
            } else if(it==target){
                cout<<"Reached destination -> "<<it->data<<endl;
                return;
            }
            unordered_map<int,pair<node*,int>>&connections_map=it->connections_map;
            cout<<"Popping "<<it->data<<" from queue"<<endl;
            loc.pop();
            it->traversed=true;
            for(auto it=connections_map.begin();it!=connections_map.end();it++){
                loc.push(it->second.first);
            }
            BFSintermediate(loc);
            it->traversed=false;
            cout<<"hi"<<endl;
        }

        void intermediateTraversal(){
            int startData,targetData,intermediateData;
            while(1){
                cout<<"Enter start point : ";
                cin>>startData;
                cout<<"Enter target data : ";
                cin>>targetData;
                cout<<"Enter intermediate data : ";
                cin>>intermediateData;
                if(isPresent(dataset,startData)||isPresent(dataset,targetData)||isPresent(dataset,intermediateData)){
                    this->start=dataset[startData];
                    this->target=dataset[targetData];
                    this->intermediate=dataset[intermediateData];
                    break;
                } else {
                    cout<<"Invalid node selected. Enter agian : "<<endl;
                    continue;
                }
            }
        
            
            bool DFSfirst;
            cout<<"Which alogorithm you want to use first :\n1 : DFS\n0 : BFS\nYour choice : ";
            cin>>DFSfirst;
            if(DFSfirst){
                stack<node*>&loc=giveStack(start);
                stack<int>costs;
                costs.push(0);
                DFSintermediate(loc,costs);
            } else {
                queue<node*>&loc=giveQueue(start);
            }
            cout<<"Came out of intermediateTraversal()"<<endl;
        }
        
        void intermediateTraversal2(){
            int startData,targetData,intermediateData,k;
            vector<bool>traversals;
            vector<node*>intermediates;
            // while(1){
            bool temp;
            cout<<"Enter start point : ";
            cin>>startData;
            cout<<"Enter target data : ";
            cin>>targetData;
            if(isPresent(dataset,startData)||isPresent(dataset,targetData)){
                this->start=dataset[startData];
                this->target=dataset[targetData];
                // break;
            } else {
                cout<<"Invalid node selected. Enter agian : "<<endl;
                // continue;
            }

            cout<<"How many breaks you have scheduled from : "<<startData<<"->"<<targetData<<" : ";
            cin>>k;
            // traversals.resize(k);
            intermediates.resize(k,nullptr);
            int curr=startData;
            for(int i=0;i<k;i++){
                cout<<"Enter data of intermediate no - "<<i+1<<" : ";
                cin>>intermediateData;
                intermediates[i]=dataset[intermediateData];
                cout<<"Which traversal to use from "<<curr<<"->"<<intermediateData<<"?\n1 : DFS 0 : BFS\nYour chocie : ";
                cin>>temp;
                traversals.push_back(temp);
                curr=intermediateData;
            }
            bool temp2;
            cout<<"Which traversal to use from "<<intermediates.back()->data<<"->"<<target->data<<"?\n1 : DFS 0 : BFS\nYour chocie : ";
            cin>>temp2;
            intermediates.push_back(target);
            traversals.push_back(temp2);
            int totalMinCost=0;
            cout<<"traversals.size() = "<<traversals.size() <<" & intermediates.size() = "<<intermediates.size()<<endl;
            stack<node*>&st=giveStack(start);
            queue<node*>&qu=giveQueue(start);
            for(int i=0;i<=k;i++){
                // min_cost=INT_MAX;
                if(traversals[i]){
                    cout<<"Hi"<<endl;
                    if(i==0)DFS(start,intermediates[i]);
                    else DFS(intermediates[i-1],intermediates[i]);
                    if(min_cost==INT_MAX){
                        cout<<"Not possible to reach "<<intermediates[i]->data<<" from ";
                        if(i==0){
                            cout<<start->data<<endl;
                            intermediates[i]=start;
                        }
                        else{
                            cout<<intermediates[i-1]->data<<endl;
                            intermediates[i]=intermediates[i-1];
                        }

                        continue;
                    }
                    totalMinCost+=min_cost;
                    cout<<"totalMinCost = "<<totalMinCost<<endl;
                    // if(i!=0)cout<<"Reached "<<intermediates[i]->data<<" from "<<intermediates[i-1]->data<<endl;
                    // else cout<<"Reached "<<intermediates[i]->data<<" from "<<start->data<<endl;
                } else {
                    if(i==0)BFS(start,intermediates[i]);
                    else BFS(intermediates[i-1],intermediates[i]);
                    if(min_cost==INT_MAX){
                        cout<<"Not possible to reach "<<target->data<<" from "<<start->data<<endl;
                        return;
                    }
                    // BFS_helper(qu,intermediates[i],costs,path_with_min_cost);
                    totalMinCost+=min_cost;
                    cout<<"totalMinCost = "<<totalMinCost<<endl;
                    // if(i!=0)cout<<"Reached "<<intermediates[i]->data<<" from "<<intermediates[i-1]->data<<endl;
                    // else cout<<"Reached "<<intermediates[i]->data<<" from "<<start->data<<endl;
                }
            }
            cout<<"After all traversals totalMinCost  = "<<totalMinCost<<endl;
        }

        void displayAdjacancyList(){
            cout<<"Adjacancy List is : "<<endl;
            for(auto it=adjacancy_list.begin();it!=adjacancy_list.end();it++){
                cout<<it->first->data<<" : ";
                for(auto neighbour=it->second.begin();neighbour!=it->second.end();neighbour++){
                    cout<<"->"<<(*neighbour)->data;
                }
                cout<<endl;
            }
        }

        void displayAdjacancyList2(){
            cout<<"Adjacancy List2 is : "<<endl;
            for(auto it=adjacancyList2.begin();it!=adjacancyList2.end();it++){
                cout<<it->first->data<<" : ";
                for(auto neighbour=it->second.begin();neighbour!=it->second.end();neighbour++){
                    cout<<"->"<<(*neighbour)->data;
                }
                cout<<endl;
            }
        }

        void BFSnoOfDisconnectedComponents(queue<node*>&loc){
            if(loc.empty()){
                cout<<"Queue found empty.Traversal complete."<<endl;
                return;
            }
            auto it=loc.front();
            loc.pop();
            if(visited.find(it)==visited.end()){
                visited.insert(it);
                for(auto neighbour =adjacancy_list[it].begin();neighbour!=adjacancy_list[it].end();neighbour++){
                    loc.push(*neighbour);
                }
            } 
            BFSnoOfDisconnectedComponents(loc);
        }

        void DFSnoOfDisconnectedComponents(stack<node*>&loc){
            if(loc.empty()){
                cout<<"Stack is empty.All traversals complete"<<endl;
                return;
            }
            auto it=loc.top();
            loc.pop();
            if(visited.find(it)==visited.end()){
                visited.insert(it);
                list<node*>&listRef=adjacancy_list[it];
                for(auto neighbour=listRef.begin();neighbour!=listRef.end();neighbour++){
                    loc.push(*neighbour);
                }
            }
            DFSnoOfDisconnectedComponents(loc);
        }

        bool DFSnoOfDisconnectedComponents2(node*one_node){
            if(visited.find(one_node)!=visited.end())return false;
            visited.insert(one_node);
            for(auto neighbour=adjacancy_list[one_node].begin();neighbour!=adjacancy_list[one_node].end();neighbour++){
                DFSnoOfDisconnectedComponents2(*neighbour);
            }
            return true;
        }

        int noOfDisconnectedComponents(){
            displayAdjacancyList();
            visited.clear();
            int total=0,choice;
            bool useBoolReturnFunction;
            cout<<"Which fucntion to use(1 : Returns bool 0 : Void type)\nYour choice : ";
            cin>>useBoolReturnFunction;

            if(useBoolReturnFunction){
                if(choice==1){
                    for(auto it=adjacancy_list.begin();it!=adjacancy_list.end();it++){
                        if(DFSnoOfDisconnectedComponents2(it->first)){
                            total++;
                        }
                    }
                } 
                cout<<"Number of disconnected components are : "<<total<<endl;
            } else {
                cout<<"Find answer via: 1 : DFS\n2 : BFS \nYour choice : ";
                cin>>choice;
                for(auto it=adjacancy_list.begin();it!=adjacancy_list.end();it++){
                    if(visited.find(it->first)==visited.end()){
                        total++;
                        if(choice==1){
                            stack<node*>loc;
                            loc.push(it->first);
                            DFSnoOfDisconnectedComponents(loc);
                        } else if(choice==2){
                            queue<node*>loc;
                            loc.push(it->first);
                            BFSnoOfDisconnectedComponents(loc);
                        }
                    }
                }
                
                cout<<"Total no of disocnnected components in thsi graph are : "<<total<<endl;
            }
            
            
            return total;
        }

        void createAdjacancyList(){
            adjacancy_list.clear();
            for(auto it=dataset.begin();it!=dataset.end();it++){
                adjacancy_list[it->second];
                adjacancyList2[it->second];
                for(auto neighbour=it->second->connections_map.begin();neighbour!=it->second->connections_map.end();neighbour++){
                    adjacancyList2[it->second].insert(neighbour->second.first);
                    adjacancy_list[it->second].push_front(neighbour->second.first);
                }
            }
            cout<<"Adjacancy list created"<<endl;
        }

        bool DFSlargestComponent(node*one_node,int &total){
            if(visited.find(one_node)!=visited.end())return false;
            visited.insert(one_node);
            total++;
            for(auto neighbour=adjacancy_list[one_node].begin();neighbour!=adjacancy_list[one_node].end();neighbour++){
                DFSlargestComponent(*neighbour,total);
            }
            return true;
        }

        int DFSlargestComponentCount(node*one_node){
            if(visited.find(one_node)!=visited.end())return 0;
            visited.insert(one_node);
            int cnt=1;
            for(auto neighbour=adjacancy_list[one_node].begin();neighbour!=adjacancy_list[one_node].end();neighbour++){
                cnt+=DFSlargestComponentCount(*neighbour);
            }
            return cnt;
        }

        int largestComponent(){
            visited.clear();
            int total=0,maxC=0,minC=INT_MAX;
            int m;
            node *minComponentStart=nullptr,*maxComponentStart=nullptr;
            cout<<"Which method to use \n1 : Bool\n2 : Int return type\nYour choice  : ";
            cin>>m;
            if(m==1){

            for(auto it=adjacancy_list.begin();it!=adjacancy_list.end();it++){
                total=0;
                if(DFSlargestComponent(it->first,total)){
                    cout<<"Traversed thorugh : "<<it->first->data<<endl;
                    if(total>maxC)maxC=(total);
                }
            }
            cout<<"Largest component has "<<maxC<<" nodes"<<endl;
            return maxC;
            } else if(m==2){
                for(auto it=adjacancy_list.begin();it!=adjacancy_list.end();it++){
                    if(visited.find(it->first)==visited.end()){
                        cout<<"traversed through "<<it->first->data<<endl;
                        int cnt=DFSlargestComponentCount(it->first);
                        if(cnt>maxC){maxC=cnt;  maxComponentStart=it->first;}
                        if(cnt<minC){minC=cnt;  minComponentStart=it->first;}
                    }
                } 
                cout<<"Minimum component has "<<minC<<" nodes from : "<<minComponentStart->data<<endl;
                cout<<"Maximum component has "<<maxC<<" nodes from : "<<maxComponentStart->data<<endl;
            }
            return maxC;
        }

        bool DFSisCyclePresent(node*&one_node,unordered_set<node*>&currVisited){
            if(!one_node)return false;
            else if(currVisited.find(one_node)!=currVisited.end())return true;

            currVisited.insert(one_node);
            bool result=false;
            for(auto it=one_node->connections_map.begin();it!=one_node->connections_map.end();it++){
                result= result || DFSisCyclePresent(it->second.first,currVisited);
            }
            return result;
        }

        bool DFSisCyclePresentUndirected(node*&one_node,unordered_set<node*>&currVisited,node*parent){

            if(currVisited.find(one_node)!=currVisited.end())return true;
            currVisited.insert(one_node);
            bool result=false;
            for(auto it=one_node->connections_map.begin();it!=one_node->connections_map.end();it++){
                if(it->second.first==parent)continue;
                result= result || DFSisCyclePresentUndirected(it->second.first,currVisited,one_node);
            }
            return result;
        }

        bool isCyclePresent(){
            bool undirected=false;
            cout<<"Is graph undirected ? : ";
            cin>>undirected;
            if(undirected){
                unordered_set<node*>currVisited,prevVisited;
                for(auto it=dataset.begin();it!=dataset.end();it++){
                    if(prevVisited.find(it->second)==prevVisited.end()){
                        if(DFSisCyclePresentUndirected(it->second,currVisited,nullptr)){
                            cout<<"Cycle found for "<<it->second->data<<endl;
                            return true;
                        }
                        else {
                            prevVisited.insert(currVisited.begin(),currVisited.end());
                            currVisited.clear();
                        }
                    }
                }
                return false;
            } else {
                unordered_set<node*>currVisited,prevVisited;
                for(auto it=dataset.begin();it!=dataset.end();it++){
                    if(prevVisited.find(it->second)==prevVisited.end()){
                        if(DFSisCyclePresent(it->second,currVisited)){
                            cout<<"Cycle found for "<<it->second->data<<endl;
                            return true;
                        }
                        else {
                            prevVisited.insert(currVisited.begin(),currVisited.end());
                            currVisited.clear();
                        }
                    }
                }
                return false;
            }
        }

        void DijeskstrasHelper(node*&one_node,unordered_map<node*,int>&table,string path){
            
            if(!one_node){
                cout<<"one_node == nullptr"<<endl;
                return;
            }else if(visited.find(one_node)!=visited.end()){
                return;
            }
            // unordered_set<node*>visitedTemp=visited;
            visited.insert(one_node);
            int nextMin=INT_MAX;
            node*next_node=nullptr;
            queue<node*>loc;

            for(auto it=one_node->connections_map.begin();it!=one_node->connections_map.end();it++){
                
                int nextDist=table[one_node]+it->second.second;
                if(visited.find(it->second.first)==visited.end()){
                    // cout<<"Next distance for "<<it->first<<" from "<<one_node->data<<" is : "<<nextDist<<endl;
                    // cout<<"nextDist for "<<one_node->data<<" to "<<it->second.first->data<<" = "<<nextDist<<endl;
                    if(nextDist<=nextMin){
                        // next_node=it->second.first;
                        if(nextMin==nextDist)loc.push(it->second.first);
                        else {
                            while(!loc.empty())loc.pop();
                            loc.push(it->second.first);
                        }
                        nextMin=nextDist;
                    }
                    if(table.find(it->second.first)==table.end()){
                        table[it->second.first]=nextDist;
                        // DijekstrasPath[it->second.first]=path+"->"+to_string(it->second.first->data);
                        // cout<<"setting value for "<<it->first<<" = "<<table[it->second.first]<<" & path = "<<paths[it->second.first]<<endl;
                    } else {
                        if(table[it->second.first]>nextDist){
                            // cout<<"updating value of "<<it->first<<" from "<<table[it->second.first]<<" to ";
                            table[it->second.first]=nextDist;
                            // if(DijekstrasPath.find(it->second.first)!=DijekstrasPath.end())
                            //     DijekstrasPath[it->second.first]=path+"->"+to_string(it->second.first->data);
                            // else 
                            //     DijekstrasPath[it->second.first]=DijekstrasPath[one_node]+"->"+to_string(it->second.first->data);
                            // cout<<table[it->second.first]<<" & path = "<<DijekstrasPath[it->second.first]<<endl;
                        } else {
                            // cout<<"Keeping value for "<<it->first<<" as it is i.e. ("<<table[it->second.first]<<")"<<" & path = "<<paths[it->second.first]<<endl;
                        }
                    }
                } 
                else {
                    // cout<<it->second.first->data<<" is said visited for "<<one_node->data<<endl;
                }
            }
            
            // if(loc.size()!=1)cout<<"loc.size() == "<<loc.size()<<" for "<<one_node->data<<endl;
            while(!loc.empty()){
                cout<<"traversing to "<<loc.front()->data<<" from "<<one_node->data<<endl;
                DijeskstrasHelper(loc.front(),table,path+"->"+to_string(loc.front()->data));
                // visited.erase(loc.front());
                loc.pop();
            }
        }

        void displayDijeskstrasTable(unordered_map<node*,int>&table){
            cout<<"Dijekstra's Table is : "<<endl;
            for(auto it=table.begin();it!=table.end();it++){
                cout<<it->first->data<<" : "<<it->second<<endl;
            }
        }
        
        void Dijeskstras(){
            all_paths.clear();
            visited.clear();
            unordered_map<node*,int>table;
            unordered_map<node*,string>paths;
            int data,choice;
            cout<<"Which Dijekstra's to implement \n1 : With Priority Queue\n2 : Without priority queue\nYour choice : ";
            cin>>choice;
            if(choice==1){
                priority_queue<node*,vector<node*>,DijekstrasCompare>loc;
                cout<<"Size of dataset = "<<dataset.size()<<endl;
                for(auto it=dataset.begin();it!=dataset.end();it++){
                    loc.push(it->second);
                    it->second->cost=0;
                    DijekstrasUsingPriorityQueue(loc,visited);
                    for(auto all_nodes=dataset.begin();all_nodes!=dataset.end();all_nodes++){
                        it->second->DijekstrasDist[all_nodes->second]=all_nodes->second->cost;
                        all_nodes->second->cost=INT_MAX;
                    }
                    cout<<"Dijesktra's table created for "<<it->second->data<<" size = "<<it->second->DijekstrasDist.size()<<endl;
                    displayDijeskstrasTable(it->second->DijekstrasDist);
                    while(!loc.empty())
                        loc.pop();
                    visited.clear();
                }
                cout<<"Dijesktra's for all nodes is done"<<endl;
            }   else if(choice==2){
                for(auto it=dataset.begin();it!=dataset.end();it++){
                    table.clear();
                    table[it->second]=it->first;
                    DijeskstrasHelper(it->second,table,"St->");
                    it->second->DijekstrasDist=table;
                    cout<<"After performing Dijekstras for "<<it->first<<" the table lokos like : "<<endl;
                    displayDijeskstrasTable(table);
                    table.clear();
                }
                cout<<"Dijekstra for all nodes is done"<<endl;
                // cout<<"From whcih node you want to start Dijesktras's : ";
                // cin>>data;
                // node*start=dataset[data];
                // // for(auto it=dataset.begin();it!=dataset.end();it++){
                // // if(visited.find(it->second)==visited.end()){
                // table[start]=0;
                // DijeskstrasHelper(start,table,to_string(start->data));
                // }
                // }
            }
            cout<<"All process of Dijeskstra's is completed"<<endl;
            // displayDijeskstrasTable(table);
        }

        void DisplayDijekstrasTableOfANode(){
            int data;
            cout<<"Enter data of node you want to see Dijekstra's table of : ";
            cin>>data;
            node*one_node=dataset[data];
            displayDijeskstrasTable(one_node->DijekstrasDist);
        }

        void DijekstrasUsingPriorityQueue(priority_queue<node*,vector<node*>,DijekstrasCompare>&loc,unordered_set<node*>&visited,node*target=nullptr){

            if(loc.empty()){
                cout<<"Queue found empty"<<endl;
                return;
            }

            while(!loc.empty()&&visited.find(loc.top())!=visited.end())
                loc.pop();
            if(loc.empty()){
                cout<<"queue made empty"<<endl;
                return;
            }
            node* current_node=loc.top();
            if(current_node==target){
                flag=true;
                cout<<"FOund target"<<endl;
                return;
            }
            loc.pop();
            visited.insert(current_node);
            for(auto it=current_node->connections_map.begin();it!=current_node->connections_map.end();it++){
                if(flag)return;
                if(visited.find(it->second.first)==visited.end()){
                    int newCost=current_node->cost+it->second.second;
                    if(newCost<it->second.first->cost){
                        it->second.first->cost=newCost;
                        it->second.first->reachedFrom=current_node->data;
                        loc.push(it->second.first);
                    }
                }
            }
            DijekstrasUsingPriorityQueue(loc,visited);
        }

        void DijekstrasPointToPoint(){
            int Start,Destination;
            cout<<"Enter start point data : ";
            cin>>Start;
            cout<<"Enter destination data : ";
            cin>>Destination;
            node*start=dataset[Start];
            node*destination=dataset[Destination];
            cout<<"The minimum distance required to reach "<<Destination<<" from "<<Start<<" is : "<<start->DijekstrasDist[destination]<<endl;
        }

        void DijekstrasOneToOne(){
            visited.clear();
            int startData,destinationData;
            cout<<"Enter data of start ndoe : ";
            cin>>startData;
            cout<<"Enter destination data : ";
            cin>>destinationData;
            node* start=dataset[startData];
            priority_queue<node*,vector<node*>,DijekstrasCompare>loc;
            loc.push(start);
            DijekstrasUsingPriorityQueue(loc,visited);
            cout<<"Dijekstras Traversal done"<<endl;
            cout<<"Lets print path"<<endl;
            int curr=destinationData;
            while(curr!=startData){
                cout<<curr<<"<-";
                curr=dataset[curr]->reachedFrom;
            }
            cout<<startData<<endl;
            cout<<"out of while loop"<<endl;
        }

        void loadHeuristicalValues(string path){
            ifstream input(path,ios::in);
            string line;
            int n;
            int originData,numberOfNeighbours,neighboursData,heuristicValue;
            while(getline(input,line)){
                if(line.empty()||line[0]=='#')continue;
                stringstream ss(line);
                ss>>originData;
                ss>>numberOfNeighbours;
                for(int i=0;i<numberOfNeighbours;i++){
                    ss>>neighboursData>>heuristicValue;
                    dataset[originData]->HeuristicValues[dataset[neighboursData]]=heuristicValue;
                }
            }

        }

        void displayHeuristicValuesOfANode(node*one_node=nullptr){
            int data;
            if(nullptr){
                cout<<"Enter node data whom heuristic values you wish to see : ";
                cin>>data;
                one_node=dataset[data];
            }
            cout<<"Heuristic value of "<<one_node->data<<" from other nodes is : "<<endl;
            for(auto it=one_node->HeuristicValues.begin();it!=one_node->HeuristicValues.end();it++){
                cout<<"From "<<it->first->data<<" is <---> "<<it->second<<endl;
            }
        }

        void AStartHelper(priority_queue<node*,vector<node*>,AStarCompare>&loc){    

            while(!loc.empty()&&visited.find(loc.top())!=visited.end()){
                loc.pop();
            }

            if(loc.empty()){
                cout<<"Queue found empty"<<endl;
                return;
            }

            node*current_node=loc.top();
            if(current_node==destination){
                cout<<"Reached destination"<<endl;
                return;
            }

            visited.insert(current_node);
            loc.pop();

            for(auto it=current_node->connections_map.begin();it!=current_node->connections_map.end();it++){

                if(visited.find(it->second.first)==visited.end()){
                    // cout<<"Looking for "<<it->first<<endl;
                    int newCost=current_node->cost+it->second.second+it->second.first->HeuristicValues[destination];
                    if(it->second.first->costWithHeuristicValue>newCost){
                        it->second.first->costWithHeuristicValue=newCost;
                        it->second.first->reachedFrom=current_node->data;
                        it->second.first->cost=current_node->cost+it->second.second;
                        loc.push(it->second.first);
                    }
                } else {
                    // cout<<it->first<<" is already visited by "<<it->second.first->reachedFrom-1<<endl;
                }
            }

            AStartHelper(loc);

        }

        void AStar(){
            for(auto it=dataset.begin();it!=dataset.end();it++){
                it->second->costWithHeuristicValue=INT_MAX;
                it->second->cost=INT_MAX;
            }
            //c1
            visited.clear();
            start=nullptr;
            destination=nullptr;
            int startData,destinationData;
            cout<<"Enter data of the start point : ";
            cin>>startData;
            start=dataset[startData];
            cout<<"Enter Destination data : ";
            cin>>destinationData;
            destination=dataset[destinationData];
            // start->costWithHeuristicValue=destination->HeuristicValues[start];
            start->costWithHeuristicValue=start->HeuristicValues[destination];
            start->cost=0;
            cout<<"start->costWithHeuristicValue = "<<start->costWithHeuristicValue<<endl;
            cout<<"start->cost = "<<start->cost<<endl;
            priority_queue<node*,vector<node*>,AStarCompare>loc;
            loc.push(start);
            cout<<loc.top()->data<<" is at the top let's start AStar"<<endl;
            AStartHelper(loc);
            cout<<"AStar Algorithm Done"<<endl;
            cout<<"destination("<<destination->data<<")->costWithHeuristicValue = "<<destination->costWithHeuristicValue<<endl;
            cout<<"destination->cost = "<<destination->cost<<endl;
            cout<<"All the nodes traversed are : ";
            for(auto it=visited.begin();it!=visited.end();it++){
                cout<<(*it)->data<<" ";
            }
            cout<<endl;
            visited.clear();
        }

        void displayHeuristicValuesOfAllNodes(){
            for(auto it=dataset.begin();it!=dataset.end();it++){
                displayHeuristicValuesOfANode(it->second);
            }
        }

        void helperBelmonFordTry3(node*&one_node,node*&parent,unordered_map<int,int>&map2){
            if(visited.find(one_node)!=visited.end()){
                // cout<<"Coming back from "<<one_node->data<<endl;
                return;
            }
            else visited.insert(one_node);

            for(auto it=one_node->connections_map.begin();it!=one_node->connections_map.end();it++){
                // if(it->second.first!=parent){                    //  fails to detect negative edge cycles if we add this 
                    int newCost=one_node->cost+it->second.second;
                    if(it->second.first->cost==INT_MAX){
                        flag=true;
                        map2[it->first]=newCost;
                        // it->second.first->cost=newCost;
                        continue;
                    } else if(it->second.first->cost>newCost) {
                        flag=true;
                        map2[it->first]=newCost;
                        // it->second.first->cost=newCost;
                    }
                    // cout<<"Going through : "<<it->first<<endl;
                    helperBelmonFordTry3(it->second.first,one_node,map2);
                // }
            }
        }

        void helperBelmonFordTry2(unordered_map<int,int>&map2){
            for(auto it=dataset.begin();it!=dataset.end();it++){
                for(auto neighbours=it->second->connections_map.begin();neighbours!=it->second->connections_map.end();neighbours++){
                    if(it->second->cost==INT_MAX)continue;

                    int newDist=it->second->cost+neighbours->second.second;
                    if(newDist<neighbours->second.first->cost){
                        // neighbours->second.first->cost=newDist;
                        flag=true;
                        map2[neighbours->first]=newDist;
                    }
                }
            }
        }

        void helperBelmanFord(node*& one_node,node*parent=nullptr){
            for(auto it=one_node->connections_map.begin();it!=one_node->connections_map.end();it++){
                if(it->second.first!=parent){
                    cout<<"Checking for "<<it->first<<endl;
                    int newDist=one_node->cost+it->second.second;
                    cout<<"newDist = "<<newDist<<endl;
                    if(it->second.first->cost==INT_MAX){
                        flag=true;
                        cout<<"Relaxed distance between "<<one_node->data<<" -> "<<it->first<<endl;
                        it->second.first->cost=newDist;
                        continue;
                    } else if(it->second.first->cost<newDist) {
                        flag=true;
                        it->second.first->cost=newDist;
                        cout<<"Relaxed distance betweenn "<<one_node->data<<" -> "<<it->first<<endl;
                    }
                    helperBelmanFord(it->second.first,one_node);
                }
            }
        }
    
        void BelmanFord(){
            for(auto it=dataset.begin();it!=dataset.end();it++){
                it->second->cost=INT_MAX;
            }
            int startData,destinationData;
            cout<<"Enter data of start node : ";
            cin>>startData;
            cout<<"Enter data of destination node : ";
            cin>>destinationData;
            start=dataset[startData];
            start->cost=0;
            destination=dataset[destinationData];
            int maxNoOfRelaxation=dataset.size()-1;
            unordered_map<int,int>map2;
            node*temp=new node(-5);
            int method;
            cout<<"Which method you want to use :\n1 ,2,3\nYour choice : ";
            cin>>method;
            if(method==1){
                //helperBelmonFord
                for(int i=0;i<maxNoOfRelaxation;i++){
                    helperBelmanFord(start);
                }
            } else if(method==2){
                //helperBelmonFordTry2 
                for(int i=0;i<maxNoOfRelaxation;i++){
                    helperBelmonFordTry2(map2);
                    for(auto it=map2.begin();it!=map2.end();it++){
                        dataset[it->first]->cost=map2[it->first];
                    }
                    map2.clear();
                }
            } else if(method==3){
                //helperBelmonFordTry3
                for(int i=0;i<maxNoOfRelaxation;i++){
                    helperBelmonFordTry3(start,temp,map2);
                    visited.clear();
                    for(auto it=map2.begin();it!=map2.end();it++){
                        dataset[it->first]->cost=it->second;
                    }
                    map2.clear();
                }
            }
        
            flag=false;
  
            {
                cout<<"Belmon ford completed for "<<maxNoOfRelaxation<<" times"<<endl;
                cout<<"Destination: "<<destinationData<<" reached with cost = "<<destination->cost<<endl;
                cout<<"Lets test if there exit any negative edge cycles"<<endl;
                // cout<<"Distances of all nodes from start after "<<maxNoOfRelaxation<<" are : "<<endl;
                // for(auto it=dataset.begin();it!=dataset.end();it++){
                //     cout<<it->first<<" : "<<it->second->cost<<endl;
                // }
            }
            
            if(method==1)helperBelmanFord(start);
            else if(method==2)helperBelmonFordTry2(map2);
            else if(method==3)helperBelmonFordTry3(start,temp,map2);

            if(flag){
                cout<<"Negative edge cycles present in this graph!!!!"<<endl;
            } else {
                cout<<"No negative edge cycles present"<<endl;
            }
            
            cout<<"Destination: "<<destinationData<<" reached with cost = "<<destination->cost<<endl;
            delete temp;
        }

        void displayMatrix(vector<vector<int>>&matrix){
            cout<<"Matrix is : "<<endl;
            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[i].size();j++){
                    cout<<matrix[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        bool BFSInMatrix(vector<vector<int>>&matrix,queue<int>&loc,unordered_set<int>&visitedNodes){
            if(loc.empty())return true;
            int element=loc.front();
            loc.pop();
            if(visitedNodes.find(element)!=visitedNodes.end()){
                BFSInMatrix(matrix,loc,visitedNodes);
                return false;
            } else {
                visitedNodes.insert(element);
            }
            for(int i=0;i<matrix[element-1].size();i++){
                if((i+1)!=element&&matrix[element-1][i]==1){
                    loc.push(i+1);
                }
            }
            BFSInMatrix(matrix,loc,visitedNodes);
            return true;
        }

        bool DFSInMatrix(vector<vector<int>>&matrix,int element,unordered_set<int>&visitedNodes){
            // cout<<"hi"<<endl;
            if(visitedNodes.find(element)!=visitedNodes.end())return false;
            else visitedNodes.insert(element);
            for(int i=0;i<matrix[element-1].size();i++){
                if((i+1)!=element&&matrix[element-1][i]==1){
                    cout<<"Going through "<<i+1<<endl;
                    DFSInMatrix(matrix,i+1,visitedNodes);
                }
            }
            return true;
        }

        int noOfComponentsViaMatrix(){
            vector<vector<int>>matrix(dataset.size(),vector<int>(dataset.size(),0));
            cout<<"All elements in the graph must be from 1-n"<<endl;
            for(auto it=dataset.begin();it!=dataset.end();it++){
                int sourceLoc=it->first-1;
                matrix[sourceLoc][sourceLoc]=1;
                for(auto neighbour=it->second->connections_map.begin();neighbour!=it->second->connections_map.end();neighbour++){
                    matrix[sourceLoc][neighbour->first-1]=1;
                }
            }
            cout<<"Vector created of all elements"<<endl;
            displayMatrix(matrix);
            unordered_set<int>visitedNodes;
            int cnt=0,choice;
            cout<<"Which method to use (1 : DFS 2 : BFS)\nYour chocie : ";
            cin>>choice;
            if(choice==1){
                for(int i=1;i<=matrix.size();i++){
                    if(DFSInMatrix(matrix,i,visitedNodes)){
                        cnt++;
                    }
                }
            } else if(choice==2){
                for(int i=1;i<=matrix.size();i++){
                    queue<int>loc;
                    loc.push(i);
                    if(BFSInMatrix(matrix,loc,visitedNodes)){
                        cnt++;
                    }
                }
            }
            cout<<"No of provinces is : "<<cnt<<endl;
            return cnt;
        }

        bool BFSnoOfIslands(vector<vector<int>>&matrix,queue<pair<int,int>>&loc,unordered_map<int,unordered_set<int>>&visitedNodes){
            if(loc.empty())return false;
            pair<int,int> currentPair=loc.front();
            loc.pop();
            int x=currentPair.first,y=currentPair.second;
            if(matrix[x][y]==0||(visitedNodes.find(x)!=visitedNodes.end()&&visitedNodes[x].find(y)!=visitedNodes[x].end())){
                BFSnoOfIslands(matrix,loc,visitedNodes);
                return false;
            } else {
                visitedNodes[x].insert(y);
            }
            loc.push({x-1,y});
            loc.push({x+1,y});
            loc.push({x,y+1});
            loc.push({x,y-1});
            BFSnoOfIslands(matrix,loc,visitedNodes);
            return true;
        }

        int noOfIslands(){
            int row,colomn;
            string path="graphs_data/weighted_graphs/noOfIslands/";
            string filename;
            cout<<"Enter filename : ";
            cin>>filename;
            ifstream input(path+filename,ios::in);
            string line;
            while(getline(input,line)){
                if(line.empty()||line[0]=='#')continue;
                stringstream ss(line);
                ss>>row>>colomn;
                break;
            }
            vector<vector<int>>matrix(row+2,vector<int>(colomn+2,0));
            cout<<"No of rows of matrix : "<<matrix.size()<<" & No of colomns of matrix = "<<matrix[0].size()<<endl;
            int i=1;
            while(getline(input,line)){
                if(line.empty()||line[0]=='#')continue;
                stringstream ss(line);
                for(int j=1;j<=colomn;j++){
                    ss>>matrix[i][j];
                }
                i++;
            }
            cout<<"Matrix is set"<<endl;
            displayMatrix(matrix);
            // unordered_set<pair<int,int>>visitedNodes;
            // unordered_set<int>visitedX,visitedY;
            unordered_map<int,unordered_set<int>>visitedNodes;
            int cnt=0;
            for(int i=1;i<=row;i++){
                for(int j=1;j<=colomn;j++){
                    queue<pair<int,int>>loc;
                    loc.push({i,j});
                    if(BFSnoOfIslands(matrix,loc,visitedNodes)){
                        cnt++;
                    }
                }
            }
            cout<<"No of islands found are : "<<cnt<<endl;
            return cnt;
        }

        void AStarKIntermediates(){
            for(auto it=dataset.begin();it!=dataset.end();it++){
                it->second->costWithHeuristicValue=INT_MAX;
                it->second->cost=INT_MAX;
            }
            AStarKIntermediatesCompare obj(this);
            int startData,destinationData;
            node*startNode,*destinationNode;
            cout<<"Enter startData : ";
            cin>>startData;
            cout<<"Enter destination data : ";
            cin>>destinationData;
            startNode=dataset[startData];
            source=start;
            destinationNode=dataset[destinationData];
            int k;
            bool sequenceNecessary;
            cout<<"How many intermediates there are : ";
            cin>>k;
            cout<<"Do all intermediates need to be traversed in sequence?1 : Yes 0 : No\nYour choice : ";
            cin>>sequenceNecessary;
            cout<<"Enter data of "<<k<<" intermediates : ";
            if(sequenceNecessary){

            } else {
                // priority_queue<node*,vector<node*>,AStarKIntermediatesCompare>loc(obj);
                int intermediateData;
                vector<node*>intermediates;
                for(int i=0;i<k;i++){
                    cin>>intermediateData;
                    intermediates.push_back(dataset[intermediateData]);
                    // cout<<"Heursitic value of "<<dataset[intermediateData]->data<<" from "<<source->data<<" is : "<<source->HeuristicValues[dataset[intermediateData]]<<endl;
                    // loc.push(dataset[intermediateData]);
                }
                
                cout<<intermediates.size()<<" intermediate nodes stored"<<endl;
                source=startNode;
                visited.clear();
                node* nextNode;
                while(!intermediates.empty()){
                    nextNode=intermediates[0];
                    for(int i=0;i<intermediates.size();i++){
                        if(intermediates[i]->HeuristicValues[source]<nextNode->HeuristicValues[source]){
                            nextNode=intermediates[i];
                        }
                    }
                    cout<<"Next node is selected as : "<<nextNode->data<<" from "<<source->data<<endl;
                    priority_queue<node*,vector<node*>,AStarCompare>loc;
                    loc.push(source);
                    destination=nextNode;
                    source->cost=0;
                    source->costWithHeuristicValue=source->HeuristicValues[nextNode];

                    AStartHelper(loc);

                    cout<<"destination("<<destination->data<<")->costWithHeuristicValue = "<<destination->costWithHeuristicValue<<endl;
                    cout<<"destination->cost = "<<destination->cost<<endl;
                    cout<<"All the nodes traversed are : ";
                    for(auto it=visited.begin();it!=visited.end();it++){
                        cout<<(*it)->data<<" ";
                    }
                    source=nextNode;
                    visited.clear();
                    auto deleteIntermediate=find(intermediates.begin(),intermediates.end(),nextNode);
                    intermediates.erase(deleteIntermediate);
                     for(auto it=dataset.begin();it!=dataset.end();it++){
                        it->second->costWithHeuristicValue=INT_MAX;
                        it->second->cost=INT_MAX;
                    }
                }
                cout<<"All "<<k<<" intermediates traversed let's traver from "<<source->data<<" to "<<destinationNode->data<<endl;
                priority_queue<node*,vector<node*>,AStarCompare>loc;
                loc.push(source);
                source->cost=0;
                source->costWithHeuristicValue=source->HeuristicValues[destinationNode];
                destination=destinationNode;
                AStartHelper(loc);

                cout<<"AStar K Intermediates funciton completed"<<endl;
            }

        }
        
        void floodFillWithUMap(vector<vector<int>>&matrix,int x,int y,int& parent,int& color){
            if(x<0||y<0||x>=matrix.size()||y>=matrix[x].size())return;
            else if(visitedPlaces.find(x)!=visitedPlaces.end()&&visitedPlaces[x].find(y)!=visitedPlaces[x].end())return;
            else if(matrix[x][y]!=parent)return;
            visitedPlaces[x];
            visitedPlaces[x].insert(y);
            matrix[x][y]=color;   
            floodFillWithUMap(matrix,x-1,y,parent,color);
            floodFillWithUMap(matrix,x+1,y,parent,color);
            floodFillWithUMap(matrix,x,y-1,parent,color);
            floodFillWithUMap(matrix,x,y+1,parent,color);
        }

        void floodFillWithoutUMap(vector<vector<int>>&matrix,int x,int y,int &parent,int& color){
            if(x<0||y<0||x>=matrix.size()||y>=matrix[x].size())return;
            else if(matrix[x][y]!=parent)return;
            cout<<"x = "<<x<<" & y = "<<y<<endl;
            matrix[x][y]=color;   
            floodFillWithoutUMap(matrix,x-1,y,parent,color);
            floodFillWithoutUMap(matrix,x+1,y,parent,color);
            floodFillWithoutUMap(matrix,x,y-1,parent,color);
            floodFillWithoutUMap(matrix,x,y+1,parent,color);
        }

        void floodFill(){
            // vector<vector<int>>matrix=loadMatrix();
            loadMatrix();
            bool usingUMap;
            int x,y,parent,color;
            cout<<"Enter x & y co-ordinates of starting point : ";
            cin>>x>>y;
            parent=matrix[x][y];
            cout<<"Enter new colour you want to fill with : ";
            cin>>color;
            cout<<"Do you want to solve using Unordered_map?1 : Yes 0 : no\nYour choice :" ;
            cin>>usingUMap;
            if(usingUMap){
                floodFillWithUMap(matrix,x,y,parent,color);
            } else {
                floodFillWithoutUMap(matrix,x,y,parent,color);
            }
            cout<<"Matrix after performing the flood FIll is : "<<endl;
            displayMatrix(matrix);
            // displayAdjcancyMatrixMadeFromGraph();
        }

        void displayAdjcancyMatrixMadeFromGraph(){
            cout<<"\t\tWith"<<endl<<"\t";
            for(auto it=dataset.begin();it!=dataset.end();it++){
                cout<<it->first<<"\t";
            }
            cout<<endl;
            for(auto it=dataset.begin();it!=dataset.end();it++){
                cout<<"From "<<it->first<<":";
                for(auto neighbours=dataset.begin();neighbours!=dataset.end();neighbours++){
                    cout<<adjacancyMatrixUsingGraph[it->second][neighbours->second]<<"\t";
                }
                cout<<endl;
            }
        }

        void createAdjacancyMatrixFromGraph(){
            for(auto it=dataset.begin();it!=dataset.end();it++){
                adjacancyMatrixUsingGraph[it->second][it->second]=1;
                for(auto neighbours=it->second->connections_map.begin();neighbours!=it->second->connections_map.end();neighbours++){
                    adjacancyMatrixUsingGraph[it->second][neighbours->second.first]=1;
                }
            }
        }

        void loadMatrixFromFile(){
            // this->matrix=loadMatrix();
            loadMatrix();
        }

        void loadMatrix(){
            string path="graphs_data/matrix_data/";
            string filename;
            cout<<"Enter fileanme of the matrix you want to form : ";
            cin>>filename;
            path+=filename;
            cout<<"Fetching matrix from "<<path<<endl;
            // vector<vector<int>>matrix;

            ifstream input(path,ios::in);
            if(!input.is_open()){
                cout<<"Error openign the file"<<endl;
                return;
            }
            int row,col;
            input>>row>>col;
            matrix.resize(row,vector<int>(col,0));
            cout<<"Size of matrix : "<<matrix.size()<<" & size of matrix[0] = "<<matrix[0].size()<<endl;
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    input>>matrix[i][j];
                }
            }
            cout<<"Matrix formed"<<endl;
            displayMatrix(matrix);
            input.close();
            // return matrix;
            return;
        }

        bool safeCheck(vector<vector<int>>&matrix,int x,int y){
            if(x<0||y<0||x>=matrix.size()||y>=matrix[x].size())return false;
            else return true;
        }

        void rottenOrangesHelperBFSOneTry(const pair<int,int>&loc,unordered_set<pair<int,int>,pairIntIntHash>&rotten,unordered_set<pair<int,int>,pairIntIntHash>&fresh){
            int x=loc.first,y=loc.second;
            if(safeCheck(matrix,x-1,y)&&matrix[x-1][y]==1){
                matrix[x-1][y]=2;
                rotten.insert({x-1,y});
                fresh.erase({x-1,y});
                cout<<x-1<<" & "<<y<<" new Rotten Oragne"<<endl;
            }

            if(safeCheck(matrix,x+1,y)&&matrix[x+1][y]==1){
                matrix[x+1][y]=2;
                rotten.insert({x+1,y});
                fresh.erase({x+1,y});
                cout<<x+1<<" & "<<y<<" new Rotten Oragne"<<endl;
            }  

            if(safeCheck(matrix,x,y-1)&&matrix[x][y-1]==1){
                matrix[x][y-1]=2;
                rotten.insert({x,y-1});
                fresh.erase({x,y-1});
                cout<<x<<" & "<<y-1<<" new Rotten Oragne"<<endl;
            }  

            if(safeCheck(matrix,x,y+1)&&matrix[x][y+1]==1){
                matrix[x][y+1]=2;
                rotten.insert({x,y+1});
                fresh.erase({x,y+1});
                cout<<x<<" & "<<y+1<<" new Rotten Oragne"<<endl;
            }

            rotten.erase({x,y});
            cout<<x<<" & "<<y<<" deleted from rotten"<<endl;
        }

        void rottenOrangesHelperBFSOneTry2(const pair<int,int>&loc,unordered_set<pair<int,int>,pairIntIntHash>&rotten,unordered_set<pair<int,int>,pairIntIntHash>&fresh){

            int x=loc.first,y=loc.second;
            for(auto &it : fourDirections){
                // cout<<"it.first = "<<it.first<<" & it.second = "<<it.second<<endl;
                if(safeCheck(matrix,x+it.first,y+it.second)&&matrix[x+it.first][y+it.second]==1){
                    matrix[x+it.first][y+it.second]=2;
                    rotten.insert({x+it.first,y+it.second});
                    fresh.erase({x+it.first,y+it.second});
                    cout<<"FOund at x = "<<x+it.first<<" & y = "<<y+it.second<<endl;
                }
            }
            rotten.erase({x,y});
        }

        void rottenOrangesHelperPureBFS(queue<pair<int,int>>&loc,unordered_set<pair<int,int>,pairIntIntHash>&fresh,int& minute){
            if(loc.empty()){
                cout<<"Queue found empty"<<endl;
                return;
            } else if(fresh.empty()){
                cout<<"All oranges are rotten so lets go back"<<endl;
                return;
            }
            minute++;
            cout<<"Inside the recursion minute = "<<minute<<endl;
            int size=loc.size();
            while(size--){
                pair<int,int> p=loc.front();
                loc.pop();
                int x=p.first,y=p.second;
                for(auto& it:fourDirections){
                    int nextX=x+it.first,nextY=y+it.second;
                    if(safeCheck(matrix,nextX,nextY)&&matrix[nextX][nextY]==1){
                        matrix[nextX][nextY]=2;
                        fresh.erase({nextX,nextY});
                        loc.push({nextX,nextY});
                    }
                }
            }
            rottenOrangesHelperPureBFS(loc,fresh,minute);
        }

        int rottenOrangesBFSBloom(queue<pair<int,int>>&loc,unordered_set<pair<int,int>,pairIntIntHash>&visitedLoc,unordered_set<pair<int,int>,pairIntIntHash>&fresh,int min=1){
            if(loc.empty()){
                cout<<"I dont think this will come"<<endl;
                return min;
            }
            int size=loc.size();
            while(size--){
                pair<int,int>curr=loc.front();
                loc.pop();
                int x=curr.first,y=curr.second;
                matrix[x][y]=2;
                fresh.erase({x,y});
                for(auto &it: fourDirections){
                    int nextX=x+it.first,nextY=y+it.second;
                    if(safeCheck(matrix,nextX,nextY)&&matrix[nextX][nextY]==1&&visitedLoc.find({nextX,nextY})==visitedLoc.end()){
                        visitedLoc.insert({nextX,nextY});
                        loc.push({nextX,nextY});
                    }
                }
            }
            if(loc.empty())return min;
            else return rottenOrangesBFSBloom(loc,visitedLoc,fresh,min+1);
        }

        void rottenOranges(){
            bool loadMatrix=false;
            cout<<"Do you want to load matrix from file : 1 : yes\nYour choice : ";
            cin>>loadMatrix;
            if(loadMatrix)  loadMatrixFromFile();

            int choice=false;;
            cout<<"1 : Using unordered_set + BFS Approach\n2 : Using Queue for BFS\n3 : Improved - BFS Bloom\nYour choice : ";
            cin>>choice;

            if(choice==1){
                unordered_set<pair<int,int>,pairIntIntHash>rotten,newRotten;
                unordered_set<pair<int,int>,pairIntIntHash>fresh;
                for(int i=0;i<matrix.size();i++){
                    for(int j=0;j<matrix[i].size();j++){
                        if(matrix[i][j]==1){
                            fresh.insert({i,j});
                        } else if(matrix[i][j]==2){
                            rotten.insert({i,j});
                        }
                    }
                }
                newRotten=rotten;
                cout<<"Wole matrix Scanned"<<endl;
                int minute=0;
                cout<<"No of rotten oranges : "<<rotten.size()<<endl;
                cout<<"No of oranges : "<<fresh.size()<<endl; 
                while(!rotten.empty()&&!fresh.empty()){
                    minute++;
                    for(auto it=rotten.begin();it!=rotten.end();it++){
                        // rottenOrangesHelperBFSOneTry(*it,newRotten,fresh);    
                        rottenOrangesHelperBFSOneTry2(*it,newRotten,fresh);    
                    }
                    rotten.clear();
                    rotten=newRotten;
                }
                if(fresh.empty()){
                    cout<<"Total time taken to rotten all oranges is : "<<minute<<endl;
                    cout<<"Minute = "<<minute<<endl;
                } else {
                    cout<<"Not possible to rotten all oranges"<<endl;
                    cout<<"Minute = "<<minute<<endl;
                }
            } else if(choice==2){
                int minute=0;
                unordered_set<pair<int,int>,pairIntIntHash>fresh;
                queue<pair<int,int>>loc;
                for(int i=0;i<matrix.size();i++){
                    for(int j=0;j<matrix[i].size();j++){
                        if(matrix[i][j]==1){
                            fresh.insert({i,j});
                        } else if(matrix[i][j]=2){
                            loc.push({i,j});
                        }
                    }
                }
                cout<<"No of rotten oranges : "<<loc.size()<<endl;
                cout<<"No of oranges : "<<fresh.size()<<endl;
                rottenOrangesHelperPureBFS(loc,fresh,minute);
                if(fresh.empty())
                    cout<<"Total time required was : "<<minute<<endl;
                else {
                    cout<<"Not possible to rotten all oranges"<<endl;
                    cout<<"minute = "<<minute<<endl;
                }
            } else if(choice==3){
                queue<pair<int,int>>loc;
                unordered_set<pair<int,int>,pairIntIntHash>visitedLoc;
                unordered_set<pair<int,int>,pairIntIntHash>fresh;
                for(int i=0;i<matrix.size();i++){
                    for(int j=0;j<matrix[i].size();j++){
                        if(matrix[i][j]==2){
                            loc.push({i,j});
                            visitedLoc.insert({i,j});
                        } else if(matrix[i][j]==1){
                            fresh.insert({i,j});
                        }
                    }
                }
                if(fresh.empty()){
                    cout<<"THere are no fresh oranges initially so time required = 0"<<endl;
                }
                cout<<"Total fresh oranges are : "<<fresh.size()<<endl;
                int minReq=rottenOrangesBFSBloom(loc,visitedLoc,fresh,0);
                if(fresh.empty())
                    cout<<"Total time required to rotten all oranges is : "<<minReq<<endl;
                else {
                    cout<<"Not possible to rotten all oranges"<<endl;
                }
                // return minReq;
            }
            // cout<<"Which method to implement\n1 : BFS\n2 : Flood Fll\nYour choice : ";
            // cin>>choice;
            // if(choice==1){
                
            // } else if(choice==2){

            // }
               
        }

        void cycleInMatrix(){
            bool loadMatrix=false;
            cout<<"Do you wnat to load matrix : 1 : Yes\nYour choice : ";
            cin>>loadMatrix;
            if(loadMatrix)loadMatrixFromFile();
            unordered_set<pair<int,int>,pairIntIntHash>visitedLoc;
            queue<pair<int,int>>loc;
            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[i].size();j++){
                    // if(visited.find({i,j})==visited.end()&&helperCyclePresentInMatrix()){
                    //     cout<<"Cycle is present in the matrix"<<endl;
                    // }
                }
            }

        }

        bool traverseIsCylePresentInMatrix(pair<int,int>&parent,pair<int,int>curr,unordered_set<pair<int,int>,pairIntIntHash>visitedLoc){
            if(visitedLoc.find(curr)!=visitedLoc.end()){
                return true;
            } else {
                visitedLoc.insert({curr.first,curr.second});
            }
            bool ret=false;
            for(auto & it : fourDirections){
                int nextX=curr.first+it.first,nextY=curr.second+it.second;
                if(safeCheck(matrix,nextX,nextY)&&(nextX!=parent.first&&nextY!=parent.second)&&matrix[nextX][nextY]==matrix[curr.first][curr.second]){
                    ret =  ret || traverseIsCylePresentInMatrix(curr,{nextX,nextY},visitedLoc);
                    if(ret)return true;
                }
            }
            return false;
        }

        bool containsCycle(){
            loadMatrixFromFile();
            unordered_set<pair<int,int>,pairIntIntHash>visitedLoc;

            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[i].size();j++){
                    pair<int,int>curr={i,j};
                    if(visitedLoc.find(curr)==visitedLoc.end()){
                        pair<int,int>parent={-1,-1};
                        if(traverseIsCylePresentInMatrix(parent,curr,visitedLoc)){
                            cout<<"Cycle is presen ttold by x= "<<curr.first<<" & y = "<<curr.second<<endl;
                            return true;
                        }
                    }
                }
            }
            cout<<"Cycle is not present in the matrix so returnign false"<<endl;
            return false;
        }

        bool isCyclicBFS(queue<node*>&loc,vector<node*>&parents){
            if(loc.empty()){
                cout<<"Queue found empty"<<endl;
                return false;
            } 
            bool ret=false;
            int size=loc.size();
            vector<node*>newVec;
            for(int i=0;i<size;i++){
                node*curr=loc.front();
                loc.pop();
                if(visited.find(curr)!=visited.end()){
                    cout<<"Cycle found at : "<<curr->data<<endl;
                    return true;
                } else {
                    visited.insert(curr);
                }
                for(auto neighbours=curr->connections_map.begin();neighbours!=curr->connections_map.end();neighbours++){
                    if(parents[i]!=neighbours->second.first){
                        loc.push(neighbours->second.first);
                        newVec.push_back(curr);
                    }
                }
            }
     
            ret = ret || isCyclicBFS(loc,newVec);
            return ret;
        }

        bool isCyclicBFSTry2(queue<pair<node*,node*>>&loc){
            if(loc.empty()){
                cout<<"Queue found empty"<<endl;
                return false;
            }
            pair<node*,node*>p=loc.front();
            loc.pop();
            if(visited.find(p.first)!=visited.end()){
                cout<<p.first->data<<" is already visited"<<endl;
                return true;
            } else {
                visited.insert(p.first);
            }
            bool ret=false;
            for(auto neighbours=p.first->connections_map.begin();neighbours!=p.first->connections_map.end();neighbours++){
                node* neighbour=neighbours->second.first;
                if(neighbour!=p.second){
                    loc.push({neighbour,p.first});
                }
            }
            ret = ret || isCyclicBFSTry2(loc);
            return ret;
        }

        bool helperIsCyclicDFS(node*&curr,node*&parent){
            if(visited.find(curr)!=visited.end()){
                cout<<curr->data<<" is already visited"<<endl;
                return true;
            } else {
                visited.insert(curr);
            }
            bool ret=false;
            for(auto neighbours=curr->connections_map.begin();neighbours!=curr->connections_map.end();neighbours++){
                node* neighbour=neighbours->second.first;
                if(neighbour!=parent){
                    ret = helperIsCyclicDFS(neighbour,curr);
                    if(ret)return true; // immediately returning because its DFS
                }
            }
            return false;
        }

        bool isCyclicUndirectedDFS(){
            node*temp=nullptr;
            for(auto it=dataset.begin();it!=dataset.end();it++){
                if(visited.find(it->second)==visited.end()){
                    if(helperIsCyclicDFS(it->second,temp)){
                        cout<<"Cycle found from  "<<it->first<<endl;
                        return true;
                    }
                }
            }
            cout<<"No cycle found"<<endl;
            return false;
        }

        bool isCyclicUndirectedBFS(){
            visited.clear();
            int choice;
            cout<<"Which method to use :\n1 : Use vector to refere to parents\n2 : Use queue<pair<node*,node*>> to refer to parents\nYour chocie : ";
            cin>>choice;
            if(choice==1){
                for(auto it=dataset.begin();it!=dataset.end();it++){
                    if(visited.find(it->second)==visited.end()){
                        cout<<"Going through : "<<it->first<<endl;
                        queue<node*>loc;
                        loc.push(it->second);
                        vector<node*>temp;
                        temp.push_back(nullptr);
                        if(isCyclicBFS(loc,temp)){
                            cout<<"Cycle Present found from node "<<it->first<<endl;
                            return true;
                        }
                    }
                }
            } else if(choice==2){
                for(auto it=dataset.begin();it!=dataset.end();it++){
                    if(visited.find(it->second)==visited.end()){
                        queue<pair<node*,node*>>loc;
                        loc.push({it->second,nullptr});
                        if(isCyclicBFSTry2(loc)){
                            cout<<"Cycle found from "<<it->first<<endl;
                            return true;
                        }
                    }
                }
            }
            cout<<"No cycle present in this undirected graph"<<endl;
            return false;
        }

        int findNearestZero(int x,int y,unordered_set<pair<int,int>,pairIntIntHash>&visitedLoc){
            if(visitedLoc.find({x,y})!=visitedLoc.end()){
                return INT_MAX;
            } 
            if(matrix[x][y]==0)return 0;

            int ret=INT_MAX;
            for(auto &it : fourDirections){
                visitedLoc.insert({x,y});
                int nextX=x+it.first,nextY=y+it.second;
                cout<<"Lets check for x = "<<nextX<<" & y = "<<nextY<<endl;
                if(safeCheck(matrix,nextX,nextY)){
                    ret = min(ret, findNearestZero(nextX, nextY, visitedLoc));
                    visitedLoc.erase({x,y});
                }
                // visitedLoc.erase({x,y});
            }
            if(ret==INT_MAX)return ret;
            else return ret+1;
        }

        int findNearestZeroBFS(queue<pair<int,int>>&loc,unordered_set<pair<int,int>,pairIntIntHash>&visitedLoc){
            if(loc.empty()){
                cout<<"queue found empty"<<endl;
                return INT_MAX;
            }
            // visitedLoc.insert({x,y});
            cout<<"hi"<<endl;
            int size=loc.size();
            while(size--){
                pair<int,int> curr=loc.front();
                loc.pop();
                int x=curr.first,y=curr.second;
                if(visitedLoc.find({x,y})!=visitedLoc.end()){
                    continue;
                } else {
                    visitedLoc.insert({x,y});
                }
                for(auto &it:fourDirections){
                    int nextX=x+it.first,nextY=y+it.second;
                    if(safeCheck(matrix,nextX,nextY)){
                        if(matrix[nextX][nextY]==0)return 1;
                        else if(matrix[nextX][nextY]==1){
                            loc.push({nextX,nextY});
                        }
                    }
                }
            }
            int ret=findNearestZeroBFS(loc,visitedLoc);
            if(ret==INT_MAX)return ret;
            else return ret+1;
        }

        void findNearestZeroBFSTry2(queue<pair<int,int>>&loc,unordered_set<pair<int,int>,pairIntIntHash>&visitedLoc,int step=0){
            if(loc.empty()){
                cout<<"queue found empty"<<endl;
                return;
            }
            int size=loc.size();
            while(size--){
                pair<int,int>curr=loc.front();
                int x=curr.first,y=curr.second;
                loc.pop();
                matrix[x][y]=step;
                for(auto & it : fourDirections){
                    int nextX=x+it.first,nextY=y+it.second;
                    if(safeCheck(matrix,nextX,nextY)&&visitedLoc.find({nextX,nextY})==visitedLoc.end()){
                        visitedLoc.insert({nextX,nextY});
                        loc.push({nextX,nextY});
                    }
                }
            }
            findNearestZeroBFSTry2(loc,visitedLoc,step+1);
        }

        void nearest0InMatrix(){
            loadMatrixFromFile();
            bool choice;
            cout<<"Which method to use ?\n1 : DFS 2 : BFS\n3 : BFS More Efficient(traversing once ONLY)\nYour choice : ";
            cin>>choice;
            if(choice==1){
                for(int i=0;i<matrix.size();i++){
                    for(int j=0;j<matrix[i].size();j++){
                        if(matrix[i][j]==1){
                            unordered_set<pair<int,int>,pairIntIntHash>visitedLoc;
                            int pos=findNearestZero(i,j,visitedLoc);
                            cout<<"For the 1 present at x = "<<i<<" & y = "<<j<<" nearest 0 found is at distance : "<<pos<<endl;
                            matrix[i][j]=pos;
                        }
                    }
                }
            } else if(choice==2){
                cout<<"hey"<<endl;
                for(int i=0;i<matrix.size();i++){
                    for(int j=0;j<matrix[i].size();j++){
                        if(matrix[i][j]==1){
                            unordered_set<pair<int,int>,pairIntIntHash>visitedLoc;
                            queue<pair<int,int>>loc;
                            loc.push({i,j});
                            int pos=findNearestZeroBFS(loc,visitedLoc);
                            cout<<"For the 1 present at x = "<<i<<" & y = "<<j<<" nearest 0 found is at distance : "<<pos<<endl;
                            matrix[i][j]=pos;
                        }
                    }
                }
            }
            else if(choice==3){
                queue<pair<int,int>>loc;
                unordered_set<pair<int,int>,pairIntIntHash>visitedLoc;
                for(int i=0;i<matrix.size();i++){
                    for(int j=0;j<matrix[i].size();j++){
                        if(matrix[i][j]==0){
                            loc.push({i,j});
                            visitedLoc.insert({i,j});
                        }
                    }
                }
                findNearestZeroBFSTry2(loc,visitedLoc,0);
            }
            cout<<"Done"<<endl;
            cout<<"Matrix formed is : "<<endl;
            displayMatrix(matrix);
        }

        bool isCyclicBFS(queue<pair<node*,node*>>&loc){
            if(loc.empty())return false;
            int size=loc.size();
            while(size--){
                pair<node*,node*>curr=loc.front();
                loc.pop();
                node* current_node=curr.first;
                node*parent=curr.second;
                for(auto it=current_node->connections_map.begin();it!=current_node->connections_map.end();it++){
                    node* neighbour=it->second.first;
                    if(neighbour!=parent){
                        if(visited.find(it->second.first)!=visited.end()){
                            cout<<"Cycle is present"<<endl;
                            return true;
                        } else {
                            loc.push({neighbour,current_node});
                            visited.insert(neighbour);
                        }
                    }
                }
            }
            return isCyclicBFS(loc);
        }

        bool isCyclicDFS(node*&curr,node*&parent){
            bool ret=false;
            for(auto &it : curr->connections_map){
                node*neighbour=it.second.first;
                if(neighbour!=parent){
                    if(visited.find(neighbour)!=visited.end()){
                        cout<<"CYCle is present found at : "<<curr->data<<" to -> "<<neighbour->data<<endl;
                        return true;
                    } else {
                        visited.insert(neighbour);
                        ret=isCyclicDFS(neighbour,curr);
                        if(ret)return true;
                    }
                }
            }
            return false;
        }

        bool isCyclicUndirected(){
            int choice;
            cout<<"Whihc method to use?'n1 : DFS'n2 : BFS\nYour chocie : ";
            cin>>choice;
            visited.clear();
            if(choice==1){
                for(auto &it:dataset){
                    if(visited.find(it.second)==visited.end()){
                        node*temp=nullptr;
                        if(isCyclicDFS(it.second,temp)){
                            cout<<"Cycle present found from "<<it.first<<endl;
                            return true;
                        }
                    }
                }
            } else if(choice==2){
                for(auto &it:dataset){
                    if(visited.find(it.second)==visited.end()){
                        queue<pair<node*,node*>>loc;
                        loc.push({it.second,nullptr});
                        if(isCyclicBFS(loc)){
                            cout<<"Cycle is present found from "<<it.first<<endl;
                            return true;
                        }   
                    }
                }
            } 
            cout<<"No cycle found in this undirected graph"<<endl;
            return false;
        }
    
        void DFSHelperDistinctIslands(int x,int y,int &baseX,int& baseY,vector<vector<int>>&matrix,int& cnt,string& path){
            cnt++;
            visitedLoc.insert({x,y});
            for(auto it=fourDirections.begin();it!=fourDirections.end();it++){
                int nextX=x+it->first,nextY=y+it->second;
                if(safeCheck(matrix,nextX,nextY)&&matrix[nextX][nextY]==1&&visitedLoc.find({nextX,nextY})==visitedLoc.end()){
                    path+=(to_string(nextX-baseX)+to_string(nextY-baseY));
                    DFSHelperDistinctIslands(nextX,nextY,baseX,baseY,matrix,cnt,path);
                }
            }
        }
    
        // void BFSHelperDistinctIslands(queue<pair<int,int>>&loc,vector<vector<int>>&matrix,string &path){
        //     if(loc.empty()){
        //         return;
        //     }
        //     pair<int,int>p=loc.front();
        //     int x=p.first,y=p.second;
        //     visitedLoc.insert(p);
        //     loc.pop();
        //     for(auto it=fourDirections.begin();it!=fourDirections.end();it++){
        //         int nextX=x+it->first,nextY=y+it->second;
        //         if(safeCheck(matrix,nextX,nextY)&&matrix[nextX][nextY]==1&&visitedLoc.find({nextX,nextY})==visitedLoc.end()){
        //         //  path+=fourDrxn[distance(fourDirections.begin(),it)];
        //          loc.push({nextX,nextY})
        //         }
        //     }
        //     BFSHelper(loc,matrix,path);
        // }
    
        int countDistinctIslands(vector<vector<int>>&matrix){

            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[i].size();j++){
                    if(matrix[i][j]==1&&visitedLoc.find({i,j})==visitedLoc.end()){
                        int cnt=0;
                        string path="";
                        DFSHelperDistinctIslands(i,j,i,j,matrix,cnt,path);
                        distinctIslands.insert({cnt,path});
                        // queue<pair<int,int>>loc;
                        // loc.push({i,j});
                        // BFSHelper(loc,matrix,path);
                        // distinctIslands.insert(path);
                    }
                }
            }
            
            return distinctIslands.size();
        }

        void colorBipartiteDFS(node*curr_node,node*parent){
            if(visited.find(curr_node)!=visited.end())return;
            else visited.insert(curr_node);
            curr_node->colored=!parent->colored;
            for(auto &it:curr_node->connections_map){
                colorBipartiteDFS(it.second.first,curr_node);
            }
        }
        
        bool isBipartiteDFS(node* curr_node,node*parent){
            cout<<curr_node->data<<endl;
            if(curr_node->colored==parent->colored){
                cout<<curr_node->data<<" & "<<parent->colored<<" are colored same"<<endl;
                return false;
            }
            visited.insert(curr_node);
            bool ret=true;
            for(auto &neighbours:curr_node->connections_map){
                node* neighbour=neighbours.second.first;
                if(neighbour!=parent){
                    if(visited.find(neighbour)==visited.end()){
                        ret= ret && isBipartiteDFS(neighbour,curr_node);
                        if(!ret){
                            return false;
                        }
                    } else {
                        if(neighbour->colored==curr_node->colored){
                            cout<<neighbour->data<<" is visited but ... ";
                            cout<<curr_node->data<<" & "<<parent->data<<" are colored same"<<endl;
                            return false;
                        }
                    }
                }
            }
            return true;
        }

        bool isBipartiteBFS(queue<pair<node*,node*>>&loc){
            // cout<<"hi"<<endl;
            if(loc.empty()){
                cout<<"Queue found empty graph must be Biparitite"<<endl;
                return true;
            }
            node* curr_node=loc.front().first;
            cout<<curr_node->data<<endl;
            node* parent=loc.front().second;
            loc.pop();

           { if(curr_node->colored){
                cout<<curr_node->data<<" is colored"<<endl;
            } else {
                cout<<curr_node->data<<" is not colored"<<endl;
            }
            if(parent->colored){
                cout<<parent->data<<" is colored"<<endl;
            } else {
                cout<<parent->data<<" is not colored"<<endl;
            }
            }
           
            if(curr_node->colored==parent->colored){
                cout<<curr_node->data<<" & "<<parent->data<<" are colored same"<<endl;
                return false;
            }

            if(visited.find(curr_node)!=visited.end()){
                return isBipartiteBFS(loc);
            } else {
                visited.insert(curr_node);
            }
            
            for(auto &neighbours:curr_node->connections_map){
                node*neighbour=neighbours.second.first;
                if(parent!=neighbour){
                    loc.push({neighbour,curr_node});
                }
            }
            return isBipartiteBFS(loc);
        }

        bool isBipartite(){
            if(!start){
                cout<<"The graph is not colored yet"<<endl;
                return false;
            }
           
            visited.clear();
            node*temp=new node(-5);
            temp->colored=!start->colored;
            bool choice;
            cout<<"WHihc method to use to verify whehter graph is Bipartite or not ?\n1 : DFS\n0 : BFS\nYour choice : ";
            cin>>choice;
            
            cout<<"Starting Bipartite check from "<<start->data<<endl;
            if(choice){
                bool isBipartite=isBipartiteDFS(start,temp);
                delete temp;
                if(isBipartite){
                    cout<<"The given graph is found to be Bipartite by DFS Method"<<endl;
                    return true;
                } else {
                    cout<<"The graph is not Bipartite found by DFS"<<endl;
                    return false;
                }
            } else {
                queue<pair<node*,node*>>loc;
                loc.push({start,temp});
                bool isBipartite=isBipartiteBFS(loc);
                delete temp;
                if(isBipartite){
                    cout<<"The given graph is found to be Bipartite by BFS Method"<<endl;
                    return true;
                } else {
                    cout<<"The graph is not Bipartite found by BFS"<<endl;
                    return false;
                }
            }
            return false;
        }
        
        void colorBipartiteBFS(queue<node*>&loc,bool color){
            if(loc.empty())return;
            int size=loc.size();
            while(size--){
                node*curr_node=loc.front();
                loc.pop();
                cout<<"curr_node = "<<curr_node->data<<endl;
                if(visited.find(curr_node)!=visited.end()){
                    cout<<"This should never arrise i think"<<endl;
                    continue;
                    // colorBipartiteBFS(loc,!color);
                } else {
                    visited.insert(curr_node);
                    curr_node->colored=color;
                }
                for(auto& neighbours : curr_node->connections_map){
                    node* neighbour=neighbours.second.first;
                    if(visited.find(neighbour)==visited.end()){
                        loc.push(neighbour);
                    }
                }
            }
            colorBipartiteBFS(loc,!color);
        }
       
        void colorBipartite(){
            for(auto & it:dataset){
                it.second->colored=false;
            }
            visited.clear();
            cout<<" uncolored all nodes first"<<endl;
            int startData;
            cout<<"Enter node data from which to start coloring : ";
            cin>>startData;
            start=dataset[startData];
            cout<<"Starting from "<<start->data<<endl;
            node*temp=new node(-5);
            bool choice;
            cout<<"Which method to use to color the graph?\n1 : DFS\n0 : BFS\nYour choice : ";
            cin>>choice;
            if(choice){
                colorBipartiteDFS(start,temp);
            } else {
                queue<node*>loc;
                loc.push(start);
                colorBipartiteBFS(loc,true);
                return;
            }
            cout<<"Graph colored "<<endl;
            delete temp;
        }

        void displayColoring(){
            for(auto & it:dataset){
                cout<<it.first<<" is : ";
                if(it.second->colored)cout<<" colored"<<endl;
                else cout<<" not colored"<<endl;
            }
        }

        bool coloringUsingBFS(queue<pair<node*,node*>>&loc,bool sign){
            if(loc.empty()){
                cout<<"Queue found empyt"<<endl;
                return true;
            }
            node* curr_node=loc.front().first;
            node*parent=loc.front().second;
            loc.pop();
            if(visited.find(curr_node)==visited.end()){
                visited.insert({curr_node,parent});
                curr_node->colored=sign;
            } else {
                return coloringUsingBFS(loc,!sign);
            }
            for(auto&neighbours : curr_node->connections_map){
                node*neighbour=neighbours.second.first;
                if(visited.find(neighbour)==visited.end()){
                    loc.push({neighbour,curr_node});
                } else {
                    if(neighbour->colored==curr_node->colored){
                        cout<<"Returning false"<<endl;
                        return false;
                    }
                }
            }
            return coloringUsingBFS(loc,!sign);
        }

        bool coloringGraphWhileCheckBFS(queue<pair<node*,node*>>&loc,bool color){
            if(loc.empty()){
                cout<<"Queue found empty that means all are colored safely"<<endl;
                return true;
            }
            int size=loc.size();
            while(size--){
                node*curr_node=loc.front().first;
                node*parent=loc.front().second;
                loc.pop();
              
                if(visited.find(curr_node)==visited.end()){
                    visited.insert(curr_node);
                    curr_node->colored=!parent->colored;
                } else {
                    if(curr_node->colored==parent->colored){
                        cout<<curr_node->data<<" & "<<parent->data<<" are colored same"<<endl;
                        return false;
                    }
                    cout<<"Revisited "<<curr_node->data<<endl;
                    continue;
                } 
                for(auto& neighbours:curr_node->connections_map){
                    node*neighbour=neighbours.second.first;
                    if(neighbour!=parent){
                        // if(visited.find(neighbour)==visited.end()){ //removed because in cylic structure thenode whehre two branches merge should also be check i.e. (cycle formed -> even edges or odd edges)
                        loc.push({neighbour,curr_node});
                        // }
                    }
                }
            }
            return coloringGraphWhileCheckBFS(loc,!color);
        }

        bool colorGraphAndCheckBipartiteness(){
            for(auto & it:dataset){
                it.second->colored=false;
            }
            visited.clear();
            cout<<" uncolored all nodes first"<<endl;
            int startData;
            cout<<"Enter node data from which to start coloring : ";
            cin>>startData;
            start=dataset[startData];
            cout<<"Starting from "<<start->data<<endl;
            node*temp=new node(-5);
            bool firstNodeColor;
            cout<<"Do you want start node to be colored?1 : Yes 0  : no\nYour choice : ";
            cin>>firstNodeColor;
            if(firstNodeColor){
                start->colored=true;
            } else {    
                temp->colored=true;
            }
            bool choice;
            cout<<"Which method to use to color the graph\n1 : DFS\n0 : BFS\nYour choice : ";
            cin>>choice;
            if(choice){
                // colorBipartiteDFS(start,temp);
            } else {
                queue<pair<node*,node*>>loc;
                loc.push({start,temp});
                bool Bipartite=coloringGraphWhileCheckBFS(loc,true);
                if(Bipartite){
                    cout<<"Graph colored sucessfuly"<<endl;
                    return true;
                } else {
                    cout<<"Grpah cannot be colored to create this graph Bypartite Graph"<<endl;
                    return false;
                }
                // queue<node*>loc;
                // loc.push(start);
                // colorBipartiteBFS(loc,true);
                // return;
            }
            cout<<"Invalid input"<<endl;
            delete temp;
            return false;
        }

        //isBypartite BFS + DFS Codes
        void isBypartiteQuestionCodes(){
            unordered_set<int>visited;
            unordered_map<int,bool>colored;
                        bool isBipartiteBFS(queue<pair<int,int>>&loc,vector<vector<int>>&adjacancyList){
                    if(loc.empty()){
                        // cout<<"Queue found empty"<<endl;
                        return true;
                    }
                    int size=loc.size();
                    while(size--){
                        int curr=loc.front().first;
                        int parent=loc.front().second;
                        // cout<<"Curr = "<<curr<<" & parent = "<<parent<<endl;
                        loc.pop();
                        if(visited.find(curr)==visited.end()){
                            visited.insert(curr);   
                            colored[curr]=!colored[parent];
                        } else {
                            if(colored[curr]==colored[parent]){
                                // cout<<curr<<" & "<<parent<<" are colored same"<<endl;
                                return false;
                            } else {
                                continue;
                            }
                        }
                        for(int neighbour:adjacancyList[curr]){
                            if(neighbour!=parent){
                                loc.push({neighbour,curr});
                            }
                        }
                    }
                    return isBipartiteBFS(loc,adjacancyList);
                }

                bool isBipartiteBFS2(queue<int>&loc,bool color,vector<vector<int>>&adjacancyList){
                    if(loc.empty())return true;
                    int size=loc.size();
                    while(size--){
                        int curr=loc.front();
                        loc.pop();
                        colored[curr]=color;
                        for(int neighbour:adjacancyList[curr]){
                            if(colored.find(neighbour)==colored.end()){
                                loc.push(neighbour);
                            } else if(colored[neighbour]==color){
                                return false;
                            }
                        }
                    }
                    return isBipartiteBFS2(loc,!color,adjacancyList);
                }

                bool isBipartiteDFS(int curr,int parent,vector<vector<int>>&adjacancyList){
                    if(visited.find(curr)==visited.end()){
                        visited.insert(curr);
                        colored[curr]=!colored[parent];
                    } else {
                        if(colored[curr]==colored[parent]){
                            cout<<curr<<" & "<<parent<<" are colored same"<<endl;
                            return false;
                        }
                        return true;
                    }
                    bool ret;
                    for(int neighbour: adjacancyList[curr]){
                        if(neighbour!=parent){
                            ret=isBipartiteDFS(neighbour,curr,adjacancyList);
                            if(!ret){
                                return false;
                            }
                        }
                    }
                    return true;
                
                }

                bool isBipartiteDFS2(int curr,int parent,vector<vector<int>>&adjacancyList){
                    colored[curr]=!colored[parent];
                    for(int neighbour: adjacancyList[curr]){
                        if(colored.find(neighbour)==colored.end()){
                            bool ret=isBipartiteDFS2(neighbour,curr,adjacancyList);
                            if(!ret)return false;
                        } else {
                            if(colored[neighbour]==colored[curr])return false;
                        }
                    }
                    return true;
                }

                bool isBipartiteDFS3(int curr,bool color,vector<vector<int>>&adjacancyList){
                    if(colored.find(curr)==colored.end())
                        colored[curr]=color;
                    else if(colored[curr]!=color)return false;
                    bool ret=true;
                    for(int neighbour : adjacancyList[curr]){
                        if(colored.find(neighbour)==colored.end()){
                            ret=isBipartiteDFS3(neighbour,!color,adjacancyList);
                            if(!ret)return false;
                        } else {
                            if(colored[neighbour]==color)return false;
                        }
                    }
                    cout<<"Retunring true from "<<curr<<endl;
                    return ret;
                }

        }

};

Graph*  Graph :: instance = nullptr;

void DFS_using_stack(stack<node*>&loc,node*&target,vector<string>&all_paths,string path="->"){
    if(loc.empty()){
        all_paths.push_back(path);
        cout<<"Stack is empty"<<endl;
        return;
    }
    auto it=loc.top();
    if(it->traversed)return;
    string add=to_string(it->data);
    if(it==target){
        cout<<add<<endl;
        cout<<"reached "<<target->data<<endl;
        all_paths.push_back(path);
        return;
    }
    if(it->connections_map.empty()){
        cout<<add<<endl;
        cout<<"From "<<it->data<<" no further connections possible"<<endl;
        all_paths.push_back(path+add);
        return;
    }
    it->traversed=true;
    int size=it->connections_map.size();
    unordered_map<int,pair<node*,int>>&connections_map=it->connections_map;
    
    for(auto next = connections_map.begin();next!=connections_map.end();next++){
        cout<<it->data<<" ";
        loc.push(next->second.first);
        DFS_using_stack(loc,target,all_paths,path+add+"->");
        loc.pop();
    }
    it->traversed=false;
    }

pair<node*,node*> getPair(Graph& graph){
    int start_data,target_data;
    cout<<"Enter start point for DFS : ";
    cin>>start_data;
    cout<<"Enter target : ";
    cin>>target_data;
    return {graph.dataset[start_data],graph.dataset[target_data]};
}

int getChoiceCreateGraph(){
    int choice;
    cout<<"Enter your choce :"<<endl;
    cout<<"1 : Manually"<<endl;
    cout<<"2 : Load Graph"<<endl;
    cout<<"3 : Create adjacancy list"<<endl;
    cout<<"Your choice : ";
    cin>>choice;
    return choice;
}

int getChoice(){
    int choice;
    cout<<"Enter your choce :"<<endl;
    cout<<"1 : DFS"<<endl;
    cout<<"2 : BFS"<<endl;
    cout<<"3 : Reach target by switching traversals"<<endl;
    cout<<"4 : Reach target via k intermediates"<<endl;
    cout<<"5 : Find no. of disconnected components"<<endl;
    cout<<"6 : Display adjacancy list"<<endl;
    cout<<"7 : Create adjacancy list"<<endl;
    cout<<"8 : Larget component"<<endl;
    cout<<"9 : Load graph again"<<endl;
    cout<<"10 : is cycle present"<<endl;
    cout<<"11 : Dijekstras"<<endl;
    cout<<"12 : Display Dijekstra's tabel for a node"<<endl;
    cout<<"13 : Shortest Distance from one node to another"<<endl;
    cout<<"14 : Dijekstra from start to Destination"<<endl;
    cout<<"15 : See heuristic values of a node"<<endl;
    cout<<"16 : A Star Algorithm"<<endl;
    cout<<"17 : Display heuristic values of all nodes"<<endl;
    cout<<"18 : Belmon Ford"<<endl;
    cout<<"19 : No of Provinces from Matrix"<<endl;
    cout<<"20 : No. of Islands"<<endl;
    cout<<"21 : AStar With K Intermediates"<<endl;
    cout<<"22 : Flood Fill"<<endl;
    cout<<"23 : Create Adjcancy Matrix from existing graph"<<endl;
    cout<<"24 : Display Adjacancy Matrix formed using Graph"<<endl;
    cout<<"25 : Create Matrix from file"<<endl;
    cout<<"26 : Rotten Oranges"<<endl;
    cout<<"27 : Matrix contain Cycles?"<<endl;
    cout<<"28 : is UNdirected Graph Cyclic using  BFS"<<endl;
    cout<<"29 : is Undirected Graph Cyclic BFS Improved"<<endl;
    cout<<"30 : Find nearest 0 in a martix"<<endl;
    cout<<"31 : Is Cyclic in Undirected Graph try 2"<<endl;
    cout<<"32 : Color a graph"<<endl;
    cout<<"33 : Is Graph Bipartite"<<endl;
    cout<<"34 : Display coloring of each node"<<endl;
    cout<<"35 : Color Graph and Check Bipartiteness"<<endl;
    cout<<"Your choice : ";
    cin>>choice;
    return choice;
}

void setDirection(){
    cout<<"Do you want Bidirectional graph (1 : Yes) : ";
    cin>>bidirectional;
}

int main(){
    vector<string>all_paths;
    unordered_map<int,node*>dataset;
    unordered_map<node*,list<node*>>map;
    Graph graph;
    int choice=getChoiceCreateGraph();
    //setDirection();
    if(choice==1)graph.createGraphManually(dataset);
    else if(choice==2) graph.loadGraph();

    unordered_map<node*,list<pair<node*,int>>>adjacancy_list;
    for(auto it=dataset.begin();it!=dataset.end();it++){
        for(auto neighbour=it->second->connections_map.begin();neighbour!=it->second->connections_map.end();neighbour++){
            // adjacancy_list[it]={neighbour->second.first,it->second->connections_map[neighbour->second.second]};
        }
    }

    while(choice){
        choice=getChoice();
        if(choice==1){
            pair<node*,node*>temp=getPair(graph);
            node*start=temp.first;
            node*target=temp.second;
            graph.DFS(start,target);
        } else if(choice==2){
            pair<node*,node*>temp=getPair(graph);
            node*start=temp.first;
            node*target=temp.second;
            graph.BFS(start,target);
        }
        else if(choice==3){
            graph.intermediateTraversal();
            cout<<"came out"<<endl;
        } else if(choice==4){
            graph.intermediateTraversal2();
        } else if(choice==5){
            graph.noOfDisconnectedComponents();
        } else if(choice==6){
            graph.displayAdjacancyList();
            graph.displayAdjacancyList2();
        } else if(choice==7){
            graph.createAdjacancyList();
        } else if(choice==8){
            graph.largestComponent();
        } else if(choice==9){
            graph.loadGraph();
        }
        else if(choice==10){
            bool isCyclePresent=graph.isCyclePresent();
            if(isCyclePresent){
                cout<<"Cycle is present in the graph"<<endl;
            } else {
                cout<<"Cycle is not present in the graph"<<endl;
            }
        }
        else if(choice==11){
            graph.Dijeskstras();
        }
        else if(choice==12){
            graph.DisplayDijekstrasTableOfANode();
        }
        else if(choice==13){
            graph.DijekstrasPointToPoint();
        }
        else if(choice==14){
            graph.DijekstrasOneToOne();
        }
        else if(choice==15){
            graph.displayHeuristicValuesOfANode();
        }
        else if(choice==16){
            graph.AStar();
        }
        else if(choice==17){
            graph.displayHeuristicValuesOfAllNodes();
        }
        else if(choice==18){
            graph.BelmanFord();
        }
        else if(choice==19){
            graph.noOfComponentsViaMatrix();
        }
        else if(choice==20){
            graph.noOfIslands();
        }
        else if(choice==21){
            graph.AStarKIntermediates();
        }
        else if(choice==22){
            graph.floodFill();
        } else if(choice==23){
            graph.createAdjacancyMatrixFromGraph();
        } else if(choice==24){
            graph.displayAdjcancyMatrixMadeFromGraph();
        }
        else if(choice==25){
            graph.loadMatrix();
        } else if(choice==26){
            graph.rottenOranges();
        }
        else if(choice==27){
            graph.containsCycle();
        }
        else if(choice==28){
            graph.isCyclicUndirectedBFS();
        } else if(choice==29){
            graph.isCyclicUndirectedDFS();
        }
        else if(choice==30){
            graph.nearest0InMatrix();
        }
        else if(choice==31){
            graph.isCyclicUndirected();
        }
        else if(choice==32){
            graph.colorBipartite();
        }
        else if(choice==33){
            graph.isBipartite();
        } else if(choice==34){
            graph.displayColoring();
        }
        else if(choice==35){
            graph.colorGraphAndCheckBipartiteness();
        }
    }
    // graph.delete_dataset(); //already included in the graph destructor
}