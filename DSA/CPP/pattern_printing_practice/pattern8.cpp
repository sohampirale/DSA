#include<iostream>
using namespace std;
void print(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++)cout<<" ";
        for(int j=0;j<=i;j++)cout<<"* ";
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    print(n);
}

