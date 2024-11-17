#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
#include<climits>
using namespace std;
class node{
    public:
        int data;
        bool traversed=false;
        // vector<node*>connections;
        unordered_map<int,pair<node*,int>>connections_map;
        node(int data):data(data){
            cout<<data<<" created"<<endl;
        }
        
        void connect_to(node*one_node,int dist){
            if(connections_map.find(one_node->data)==connections_map.end()){
                pair<node*,int>temp={one_node,dist};
                connections_map[one_node->data]=temp;
                cout<<this->data<<" is connected with "<<one_node->data<<" with distance : "<<temp.second<<endl;
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
       
        node* find(vector<node*>&all_nodes,int data){
            for(auto it=all_nodes.begin();it!=all_nodes.end();it++){
                if((*it)->data==data){
                    return *it;
                }
            } 
            return nullptr;
        }
        
        void connect_to_helper(unordered_map<int,node*>&all_nodes){
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
                node* one_node=all_nodes[data];
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
        unordered_map<int,node*>all_nodes;
        vector<string>all_paths;
        int min_cost=0;
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
            it->traversed=true;
            int size=loc.size();
            for(int i=0;i<size;i++){
                auto front=loc.front();
                addAddrInQueue(front,loc,costs,costs.front());
                loc.pop();
                costs.pop();
                BFS_helper(loc,target,costs,path+add+"->");
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

        void connect_all_nodes(unordered_map<int,node*>&all_nodes){
            for(auto it=all_nodes.begin();it!=all_nodes.end();it++){
                    it->second->connect_to_helper(all_nodes);
            }
            cout<<"All nodes connected"<<endl;
        }

        void create_graph(unordered_map<int,node*>&all_nodes){
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
                all_nodes[data[i]]=one_node;
            }
            cout<<"All nodes created"<<endl;
            this->all_nodes=all_nodes;
            connect_all_nodes(all_nodes);
            display_all_connections(all_nodes);

        }

        void display_all_connections(unordered_map<int,node*>&all_nodes){
            for(auto node =all_nodes.begin();node!=all_nodes.end();node++){
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
                cout<<"before min cost = "<<min_cost<<endl;
                if(cost<min_cost)min_cost=cost;
                cout<<"after min cost = "<<min_cost<<endl;
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
            all_paths.clear();
            stack<node*>loc;
            loc.push(start);
            DFS_helper(loc,target);
            display_all_paths();
            cout<<"Minimum cost required was : "<<min_cost<<endl;
        }

        void display_all_paths(){
            if(all_paths.empty())return;
            for(string str : all_paths){
                cout<<str<<endl;
            }
        }

};

void delete_all_nodes(unordered_map<int,node*>&all_nodes){
    for(auto it = all_nodes.begin();it!=all_nodes.end();it++){
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
    return {graph.all_nodes[start_data],graph.all_nodes[target_data]};
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

int main(){
    vector<string>all_paths;
    unordered_map<int,node*>all_nodes;
    Graph graph;
    graph.create_graph(all_nodes);

    int choice=1;
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
    }
    delete_all_nodes(all_nodes);
}