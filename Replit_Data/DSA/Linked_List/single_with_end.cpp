// #include<iostream>
// using namespace std;
// int l=0;
// class node{
// public :
// int data;
// node* right,*left;
// node(int data){
//   this->data=data;
//   this->right=NULL;
//   this->left=nullptr;
// }
// };
// node* insert_rec(node*&temp,int p,int i=1){
//   if(temp==nullptr){
//     cout<<"Invalid location"<<endl;
//     return nullptr;
//   }
//   if(p-1==i){
//     return temp;
//   }
//   i++;
//   temp=temp->right;
//   return insert_rec(temp,p,i);
// }
// // void insert_recursion(node*&start,int p,node*&one_node,node*temp,int i=1){
// //   if(p==1){
// //     one_node->next=start;
// //     start=one_node;
// //     return;
// //   }
// //   // static node*temp=start;
// //   if(temp==nullptr){
// //     cout<<"Invalid location"<<endl;
// //     delete one_node;
// //     return;
// //   }
// //   if(p-1==i){
// //     one_node->next=temp->next;
// //     temp->next=one_node;
// //     return;
// //   }
// //   i++;
// //   temp=temp->next;
// //   insert_recursion(start, p, one_node,temp,i);
// // }

// void display(node*&start){
//   node*temp=start;
//   cout<<"Linked List is : ";
//   while(temp!=nullptr){
//     cout<<temp->data<<" ";
//     temp=temp->right;
//   }
//   cout<<endl;
// }
// int main(){
//   node*start=NULL;
//   int choice=1,data=0,p;
//   while(choice!=0){
//     cout<<"1 : Insert using recursion\n2 : Insert using recursion void type\n3 : Display\n0 : Exit\nYour choice : ";
//     cin>>choice;
//     if(choice==3){
//       display(start);
//       continue;
//     }
//     if(choice==0){
//       break;
//     } 
//     if(choice>=1&&choice<=2){
//       cout<<"Enter the data with which you want to create node : ";
//       cin>>data;
//       cout<<"Enter position at which you want to insert node : ";
//       cin>>p;
//       if(p<1){
//         cout<<"Invalid Location\nLocation cnanot be less than 1"<<endl;
//         continue;
//       }
//       node*one_node=new node(data);
//       if(p==1){
//         if(start==nullptr){
//           start=one_node;
//           continue;
//         } else{
//           one_node->right=start;
//           start->left=one_node;
//           start=one_node;
//           continue;
//         }
//       } else if(choice==1){
//         node*ptr=start;
//         node*temp=insert_rec(ptr,p);
//         if(temp!=nullptr){
//           one_node->right=temp->right;
//           one_node->left=temp;
//           temp->right=one_node;
//           if(one_node->right!=nullptr)one_node->right->left=one_node;
//           continue;
//         } else{
//           cout<<"nullptr received"<<endl;
//           delete one_node;
//           continue;
//         }
//       } else if(choice==2){
//         cout<<"Coming soon"<<endl;
//         continue;
//       }
//     }  
//   }
// }
