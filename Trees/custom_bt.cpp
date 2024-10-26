#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
        int data;
        node*left,*right;
        node(int data):data(data),left(nullptr),right(nullptr){}
        ~node(){
            cout<<data<<" deleted"<<endl;
        }
};

void preorder(node*t){
    cout<<t->data<<endl;
    if(t->left){
        cout<<"Left children of "<<t->data<<" : "<<endl;
        preorder(t->left);
    }
    if(t->right){
        cout<<"Right children of "<<t->data<<" : "<<endl;
        preorder(t->right);
    }
}

void display_with_indent(node*&one_node,string indent="",string side=""){
    if(!one_node)return;
    cout<<indent<<"|"<<side<<one_node->data<<endl;
    display_with_indent(one_node->left,indent+"\t","l");
    display_with_indent(one_node->right,indent+"\t","r");
}

void display_with_arrows1(node*&one_node,string indent="  ",int level=0){
    if(!one_node)return;
    display_with_arrows1(one_node->right,indent+"  ",level+1);
    if(one_node->right){
        for(int i=0;i<=level;i++)cout<<indent;
        cout<<"|"<<endl;
    }
    for(int i=0;i<level;i++)cout<<indent;
    cout<<"->"<<one_node->data<<endl;
    if(one_node->left){
        for(int i=0;i<=level;i++)cout<<indent;
        cout<<"|"<<endl;
    }
    display_with_arrows1(one_node->left,indent+"  ",level+1);
}

void display_with_arrows2(node*&one_node,string indent=" ",int level=0){
    // if(!one_node)return;

    if(one_node->right){
        // for(int i=0;i<=level;i++)cout<<indent;
        // cout<<"|"<<endl;
        display_with_arrows2(one_node->right,indent,level+1);
    }

    for(int i=0;i<level;i++)cout<<indent;
    cout<<"|"<<endl;

    for(int i=0;i<level-2;i++)cout<<indent;
    cout<<"|"<<indent;
    cout<<"->"<<one_node->data<<endl;

    for(int i=0;i<level;i++)cout<<indent;
    cout<<"|"<<endl;
    
    if(one_node->left){
        display_with_arrows2(one_node->left,indent,level+1);
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


void add(node*&one_node){
    if(!one_node){
        int data;
        cout<<"Enter data : ";
        cin>>data;
        one_node=new node(data);
        cout<<data<<" created"<<endl;
    }
    bool left,right;

    cout<<"Do you want to create to the left of "<<one_node->data<<"? : ";
    cin>>left;
    if(left){
        add(one_node->left);
    }

    cout<<"Do you wnat to create to the right of "<<one_node->data<<" ? : ";
    cin>>right;
    if(right){
        add(one_node->right);
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

int main(){
    node*root=nullptr;
    add(root);
    cout<<"Tree created is : "<<endl;
    int choice;
    cout<<"Enter by which method you want to print(1-4) : ";
    cin>>choice;
    
    if(choice==1) display_with_arrows1(root);
    else if(choice==2)display_with_arrows2(root);
    else if(choice==3)preetyDisplayRight(root);
    else if(choice==4)preetyDisplayLeft(root);
    delete_nodes(root);
}




// if(one_node->right){
//     cout<<indent<<"|"<<endl;
//     display_with_arrows(one_node->right,indent+" ",level+1);
// }
// cout<<indent;
// for(int i=0;i<level;i++)cout<<"-";
// cout<<"->"<<one_node->data<<endl;

//    if(one_node->left){
//     display_with_arrows(one_node->left,indent+" ",level+1);
//     cout<<indent<<"|"<<endl;
// }