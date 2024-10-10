#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class process{
    public:
        int at,priority,bt;
        string name;
        process* next;
        process(string name,int bt,int priority):bt(bt),name(name),next(nullptr),priority(priority){}
};
void free(process*& head){
    process* temp1=head,*temp2;
    while(temp1!=nullptr){
        temp2=temp1;
        temp1=temp1->next;
        cout<<"Deleted process : "<<temp2->name<<endl;
        delete(temp2);
    }
}
void add_lp(process* one_process,process** lp){
    if(lp[0]==nullptr){
        lp[0]=one_process;
        lp[1]=one_process;
        cout<<"Added first process to the low pirority tasks list"<<endl;
    } else {
        lp[1]->next=one_process;
        cout<<"Process added at the end in the low priiority list"<<endl;
    }
    one_process->next=nullptr;
}
void add_mp(process* one_process,process** mp){
    if(mp[0]==nullptr){
        mp[0]=one_process;
        mp[1]=one_process;
        cout<<"Added first process to the mid pirority tasks list"<<endl;
    } else {
        mp[1]->next=one_process;
        cout<<"Process added at the end in the mid priiority list"<<endl;
    }
    one_process->next=nullptr;
}
void add_hp(process* one_process,process** hp){
    if(hp[0]==nullptr){
        hp[0]=one_process;
        hp[1]=one_process;
        cout<<"Added first process to the high pirority tasks list"<<endl;
    } else {
        hp[1]->next=one_process;
        cout<<"Process added at the end in the high priiority list"<<endl;
    }
    one_process->next=nullptr;
}
void add_process(process* one_process,process**hp,process**mp,process**lp){
    int priority=one_process->priority;
    if(priority==1){
        add_hp(one_process,hp);
    }
    if(priority !=3){
        add_mp(one_process,mp);
    }
    add_lp(one_process,lp);
}

int main(){
    int p,priority,bt;
    cout<<"Enter total number of processes : ";
    cin>>p;
    process* hp[2]={nullptr,nullptr};
    process* mp[2]={nullptr,nullptr};
    process* lp[2]={nullptr,nullptr};
    for(int i=0;i<p;i++){
        cout<<"Enter burst time of process no - "<<i+1<<" : ";
        cin>>bt;
        cout<<"Enter priority of this process :\n1 : High 2 : Medium 3 : Low\nYour choice : ";
        cin>>priority;
        process* one_process=new process("P"+to_string(i+1),bt,priority);
        add_process(one_process,hp,mp,lp);
    }
    free(lp[0]);
}