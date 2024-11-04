#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream file;
    file.open("reading.txt",ios::in);
    if(file.is_open()){
        string data;
        string pid;
        int bt,at,priority;
        bool reqRes,isImp;
        while(file>>pid>>bt>>at>>reqRes>>isImp>>priority){
            cout << "PID: " << pid
                  << ", BT: " << bt
                  << ", AT: " << at
                  << ", Required Resource: " << (reqRes ? "Yes" : "No")
                  << ", Is Important: " << (isImp ? "Yes" : "No")
                  << ", Priority: " << priority << std::endl;
        }
        file.close();
    } else {
        cout<<"Error opening the file"<<endl;
    }
}