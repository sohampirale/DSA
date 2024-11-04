// #include<iostream>
// using namespace std;
// class node;
// node*top=nullptr;
// class node{
// public:
//   int data;
//   node*next;
//   node(int data){
//     cout<<"hi"<<endl;
//     this->data=data;
//     next=top;
//     top=this;
//   }
//   ~node(){
//       top=this->next;
//       if(top!=nullptr)cout<<"Node popped and top is pointing at : "<<top->data<<endl;
//   }
// };

// void display(node*&top){
//   node*temp=top;
//   cout<<"Elements in stack are : ";
//   while(temp!=nullptr){
//     cout<<temp->data<<" ";
//     temp=temp->next;
//   }
//   cout<<endl;
// }

// int main(){
//   int choice=1,data;
//   node*recent_node;
//   while(choice!=0){
//     cout<<"Enter your chocie\n1 : Push\n2 : Pop\n3 : Top\n4 : Display\nYour choice  : ";
//     cin>>choice;
//     if(choice==1){
//       cout<<"Enetr data : ";
//       cin>>data;
//       recent_node=new node(data);
//     } else if(choice==2){
//       if(top!=nullptr){
//         delete recent_node;
//         recent_node=top;
//       }
//       else cout<<"Stack is empty"<<endl;
//     } else if(choice==3){
//       if(top!=nullptr)cout<<"Topmost element in the stack is : "<<top->data<<endl;
//       else cout<<"Stack is empty"<<endl;
//     }
//     else if(choice==4)display(top);
//   }
// }
// // #include<iostream>
// // using namespace std;
// // class node{
// // public:
// //   int data;
// //   node*right,*left;
// // node(int data){
// //   this->data=data;
// //   this->right=nullptr;
// //   this->left=nullptr;
// // }
// // };
// // void pop(node*&start,node*&end){
// //   if(start==nullptr){
// //     cout<<"Stack is empty"<<endl;
// //     return;
// //   }
// //   if(start==end){
// //     cout<<"Node deleted with data : "<<end->data<<endl;
// //     delete start;
// //     start=nullptr;
// //     end=nullptr;
// //   } else{
// //     cout<<"Node deleted with data : "<<end->data<<endl;
// //     end=end->left;
// //     delete end->right;
// //     end->right=nullptr;
// //   }
// // }
// // void push(node*&start,node*&end){
// //   int data;
// //   cout<<"Enter data : ";
// //   cin>>data;
// //   node*new_node=new node(data);
// //   if(start==nullptr){
// //     start=new_node;
// //     end=new_node;
// //   } else{
// //     new_node->right=start;
// //     start->left=new_node;
// //     start=new_node;
// //   }
// //   cout<<"Node added with data : "<<start->data<<endl;
// // }
// // void display(node*&start,node*temp){
// //   if(temp==nullptr)return;
// //   display(start,temp->right);
// //   cout<<temp->data<<" ";
// // }
// // int main(){
// //   int choice=1;
// //   node*start=nullptr,*end=nullptr;
// //   while(choice!=0){
// //     cout<<"Enter your chocie :\n1 : Push\n2 : Pop\n3 : Top\nYour choice : ";
// //     cin>>choice;
// //     if(choice==1){
// //       push(start,end);
// //     } else if(choice==2){
// //       pop(start,end);
// //     } else if(choice==3){
// //       if(end!=nullptr)cout<<"The first element to get out of Queue is : "<<end->data<<endl;
// //       else cout<<"Stack is empty"<<endl;
// //     }
// //     cout<<"Stack until now is : ";
// //     display(start,start);
// //   }
// // }