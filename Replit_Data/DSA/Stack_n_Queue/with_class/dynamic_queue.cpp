// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// class node{
//   public:

//     int start=-1,end=0,size;
//     vector<int>queue;

//     node(int size){
//       this->size=size;
//       queue.resize(size,0);
//       cout<<"Queue created suceessfully with size : "<<queue.size()<<endl;
//     }
//     void display(){
//       if(empty()){
//         cout<<"QUeue is empty"<<endl;
//         return;
//       }
//       int i=start;
//       do{
//         cout<<queue[i]<<" ";
//         i=(i+1)%queue.size();
//       }while(i!=end);
//       cout<<endl;
//       // if(empty()){
//       //   cout<<"Queue is empty"<<endl;
//       //   return;
//       // }
//       // for(int i=start;i!=end;i=(i+1)&queue.size()){
//       //   cout<<queue[i]<<" ";
//       // }
//     }
//     void pop(){
//       if(empty()){
//         cout<<"Queue is empty"<<endl;
//         start=-1;
//         end=0;
//         cout<<"Start and end are made to -1 & 0"<<endl;
//         return;
//       }
//       cout<<queue[start]<<" is popped"<<endl;
//       start++;
//       if(start==queue.size())start=0;
//       cout<<"Now strart = "<<start<<" & end = "<<end<<endl;
//     }
//     void push(int data){
//       if(start==-1){
//         cout<<"Starting queue"<<endl;
//         start=0;
//       } else if(full()){
//         cout<<"Queue full"<<endl;
//         if(start==0){
//           cout<<"Pushed back because stack is full and start=0"<<endl;
//           queue.push_back(data);
//           end=0;
//           return;
//         } else {
//           cout<<"Queue is full but start = "<<start<<" so not increasing queue length"<<endl;
//           queue.insert(queue.begin()+end,data);
//           end++;
//           start++;
//           cout<<"start = "<<start<<" & end = "<<end<<endl;
//           return;
//         }
//         cout<<queue[end]<<" is pushed"<<endl;
//         return;
//       }
//       queue[end]=data;
//       end=(end+1)%queue.size();
//       cout<<data<<" is pusheddd start = "<<start<<" & end = "<<end<<" & queue suze = "<<queue.size()<<endl;
//     }

//     bool full(){
//       return end==start;
//     }

//     bool empty(){
//       return start==-1;
//     }

// };
// int main(){
//   int n,choice=1,data;
//   cout<<"Enter size : ";
//   cin>>n;
//   node queue(n);
//   while(choice!=0){
//     cout<<"Enter your chocie\n1 : Push\n2 : Pop\n3 : Display\n4 : Top\nYour choice : ";
//     cin>>choice;
//     if(choice==1){
//       cout<<"Enter data : ";
//       cin>>data;
//       queue.push(data);
//     } else if(choice==2){
//       queue.pop();
//     } else if(choice==3){
//       queue.display();
//     }
//   }
// }