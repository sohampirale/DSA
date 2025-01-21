#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<unsigned long long,unsigned long long>fiboMap={{0,0},{1,1},{2,1}};
unsigned long long cnt=0;

unsigned long long fibo(unsigned long long n){
    if(n<=2)return 1;
    if(fiboMap.find(n)==fiboMap.end()){
        cnt++;
        cout<<"Calculation no - "<<cnt<<endl;
        fiboMap[n]=fibo(n-1)+fibo(n-2);
    } 
    return fiboMap[n];
}

unsigned long long normalFibo(unsigned long long n){
    cnt++;
    cout<<"making calculation no "<<cnt<<endl;
    if(n==1||n==2)return 1;
    else return normalFibo(n-1)+normalFibo(n-2);
}

int main(){
    int choice=1;
    unsigned long long num=1;
    while(choice){
        cout<<"1 : Use normal Fibo"<<endl;
        cout<<"2 : use fibo using unordered map"<<endl;
        cout<<"3 : Clear the unordered map"<<endl;
        cout<<"Your choice : ";
        cin>>choice;
        if(choice==1){
            cout<<"Enter number to check its fibinachi number : ";
            cin>>num;
            unsigned long long ans=normalFibo(num);
            cout<<"Finonachi number of "<<num<<" is : "<<ans<<endl;
        } else if(choice==2){
            cout<<"Enter number to check its fibinachi number : ";
            cin>>num;
            unsigned long long ans=fibo(num);
            cout<<"Finonachi number of "<<num<<" is : "<<ans<<endl;
        } else if(choice==3){
            fiboMap.clear();
            cout<<"Unordered map cleared"<<endl;
        }
       
    }
    
}