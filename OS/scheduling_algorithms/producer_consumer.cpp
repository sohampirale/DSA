#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n,data;
    cout<<"Enter size of the buffer : ";
    cin>>n;
    int choice=1;
    stack<int>buffer;
    while(choice!=0){
        cout<<"Enter your choice : \n1 : Produce data\n2 : Consume data\nYour choice : ";
        cin>>choice;
        if(choice==1){
            if(buffer.size()==n){
                cout<<"Buffer is full so cannot produce"<<endl;
                continue;
            }
            cout<<"Enter data : ";
            cin>>data;
            buffer.push(data);
        } else if(choice==2){
            if(buffer.size()==0){
                cout<<"Buffer is empty so cannot consume"<<endl;
                continue;
            }
            int data=buffer.top();
            cout<<"Data consumed by consumer is : "<<data<<endl;
            buffer.pop();
        }
    }
}


// Enter size of the buffer : 3
// Enter your choice : 
// 1 : Produce data
// 2 : Consume data
// Your choice : 1
// Enter data : 1
// Enter your choice : 
// 1 : Produce data
// 2 : Consume data
// Your choice : 1
// Enter data : 2
// Enter your choice : 
// 1 : Produce data
// 2 : Consume data
// Your choice : 1
// Enter data : 3
// Enter your choice : 
// 1 : Produce data
// 2 : Consume data
// Your choice : 1
// Buffer is full so cannot produce
// Enter your choice : 
// 1 : Produce data
// 2 : Consume data
// Your choice : 2
// Data consumed by consumer is : 3
// Enter your choice : 
// 1 : Produce data
// 2 : Consume data
// Your choice : 2
// Data consumed by consumer is : 2
// Enter your choice : 
// 1 : Produce data
// 2 : Consume data
// Your choice : 2
// Data consumed by consumer is : 1
// Enter your choice : 
// 1 : Produce data
// 2 : Consume data
// Your choice : 2
// Buffer is empty so cannot consume