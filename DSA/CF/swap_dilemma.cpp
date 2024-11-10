#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int find(vector<int>&nums,int comp){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==comp)return i;
    }
    return -1;
}
bool check(vector<int>&nums1,vector<int>&nums2){
    if(nums1.empty())return false;
    for(int i=0;i<nums1.size();i++){
        if(nums1[i]!=nums2[i]){
            // cout<<"No"<<endl;
            return false;
        }
    }
    // cout<<"Yes"<<endl;
    return true;
}
int main() {
    int t,n,flag=1;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        vector<int>nums1(n);
        vector<int>nums2(n);
        for(int j=0;j<n;j++){
            cin>>nums1[j];
        }
        for(int j=0;j<n;j++){
            cin>>nums2[j];
        }
        if(check(nums1,nums2)){
            cout<<"Yes nums1==nums2 already"<<endl;
            continue;
        }
        for(int j=0;j<1;j++){
            if(nums1[j]==nums2[j]){
                // cout<<"Erasing "<<nums1[j]<<endl;
                j--;
                nums1.erase(nums1.begin());
                nums2.erase(nums2.begin());
                continue;
            }
            int pos=find(nums2,nums1[j]);
            if(pos==-1){
                flag=0;
                break;
            }
            int temp=nums1[j];
            nums1[j]=nums1[pos];
            nums1[pos]=temp;
            // cout<<"Interchanged "<<temp<<" & "<<nums1[j]<<endl;
        }
        if(!flag){
            // cout<<"no not present in nums2"<<endl;
            cout<<"No"<<endl;
            continue;
        }
        for(int j=0;j<1;j++){
            if(nums1.empty()){
                // cout<<"No"<<endl;
                break;
            }
            if(nums1[j]==nums2[j]){
                // cout<<"Deleting "<<nums1[j]<<endl;
                j--;
                nums1.erase(nums1.begin());
                nums2.erase(nums2.begin());
                continue;
            }
            int pos=find(nums1,nums2[j]);
            if(pos==-1){
                flag=0;
                break;
            }
            int temp=nums2[j];
            nums2[j]=nums2[pos];
            nums2[pos]=temp;
            // cout<<"Interchanged "<<temp<<" & "<<nums1[j]<<endl;
        }
        bool equal=check(nums1,nums2);
        if(equal)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

// 1
// 4
// 1 2 3 4
// 1 2 3 4
// Yes nums1==nums2 already

// 1
// 5
// 1 3 4 2 5
// 7 1 2 5 4
// No

// 1
// 4
// 1 2 3 4
// 4 3 2 1
// Yes

// 1
// 3
// 1 2 3
// 1 3 2
// No

// 1
// 5
// 1 5 7  1000 4
// 4 1 7  5 1000
// No

// 1
// 3
// 1 4 2   
// 1 3 2
// No