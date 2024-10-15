#include<iostream>
#include<vector>
using namespace std;//hjh
vector<int> merge_sort(vector<int>&nums,int st,int end){
    if(st==end){
        vector<int>temp(1,nums[st]);
        return temp;
    }
    int mid=st+(end-st)/2;
    vector<int>left=merge_sort(nums,st,mid);
    vector<int>right=merge_sort(nums,mid+1,end);
    vector<int>temp;
    int i=0,j=0;
    while(i<left.size()&&j<right.size()){
        if(left[i]<right[j]){
            temp.push_back(left[i]);
            i++;
        } else {
            temp.push_back(right[j]);
            j++;
        }
    }
    if(i==left.size()){
        temp.insert(temp.end(),right.begin()+j,right.end());
    } else if(j==right.size()){
        temp.insert(temp.end(),left.begin()+i,left.end());
    }
    // while(i==left.size()&&j<right.size()){
    //     temp.push_back(right[j]);
    //     j++;
    // }
    // while(j==right.size()&&i<left.size()){
    //     temp.push_back(left[i]);
    //     i++;
    // }
    cout<<"Retunring : ";
    for(int k=0;k<temp.size();k++)cout<<temp[k]<<" ";
    cout<<endl;
    return temp;
}
int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0;i<n;i++)cin>>nums[i];
    vector<int>ans=merge_sort(nums,0,nums.size()-1);
    cout<<"Received sorted array is : " ;
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}
