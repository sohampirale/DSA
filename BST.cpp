#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data,height,cnt=0;
        node*left,*right,*next;
        node(int data){
            this->data=data;
            this->left=nullptr;
            this->right=nullptr;
            this->next=nullptr;
            this->height=0;
        }
        ~node(){
            cout<<"Deleting "<<this->data<<endl;
        }
};

class node{
    public:
        int data,height,cnt=0;
        node*left,*right,*next;
        node(int data){
            this->data=data;
            this->left=nullptr;
            this->right=nullptr;
            this->next=nullptr;
            this->height=0;
        }
        ~node(){
            cout<<"Deleting "<<this->data<<endl;
        }
};

void preorder(node*&one_node){
    if(!one_node)return;
    cout<<one_node->data<<" ";
    preorder(one_node->left);
    preorder(one_node->right);
}

void inorder(node*&one_node){
    if(!one_node)return;
    cout<<one_node->data<<" ";
    inorder(one_node->left);
    inorder(one_node->right);
}

void postorder(node*&one_node){
    if(!one_node)return;
    cout<<one_node->data<<" ";
    postorder(one_node->left);
    postorder(one_node->right);
}

node* add(node*one_node,node*&root,int data){
    if(!one_node){
        cout<<"Node "<<data<<" added"<<endl;
        return new node(data);
    }

    if(data<=one_node->data){
        one_node->left=add(one_node->left,root,data);
        // cout<<one_node->data<<" received left as : "<<one_node->left->data<<endl;
    }

    if(data>one_node->data){
        one_node->right=add(one_node->right,root,data);
        // cout<<one_node->data<<" received right as : "<<one_node->right->data<<endl;

    }
    // node*temp=one_node;
    // one_node=rotate(one_node,root);
    // cout<<"Rotate funciton gave one_node = "<<one_node->data<<" but original call was made from"<<temp->data<<endl;
    one_node->height=max(getHeight(one_node->right),getHeight(one_node->left))+1;
    return one_node;
}

int getchoice(){
    int choice;
    cout<<"1 : Add node\n";
    cout<<"2 : preorder"<<endl;
    cout<<"3 : Postorder"<<endl;
    cout<<"4 : Inorder"<<endl;
    cout<<"Your choice : ";
    cin>>choice;
    return choice;
}

void delete_nodes(node*&one_node){
    if(!one_node)return;
    delete_nodes(one_node->left);
    delete_nodes(one_node->right);
    delete one_node;
}

int main(){
    node*root=nullptr;
    int choice=getchoice();
    int data;
    if(choice==1){
        cout<<"Enter data : ";
        cin>>data;
         try{
            if(!root)root=new node(data);
            else root=add(root,root,data);
            cout<<"Root pointing at : "<<root->data<<endl;
        } catch(...){
            cout<<"Error occured"<<endl;
        }
    } else if(choice==2){
        preorder(root);
    } else if(choice==3){
        postorder(root);
    } else if(choice==4){
        inorder(root);
    }
    delete_nodes(root);
}