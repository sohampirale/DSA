// #include<iostream>
// using namespace std;
// int l1=0,l2=0;
// void clear() {
//     cout << "\033[2J\033[1;1H";
// }
// class complete{
// public:
// string task;
// complete*right,*left;
// complete(string task){
//   this->task=task;
//   this->right=nullptr;
//   this->left=nullptr;
// }
// };

// class pending{
// public:
// string task;
// pending*right,*left;
// pending(string task){
//   this->task=task;
//   this->right=nullptr;
//   this->left=nullptr;
// }
// };
// string mark(pending*&start1,pending*&end1,int p);
// void add_completed(string task,complete*&start2,complete*&end2);
// string uni_task;

// string mark(pending*&start1,pending*&end1,int p){
//   string task;
//   pending*temp,*temp2;
//   int i;
//   if(p<1||p>l1+1){
//     clear();
//     cout<<"You have entered wrong position number\nEnter between 1-"<<l1<<endl;
//   } else if(p==1){
//     temp=start1;
//     start1=temp->right;
//     temp->right->left=nullptr;
//     task=temp->task;
//     delete temp;
//     clear();
//     cout<<"Task number 1 is marked as complete"<<endl;
//     l1--;
//   }
//   else if(p<=l1/2){
//     cout<<"case 1"<<endl;
//     i=1;
//     // cout<<"Value of p = "<<p<<endl;
//     temp=start1;
//     while(1){
//       if(i==p){
//         temp2=temp->left;
//         temp2->right=temp->right;
//         if(temp->right!=nullptr)temp->right->left=temp2;
//         task=temp->task;
//         delete temp;
//         l1--;
//         break;
//       }
//       i++;
//       temp=temp->right;
//     }
//   } else {
//     cout<<"Case 2"<<endl;
//     temp=end1;
//     i=l1;
//     while(1){
//       if(i==p){
//         temp2=temp->left;
//         temp2->right=temp->right;
//         if(temp->right!=nullptr)temp->right->left=temp2;
//         task=temp->task;
//         if(temp==end1){
//           clear();
//           cout<<"Marking the last task of the list as complete"<<endl;
//           end1=temp2;
//         }
//         delete temp;
//         l1--;
//         break;
//       }
//       i--;
//       temp=temp->left;
//     }
//   }
//   return task;
// }
// void complete_manager(complete*&start2,complete*&end2){
//   complete*one_node=new complete(uni_task);
//   // cout<<"A node is created which contain Task = "<<one_node->task<<endl;
//   if(start2==nullptr){
//     cout<<"Congratulations on completing your first task!"<<endl;
//     l2++;
//     start2=one_node;
//   } else{
//     l2++;
//     one_node->right=start2;
//     start2->left=one_node;
//     start2=one_node;
//   }
//   uni_task.clear();
// }

// void pending_manager(string task,pending *& start1,pending *& end1,int p,int choice){
//   int i;
//   if(choice==2&&start1==nullptr){
//     cout<<"No tasks are assigned right now so cannot mark anything as complete"<<endl<<endl;
//     return;
//   }
//   if(choice==1)cout<<"We want to add at position = "<<p<<endl;
//   pending*one_node=new pending(task);

//   if(p==1){
//     if(choice==1){
//       if(start1==nullptr)end1=one_node;
//       clear();
//       if(start1==nullptr)cout<<"Linked list was empty"<<endl;
//       one_node->right=start1;
//       start1=one_node;
//       if(one_node->right!=nullptr)one_node->right->left=one_node;
//       } else if(choice==2){
//       pending*temp;//,*temp2
//       temp=start1;
//       start1=temp->right;
//       if(temp->right!=nullptr)temp->right->left=nullptr;
//       uni_task=temp->task;
//       delete temp;
//       clear();
//       cout<<"Task no-1 is marked as complete"<<endl;
//       l1--;
//       }
//   } else if(p==l1+1){
//     if(choice==1){
//     clear();
//     cout<<"You are adding at the end of the linked list"<<endl;
//     end1->right=one_node;
//     one_node->left=end1;
//     end1=end1->right;
//     } else if(choice==2){
//       clear();
//       cout<<"You have entered wrong position number\nEnter between 1-"<<l1<<endl;
//       uni_task="";
//     }
//   } else if(p<1||p>l1+1){
//     if(choice==1){
//     clear();
//     cout<<"You have entered a invalid location"<<endl;
//     l1--;
//     } else if(choice==2){
//       clear();
//       cout<<"You have entered wrong position number\nEnter between 1-"<<l1<<endl;
//       uni_task.clear();
//       // uni_task="";
//     }
//   }else {
    
