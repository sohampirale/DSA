#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
#include<algorithm>

using namespace std;
// #include "process.h"
// #include "resource.h"
// #include "batch.h"
// #include "loadFromFile.h"
// #include "processUsingResource.h"

class process;
class core;
class resource;
class process_using_resource;
class batch;

class process{
    public:
        bool isImp;
        string pid;
        int bt,memory,priority=-1;
        process(string pid,int bt,int memory,bool isImp,int priority=-1){
            this->pid=pid;
            this->bt=bt;
            this->memory=memory;
            this->isImp=isImp;
            if(isImp)this->priority=priority;
        }      
};

struct compMinBT{
    bool operator()(const process& a, const process& b){
        return a.bt > b.bt;
    }
};

class core{
    public:
        int number;
        core(int number){
            this->number=number;
        }
        void execute(vector<vector<process>>&heap){

        }
};

class resource{
    public:
        string resource_name;
        int free_resources;
        resource(string resource_name,int free_resources){

            this->resource_name=resource_name;
            this->free_resources=free_resources;
            cout<<free_resources<<" : "<<resource_name<<"'s created" <<endl;

        }
};  

class process_using_resource{
    public:
        string PId;
        int bt,memory;
        vector<int>need;
        vector<int>allocated;
        vector<vector<process_using_resource>>requests;
        process_using_resource(string PId,int bt,int memory,vector<int>&need,vector<int>&allocated){

            this->PId=PId;
            this->bt=bt;
            this->memory=memory;
            this->need=need;
            this->allocated=allocated;
            cout<<endl;
        }
};

class batch{
    public:
        string batch_name;
        vector<priority_queue<process,vector<process>,compMinBT>>system;
        batch(string batch_name,int type){
            this->batch_name=batch_name;
            cout<<"Batch "<<batch_name<<" created with ";
            if(type==1||type==2){
                system.resize(6);
                cout<<6<<" heaps"<<endl;
            } else {
                system.resize(2);
                cout<<2<<" heaps"<<endl;
            }
        }
};

void load_resources_from_file(vector<resource>&all_resources){
        fstream file;
        file.open("file_data/resources.txt",ios::in);
        if(file.is_open()){
            string resource_name;
            int k_resources_int_total;
            while(file>>resource_name>>k_resources_int_total){
                resource r(resource_name,k_resources_int_total);
                all_resources.push_back(r);
            }
            file.close();
        } else {
            cout<<"Error opening the file"<<endl;
        }
}

void load_normal_processes_from_file(vector<process>&all_procesees){
    fstream file;
    file.open("file_data/processes.txt",ios::in);
    if(file.is_open()){
        string PId;
        int bt,memory,priority=-1;
        bool isImp;
        while(file>>PId>>bt>>memory>>isImp>>priority){
            process p(PId,bt,memory,isImp,priority);
            all_procesees.push_back(p);
        }
        file.close();
    } else {
        cout<<"Error opening the processes.txt file"<<endl;
    }
}

void load_processes_using_resources_from_file(vector<resource>&all_resources,vector<process>&all_procesees,vector<process_using_resource>&all_process_using_resources){

    fstream file;
    file.open("file_data/processes_using_resources_no_deadlock.txt",ios::in);
    if(file.is_open()){
        string PId;
        int bt,memory,total,allo;
        vector<int>total_need(all_resources.size()),allocated(all_resources.size());
        while(file>>PId>>bt>>memory>>total>>allo){
            // cout<<PId<<" Total : "<<total<<" & allo : "<<allo<<endl;
            int i=0;
           while(total!=0){
                total_need[i]=total%10;
                allocated[i]=allo%10;
                total/=10;
                allo/=10;
                i++;
           }
           reverse(total_need.begin(),total_need.end());
           reverse(allocated.begin(),allocated.end());


            // cout<<PId<<" : "<<endl;
            // cout<<"Total Need : ";
            // for(int i=0;i<total_need.size();i++)cout<<total_need[i]<<" ";
            // cout<<endl;

            // cout<<"Allocated : ";
            // for(int i=0;i<total_need.size();i++)cout<<total_need[i]<<" ";
            // cout<<endl;
           process_using_resource p(PId,bt,memory,total_need,allocated); 
        }
        file.close();
    } else {
        cout<<"Error opening the processes.txt file"<<endl;
    }
}

