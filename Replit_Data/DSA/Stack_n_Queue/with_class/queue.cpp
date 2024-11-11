// #include<iostream>
// using namespace std;
// class node{
// public:
//     int*array;
//     int end=0,curr=0,size;
//     node(){}
//     node (int size):array(new int[size]),size(size){
//       cout<<"Queue created with size of array : "<<this->size<<endl;
//     }
//     bool full(){
//       return end==size;
//     }
//     bool empty(){
//       return end==0;  
//     }
//     void push(int data){
//       if(full()){
//         cout<<"Queue is full"<<endl;
//         return;
//       }
//       array[end++]=data;
//       curr++;
//       cout<<"Size of queue is : "<<curr<<endl;
//     }
//     void pop(){
//       if(empty()){
//         cout<<"Queue is empty"<<endl;
//         return ;
//       }
//       cout<<array[0]<<" is popped"<<endl;
//       for(int i=1;i<end;i++){
//         array[i-1]=array[i];
//       }
//       end--;
//       curr--;
//     }
//     void display(){
//       if(empty()){
//         cout<<"Queue is empty"<<endl;
//         return;
//       }
//       cout<<"Start <- ";
//       for(int i=0;i<end;i++){
//         cout<<array[i]<<" <- ";
//       }
//       cout<<"End"<<endl;
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
//       cout<<"Top : "<<ex.array[0]<<endl;
//     } else if(choice==4){
//       ex.display();
//     }
//   }
// }

