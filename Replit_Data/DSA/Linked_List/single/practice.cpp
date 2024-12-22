#include<iostream>
#include<vector>
// #include<algorithm>
using namespace std;
class node{
public :
int data;
node*next;
node(int data){
  this->data=data;
  this->next=nullptr;
}
};
void remove_consecutive_sum_zero(node*&start){
  vector<node*>nodes;
  node*temp=start;
  cout<<"Hey there"<<endl;
  while(temp!=nullptr){
    nodes.push_back(temp);
    temp=temp->next;
  }
  cout<<"Nodes stored"<<endl;
  for(int i=0;i<nodes.size();i++){
    cout<<"Lets check for "<<nodes[i]->data<<" & i = "<<i<<endl;
    int sum=0;
    for(int j=i;j<nodes.size();j++){
      sum+=nodes[j]->data;
      if(sum==0){
        nodes.erase(nodes.begin()+i,nodes.begin()+j+1);
        cout<<"Data erased from i="<<i<<" & j = "<<j<<endl;
        i=-1;
        break;
      }
    }
    cout<<"checked for i="<<i<<endl;
  }
  cout<<"came out"<<endl;
  cout<<"Vector with data is now : ";
  for(int i=0;i<nodes.size();i++){
    cout<<nodes[i]->data<<" ";
  }
  start=nodes[0];
  for(int i=0;i<nodes.size()-1;i++){
    nodes[i]->next=nodes[i+1];
  }
  nodes[nodes.size()-1]->next=nullptr;
}
void rotate(node*&start,int k){
  int head,end;
  vector<node*>nums;
  node*temp=start;
  while(temp!=nullptr){
    nums.push_back(temp);
    temp=temp->next;
  }
  head=0;
  end=nums.size()-1;
  for(int i=0;i<k;i++){
    head=end;
    end--;
    if(end==-1)end=nums.size()-1;
  }
  cout<<"After "<<k<<" rotations head pointing at : "<<nums[head]->data<<" & end pointing at : "<<nums[end]->data<<endl;
  nums[nums.size()-1]->next=nums[0];
  start=nums[head];
  nums[end]->next=nullptr;
}
void jumpn(node*&jump,int n);
void delete_node(node*&start,int choice);
void recursive_solution(node*&start,node*temp);
void sortList(node* head);
void reverse_link_list_iteration(node*&start);
void reverse_link_list_recursion(node*&start,node*t1,node*t2=nullptr);
void display_recursion_reverse(node*t);
void reverse_specific(node*&start);
void reverse_specific_helper(node*&begin,int i,int right);
void display(node*&start);
void helper_reorderlist2(node*&t1,node*t2,node*&end);
void reorderList(node* head) ;
void helper_reorderlist(node*&t1,node*t2,node*&end);
node* find_mid(node*&start);
void reverse_half_half_merge(node*&start);
node*reverse_half_half_merge_helper(node*&head,int right);

