#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
#include "all_classes.h"
#include "loadFromFile.h"
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
