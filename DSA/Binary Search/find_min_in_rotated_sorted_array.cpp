#include<iostream>
#include<vector>
using namespace std;
int find_peak(vector<int>&nums){
    int st=0,end=nums.size()-1,mid;
    while(st<end){
        mid=st+(end-st)/2;
        if(nums[mid]>nums[mid+1]){
            return mid;
        } else if(nums[mid]>nums[st]){
            st=mid+1;
        } else {
            end=mid-1;
        }
    }
    return st;
}
int findd(vector<int>&nums,int st,int end,int find){
    int mid;
    while(st<=end){
        mid=st+(end-st)/2;
        cout<<"Mid = "<<mid<<endl;
        if(nums[mid]==find){
            return mid;
        } else if(nums[mid]>find)end=mid-1;
        else st=mid+1;
    }
    return -1;
}
int main(){
    int n1,n2;
    cout<<"ENter size of array 1 : ";
    cin>>n1;
    cout<<"ENter "<<n1<<" numbers of array 1 : ";
    int temp;
    vector<int>nums1(n1,0);
    for(int i=0;i<n1;i++){
        cin>>nums1[i];
    }
    int find;
    cout<<"Enter th enumber you want to find : ";
    cin>>find;
    int peak=find_peak(nums1),ans;
    cout<<"PEak found at index : "<<peak<<endl;
    if(nums1[0]<=find){
        ans=findd(nums1,0,peak,find);
    } else {
        ans=findd(nums1,peak+1,nums1.size()-1,find);
    }
    cout<<"Answer received is : "<<ans<<endl;
    return ans;
}