int i=1,j=-1,l=0;
void helper_swap_nodes(node*&start,node*&t1,node*&t2,node*&t3,node*&t4,node*t,int k){
    if(t==nullptr)return;
    if(i==k-1){
        t1=t;
        t2=t1->next;
        cout<<"t1 marked at : "<<t1->data<<" & t2 marked at : "<<t2->data<<endl;
    }
    i++;
      helper_swap_nodes(start,t1,t2,t3,t4,t->next,k);
    if(t3!=nullptr||t4!=nullptr)return;
    j++;
      if(j==k){
        l=1;
        t3=t;
        t4=t->next;
        cout<<"t3 marked at : "<<t3->data<<" & t4 marked at : "<<t4->data<<endl;
        return;
      } else if(j==k-1&&t==start){
        l=2;
        t3=nullptr;
        t4=t;
        cout<<"t3 pointing at nullptr & t4 pointing at : "<<t4->data<<endl;
        return;
      } 
}
void helper2_swap_nodes(node*&start,node*&t3,node*&t4){
    while(t4->next!=nullptr){
        t3=t4;
        t4=t4->next;
    }
  cout<<"In helper two function t3 is at : "<<t3->data<<" & t4 is at : "<<t4->data<<endl;
}
void swap_nodes(node*&start,int k){
  if(start==nullptr||start->next==nullptr)return ;
  node*t1=nullptr,*t2=nullptr,*t3=nullptr,*t4=nullptr,*t=start,*t5=nullptr;
  if(k==1){
      t2=start;
      t3=start;
      t4=start;
      helper2_swap_nodes(start,t3,t4);
      if(t2==t3){
        cout<<"t1==t3"<<endl;
          t4->next=t2;
          t2->next=nullptr;
          start=t4;
          return ;
      }  else  {
          start=t4;
          t4->next=t2->next;
          t3->next=t2;
          t2->next=nullptr;
          return;
      }
  }
      helper_swap_nodes(start,t1,t2,t3,t4,t,k);
      if(t1==t3&&t2==t4){
        cout<<"Middle element choosen so returning list as it is"<<endl;
        return;
      } else if(t2==t3&&t1!=t4){
        cout<<"Side by side elements need to be interchanged"<<endl;
        t5=t4->next;
        t1->next=t4;
        t4->next=t2;
        t2->next=t5;
        return;
      } else if(t3==nullptr&&t4==start){
        cout<<"swapping first node"<<endl;
        start=t2;
        t2->next=t4->next;
        t1->next=t4;
        t4->next=nullptr;
        return;
      } else if(t1==t4&&t3!=t2){
          t5=t2->next;
          cout<<"Side by side elements need to be interchanged "<<endl;
          t3->next=t2;
          t2->next=t1;
          t1->next=t5;
          return;
        }  else if(t1==t4&&t3!=t2){
          t5=t2->next;
          cout<<"Side by side elements need to be interchanged "<<endl;
          t3->next=t2;
          t2->next=t1;
          t1->next=t5;
          return;
        }  else if(t1!=t3&&t2!=t4&&t2!=t3){
            cout<<"No two pointers are coninciding"<<endl;
            t5=t4->next;
            t1->next=t4;
            t4->next=t2->next;
            t3->next=t2;
            t2->next=t5;
            return;
        } else  {
          cout<<"No condition satisfied"<<endl;
        }
      return ;
}

















// if(t4!=nullptr)t5=t4->next;

// if(t2==t3){
//     t1->next=t4;
//     t4->next=t2;
//     t2->next=t5;
//     return;
// } else if(t1==t4){
//   cout<<"t1==t4"<<endl;
//   t3->next=t1;
//   t1->next=t2;
//   t2->next=nullptr;
//   start=t3;
//     return;
// } else if(t1==t2&&t4==t3){
//   if(l==1)return;
//   t4->next=t2;
//   t2->next=nullptr;
//   start=t4;
//   return;
// }else if(t1!=t3&&t2!=t4){
//   t1->next=t4;
//   t4->next=t2->next;
//   t2->next=t5;
//   t3->next=t2;
//   return;
// }
node* reverse_half(node*&start,node*slow,node*fast,node*t=nullptr){
  if(fast==nullptr||fast->next==nullptr){
    cout<<"Reached at the end"<<endl;
    cout<<"Slow ptr is on "<<slow->data<<endl;
    // start=t;
    return t;
  }
   node*newstart=reverse_half(start,slow->next,fast->next->next,slow);
    slow->next=t;
  return newstart;
}
void jumpn(node*&jump,int n){
  for(int i=1;i<=n;i++){
    if(jump->next!=nullptr)jump=jump->next;
    else{
      cout<<"Invalid jump output so made "<<i-1<<" jumps instead"<<endl;
      break;
    }
  }
}

