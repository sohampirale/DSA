class Solution {
public:
    int find_peak_hori(vector<int>&nums){
        int st=0,end=nums.size()-1,mid;
        whiel(st<=end){
            mid=st+(end-st)/2;
            if(mid!=nums.size()&&nums[mid]>nums[mid+1]){
                return mid;
            } else if(nums[mid]>nums[st]){
                st=mid+1;
            } else {
                end=mid-1;
            }
        }
        cout<<"Hi"<<endl;
        return -1;
    }
    bool verify(vector<vector<int>>&nums,int colomn,int peak){
        for(int i=1;i<nums.size()-1;i++){
            if()
        }
    }
     int find_peak(vector<int>&nums){
        int st=0,end=nums.size()-1,mid;
        whiel(st<=end){
            mid=st+(end-st)/2;
            if(mid!=nums.size()&&nums[mid]>nums[mid+1]){
                return mid;
            } else if(nums[mid]>nums[st]){
                st=mid+1;
            } else {
                end=mid-1;
            }
        }
        cout<<"Hi"<<endl;
        return -1;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        for(int i=1;i<nums[0].size()-1;i++){
            int peak=find_peak(nums[i]);
            cout<<"Peak found in row : "<<i+1<<" is : "<<peak<<endl;
            bool ans=verify(nums[i],nums[i][peak]);
        }
    }
};