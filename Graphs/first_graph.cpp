#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class node{
    public:
        int data;
        vector<node*>connections;
        node(int data):data(data){
            cout<<data<<" created"<<endl;
        }
        void connect_to(node*one_node){
            // if(find(connections.begin(),connections.end(),one_node)!=connections.end()){
            //     cout<<this->data<<" is already connected with "<<one_node->data<<endl;
            // } else {
                // connections.resize(size+1);
                try{
                    connections.push_back(one_node);
                    cout<<this->data<<" is connected with "<<one_node->data<<endl;
                } catch(...){
                    cout<<"Faile dot connect to "<<one_node->data<<endl;
                }
            // }
        } 
        void display_connections(){
            cout<<this->data<<" is connected with nodes : ";
            for(auto it : connections){
                cout<<it->data<<" ";
            }
            cout<<endl;
        }
        ~node(){
            cout<<"Deleting "<<this->data<<endl;
        }

};
void delete_all_nodes(vector<node*>&all_nodes){
    for(auto it : all_nodes){
        delete it;
    }
}
int main(){
    int n;
    cout<<"How many nodes you have : ";
    cin>>n;
    vector<int>data(n);
    cout<<"Enter data of "<<n<<" nodes : "<<endl;
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    node*start=nullptr;
    vector<node*>all_nodes;
    for(int i=0;i<n;i++){
        node*one_node=new node(data[i]);
        all_nodes.push_back(one_node);
    }
    cout<<"All nodes created"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            all_nodes[i]->connect_to(all_nodes[j]);
        }
    }
    
    cout<<"All nodes are interconencted now"<<endl;
     for(int i=0;i<n;i++){
        all_nodes[i]->display_connections();
    }
    delete_all_nodes(all_nodes);
}