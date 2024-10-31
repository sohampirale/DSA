// #include<iostream>
// using namespace std;

// void push(int*stack,int &top,int data,int n){
//   if(top==n-1){
//     cout<<"Stack is full"<<endl;
//     return;
//   }
//   top++;
//   stack[top]=data;
//   cout<<"Data stored in stack as : "<<stack[top];
// }

// void pop(int*stack,int&top){
//   if(top==-1){
//     cout<<"Stack is empty"<<endl;
//     return;
//   }
//   cout<<"Data : "<<stack[top]<<" is popped"<<endl;
//   top--;
// }
// int main(){
//   int n,choice=1,data,top=-1;
//   cout<<"Enter size of the stack : ";
//   cin>>n;
//   int stack[n];
//   while(choice!=0){
//     cout<<"Enter your choice\n1 : Push\n2 : Pop\n3 : Top\nYour choice : ";
//     cin>>choice;
//     if(choice==1){
//       cout<<"Enter the data you want to store : ";
//       cin>>data;
//       push(stack,top,data,n);
//     } else if(choice==2){
//       pop(stack,top);
//     } else if(choice==3){
//       if(top==-1){
//         cout<<"Stack is empty"<<endl;
//         continue;
//       }
//       cout<<"Topmost element is : "<<stack[top]<<endl;
//     }
//   }
// }