// #include<iostream>
// using namespace std;
// class node;
// node*first=nullptr,*last=nullptr;
// class node{
//   public:
//   int data;
//   node*right,*left;
//   node(int data){
//     this->data=data;
//     this->right=first;
//     this->left=nullptr;
//     if(first!=nullptr)first->left=this;
//     first=this;
//   }
//   ~node(){
//     cout<<"Node with data : "<<last->data<<" is popped"<<endl;
//     if(last!=first){
//       last=last->left;
//       cout<<"Now last is pointing at : "<<last->data<<endl;
//       last->right=nullptr;
//     }
//     else {
//       last=nullptr;
//       first=nullptr;
//     }
//   }
// };
// void display(node*&first){
//   cout<<"enqueue->";
//   node*temp=first;
//   while(temp!=nullptr){
//     cout<<temp->data<<"->";
//     temp=temp->right;
//   }
//   cout<<"dequeue side"<<endl;
// }
// int main(){
//   int choice=1,data;
//   node*recent_node=nullptr;
//   while(choice!=0){
//     cout<<"Enter your choice \n1 : Push\n2 : Pop\n3 : Top\n4 : Display\nYour chocie : ";
//     cin>>choice;
//     if((choice==2||choice==3||choice==4)&&last==nullptr){
//       cout<<"Queue is empty"<<endl;
//       continue;
//     }
//     if(choice==1){
//       cout<<"Enter data : ";
//       cin>>data;
//       recent_node=new node(data);
//       if(first->right==nullptr){
//         last=recent_node;
//       }
//     } else if(choice==2){
//         delete last;
//     } else if(choice==3){
//         cout<<"Element which will be dequeued first is : "<<last->data<<endl;
//     } else if(choice==4)display(first);
//   }
// }

