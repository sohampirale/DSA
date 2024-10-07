class Solution {
public:
    int find(vector<int>&nums){
        int st=0,end=nums.size()-1,mid;
        while(st<=end){
            mid=st+(end-st)/2;

            if(mid!=nums.size()-1&&nums[mid]==nums[mid+1]){
                if(mid%2==0){
                    st=mid+1;
                } else {
                    end=mid-1;
                }
            } else if(mid!=0&&nums[mid]==nums[mid-1]){
                if((mid-1)%2==0){
                    st=mid+1;
                } else {
                    end=mid-1;
                }
            } else {
                cout<<"NUmber found : "<<nums[mid]<<endl;
                return nums[mid];
            }
        }

    }
    int singleNonDuplicate(vector<int>& nums) {
        int ans=find(nums);   
        cout<<"ANswer received si : "<<ans<<endl;
        retunr ans;
    }
};