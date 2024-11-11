#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
        int data,height;
        node*left,*right;
        int index;
        node(int data):data(data),height(0),index(0){}
        node(int data,int index):data(data),index(index),height(0){}

        ~node(){
            cout<<"Deleting "<<data<<endl;
        }
};

int getHeight(node*& one_node){
   if(!one_node)return 0;
   else return one_node->height;
}

int getHeightDiff(node*&one_node){
    if(!one_node->left)return 0;
    else if(!one_node->right)return 1;
    int lefth=getHeight(one_node->left);
    int righth=getHeight(one_node->right);
    return lefth-righth;
}

bool goLeft(int lefth,int righth,int leftHeightDiff,int rightHeightDiff){
    if((lefth==righth)&&(leftHeightDiff==0)&&(rightHeightDiff==0)){
        cout<<"Data needs to be added to a new line left side"<<endl;
        return true;
    } else if((lefth>righth)&&(leftHeightDiff!=0)){
        cout<<"Data needed to be added somewhere on the left side"<<endl;
        return true;
    } else {
        cout<<"Returning false"<<endl;
        cout<<"lefth = "<<lefth<<endl;
        cout<<"righth = "<<righth<<endl;
        cout<<"leftHeightDiff = "<<leftHeightDiff<<endl;
        cout<<"rightHeightDiff = "<<rightHeightDiff<<endl;
        return false;
    }
}

void add(int data,node*one_node){
    if(!one_node->left){
        one_node->left=new node(data,(one_node->index*2)+1);
        cout<<data<<" added to left of "<<one_node->data<<endl;
        one_node->height=1;
        cout<<"Height of "<<one_node->data<<" is set to : "<<one_node->height<<endl;
        return;
    }
    if(!one_node->right){
        one_node->right=new node(data,(one_node->index*2)+2);
        cout<<data<<" added to right of "<<one_node->data<<endl;
        one_node->height=1;
        cout<<"Height of "<<one_node->data<<" is set to : "<<one_node->height<<endl;
        return;
    }
    int lefth=getHeight(one_node->left);
    int righth=getHeight(one_node->right);
    int leftHeightDiff=getHeightDiff(one_node->left);
    int rightHeightDiff=getHeightDiff(one_node->right);

    if(goLeft(lefth,righth,leftHeightDiff,rightHeightDiff)){
        cout<<"Decided to go left from "<<one_node->data<<endl;
        add(data,one_node->left);
        one_node->height=getHeight(one_node->left)+1;
        cout<<"Height of "<<one_node->data<<" is set to : "<<one_node->height<<endl;
        return;
    } else {
        cout<<"Decided to go right from "<<one_node->data<<endl;
        add(data,one_node->right);
        one_node->height=getHeight(one_node->left)+1;
        cout<<"Height of "<<one_node->data<<" is set to : "<<one_node->height<<endl;
        return;
    }
}

void delete_nodes(node*&one_node){
    if(!one_node)return;
    delete_nodes(one_node->left);
    delete_nodes(one_node->right);
    delete one_node;
}

void preetyDisplayRight(node*&one_node,int level=0){
    if(!one_node)return;
    if(one_node->right)preetyDisplayRight(one_node->right,level+1);
    if(level!=0){
        for(int i=0;i<level-1;i++)cout<<"|\t";
        cout<<"|----->"<<one_node->data<<endl;
    } else cout<<one_node->data<<endl;
    if(one_node->left)preetyDisplayRight(one_node->left,level+1);
}

void preetyDisplayRightIndexes(node*&one_node,int level=0){
    if(!one_node)return;
    if(one_node->right)preetyDisplayRight(one_node->right,level+1);
    if(level!=0){
        for(int i=0;i<level-1;i++)cout<<"|\t";
        cout<<"|----->"<<one_node->index<<endl;
    } else cout<<one_node->index<<endl;
    if(one_node->left)preetyDisplayRight(one_node->left,level+1);
}

int main(){
    node*root=nullptr;
    int choice=1,data;
    while(choice){
        cout<<"1 : Add node\n2 : search for sum\n3 : Display Tree\n4 : Display indexes\nYour choice : ";
        cin>>choice;
        if(choice==1){
            cout<<"Enter data : ";
            cin>>data;
            if(!root)root=new node(data,0);
            else add(data,root);
        } else if(choice==3){
            preetyDisplayRight(root);
        } else if(choice==4){
            preetyDisplayRightIndexes(root);
        }
    }
    delete_nodes(root);
}