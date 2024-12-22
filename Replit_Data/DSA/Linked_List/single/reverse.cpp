#include<iostream>
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

void display(node*&start){
  node*temp=start;
  cout<<"Linked list is : "<<endl;
  while(temp!=nullptr){
    cout<<temp->data<<" ";
    temp=temp->next;
    // l++;
    // if(l==6)break;
  }
  cout<<endl;
}

void reverse(node*&start,node*temp1,node*ori_start,node*temp2=nullptr){
  if(start==nullptr)return;
  if(temp1==nullptr)return;
  if(temp1->next==nullptr){
    start=temp1;
    return;
  }
  temp2=temp1;
  temp1=temp1->next;
  reverse(start,temp1,temp2);
  temp1->next=temp2;
  temp1=temp2;
  if(temp2==ori_start){
    cout<<"Condition hit"<<endl;
    temp2->next=nullptr;
  }
}

int main(){
  node*start=nullptr;
  int data;
  while(1){
    cout<<"Enter a number : ";
    cin>>data;
    if(data==0)break;
    else if(data==-1)display(start);
    else{
    node*one_node=new node(data);
    cout<<"Node created with data = "<<one_node->data<<endl;
    if(start==nullptr){
      start=one_node;
    } else{
      one_node->next=start;
      start=one_node;
    }
    }
  }
  reverse(start,start,start);
  display(start);
}