// //runtime error
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         if(head==nullptr)return head;
//         ListNode*temp=head,*end=head,*temp2=head;
//         while(end->next!=nullptr){
//             end=end->next;
//         }
//         while(temp!=nullptr){
//             if(temp->next!=nullptr&&temp->val>temp->next->val){
//                 if(temp==head){
//                     head=head->next;
//                     end->next=temp;
//                     temp->next=nullptr;
//                     end=end->next;
//                     temp=head;
//                     temp2=head;
//                     continue;
//                 } else if(temp->next!=nullptr){
//                     temp2->next=temp->next;
//                     end->next=temp;
//                     temp->next=nullptr;
//                     end=end->next;
//                     temp=head;
//                     temp2=head;
//                     continue;
//                 }
//             }
//             temp2=temp;
//             temp=temp->next;
//         }
//         return head;
//     }
// };