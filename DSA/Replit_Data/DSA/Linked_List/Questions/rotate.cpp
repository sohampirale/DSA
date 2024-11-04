// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {

//     }
// };

// void rotate(node*&start,int k){
//   int head,end;
//   vector<node*>nums;
//   node*temp=start;
//   while(temp!=nullptr){
//     nums.push_back(temp);
//     temp=temp->next;
//   }
//   head=0;
//   end=nums.size()-1;
//   for(int i=0;i<k;i++){
//     head=end;
//     end--;
//     if(end==-1)end=nums.size()-1;
//   }
//   cout<<"After "<<k<<" rotations head pointing at : "<<nums[head]->data<<" & end pointing at : "<<nums[end]->data<<endl;
//   nums[nums.size()-1]->next=nums[0];
//   start=nums[head];
//   nums[end]->next=nullptr;
// }