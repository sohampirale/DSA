// // finds the target in an array by splitting it  into left and right everytime
// //time complexity is large
// #include<iostream>
// using namespace std;
// int cnt=0;
// int findSplittingArr(int *num, int target, int st, int end) {
//   cnt++;
//   int mid = (st + end) / 2;
//   if (num[mid] == target)
//     return mid;
//   else if (st + 1 == end) {
//     // cout<<"st+1==end, st = "<<st<<"& end = "<<end<<endl;
//     return 0;
// } else{
//     int temp=findSplittingArr(num, target, 0, mid) ;
//     if(temp!=0)return temp;
//     else return findSplittingArr(num, target, mid, end);
//   }
// }

// int findPeakInCyclicArray(int *num, int st, int end) {
//   int mid = (st + end) / 2;
//   if (num[mid] > num[mid+1])
//     return mid;
//   else if (st + 1 == end) {
//     // cout<<"st+1==end, st = "<<st<<"& end = "<<end<<endl;
//     return 0;
//   } else
//     return findPeakInCyclicArray(num, 0, mid) + findPeakInCyclicArray(num,  mid, end);
// }

// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   int num[n];
//   for(int i=0;i<n;i++)cin>>num[i];
//   int target=1,ans;
//   while(target!=0){
//     cout<<"Enter target : ";
//     cin>>target;
//     ans=findSplittingArr(num,target,0,n-1);
//     cout<<"Ans = "<<ans<<endl;
//     cout<<"number of counts required were : "<<cnt<<endl;
//     cnt=0;
//   }
// }