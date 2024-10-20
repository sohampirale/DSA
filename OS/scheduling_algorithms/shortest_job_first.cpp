#include<iostream>
#include<vector>
using namespace std;
class process;
class base_process;
void saveProcess(vector<base_process>&SJF_v,process& one_process);
void manage(vector<vector<base_process>>&system,process& one_process,bool reqRes=false);
class core{
    public:
        int number;
        core(int number){
            this->number=number;
        }
        void execute(vector<vector<process>>&heap){

        }
};


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
        //temp
        process(int bt){
            this->bt=bt;
        }
        process(){
            this->pid="demo";
            this->bt=-1;
            this->priority=false;
        }
        process(const process& one_process){
            this->pid=one_process.pid;
            this->bt=one_process.bt;
            this->memory=one_process.memory;
            this->priority=one_process.priority;
        }
};
class process_using_resource{
    public:
        string pid;
        int bt,memory;
        vector<int>need;
        vector<vector<process_using_resource>>requests;
        process_using_resource(string pid,int bt,int memory,vector<int>&need){
            this->pid=pid;
            this->bt=bt;
            this->memory=memory;
            this->need=need;
        }
};
class base_process{
    public:
        string pid,batch;
        vector<process>heap;
        base_process(string batch){
            this->pid="demo process";
            heap.push_back(process());
            cout<<"Size of vector<process>heap = "<<heap.size()<<endl;
        }
        int parent(int pos){
            return pos/2;
        }
        void show_size(){
            cout<<"Size of vector<process>heap = "<<heap.size()<<endl;
        }
        void swap(int& parent_index,int& curr){
            process temp(heap[parent_index]);
            heap[parent_index]=heap[curr];
            heap[curr]=temp;
            cout<<"In batch : "<<this->batch<<" : "<<endl;
            cout<<"Process "<<heap[parent_index].pid<<" interchanged with  "<<heap[curr].pid<<endl;
            curr=parent_index;
        }
        void add_heap(process& one_process){
            int curr=heap.size();
            heap.push_back(one_process);
            int parent_index=parent(curr);
            while(heap[parent_index].bt>heap[curr].bt){
                if(curr==1){
                    cout<<"Recently added process is at the first position waiting ..."<<endl;
                    return;
                }
                parent_index=parent(curr);
                swap(parent_index,curr);
            }
            cout<<"After swapping the heap becomes : ";
            for(int i=1;i<heap.size();i++){
                cout<<heap[i].pid<<":"<<heap[i].bt<< " ";
            }
            cout<<endl;
        }

};
class batch{
    public:
        string batch_name;
        vector<vector<process>>system;
        vector<vector<process_using_resource>>processes_using_resoources;
        batch(){
            this->batch_name="demo node";
            cout<<"Demo node created"<<endl;
        }
        batch(string batch_name,vector<process> base_process,int type=1){
            this->batch_name=batch_name;
            if(type==1){
                //for creating 2d system
                for(int i=0;i<6;i++){
                    system.push_back(base_process);
                }
                for(int i=0;i<6;i++){
                    process temp(10+i);
                    system[i].push_back(temp);
                }
            } else if(type==2){
                    for(int i=0;i<2;i++){
                        system.push_back(base_process);
                    }
            }
        }
        void display_system(){
            for(int i=0;i<system.size();i++){
                cout<<"Processes in row - "<<i+1<<" : ";
                for(int j=0;j<system[i].size();j++){
                    cout<<system[i][j].bt<<" ";
                }
                cout<<endl;
            }
        }
        //for creating a batch of priority algorithm
        batch(string batch_name,vector<process> base_process){
            this->batch_name=batch_name;
            for(int i=0;i<6;i++){
                system.push_back(base_process);
            }
            // system.resize(6,vector<process>(6));
            cout<<"Batch - "<<batch_name<<" is created"<<endl;
            cout<<"no of rows : "<<system.size()<<endl;
            cout<<"Number of colommns in each row : "<<system[0].size()<<endl;
        }
};
void manage(vector<vector<base_process>>&system,process& one_process,bool reqRes){
    if(!reqRes){
        if(one_process.isImp){
            int priority=one_process.priority;
            if(priority==1){
                saveProcess(system[3],one_process);
            }
            if(priority==1||priority==2){
                saveProcess(system[4],one_process);
            }

            // save_SJF_Process(system[5],one_process);
        }
        for(int i=0;i<3;i++){
            saveProcess(system[i],one_process);
        }
        cout<<"Process : "<<one_process.pid<<" is arranged in appropriate batches"<<endl;
    }
}
void saveProcess(vector<base_process>&SJF_v,process& one_process){
    int memory=one_process.memory;
    if(memory<0||memory>256){
        cout<<"Invalid memory entered"<<endl;
        if(memory>256){
            cout<<"A process can have maximum memory  : 256 kB"<<endl;
        }
        return;
    }
    if(memory<=8){
        cout<<"Adding process into space of 8 kB"<<endl;
        SJF_v[0].add_heap(one_process);
    } else if(memory <=16){
        cout<<"Adding process into space of 16 kB"<<endl;
        SJF_v[1].add_heap(one_process);
    }else if(memory<=32){
        cout<<"Adding process into space of 32 kB"<<endl;
        SJF_v[2].add_heap(one_process);
    }else if(memory<=64){
        cout<<"Adding process into space of 64 kB"<<endl;
        SJF_v[3].add_heap(one_process);
    }else if(memory<=128){
        cout<<"Adding process into space of 128 kB"<<endl;
        SJF_v[4].add_heap(one_process);
    }else if(memory<=256){
        cout<<"Adding process into space of 256 kB"<<endl;
        SJF_v[5].add_heap(one_process);
    } 
}
void set_batch_name(vector<vector<base_process>>&system,vector<string>batches){
    for(int i=0;i<6;i++){
        for(int j=0;j,6;j++){
            system[i][j].batch=batches[i];
        }
    }
}
int main(){
    vector<batch>batches;
    vector<string>batches_name={"SJF","SRTF"};
    process base;
    vector<process>base_process={base};
    batch temp("SJF",base_process,1);
    temp.display_system();
    cout<<"Came out"<<endl;
    batch temp2("SRTF",base_process,2);
    temp2.display_system();
    cout<<"Came out"<<endl;
    // for(int i=0;i<batches.size();i++){
    //     batch temp(batches_name[i],base_process);
    //     batches.push_back(temp);
    // }
    
    // int n;
    // cout<<"Enter number of processes : ";
    // cin>>n;
    // bool reqRes;
    // int bt,memory;
    // string PId;
    // vector<int>need,allocated;
    // for(int i=0;i<n;i++){
    //     cout<<"Enter PId of process no-"<<i+1<<" : ";
    //     cin>>PId;
    //     cout<<"Does "<<PId<<" requires Resources ? \n1 : Yes 0 : No\nYour choice : ";
    //     cin>>reqRes;
    //     cout<<"Enter burst time of "<<PId<<" : ";
    //     cin>>bt;
    //     cout<<"Enter memory size of "<<PId<<" : ";
    //     cin>>memory;

    //     if(!reqRes){
    //         // cout<<""        
    //     }
    // }
//     int n;
//     string pid;
//     vector<core>cores={core(1),core(2),core(3),core(4),core(5),core(6)};
//     vector<string>batches={"SJF","SRTF","Round Robbin","Highest Priority","Medium Priority","Lowest Priority"};
//     bool isImp;
//     int bt,memory,priority=-1;
//     cout<<"How many processes you have : ";
//     cin>>n;
//     vector<vector<base_process>>system(6,vector<base_process>(6));
//     set_batch_name(system,batches);
//     for(int i=0;i<n;i++){
//         cout<<"Enter name of process no : "<<i+1<<" : ";
//         cin>>pid;
//         cout<<"Enter burst time of "<<pid<<" : ";
//         cin>>bt;
//         cout<<"Enter memory of "<<pid<<" : ";
//         cin>>memory;
//         cout<<"Does "<<pid<<" has priority ?\n1 : Yes 0 : NO\nYour choice : ";
//         cin>>isImp;
//         if(isImp){
//             cout<<"Enter priority of the process\n1 : High\n2 : Mid\n3 : Low\nYour choice : ";
//             cin>>priority;
//         } else priority=-1;
//         process one_process(pid,bt,memory,isImp,priority);
//         priority=-1;
//         manage(system,one_process);
//         // save_SJF_Process(system[0],one_process);
//     }
// //     cout<<"SJF batch is :"<<endl;
// //     for(int i=0;i<system[0].size();i++){
// //         cout<<"Section : "<<i+1<<" : ";
// //         for(int j=1;j<system[0][i].batch.size();j++){
// //             cout<<system[0][i].heap[j].pid<<" ";
// //         }
// //         cout<<endl;
// //     }

}