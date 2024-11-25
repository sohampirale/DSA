#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class process{
    public:
        bool isImp;
        string pid;
        int bt,memory,priority=-1;
        process(int bt){
            this->bt=bt;
        }
};
struct compMinBT{
    bool operator()(const process& a, const process& b){
        return a.bt > b.bt;
    }
};

int main(){

    
    priority_queue<process,vector<process>, compMinBT>pq;
    process p1(2);
    process p2(1);
    process p3(4);
    process p4(11);

    pq.push(p1);
    pq.push(p2);
    pq.push(p3);
    pq.push(p4);

    while(!pq.empty()){
        cout<<pq.top().bt<<endl;
        pq.pop();
    }
    cout<<"Came out"<<endl;


    
}
