// class Solution {
// public:

//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         vector<ListNode*>addr1;
//         vector<ListNode*>addr2;
//         ListNode*t1=headA,*t2=headB;
//        while(t1!=nullptr){
//            addr1.push_back(t1);
//            t1=t1->next;
//        }
//         while(t2!=nullptr){
//             addr2.push_back(t2);
//             t2=t2->next;
//         }
//         sort(addr1.begin(),addr1.end());
//         sort(addr2.begin(),addr2.end());
//         vector<ListNode*>common;
//         set_intersection(addr1.begin(),addr1.end(),addr2.begin(),addr2.end(),back_inserter(common));
//         if(!common.empty())return common[0];
//         else return nullptr;
//     }
// };
// // class Solution {
// // public:
    
// //     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
// //         ListNode*t1=headA,*t2=headB;
// //         while(t1!=nullptr){
// //             while(t2!=nullptr){
// //                 if(t1==t2)return t1;
// //                 t2=t2->next;
// //             }
// //             t2=headB;
// //             t1=t1->next;
// //         }
// //         return nullptr;
// //     }
// // };