#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>pq;
    int temp;
    for(int i=1;i<=6;i++){
        cin>>temp;
        pq.push(temp);
    }
    cout<<"Pq has elemnets as follows : ";
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

}

 
// Pq has elemnets as follows : 88 45 33 5 2 1 