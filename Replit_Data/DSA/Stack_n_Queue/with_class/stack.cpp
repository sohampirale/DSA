// //can also be done using top=0 and saving and then incrementing or decrementing it

// #include<iostream>

// using namespace std;

// class stack {

//   public:
//     float testing;
//     int top=-1;
//     int size;
//     int*array;
//     int curr=0;
//     stack(){ 
//     }

//     stack(int size):size(size) ,array(new int[size]){
//       cout<<"Stack created with size : "<<this->size<<endl;
//     }
//     stack(float test):testing(test),size(0),array(nullptr){
//       cout<<"Testing = "<<testing<<endl;
//     }
//     bool full(){
//       return top==size-1;
//     }
//     bool empty(){
//       return top==-1;
//     }
//     void push(int data){
//       if(full()){
//         cout<<"Stack is full"<<endl;
//         return;
//       }
//       if(top==-1)top=0;
//       else top=(top+1)%size;
//       array[top]=data;
//       cout<<array[top]<<" is pushed"<<endl;
//       curr++;
//     }

//     void pop(){
//       if(empty()){
//         cout<<"Stack is empty"<<endl;
//         return;
//       }  
//       cout<<array[top]<<" is popped"<<endl;
//       top--;
//       curr--;
//     }

//     void display(){
//       if(empty()){
//         cout<<"Stack is empty"<<endl;
//         return ;
//       }
//       for(int i=0;i<curr;i++){
//         cout<<array[i]<<" ";
//       }
//       cout<<endl;
//       cout<<"Current size of the stack is : "<<curr<<endl;
//     }
// };
// int main(){
//   stack ex;
//   int choice,n,data;
//   cout<<"1 : Give size of stack\n2 : By default(5)\nYour choice : ";
//   cin>>choice;
//   if(choice==1){
//     cout<<"Enter size : ";
//     cin>>n;
//     ex=n;
//   } else ex=5;
//   while(choice!=0){
//     cout<<"Enter your chocie\n1 : Push\n2 : Pop\n3 : Top\n4 : Display\n0 : Exit\nYour choice : ";
//     cin>>choice;
//     if(choice==1){
//       cout<<"Enetr data : ";
//       cin>>data;
//       ex.push(data);
//     } else if(choice==2){
//       ex.pop();
//     } else if(choice==3){
//       if(!ex.empty())cout<<"Top : "<<ex.array[ex.top]<<endl;
//       else cout<<"Stack is empty"<<endl;
//     } else if(choice==4){
//       ex.display();
//     }
//   }
// }



// //top=0 inilially

// #include<iostream>

// using namespace std;

// class stack {

//   public:
//     float testing;
//     int top=0;
//     int size;
//     int*array;
//     int curr=0;
//     stack(){ 
//     }

//     stack(int size):size(size) ,array(new int[size]){
//       cout<<"Stack created with size : "<<this->size<<endl;
//     }
//     stack(float test):testing(test),size(0),array(nullptr){
//       cout<<"Testing = "<<testing<<endl;
//     }
//     bool full(){
//       return top==size;
//     }
//     bool empty(){
//       return top==0;
//     }
//     void push(int data){
//       if(full()){
//         cout<<"Stack is full"<<endl;
//         return;
//       }

//       array[top++]=data;
//       cout<<array[top-1]<<" is pushed"<<endl;
//       curr++;
//     }

//     void pop(){
//       if(empty()){
//         cout<<"Stack is empty"<<endl;
//         return;
//       }  
//       cout<<array[--top]<<" is popped"<<endl;
//       // top--;
//       curr--;
//     }

//     void display(){
//       if(empty()){
//         cout<<"Stack is empty"<<endl;
//         return ;
//       }
//       for(int i=0;i<curr;i++){
//         cout<<array[i]<<" ";
//       }
//       cout<<endl;
//       cout<<"Current size of the stack is : "<<curr<<endl;
//     }
// };
// int main(){
//   stack ex;
//   int choice,n,data;
//   cout<<"1 : Give size of stack\n2 : By default(5)\nYour choice : ";
//   cin>>choice;
//   if(choice==1){
//     cout<<"Enter size : ";
//     cin>>n;
//     ex=n;
//   } else ex=5;
//   while(choice!=0){
//     cout<<"Enter your chocie\n1 : Push\n2 : Pop\n3 : Top\n4 : Display\n0 : Exit\nYour choice : ";
//     cin>>choice;
//     if(choice==1){
//       cout<<"Enetr data : ";
//       cin>>data;
//       ex.push(data);
//     } else if(choice==2){
//       ex.pop();
//     } else if(choice==3){
//       if(!ex.empty())cout<<"Top : "<<ex.array[ex.top-1]<<endl;
//       else cout<<"Stack is empty"<<endl;
//     } else if(choice==4){
//       ex.display();
//     }
//   }
// }