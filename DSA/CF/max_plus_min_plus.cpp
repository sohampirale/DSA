#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int ans_size=0;
vector<int> getIndex(vector<int>&nums,int comp){
    vector<int>index;
   for(int i=0;i<nums.size();i++){
        if(nums[i]==comp)index.push_back(i);
   }
   return index;
}
int remove_unwanted(vector<int>&index){
    if(index.size()==1)return 1;
    for(int i=0;i<index.size()-1;i++){
        if(index[i]+1==index[i+1]){
            index.erase(index.begin()+i+1);
        }
    }
    return index.size();
}
void remove_from_nums(vector<int>&nums,int comp){
    // cout<<"Before erasing the nums  : ";
    // for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    // cout<<endl;
    int size=nums.size();
    for(int i=0;i<nums.size();i++){
        if(nums[i]==comp){
            nums.erase(nums.begin()+i);
            i--;
        }
        size=nums.size();
    }
    // cout<<"After erasing the nums becomes : ";
    // for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    // cout<<endl;
}
int main() {
    int t,n,temp;
    cin>>t;
    vector<int>nums;
    vector<int>ans;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>temp;
            nums.push_back(temp);
        }
        int j=0;
        while(!nums.empty()){
            int comp=nums[i];
            vector<int>index=getIndex(nums,comp);    
            remove_from_nums(nums,comp);
            int cnt=remove_unwanted(index);
            if(cnt==1){

                // cout<<"Only 1 : "<<comp<<"present"<<endl;
            } else {
                for(int k=0;k<cnt;k++)ans.push_back(comp);
            }
            // cout<<"Answer vector becomes : ";
            // for(int k=0;k<ans.size();k++)cout<<ans[k]<<" ";
            // cout<<endl;
        }
        int mx=*max_element(ans.begin(),ans.end());
        int min=*min_element(ans.begin(),ans.end());
        int final_ans=ans.size()+mx+min;
        cout<<final_ans<<endl;
        nums.clear();
        ans.clear();
    }
    return 0;
}


// 1
// 3
// 5 4 5
// 12


// 1
// 3
// 4 5 4
// 10

// 1
// 10
// 3 3 3 3 4 1 2 3 5 4
// 12

// 1
// 10
// 17 89 92 42 29 41 92 14 70 45
// 186