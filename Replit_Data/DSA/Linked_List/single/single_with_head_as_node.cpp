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

void add(int p,node*&head,node*&tail){
  int data;
  cout<<"Enter the data you want to insert : ";
  cin>>data;
  node* one_node=new node(data);
  // cout<<"Enter at what position you want to insert : ";
  // cin>>p;
  if(p==1){
    if(head==nullptr){
      head->data=data;
    }
  }
}
int main(){
  node*head,*tail;
  int choice=1;
  while(choice!=0){
    cout<<"Enter your choice : \n1 : Add at start\n2 : Add at end\n3 : Add at given location\nYour choice : ";
    cin>>choice;
    
  }
}