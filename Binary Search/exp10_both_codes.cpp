#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int>&nums,int target){
    int st=0,end=nums.size()-1;
    int mid=st+(end-st)/2;
    while(st<=end){
        mid=st+(end-st)/2;
        if(nums[mid]==target)return mid;
        else if(nums[mid]<target){
            st=mid+1;
        } else {
            end=mid-1;
        }
    }
    return -1;
}
int linearSearch(vector<int>&nums,int target){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target)return i;
    }
    return -1;
}
int main(){
    int n;
    cout<<"ENter size of the array : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0;i<n;i++)cin>>nums[i];
    int choice;
    cout<<"1 : Bionary search\n2 : Linear search\nYour choice : ";
    cin>>choice;
    int target;
    cout<<"Enter target : ";
    cin>>target;
    if(choice==1){
        int ans=binarySearch(nums,target);
        if(ans!=-1){
            cout<<target<<" is present at index : "<<ans<<endl;
        } else cout<<target<<" not found"<<endl;
    } else if(choice==2){
        int ans=linearSearch(nums,target);
        if(ans!=-1){
            cout<<target<<" is present at index : "<<ans<<endl;
        } else cout<<target<<" not found"<<endl;
    }
}