//     pending*temp;
//     if(p<=l1/2){
//       if(choice==1){
//       cout<<"First case"<<endl;
//       temp=start1;
//       i=1;
//       while(1){
//         if(i==p){
//           one_node->right=temp;
//           one_node->left=temp->left;
//           temp->left->right=one_node;
//           temp->left=one_node;
//           clear();
//           cout<<"Task : "<<one_node->task<<" added\n";
//           break;
//         }
//         i++;
//         temp=temp->right;
//       }}
//       else if(choice==2){
//         pending*temp,*temp2;

//         cout<<"case 1"<<endl;
//           i=1;
//           cout<<"Value of p = "<<p<<endl;
//           temp=start1;
//           while(1){
//             if(i==p){
//               temp2=temp->left;
//               temp2->right=temp->right;
//               if(temp->right!=nullptr)temp->right->left=temp2;
//               uni_task=temp->task;
//               delete temp;
//               l1--;
//               break;
//             }
//             i++;
//             temp=temp->right;
//           }
//       }
//     } else {
//       if(choice==1){
//       cout<<"Second case"<<endl;
//       temp=end1;
//       i=l1;
//       while(1){
//         if(i==p){
//           pending*temp2=temp->left;
//           one_node->right=temp;
//           one_node->left=temp->left;
//           temp2->right=one_node;
//           temp->left=one_node;
//           clear();
//           cout<<"Task : "<<task<<" is added"<<endl;
//           break;
//         }
//         i--;
//         temp=temp->left;
//       }
//     } else if(choice==2){
//         pending*temp,*temp2;
//         cout<<"Case 2"<<endl;
//         temp=end1;
//         i=l1;
//         while(1){
//           if(i==p){
//             temp2=temp->left;
//             temp2->right=temp->right;
//             if(temp->right!=nullptr)temp->right->left=temp2;
//             uni_task=temp->task;
//             if(temp==end1){
//               clear();
//               cout<<"Marking the last task of the list as complete"<<endl;
//               end1=temp2;
//             }
//             delete temp;
//             l1--;
//             break;
//           }
//           i--;
//           temp=temp->left;
//         }
//     }
//     }
//   }
//    if(choice==1)l1++;
//   // if(choice==2){
//   //   cout<<"Task : "<<uni_task<<" is marked as completed"<<endl;
//   // }
// }

// void display(pending*&start1,pending*&end1){
//   pending*temp=start1;
//   if(temp==nullptr){
//     cout<<"No pending tasks :)"<<endl<<endl;;
//     return;
//   }
//   int i=1;
//   cout<<"Pending tasks are : "<<endl;
//   while(temp!=nullptr){
//     cout<<i<<". "<<temp->task<<endl;
//     temp=temp->right;
//     i++;
//   }
//   cout<<endl<<"Number of pending tasks : "<<l1<<endl;
// }
// void display_completed(complete*&start2){
//   complete*temp=start2;
//   if(temp==nullptr){
//     cout<<"No tasks are completed yet"<<endl;
//     return;
//   }
//   int i=1;
//   cout<<"Completed tasks are : "<<endl;
//   while(temp!=nullptr){
//     cout<<i<<". "<<temp->task<<endl;
//     i++;
//     temp=temp->right;
//   }
// }
// int main(){
//   int choice=1;
//   complete*start2=nullptr,*end2=nullptr;
//   pending*start1=nullptr,*end1=nullptr;
  
