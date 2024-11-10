//accepted
// void helper_swap_nodes(node*&start,node*&t1,node*&t2,node*&t3,node*&t4,node*t,int k){
//   if(t==nullptr)return;
//   if(i==k-1){
//       t1=t;
//       t2=t1->next;
//       cout<<"t1 marked at : "<<t1->data<<" & t2 marked at : "<<t2->data<<endl;
//   }
//   i++;
//     helper_swap_nodes(start,t1,t2,t3,t4,t->next,k);
//   if(t3!=nullptr||t4!=nullptr)return;
//   j++;
//     if(j==k){
//       l=1;
//       t3=t;
//       t4=t->next;
//       cout<<"t3 marked at : "<<t3->data<<" & t4 marked at : "<<t4->data<<endl;
//       return;
//     } else if(j==k-1&&t==start){
//       l=2;
//       t3=nullptr;
//       t4=t;
//       cout<<"t3 pointing at nullptr & t4 pointing at : "<<t4->data<<endl;
//       return;
//     } 
// }
// void helper2_swap_nodes(node*&start,node*&t3,node*&t4){
//   while(t4->next!=nullptr){
//       t3=t4;
//       t4=t4->next;
//   }
// cout<<"In helper two function t3 is at : "<<t3->data<<" & t4 is at : "<<t4->data<<endl;
// }
// void swap_nodes(node*&start,int k){
// if(start==nullptr||start->next==nullptr)return ;
// node*t1=nullptr,*t2=nullptr,*t3=nullptr,*t4=nullptr,*t=start,*t5=nullptr;
// if(k==1){
//     t2=start;
//     t3=start;
//     t4=start;
//     helper2_swap_nodes(start,t3,t4);
//     if(t2==t3){
//       cout<<"t1==t3"<<endl;
//         t4->next=t2;
//         t2->next=nullptr;
//         start=t4;
//         return ;
//     }  else  {
//         start=t4;
//         t4->next=t2->next;
//         t3->next=t2;
//         t2->next=nullptr;
//         return;
//     }
// }
//     helper_swap_nodes(start,t1,t2,t3,t4,t,k);
//     if(t1==t3&&t2==t4){
//       cout<<"Middle element choosen so returning list as it is"<<endl;
//       return;
//     } else if(t2==t3&&t1!=t4){
//       cout<<"Side by side elements need to be interchanged"<<endl;
//       t5=t4->next;
//       t1->next=t4;
//       t4->next=t2;
//       t2->next=t5;
//       return;
//     } else if(t3==nullptr&&t4==start){
//       cout<<"swapping first node"<<endl;
//       start=t2;
//       t2->next=t4->next;
//       t1->next=t4;
//       t4->next=nullptr;
//       return;
//     } else if(t1==t4&&t3!=t2){
//         t5=t2->next;
//         cout<<"Side by side elements need to be interchanged "<<endl;
//         t3->next=t2;
//         t2->next=t1;
//         t1->next=t5;
//         return;
//       }  else if(t1==t4&&t3!=t2){
//         t5=t2->next;
//         cout<<"Side by side elements need to be interchanged "<<endl;
//         t3->next=t2;
//         t2->next=t1;
//         t1->next=t5;
//         return;
//       }  else if(t1!=t3&&t2!=t4&&t2!=t3){
//           cout<<"No two pointers are coninciding"<<endl;
//           t5=t4->next;
//           t1->next=t4;
//           t4->next=t2->next;
//           t3->next=t2;
//           t2->next=t5;
//           return;
//       } else  {
//         cout<<"No condition satisfied"<<endl;
//       }
//     return ;
// }



// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k) {
//       vector<int>data;
//       ListNode*temp=head;
//       while(temp!=nullptr){
//         data.push_back(temp->val);
//         temp=temp->next;
//       }
//       int t=data[data.size()-k];
//       data[data.size()-k]=data[k-1];
//       data[k-1]=t;
//       temp=head;
//       int i=0;
//       while(temp!=nullptr){
//         temp->val=data[i];
//         i++;
//       }
//       return head;
//     }
// };


//not accepted
// class Solution {
// public:
// int i=1,j=-1;
// void helper(ListNode*&start,ListNode*&t1,ListNode*&t2,ListNode*&t3,ListNode*&t4,ListNode*&t,int k){
//     if(t==nullptr)return;
//     if(i==k-1){
//         t1=t;
//         t3=t1->next;
//         // cout<<"t1 marked at : "<<t1->data<<" & t3 marked at : "<<t3->data<<endl;
//     }
//     helper(start,t1,t2,t3,t4,t->next);
//     if(t2!=nullptr)return;
//     j++;
//     if(j==k){
//         t2=t;
//         t4=t->next;
//         // cout<<"t2 marked at : "<<t2->data<<" & t4 marked at : "<<t4->data<<endl;
//     }
// }
//     ListNode* swapNodes(ListNode* head, int k) {
//         ListNode*t1=nullptr,*t2=nullptr,*t3=nullptr,*t4=nullptr,*t=head,*t5=nullptr;
//         helper(head,t1,t2,t3,t4,t,k);
//         t5=t4->next;
//         t1->next=t4;
//         t4->next=t3->next;
//         t3->next=t5;
//         t2->next=t3;
//         // cout<<"Linked list becomes : ";
//         // display(head);
//     }
// };

