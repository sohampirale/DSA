#include<iostream>
#include<vector>
using namespace std;
template<typename T>
void quick_sort_pivot_at_mid(vector<T>&nums,int low,int high){
    if(low>high)return;
    if(low==high){
        // cout<<"low = "<<low<<" & high = "<<high<<endl;
        return;
    }
    int st=low,end=high;
    int mid=st+(end-st)/2;
    T pivot=nums[mid];
    while(st<=end){
        while(nums[st]<pivot){
            st++;
        }
        while(nums[end]>pivot)
            end--;
        if(st<=end){
            T temp=nums[st];
            nums[st]=nums[end];
            nums[end]=temp;
            st++;
            end--;
        } 
    }
    quick_sort_pivot_at_mid(nums,low,end);
    quick_sort_pivot_at_mid(nums,st,high);
}
int main(){
    vector<int>nums={10,24,23,15,2,45,6};
    quick_sort_pivot_at_mid(nums,0,6);
    cout<<"Array after sorting becomes :";
    for(int i=0;i<7;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}