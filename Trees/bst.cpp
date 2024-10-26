#include<iostream>
#include<vector>
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

node* search(int data,node*t){
    if(t==nullptr){
        cout<<"Returning nullptr"<<endl;
        return nullptr;
    }
    if(t->data==data)return t;
    if(t->data<data)return search(data,t->right);
    else return search(data,t->left);

}

string search(int data,node*t,string path){
    if(t==nullptr){
        path.clear();
        return path;
    }
    if(t->data==data)return path ;
    if(t->data<data) return search(data,t->right,path+"->"+to_string(t->data));
    else return search(data,t->left,path+"->"+to_string(t->data));
}


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


void free_nodes(node*t){
    if(t==nullptr)return;
    free_nodes(t->left);
    free_nodes(t->right);
    cout<<"Deleting "<<t->data<<endl;
    delete t;
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


void add2(int data,node*&t){
    if(t==nullptr){
        cout<<"Added "<<data<<endl;
        t=new node(data);
        return;
    }

    if(data<t->data){
        add2(data,t->left);
        return;
    } else { 
        add2(data,t->right);
        return;
    }
}

void preorder(node*t){
    // if(!t)return;
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

int main(){
    int choice=1,data;
    node*root=nullptr;
    while(choice!=0){
        cout<<"1 : Add data\n2 : Serach a node\n3 : Display\nYour choice : ";
        cin>>choice;
        if(choice==1){
            cout<<"Enter data : ";
            cin>>data;
            add2(data,root);
        } else if(choice==2){

        } else if(choice==3){
            preorder(root);
            cout<<endl;
        }
    }
    delete_nodes(root);
} 


// int choice=1,data;
//     node*root=nullptr;
//     while(choice!=0){
//         cout<<"Enter your choice\n1 : Add \n2 : search\nYour choice : ";
//         cin>>choice;
//         if(choice==1){
//             cout<<"Enter the data : ";
//             cin>>data;
//             add2(data,root);
//         } else if(choice==2){
//             cout<<"Enter the data to search : ";
//             cin>>data;

//             cout<<"1 : Get ptr\n2 : Get string\nYour chocie : ";
//             cin>>choice;
//             if(choice==1){
//                 node*temp=search(data,root);
//                 cout<<"Came out"<<endl;
//                 if(temp)cout<<"Node found with data : "<<temp->data<<endl;
//                 else cout<<"Node with data : "<<data<<" not found"<<endl;
//             } else if(choice==2){
//                 string path=search(data,root,"root");
//                 if(!path.empty()){
//                     cout<<"Node found wiht that data : ";
//                     cout<<"Path : "<<path<<endl;
//                 } else cout<<"NOde with data : "<<data<<" not found"<<endl;
//             }            
//         }
//     }
//     delete_nodes(root);