#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        unordered_map<int,node*>connections;
        node(int data):data(data){}
};
void displayAdjacancyList(unordered_map<node*,list<node*>>&adjacancy_list){
    for(auto it=adjacancy_list.begin();it!=adjacancy_list.end();it++){
        cout<<it->first->data<<" is connected with "<<it->second.size()<<" neighbours\n"<<it->first->data<<"|";
        for(auto neighbour=it->second.begin();neighbour!=it->second.end();neighbour++){
            cout<<"->"<<(*neighbour)->data;
        }
        cout<<endl;
    }
}
void deleteAllNode(unordered_map<int,node*>&dataset){
    for(auto it=dataset.begin();it!=dataset.end();it++){
        delete it->second;
    }
}

int main(){

    unordered_map<int,node*>dataset;
    unordered_map<node*,list<node*>>adjacancy_list;
    int n,data,k;
    cout<<"How many nodes are present : ";
    cin>>n;
    cout<<"Enter data of "<<n<<" nodes : ";
    for(int i=0;i<n;i++){
        cin>>data;
        node*one_node=new node(data);
        dataset[data]=one_node;
    }
    for(auto it=dataset.begin();it!=dataset.end();it++){
        cout<<"How many neighbours does "<<it->second->data<<" has : ";
        cin>>k;
        for(int i=0;i<k;i++){
            cout<<"Enter data of neighbour no "<<i+1<<" : ";
            cin>>data;
            auto neighbour=dataset.find(data);
            if(neighbour!=dataset.end()){
                adjacancy_list[it->second].push_front(neighbour->second);
            } else {
                cout<<"No node found with data : "<<data<<" in the dataset"<<endl;
            }
        }
    }
    displayAdjacancyList(adjacancy_list);
}
