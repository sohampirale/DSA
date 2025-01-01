#include<iostream>
#include<vector>
#include<filesystem>
#include<fstream>
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

int main(){
    int choice=1;
    string userName,passWord;
    while(choice){
        cout<<"1 : Sign up"<<endl;
        cout<<"2 : Log In"<<endl;
        cout<<"ENter your choice : ";
        cin>>choice;
        cin.ignore();
        if(choice==1){
            cout<<"Enter username : ";
            getline(cin,userName);
            if(filesystem::exists(userName) && filesystem::is_directory(userName)){
               cout<<"User with username : "<<userName<<" already exists"<<endl;
               continue;
            } 
            cout<<"Enter password : ";
            getline(cin,passWord);
            filesystem::create_directory(userName);
            string path = userName + "/";
            ofstream userFile(path + "passWord");
            if(!userFile.is_open()){
                cout << "Failed to create user file." << endl;
            } 
        }
    }
}