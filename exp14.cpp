//Roll no - 2022
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        vector<node*>connections;
        node(int data):data(data){}
};
void printAdjacancyList(unordered_map<node*,list<node*>>&map){
    for(auto it=map.begin();it!=map.end();it++){
        cout<<it->first->data<<" is connected with nodes ->";
        for(auto item : it->second){
            cout<<item->data<<" ";
        }
        cout<<endl;
    }
}
int main(){
    unordered_map<node*,list<node*>>map;
    int n,data;
    cout<<"How many nodes you have : ";
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cout<<"Enter data of node no-"<<i+1<<" : ";
        cin>>data;
        node*one_node=new node(data);
        list<node*>temp;
        cout<<"How many edges are present for "<<data<<" : ";
        cin>>k;
        for(int j=0;j<k;j++){
            cout<<"ENter data of neighbour no - "<<j+1<<" : ";
            cin>>data;
            temp.push_back(new node(data));
        }
        map[one_node]=temp;
    }
    printAdjacancyList(map);
}