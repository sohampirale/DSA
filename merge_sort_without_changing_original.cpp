#include<iostream>
#include<vector>
using namespace std;
void merge_sort(vector<int>&nums,int st,int end){
    if(st==end)return;
    int mid=st+(end-st)/2;
    int t=mid+1;
    merge_sort(nums,st,mid);
    merge_sort(nums,mid+1,end);
    for(int i=t;i<=end;i++){
        // cout<<"i = "<<i<<endl;
        if(nums[i]<nums[i-1]){
            // cout<<"We need to shift : "<<nums[i]<<endl;
            int temp=nums[i];
            int j=i-1;
            while(j>=0&&nums[j]>temp){
                // cout<<"Shifting : "<<nums[j]<<endl;
                nums[j+1]=nums[j--];
            }
            // cout<<"PUtting "<<temp<<" at pos : "<<j+1<<endl;
            nums[j+1]=temp;
        }
    }
    // cout<<"Nums (st="<<st<<" & end = "<<end<<" & t = "<<t<<"): ";
    // for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    // cout<<endl;
}
int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0;i<n;i++)cin>>nums[i];
    merge_sort(nums,0,nums.size()-1);
    cout<<"After calling funciton nums become : ";
    for(int i=0;i<n;i++)cout<<nums[i]<<" ";
    cout<<endl;
}