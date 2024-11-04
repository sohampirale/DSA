#include<iostream>
#include<vector>
using namespace std;
void factorial(int n,vector<int>&arr){
    for(int i=2;i<=n;i++){
        int carry=0;
        for(int j=0;j<arr.size()||carry!=0;j++){
            if(j<arr.size()){
                int temp=arr[j]*i+carry;
                arr[j]=temp%10;
                carry=temp/10;
            } else {
                arr.push_back(carry%10);
                carry/=10;
            }
        }
    }
}
int main(){
    int n;
    vector<int>arr(1,1);
    arr[0]=1;
    cout<<"Enter n : ";
    cin>>n;
    factorial(n,arr);
    cout<<"Answer : ";
    for(int i=arr.size()-1;i>=0;i--)cout<<arr[i];
    cout<<endl;
}