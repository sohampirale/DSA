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

node* add(int data,node*one_node){
    if(!one_node){
        one_node=new node(data);
        return one_node;
    }
    int lefth=0,righth=0;
    if(data<=one_node->data){
        one_node->left=add(data,one_node->left);
    }

    if(data>one_node->data){
        one_node->right=add(data,one_node->right);
    }

    if(one_node->right)righth=one_node->right->height;
    if(one_node->left)lefth=one_node->left->height;
    cout<<"righth = "<<righth<<" & lefth = "<<lefth<<" of "<<one_node->data<<endl;
    if(abs(lefth-righth)>1){
        if(!not_balanced_point)not_balanced_point=one_node;
        balanced=false;
    }
    int mx=max(righth,lefth)+1;
    one_node->height=mx;
   
    return one_node;

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

// void getMinMaxHeights(node*one_node,int level=0){
//     cout<<"hi"<<endl;
//     if(!one_node->left&&!one_node->right){
//         if(level>mx)mx=level;
//         if(level<mn)mn=level;
//         return;
//     } 
//     if(one_node->left){
//         getMinMaxHeights(one_node->left,level+1);
//     } 
//     if(one_node->right) {
//         getMinMaxHeights(one_node->right,level+1);
//     }
// }

int main(){
    int choice=1,data;
    node*root=nullptr;
    vector<int>max_heights;
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
            }
        }else if(choice==2){
            
        }
         else if(choice==3){
            preetyDisplayRight(root);
        }
    }
    delete_nodes(root);
} 