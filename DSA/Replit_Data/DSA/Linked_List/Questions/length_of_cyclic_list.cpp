// void ans(){
//   node*temp=slow,*fast=start;
//   int l=0;
//   while(fast!=nullptr&&fast->next!=nullptr){
//     fast=fast->next->next;
//     slow=slow->next;
//     if(fast==slow){
//       do{
//         slow=slow->next;
//         l++;
//       }while(slow!=fast);
//       // while(slow!=fast){
//       //   slow=slow->next;
//       //   l++;
//       // }
//       cout<<"Length of the cyclic linked list is : "<<l<<endl;
//     }
    
//   }
// }