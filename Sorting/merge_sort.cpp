#include<iostream>
#include<vector>
using namespace std;
vector<int> mergeSort(vector<int>&nums,int st,int end){
    if(st==end){
        vector<int>temp;
        temp.push_back(nums[st]);
        return temp;
    }
    int mid=st+(end-st)/2;
    vector<int>left=mergeSort(nums,st,mid);
    vector<int>right=mergeSort(nums,mid+1,end);
    vector<int>ans(left.size()+right.size());
    int i=0,j=0,k=0;
    while(i<left.size()&&j<right.size()){
        if(left[i]<right[j]){
            ans[k]=left[i];
            i++;
        } else {
            ans[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<left.size()){
        ans[k]=left[i];
        i++;
        k++;
    }
    while(j<right.size()){
        ans[k]=right[j];
        j++;
        k++;
    }
    return ans;
}

void mergeSort2(vector<int>&nums,int st,int end){
    if(st==end)return;
    int mid=st+(end-st)/2;
    mergeSort2(nums,st,mid);
    mergeSort2(nums,mid+1,end);
    vector<int>temp(mid-st+1);
    int i=0,j=st,k=0;
    for(i=0;i<temp.size();i++){
        temp[i]=nums[j];
        j++;
    }
    i=0,j=0;
    while(i<temp.size()&&j<=end){
        if(temp[i]<nums[j]){
            nums[k]=temp[i];
            i++;
        } else {
            int tempp=nums[j];
            nums[j]=temp[i];
            nums[k]=tempp;
        }
    }
    while(i<temp.size()){
        nums[k]=temp[i];
        i++;
        k++:
    } 
    while(j<end)
}
int main(){
    int n;
    cout<<"How many numbers you have : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0;i<n;i++)cin>>nums[i];
    vector<int>sortedArray=mergeSort(nums,0,n-1);
    cout<<"Original array : ";
    for(int i=0;i<n;i++)cout<<nums[i]<<" ";
    cout<<endl<<"Sorted array : ";
    for(int i=0;i<sortedArray.size();i++)cout<<sortedArray[i]<<" ";
    cout<<endl;
}