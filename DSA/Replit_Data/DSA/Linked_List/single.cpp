// #include<iostream>
// using namespace std;
// class node{
// public :
// int data;
// node* next;
// node(int data){
//   this->data=data;
//   this->next=NULL;
// }
// };

// node* insert_rec(node*&start,node*&temp,int p,int i=1){
//   if(temp==nullptr){
//     cout<<"Invalid location"<<endl;
//     return nullptr;
//   }
//   if(p-1==i){
//     return temp;
//   }
//   i++;
//   temp=temp->next;
//   return insert_rec(start,temp,p,i);
// }
// void insert_recursion(node*&start,int p,node*&one_node,node*temp,int i=1){
//   if(p==1){
//     one_node->next=start;
//     start=one_node;
//     return;
//   }
//   // static node*temp=start;
//   if(temp==nullptr){
//     cout<<"Invalid location"<<endl;
//     delete one_node;
//     return;
//   }
//   if(p-1==i){
//     one_node->next=temp->next;
//     temp->next=one_node;
//     return;
//   }
//   i++;
//   temp=temp->next;
//   insert_recursion(start, p, one_node,temp,i);
// }
// void insert(node*&start,node*&one_node,int choice){
//   if(choice==1){
//     if(start==nullptr){
//       one_node->next=nullptr;
//       start=one_node;
//     } else{
//       one_node->next=start;
//       start=one_node;
//     }
//   } else if(choice==2){
//     if(start==nullptr){
//       // one_node->next=start;//next i salready being mae nullptr in construictor
//       start=one_node;
//     } else {
//       node*temp=start;
//       while(temp->next!=nullptr){
//         temp=temp->next;
//       }
//       temp->next=one_node;
//       if(one_node->next==nullptr)cout<<"Right"<<endl;
//     }
//   } else if(choice==3){
//     int p,i=1;
//     cout<<"Enter at position you want to insert this node : ";
//     cin>>p;
//     if(p<1){
//       cout<<"Invalid Location"<<endl;
//       return;
//     }
//     if(p==1){
//       one_node->next=start;
//       start=one_node;
//     } else{
//       node*temp=start;
//       while(temp!=nullptr){
//         if(p-1==i){
//           one_node->next=temp->next;
//           temp->next=one_node;
//           return;
//         }
//         i++;
//         temp=temp->next;
//       }
//       if(temp==nullptr){
//         cout<<"Invalid Location"<<endl;
//         delete temp;
//         return;
//       }
//     }
//   }
// }
// void insert(int data,int choice,node*&start,node*&end){
//   if(choice==0)return;
//   if(choice==1||start==NULL){
//     node *one_node=new node(data);
//     if(start==NULL){
//       start=one_node;
//       end=one_node;
//       cout<<"Linked list was empty "<<one_node->data<<" is added at the start"<<endl;
//     } else {
//       cout<<"Linked list is not empty"<<endl;
//       one_node->next=start;
//       start=one_node;
//       cout<<"Data : "<<data<<" added at the start"<<endl;
//     }
//   } else if(choice ==2){
//     node *one_node=new node(data);
//     end->next=one_node;
//     end=end->next;
//     cout<<"Data "<<data<<" stored at the end"<<endl;
//   } else if(choice ==3){
//     int p,i=0;
//     node*temp=start;
//     node *one_node=new node(data);
//     cout<<"Enter at which location you want to insert '"<<data<<"'"<<endl;
//     cin>>p;
//     if(p==1){
//       one_node->next=temp;
//       start=one_node;
//       cout<<"Number inserted at first position successfully"<<endl;
//     } else if(p<1){
//       cout<<"Invalid input"<<endl;
//     }
//     else while(1){
//       if(i+2>=p){
//         one_node->next=temp->next;
//         if(temp->next==NULL){
//           cout<<"Number inserted at the end of the linked list so updating the end pointer"<<endl;
//           end=one_node;
//         }
//         temp->next=one_node;
//         cout<<"Data inserted successfully"<<endl;
//         break;
//       } else if(temp->next==NULL){
//         cout<<"Invalid input"<<endl;
//         break;
//       }
//       i++;
//       temp=temp->next;
//     }
//   } else if(choice==4){
//     node*temp=start;
//     int i=1;
//     cout<<"Linked list : ";
//     while(temp!=NULL){
//       cout<<temp->data<<" ";
//       temp=temp->next;
//       i++;
//     }
//     cout<<endl;
//   } else if(choice==5){
//     int p,ask;
//     cout<<"Enter node number which you want to delete : ";
//     cin>>p;
//     node* temp=start;
//     int i=0;
//     while(1){
//       if(i+2>=p){
//         if(p==1){
//           cout<<"Do you want to delete node no-"<<p<<" which has data = "<<temp->data<<"\n1 :Yes\n2 : No\nYour choice : "<<endl;
//           cin>>ask;
//           if(ask==0){cout<<"Deletion process cancelled"<<endl;break;}
//           start=temp->next;
//           free(temp);
//           cout<<"Node deleted successfully"<<endl;
//           break;
//         }else {
//         cout<<"Do you want to delete node no-"<<p<<" which has data = "<<temp->next->data<<"\n1 :Yes\n2 : No\nYour choice : "<<endl;
//         cin>>ask;
//         if(ask==0){cout<<"Deletion process cancelled"<<endl;break;}
//         node*temp2=temp->next;
//         temp->next=temp2->next;
//         free(temp2);
//         cout<<"Data deleted successfully"<<endl;
//         break;
//       }
//       } else if(temp->next==NULL){
//         cout<<"Invalid input"<<endl;
//         break;
//       }
//       i++;
//       temp=temp->next;
//     }
//   }
// }
// void display(node*&start){
//   node*temp=start;
//   cout<<"Linked List is : ";
//   while(temp!=nullptr){
//     cout<<temp->data<<" ";
//     temp=temp->next;
//   }
//   cout<<endl;
// }
// int main(){
//   node*start=NULL;
//   int choice=1,data=0,p;
//   while(choice!=0){
//     cout<<"Choose operation :\n1 : Add at the start\n2 : Add at the end\n3 : Add at a given location\n4 : Display linked list\n5 : Delete a node\n6 : Insert a node via recursion\n7 : Insert via recursion node* return type \n0 : Exit\nYour choice : ";
//     cin>>choice;
//     if(choice>=1&&choice<=3){
//       cout<<"Enter the data you want to insert : ";
//       cin>>data;
//       node*one_node=new node(data);
//       insert(start, one_node, choice);
//     } else if(choice==6){
//       cout<<"Enter the data you want create node with : ";
//       cin>>data;
//       node*one_node=new node(data);
//       cout<<"At what position you want to insert : ";
//       cin>>p;
//       insert_recursion(start,p,one_node,start);
//     } else if(choice==4){
//       display(start);
//     } else if(choice==7){
//       cout<<"Enter the data with which you want to create node with : ";
//       cin>>data;
//       node*one_node=new node(data);
//       cout<<"Enter at what position you want to insert the node : ";
//       cin>>p;
      
//       if(p==1){
//         if(start==nullptr){
//           start=one_node;
//         } else{
//           one_node->next=start;
//           start=one_node;
//         }
//       } else{
//       node*ptr=start;
//       node*temp=insert_rec(start,ptr,p);
//         if(temp!=nullptr){
//           one_node->next=temp->next;
//           temp->next=one_node;
//         } else{
//           cout<<"Nullptr pointer received i.e. invalid location"<<endl;
//           delete one_node;
//         }
//     }
//     }
//   }
// }
