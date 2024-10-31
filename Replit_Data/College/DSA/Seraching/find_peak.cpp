// #include<iostream>
// #include<vector>
// using namespace std;
// int find_peak(vector<int>&nums){
//   int st=0,end=nums.size()-1,mid;
//   while(st<end){
//     mid=st+(end-st)/2;
//     if(nums[mid]>nums[mid+1])return mid;
//     if(nums[mid]<nums[mid+1]){
//       st=mid+1;
//     } else{
//       end=mid+1;
//     }
//   }
//   return st;
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>nums;
//   cout<<"Enter "<<n<<" numbers : ";
//   for(int i=0;i<n;i++){
//     int temp;
//     cin>>temp;
//     nums.push_back(temp);
//   }
//   int peak=find_peak(nums);
//   cout<<"Peak found at "<<peak<<endl;
// }

// // Enter n : 6
// // Enter 6 numbers : 1 2 5 6 4 2
// // Peak found at 4

// // Enter n : 4
// // Enter 4 numbers : 0 2 1 0
// // Peak found at 1

// // Enter n : 9
// // Enter 9 numbers : 1 2 3 4 5 6 9 6 4
// // Peak found at 6

// // Enter n : 4
// // Enter 4 numbers : 3 4 5 1
// // Peak found at 2