//   while(choice!=0){
//     cout<<"Enter your choice : \n1 : Add a task\n2 : Mark a task as complete\n3 : Show completed tasks\n0: Exit\nYour choice : ";
//     cin>>choice;
//     if(choice==1){
//       int p=1;
//       string task;
//       cout<<"Enter new task : ";
//       cin>>task;
//       if(start1!=nullptr){
//         cout<<"Enter priority number of the task you want to add : ";
//         cin>>p;
//       }
//       pending_manager(task,start1,end1,p,1);
//     } else if(choice==2){
//       int p;
//       cout<<"Enter task number which you want to mark as complete : ";
//       cin>>p;
//       clear();
//       pending_manager("",start1,end1,p,2);
//       if(!uni_task.empty()){
//         cout<<"Task "<<uni_task<<" is marked as complete and removed from pending lists"<<endl;
//         complete_manager(start2,end2);
//       }
//       // string marked=mark(start1,end1,p);
//       // cout<<"The task which is marked as complete is : "<<marked<<endl;
//     } else if(choice ==3){
//       clear();
//       display_completed(start2);
//     }
//     cout<<endl;
//     display(start1,end1);
//     cout<<"Number of completed tasks : "<<l2<<endl<<endl;
//   }
// }



// // #include<iostream>
// // using namespace std;
// // int l1=0,l2=0;
// // void clear() {
// //     cout << "\033[2J\033[1;1H";
// // }
// // class complete{
// // public:
// // string task;
// // complete*right,*left;
// // complete(string task){
// //   this->task=task;
// //   this->right=nullptr;
// //   this->left=nullptr;
// // }
// // };

// // class pending{
// // public:
// // string task;
// // pending*right,*left;
// // pending(string task){
// //   this->task=task;
// //   this->right=nullptr;
// //   this->left=nullptr;
// // }
// // };
// // string mark(pending*&start1,pending*&end1,int p);
// // void add_completed(string task,complete*&start2,complete*&end2);

// // string mark(pending*&start1,pending*&end1,int p){
// //   string task;
// //   pending*temp,*temp2;
// //   int i;
// //   if(p<1||p>l1+1){
// //     clear();
// //     cout<<"You have entered wrong position number\nEnter between 1-"<<l1<<endl;
// //   } else if(p==1){
// //     temp=start1;
// //     start1=temp->right;
// //     temp->right->left=nullptr;
// //     task=temp->task;
// //     delete temp;
// //     clear();
// //     cout<<"Task number 1 is marked as complete"<<endl;
// //     l1--;
// //   }
// //   else if(p<=l1/2){
// //     cout<<"case 1"<<endl;
// //     i=1;
// //     cout<<"Value of p = "<<p<<endl;
// //     temp=start1;
// //     while(1){
// //       if(i==p){
// //         temp2=temp->left;
// //         temp2->right=temp->right;
// //         if(temp->right!=nullptr)temp->right->left=temp2;
// //         task=temp->task;
// //         delete temp;
// //         l1--;
// //         break;
// //       }
// //       i++;
// //       temp=temp->right;
// //     }
// //   } else {
// //     cout<<"Case 2"<<endl;
// //     temp=end1;
// //     i=l1;
// //     while(1){
// //       if(i==p){
// //         temp2=temp->left;
// //         temp2->right=temp->right;
// //         if(temp->right!=nullptr)temp->right->left=temp2;
// //         task=temp->task;
// //         if(temp==end1){
// //           clear();
// //           cout<<"Marking the last task of the list as complete"<<endl;
// //           end1=temp2;
// //         }
// //         delete temp;
// //         l1--;
// //         break;
// //       }
// //       i--;
// //       temp=temp->left;
// //     }
// //   }
// //   return task;
// // }

// // void add_task(string task,pending *& start1,pending *& end1,int p,int choice){
// //   int i;
// //   cout<<"We want to add at position = "<<p<<endl;
// //   pending*one_node=new pending(task);
// //   if(p==1){
// //     if(choice==1){
// //       if(start1==nullptr)end1=one_node;
// //       clear();
// //       if(start1==nullptr)cout<<"Linked list was empty"<<endl;
// //       one_node->right=start1;
// //       start1=one_node;
// //       if(one_node->right!=nullptr)one_node->right->left=one_node;
// //       } else if(choice==2){

