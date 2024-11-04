#include<iostream>
#include<vector>
using namespace std;
class folder{
    public:
        string folder_name;
        vector<folder*>sub;
};
class file:public folder{
    public:
        string filedata;
};

void addfile(folder*&root,string filename){
    if(root==nullptr){
        cout<<"CUrrently the directory is empty so first we need to create the folder"<<endl;
        return;
    }
    cout<<"Folder present in this directory are :\n";
    for(int i=0;i<root->sub.size();i++){
        
    }

}
int main(){
    int choice=1;
    folder* root=nullptr; 
    while(choice!=0){
        cout<<"Enter your chocie\n1 : Create a folder \n2 : CReate a file\nYour choice : ";
        if(choice==1){
            string foldername;
            cout<<"Enter name of the folder : ";
            cin>>foldername;
        } else if(choice==2){
            string filename;
            cout<<"ENter name of the file : ";
            cin>>filename;
        }
    }
}