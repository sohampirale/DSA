#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int>&nums){
    for(int i=0;i<nums.size()-1;i++){
        for(int j=0;j<nums.size()-1;j++){
            if(nums[j]>nums[j+1]){
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
}
int main(){
    int n;
    cout<<"Enter how many numbers you have : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0;i<n;i++)cin>>nums[i];
    bubbleSort(nums);
    cout<<"After sorting the array becomes : ";
    for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
}