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


int main(){
  int choice=1;
  node*start=nullptr;
  node*slow=start,*fast=start;
  while(choice!=0){
    cout<<"Enter your choice :\n1 : Add at start\n2 : Add at end\n3 : Add at given location\n4 : Delete at start\n5 : Delete at end\n6 : Delete at gievn location\n7 : Display Linked List\nYour choice : ";
    cin>>choice;
    if(choice>0&&choice<4)add(start,choice);
    else if(choice>=4&&choice<=6)delete_node(start,choice);
    else if(choice==7)display(start);
  }
}