// //       }
// //   } else if(p==l1+1){
// //     clear();
// //     cout<<"You are adding at the end of the linked list"<<endl;
// //     end1->right=one_node;
// //     one_node->left=end1;
// //     end1=end1->right;
// //   } else if(p<1||p>l1+1){
// //     if(choice==1){
// //     clear();
// //     cout<<"You have entered a invalid location"<<endl;
// //     l1--;
// //     } else if(choice==2){
// //       clear();
// //       cout<<"You have entered wrong position number\nEnter between 1-"<<l1<<endl;
// //     }
// //   }else {
// //     pending*temp;
// //     if(p<=l1/2){
// //       cout<<"First case"<<endl;
// //       temp=start1;
// //       i=1;
// //       while(1){
// //         if(i==p){
// //           one_node->right=temp;
// //           one_node->left=temp->left;
// //           temp->left->right=one_node;
// //           temp->left=one_node;
// //           clear();
// //           cout<<"Task : "<<one_node->task<<" added\n";
// //           break;
// //         }
// //         i++;
// //         temp=temp->right;
// //       }
// //     } else {
// //       cout<<"Second case"<<endl;
// //       temp=end1;
// //       i=l1;
// //       while(1){
// //         if(i==p){
// //           pending*temp2=temp->left;
// //           one_node->right=temp;
// //           one_node->left=temp->left;
// //           temp2->right=one_node;
// //           temp->left=one_node;
// //           clear();
// //           cout<<"Task : "<<task<<" is added"<<endl;
// //           break;
// //         }
// //         i--;
// //         temp=temp->left;
// //       }
// //     }
// //   }
// //    l1++;
// // }

// // void display(pending*&start1,pending*&end1){
// //   pending*temp=start1;
// //   int i=1;
// //   cout<<"Pending tasks are : "<<endl;
// //   while(temp!=nullptr){
// //     cout<<i<<". "<<temp->task<<endl;
// //     temp=temp->right;
// //     i++;
// //   }
// //   cout<<"Number of pending tasks are : "<<l1<<endl;
// // }

// // int main(){
// //   int choice=1;
// //   // complete*start2=nullptr,*end2=nullptr;
// //   pending*start1=nullptr,*end1=nullptr;

// //   while(choice!=0){
// //     cout<<"Enter your choice : \n1 : Add a task\n2 : Mark a task as complete\n3 : Show completed tasks\n0: Exit\nYour choice : ";
// //     cin>>choice;
// //     if(choice==1){
// //       int p=1;
// //       string task;
// //       cout<<"Enter new task : ";
// //       cin>>task;
// //       if(start1!=nullptr){
// //         cout<<"Enter priority number of the task you want to add : ";
// //         cin>>p;
// //       }
// //       add_task(task,start1,end1,p);
// //     } else if(choice==2){
// //       int p;
// //       cout<<"Enter task number which you want to mark as complete : ";
// //       cin>>p;
// //       string marked=mark(start1,end1,p);
// //       cout<<"The task which is marked as complete is : "<<marked<<endl;
// //     } else if(choice ==3){

// //     }
// //     display(start1,end1);
// //   }
// // }




// // #include<iostream>
// // using namespace std;
// // class node{
// // public : 
// // int data;
// // node* right,*left;
// // node(int data){
// //   this->data=data;
// //   this->right=nullptr;
// //   this->left=nullptr;
// // }
// // };
// // void insert();
// // int main(){
// //   int j=10,i=1;
// //   node* start=nullptr,*end=nullptr;
// //   while(i!=5){
// //   if(start==nullptr){
// //     node* one_node=new node(j);
// //     j+=10;
// //     start=one_node;
// //     end=one_node;
// //     // one_node->left=start;
// //     cout<<"added"<<endl;
// //   } else{
// //     node* one_node=new node(j);
// //     j+=10;
// //     one_node->left=end;
// //     end->right=one_node;
// //     end=end->right;
// //     cout<<"done"<<endl;
// //   }
// //     i++;
// //   }
// //   cout<<"Linked list becomes :";
// //   node*temp=start;
// //   while(temp->right!=nullptr){
// //     cout<<temp->data<<" ";
// //     temp=temp->right;
// //   }
// //   cout<<temp->data;
// //   cout<<"staright traversing complete"<<endl;
// //   cout<<"Back traversing : ";
  
// //   while(temp->left!=nullptr){
// //     cout<<temp->data<<" ";
// //     temp=temp->left;
// //   } cout<<temp->data;
// // }

// // cout<<temp->data<<endl;
// // cout<<temp->left->data<<endl;
// //  cout<<temp->left->left->data<<endl; 
// // cout<<temp->left->left->left->data<<endl;
// // cout<<temp->left->left->left->left->data<<endl;
// // if(temp->left->left->left->left==nullptr)cout<<"Null";