int test=0;
void reverse_k_helper(node*&start,node*&end,node*&temp,int k,node*t1,node*t2=nullptr,int i=1){
 
  if(t2==nullptr){
    end=t1;
    cout<<"End is assigned at : "<<end->data<<endl;
  }
  if(i==k+1){
    start=t2;
    temp=start->next;
    cout<<"Temp is assigned at : "<<temp->data<<endl;
    cout<<"Start is assigned at : "<<start->data<<endl;
    if(t1==nullptr){
      cout<<"reached the end and successfully paired all groups"<<endl;
      test=2;
    }
    return ;
  }
  if(t1==nullptr){
    test=1;
    cout<<"Not enough nodes to reverse"<<endl;
    return;
  }
    reverse_k_helper(start,end,temp,k,t1->next,t1,i+1);
   if(test==1)return;
    t1->next=t2;
}
void reverse_k(node*&start,int k){
  node*temp=start,*traverse=new node(0);
  node*newstart=traverse;
  for(int i=0;test!=1&&test!=2;i++){
    if(i%k==0){
      node*start1=temp;
      node*end1;
      reverse_k_helper(start1,end1,temp,k,start1);
      cout<<"Start1 pointing at : "<<start1->data<<endl;
      cout<<"End pointing at : "<<end1->data<<endl;
      if(temp!=nullptr)cout<<"Temp pointing at : "<<temp->data<<endl;
      cout<<"Short reversede Linked list is : "<<endl;
      display(start1);
      if(test==1){
        traverse->next=temp;
        traverse=temp;
        cout<<"Done"<<endl;
        break;
      }
      traverse->next=start1;
      traverse=end1;
      cout<<"Linked list formed is : "<<endl;
      // display(newstart->next);
      i+=(k-1);
    }
    else temp=temp->next;
  }
  // cout<<"Linked List formed is : ";
  // display(newstart);
  cout<<"Final Answer is : ";
  start=newstart;
  delete newstart;
  display(start);
}

node* find_mid(node*&start){
  node*slow=start,*fast=start;
  while(fast!=nullptr||fast->next!=nullptr){
    fast=fast->next->next;
    slow=slow->next;
  }
  return slow;
}
int t=0;




void helper_reorderlist(node*&t1,node*t2,node*&end){
    if(t2==nullptr)return;
      helper_reorderlist(t1,t2->next,end);
    if(t==1)return;
    end->next=t1;
    end=t1;
    t1=t1->next;
    if(t2->next==t1){
        end->next=nullptr;
        t=1;
        return;
    }
    end->next=t2;
    end=t2;
}

void reorderList(node* head) {
  node*t1=head,*t2=head,*one_node=new node(5),*temp=head;
      helper_reorderlist(t1,t2,one_node);
    head=temp;
}

void helper_reorderlist2(node*&t1,node*t2,node*&end){
  if(t2==nullptr)return;
  helper_reorderlist2(t1,t2->next,end);
  if(t==1)return;
  end->next=t1;
  end=t1;
  t1=t1->next;
  if(t2->next==t1){
      end->next=nullptr;
      t=1;
      return;
  }
  end->next=t2;
  end=t2;
}
void reorderList2(node* head) {
  // node*mid=find_mid(head);
  
node*t1=head,*t2=head,*one_node=new node(5),*temp=head;
    helper_reorderlist2(t1,t2,one_node);
  head=temp;
}


