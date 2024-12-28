#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class node{
    public:
        string word;
        vector<pair<node*,node*>>child;
        node*smaller,*larger;
        node(string word){
            this->smaller=nullptr;
            this->larger=nullptr;
            cout<<"Word : "<<word<<" created"<<endl;
            this->word=word;
            child.resize(word.size(),{nullptr,nullptr});
        }

        ~node(){
            cout<<"Deleting "<<word<<endl;
        }
};

class msgNode{
    public:
        char data;
        msgNode*left,*right;
        msgNode(char data){
            this->data=data;
            this->left=nullptr;
            this->right=nullptr;
        }
};

void create(string word,node*one_node){
    int i=0;
    string treeWord=one_node->word;
    if(treeWord==word){
        cout<<"word : "<<word<<" already exists in the tree no need to add"<<endl;
        return;
    } else if(word.size()!=treeWord.size()){
        if(word.size()<treeWord.size()){
            cout<<"word : "<<word<<" is smaller than "<<treeWord<<endl;
            cout<<"Lets look at left side of "<<treeWord<<endl;
            if(one_node->smaller==nullptr){
                cout<<"Lets create to left side of "<<treeWord<<endl;
                one_node->smaller=new node(word);
                return;
            } else {
                create(word,one_node->smaller);
                cout<<"Returning from "<<treeWord<<endl;
                return;
            }
        } else {
            cout<<"word : "<<word<<" is larger than "<<treeWord<<endl;
            cout<<"Lets look at right side of "<<treeWord<<endl;
            if(one_node->larger==nullptr){
                cout<<"Lets create to the right side of "<<treeWord<<endl;
                one_node->larger=new node(word);
                return;
            } else {
                create(word,one_node->larger);
                cout<<"retunring from "<<treeWord<<endl;
                return;
            }
        }
    }
    while(i<=word.size()){
        if(word[i]==treeWord[i])i++;
        else break;
    }
    cout<<word<<" & "<<treeWord<<" differ at index : "<<i<<endl;

   if(word[i]<treeWord[i]){
        cout<<"Lets go to left of "<<treeWord<<endl;
        if(one_node->child[i].first==nullptr){
            cout<<"Lets create "<<word<<" to left of "<<treeWord<<endl;
            one_node->child[i].first=new node(word);
            return;
        } else {
            create(word,one_node->child[i].first);
            cout<<"Retunring from "<<treeWord<<endl;
            return;
        }
    } else {
        cout<<"Lets go to right of "<<treeWord<<endl;
        if(one_node->child[i].second==nullptr){
            cout<<"Lets create to the right of "<<treeWord<<endl;
            one_node->child[i].second=new node(word);
            return;
        } else {
            create(word,one_node->child[i].second);
            cout<<"Returning from "<<treeWord<<endl;
            return;
        }
    }

}

void search(string word,node*one_node){
    int i=0;
    string treeWord=one_node->word;
    if(word==treeWord){
        cout<<word<<" found"<<endl;
        return;
    } else if(word.size()!=treeWord.size()){
        cout<<"Size of "<<word<<" & "<<treeWord<<" is not same"<<endl;
        if(word.size()<treeWord.size()){
            cout<<"word : "<<word<<" is smaller than "<<treeWord<<endl;
            cout<<"Lets look at smaller side of "<<treeWord<<endl;
            if(one_node->smaller==nullptr){
                cout<<word<<" not found in the tree :("<<endl;
                return;
            } else {
                search(word,one_node->smaller);
                cout<<"Returning from "<<treeWord<<endl;
                return;
            }
        } else {
            cout<<"word : "<<word<<" is larger than "<<treeWord<<endl;
            cout<<"Lets look at larger side of "<<treeWord<<endl;
            if(one_node->larger==nullptr){
                cout<<word<<" not found in the tree :("<<endl;
                return;
            } else {
                search(word,one_node->larger);
                cout<<"retunring from "<<treeWord<<endl;
                return;
            }
        }
    }
    while(i<word.size()&&i<treeWord.size()){
        if(word[i]==treeWord[i])i++;
        else break;
    }

    cout<<word<<" & "<<treeWord<<" differ at index = "<<i<<endl;
    if(word[i]<treeWord[i]){
        cout<<"Lets look at left side of "<<treeWord[i]<<endl;
        if(one_node->child[i].first==nullptr){
            cout<<"Word : "<<word<<"not found"<<endl;
            return;
        } else {
            search(word,one_node->child[i].first);
            cout<<"Returing from "<<treeWord<<endl;
        }
    } else {
        cout<<"Let's look at right side of "<<treeWord[i]<<endl;
        if(one_node->child[i].second==nullptr){
            cout<<"Word : "<<word<< "not found in the tree"<<endl;
            return;
        } else {
            search(word,one_node->child[i].second);
            cout<<"Returning from "<<treeWord<<endl;
            return;
        }
    }
}

void deleteAllNodes(node*one_node){
    if(one_node->smaller)deleteAllNodes(one_node->smaller);
    if(one_node->larger)deleteAllNodes(one_node->larger);

    for(auto it:one_node->child){
        if(it.first)deleteAllNodes(it.first);
        if(it.second)deleteAllNodes(it.second);
    }
    delete one_node;
}

void addAddrInQueue(msgNode*one_node,queue<msgNode*>&loc){
    if(!one_node->left){
        loc.push(one_node->left);
    }
    if(one_node->right){
        loc.push(one_node->right);
    }
}

msgNode* createTreeFromMsg(string msg,msgNode*&root){
    queue<msgNode*>loc;
    root=new msgNode(msg[0]);
    msg.erase(msg.begin());
    loc.push(root);
    while(!msg.empty()){
        msgNode*one_node=loc.front();
        loc.pop();
        one_node->left=new msgNode(msg[0]);
        msg.erase(msg.begin());
        if(msg.empty())break;
        one_node->right=new msgNode(msg[0]);
        msg.erase(msg.begin());
        loc.push(one_node->left);
        loc.push(one_node->right);
    }
    cout<<"Tree created successfully"<<endl;
    cout<<"Lets see its preorder "<<endl;
    preorder(root);
}

void preorder(msgNode*&one_node){
    cout<<one_node->data<<" ";
    preorder(one_node->left);
    preorder(one_node->right);
}
int main(){
    string rootWord;
    msgNode* root=nullptr;
    cout<<"Enter root word : ";
    cin>>rootWord;
    cin.ignore();
    node* root=new node(rootWord);
    int choice=1;
    while(choice){
        cout<<"1 : Add a word"<<endl;
        cout<<"2 : Search a word"<<endl;
        cout<<"3 : CReate tree of a string "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        cin.ignore();
        if(choice==1){
            string word;
            cout<<"Enter word : ";
            cin>>word;
            create(word,root);
            cout<<"Came back in main fucntion"<<endl;
        } else if(choice==2){
            string word;
            cout<<"ENter the word you want to search for : ";
            cin>>word;
            search(word,root);
            cout<<"Came back in main fucntion"<<endl;
        } else if(choice==3){
            string msg;
            cout<<"Enter the message : ";
            getline(cin,msg);
            cout<<"Original msg is : "<<msg<<endl;

        }
    }
    deleteAllNodes(root);
}