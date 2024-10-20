#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream file;
    file.open("write.txt",ios::out);
    if(file.is_open()){
        string data;
        cout<<"Enter the data you want to write : ";
        getline(cin,data);
        file<<data<<"\n";
        cout<<"Data written intot he file"<<endl;
        file.close();
    } else {
        cout<<"Error opening the file"<<endl;
    }
}