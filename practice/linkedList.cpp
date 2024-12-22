#include<iostream>
#include<stack>
using namespace std;

class node{
    public:
        int data;
        static int n;
        node* next;
        node(int data):data(data),next(nullptr){
            n++;
        }
        ~node(){
            cout<<"Deleting "<<data<<endl;
        }
};

int node::n=0;
void add(int data,node*&start,node*&end){
    if(!start){
        start=new node(data);
        end=start;
        return;
    } else {
        end->next=new node(data);
        end=end->next;
        return;
    }
}

void evenNodesAtEnd(node*&start,node*&end,stack<node*>nodes){
    if(start->next==end||start==end){
        while(!nodes.empty()){
            end->next=nodes.top();
            nodes.pop();
            end=end->next;
        }
        end->next=nullptr;
        return;
    }
    nodes.push(start->next);
    start->next=start->next->next;
    evenNodesAtEnd(start->next,end,nodes);
}

void display(node*start){
    cout<<"Linked list is : ";
    while(start){
        cout<<start->data<<" ";
        start=start->next;;
    }
}

void deleteAllNodes(node*start){
    if(!start)return;
    deleteAllNodes(start->next);
    delete start;
}
bool flag=false;
bool isPalindrome(node*& front,node* back){
    if(!back)return true;
    isPalindrome(front,back->next);
    if(flag)return false;
    if(front->data!=back->data){
        flag=true;
        return false;
    }
    front=front->next;
    return true;
}

int findNmodKas0(node*temp,int k,int n=1){
    if(!temp)return 0;
    int ans=0;
    ans+=findNmodKas0(temp->next,k,n+1);
    if(flag)return ans;
    if(n%k==0){
        flag=true;
        return temp->data;
    }
    return 0;
}

int main(){
    int choice=1,data;
    node*start=nullptr,*end=nullptr;
    while(choice){
        cout<<"Enter your chocie :\n1 : Add at end\n0 : exit\nYour chocie : ";
        cin>>choice;
        if(choice==1){
            cout<<"Enter data : ";
            cin>>data;
            add(data,start,end);
        } 
    }
    choice=1;
    while(choice){
        cout<<"Enter your choice :\n1 : Even no of nodes at end"<<endl;
        cout<<"2 : Display linked list"<<endl;
        cout<<"3 : Check if palindrome"<<endl;
        cout<<"Find the node for which n%k==0 from behind"<<endl;
        cout<<"Your chocie : ";
        cin>>choice;
        if(choice==1){
            stack<node*>nodes;
            evenNodesAtEnd(start,end,nodes);
        } else if(choice==2){
            display(start);
        } else if(choice==3){
            bool palindrome=isPalindrome(start,start);
            if(palindrome){
                cout << "Given linked list is a palindrome" << endl;
            } else {
                cout << "Given linked list is not a palindrome" << endl;
            }
            flag=false;
        } else if(choice==4){
            int k;
            cout<<"enter k : ";
            cin>>k;
            // cout<<"ENter total no of nodes : "<<endl;
            // cin>>n;
            cout<<"n = "<<node::n<<endl;
            int n=node::n;
            int ans=findNmodKas0(start,k,n);
            cout<<"Ans = "<<ans<<endl;
            flag=false;
        }
    }
    deleteAllNodes(start);
    return 0;
}