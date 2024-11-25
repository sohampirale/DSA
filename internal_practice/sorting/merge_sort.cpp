#include<iostream>
#include<vector>
using namespace std;
vector<int>mergeSort(int st,int end,vector<int>&nums){
    if(st==end){
        return {nums[st]};
    }
    int mid=st+(end-st)/2;
    vector<int>left=mergeSort(st,mid,nums);
    vector<int>right=mergeSort(mid+1,end,nums);
    int i=0,j=0;
    vector<int>ret;
    while(i<left.size()&&j<right.size()){
        if(left[i]<=right[j]){
            ret.push_back(left[i]);
            i++;
        } else {
            ret.push_back(right[j]);
            j++;
        }
    }
    while(i<left.size())ret.push_back(left[i++]);
    while(j<right.size())ret.push_back(right[j++]);
    return ret;
}

void merge_sort2(int*num,int st,int end,int size){
    if(st>=end)return;
    int mid=st+(end-st)/2;
    merge_sort2(num,st,mid,size);
    merge_sort2(num,mid+1,end,size);
    int leftsize=mid-st+1,rightsize=end-mid;
    int left[leftsize],right[rightsize];
    for(int i=0;i<leftsize;i++){
        left[i]=num[st+i];
    }
    for(int i=0;i<rightsize;i++){
        right[i]=num[mid+1+i];
    }
    int i=0,j=0,k=st;
    while(i<leftsize&&j<rightsize){
        if(left[i]<=right[j]){
            num[k]=left[i];
            k++;
            i++;
        } else {
            num[k]=right[j];
            k++;
            j++;
        }
    }
    while(i<leftsize){
        num[k]=left[i];
        k++;
        i++;
    }
    while(j<rightsize){
        num[k]=right[j];
        j++;
        k++;
    }
}

int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int num[n];
    // vector<int>num(n);
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0;i<n;i++)cin>>num[i];
    // vector<int>ans=mergeSort(0,n-1,num);
    // cout<<"Received answer is : ";
    // for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    // cout<<endl;

     merge_sort2(num,0,n-1,n);
    cout<<"Received answer is : ";
    for(int i=0;i<n;i++)cout<<num[i]<<" ";
    cout<<endl;
}