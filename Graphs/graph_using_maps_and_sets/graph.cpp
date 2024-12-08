#include<iostream>
#include<set>
#include<unordered_map>
using namespace std;
class node{
    public:
        int data;
        unordered_map<int,node*>connections;
        node(int data):data(data){
            cout<<"Created "<<data<<endl;
        }

        void setConnections(unordered_map<int,node*>&dataset){
            int k,data;
            cout<<"How many connections does "<<this->data<<" has : ";
            cin>>k;
            for(int i=0;i<k;i++){
                cout<<"Enter data of neighbour no - "<<i+1<<" : ";
                cin>>data;
                auto it=dataset.find(data);
                if(it==dataset.end()){
                    dataset[data]=new node(data);
                }                
                connections[data]=dataset[data];
            }
            cout<<connections.size()<<" neighbours are connected to "<<this->data<<endl;
        }

        ~node(){
            cout<<"Deleting "<<this->data<<endl;
        }
};

void displayNeighbours(set<node*>&neighbours){
    for(auto & it : neighbours){
        cout<<it->data<<" ";
    }
    cout<<endl;
}

void deleterAllNodes(unordered_map<int,node*>&dataset){
    for(auto& it : dataset){
        delete it.second;
    }
}

int main(){
    // set<node*>s;
    // unordered_map<int,pair<node*,set<node*>>>map;
    // unordered_map<int,node*>dataset;
    // int n,data;
    // cout<<"How many nodes you have : ";
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     cout<<"Enter data of node no - "<<i+1<<" : ";
    //     cin>>data;
    //     node*one_node=new node(data);
    //     dataset[data]=one_node;
    // }
    // int k;
    // for(auto &it : dataset){
    //     cout<<"How many neighbours does "<<it.first<<" has : ";
    //     cin>>k;
    //     set<node*>temp;
    //     for(int i=0;i<k;i++){
    //         cout<<"Enter data of neighbour no - "<<i+1<<" : ";
    //         cin>>data;
    //         temp.insert(dataset[data]);
    //     }
    //     map[it.first]={dataset[it.first],temp};
    //     cout<<it.first<<" has "<<map[it.first].second.size()<<" neighbours -> ";
    //     displayNeighbours(map[it.first].second);
    // }
    // cout<<"out of logic"<<endl;
    // return 0;
    
//Creating nodes an dinitializing its neighbour sat the same time (creating new nodes if not found)
    // unordered_map<int,node*>dataset;
    // int n,data;
    // cout<<"How many ndoes you have : ";
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     cout<<"Enter data of node no - "<<i+1<<" : ";
    //     cin>>data;
    //     auto it=dataset.find(data);
    //     if(it==dataset.end()){
    //         dataset[data]=new node(data);
    //     }
    //     dataset[data]->setConnections(dataset);
    // }
    // cout<<"SIze of the dataset : "<<dataset.size()<<endl;
    // deleterAllNodes(dataset);
}