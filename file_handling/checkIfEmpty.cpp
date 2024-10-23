#include<iostream>
#include<fstream>
#include <unistd.h>
#include <filesystem>
using namespace std;
bool isEmpty(string filename){
    ifstream file(filename,ios::binary|ios::ate);
    bool ans=file.tellg()==0;
    file.close();
    return ans;
}

bool checkEmptyFile(const std::string& filename) {
    return std::filesystem::file_size(filename) == 0;
}
int main(){
    string filename;
    cout<<"Enter the filename : ";
    cin>>filename;
    for(int i=0;i<10;i++){
        if(isEmpty(filename))cout<<filename<<" is empty"<<endl;
        else cout<<filename<<" is not empty"<<endl;
        cout<<"i = "<<i<<endl;
        sleep(2);
    }
}