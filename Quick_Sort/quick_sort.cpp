#include<iostream>
#include<vector>
using namespace std;//idbsidbsihbd
void quick_sort(vector<int>&nums,int low,int high){
    if(low>high)return;
    if(low==high){
        cout<<"low = "<<low<<" & high = "<<high<<endl;
        return;
    }
    int st=low,end=high;
    // int pivot=nums[low];
    while(st<end){
        int pivot=nums[st];
        while(nums[st]<pivot){
            st++;
            cout<<"This will never be in action"<<endl;
        }
        
        while(nums[end]>pivot)
            end--;

        if(st<end){
            int temp=nums[st];
            nums[st]=nums[end];
            nums[end]=temp;
        }
        st++;
        end--;
        cout<<"Array modified to : ";
        for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
        cout<<endl;
    }
    cout<<"Came out at st = "<<st<<" & end = "<<end<<endl;
    quick_sort(nums,low,end);
    quick_sort(nums,st,high);
}
int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0;i<n;i++)cin>>nums[i];
    quick_sort(nums,0,n-1);
    cout<<"After callignt he quick sort fucntion the original array becomes : ";
    for(int i=0;i<n;i++)cout<<nums[i]<<" ";
}
