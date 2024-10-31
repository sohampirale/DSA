// #include<iostream>
// using namespace std;

// void push(int*queue,int data,int size,int&start,int&end){
//   if(end==size-1)end=0;
//   else end++;
//   if(start==-1)start=0;
//   else if(end==start){
//     cout<<"Queue is full"<<endl;
//     if(end==0)end=size-1;
//     else end--;
//     return;
//   }
//   queue[end]=data;
//   cout<<"Data stored in queue as : "<<queue[end]<<endl;
// }

// void pop(int*queue,int size,int&start,int&end){
//   if(start==-1){
//     cout<<"Queue is empty"<<endl;
//     return;
//   }
//  if(start==end){
//    cout<<"Data : "<<queue[start]<<" is deleted"<<endl;
//    start=-1;
//    end=-1;
//  } else{
//     cout<<"Data : "<<queue[start]<<" is deleted"<<endl;
//    if(start==size-1)start=0;
//    else start++;
//  }
// }

// int main(){
//   int size,choice=1,data,start=-1,end=-1;
//   cout<<"Enter size of the Queue : ";
//   cin>>size;
//   int queue[size];
//   while(choice!=0){
//     cout<<"Enter your choice\n1 : Push\n2 : Pop\n3 : Top\nYour choice : ";
//     cin>>choice;
//     if(choice==1){
//       cout<<"Enter the data you want to store : ";
//       cin>>data;
//       push(queue,data,size,start,end);
//     } else if(choice==2){
//       pop(queue,size,start,end);
//     } else if(choice==3){
//       if(start==-1){
//         cout<<"Queue is empty"<<endl;
//         continue;
//       }
//       cout<<"Topmost element is : "<<queue[start]<<endl;
//     }
//   }
// }