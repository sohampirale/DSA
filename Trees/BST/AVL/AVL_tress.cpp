#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class node{
    public:
        int data,height;
        node*left,*right;
        node(int data){
            this->data=data;
            this->left=nullptr;
            this->right=nullptr;
            this->height=0;
        }
        ~node(){
            cout<<"Deleting "<<this->data<<endl;
        }
};

void preetyDisplayRight(node*&one_node,int level=0){
    if(!one_node)return;
    if(one_node->right)preetyDisplayRight(one_node->right,level+1);
    if(level!=0){
        for(int i=0;i<level-1;i++)cout<<"|\t";
        cout<<"|----->"<<one_node->data<<endl;
    } else cout<<one_node->data<<endl;
    if(one_node->left)preetyDisplayRight(one_node->left,level+1);
}

int getHeight(node*&one_node){
    if(!one_node)return -1;
    return one_node->height;
}

void setHeight(node*& one_node){
    one_node->height=max(getHeight(one_node->left),getHeight(one_node->right))+1;
}

node* rightShift(node*&one_node,node*&root){
    cout<<"Doing right shift around "<<one_node->data<<endl;
    node*temp=one_node->left;
    if(root==one_node){
        root=temp;
        cout<<"Changing root to "<<root->data<<endl;
    }
    one_node->left=temp->right;
    temp->right=one_node;
    setHeight(one_node);
    setHeight(temp);
    return temp;
}

node* leftShift(node*&one_node,node*&root){
    cout<<"Doing leftShift around "<<one_node->data<<endl;
    node*temp=one_node->right;
    if(root==one_node){
        root=temp;
        cout<<"Changing root to "<<root->data<<endl;
    }
    one_node->right=temp->left;
    temp->left=one_node;
    setHeight(one_node);
    setHeight(temp);
    return temp;
}

node* rotate(node*&one_node,node*&root){
    int righth=getHeight(one_node->right);
    if(righth==-1)righth=0;
    int lefth=getHeight(one_node->left);
    if(lefth==-1)lefth=0;
    if(righth-lefth>1){
        if(getHeight(one_node->right->left) >getHeight(one_node->right->right)){
            cout<<"right left case"<<endl;
            one_node->right=rightShift(one_node->right,root);
            // preetyDisplayRight(root);
            return leftShift(one_node,root);
        } else {
            cout<<"Right right case"<<endl;
            return leftShift(one_node,root);
        }
    } else if(lefth-righth >1){
        if(getHeight(one_node->left->left) >getHeight(one_node->left->right)){
            cout<<"left left case"<<endl;
            return rightShift(one_node,root);
        } else {
            cout<<"left right case"<<endl;
            one_node->left=leftShift(one_node->left,root);
            // preetyDisplayRight(root);
            return rightShift(one_node,root);
        }
    }
    cout<<"No need to rotate for "<<one_node->data<<endl;
    return one_node;
}

node* add(node*&one_node,node*&root,int data){
    if(!one_node){
        cout<<"Node "<<data<<" added"<<endl;
        return new node(data);
    }

    if(data<=one_node->data){
        one_node->left=add(one_node->left,root,data);
    }

    if(data>one_node->data){
        one_node->right=add(one_node->right,root,data);
    }

    one_node=rotate(one_node,root);
    one_node->height=max(getHeight(one_node->right),getHeight(one_node->left))+1;
    return one_node;
}

void delete_nodes(node*&one_node){
    if(!one_node)return;
    delete_nodes(one_node->left);
    delete_nodes(one_node->right);
    delete one_node;
}

int main(){
    int choice=1,data;
    node*root=nullptr;
    while(choice){
        cout<<"1 : Add node\n2 : Display\nYour choice : ";
        cin>>choice;
        if(choice==1){
            cout<<"Enter data : ";
            cin>>data;
            try{
                if(!root)root=new node(data);
                else root=add(root,root,data);
            } catch(...){
                cout<<"Error occured"<<endl;
            }
        } else if(choice==2){
            preetyDisplayRight(root);
        }
    }
    cout<<"Came out"<<endl;
    delete_nodes(root);
}    