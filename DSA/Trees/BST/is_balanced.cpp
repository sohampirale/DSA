#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class node{
    public:
        int data;
        node*left,*right;
        node(int data){
            this->data=data;
            this->left=nullptr;
            this->right=nullptr;
        }
        ~node(){
            cout<<"Deleting "<<this->data<<endl;
        }
};



void add(int data,node*&t){
    if(t==nullptr){
        cout<<"First node of BST  created"<<endl;
        t=new node(data);
        return;
    }

    if(data<t->data){
        if(!t->left){
            t->left=new node(data);
            cout<<"CReated a left child of "<<t->data<<endl;
            return;
        } else {
           add(data,t->left);
           return;
        }
    } else {
        if(!t->right){
            t->right=new node(data);
            cout<<"Right child created of "<<t->data<<endl;
            return;
        } else {
                add(data,t->right);
                return;
            }
    }
}

void delete_nodes(node*root){
    if(root==nullptr){
        // cout<<"Hit null"<<endl;
        return;
    }
    delete_nodes(root->left);
    delete_nodes(root->right);
    delete root;
}

//went to rigthmost first
void preetyDisplayRight(node*&one_node,int level=0){
    if(!one_node)return;
    if(one_node->right)preetyDisplayRight(one_node->right,level+1);
    if(level!=0){
        for(int i=0;i<level-1;i++)cout<<"|\t";
        cout<<"|----->"<<one_node->data<<endl;
    } else cout<<one_node->data<<endl;
    if(one_node->left)preetyDisplayRight(one_node->left,level+1);
}


//went to leftmost first
void preetyDisplayLeft(node*&one_node,int level=0){

    if(!one_node)return;
    if(one_node->left)preetyDisplayLeft(one_node->left,level+1);
    if(level!=0){
        for(int i=0;i<level-1;i++)cout<<"|\t";
        cout<<"|----->"<<one_node->data<<endl;
    } else cout<<one_node->data<<endl;
    if(one_node->right)preetyDisplayLeft(one_node->right,level+1);
}

int mn=100,mx=0;
void isBalanced(node*&one_node,vector<int>&max_heights,int level=0){
    if(!one_node)return;
    // cout<<"on "<<one_node->data<<endl;
    if(!one_node->right&&!one_node->left){
        // cout<<"mx = "<<mx<<" & mn = "<<mn<<endl;
        if(level>mx)mx=level;
        if(level<mn)mn=level;
        return;
    }
    isBalanced(one_node->left,max_heights,level+1);
    isBalanced(one_node->right,max_heights,level+1);
    // max_heights.push_back(level);
}
int main(){
    int choice=1,data;
    node*root=nullptr;
    vector<int>max_heights;
    while(choice!=0){
        cout<<"1 : Add data\n2 : Find min max heights & verify balanced or not\n3 : Display\nYour choice : ";
        cin>>choice;
        if(choice==1){
            cout<<"ENter data : ";
            cin>>data;
           add(data,root);
        }else if(choice==2){
            isBalanced(root,max_heights,0);
            // cout<<"Max heights vetcor is : ";
            // for(int i=0;i<max_heights.size();i++)cout<<max_heights[i]<<" ";
            cout<<"Mx = "<<mx<<" & mn = "<<mn<<endl;
            if(mx-mn<=1)cout<<"Balanced"<<endl;
            else cout<<"Not balanced"<<endl;
            mn=1000;
            mx=0;
        }
        else if(choice==3){
            preetyDisplayRight(root);
        }
    }
    delete_nodes(root);
} 