void load_processes_from_file(vector<resource>&all_resources,vector<process>&all_procesees,vector<process_using_resource>&all_process_using_resources){

    load_normal_processes_from_file(all_procesees);
    load_processes_using_resources_from_file(all_resources,all_procesees,all_process_using_resources);

}

void load_from_file(vector<resource>&all_resources,vector<process>&all_processes,vector<process_using_resource>&all_processes_using_resources){

        load_resources_from_file(all_resources);
        load_processes_from_file(all_resources,all_processes,all_processes_using_resources);

}

void load_manually(vector<int>&k_needed,vector<int>&k_allocated,vector<resource>&all_resources,vector<process>&all_processes,vector<process_using_resource>&all_processes_using_resources){
    bool reqRes,isImp;
    int n_resources, k_resources_of_each,n,bt,memory,priority;
    string resource_name,PId;
    cout<<"Enter how many resources are there : ";
    cin>>n_resources;
    for(int i=0;i<n_resources;i++){
        cout<<"Enter name of resource no:"<<i+1<<" : ";
        cin>>resource_name; 
        cout<<"How many "<<resource_name<<"'s are present in total : ";
        cin>>k_resources_of_each;
        resource temp(resource_name,k_resources_of_each);
        all_resources.push_back(temp);
    }
    cout<<"Enter number of processes : ";
    cin>>n;
    vector<int>need,allocated;
    for(int i=0;i<n;i++){
        cout<<"Enter PId of process no-"<<i+1<<" : ";
        cin>>PId;
        cout<<"Does "<<PId<<" requires Resources ? \n1 : Yes 0 : No\nYour choice : ";
        cin>>reqRes;
        cout<<"Enter burst time of "<<PId<<" : ";
        cin>>bt;
        cout<<"Enter memory size of "<<PId<<" : ";
        cin>>memory;
        if(!reqRes){
            cout<<"Is "<<PId<<" an important process?\n1 : Yes 0 : No\nYour choice : ";
            cin>>isImp;
            if(isImp){
                cout<<"Set priority for "<<PId<<"\n1 : High 2 : Mid\n3Your choice :  ";
                cin>>priority;
                // process(string pid,int bt,int memory,bool isImp,int priority=-1){
                process temp(PId,bt,memory,isImp,priority);
                all_processes.push_back(temp);
            } else {
                process temp(PId,bt,memory,isImp);
                all_processes.push_back(temp);
            }
        } else {
            int temp;
            for(int j=0;j<all_resources.size();j++){
                cout<<"How many "<<all_resources[i].resource_name<<"'s are needed for "<<PId<<" : ";
                cin>>temp;
                k_needed.push_back(temp);
            }
            for(int j=0;j<all_resources.size();j++){
                cout<<"How many "<<all_resources[i].resource_name<<"'s are allocated to "<<PId<<" : ";
                cin>>temp;
                k_allocated.push_back(temp);
            }
            process_using_resource temp_p(PId,bt,memory,k_needed,k_allocated);
            all_processes_using_resources.push_back(temp_p);
            need.clear();
            allocated.clear();
        }
    }
}

void create_batches(vector<batch>&batches){
    batch SJF("SJF",1);
    batch SRTF("SRTF",2);
    batch Priority("Priority",3);
    batch Process_Resource("Process_Resource",4);
}

int start(){
    int choice;
    cout<<"Enter your choice :\n1 : Enter data manually\n2 : Load Data\nYour choice : ";
    cin>>choice;
    return choice;
}

int main(){
    bool reqRes,isImp;
    int bt,memory,priority,n,k_resources_of_each,n_resources;
    string PId,resource_name;
    vector<int>k_needed,k_allocated;    //this vector is used to get no of each resources are needed/allocated to a process
    vector<resource>all_resources;
    vector<process>all_processes;
    vector<process_using_resource>all_processes_using_resources;
    vector<batch>batches;
    create_batches(batches);

    int choice=start();
    if(choice==1){
        load_manually(k_needed,k_allocated,all_resources,all_processes,all_processes_using_resources);
    } else if(choice==2){
        load_from_file(all_resources,all_processes,all_processes_using_resources);
    }
}
