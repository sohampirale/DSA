#include<iostream>
#include<vector>
using namespace std;
void merge_sort(vector<int>&nums,int st,int mid,int end){
    if(st==end)return;
    mid=st+(end-st)/2;
    cout<<"st = "<<st;
    cout<<" end = "<<end<<" mid = "<<mid<<endl;
    if(st==end)return;
    merge_sort(nums,st,mid,mid);
    merge_sort(nums,mid+1,mid,end);
    int i=st,j=mid+1,k=st;
    while(i<=mid&&j<=end){
        if(nums[i]<nums[j]){
            cout<<"at k = "<<k<<" put : "<<nums[i]<<endl;
            nums[k++]=nums[i++];
            cout<<k<<endl<<i<<endl;
        } else {
            cout<<" att : k = "<<k<<" put : "<<nums[j]<<endl;
            nums[k++]=nums[j++];
        }
    }/*
    cout<<"after first try array becomes : ";
    for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    cout<<endl;
*/
    if(i>mid){
        while(j<=end){
            nums[k++]=nums[j++];
        }
    } else {
        while(i<=mid){
            nums[k++]=nums[i++];
        }
    }/*
    cout<<"after this arrangement array becomes : ";
    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
    cout<<endl;*/
}
int main(){
    int n,temp;
    cout<<"ENter size of array  : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    merge_sort(nums,0,(n-1)/2,n-1);
    cout<<"After coming out of the matrix the array becomes : ";
    for(int i=0;i<n;i++)cout<<nums[i]<<" ";
    cout<<endl;
}