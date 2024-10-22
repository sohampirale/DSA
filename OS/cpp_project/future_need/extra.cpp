// cout<<PId<<"'s need of resources is updated to : "<<endl;
// for(int i=0;i<need.size();i++){
//     need[i]-=allocated[i];
//     cout<<need[i]<<" ";
// }
// void saveProcess(vector<base_process>&SJF_v,process& one_process){
//     int memory=one_process.memory;
//     if(memory<0||memory>256){
//         cout<<"Invalid memory entered"<<endl;
//         if(memory>256){
//             cout<<"A process can have maximum memory  : 256 kB"<<endl;
//         }
//         return;
//     }
//     if(memory<=8){
//         cout<<"Adding process into space of 8 kB"<<endl;
//         SJF_v[0].add_heap(one_process);
//     } else if(memory <=16){
//         cout<<"Adding process into space of 16 kB"<<endl;
//         SJF_v[1].add_heap(one_process);
//     }else if(memory<=32){
//         cout<<"Adding process into space of 32 kB"<<endl;
//         SJF_v[2].add_heap(one_process);
//     }else if(memory<=64){
//         cout<<"Adding process into space of 64 kB"<<endl;
//         SJF_v[3].add_heap(one_process);
//     }else if(memory<=128){
//         cout<<"Adding process into space of 128 kB"<<endl;
//         SJF_v[4].add_heap(one_process);
//     }else if(memory<=256){
//         cout<<"Adding process into space of 256 kB"<<endl;
//         SJF_v[5].add_heap(one_process);
//     } 
// }


// void manage(vector<vector<base_process>>&system,process& one_process,bool reqRes){
//     if(!reqRes){
//         if(one_process.isImp){
//             int priority=one_process.priority;
//             if(priority==1){
//                 saveProcess(system[3],one_process);
//             }
//             if(priority==1||priority==2){
//                 saveProcess(system[4],one_process);
//             }

//             // save_SJF_Process(system[5],one_process);
//         }
//         for(int i=0;i<3;i++){
//             saveProcess(system[i],one_process);
//         }
//         cout<<"Process : "<<one_process.pid<<" is arranged in appropriate batches"<<endl;
//     }
// }



// class base_process{
//     public:
//         string pid,batch;
//         vector<process>heap;
//         base_process(string batch){
//             this->pid="demo process";
//             heap.push_back(process());
//             cout<<"Size of vector<process>heap = "<<heap.size()<<endl;
//         }
//         int parent(int pos){
//             return pos/2;
//         }
//         void show_size(){
//             cout<<"Size of vector<process>heap = "<<heap.size()<<endl;
//         }
//         void swap(int& parent_index,int& curr){
//             process temp(heap[parent_index]);
//             heap[parent_index]=heap[curr];
//             heap[curr]=temp;
//             cout<<"In batch : "<<this->batch<<" : "<<endl;
//             cout<<"Process "<<heap[parent_index].pid<<" interchanged with  "<<heap[curr].pid<<endl;
//             curr=parent_index;
//         }
//         void add_heap(process& one_process){
//             int curr=heap.size();
//             heap.push_back(one_process);
//             int parent_index=parent(curr);
//             while(heap[parent_index].bt>heap[curr].bt){
//                 if(curr==1){
//                     cout<<"Recently added process is at the first position waiting ..."<<endl;
//                     return;
//                 }
//                 parent_index=parent(curr);
//                 swap(parent_index,curr);
//             }
//             cout<<"After swapping the heap becomes : ";
//             for(int i=1;i<heap.size();i++){
//                 cout<<heap[i].pid<<":"<<heap[i].bt<< " ";
//             }
//             cout<<endl;
//         }

// };



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
// }




//g
// cout<<"Enter how many resources are there : ";
//     cin>>n_resources;
//     for(int i=0;i<n_resources;i++){
//         cout<<"Enter name of resource no:"<<i+1<<" : ";
//         cin>>resource_name; 
//         cout<<"How many "<<resource_name<<"'s are present in total : ";
//         cin>>k_resources_of_each;
//         resource temp(resource_name,k_resources_of_each);
//         all_resources.push_back(temp);
//     }
//     cout<<"Enter number of processes : ";
//     cin>>n;
//     vector<int>need,allocated;
//     for(int i=0;i<n;i++){
//         cout<<"Enter PId of process no-"<<i+1<<" : ";
//         cin>>PId;
//         cout<<"Does "<<PId<<" requires Resources ? \n1 : Yes 0 : No\nYour choice : ";
//         cin>>reqRes;
//         cout<<"Enter burst time of "<<PId<<" : ";
//         cin>>bt;
//         cout<<"Enter memory size of "<<PId<<" : ";
//         cin>>memory;
//         if(!reqRes){
//             cout<<"Is "<<PId<<" an important process?\n1 : Yes 0 : No\nYour choice : ";
//             cin>>isImp;
//             if(isImp){
//                 cout<<"Set priority for "<<PId<<"\n1 : High 2 : Mid\n3Your choice :  ";
//                 cin>>priority;
//                 // process(string pid,int bt,int memory,bool isImp,int priority=-1){
//                 process temp(PId,bt,memory,isImp,priority);
//                 all_processes.push_back(temp);
//             } else {
//                 process temp(PId,bt,memory,isImp);
//                 all_processes.push_back(temp);
//             }
//         } else {
//             int temp;
//             for(int j=0;j<all_resources.size();j++){
//                 cout<<"How many "<<all_resources[i].resource_name<<"'s are needed for "<<PId<<" : ";
//                 cin>>temp;
//                 k_needed.push_back(temp);
//             }
//             for(int j=0;j<all_resources.size();j++){
//                 cout<<"How many "<<all_resources[i].resource_name<<"'s are allocated to "<<PId<<" : ";
//                 cin>>temp;
//                 k_allocated.push_back(temp);
//             }
//             process_using_resource temp_p(PId,bt,memory,k_needed,k_allocated);
//             all_processes_using_resources.push_back(temp_p);
//             need.clear();
//             allocated.clear();
//         }