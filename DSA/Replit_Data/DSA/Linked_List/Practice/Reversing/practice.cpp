// whole reversing
// void reverse_whole(node*&start){
//   node*t=nullptr,*t2=start,*t1;
//   if(start->next!=nullptr)t1=start->next;
//   else {
//     cout<<"List has only 1 item"<<endl;
//     display(start);
//     return;
//   }
//   for(int i=0;t1!=nullptr||t2!=nullptr;i++){
//     t2->next=t;
//     t=t2;
//     t2=t1;
//     if(t1!=nullptr)t1=t1->next;
//   }
//   start=t;
//   display(start);
// }


// reverse half
// node* reverse_half(node*&start,node*slow,node*fast,node*t=nullptr){
//   if(fast==nullptr||fast->next==nullptr){
//     cout<<"Reached at the end"<<endl;
//     cout<<"Slow ptr is on "<<slow->data<<endl;
//     // start=t;
//     return t;
//   }
//    node*start=reverse_half(start,slow->next,fast->next->next,slow);
//     slow->next=t;
//   return start;
// }

// reverse from left to right index
// void reverse_given(node*&start,int left,int right){
  
// }