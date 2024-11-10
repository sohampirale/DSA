#include<iostream>
#include<vector>
using namespace std;
int test=0,cnt=0;
void merge(vector<int>&nums,int j,int st,int mid,int end){
     cout<<endl<<"Before  : ";
    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    int i=st,k=mid+1;
    while(i<=mid&&k<=end){
        if(nums[i]<nums[k]){
            nums[j++]=nums[i++];
        } else {
            nums[j++]=nums[k++];
        }
    }
    while(i<=mid){
        nums[j++]=nums[i++];
    }
    while(k<=end){
        nums[j++]=nums[k++];
    }
    cout<<"After : ";
    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
    cout<<endl<<endl;
}
void merge_sort(vector<int>ans,vector<int>&nums,int st,int end,int j=0){
   if(st==end){
    nums[j]=nums[st];
    // ans.push_back(nums[st]);
    return;
   }
   int mid=st+(end-st)/2;
    merge_sort(ans,nums,st,mid,j);
    merge_sort(ans,nums,mid+1,end,mid+1);
   merge(nums,j,st,mid,end);
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
    vector<int>ans;
    cout<<"Original array : ";
    for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    cout<<endl;
    merge_sort(ans,nums,0,n-1);
    cout<<"After coming out of the matrix the array becomes : ";
    for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    cout<<endl;
}

// ENter size of array  : 9
// Enter 9 numbers : 23 1 45 25 34 23 99 56 34
// Original array : 23 1 45 25 34 23 99 56 34 
// After coming out of the matrix the array becomes : 1 23 23 25 34 34 45 56 99 

// ENter size of array  : 8
// Enter 8 numbers : 23 14 68 23 12 56 1 9
// Original array : 23 14 68 23 12 56 1 9 
// After coming out of the matrix the array becomes : 1 9 12 14 23 23 56 68 