// // #include<iostream>
// // using namespace std;
// // int c=1;
// // class pending{
// // public :
// // string task;
// // pending*right,*left;
// // pending(string task){
// //   this->task=task;
// // }
// // };
// // class completed{
// // public :
// // string task;
// // completed*right,*left;
// // completed(string task){
// //   this->task=task;
// // }
// // };
// // void display_p(pending*&start1,pending*&end1){
// //   pending*temp=start1;
// //   int i=1;
// //   while(temp!=NULL){
// //     cout<<i<<". "<<temp->task<<endl;
// //     i++;
// //     temp=temp->right;
// //   }
// // }
// // void merger_c(completed*&start2,completed*&one_node){
// //   cout<<"Went here"<<endl;
// //   if(start2==NULL){
// //     cout<<"Congratulation on completing your first task!"<<endl;
// //     start2=one_node;
// //     one_node->right=NULL;
// //     one_node->left=start2;
// //     c++;
// //   } else{
// //     cout<<"You have completed your "<<c<<"th task!"<<endl;
// //     one_node->right=start2;
// //     start2=one_node;
// //     one_node->left=start2;
// //     one_node->right->left=one_node;
// //     c++;
// //   }
// // }
// // void merger_p(pending*&behind,pending*&one_node){
// //   if(behind==NULL){
// //     cout<<"This is your first task"<<endl;
// //     behind=one_node;
// //     one_node->left=behind;
// //     one_node->right=NULL;
// //   } else{
// //     one_node->right=behind;
// //     behind=one_node;

// //     one_node->right->left=one_node;
// //     one_node->left=behind;
// //   }
// //   cout<<"Node added successfully"<<endl;
// // }
// // void add_task(pending*&start1,pending*&end1){
// //   string task;
// //   cout<<"Enter task : ";
// //   getline(cin,task);
// //   pending*one_node=new pending(task);
// //   merger_p(start1,one_node);
// // }
// // void mark(pending*&start1,pending*&end1,completed*&start2,completed*&end2){
// //   int p,i=0,ask;
// //   cout<<"Enter task number which you want to mark as complete : ";
// //   cin>>p;
// //   string task;
// //   pending*temp=start1;
// //   if(p==1){
// //     task=temp->task;
// //     start1->right=temp->right;
// //     start1->right->left=start1;
// //     cout<<"Task at temp->task : "<<temp->task<<endl;
// //     completed*one_node=new completed(task);
// //     merger_c(start2,one_node);
// //     delete temp;
// //     // break;
// //   }else { 
// //     while(1){
// //     if(i+2>=p){
// //       task=temp->right->task;
// //       cout<<"Do you want to mark task : "<<task<<" as complete? \n1: Yes \n0 : No\nYour choice : ";
// //       cin>>ask;
// //       if(ask==0){
// //         cout<<"task completion process cancelled"<<endl;
// //         break;
// //       }
// //       delete temp->right;
// //       if(temp->right->right!=NULL){
// //         temp->right=temp->right->right;
// //         temp->right->left=temp;
// //       } else{
// //         temp->right=NULL;
// //       }
// //       cout<<"Task : "<<task<<" is marked as completed"<<endl;
// //       completed*one_node=new completed(task);
// //       cout<<"Seprate node which we want to merge in completed list is : "<<one_node->task<<endl;
// //       merger_c(start2,one_node);
// //       break;
// //     } else if(temp->right==NULL){
// //       cout<<"Invalid input"<<endl;
// //       break;
// //     }
// //     i++;
// //     temp=temp->right;
// //   }
// // }
// // }
// // int main(){
// //   pending*start1=NULL,*end1=NULL;
// //   completed*start2=NULL,*end2=NULL;
// //   int choice=1;
// //   while(choice!=0){
// //     cout<<"Enter your choice :\n1 : Add task\n2 : Mark a task as complete\n3 : Display pending tasks\n4 : Display completed taks\n0 : Exit\nYour choice : ";
// //     cin>>choice;
// //     cin.ignore();
// //     if(choice==1)add_task(start1,end1);
// //     else if(choice==2)mark(start1,end1,start2,end2);
// //     else if(choice==3)display_p(start1,end1);
// //   }
// // }
// // // #include<iostream>
// // // using namespace std;
// // // class complete{
// // //   public:
// // //     string task;
// // //     complete* right;
// // //     complete* left;

