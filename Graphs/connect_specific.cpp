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

        node(int data):data(data){
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
        node* destination=nullptr;
        bool flag=false;

        Graph(){
            signal(SIGSEGV, signalHandler); //  segmentation fault
            signal(SIGTSTP, signalHandler); //  cntl + Z
            instance=this;
        }

        ~Graph(){
            delete_dataset();
        }

        class DijekstrasCompare{
            public:     
                bool operator()(const node* n1,const node* n2){
                    return n1->data>n2->data;
                }
        };

        class AStartCompare{
            public:
                bool operator()(const node*n1,const node* n2){
                    return n1->costWithHeuristicValue>n2->costWithHeuristicValue;
                }
        };

        static void signalHandler(int signum) {
            cout << "Caught signal " << signum << ". deallocating nodes..." << endl;
            if(instance){
                instance->delete_dataset();
            }
            exit(signum);
        }

        void delete_dataset(){
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
            bool heuristicPresent;
            cout<<"Does this graph have heiristic values? 1 : Yes 0 : No\nYour chocie : ";
            cin>>heuristicPresent;
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

        void AStartHelper(priority_queue<node*,vector<node*>,AStartCompare>&loc,unordered_set<node*>&visited){

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
                    cout<<"Looking for "<<it->first<<endl;
                    int newCost=current_node->cost+it->second.second+it->second.first->HeuristicValues[destination];
                    if(it->second.first->costWithHeuristicValue>newCost){
                        it->second.first->costWithHeuristicValue=newCost;
                        it->second.first->reachedFrom=current_node->data;
                        it->second.first->cost=current_node->cost+it->second.second;
                        loc.push(it->second.first);
                    }
                } else {
                    cout<<it->first<<" is already visited by "<<it->second.first->reachedFrom-1<<endl;
                }
            }
            AStartHelper(loc,visited);
        }

        void AStar(){
            for(auto it=dataset.begin();it!=dataset.end();it++){
                it->second->costWithHeuristicValue=INT_MAX;
                it->second->cost=INT_MAX;
            }
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
            priority_queue<node*,vector<node*>,AStartCompare>loc;
            loc.push(start);
            cout<<loc.top()->data<<" is at the top let's start AStar"<<endl;
            AStartHelper(loc,visited);
            cout<<"AStar Algorithm Done"<<endl;
            cout<<"destination->costWithHeuristicValue = "<<destination->costWithHeuristicValue<<endl;
            cout<<"destination->cost = "<<destination->cost<<endl;
            cout<<"All th enodes traversed are : ";
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
    }
    // graph.delete_dataset();
}