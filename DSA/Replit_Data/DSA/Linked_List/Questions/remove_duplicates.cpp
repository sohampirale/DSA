// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode*temp1,*temp2,*temp;
//         if(head!=nullptr&&head->=nullptr){
//             temp2=head;
//             temp1=head->next;
//         }
//         else return head;
//         while(temp1!=nullptr){
//             if(temp1->val==temp2->val){
//                 temp=temp1;
//                 temp1=temp->next;
//                 temp2->next=temp1;
//                 delete temp;
//             } else{
//                 temp2=temp1;
//                 temp1=temp1->next;
//             }
//         }
//         return head;
//     }
// };