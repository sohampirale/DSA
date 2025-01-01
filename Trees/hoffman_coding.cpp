#include<iostream>
#include<set>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
class node{
    public:
        char data;
        int cnt;
        string mark;
        node* left,*right;
        node(char data,int cnt){
            cout<<data<<" created"<<endl;
            this->cnt=cnt;
            this->data=data;
            this->left=nullptr;
            this->right=nullptr;
        }
};

class NodeComp{
    public:
        bool operator()(node*t1,node*t2){
            return t1->cnt>t2->cnt;
        }
};

unordered_map<char,string>encodingMap;
unordered_map<string,char>decodingMap;
unordered_map<char,int>frequenceCounts;
priority_queue<node*,vector<node*>,NodeComp>pq;

void displayPQ(){
    queue<node*>temp;
    while(!pq.empty()){
        node* curr=pq.top();
        temp.push(curr);
        pq.pop();
        cout<<curr->data<<"  & "<<curr->cnt<<" & mark = "<<curr->mark<<endl;
        delete curr;
    }
    // while(!temp.empty()){
    //     pq.push(temp.front());
    //     temp.pop();
    // }
}

void createInititalNodes(string msg){
    for(char ch:msg){
        frequenceCounts[ch]++;
    }
    for(auto it:frequenceCounts){
        // allNodes.insert(new node(it.first,it.second));
        pq.push(new node(it.first,it.second));
    }
    cout<<"Size of priority queue now is : "<<pq.size()<<endl;
    // displayPQ();
}
 
void preOrder(node*&one_node){
    if(!one_node){
        cout<<"null"<<endl;
        return;
    }
    cout<<one_node->data<<"  & "<<one_node->cnt<<" & mark = "<<one_node->mark<<endl;
    preOrder(one_node->left);
    preOrder(one_node->right);
}

void createDecodingMap(){
    decodingMap.clear();
    for(auto it:encodingMap){
        decodingMap[it.second]=it.first;
    }
    cout<<"Decoding map created"<<endl;
}

void createEncodingMap(node*&one_node,string path=""){
    if(!one_node)return;
    string currPath=path+one_node->mark;
    encodingMap[one_node->data]=currPath;
    createEncodingMap(one_node->left,currPath);
    createEncodingMap(one_node->right,currPath);
}

void work(node*&root){
    while(pq.size()!=1){
        node*first=pq.top();
        pq.pop();
        node*second=pq.top();
        pq.pop();
        node* one_node=new node('#',first->cnt+second->cnt);
        one_node->left=first;
        one_node->right=second;
        first->mark="0";
        second->mark="1";
        pq.push(one_node);
    }
    root=pq.top();
    pq.pop();
    cout<<"Tree created "<<endl;
    preOrder(root);
    cout<<"preorder complete"<<endl;
}

void deleteAllNodes(node*&one_node){
    if(!one_node)return;
    deleteAllNodes(one_node->left);
    deleteAllNodes(one_node->right);
    delete one_node;
}

void displayDecodingMap(){
    cout<<"Decoding Map"<<endl;
    for(auto it:decodingMap){
        cout<<it.first<<" : "<<it.second<<endl;
    }
}

void displayEncodingMap(){
    cout<<"Encoding map"<<endl;
    for(auto it:encodingMap){
        cout<<it.first<<" : "<<it.second<<endl;
    }
}

string convertEncodedMsgToMsg(string encodedMsg){
    string comp="",decodedMsg="";
    int i=0;
    while(i<encodedMsg.size()){
        // i=0;
        while(decodingMap.find(comp)==decodingMap.end()&&i<encodedMsg.size()){
            cout<<"comparing "<<comp<<endl;
            comp+=encodedMsg[i];
            i++;
        }
        cout<<"Found at : "<<comp<<endl;
        decodedMsg+=decodingMap[comp];
        comp="";
    }
    return decodedMsg;
}

string convertMsgToEncodedMsg(string msg){
    string encodedMsg="";
    for(char ch : msg){
        encodedMsg+=encodingMap[ch];
    }
    return encodedMsg;
}

void clearEverything(node*&root){
    encodingMap.clear();
    decodingMap.clear();
    frequenceCounts.clear();
    while(!pq.empty())pq.pop();
    deleteAllNodes(root);
    root=nullptr;
}

void encodeIt(string msg){

}

int main(){
    int choice=1;
    string msg,encodedMsg,decodedMsg;
    node*root=nullptr;
    while(choice){
        cout<<"1 : Encode a string"<<endl;
        cout<<"2 : Decode a string"<<endl;
        cout<<"3 : Clear everything"<<endl;
        cout<<"4 : Display encoding & decoding map"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        cin.ignore();
        if(choice==1){
            cout<<"Enter your message : ";
            getline(cin,msg);
            createInititalNodes(msg);
            work(root);
            createEncodingMap(root);
            encodingMap.erase('#');
            createDecodingMap();
            displayEncodingMap();
            encodedMsg=convertMsgToEncodedMsg(msg);
            cout<<"Original msg : "<<msg<<endl;
            cout<<"Encoded msg : "<<encodedMsg<<endl;
        } else if(choice==2){
            createDecodingMap();
            displayDecodingMap();
            decodedMsg=convertEncodedMsgToMsg(encodedMsg);
            cout<<"decoded msg is : "<<decodedMsg<<endl;
        } else if(choice==3){
            clearEverything(root);
        } else if(choice==4){
            displayEncodingMap();
            displayDecodingMap();
        }
    }
    deleteAllNodes(root);
}