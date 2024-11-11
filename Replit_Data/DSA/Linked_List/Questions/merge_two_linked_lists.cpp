// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode *t1=list1,*t2=list2,*start=nullptr,*end=nullptr,*one_node=nullptr;
//         while(t1!=nullptr||t2!=nullptr){
//             if(t1==nullptr){
//                 if(start==nullptr){
//                     start=t2;
//                     return start;
//                 }else {
//                     end->next=t2;
//                     return start;
//                 }
//             } else if(t2==nullptr){
//                 if(start==nullptr){
//                     start=t1;
//                     return start;
//                 }else {
//                     end->next=t1;
//                     return start;
//                 }
//             }  else if(t1->val<t2->val){
//                 one_node=new ListNode(t1->val);
//                 t1=t1->next;
//             } else if(t1->val>t2->val){
//                 one_node=new ListNode(t2->val);
//                 t2=t2->next;
//             }
//             if(start==nullptr){
//                 start=one_node;
//                 end=one_node;
//             } else{
//                 end->next=one_node;
//                 end=one_node;
//             }
//         }
//         return start;
//     }
// };

// // class Solution {
// // public:
// //     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
// //         ListNode *t1=list1,*t2=list2,*start=nullptr,*end=nullptr,*one_node,*extra;
// //         while(t1!=nullptr&&t2!=nullptr){
// //             if(t1==nullptr){
// //                 one_node=new ListNode(t2->val);
// //                 t2=t2->next;
// //             } else if(t2==nullptr){
// //                 one_node=new ListNode(t1->val);
// //                 t1=t1->next;
// //             } else if(t1->val==t2->val){
// //                 one_node=new ListNode(t1->val);
// //                 extra=new ListNode(t2->val);
// //                 t1=t1->next;
// //                 t2=t2->next;
// //             } else if(t1->val<t2->val){
// //                 one_node=new ListNode(t1->val);
// //                 t1=t1->next;
// //             } else if(t1->val>t2->val){
// //                 one_node=new ListNode(t2->val);
// //                 t2=t2->next;
// //             }
// //             if(start==nullptr){
// //                 start=one_node;
// //                 end=one_node;
// //             } else{
// //                 end->next=one_node;
// //                 end=one_node;
// //             }
// //             if(extra!=nullptr){
// //                 one_node->next=extra;
// //                 end=extra;
// //                 extra=nullptr;
// //             }
// //         }
// //         return start;
// //     }
// // };