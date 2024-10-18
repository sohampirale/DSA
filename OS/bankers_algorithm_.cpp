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
        process_using_resource(string pid,int bt,int memory,vector<int>&need,vector<int>&allocated,vector<resource>&resources){
            this->pid=pid;
            this->bt=bt;
            this->memory=memory;
            this->need=need;
            this->allocated=allocated;
            cout<<"After assingning resources to "<<pid<<" free resources are : "<<endl;
            for(int i=0;i<resources.size();i++){
                resources[i].free_r-=allocated[i];
                cout<<"Resource no - "<<i+1<<" has : "<<resources[i].free_r<<" free resources:"<<endl;
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
    while(!processes.empty()){
        for(int i=0;i<processes.size();i++){
            bool possible=true;
            for(int j=0;j<n;j++){
                if(resources[j].free_r<processes[i].need[j]){
                    possible=false;
                    break;
                }
            }
            if(possible){
                cout<<"Process "<<processes[i].pid<<" is execuetd"<<endl;
                for(int j=0;j<n;j++){
                    resources[j].free_r+=processes[i].allocated[j];
                }
                processes.erase(processes.begin()+i);
                cout<<"Reamianning processes are : ";
                for(int j=0;j<processes.size();j++){
                    cout<<processes[j].pid<<" ";
                }
                cout<<endl;
            }
        }
    }
    cout<<"Came out"<<endl;
}


// Enter number of resources there are : 3
// Enter the resource name of resource no - 1 : printer
// Enter how many printer's are present in total : 10
// There are 10 printer's availaible in total
// Enter the resource name of resource no - 2 : scanner
// Enter how many scanner's are present in total : 5
// There are 5 scanner's availaible in total
// Enter the resource name of resource no - 3 : resource3
// Enter how many resource3's are present in total : 3
// There are 3 resource3's availaible in total
// Resources and theri toal coutn : 
// 1 printer : 10
// 2 scanner : 5
// 3 resource3 : 3
// Enter how many processes are there which need resources : 2
// Enter processId of the process : p1
// ENter burst time of p1 : 1
// Enter memory of p1 : 1
// How many printer's are needed by p1 :  6
// How many scanner's are needed by p1 :  2
// How many resource3's are needed by p1 :  1
// How many printer's are allocated initially to p1 : 1
// How many scanner's are allocated initially to p1 : 2
// How many resource3's are allocated initially to p1 : 0
// After assingning resources to p1 free resources are : 
// Resource no - 1 has : 9 free resources:
// Resource no - 2 has : 3 free resources:
// Resource no - 3 has : 3 free resources:
// Enter processId of the process : p2
// ENter burst time of p2 : 2
// Enter memory of p2 : 2
// How many printer's are needed by p2 :  4
// How many scanner's are needed by p2 :  2
// How many resource3's are needed by p2 :  2
// How many printer's are allocated initially to p2 : 2
// How many scanner's are allocated initially to p2 : 1
// How many resource3's are allocated initially to p2 : 1
// After assingning resources to p2 free resources are : 
// Resource no - 1 has : 7 free resources:
// Resource no - 2 has : 2 free resources:
// Resource no - 3 has : 2 free resources:
// Process p1 is execuetd
// Reamianning processes are : p2 
// Process p2 is execuetd
// Reamianning processes are : 
// Came out