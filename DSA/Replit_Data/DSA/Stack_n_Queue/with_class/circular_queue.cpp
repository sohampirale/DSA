// #include<iostream>
// using namespace std;
// class node{
// public:
//     int*array;
//     int end=0,start=-1,curr=0,size=99;
//     node(){}
//     node (int size):array(new int[size]),size(size){
//       cout<<"Queue created with size of array : "<<this->size<<endl;
//     }
//     bool full(){
//       return end==start;
//     }
//     bool empty(){
//       return start==-1;  
//     }
//     void push(int data){
//       if(full()){
//         cout<<"Queue is full"<<endl;
//         return;
//       }
//       if(start==-1)start=0;
//       array[end]=data;
//       end=(end+1)%size;
//       curr++;
//       cout<<"Size of queue is : "<<curr<<endl;
//     }
//     void pop(){
//       if(empty()){
//         cout<<"Queue is empty"<<endl;
//         return ;
//       }
//       cout<<array[start]<<" is popped"<<endl;
//       start=(start+1)%size;
//       if(start==end){
//         cout<<"Queue is made empty now"<<endl;
//         start=-1;
//         end=0;
//       }
//       curr--;
//     }
//     void display(){
//       if(empty()){
//         cout<<"Queue is empty"<<endl;
//         return;
//       }
//       int i=start;
//       cout<<"Start <- ";
//       do{
//         cout<<array[i]<<" <- ";
//         i=(i+1)%size;
//       }while(i!=end);

//       cout<<"End"<<endl;
//     }
//     ~node(){
//       cout<<"Deleting a queue with size : "<<size<<endl;
//     }
// };

// int main(){
//   node ex;
//   int choice,size,data;
//   cout<<"1 : Set size of the queue\n2 : Set size by default i.e. (5)\nYour choice : ";
//   cin>>choice;
//   if(choice==1){
//     cout<<"Enter size you want to set : ";
//     cin>>size;
//     ex=size;
//   } else ex=5;
//   while(choice!=0){
//     cout<<"Enter your choice\n1 : Push\n2 : Pop\n3 : Top\n4 : Display\nYour choice : ";
//     cin>>choice;
//     if(choice==1){
//       cout<<"Enter data : ";
//       cin>>data;
//       ex.push(data);
//     } else if(choice==2){
//       ex.pop();
//     } else if(choice==3){
//       if(!ex.empty())cout<<"Top : "<<ex.array[ex.start]<<endl;
//       else cout<<"Queue is empty"<<endl;
//     } else if(choice==4){
//       ex.display();
//     }
//   }
// }