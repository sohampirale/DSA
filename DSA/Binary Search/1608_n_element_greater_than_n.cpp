#include<iostream>
#include<vector>
using namespace std;
int find(vector<int>&nums){
    int st=0,end=nums.size()-1,mid,cnt;
    while(st<=end){
        mid=st+(end-st)/2;
        cnt=0;
        int n=nums[mid];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=n)cnt++;
        }
        if(cnt==n){
            return n;
        }
        if(cnt<=(nums.size()/2))st=mid+1;
        else end=mid-1;
    }
    return -1;
}
int main(){
    int n;
    cout<<"ENter size of array 1 : ";
    cin>>n;
    cout<<"ENter "<<n<<" numbers of array 1 : ";
    vector<int>nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans=find(nums);
    cout<<"Answer received is : "<<ans<<endl;

    
}