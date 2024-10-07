class Solution {
public:

    int find_peak(vector<int>&nums){
        int  st=0,end=nums.size()-1,mid;
        while(st<end){
            mid=st+(end-st)/2;
            if(nums[mid]>nums[mid+1]){
                return mid!=nums.size()-1?nums[mid+1] : 0;
            }
            if(nums[mid]<nums[st])end=mid-1;
            else st=mid+1;
        }
        cout<<"St = "<<st<<endl;
        return st!=nums.size()-1?nums[st+1] : nums[0];
    }
    int findMin(vector<int>& nums) {
        return find_peak(nums);
    }
};