//returns new vector every time
#include<iostream>
#include<vector>
using namespace std;
int test=0,cnt=0;
vector<int> merge_sort(vector<int>ans,vector<int>&nums,int st,int end){
    if(ans.empty())cout<<"Ans vector is  always taken as empty"<<endl;
    if(st>=end){
        cout<<nums[st]<<" pushed at back"<<endl;
        ans.push_back(nums[st]);
        return ans;
    }
    int mid=st+(end-st)/2;
    vector<int>left_side=merge_sort(ans,nums,st,mid);
    vector<int>right_side=merge_sort(ans,nums,mid+1,end);
    cout<<"size of left side receievd answer is : "<<left_side.size()<<endl;
    cout<<"size of right side receievd answer is : "<<right_side.size()<<endl;
    cout<<endl;
    int i=0,j=0,k=0;
    if(left_side.empty())return right_side;
    else if(right_side.empty())return left_side;
    while(i<left_side.size()&&j<right_side.size()){
        if(left_side[i]<right_side[j]){
            if(ans.empty())cout<<"Everytime ans will be empty in new function in stack"<<endl;
            // ans.push_back(left_side[i++]);
        } else { 
            ans.push_back(right_side[j++]);
        }
    }
    if(i>=left_side.size()){
        while(j<right_side.size()){
            ans.push_back(right_side[j++]);
        }
    }  else {
        while(i<left_side.size()){
            ans.push_back(left_side[i++]);
        }
    }
    return ans;
}
int main(){
    int n,temp;
    cout<<"ENter size of array  : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>ans;
    cout<<"Original array : ";
    for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    cout<<endl;
    ans=merge_sort(ans,nums,0,n-1);
    cout<<"After coming out of the matrix the array becomes : ";
    for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    cout<<endl;
}

// ENter size of array  : 9
// Enter 9 numbers : 23 1 45 25 34 23 99 56 34
// Original array : 23 1 45 25 34 23 99 56 34 
// After coming out of the matrix the array becomes : 1 23 23 25 34 34 45 56 99 

// ENter size of array  : 8
// Enter 8 numbers : 23 14 68 23 12 56 1 9
// Original array : 23 14 68 23 12 56 1 9 
// After coming out of the matrix the array becomes : 1 9 12 14 23 23 56 68 



