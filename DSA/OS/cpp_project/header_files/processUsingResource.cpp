#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

#include "processUsingResource.h"
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
