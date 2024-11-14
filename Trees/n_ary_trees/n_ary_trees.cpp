#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class node{
    public:
        string person;
        vector<node*>child;
    node(string person):person(person){}
    ~node(){
        cout<<"Deleting "<<person<<endl;
    }
};
vector<string>allPaths;
node* work(vector<string>people,string nodeString,string path=""){
    node*one_node=new node(nodeString);
    if(people.empty()){
        cout<<"All people did sit"<<endl;
        cout<<"Path = "<<path<<endl;
        allPaths.push_back(path);
        return one_node;
    }
    int size=people.size();
    for(int i=0;i<size;i++){
        // cout<<"Calling child of "<<one_node->person<<" & people.size() = "<<people.size()<<endl;

        vector<string>temp=people;
        string nextperson=people[i];
        temp.erase(temp.begin()+i);
        // cout<<"Passing : "<<nextperson<<endl;
        one_node->child.push_back(work(temp,nextperson,path+"->"+nextperson));
    }

    return one_node;
}

void inorder(node*&one_node){
    cout<<one_node->person<<" ";
    int size=one_node->child.size();
    if(size==0){
        cout<<"Nullptr"<<endl;
        return;
    }
    for(int i=0;i<size;i++){
        inorder(one_node->child[i]);
    }
}
void delete_all_node(node*&one_node){
    if(!one_node)return;
    int size=one_node->child.size();
    for(int i=0;i<size;i++){
        delete_all_node(one_node->child[i]);
    }
    delete one_node;
}
int main(){
    int n;
    cout<<"Enter n :";
    cin>>n;
    cout<<"Enter "<<n<<" people : ";
    string temp;
    vector<string>people(n);
    for(int i=0;i<n;i++){
        cin>>people[i];
    }
    node*root=work(people,"root");
    // inorder(root);
    delete_all_node(root);
}