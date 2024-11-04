// //most simple


// class Solution {
// public:
//     int find_left(vector<int>&nums,int target,int st,int end,int pans){
//         if(st>end){
//             return pans;
//         }
//         int mid=st+(end-st)/2;
//         if(nums[mid]==target){pans=mid;end=mid-1;}
//         else if(target>nums[mid])st=mid+1;
//         return find_left(nums,target,st,end,pans);
//     }
//     int find_right(vector<int>&nums,int target,int st,int end,int pans){
//         if(st>end){
//             return pans;
//         }
//         int mid=st+(end-st)/2;
//         if(nums[mid]==target){pans=mid;st=mid+1;}
//         else if(target<nums[mid])end=mid-1;
//         return find_right(nums,target,st,end,pans);
//     }
//     vector<int> find(vector<int>&nums,int target,int st,int end){
//         static vector<int>ans(0,0);
//         ans.clear();
//         if(st>end){
//             ans.push_back(-1);
//             ans.push_back(-1);
//             return ans;
//         }
//         int mid=st+(end-st)/2;
//         if(nums[mid]==target){
//             int left=find_left(nums,target,0,mid,mid);
//             int right=find_right(nums,target,mid,end,mid);
//             ans.push_back(left);
//             ans.push_back(right);
//             return ans;
//         } else if(target>nums[mid])st=mid+1;
//         else if(target<nums[mid])end=mid-1;
//         return find(nums,target,st,end);
//     }
//     vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int>ans=find(nums,target,0,nums.size()-1);
//         return ans;
//     }
// };
// // my answer
// // class Solution {
// // public:
// //     int find_left(vector<int>&nums,int target,int st,int end){
// //         if(st==end){
// //             cout<<"Retunring "<<st<<" from find_left"<<endl;
// //             return st;
// //         }
// //         int mid=st+(end-st)/2;
// //         if(nums[mid]==target)end=mid;
// //         else st=mid+1;
// //         return find_left(nums,target,st,end);
// //     }
// //     int find_right(vector<int>&nums,int target,int st,int end){
// //         if(st==end){
// //             cout<<"Returning "<<st<<" from find_right"<<endl;
// //             return st;
// //         }
// //         int mid=st+(end-st)/2;
// //         if(nums[mid]==target)st=mid;
// //         else end=mid-1;
// //         return find_right(nums,target,st,end);
// //     }
// //     vector<int> find(vector<int>&nums,int target,int st,int end){
// //         static vector<int>ans;
// //         ans.clear();
// //         if(st>end){
// //             cout<<"Element not found"<<endl;
// //             ans.push_back(-1);
// //             ans.push_back(-1);
// //             return ans;
// //         }
// //         int mid=st+(end-st)/2;
// //         if(nums[mid]==target){
// //             int left=find_left(nums,target,0,mod);
// //             int right=find_right(nums,target,mid,nums.size()-1);
// //             ans.push_back(left);
// //             ans.push_back(right);
// //             return ans;
// //         } else if(target>nums[mid])st=mid+1;
// //         else if(target<nums[mid])end=mid-1;
// //         return find(nums,target,st,end);
// //     }
// //     vector<int> searchRange(vector<int>& nums, int target) {
// //         vector<int>ans=find(nums,target,0,nums.size()-1);
// //         return ans;
// //     }
// // };

//incorrect
// class Solution {
// public:
//     vector<int> helper(vector<int>&nums,int target,int start,int end){
//         static vector<int>ans;
//         ans.clear();
//         if(start>end){
//             cout<<"Before pushing -1 the vecor was :";
//             for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
//                 ans.push_back(-1);
//                 ans.push_back(-1);
//                 return ans;
//         }
//         int mid=start+(end-start)/2;
//         if(nums[mid]==target){
//             if(mid!=0&&nums[mid-1]==target){
//                 ans.push_back(mid-1);
//                 ans.push_back(mid);
//                 cout<<"hi"<<endl;
//                 return ans;
//             } else if(mid!=nums.size()-1&&nums[mid+1]==target){
//                 cout<<"hey"<<endl;

//                 ans.push_back(mid);
//                 ans.push_back(mid+1);
//                 return ans;
//             } else{
//                 ans.push_back(mid);
//                 ans.push_back(mid);
//                 return ans;
//             }
//         } else if(nums[mid]<target)start=mid+1;
//         else if(nums[mid]>target)end=mid-1;
//         return helper(nums,target,start,end);
//     }
//     vector<int> searchRange(vector<int>& nums, int target) {
//         // if(nums.size()==1&&nums.front()==target){
//         //     vector<int>ans(2,0);
//         //     return ans;
//         // }
//         return helper(nums,target,0,nums.size()-1);
//     }
// };



