// class Solution {
// public:
//     int i=0;
//     void helper(ListNode*temp,int k){
//         if(temp==nullptr)return;
//         helper(temp->next,k);
//         if(i==k){
//             ListNode*t2=temp->next;
//             temp->next=temp->next->next;
//             delete t2;
//             return;
//         } 
//         i++;
//     }
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         helper(head,n);
//     }
// };