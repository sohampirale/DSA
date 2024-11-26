//Soham Sachin Pirale
//2022

#include<iostream>
#include<vector>
using namespace std;
void bubblesort(vector<int>&nums){
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

void display(vector<int>&nums){
    cout<<"Nums : ";
    for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    cout<<endl;
}

int main(){
    int n;
    cout<<"ENetr size of aray : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0;i<n;i++)cin>>nums[i];
    bubblesort(nums);
    display(nums);
}