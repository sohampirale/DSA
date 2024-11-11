#include<iostream>
#include<stack>
using namespace std;
class node{
    public:
        int data;
        node*next;
        node(int data):data(data),next(nullptr){}
    ~node(){
        cout<<"Deleting "<<this->data<<endl;
    }
        
};

void create_at_end(node*&end,int data){
    end->next=new node(data);
    end=end->next;
}

void display(node*&start){
    node*temp=start;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"nullptr"<<endl;
}

void reverse_K_nodes(int k,node*&start){
    node*back=nullptr,*temp=start;
    stack<node*>s;
    try{
    while(temp!=nullptr){
        cout<<"temp = "<<temp->data<<endl;
        for(int i=0;i<k;i++){
            if(!temp){
                cout<<"breaking"<<endl;
                break;
            }
            cout<<"Pushed "<<temp->data<<endl;
            s.push(temp);
            temp=temp->next;
        }
        if(!back){
            back=s.top();
            start=back;
            s.pop();
            cout<<"Back and start pointing at : "<<back->data<<endl;
        }
        while(!s.empty()){
            back->next=s.top();
            if(back->next)cout<<back->data<<"->"<<back->next->data<<"->";
            back=back->next;
            s.pop();
        }
        back->next=temp;
        if(!temp)cout<<"temp poitnign to nullptr"<<endl;
        if(back->next)cout<<back->data<<"->"<<back->next->data<<"->";
    }
    }catch (...){
        cout<<"Error"<<endl;
    }
}

void delete_all_nodes(node*&start){
    node*temp=start;
    while(start){
        temp=start->next;
        delete start;
        start=temp;
    }
}

int main(){
    int n;
    cout<<"How many nodes you ahve in a linked list : ";
    cin>>n;
    node*start=nullptr,*end=nullptr;
    for(int i=1;i<=n;i++){
        if(!start){
            start=new node(i);
            end=start;
        }
        else create_at_end(end,i);
    }
    int k;
    cout<<"Enter k : ";
    cin>>k;
    cout<<"Before : ";
    display(start);
    try{
        reverse_K_nodes(k,start);
    } catch(...){
        cout<<"Error occured"<<endl;
    }
    cout<<"Came out"<<endl;
    cout<<"After : ";
    display(start);
    delete_all_nodes(start);
}