// // //   complete(string task){
// // //     this->task=task;
// // //     this->right=NULL;
// // //     this->left=NULL;
// // //   }
// // // };
// // // class node{
// // // public:
// // // string task;
// // // node* right;
// // // node*left;
// // // node(string task){
// // //   this->task=task;
// // //   this->right=NULL;
// // //   this->left=NULL;
// // // }
// // // };
// // // void display_completed(complete*&start2,complete*&end2){
// // //   complete*temp=start2;
// // //   int i=1;
// // //   cout<<"Completed tasks are : "<<endl;
// // //   while(temp!=NULL){
// // //     cout<<i<<". "<<temp->task<<endl;
// // //     i++;
// // //     temp=temp->right;
// // //   }
// // // }
// // // void display_pending(node*&start1,node*&end1){
// // //   node*temp=start1;
// // //   int i=1;
// // //   cout<<"Pending tasks are : "<<endl;
// // //   while(temp!=NULL){
// // //     cout<<i<<". "<<temp->task<<endl;
// // //     i++;
// // //     temp=temp->right;
// // //   }
// // // }
// // // void mark_helper(complete*&start2,complete*&end2,complete*&one_node){
// // //   one_node->right=start2;
// // //   start2->right->left=one_node;
// // //   one_node->left=start2;
// // //   start2->right=one_node;
// // // }
// // // void mark(node*&start1,node*end1,complete*&start2,complete*&end2){
// // //   int p,i=0;
// // //   node*temp=start1;
// // //   cout<<"Enter task number to mark it as complete : ";
// // //   cin>>p;
// // //   string task;
// // //   if(p==1){
// // //     start1=start1->right->right;
// // //     start1->right->right->left=start1;
// // //     // temp->right->left=start1;
// // //     task=temp->task;
// // //     complete*one_node=new complete(task);
// // //     mark_helper(start2,end2,one_node);
// // //     cout<<"Task : "<<start2->right->task<<" is marked as completed"<<endl;
// // //   } else {
// // //     while(1){
// // //       if(i+2>=p){
// // //         task=temp->right->task;
// // //         complete*one_node=new complete(task);
// // //         delete temp->right;
// // //         temp->right=temp->right->right;
// // //         temp->right->right->left=temp;
// // //         cout<<"Task : "<<one_node->task<<" is marked as complete"<<endl;
// // //         mark_helper(start2,end2,one_node);
// // //         // free(temp->right);
// // //         delete temp->right;
// // //         break;
// // //       } else if(temp->right==NULL){
// // //         cout<<"Invalid input"<<endl;
// // //         break;
// // //       }
// // //     }
// // //   }
// // // }
// // // void add_task(node*&start1,node*&end1){
// // //   string task;
// // //   cout<<"Enter new task here : ";
// // //   // getline(cin,task);
// // //   cin>>task;
// // //   cout<<"Task saved"<<endl;
// // //   node*one_node=new node(task);
// // //   cout<<"Node created"<<endl;

// // //   if(start1==NULL){
// // //     start1=one_node;
// // //     one_node->right=NULL;
// // //     one_node->left=start1;
// // //     end1=one_node;
// // //     cout<<"This is your first task!"<<endl;
// // //   } else {
// // //     cout<<"Went here"<<endl;
// // //     one_node->right=start1;
// // //     cout<<"Went here"<<endl;

// // //     start1->right->left=one_node;
// // //     cout<<"Went here"<<endl;

// // //     start1=one_node;
// // //     cout<<"Went here"<<endl;

// // //     one_node->left=start1;
// // //     cout<<"Went here"<<endl;

// // //   }
// // //   cout<<"Task : "<<one_node->task<<"is set"<<endl;
// // // }

// // // int main(){
// // //   node*start1=NULL,*end1=NULL;
// // //   complete *start2=NULL,*end2=NULL;
// // //   int choice=1;
// // //   while(choice!=0){
// // //     cout<<"Choose option\n1 : Add task\n2 : Mark a task as complete\n3 : Display pending tasks\n4 : Display completed tasks\nYour option : ";
// // //     cin>>choice;
// // //     cin.ignore();
// // //     if(choice==1)add_task(start1,end1);
// // //     else if(choice==2)mark(start1,end1,start2,end2);
// // //     else if(choice==3)display_pending(start1,end1);
// // //     else if(choice==4)display_completed(start2,end2);
// // //   }
// // // }