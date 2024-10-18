#include<iostream>
#include<vector>
using namespace std;
class resource;
class process_using_resource;
class resource{
    public:
        string resource_name;
        int free_r;
        resource(string resource_name,int number){
            this->resource_name=resource_name;
            free_r=number;
            cout<<"There are "<<free_r<<" "<<resource_name<<"'s availaible in total"<<endl;
        }
};
class process_using_resource{
    public:
        string pid;
        int bt,memory;
        vector<int>need;
        vector<int>allocated;
        // vector<vector<process_using_resource>>requests;
        process_using_resource(string pid,int bt,int memory,vector<int>&need,vector<int>&allocated,vector<resource>&resources){
            this->pid=pid;
            this->bt=bt;
            this->memory=memory;
            this->need=need;
            this->allocated=allocated;
            cout<<"After assingning resources to "<<pid<<" free resources are : "<<endl;
            for(int i=0;i<resources.size();i++){
                // cout<<"allocated[] = "<<allocated[i]<<endl;
                // cout<<resources[i].resource_name<<endl;
                resources[i].free_r-=allocated[i];
                cout<<"Resource no - "<<i+1<<" : "<<resources[i].free_r<<endl;
            }
        }
};

int main(){
    int n,number,bt,memory;
    string resource_name,pid;
    cout<<"Enter number of resources there are : ";
    cin>>n;
    vector<resource>resources;
    vector<process_using_resource>processes;
    for(int i=0;i<n;i++){
        cout<<"Enter the resource name of resource no - "<<i+1<<" : ";
        cin>>resource_name;
        cout<<"Enter how many "<<resource_name<<"'s are present in total : ";
        cin>>number;
        resource one_resource(resource_name,number);
        resources.push_back(one_resource);
    }
    cout<<"Resources and theri toal coutn : "<<endl;
    for(int i=0;i<resources.size();i++){
        cout<<i+1<<" "<<resources[i].resource_name<<" : "<<resources[i].free_r<<endl;
    }
    int p,types_of_resources_required;
    cout<<"Enter how many processes are there which need resources : ";
    cin>>p;
    for(int i=0;i<p;i++){
        vector<int>need(n),allocated(n);
        cout<<"Enter processId of the process : ";
        cin>>pid;
        cout<<"ENter burst time of "<<pid<<" : ";
        cin>>bt;
        cout<<"Enter memory of "<<pid<<" : ";
        cin>>memory;
        for(int j=0;j<n;j++){
            cout<<"How many "<<resources[j].resource_name<<"'s are needed by "<<pid<<" :  ";
            cin>>need[j];
        }
        for(int j=0;j<n;j++){
            cout<<"How many "<<resources[j].resource_name<<"'s are allocated initially to "<<pid<<" : ";
            cin>>allocated[j];
        }
        process_using_resource one_process(pid,bt,memory,need,allocated,resources);
        processes.push_back(one_process);
    }
    cout<<"Came out"<<endl;

}