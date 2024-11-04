// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         if(head==nullptr||head->next==nullptr)return nullptr;
//         ListNode*temp=head,*slow=head,*fast=head;
//         while(fast!=slow){
//             fast=fast->next->next;
//             slow=slow->next;
//             if(fast==nullptr||fast->next==nullptr)return nullptr;
//         }
//         while(slow!=temp){
//             slow=slow->next;
//             if(slow==fast)temp=temp->next;
//         }
//         return slow;
//     }
// };


//more efficient
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         if(head==nullptr||head->next==nullptr)return nullptr;
//         int l=0;
//         ListNode*temp=head,*slow=head->next,*fast=head->next->next;
//         while(fast!=slow){
//             if(fast==nullptr||fast->next==nullptr)return nullptr;
//             fast=fast->next->next;
//             slow=slow->next;
//         }
//         while(slow!=temp){
//             slow=slow->next;
//             if(slow==temp)return slow;
//             temp=temp->next;
//         }
//         return temp;
//     }
// };