#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class node{
    public:
        int data;
        node*left,*right;
        node(int data):data(data){}
        
        node(int data,node*left,node*right){
            this->data=data;
            this->left=left;
            this->right=right;
        }
};

void preetyDisplay(node*&one_node,int level=0){
    if(!one_node)return;
    preetyDisplay(one_node->right,level+1);
    for(int i=0;i<level-1;i++)cout<<"|\t";
    if(level!=0)cout<<"|----->";
    cout<<one_node->data<<endl;
    preetyDisplay(one_node->left,level+1);
}

node* treeFromPreAndIn(vector<int>&preorder,vector<int>inorder){
    if(inorder.empty())return nullptr;
    int curr=preorder.front();
    node* one_node=new node(curr);
    preorder.erase(preorder.begin());
    vector<int>left,right;
    int i=0;
    while(inorder[i]!=curr){
        left.push_back(inorder[i]);
        i++;
    }
    i++;
    while(i<inorder.size()){
        right.push_back(inorder[i]);
        i++;
    }
    one_node->left=treeFromPreAndIn(preorder,left);
    one_node->right=treeFromPreAndIn(preorder,right);
    return one_node;
}

node* treeFromPostAndIn(vector<int>&postorder,vector<int>inorder){
    if(inorder.empty())return nullptr;
    int curr=postorder.back();
    node* one_node=new node(curr);
    postorder.pop_back();
    vector<int>left,right;
    int i=0;
    while(inorder[i]!=curr){
        left.push_back(inorder[i]);
        i++;
    }
    i++;
    while(i<inorder.size()){
        right.push_back(inorder[i]);
        i++;
    }
    one_node->right=treeFromPostAndIn(postorder,right);
    one_node->left=treeFromPostAndIn(postorder,left);
    return one_node;
}

node*treeFromPreAndInUMap(vector<int>&preorder,unordered_map<int,int>&inorder,int st,int end,int &index){
    if(st>end)return nullptr;
    int curr=preorder[index];
    node* one_node=new node(curr);
    int currPos=inorder[curr];
    index++;
    one_node->left=treeFromPreAndInUMap(preorder,inorder,st,currPos-1,index);
    if(!one_node->left)index--;
    index++;
    one_node->right=treeFromPreAndInUMap(preorder,inorder,currPos+1,end,index);
    if(!one_node->right)index--;
    return one_node;
}

node* treeFromPostAndInUMap(vector<int>&postorder,unordered_map<int,int>&inorder,int st,int end,int &index){
    if(st>end)return nullptr;
    int curr=postorder[index];
    node*one_node=new node(curr);
    int currPos=inorder[curr];
    index--;
    one_node->right=treeFromPostAndInUMap(postorder,inorder,currPos+1,end,index);
    if(one_node->right)index--;
    // index++;
    one_node->left=treeFromPostAndInUMap(postorder,inorder,st,currPos-1,index);
    if(!one_node->left)index++;
    return one_node;
}

void preorder(node*&one_node){
    if(!one_node)return;
    cout<<one_node->data<<" ";
    preorder(one_node->left);
    preorder(one_node->right);
}

void postorder(node*one_node){
    if(!one_node)return;
    postorder(one_node->left);
    postorder(one_node->right);
    cout<<one_node->data<<" ";
}

void delteAllNodes(node*one_node){
    if(!one_node)return;
    delteAllNodes(one_node->left);
    delteAllNodes(one_node->right);
    delete one_node;
}

// node* createTree(vector<int>)

void dotreeFromPreAndIn(){
    int n;
    cout<<"How many nodes you have : ";
    cin>>n;
    vector<int>preorder(n),inorder(n);
    cout<<"Enter "<<n<<" numbers for preorder : ";
    for(int i=0;i<n;i++)cin>>preorder[i];
    cout<<"Enter "<<n<<" numbers for inorder : ";
    for(int i=0;i<n;i++)cin>>inorder[i];
    node* root=treeFromPreAndIn(preorder,inorder);
    cout<<"Tree created"<<endl;
    postorder(root);
    cout<<endl;
    preetyDisplay(root);
    cout<<"Deleting all nodes"<<endl;
    delteAllNodes(root);
}

void dotreeFromPostAndIn(){
    int n;
    cout<<"HOw many nodes ar ein the tree : ";
    cin>>n;
    vector<int>inorder(n),postorder(n);
    cout<<"Enter "<<n<<" numbers  for inorder : ";
    for(int i=0;i<n;i++)cin>>inorder[i];
    cout<<"Enter "<<n<<" numbers of postorder : ";
    for(int i=0;i<n;i++)cin>>postorder[i];
    node* root=treeFromPostAndIn(postorder,inorder);
    cout<<"tree created"<<endl;
    preorder(root);
    cout<<endl;
    preetyDisplay(root);
    delteAllNodes(root);
}

void dotreeFromPreAndInUMap(){
    int n;
    cout<<"Enter hoe many numbers you have : ";
    cin>>n;
    vector<int>preorder(n);
    unordered_map<int,int>inorder;
    cout<<"Enter "<<n<<" numbers of preorder : ";
    for(int i=0;i<n;i++)cin>>preorder[i];
    cout<<"Enter "<<n<<" numbers of inorder : ";
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        inorder[temp]=i;
    }
    int index=0;
    node*root=treeFromPreAndInUMap(preorder,inorder,0,n-1,index);
    cout<<"Tree built"<<endl;
    ::preorder(root);
    cout<<endl;
    preetyDisplay(root);
    delteAllNodes(root);
}

void dotreeFromPostAndInUMap(){
    int n,temp;
    cout<<"How many numbers you have : ";
    cin>>n;
    vector<int>postorder(n);
    unordered_map<int,int>inorder;
    cout<<"Enter "<<n<<" numbers for postorder : ";
    for(int i=0;i<n;i++)cin>>postorder[i];
    cout<<"ENter "<<n<<" numbers for inorder : ";
    for(int i=0;i<n;i++){
        cin>>temp;
        inorder[temp]=i;
    }
    int index=n-1;
    node*root=treeFromPostAndInUMap(postorder,inorder,0,n-1,index);
    cout<<"Tree created"<<endl;
    preetyDisplay(root);
    delteAllNodes(root);
}
int getChoice(){
    int choice;
    cout<<"1 : From Inorder & Preorder to tree building"<<endl;
    cout<<"2 : CReate Tree From Postorder and Inorder"<<endl;
    cout<<"3 : Create Tree from Preorder and Inorder Using UNordered Maps"<<endl;
    cout<<"4 : Create Tree From Postorder and Inorder"<<endl;
    cout<<"Your choice : ";
    cin>>choice;
    return choice;
}

int main(){
  int choice=1;
  while(choice){
    choice=getChoice();
    if(choice==1){
        dotreeFromPreAndIn();
    } else if(choice==2){
        dotreeFromPostAndIn();
    } else if(choice==3){
        dotreeFromPreAndInUMap();
    } else if(choice==4){
        dotreeFromPostAndInUMap();
    }
  }
}