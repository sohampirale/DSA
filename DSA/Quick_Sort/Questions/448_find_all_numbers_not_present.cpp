class Solution {
public:
    voic quick_sort(vector<int>&nums,int low,int high){
        if(low>=high)return;
        int st=low,end=high;
        int mid=st+(end-st)/2;
        int pivot=nums[mid];
        while(st<=end){
            while(nums[st]<pivot)st++;
            while(nums[end]>pivot)end--;
            if(st<=end){
                int temp=nums[end];
                nums[end]=nums[st];
                nums[st]=temp;
                st++;
                end--;
            }
        }

    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
    }
};