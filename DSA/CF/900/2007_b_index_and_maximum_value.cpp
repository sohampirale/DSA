#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(vector<long long>&nums,long long l,long long r,bool add){
    for(int i=0;i<nums.size();i++){
        if(nums[i]>=l&&nums[i]<=r){
            if(add)nums[i]++;
            else nums[i]--;
        }
    }
    int mx=*max_element(nums.begin(),nums.end());
    // cout<<"Nums modified to : ";
    // for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    // cout<<endl;
    return mx;
}
int main(){
    int tt;
    cin>>tt;
    for(int t=0;t<tt;t++){
        int n,m;
        cin>>n>>m;
        vector<long long>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        cin.ignore();
        vector<string>instructions;
        string line;
        vector<char>signs(m);
        vector<long long>n1(m);
        vector<long long>n2(m);
        for(int i=0;i<m;i++){
            cin>>signs[i]>>n1[i]>>n2[i];
        }
        for(int i=0;i<m;i++){
            cout<<solve(nums,n1[i],n2[i],signs[i]=='+' ? true : false)<<" ";
        }
        cout<<endl;
    }

}