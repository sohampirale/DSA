#include<iostream>
#include<vector>
using namespace std;
class process;
class base_process;

void saveProcess(vector<base_process>&SJF_v,process& one_process);
void manage(vector<vector<base_process>>&system,process& one_process);
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
void manage(vector<vector<base_process>>&system,process& one_process,bool reqRes){
    if(reqRes){
        if(one_process.isImp){
            int priority=one_process.priority;
            if(priority==1){
                save_SJF_Process(system[3],one_process);
            }
            if(priority==1||priority==2){
                save_SJF_Process(system[4],one_process);
            }

            // save_SJF_Process(system[5],one_process);
        }
        for(int i=0;i<3;i++){
            save_SJF_Process(system[i],one_process);
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
    int n;
    string pid;
    vector<core>cores={core(1),core(2),core(3),core(4),core(5),core(6)};
    vector<string>batches={"SJF","SRTF","Round Robbin","Highest Priority","Medium Priority","Lowest Priority"};
    bool isImp;
    int bt,memory,priority=-1;
    cout<<"How many processes you have : ";
    cin>>n;
    vector<vector<base_process>>system(6,vector<base_process>(6));
    set_batch_name(system,batches);
    for(int i=0;i<n;i++){
        cout<<"Enter name of process no : "<<i+1<<" : ";
        cin>>pid;
        cout<<"Enter burst time of "<<pid<<" : ";
        cin>>bt;
        cout<<"Enter memory of "<<pid<<" : ";
        cin>>memory;
        cout<<"Does "<<pid<<" has priority ?\n1 : Yes 0 : NO\nYour choice : ";
        cin>>isImp;
        if(isImp){
            cout<<"Enter priority of the process\n1 : High\n2 : Mid\n3 : Low\nYour choice : ";
            cin>>priority;
        } else priority=-1;
        process one_process(pid,bt,memory,isImp,priority);
        priority=-1;
        manage(system,one_process);
        // save_SJF_Process(system[0],one_process);
    }
}