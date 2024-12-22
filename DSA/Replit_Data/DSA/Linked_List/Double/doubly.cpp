#include<iostream>
using namespace std;
int l1=0,l2=0;
void clear() {
    cout << "\033[2J\033[1;1H";
}
class complete{
public:
string task;
complete*right,*left;
complete(string task){
  this->task=task;
  this->right=nullptr;
  this->left=nullptr;
}
};

class pending{
public:
string task;
pending*right,*left;
pending(string task){
  this->task=task;
  this->right=nullptr;
  this->left=nullptr;
}
};
string mark(pending*&start1,pending*&end1,int p);
void add_completed(string task,complete*&start2,complete*&end2);
string uni_task;

string mark(pending*&start1,pending*&end1,int p){
  string task;
  pending*temp,*temp2;
  int i;
  if(p<1||p>l1+1){
    clear();
    cout<<"You have entered wrong position number\nEnter between 1-"<<l1<<endl;
  } else if(p==1){
    temp=start1;
    start1=temp->right;
    temp->right->left=nullptr;
    task=temp->task;
    delete temp;
    clear();
    cout<<"Task number 1 is marked as complete"<<endl;
    l1--;
  }
  else if(p<=l1/2){
    cout<<"case 1"<<endl;
    i=1;
    // cout<<"Value of p = "<<p<<endl;
    temp=start1;
    while(1){
      if(i==p){
        temp2=temp->left;
        temp2->right=temp->right;
        if(temp->right!=nullptr)temp->right->left=temp2;
        task=temp->task;
        delete temp;
        l1--;
        break;
      }
      i++;
      temp=temp->right;
    }
  } else {
    cout<<"Case 2"<<endl;
    temp=end1;
    i=l1;
    while(1){
      if(i==p){
        temp2=temp->left;
        temp2->right=temp->right;
        if(temp->right!=nullptr)temp->right->left=temp2;
        task=temp->task;
        if(temp==end1){
          clear();
          cout<<"Marking the last task of the list as complete"<<endl;
          end1=temp2;
        }
        delete temp;
        l1--;
        break;
      }
      i--;
      temp=temp->left;
    }
  }
  return task;
}
void complete_manager(complete*&start2,complete*&end2){
  complete*one_node=new complete(uni_task);
  // cout<<"A node is created which contain Task = "<<one_node->task<<endl;
  if(start2==nullptr){
    cout<<"Congratulations on completing your first task!"<<endl;
    l2++;
    start2=one_node;
  } else{
    l2++;
    one_node->right=start2;
    start2->left=one_node;
    start2=one_node;
  }
  uni_task.clear();
}

