
// class Solution {
// public:
//     int ans=-1;
//  void recursive_solution(ListNode*&start,ListNode*temp){
//         if(temp==nullptr){
//           return;
//         }
//         ListNode*temp2=temp->next;
//         recursive_solution(start,temp2);
//         if(start->val!=temp->val&&ans==-1){
//             cout<<"Not a palindrom when start is pointing at : "<<start->val<<" & temp->data = "<<temp->val<<endl;
//           ans=0;
//           return ;
//         }
//         else start=start->next;
//         if((temp==start||temp->next==start)&&ans==-1){
//             ans=1;
//             return;
//         }
//     }

//     bool isPalindrome(ListNode* head) {
//         if(head==nullptr)return false;
//         else if(head->next==nullptr)return true;
//         recursive_solution(head, head);
//         if(ans==1)return true;
//         else return false;
//     }

// };
//Recursive method acceptd

// class Solution {
// public:
//     bool helper(ListNode*&t1,ListNode*t2){
//       if(t2==nullptr)return 1;
//       bool ans=  helper(t1,t2->next);
//         if(ans==false)return false;
//         if(t1->val!=t2->val){
//         return false;
//         }
//         t1=t1->next;
//         return true;
//     }
//     bool isPalindrome(ListNode* head) {
//         return helper(head,head);
//     }
// };

// class Solution {
// public:
//     int ans=0;

//     void recursive_solution(ListNode*&start,ListNode*temp){
//         if(temp==nullptr){
//           return ;
//         }
//         recursive_solution(start, temp->next);
//         if(start->data!=temp->data&&ans==0){
//           // cout<<"Not a palindrome"<<endl;
//           ans=0;
//           return ;
//         }
//         else start=start->next;
//         if(temp==start||temp->next==start&&ans==0){
//             ans=1;
//             // cout<<"Palindrome"<<endl;
//             // cout<<"True at start->val : "<<start->val<<endl;
//             return ;
//         }
//     }

//     bool isPalindrome(ListNode* head) {
//          recursive_solution(head, head);
//         if(ans==0)return false;
//         else return true;
//     }

// };