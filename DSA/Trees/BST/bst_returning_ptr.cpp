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



bool isBalancedTree(node*&root){
    if(!root)return true;
    return abs(getHeightNode(root->left)-getHeightNode(root->right))<=1&&isBalancedTree(root->left)&&isBalancedTree(root->right);
}


int main(){
    cout<<abs(2-(-1))<<endl;
    return 0;
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


//wrong because not checking wehther the node* ptr is null or not and directly acesingthe ->height attribute
// bool isBalanced1(node*&root){
//     if(!root)return true;
//     return abs(root->left->height-root->right->height)<=1&&isBalanced1(root->left)&&isBalanced1(root->right);
// }

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