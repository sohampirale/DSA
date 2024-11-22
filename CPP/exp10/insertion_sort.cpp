#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>&nums){
    for(int i=1;i<nums.size();i++){
        int key=nums[i];
       int j=i-1;
       while(nums[j]>key&&j>=0){
            nums[j+1]=nums[j];
            j--;
       }
       nums[j+1]=key;
    }
}

int main(){
    int n;
    cout<<"Enter size of the array : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0;i<n;i++)cin>>nums[i];
    insertionSort(nums);
    cout<<"AFter sorting : ";
    for(int i=0;i<n;i++)cout<<nums[i]<<" ";
    cout<<endl;
}