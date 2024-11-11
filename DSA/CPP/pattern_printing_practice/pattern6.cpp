#include<iostream>
using namespace std;
void print(int n){
    for(int i=0;i<n/2;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    // if(n%2){
    //     for(int j=0;j<(n/2)+1;j++)cout<<"*";
    //     cout<<endl;
    // }

    for(int i=0;i<=n/2;i++){
        for(int j=0;j<=(n/2)-i;j++)cout<<"*";
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    print(n);
}

// Enter n: 5
// * * * * * 
// * * * * 
// * * * 
// * * 
// * 