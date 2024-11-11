// #include<iostream>
// #include<vector>
// using namespace std;
// int find_ele(vector<int>&nums,int st,int end,int find){
//   int mid;
//   while(st<=end){
//     mid=st+(end-st)/2;
//     if(nums[mid]==find){
//       // cout<<"Found at index = "<<mid<<endl;
//       return mid;
//     }
//     if(nums[mid]>find)end=mid-1;
//     else if(nums[mid]<find)st=mid+1;
//   }
//   // cout<<"Not found"<<endl;
//   return -1;
// }
// int find_peak(vector<int>&nums){
//   int st=0,end=nums.size()-1,mid;
//   while(st<end){
//     mid=st+(end-st)/2;
//     if(nums[mid]==nums[st]&&nums[mid]==nums[end]){
//       end--;
//       st++;
//       continue;
//     }
//     if(nums[mid]>nums[mid+1]){
//       return mid;
//     }
//     if(nums[mid]<nums[st]){
//       end=mid-1;
//     } else {
//       st=mid+1;
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
//   int find,ans=-1;
//   cout<<"Enter the number you want to find : ";
//   cin>>find;
//   if(nums[0]==find){cout<<"Found at pos = 0"<<endl;return 0;}
//   else if(nums.back()==find)cout<<"Found at last index"<<endl;
//   ans=find_ele(nums,0,peak,find);
//   if(ans!=-1)cout<<"Found at index = "<<ans<<endl;
//   else {
//     ans=find_ele(nums,peak+1,nums.size()-1,find);
//     if(ans!=-1)cout<<"Found at index = "<<ans<<endl;
//     else cout<<"Not present in the index"<<endl;
//   }

// }
// // Enter n : 7
// // Enter 7 numbers : 4 5 6 7 0 1 2
// // Peak found at 3
// // Enter the number you want to find : 0
// // Found at index = 4

// // Enter n : 7
// // Enter 7 numbers :   4 5 6 7 0 1 2
// // Peak found at 3
// // Enter the number you want to find : 3
// // Not present in the index


// // Enter n : 7
// // Enter 7 numbers : 2 5 6 0 0  1 2
// // Peak found at 2
// // Enter the number you want to find : 5
// // Found at index = 1
// // Element found at : 1
// // Enter n : 9
// // Enter 9 numbers : 1 2 3 4 5 6 9 6 4
// // Peak found at 6


// // #include<iostream>
// // #include<vector>
// // using namespace std;

// // int find_ele(vector<int>&no,int find,int st,int end){
// //   int mid;
// //   while(st<=end){
// //     mid=st+(end-st)/2;
// //     if(no[mid]==find)return mid;
// //     else if(no[mid]<find)st=mid+1;
// //     else end=mid-1;
// //   }
// //   return -1;
// // }

// // int find_peak(vector<int>&no){
// //   int st=0,end=no.size()-1,mid;
// //   while(st<end){
// //     mid=st+(end-st)/2;
// //     if(no[st]==no[mid]&&no[end]==no[mid]){
// //       st++;
// //       end--;
// //     } else if(no[mid]<no[st])end=mid-1;
// //     else st=mid;
// //   }
// //   if(st==end)cout<<"St & end same"<<endl;
// //   else cout<<"St & end not same"<<endl;
// //   int find;
// //   cout<<"Enter the number you want to find : ";
// //   cin>>find;
// //   int ans=find_ele(no,find,0,st);
// //   return ans!=-1? ans : find_ele(no,find,st,no.size()-1);
// // }

// // int main(){
// //   int n,temp;
// //   cout<<"Enter how many numbers you have : ";
// //   cin>>n;
// //   vector<int>no;
// //   cout<<"Enter "<<n<<" numbers : ";
// //   for(int i=0;i<n;i++){
// //     cin>>temp;
// //     no.push_back(temp);
// //   }
// //   int ans=find_peak(no);
// //   cout<<"Answer received is : "<<ans<<endl;
// // }