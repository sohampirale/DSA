#include<iostream>
using namespace std;
void print(int n){
    for(int i=1;i<=n/2;i++){
        for(int j=1;j<=i;j++)cout<<"*";
        for(int j=1;j<=n-(2*i);j++)cout<<" ";
        for(int j=1;j<=i;j++)cout<<"*";
        cout<<endl;
    }
    if(n%2){
        for(int i=1;i<=n;i++)cout<<"*";
        cout<<endl;
    }
    for(int i=1;i<=n/2;i++){
        for(int j=1;j<=(n/2)-i;j++)cout<<"*";
        if(n%2==0)for(int j=1;j<=2*i;j++)cout<<" ";
        else for(int j=1;j<=((i-1)*2)+1;j++)cout<<" ";
        for(int j=1;j<=(n/2)-i;j++)cout<<"*";
        cout<<endl;
    }
}
void print2(int n){
    for(int i=1;i<=n/2;i++){
        for(int j=1;j<=i;j++)cout<<"*";
        for(int j=1;j<=n/2-i;j++)cout<<" ";

        for(int j=1;j<=n/2-i;j++)cout<<" ";
        for(int j=1;j<=i;j++)cout<<"*";
        cout<<endl;
    }
    // if(n%2){
    //     for(int i=1;i<=n;i++)cout<<"*";
    //     cout<<endl;
    // }
    for(int i=1;i<=n/2;i++){
        for(int j=1;j<=(n/2)-i;j++)cout<<"*";
        for(int j=1;j<=i;j++)cout<<" ";
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    print2(n);
}

