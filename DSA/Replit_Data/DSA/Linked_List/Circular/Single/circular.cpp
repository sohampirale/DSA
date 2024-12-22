#include<iostream>
using namespace std;
class node{
public :
  int data;
  node*next;
node(int data){
  this->data=data;
}
};
void remove(node*&head,node*&tail,int choice){
  if(head==nullptr){
    cout<<"Linked List is empty"<<endl;
  }
  if(choice==4){
    node*temp=head;
  head=head->next;
  tail->next=head;
    cout<<"temp pointing at "<<temp->data<<endl;
    cout<<"Head pointing at : "<<head->data<<endl;
    cout<<"Tail pointing at : "<<tail->data<<endl;
    delete temp;
  } else if(choice==5){
    node*temp=head;
    while(temp->next!=tail)temp=temp->next;
    temp->next=tail->next;
    delete tail;
    tail=temp;
  } else if(choice==6){
    int p,i=1;
    cout<<"Enter the node number you want to remove : ";
    cin>>p;
    node*temp=head,*temp2;
    if(p==1){
      head=head->next;
      tail->next=head;
      delete temp;
      return;
    }    
    do{
      if(p-1==i){
        if(temp->next==tail){
          tail=temp;
        }
        temp2=temp->next;
        temp->next=temp2->next;
        delete temp2;
        return;
      }
      temp=temp->next;
      i++;
    }while(temp!=head);
    if(temp==head)cout<<"Invalid Input"<<endl;
  }
}
void add(node*&head,node*&tail,int choice){
  int data;
  cout<<"Enter the data you want to create node with : ";
  cin>>data;
  node*one_node=new node(data);
  if(choice==1){
    if(head==nullptr)tail=one_node;
    one_node->next=head;
    head=one_node;
    tail->next=head;
  } else if(choice==2){
    if(head==nullptr){
      one_node->next=one_node;
      head=one_node;
      tail=one_node;
    } else{
      tail->next=one_node;
      one_node->next=head;
      tail=one_node;
    }
  } else if(choice==3){
    if(head==nullptr){
      cout<<"LL is empty"<<endl;
      return;
    }
    int p,i=1;
    cout<<"At which position you want to insert this node : ";
    cin>>p;
    if(p==1){
      one_node->next=head;
      head=one_node;
      tail->next=one_node;
      cout<<"Added at start"<<endl;
      return;
    }
    node*temp=head;
    do{
      if(p-1==i){
        if(temp==tail){
          tail=one_node;
        }
        one_node->next=temp->next;
        temp->next=one_node;
        cout<<"Node added"<<endl;
        break;
      }
      temp=temp->next;
      i++;
    }while(temp!=head);
    if(temp==head){
      cout<<"Invalid input"<<endl;
    }
  }
}
void display(node*&head){
  if(head==nullptr){
    cout<<"Linked List is empty"<<endl;
    return;
  }
  node*temp=head;
  if(head==nullptr){
    cout<<"LL is empty"<<endl;
    return;
  }
  cout<<"Linked List is : ";
  do{
    cout<<temp->data<<" ";
    temp=temp->next;
  }while(temp!=head);
}
int main(){
  node *head=nullptr,*tail=nullptr;
  int choice=1;
  while(choice!=0){
    cout<<"Enter your choice :\n1 : Add at start\n2 : Add at end\n3 : Add at given location\n4 : Delete at start\n5 : Delete at vend\n6 : Delete at given location\n7 : Display\nYour choice : ";
    cin>>choice;
    if(choice>=1&&choice<=3)add(head,tail,choice);
      else if(choice>=4&&choice<=6)remove(head,tail,choice);
    else if(choice==7)display(head);
  }
}