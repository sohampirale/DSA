#include<iostream>
#include<queue>
using namespace std;
class process{
    public:
        int bt;
        string pid;
        process(string pid,int bt){
            this->pid=pid;
            this->bt=bt;
        }
};
int main(){
    int choice=1,bt;
    string pid;
    queue<process>FCFS;
    while(choice!=0){
        cout<<"Enter your choice :\n1 : Add a process\n2 : Execute a process\n 0 : Exit\nYour choice : ";
        cin>>choice;
        if(choice==1){
            cout<<"Enter PId of the process : ";
            cin>>pid;
            cout<<"Enter burst time of "<<pid<<" : ";
            cin>>bt;
            process one_process(pid,bt); 
            FCFS.push(one_process);
        } else if(choice==2){
            cout<<FCFS.front().pid<<" is executed"<<endl;
            FCFS.pop();
        } 
    }
}