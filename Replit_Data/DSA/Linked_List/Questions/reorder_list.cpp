




// class Solution {
// public:
//     void helper(ListNode*&t1,ListNode*t2,ListNode*&end){
//         if(t2==nullptr)return;
//         helper(t1,t2->next,end);
//         if(t1==t2||t2->next==t1){
//             t1->next==nullptr;
//             return;
//         }
//         end->next=t1;
//         end=t1;
//         t1=t1->next;
//         end->next=t2;
//         end=t2;
//     }
//     void reorderList(ListNode* head) {
//         ListNode*t1=head,*t2=head;
//         helper(t1,t2,head);
//         // head=one_node->next;
//     }
// };

// void helper_reorderlist(node*&t1,node*t2,node*&end){
//     if(t2==nullptr)return;
//       helper_reorderlist(t1,t2->next,end);
//     if(t==1)return;
//     end->next=t1;
//     end=t1;
//     t1=t1->next;
//     if(t2->next==t1){
//         end->next=nullptr;
//         t=1;
//         return;
//     }
//     end->next=t2;
//     end=t2;
// }
// void reorderList(node* head) {
//   node*t1=head,*t2=head,*one_node=new node(5),*temp=head;
//       helper_reorderlist(t1,t2,one_node);
//     head=temp;
// }