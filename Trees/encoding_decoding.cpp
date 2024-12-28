
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class node{
    public:
        char data;
        node*left,*right;
        node(char data){
            this->data=data;
            this->left=nullptr;
            this->right=nullptr;
        }

        // ~node(){
        //     cout<<"Deleting "<<data<<endl;
        // }
};
void addAddrInQueue(node*one_node,queue<node*>&loc){
    if(!one_node->left){
        loc.push(one_node->left);
    }
    if(one_node->right){
        loc.push(one_node->right);
    }
}
void preorder(node*&one_node,string &msg){
    if(!one_node)return;
    msg+=one_node->data;
    preorder(one_node->left,msg);
    preorder(one_node->right,msg);
}

void createTreeEncoding(string msg,node*&root){
    queue<node*>loc;
    root=new node(msg[0]);
    msg.erase(msg.begin());
    loc.push(root);
    while(!msg.empty()){
        node*one_node=loc.front();
        loc.pop();
        one_node->left=new node(msg[0]);
        msg.erase(msg.begin());
        if(msg.empty())break;
        one_node->right=new node(msg[0]);
        msg.erase(msg.begin());
        loc.push(one_node->left);
        loc.push(one_node->right);
    }
    cout<<"tree created from givem string"<<endl;
}


node* createTreeDecoding(string& encodedMsg,node*&one_node){
    // if(!one_node)return;
    one_node=new node(encodedMsg[0]);
    encodedMsg.erase(encodedMsg.begin());
    one_node->left=createTreeDecoding(encodedMsg,one_node->left);
    one_node->right=createTreeDecoding(encodedMsg,one_node->right);
    return one_node;
}

string Encoding(node*&root){
    if(!root){
        cout<<"Tree is empty so cannot convert into string"<<endl;
        return "";
    }
    cout<<"Lets convert the tree into string "<<endl;
    string msg="";
    preorder(root,msg);
    return msg;
}

void BFS(queue<node*>&loc,string& decodedMsg){
    while(!loc.empty()){
        node* curr_node=loc.front();
        decodedMsg+=(curr_node->data);
        addAddrInQueue(curr_node,loc);
        loc.pop();
    }
}
string Decoding(node*&root){
    if(!root){
        cout<<"Tree is empty so cannot convert into string"<<endl;
        return "";
    }
    string decodedMsg="";
    queue<node*>loc;
    loc.push(root);
    BFS(loc,decodedMsg);
    return decodedMsg;
}

void deleteAllNodes(node*&one_node){
    deleteAllNodes(one_node->left);
    deleteAllNodes(one_node->right);
    delete one_node;
}

int main(){
    string encodedMsg="",msg="",decodedMsg="";
    node* root=nullptr;
    int choice=1;
    while(choice){
        cout<<"1 : CReate tree of a string "<<endl;
        cout<<"2 : Decode a msg to original msg"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        cin.ignore();
        if(choice==1){
            string msg;
            cout<<"Enter the message : ";
            getline(cin,msg);
            cout<<"Original msg is : "<<msg<<endl;
            createTreeEncoding(msg,root);
            encodedMsg=Encoding(root);
            deleteAllNodes(root);
            root=nullptr;
            cout<<"Encoded msg is now : "<<encodedMsg<<endl;
        } else if(choice==2){
            bool decode;
            cout<<"Do you want to decode the msg : '"<<encodedMsg<<"' ? : ";
            cin>>decode;
            if(decode){
                if(root){
                    deleteAllNodes(root);
                    cout<<"Deleting existing tree before creating another"<<endl;
                    root=nullptr;
                }
                root=createTreeDecoding(encodedMsg,root);
                decodedMsg=Decoding(root);
                cout<<"Decoded msg is : "<<decodedMsg<<endl;
                deleteAllNodes(root);
                root=nullptr;
            }
        }
        cout<<"Back in main function"<<endl;
    }

    deleteAllNodes(root);
}