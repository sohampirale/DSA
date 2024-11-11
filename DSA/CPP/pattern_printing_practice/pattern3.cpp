#include<iostream>
using namespace std;
void print(int n){
    int k=n/2;
    for(int i=0;i<k;i++){
        for(int j=0;j<=i;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
    if(n%2){
        for(int i=0;i<k+1;i++)cout<<i+1<<" ";
        cout<<endl;
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<k-i;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    print(n);
}

// Enter n: 9
// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4 
// 1 2 3 4 5 
// 1 2 3 4 
// 1 2 3 
// 1 2 
// 1 