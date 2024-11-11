// #include<iostream>
// #include<vector>
// using namespace std;
// class node{
// public:
//   int data;
//   node*next=nullptr;

//   node();

//   node(int data){
//     this->data=data;
//   }

// };
// void list_creator(int n,node*&start,node*&end){
//   for(int i=0;i<n;i++){
//     node*one_node=new node();
//     // cout<<"Node created with data : "<<one_node->data<<endl;
//     if(start==nullptr){
//       start=one_node;
//       end=one_node;
//     }else{
//       end->next=one_node;
//       end=one_node;
//     }
//   }
//   return;
// }
// // void pop(node*&start,node*&end){
// //   node*temp=end->next;
// //   if(temp==nullptr){
// //     cout<<"Stack is empty so cannot pop anything"<<endl;
// //     return;
// //   }
// //   temp->data=0;
// //   end=temp;
// // }
// // void push(node*&start,node*&end,int data){
// //   if(end->next==start){
// //     cout<<"Stack is full so cannot push anything"<<endl;
// //     return;
// //   }
// //   node*temp=start;
// //   if(temp==end){
// //     node*temporary_node=new node();
// //     temporary_node->next=temp;
// //     temp->data=data;
// //     end=temporary_node;
// //     cout<<"Stack is now full dont try to push now"<<endl;
// //     return;
// //   }
// //   while(temp->next!=end)temp=temp->next;
// //   end->data=data;
// //   cout<<"Data is added at end"<<endl;
// //   end=temp;
// // }
// void push(node*&start,node*&t,int data){
//   node*one_node=new node(data);
//   one_node->next=t;
//   start=one_node;
//   t=one_node;
// }
// void display(node*&start){
//   if(start==nullptr){
//     cout<<"Linked list is empty"<<endl;
//     return;
//   }
//   node*temp=start;
//   cout<<"Linked list is : ";
//   while(temp!=nullptr){
//     cout<<temp->data<<" ";
//     temp=temp->next;
//   }
// }
// int main(){
//   int n;
//   node*start=nullptr,*t=nullptr;
//   cout<<"Enter the limit of the linked list : ";
//   cin>>n;
//   // list_creator(n,0start,end);
//   int choice=1;
//   while(choice!=0){
//     cout<<"Enter your chocie \n1 : Push\n2 : Pop\n0 : Exit\nYour choice : ";
//     cin>>choice;
//     if(choice==1){
//       int data;
//       cout<<"Enter data : ";
//       cin>>data;
//       push(start,t,data);
//     } else if(choice==2){
//       pop(start,end);
//     }
//     display(start);
//   }
// }
