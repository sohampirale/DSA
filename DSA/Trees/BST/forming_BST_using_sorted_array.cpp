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

void delete_nodes(node*root){
    if(root==nullptr){
        // cout<<"Hit null"<<endl;
        return;
    }
    delete_nodes(root->left);
    delete_nodes(root->right);
    delete root;
}

void createBSTfromSorted(vector<int>&nums,int st,int end,node*&root){
    if(st>end)return;
    int mid=st+(end-st)/2;
    if(!root)root=new node(nums[mid]);
    else add(nums[mid],root);
    createBSTfromSorted(nums,st,mid-1,root);
    createBSTfromSorted(nums,mid+1,end,root);
}

int main(){
    node* root=nullptr;
    vector<int>nums={1,2,3,4,5,6,7,8,9,10};
    createBSTfromSorted(nums,0,nums.size()-1,root);
    preetyDisplayRight(root);
    delete_nodes(root);
} 