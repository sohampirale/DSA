#include<iostream>
using namespace std;
void print(int n){
    int k=n/2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++)cout<<" ";
        for(int j=0;j<=i;j++)cout<<"* ";
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++)cout<<" ";
        for(int j=0;j<=n-1-i;j++)cout<<"* ";
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
//     * 
//    * * 
//   * * * 
//  * * * * 
// * * * * * 
// * * * * * 
//  * * * * 
//   * * * 
//    * * 
//     * 