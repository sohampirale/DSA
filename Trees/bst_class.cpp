#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
        int data;
        node*left,*right;
    node(int data):data(data),left(nullptr),right(nullptr){}

    ~node(){
        cout<<"Deleting "<<this->data<<endl;
    }

};

class BinaryTree{
    public:

        node*root;

        BinaryTree():root(nullptr){
            cout<<"New BT created"<<endl;
        }

        void add(int data,node*&one_node){
          
            if(!one_node){ 
                cout<<"Created first node of the BT"<<endl;
                this->root=new node(data);
                return;
            }

            if(data<one_node->data){
                if(!one_node->left){
                    one_node->left=new node(data);
                    cout<<data<<" created to the left of "<<one_node->data<<endl;
                    return;
                }
                add(data,one_node->left);
            } else {    
                if(!one_node->right){
                    one_node->right=new node(data);
                    cout<<data<<" created to the right of "<<one_node->data<<endl;
                    return;
                }
                add(data,one_node->right);    
            }
        }

        int findSum(node*&one_node){
            if(!one_node)return 0;
            return one_node->data+findSum(one_node->left)+findSum(one_node->right);
        }
};

void add(vector<BinaryTree>&all_BT,int& data){
    if(all_BT.empty()){
        cout<<"We need to create a BT first"<<endl;
        return;
    }
    int choice;
    cout<<"We have "<<all_BT.size()<<" BT's in which you want to insert "<<data<<endl;
    cout<<"Your choice : (1-"<<all_BT.size()<<") : ";
    cin>>choice;
    all_BT[choice-1].add(data,all_BT[choice-1].root);
}

void delete_node(node*temp){
    if(temp==nullptr)return;
    delete_node(temp->left);
    delete_node(temp->right);
    delete temp;
}

void delete_all_nodes(vector<BinaryTree>&all_BT){
    for(int i=0;i<all_BT.size();i++){
        if(all_BT[i].root)
            delete_node(all_BT[i].root);
        else cout<<"BT no - "<<i+1<<" is already empty so cannot delete anything"<<endl;
    }
}

int findSum(vector<BinaryTree>&all_BT){
    int choice;
    cout<<"Enter which BT you want find sum of (1-"<<all_BT.size()<<" : ";
    cin>>choice;
    return all_BT[choice-1].findSum(all_BT[choice-1].root);
}
int main(){
    int choice=1,data;
    vector<BinaryTree>all_BT;
    while(choice!=0){
        cout<<"1 : create new BT\n2 : Add node in a BT\n3 : Search a node in BT's\n4 : Find sum of all nodes in Tree\nYour choice : ";
        cin>>choice;
        if(choice==1){
            BinaryTree bt;
            all_BT.push_back(bt);
        } else if(choice==2){
            cout<<"Enter data : ";
            cin>>data;
            add(all_BT,data);
        } else if(choice==3){

        } else if(choice==4){
            int sum=findSum(all_BT);
            cout<<"Sum of all nodes : "<<sum<<endl;
        }
    }
    delete_all_nodes(all_BT);
}