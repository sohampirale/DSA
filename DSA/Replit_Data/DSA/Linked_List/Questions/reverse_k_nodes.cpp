//Recursive method

// class Solution {
// public:
//     int test=0;
//     void reverse_k_helper(ListNode*&start,ListNode*&end,ListNode*&temp,int k,ListNode*t1,ListNode*t2=nullptr,int i=1){
//     if(t2==nullptr){
//         end=t1;
//         // cout<<"End is assigned at : "<<end->data<<endl;
//     }
//     if(i==k+1){
//         start=t2;
//         temp=start->next;
//         // cout<<"Temp is assigned at : "<<temp->data<<endl;
//         // cout<<"Start is assigned at : "<<start->data<<endl;
//         if(t1==nullptr){
//         // cout<<"reached the end and successfully paired all groups"<<endl;
//         test=2;
//         }
//         return ;
//     }
//     if(t1==nullptr){
//         test=1;
//         // cout<<"Not enough nodes to reverse"<<endl;
//         return;
//     }
//         reverse_k_helper(start,end,temp,k,t1->next,t1,i+1);
//     if(test==1)return;
//         t1->next=t2;
//     }
//     ListNode* reverseKGroup(ListNode* head, int k) {
//           ListNode*temp=head,*traverse=new ListNode(0);
//   ListNode*newstart=traverse;
//   for(int i=0;test!=1&&test!=2;i++){
//     if(i%k==0){
//       ListNode*start1=temp;
//       ListNode*end1;
//       reverse_k_helper(start1,end1,temp,k,start1);
//     //   cout<<"Start1 pointing at : "<<start1->data<<endl;
//     //   cout<<"End pointing at : "<<end1->data<<endl;
//     //   if(temp!=nullptr)cout<<"Temp pointing at : "<<temp->data<<endl;
//     //   cout<<"Short reversede Linked list is : "<<endl;
//     //   display(start1);
//       if(test==1){
//         traverse->next=temp;
//         traverse=temp;
//         // cout<<"Done"<<endl;
//         break;
//       }
//       traverse->next=start1;
//       traverse=end1;
//     //   cout<<"Linked list formed is : "<<endl;
//       // display(newstart->next);
//       i+=(k-1);
//     }
//     else temp=temp->next;
//   }

//   head=newstart->next;
//   delete newstart;
//   return head;
//     }
// };

//a bit different method 

// node* reverse_k_helper(node*&start,node*&temp,int k){
//   node*t=nullptr,*t2=start,*t1=start->next,*end=start;
//   for(int i=1;i<=k;i++){
//     t2->next=t;
//     t=t2;
//     t2=t1;
//     if(t1!=nullptr)t1=t1->next;
//     else break;
//   }
//   start=t;
//   temp=t2;
//   return end;
// }
// void reverse_k(node*start,int k){
//   node*temp=start,*traverse=new node(0);
//   node*newstart=traverse;
//   for(int i=0;temp!=nullptr;i++){
//     if(i%k==0){
//       node*start1=temp;
//       node*end1=reverse_k_helper(start1,temp,k);
//       cout<<"Start1 pointing at : "<<start1->data<<endl;
//       cout<<"End pointing at : "<<end1->data<<endl;
//       if(temp!=nullptr)cout<<"Temp pointing at : "<<temp->data<<endl;
//       cout<<"Short reversede Linked list is : "<<endl;
//       display(start1);
//       traverse->next=start1;
//       traverse=end1;
//       cout<<"Linked list formed is : "<<endl;
//       display(newstart->next);
//       i+=(k-1);
//     }
//     else temp=temp->next;
//   }
// }