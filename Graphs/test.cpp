#include<iostream>
#include<unordered_set>
using namespace std;
unordered_set<node*>nodes;

class node{
    public:
        int data;
        node(int data):data(data){}

        static void cleanup(){
            for(auto it=nodes.begin();it!=nodes.end();it++){
                delete (*it);
            }
        }
        
        ~node(){
            cout<<"deleting "<<this->data<<endl;
        }
};
// unordered_set<node*> node::nodes; 
node*  operator *(size_t size){
    node* ptr= new node(size);
    // node:: nodes.insert(ptr);
    return ptr;
}

int main(){
    node*one_node=new node(10);
    one_node=new node(20);
    one_node=new node(30);
    one_node=new node(40);
    one_node=new node(50);
    node n(35);

    cout<<"Node created"<<endl;
    node::cleanup();
    return 0;
}