class Solution {
public:
    bool find(vector<int>&nums,int find){
        int st=0,end=nums.size()-1,mid;
        while(st<=end){
            mid=st+(end-st)/2;
            if(nums[mid]==find)return true;
            else if(nums[mid]<find)st=mid+1;
            else end=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& nums, int findd) {
     int i=0,j=0;
     while(i<nums.size()){
        if(find(nums[i],findd)) return true;
        i++;
     }
     return false;   
    }
};