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
using namespace std;
bool bidirectional=false;
class node{
    public:
        int data;
        bool traversed=false;
        // vector<node*>connections;
        //              data    addr,dist
        unordered_map<int,pair<node*,int>>connections_map;
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
        vector<string>all_paths;
        int min_cost=0;
        string path_with_min_cost;

        void addAddrInQueue(node*&one_node,queue<node*>&loc,queue<int>&costs,int cost){
            if(!one_node)return;
            unordered_map<int,pair<node*,int>>&connections_map=one_node->connections_map;
            int size=connections_map.size();
            for(auto it=connections_map.begin();it!=connections_map.end();it++){
                loc.push(it->second.first);
                costs.push(cost+it->second.second);
            }
        }

        void BFS_helper(queue<node*>&loc,node*&target,queue<int>&costs,string path="->"){
            cout<<"Path : "<<path<<endl;
            if(loc.empty()){
                return;
            }
            auto it=loc.front();
            string add=to_string(it->data);
            if(it->traversed){
                cout<<"Revisited "<<add<<" via path : "<<path+add<<" with cost = "<<costs.front()<<endl;
                return;
            }
            else if(it==target){
                cout<<"Reached target with path : "<<path+add<<" & cost = "<<costs.front()<<endl;
                if(costs.front()<min_cost)min_cost=costs.front();
                all_paths.push_back(path+add);
                return;
            }
            int size=loc.size();
            for(int i=0;i<size;i++){
                auto front=loc.front();
                addAddrInQueue(front,loc,costs,costs.front());
                loc.pop();
                costs.pop();
                BFS_helper(loc,target,costs,path+add+"->");
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
            BFS_helper(loc,target,costs);
            display_all_paths();
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
                cout<<"revisited "<<add<<" by this path : "<<path+add<<" returnign form here"<<endl;
                all_paths.push_back(path+add);
                return;
            } else if(it==target){
                cout<<"Found target by path : "<<path+add<<" and with cost = "<<cost<<endl;
                all_paths.push_back(path+add);
                if(cost<min_cost){
                    min_cost=cost;
                    path_with_min_cost=path+add;
                }
                return;
            }
            it->traversed=true;            
            for(auto front=it->connections_map.begin();front!=it->connections_map.end();front++){
                loc.push(front->second.first);
                DFS_helper(loc,target,path+add+"->",cost+front->second.second);
                loc.pop();
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
            display_all_paths();
            if(min_cost!=INT_MAX){
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

        void loadGraph(unordered_map<int,node*>&dataset,unordered_map<node*,list<node*>>&map){
            string path="graphs_data/";
            bool custom;
            cout<<"Is the graph you want to load is custom graph?\nYour choice(1 : Yes 0 : No) : ";
            cin>>custom;
            if(custom){
                path+="custom_graphs/";
                string graphName;
                cout<<"Enter the custom name of the graph you want to load : ";
                cin>>graphName;
                graphName+=".txt";
                if(filesystem::exists(path+graphName)){
                    path+=graphName;
                    ifstream input(path,ios::in);
                    if(input.is_open()){
                        cout<<"opened "<<path<<endl;
                        loadFromFile(input,dataset,map);
                    } else cout<<"couldn't oepn the file "<<graphName<<endl;
                } else {
                    cout<<graphName<<" does not exist at "<<path<<endl;
                }
            } else{
                int total=totalGraphsPresent(),graphNo;
                cout<<"There are total "<<total<<" graphs present\nmEnter the graph you want to load (1-"<<total<<") : ";
                cin>>graphNo;
                path+="all_graphs/";
                string graphName="graph"+to_string(graphNo)+".txt";
                if(filesystem::exists(path+graphName)){
                    path+=graphName;
                    ifstream input(path,ios::in);
                    if(input.is_open()){
                        cout<<"opened "<<path<<endl;
                        loadFromFile(input,dataset,map);
                    } else cout<<"couldn't oepn the file "<<graphName<<endl;
                } else {
                    cout<<graphName<<" does not exist in the directory : "<<path<<endl;
                }
            }
        }

};

void delete_dataset(unordered_map<int,node*>&dataset){
    for(auto it = dataset.begin();it!=dataset.end();it++){
        delete it->second;
    }
}

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
    cout<<"2 : Extract data from files"<<endl;
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
    cout<<"Your choice : ";
    cin>>choice;
    return choice;
}

void setDirection(){
    cout<<"Do you want Bidirectional graph (1 : Yes) : ";
    cin>>bidirectional;
}

int main(){
    string test="12";
    string test2="34";
    stringstream ss(test);
    int t1,t2;
    ss>>t1;
    // t2=(test2)-'0';
    cout<<"t1 = "<<t1<<" & t2 = "<<t2<<endl;
    return 0;


    vector<string>all_paths;
    unordered_map<int,node*>dataset;
    unordered_map<node*,list<node*>>map;
    Graph graph;
    int choice=getChoiceCreateGraph();
    setDirection();
    if(choice==1)graph.createGraphManually(dataset);
    else if(choice==2) graph.extract_data_from_files(dataset);

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
        }
    }
    delete_dataset(dataset);
}