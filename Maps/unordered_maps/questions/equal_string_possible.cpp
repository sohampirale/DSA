#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<string>&strings){
    int size=strings.size();
    unordered_map<char,int>map;
    for(int i=0;i<size;i++){
        for(char ch:strings[i]){
            map[ch]++;
        }
    }
    for(auto it=map.begin();it!=map.end();it++){
        if(it->second%size!=0)return false;
    }
    return true;
}

void displayMap(unordered_map<char,char>&map){
    for(auto it=map.begin();it!=map.end();it++){
        cout<<it->first<<" : "<<it->second<<endl;
    }
}

bool isAnagram(string str1,string str2){
   unordered_map<char,int>map;
    for(char ch:str1){
        map[ch]++;
    }

    for(char ch:str2){
        map[ch]--;
    }

    for(auto it=map.begin();it!=map.end();it++){
        if(it->second%2!=0)return false;
    }
    return true;
}

bool isIsomorphic(string str1,string str2){
    unordered_map<char,char>map1;
    unordered_map<char,char>map2;
    if(str1.length()!=str2.length())return false;
    for(int i=0;i<str1.length();i++){
        auto it=map1.find(str1[i]);
        if(it==map1.end()){
            map1[str1[i]]=str2[i];
        } else {
            if(it->second!=str2[i])return false;
        }
        it=map2.find(str2[i]);
        if(it==map2.end()){
            map2[str2[i]]=str1[i];
        } else {
            if(it->second!=str1[i])return false;
        }
    }
    return true;
}

pair<int,int> pairSum1(vector<int>&nums,int target){
    unordered_map<int,int>map;
    for(int num : nums){
        int i=0;
        for(auto it : map){
            if(it.second+num==target){
                pair<int,int>temp={it.second,num};
                return temp;
            }
        }
        map[num]=num;
    }
    pair<int,int>temp={-1,-1};
    return temp;
}


pair<int,int> pairSum2(vector<int>&nums,int target){
    unordered_map<int,int>map;
    for(int i=0;i<nums.size();i++){
        auto it=map.find(target-nums[i]);
        if(it!=map.end()){
            cout<<"Found at indexes : ";
            // pair<int,int>temp={it->second,i};
            // return temp;
            return {it->second,i};
        } else {
            map[nums[i]]=i;
        }
    }
    pair<int,int>temp={-1,-1};
    return temp;
}

int longestSubarray2(vector<int>&nums){
    int maxx=-1;
    unordered_map<int,vector<int>>map;
    vector<int>temp;
    temp.push_back(nums[0]);
    map[0]=temp;
    for(int i=1;i<nums.size();i++){
        vector<int>comp=map[i-1];
        int toadd=nums[i];
        vector<int>curr;
        for(int j=0;j<comp.size();j++){
            if(comp[j]+toadd==0&&j+2>maxx){
                cout<<"Found at "<<nums[i]<<endl;
                cout<<"j+2 = "<<j+2<<endl;
                maxx=j+2;
            }
            curr.push_back(comp[j]+toadd);
        }
        curr.push_back(toadd);
        map[i]=curr;
    }
    return maxx;
}


int longestSubarray1(vector<int>&nums){
    int maxx=-1;
    unordered_map<int,int>map;
    map[nums[0]]=0;
    for(int i=1;i<nums.size();i++){
        int sum=nums[i]+nums[i-1];
        auto it=map.find(sum);
        if(it!=map.end()){
            int temp=i-it->second;
            if(temp>maxx)maxx=temp;
        } else {
            map[sum]=i;
        }
        nums[i]=sum;
    }
    return maxx;
}

int longestSubarray3(vector<int>&nums){
    cout<<"hi"<<endl;
    int maxx=-1;
    unordered_map<int,int>map;
    // map[nums[0]]=0;
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        // cout<<"SUm for "<<nums[i]<<" = "<<sum<<endl;
        if(sum==0){
            maxx=i+1;
            cout<<"Found 0 in prefixSum max updated to = "<<maxx<<endl;
        }
        auto it=map.find(sum);
        if(it==map.end()){
            map[sum]=i;
        } else {
            // cout<<"Found "<<endl;
            int temp=i-it->second;
            if(temp>maxx){
                maxx=i-it->second;
                // cout<<"max updated to "<<maxx<<endl;
            }
        }
    }
    return maxx;
}

int main(){

    // unordered_map<char,int>map;
    // int n;
    // cout<<"How many strings you have : ";
    // cin>>n;
    // vector<string>strings(n);    
    // cout<<"Enter "<<n<<" strings : ";
    // for(int i=0;i<n;i++)cin>>strings[i];
    // bool ans=isPossible(strings);
    // if(ans)cout<<"Possible"<<endl;
    // else cout<<"Not possible"<<endl;

    // string str1,str2;
    // cout<<"Enter string1 : ";
    // cin>>str1;
    // cout<<"Enter string2 : ";
    // cin>>str2;
    // cout<<(isAnagram(str1,str2)?"Anagram" : "Not anagram")<<endl;
    
    // string str1,str2;
    // cout<<"Enter string1 : ";
    // cin>>str1;
    // cout<<"Enter string2 : ";
    // cin>>str2;
    // cout<<(isIsomorphic(str1,str2)?"Isomorphic" : "Not Isomorphic")<<endl;

    // int n,target;
    // cout<<"How mnay numbers are in the array : ";
    // cin>>n;
    // vector<int>nums(n);
    // cout<<"Enter "<<n<<" numbers : ";
    // for(int i=0;i<n;i++)cin>>nums[i];
    // cout<<"Enter target : ";
    // cin>>target;
    // pair<int,int>ans=pairSum2(nums,target);
    // cout<<ans.first<<" "<<ans.second<<endl;

    int n;
    cout<<"How mnay numbers are in the array : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0;i<n;i++)cin>>nums[i];
    int ans=longestSubarray3(nums);
    cout<<"Ans = "<<ans<<endl;
}