void pending_manager(string task,pending *& start1,pending *& end1,int p,int choice){
  int i;
  if(choice==2&&start1==nullptr){
    cout<<"No tasks are assigned right now so cannot mark anything as complete"<<endl<<endl;
    return;
  }
  if(choice==1)cout<<"We want to add at position = "<<p<<endl;
  pending*one_node=new pending(task);

  if(p==1){
    if(choice==1){
      if(start1==nullptr)end1=one_node;
      clear();
      if(start1==nullptr)cout<<"Linked list was empty"<<endl;
      one_node->right=start1;
      start1=one_node;
      if(one_node->right!=nullptr)one_node->right->left=one_node;
      } else if(choice==2){
      pending*temp;//,*temp2
      temp=start1;
      start1=temp->right;
      if(temp->right!=nullptr)temp->right->left=nullptr;
      uni_task=temp->task;
      delete temp;
      clear();
      cout<<"Task no-1 is marked as complete"<<endl;
      l1--;
      }
  } else if(p==l1+1){
    if(choice==1){
    clear();
    cout<<"You are adding at the end of the linked list"<<endl;
    end1->right=one_node;
    one_node->left=end1;
    end1=end1->right;
    } else if(choice==2){
      clear();
      cout<<"You have entered wrong position number\nEnter between 1-"<<l1<<endl;
      uni_task="";
    }
  } else if(p<1||p>l1+1){
    if(choice==1){
    clear();
    cout<<"You have entered a invalid location"<<endl;
    l1--;
    } else if(choice==2){
      clear();
      cout<<"You have entered wrong position number\nEnter between 1-"<<l1<<endl;
      uni_task.clear();
      // uni_task="";
    }
  }else {
    
    pending*temp;
    if(p<=l1/2){
      if(choice==1){
      cout<<"First case"<<endl;
      temp=start1;
      i=1;
      while(1){
        if(i==p){
          one_node->right=temp;
          one_node->left=temp->left;
          temp->left->right=one_node;
          temp->left=one_node;
          clear();
          cout<<"Task : "<<one_node->task<<" added\n";
          break;
        }
        i++;
        temp=temp->right;
      }}
      else if(choice==2){
        pending*temp,*temp2;

        cout<<"case 1"<<endl;
          i=1;
          cout<<"Value of p = "<<p<<endl;
          temp=start1;
          while(1){
            if(i==p){
              temp2=temp->left;
              temp2->right=temp->right;
              if(temp->right!=nullptr)temp->right->left=temp2;
              uni_task=temp->task;
              delete temp;
              l1--;
              break;
            }
            i++;
            temp=temp->right;
          }
      }
    } else {
      if(choice==1){
      cout<<"Second case"<<endl;
      temp=end1;
      i=l1;
      while(1){
        if(i==p){
          pending*temp2=temp->left;
          one_node->right=temp;
          one_node->left=temp->left;
          temp2->right=one_node;
          temp->left=one_node;
          clear();
          cout<<"Task : "<<task<<" is added"<<endl;
          break;
        }
        i--;
        temp=temp->left;
      }
    } else if(choice==2){
        pending*temp,*temp2;
        cout<<"Case 2"<<endl;
        temp=end1;
        i=l1;
        while(1){
          if(i==p){
            temp2=temp->left;
            temp2->right=temp->right;
            if(temp->right!=nullptr)temp->right->left=temp2;
            uni_task=temp->task;
            if(temp==end1){
              clear();
              cout<<"Marking the last task of the list as complete"<<endl;
              end1=temp2;
            }
            delete temp;
            l1--;
            break;
          }
          i--;
          temp=temp->left;
        }
    }
    }
  }
   if(choice==1)l1++;
  // if(choice==2){
  //   cout<<"Task : "<<uni_task<<" is marked as completed"<<endl;
  // }
}

void display(pending*&start1,pending*&end1){
  pending*temp=start1;
  if(temp==nullptr){
    cout<<"No pending tasks :)"<<endl<<endl;;
    return;
  }
  int i=1;
  cout<<"Pending tasks are : "<<endl;
  while(temp!=nullptr){
    cout<<i<<". "<<temp->task<<endl;
    temp=temp->right;
    i++;
  }
  cout<<endl<<"Number of pending tasks : "<<l1<<endl;
}
void display_completed(complete*&start2){
  complete*temp=start2;
  if(temp==nullptr){
    cout<<"No tasks are completed yet"<<endl;
    return;
  }
  int i=1;
  cout<<"Completed tasks are : "<<endl;
  while(temp!=nullptr){
    cout<<i<<". "<<temp->task<<endl;
    i++;
    temp=temp->right;
  }
}
int main(){
  int choice=1;
  complete*start2=nullptr,*end2=nullptr;
  pending*start1=nullptr,*end1=nullptr;
  
  while(choice!=0){
    cout<<"Enter your choice : \n1 : Add a task\n2 : Mark a task as complete\n3 : Show completed tasks\n0: Exit\nYour choice : ";
    cin>>choice;
    if(choice==1){
      int p=1;
      string task;
      cout<<"Enter new task : ";
      cin>>task;
      if(start1!=nullptr){
        cout<<"Enter priority number of the task you want to add : ";
        cin>>p;
      }
      pending_manager(task,start1,end1,p,1);
    } else if(choice==2){
      int p;
      cout<<"Enter task number which you want to mark as complete : ";
      cin>>p;
      clear();
      pending_manager("",start1,end1,p,2);
      if(!uni_task.empty()){
        cout<<"Task "<<uni_task<<" is marked as complete and removed from pending lists"<<endl;
        complete_manager(start2,end2);
      }
      // string marked=mark(start1,end1,p);
      // cout<<"The task which is marked as complete is : "<<marked<<endl;
    } else if(choice ==3){
      clear();
      display_completed(start2);
    }
    cout<<endl;
    display(start1,end1);
    cout<<"Number of completed tasks : "<<l2<<endl<<endl;
  }
}
