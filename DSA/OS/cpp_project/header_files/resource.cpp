#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
#include "resource.h"
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
