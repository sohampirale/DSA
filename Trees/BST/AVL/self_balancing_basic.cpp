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
    
bool child_left,grandchild_left,balanced=true;
node* not_balanced_point;
node*parent,*child,*grandchild;

void leftShiftToC(){
    cout<<"Turning left shift to "<<child->data<<endl;
    parent->left=grandchild;
    child->right=grandchild->left;
    grandchild->left=child;
}

void rightShiftToC(){
    cout<<"Doing right shift to "<<child->data<<endl;
    parent->right=grandchild;
    child->left=grandchild->right;
    grandchild->right=child;
}

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

void resertHeights(){
    parent->height=max(getHeightNode(parent->left),getHeightNode(parent->right))+1;
    child->height=max(getHeightNode(child->left),getHeightNode(child->right))+1;
    grandchild->height=max(getHeightNode(grandchild->left),getHeightNode(grandchild->right))+1;
    cout<<"After resettign heights"<<endl;
    cout<<"Parent height : "<<parent->height<<endl;
    cout<<"child height : "<<child->height<<endl;
    cout<<"grandchild height : "<<grandchild->height<<endl;
}

void rightShiftToP(node*&root,node*parent,node*child){
    cout<<"Right shifting to "<<parent->data<<endl;
    if(root==parent){
        root=child;
        cout<<"Changed root to "<<root->data<<endl;    
    }
    parent->left=child->right;
    child->right=parent;
}

void leftShiftToP(node*&root,node*parent,node*child){
    cout<<"Left shifting to "<<parent->data<<endl;
    if(root==parent){
        root=child;
        cout<<"Root changed to "<<root->data<<endl;
    }
    parent->right=child->left;
    child->left=parent;
}

void setGrandChild(node*&child){
    int righth=getHeightNode(child->right);
    int lefth=getHeightNode(child->left);
    //below two lines are maybe unnecessary
    if(!parent->left)lefth=-1;
    if(!parent->right)righth=-1;

    if(righth>lefth){
        grandchild=child->right;
        grandchild_left=false;    
    }
    else {
        grandchild=child->left;
        grandchild_left=true;    
    }
    cout<<"Grand Child is set to "<<grandchild->data<<endl;
}

void setChild(node*&parent){
    int righth=getHeightNode(parent->right);
    int lefth=getHeightNode(parent->left);
    //below two lines are maybe unnecessary
    if(!parent->left)lefth=-1;
    if(!parent->right)righth=-1;
    
    if(righth>lefth){
        child=parent->right;
        child_left=false;
    }
    else {
        child=parent->left;
        child_left=true;
    }
    cout<<"Child is set to "<<child->data<<endl;
    setGrandChild(child);
}

node* add(int data,node*one_node){
    cout<<"hi"<<endl;
    if(!one_node){
        one_node=new node(data);
        cout<<one_node->data<<" is added"<<endl;
        return one_node;
    }
    if(data<=one_node->data){
        one_node->left=add(data,one_node->left);
    }

    if(data>one_node->data){
        one_node->right=add(data,one_node->right);
    }
    
    if(!isBalancedNode(one_node)){
        if(!not_balanced_point){
            not_balanced_point=one_node;
            parent=one_node;
            cout<<"Parent is set to : "<<parent->data<<endl;
            setChild(parent);
        }
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

void tellDetails(){
    // cout<<"Tree is not balanced"<<endl;
    balanced=true;
    // cout<<"because of node at "<<not_balanced_point->data<<endl;
    cout<<"Parent pointing at : "<<parent->data<<endl;
    cout<<"Child pointing at : "<<child->data<<endl;
    cout<<"GrandChild pointing at : "<<grandchild->data<<endl;
    cout<<"this is a ";
    if(child_left)cout<<"left-";
    else cout<<"right-";
    if(grandchild_left)cout<<"left";
    else cout<<"right";
    cout<<" type of tree"<<endl;
    not_balanced_point=nullptr;
}

void tellChilds(node*&one_node){
    if(!one_node){
        return;    
    }
    cout<<"Node : "<<one_node->data;
    cout<<"Left child : ";
    if(one_node->left)cout<<one_node->left->data;
    else cout<<"NULL";
    cout<<" & Right child : ";
    if(one_node->right)cout<<one_node->right->data;
    else cout<<"NULl"<<endl;
    tellChilds(one_node->left);
    tellChilds(one_node->right);
}

// void findParent(node*p,node*pprev){
//     if(!p)return;
//     if(p->left==child){
//         parent=p;
//         parentPrev=pprev;
//         cout<<"Parent poninting at : "<<parent->data<<endl;
//         cout<<"parentPrev pointing at : "<<parentPrev->data<<endl;
//         t3=p->right;
//         return;
//     } else if(p->right==child){
//         parent=p;
//         parentPrev=pprev;
//         cout<<"Parent poninting at : "<<parent->data<<endl;
//         cout<<"parentPrev pointing at : "<<parentPrev->data<<endl;
//         t3=p->left;
//         return;
//     }
//     // parentPrev=parent;
//     findParent(p->left,p);
//     findParent(p->right,p);
// }

// void getBalancedAVL(node*& root){
//     t1=not_balanced_point->left;
//     t2=not_balanced_point->right;
//     child=not_balanced_point;
//     parentPrev=root;
//     parent=root;
//     try{
//         findParent(root,root);
//     } catch(...){
//         cout<<"Error occured from findParent fucntion"<<endl;
//     }
//     cout<<"Came out of findParent funciton"<<endl;
//     cout<<"Parent poninting at : "<<parent->data<<endl;
//     cout<<"parentPrev pointing at : "<<parentPrev->data<<endl;
// }

void getBalancedAVL(node*&root){
    if(child_left){
        if(grandchild_left){
            rightShiftToP(root,parent,child);
            cout<<"Shifting only once to right"<<endl;
        }else {
            leftShiftToC();
            rightShiftToP(root,parent,grandchild);
            cout<<"SHifted left then right"<<endl;
        }
    } else {
        if(grandchild_left){
            rightShiftToC();
            leftShiftToP(root,parent,grandchild);
            cout<<"Shifted right then left"<<endl;
        } else {
            leftShiftToP(root,parent,child);
            cout<<"SHifted only to left"<<endl;
        }
    }
    resertHeights();
    cout<<"AFter shiftign everything as needed the tree becomes :"<<endl;
}

int main(){
    int choice=1,data;
    node*root=nullptr;
    try{
        while(choice!=0){
            cout<<"1 : Add data\n2 : Get min max heights\n3 : Display\nYour choice : ";
            cin>>choice;
            if(choice==1){
                cout<<"ENter data : ";
                cin>>data;

                if(!root){
                    root=new node(data);
                    cout<<"First node created of BST"<<endl;
                }
                else {
                    root=add(data,root);cout<<"added"<<endl;
                }

                if(balanced){
                    cout<<"Tree is balanced"<<endl;
                }
                else {
                    tellDetails();
                    getBalancedAVL(root);
                    preetyDisplayRight(root);
                }
                cout<<"isBalancedTree(root) = "<<isBalancedTree(root)<<endl;
            }else if(choice==2){
                        
            }
            else if(choice==3){
                preetyDisplayRight(root);
            }
        }
    } catch(...) {
        cout<<"Error occured"<<endl;
    }
    delete_nodes(root);
} 