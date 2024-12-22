#include<iostream>
#include <cstdlib>
using namespace std;
class pending{
public : 
string task;
pending* next;
pending(string task){
  this->task=task;
  this->next=NULL;
}
};typedef pending PENDING;

class complete{
public : 
string task;
complete* next;
complete(string task){
  this->task=task;
  this->next=NULL;
}
};typedef complete COMPLETE;

void helper(int choice,PENDING*&start1,PENDING*&end1,COMPLETE*&start2,COMPLETE*&end2){
  if(choice==0)return;
  else if(choice==1||start1==NULL){
    string task;
    cout<<"Enter task : ";
    getline(cin,task);
    // cin.ignore();
    PENDING* one_task=new PENDING(task);
    if(start1==NULL){
      cout<<"This is your first task!"<<endl;
      start1=one_task;
      end1=one_task;
    } else{
      // one_task->next=end1->next;
      end1->next=one_task;
      end1=end1->next;
      cout<<"Task stored and data updated"<<endl;
    }
    cout<<"Task : '"<<one_task->task<<"' stored successfully at the end"<<endl;
  } else if(choice==2||choice==3){
    PENDING* temp=start1;
    int i=1;
    cout<<"Pending tasks are : "<<endl;
    while(temp->next!=NULL){
      cout<<i<<". "<<temp->task<<endl;
      i++;
      temp=temp->next;
    }
    cout<<i<<". "<<temp->task<<" "<<endl;
    if(choice==2){
      int n;
      cout<<"Enter task number which you want to mark as completed : ";
      cin>>n;
      temp=start1;
      i=0;
      if(n==1){
        string demo=temp->task;
        COMPLETE* taskk=new COMPLETE(demo);
        start1=temp->next;
        taskk->next=start2;
        start2=taskk;
        cout<<"Task : '"<<taskk->task<<"' is marked as completed"<<endl;
        free(temp);
      } else while(1){
        if(i+2>=n){
          PENDING*temp2=temp->next;
          string demo=temp2->task;
          COMPLETE* taskk=new COMPLETE(demo);
          // taskk->task=temp2->task;
          taskk->next=start2;
          start2=taskk;
          temp->next=temp2->next;
          free(temp2);
          cout<<"Task : '"<<taskk->task<<"' is marked as completed"<<endl;
          break;
        }
        i++;
        temp=temp->next;
      }
    }
  } else if(choice ==4){
    COMPLETE*temp=start2;
    int i=1;
    cout<<"Completed tasks are : "<<endl;
    while(temp!=NULL){
      cout<<i<<". "<<temp->task<<endl;
      i++;
      temp=temp->next;
    }
  }
}
void clear() {
    cout << "\033[2J\033[H";  
}
int main(){
  COMPLETE *start2=NULL,*end2=NULL;
  PENDING *start1=NULL,*end1=NULL;
  int choice=1;
  while(choice!=0){
    cout<<"Choose option :\n1 : Add a task\n2 : Mark a task as complete\n3 : Show pending tasks\n4 : Show completed tasks\nYour option : ";
    cin>>choice;
    cin.ignore();
    clear();
    helper(choice,start1,end1,start2,end2);
  }
}