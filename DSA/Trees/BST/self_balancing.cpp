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
    
bool balanced=true;
node* not_balanced_point;

int getHeightNode(node*&one_node){
    if(!one_node)return 0;
    return one_node->height;
}

bool isBalancedNode(node*& one_node){
    int righth=getHeightNode(one_node->right);
    int lefth=getHeightNode(one_node->left);
    cout<<"righth = "<<righth<<" & lefth = "<<lefth<<" of "<<one_node->data<<endl;
    one_node->height=max(righth,lefth)+1;
    return abs(righth-lefth)<=1;
}

node* add(int data,node*one_node){
    if(!one_node){
        one_node=new node(data);
        return one_node;
    }
    if(data<=one_node->data){
        one_node->left=add(data,one_node->left);
    }

    if(data>one_node->data){
        one_node->right=add(data,one_node->right);
    }
    
    if(!isBalancedNode(one_node)){
        if(!not_balanced_point)not_balanced_point=one_node;
        balanced=false;
    }
   
    return one_node;
}

void delete_nodes(node*root){
    if(root==nullptr){
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

void CreateBTFromSortedArray(node*&root,vector<int>&all_nums,int st,int end){
    if(st>end)return;
    int mid=st+(end-st)/2;
    if(!root)root=new node(all_nums[mid]);
    else add(all_nums[mid],root);
    
    CreateBTFromSortedArray(root,all_nums,st,mid-1);
    CreateBTFromSortedArray(root,all_nums,mid+1,end);
}

bool isBalancedTree(node*&root){
    if(!root)return true;
    return abs(getHeightNode(root->left)-getHeightNode(root->right))<=1&&isBalancedTree(root->left)&&isBalancedTree(root->right);
}

void inorder(node*one_node,vector<int>&all_nums){
    if(!one_node)return;
    inorder(one_node->left,all_nums);
    all_nums.push_back(one_node->data);
    inorder(one_node->right,all_nums);
}

void getBalanced(node*&root){
    vector<int>all_nums;
    inorder(root,all_nums);
    delete_nodes(root);
    root=nullptr;
    CreateBTFromSortedArray(root,all_nums,0,all_nums.size()-1);
}

int main(){
    int choice=1,data;
    node*root=nullptr;
    while(choice!=0){
        cout<<"1 : Add data\n2 : Get min max heights\n3 : Display\nYour choice : ";
        cin>>choice;
        if(choice==1){
            cout<<"ENter data : ";
            cin>>data;
            if(!root)root=new node(data);
            else add(data,root);
            if(balanced)cout<<"Tree is balanced"<<endl;
            else {
                cout<<"Tree is not balanced"<<endl;
                balanced=true;
                cout<<"because of node at "<<not_balanced_point->data<<endl;
                not_balanced_point=nullptr;
                cout<<"Calling getbalanced"<<endl;
                getBalanced(root);
                cout<<"Came out of getBalanced funciton call"<<endl;
            }
            cout<<"isBalancedTree(root) = "<<isBalancedTree(root)<<endl;
        }else if(choice==2){
            
        }
         else if(choice==3){
            preetyDisplayRight(root);
        }
    }
    delete_nodes(root);
} 