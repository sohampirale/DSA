// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//       ListNode*slow=head,*fast=head;
//       if(fast==nullptr)return false;
//         while(fast!=nullptr&&fast->next!=nullptr){
//             fast=fast->next->next;
//             slow=slow->next;
//             if(fast==slow)return true;
//         }
//         return false;
//     }
// };


// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//       ListNode*slow=head,*fast=head;
//         while(fast!=nullptr){
//             fast=fast->next->next;
//             slow=slow->next;
//             if(fast==slow)return true;
//         }
//         return false;
//     }
// };
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode*temp=head;
//         vector<ListNode*>t;
//         while(1){
//             if(temp==nullptr)return false;
//             if(find(t.begin(),t.end(),temp)!=t.end()){
//                 return true;
//             }
//             head.push_back(temp);
//             temp=temp->next;
//         }
//     }
// };