void display(node*&start){
  if(start==nullptr){
    cout<<"Linked List is empty"<<endl;
    return;
  }
  node*temp=start;
  cout<<"Linked list is : ";
  while(temp!=nullptr){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}
// void reverse_specific_helper(node*&begin,int i,int right){
//   node*t2,*t1,*t=begin,*tail=begin->next;
//   t2=begin->next;
//   t1=begin->next->next;
//   while(i<=right){
//     t2->next=t;
//     t=t2;
//     t2=t1;
//     if(t1!=nullptr)t1=t1->next;
//     i++;
//   }
//   node*head=t;
//   begin->next=head;
//   tail->next=t2;
// }


void reverse_specific_helper(node*&begin,int i,int right){
  node*t2,*t1,*t=begin,*tail=begin->next;
  t2=begin->next;
  if(begin->next!=nullptr)t1=begin->next->next;
  while(i<=right){
    t2->next=t;
    t=t2;
    t2=t1;
    i++;
    if(t1!=nullptr)t1=t1->next;
    else if(i>right){
      cout<<"Job done"<<endl;
      break;
    } else {
      cout<<"Invalid Input"<<endl;
      break;
    }
  }
  node*head=t;
  begin->next=head;
  tail->next=t2;
}

node*reverse_half_half_merge_helper(node*&head,int right){
  cout<<"right = "<<right<<endl;
  node*t=nullptr,*t1=head->next,*t2=head,*end=head;
  for(int i=1;i<=right;i++){
    t2->next=t;
    t=t2;
    t2=t1;
    if(t1!=nullptr)t1=t1->next;
  }
  cout<<"t pointing at : "<<t->data<<endl;
  head=t;
  return end;
}

void reverse_half_half_merge(node*&start){
  node*fast=start,*slow=start;
  int i=1;
  while(fast!=nullptr&&fast->next!=nullptr){
    slow=slow->next;
    fast=fast->next->next;
    i++;
  }
  cout<<"Hey slow pointing at : "<<slow->data<<endl;
  node*start1=start;
  node*end1=reverse_half_half_merge_helper(start1,i-1);
  cout<<"First half linked list is : ";display(start1);
  cout<<"start1 pointing at : "<<start1->data<<" & end1 pointing at : "<<end1->data<<endl;
  node*start2=slow;
  node*end2=reverse_half_half_merge_helper(start2,i-1);
  cout<<"Second half linked list is : ";display(start2);
  cout<<"start2 pointing at : "<<start2->data<<" & end2 pointing at : "<<end2->data<<endl;
  end1->next=start2;
  cout<<"After merging two linked list becomes : ";
  display(start1);
  if(fast==nullptr){
    if(end2->next==nullptr)cout<<"Already"<<endl;
    end2->next=nullptr;
  } else if(fast->next==nullptr){
    end2->next=fast;
    if(fast->next==nullptr)cout<<"ALready set"<<endl;
    fast->next=nullptr;
  }
  cout<<"Liked list after half-half reverse is :";display(start1);
}

void reverse_specific(node*&start){
  if(start==nullptr){
    cout<<"Linked list is empty"<<endl;
    return;
  } else if(start->next==nullptr){
    cout<<"Linked list has 1 element"<<endl;
    return;
  }
  int left,right;
  node*tempo=new node(0);
  tempo->next=start;
  cout<<"Enter left & right limit : ";
  cin>>left>>right;
  if(left==1){
    cout<<"hi"<<endl;
    reverse_specific_helper(tempo,1,right);
    start=tempo->next;
    cout<<"When left ==1 given linked list becomes : ";
    display(start);
    return;
  }
  node*begin=start;
  int i=1;
  while(i!=left-1){
    begin=begin->next;
    i++;
  }
  // t=begin;
  cout<<"Before calling the helper linked list is : ";
  display(start);
  reverse_specific_helper(begin,i+1,right);
  cout<<"After calling the helper lnked list is : ";
  display(start);
}

void display_recursion_reverse(node*t){
  if(t==nullptr){
    cout<<"Linked list priniting backwards is : ";
    return;
  }
  display_recursion_reverse(t->next);
  cout<<t->data<<" ";
}

// int t=0;

void reverse_link_list_recursion(node*&start,node*t1,node*t2){
  // static node*t1=start,*t2=nullptr;
  if(t1->next==nullptr){
    start=t1;
    t1->next=t2;
    return;
  }
  // t2=t1;
  // t1=t1->next;
  reverse_link_list_recursion(start,t1->next,t1);
  // if(t==0){
  //   start=t1;
  //   t=1;
  // }
  t1->next=t2;
}
// void reverse_link_list_recursion(node*&start,node*t1,node*t2=nullptr){
//   // static node*t1=start,*t2=nullptr;
//   if(t1==nullptr)return;
//   // t2=t1;
//   // t1=t1->next;
//   reverse_link_list_recursion(start,t1->next,t1);
//   if(t==0){
//     start=t1;
//     t=1;
//   }
//   t1->next=t2;
// }
void reverse_link_list_iteration(node*&start){
node*t=nullptr,*t2=start,*t1=start->next;
  while(t2!=nullptr){
    t2->next=t;
    if(t!=nullptr)cout<<t2->data<<" connected to "<<t->data<<endl;//for printing only
    // if(t1==nullptr)start=t2;//reached the end of linked list so updateing the start
    t=t2;
    t2=t1;
    // if(t1==nullptr)break;
    if(t1!=nullptr)t1=t1->next;
    else start=t;
  }
}
int ans=-1;

void sortList(node* head) {
    node*t1,*t2;
    int t=1;
    while(t!=0){
        t1=head;
        t2=head;
        t=0;
        while((t1)!=nullptr){
            if(t1->next!=nullptr&&((t1->data)>(t1->next->data))){
              cout<<"Found condsition at t1="<<t1->data<<" & t2= "<<t2->data<<endl;
                    if(t1==head){

                        t2=t1->next;
                        t1->next=t2->next;
                        t2->next=t1;
                        head=t2;
                    } else {
                        t2->next=t1->next;
                        t1->next=t1->next->next;
                        t2->next->next=t1;
                    }
                    t=1;
              cout<<"After interchanging"<<endl;
              display(head);
            }
            t2=t1;
            t1=t1->next;
        }
        if(t==0)break;
        else {
          cout<<"Still sorting possible"<<endl;
        }
    }
    return ;
}

    void recursive_solution(node*&start,node*temp){
        if(temp==nullptr){
          return ;
        }
        recursive_solution(start, temp->next);

        if(start->data!=temp->data){
            cout<<"Not a palindrom when start is pointing at : "<<start->data<<" & temp->data = "<<temp->data<<endl;
          // cout<<"Not a palindrome"<<endl;
          ans=0;
          return ;
        }
        else start=start->next;
        if((temp==start||temp->next==start)&&ans==-1){
          cout<<"Palindrome found at start pointing at "<<start->data<<" & temp pointing at : "<<temp->data<<endl;
            ans=1;
            return;
        }
        // if((temp==start||temp->next==start)&&ans==-1){
        //     ans=1;
        //     // cout<<"Palindrome"<<endl;
        //     // cout<<"True at start->val : "<<start->val<<endl;
        //     return ;
        // }
    }

// void recursive_solution(node*&start,node*temp){
//     if(temp==nullptr){
//       ans=0;
//       return ;
//     }
//     recursive_solution(start, temp->next);
//     if(start->data!=temp->data){
//       cout<<"Not a palindrome"<<endl;
//       ans=0;
//       return ;
//     }
//     else start=start->next;
//     if(temp==start||temp->next==start&&ans==-1){
//         ans=1;
//         cout<<"Palindrome"<<endl;
//         // cout<<"True at start->val : "<<start->val<<endl;
//         return ;
//     }
// }

void delete_node(node*&start,int choice){
  int p;
  if(choice==6){
    cout<<"Enter node number which you want ot delete : ";
    cin>>p;
    if(p==1)choice=4;
    else if(p<1){
      cout<<"Invalid location"<<endl;
      return;
    }
  }
   if(choice==4){
    if(start==nullptr)cout<<"LL is empty"<<endl;
    else{
    node*temp=start;
    start=temp->next;
      delete temp;
    }
  } else if(choice==5){
    if(start==nullptr)cout<<"LL is empty"<<endl;
    else {
      node*temp1=start,*temp2;
      while(temp1->next!=nullptr){
        temp2=temp1;
        temp1=temp1->next;
      }
      temp2->next=nullptr;
      cout<<"Node deleted which had data = "<<temp1->data<<endl;
      delete temp1;
    }
  } else if(choice==6){
    node*temp1=start,*temp2;
     int i=1;
     while(i<p&&temp1!=nullptr){
       temp2=temp1;
       temp1=temp1->next;
       i++;
     }
     if(temp1==nullptr)cout<<"Invalid location"<<endl;
     else {
       temp2->next=temp1->next;
       cout<<"Node no "<<p<<" deleted which had data = "<<temp1->data<<endl;
       delete temp1;
     }
  }
}
void add(node*&start,int choice){
  int data,p;
  cout<<"Enter the data you want to add : ";
  cin>>data;
  if(choice==3){
    cout<<"Enter at what position you want to insert node at : ";
    cin>>p;
    if(p==1)choice=1;
    else if(p<1){
      cout<<"Invalid location"<<endl;
      return;
    }
  }
  node* one_node=new node(data);
  if(choice==1){
    if(start==nullptr){
      cout<<"LL is empty so Let's add at the start"<<endl;
      start=one_node;
    } else{
      one_node->next=start;
      start=one_node;
    }
  } else if(choice==2){
    if(start==nullptr){
      cout<<"LL is empty"<<endl;
    } else {
    node*temp=start;
    while(temp->next!=nullptr){
      temp=temp->next;
    }
    temp->next=one_node;
    }
  } else if(choice==3){
    node*temp=start;
    int i=1;
    while(i<p-1&&temp!=nullptr){
      temp=temp->next;
      i++;
    }
    if(temp==nullptr)cout<<"Invalid location"<<endl;
    else {
      one_node->next=temp->next;
      temp->next=one_node;
    }
    cout<<"Node is added which has data = "<<data<<endl;
  } 
}

int main(){
  int choice=1;
  node*start=nullptr;
  node*slow=start,*fast=start;
  while(choice!=0){
    cout<<"Enter your choice :\n1 : Add at start\n2 : Add at end\n3 : Add at given location\n4 : Delete at start\n5 : Delete at end\n6 : Delete at gievn location\n7 : Display Linked List\n8 : Recursive Solution\n9 : Sort List\n10 : Reverse Link List using recursion\n11 : Reverse Linked List via iteration\n12 : Display Linked list in reverse order using recursion\n13 : Reverse specific portion of the linked list\n14 : Reorder List\n15 : Reverse Linked List in half half and merge\n16 : Reverse k nodes\n17 : Jump a pointer n nodes\n18 : Reverse Half\n19 : Swap two nodes\n0 : Exit\n20 : Rotate Linked List\n21 : Remove consecutive nodes which adds sum to zero\nYour choice : ";
    cin>>choice;
    if(choice>0&&choice<4)add(start,choice);
    else if(choice>=4&&choice<=6)delete_node(start,choice);
    else if(choice==7)display(start);
    else if(choice==8){
      cout<<"Value of ans before calling the function is = "<<ans<<endl;
      recursive_solution(start,start);
      cout<<"Value of ans = "<<ans<<endl;
    } 
    else if(choice==9)sortList(start);
    else if(choice==10){
      reverse_link_list_recursion(start,start);
      cout<<"After reversing ";
      display(start);
    } else if(choice==11){
      reverse_link_list_iteration(start);
      cout<<"After reversing via iteration ";
      display(start);
    } else if(choice==12){
      display_recursion_reverse(start);
      cout<<endl;
    } else if(choice==13){
      reverse_specific(start);
      cout<<endl;
    } else if(choice==14){
      reorderList(start);
      cout<<"After recordering list becomes :";
      display(start);
    } else if(choice==15)reverse_half_half_merge(start);
    else if(choice==16){
      int k;
      cout<<"Enter k : ";
      cin>>k;
      reverse_k(start,k);
    } else if(choice==17){
      node*jump=start;
      int n;
      cout<<"Enter how many jumps you want the pointer to do : ";
      cin>>n;
      jumpn(jump,n);
      cout<<"Jump pointer isn pointing at : "<<jump->data<<endl;
    } else if(choice==18){
      node*end=start;
      cout<<"End is pointing at : "<<end->data<<endl;
      node*newstart=reverse_half(start,slow,start);
      cout<<"Lets see"<<endl;
      end->next=slow;
      display(newstart);
    } else if(choice==19){
      int k;
      cout<<"Enter ndoe numebr which you want to swap : ";
      cin>>k;
      swap_nodes(start,k);
      cout<<"After swapping Linked List becomes : ";
      i=1;
      j=-1;
    } else if(choice==20){
      int k;
      cout<<"How many times you want ot rotate the linked list : ";
      cin>>k;
      rotate(start,k);
    } else if(choice==21){
      remove_consecutive_sum_zero(start);
      cout<<"Hello"<<endl;
    }
    display(start);
  }
}