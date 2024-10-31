// class Solution {
// public:
//     int getDecimalValue(ListNode* head) {
//         ListNode*temp=head;
//         string ans;
//         int final_ans=0;
//         while(temp!=nullptr){
//             ans.push_back(temp->val);
//             temp=temp->next;
//         }
//         reverse(ans.begin(),ans.end());
//         for(int i=0;i<ans.length();i++){
//             final_ans+=((ans[i]-'0')*pow(2,i));
//         }
//         return final_ans;
//     }
// };