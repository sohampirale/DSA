// #include<iostream>
// #include<vector>
// using namespace std;
// int find_peak_in_decreasing_array(vector<int>&nums){
//     int st=0,end=nums.size()-1,mid;
//     while(st<end){
//         mid=st+(end-st)/2;
//         if(mid==0   && nums[0]>nums[nums.size()-1]){
//             return mid;
//         } else if(nums[mid]>nums[mid-1]  ){
//             return mid;
//         } else if(nums[mid]>nums[end]){
//             end=mid-1;
//         } else {
//             st=mid+1;
//         }
//     }
//     cout<<"St = "<<st<<" & end = "<<end<<endl;
//     return st;
// }
// int main(){
//     int n;
//     cout<<"ENter size of array 1 : ";
//     cin>>n;
//     cout<<"ENter "<<n<<" numbers of array 1 : ";
//     int temp;
//     vector<int>nums(n,0);
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     int peak=find_peak_in_decreasing_array(nums);
//     cout<<"Peak receievd is : "<<peak<<endl;
// }