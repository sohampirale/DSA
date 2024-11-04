// #include<iostream>
// using namespace std;

// int steps,ini;
// void display(int&start,int&end,int*stack,int&size);

// void push(int&start,int&end,int*stack,int data,int&size){

//   end=(end+1)%size;
//   cout<<"end is changed to : "<<end<<endl;
  
//   if(start==-1){
//     start=0;
//   } else if(end==start){
//     cout<<"Stack is full"<<endl;
//     end--;
//     if(end==-1)end=size-1;
//     return;
//   }

//   stack[end]=data;
//   cout<<stack[end]<<" is pushed onto the stack"<<endl;
// }

// void pop(int&start,int&end,int*stack,int &size,int choice){
//   if(start==-1){
//     cout<<"Stack is empty"<<endl;
//     return;
//   }
//   if(start==end){
//     cout<<"All the elements are deleted now"<<endl;
//     start=-1;
//     end=-1;
//     return;
//   }
  
//   ini=start;
//   steps=end;
//   start=end;

//   for(int i=ini;i!=steps;i=(i+1)%size){
//     stack[(end+1)%size]=stack[i];
//     end=(end+1)%size;
//   }

//   if(choice==2)start=(start+1)%size;
//   else if(choice==3){
//     cout<<"Now the top is : "<<stack[start]<<endl;
//   }
  
// }
// void top(int&start,int&end,int*stack){
//   if(end==-1){
//     cout<<"Stack is empty"<<endl;
//     return;
//   }
//   cout<<stack[end];
// }
// void display(int&start,int&end,int*stack,int&size){
//   if(start==-1){
//     cout<<"Stack is empty"<<endl;
//     return ;
//   } else if(start==end){
//     cout<<"Stack has only one element : ";
//     cout<<stack[start]<<endl;
//     return ;
//   }
  
//   for(int i=start;i!=end;i=(i+1)%(size)){
//     cout<<stack[i]<<" ";
//   }
//   cout<<stack[end]<<endl;
  
// }
// int main(){
//   int n,choice=1,data;
//   cout<<"Enter size of the stack : ";
//   cin>>n;
//   int stack[n];
//   int start=-1,end=-1;
//   while(choice!=0){
//     cout<<"Enter your choice :\n1 : Push\n2 : Pop\n3 : TOP\n4 : Display\nYour choice : ";
//     cin>>choice;
//     if(choice==1){
//       cout<<"Enter data : ";
//       cin>>data;
//       push(start, end,stack,data, n);
//     } else if(choice==2){
//       pop(start, end, stack, n,choice);
//     } else if(choice==3){
//       pop(start, end, stack, n,choice);
//     }
//     display(start,end,stack,n);
//   }
// }


// #include<iostream>
// using namespace std;
// class node{
// public:
//   int data;
//   node(){
//     cout<<"Creating node with default value 10"<<endl;
//     node(10);
//   }
//   node(int data){
//     this->data=data;
//     cout<<"job done"<<endl;
//   }
// };
// int main(){
//   node n;
// }