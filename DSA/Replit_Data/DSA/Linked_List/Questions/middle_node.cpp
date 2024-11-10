// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode*fast=head,*slow=head;
//         if(head==nullptr)return nullptr;
//         else if(head->next==nullptr)return head;
//         while(fast!=nullptr||fast->next!=nullptr){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         return slow;
//     }
// };