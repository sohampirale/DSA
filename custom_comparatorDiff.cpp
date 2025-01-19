//About custom Comparator
    //For set               n1 : new one
    //For priority queue    n2 : new one

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node(int data):data(data){
            cout<<data<<" created"<<endl;
        }
        
        ~node(){
            cout<<"Deleting "<<this->data<<endl;
        }

};

class compareNodesByData{
    public:
        bool operator()(const node*n1,const node*n2)const{
            return n1->data>n2->data;
        }
};

int main(){
    set<node*,compareNodesByData>testSet;
     node* n1=new node(10);
    node* n2=new node(20);
    node* n3=new node(30);
    node* n4=new node(40);
    testSet.insert(n4);
    testSet.insert(n3);
    testSet.insert(n2);
    testSet.insert(n1);
    cout<<"test set : ";
    while(!testSet.empty()){
        cout<<(*testSet.begin())->data;
        testSet.erase(testSet.begin());
    }
    cout<<endl;
    priority_queue<node*,vector<node*>,compareNodesByData>loc;
    loc.push(n1);
    loc.push(n2);
    loc.push(n3);
    loc.push(n4);
    cout<<"Queue : ";
    while(!loc.empty()){
        cout<<loc.top()->data<<" ";
        loc.pop();
    }
    delete n1;
    delete n2;
    delete n3;
    delete n4;

    return 0;
}