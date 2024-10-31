// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//       int length1=0,length2=0;
//       ListNode*temp=l1,*end=nullptr;
//       int n1=0,n2=0,i=0;
//       while(temp!=nullptr){
//         n1=n1+(pow(10,i)*temp->val);
//         i++;
//         temp=temp->next;
//         length1++;
//       }
//       i=0;
//       temp=l2;
//       while(temp!=nullptr){
//         n2=n2+(pow(10,i)*temp->val);
//         i++;
//         temp=temp->next;
//         length1++;
//       }
//       string str=to_string(n1+n2);
//       int n3=stoi(str);
//       if(length1>length2)temp=l1;
//       else temp=l2;
//       while(temp!=nullptr){
//         temp->val=n3%10;
//         n3/=10;
//         end=temp;
//         temp=temp->next;
//       }
//       if(temp==nullptr&&n3!=0){
//         ListNode one_node=new ListNode(n3);
//         end->next=one_node;
//         end=one_node;
//       }
//       if(length1>length2)return l1;
//       else return l2;
//     }
// };

