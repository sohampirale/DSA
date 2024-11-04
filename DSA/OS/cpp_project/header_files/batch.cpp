#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
#include "batch.h"
#include "process.h"

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
