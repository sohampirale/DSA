// // // #include<iostream>
// // // using namespace std;
// // // int findInRotated(int*num,int target,int n){
// // //   int st=0,end=n-1;
// // //   int mid;
// // //   while(st<=end){
// // //     mid=st+(end-st)/2;
// // //     if(num[mid]==target)return mid;
// // //     else if(num[mid]<target){
// // //       if(num[end]>=target)st=mid+1;
// // //       else end=mid-1;
// // //     } else if(num[mid]>target){
// // //       if(num[end]>target)st=mid+1;
// // //       else end=mid-1;
// // //     }
// // //   }
// // //   return -1;
// // // }
// // // int main(){
// // //   int n;
// // //   cout<<"Enter n : ";
// // //   cin>>n;
// // //   int num[n];
// // //   for(int i=0;i<n;i++)cin>>num[i];
// // //   int target;
// // //   cout<<"Enter target : ";
// // //   cin>>target;
// // //   int ans=findInRotated(num,target,n);
// // //   cout<<ans<<endl;
// // // }


// // #include <iostream>
// // using namespace std;

// // // in this search everytime target is not found on the mid, the search goes left
// // // and right from mid until only 2 elemnets remain the left one is not target

// // int findSplittingArr(int *num, int target, int st, int end) {
// //   int mid = (st + end) / 2;
// //   if (num[mid] == target)
// //     return mid;
// //   else if (st + 1 == end) {
// //     // cout<<"st+1==end, st = "<<st<<"& end = "<<end<<endl;
// //     return 0;
// //   } else
// //     return findSplittingArr(num, target, 0, mid) + findSplittingArr(num, target, mid, end);
// // }
// // int find(int*arr,int target,int st,int end){
// //   int mid;
// //   while(st<=end){
// //     mid=st+(end-st)/2;
// //     if(arr[mid]==target)return mid;
// //     else if(target>arr[mid])st=mid+1;
// //     else end=mid-1;
// //   }
// //   return -1;
// // }
// // int findPeakInCyclicArray(int *num, int st, int end) {
// //   int mid = (st + end) / 2;
// //   if (num[mid] > num[mid+1])
// //     return mid;
// //   else if (st + 1 == end) {
// //     // cout<<"st+1==end, st = "<<st<<"& end = "<<end<<endl;
// //     return 0;
// //   } else
// //     return findPeakInCyclicArray(num, 0, mid) + findPeakInCyclicArray(num,  mid, end);
// // }

// // int findPeakRotatedArray(int*arr,int st,int end){
// //   int mid;
// //   while(st<=end){
// //     mid=st+(end-st)/2;
// //     if(arr[mid]>arr[mid+1])return mid;
// //     else if(arr[mid]<arr[st])end=mid-1;
// //     else st=mid+1;
// //   }
// //   return -1;
// // }
// // int main() {
// //   int n;
// //   cout << "ENter n : ";
// //   cin >> n;
// //   int num[n];
// //   for (int i = 0; i < n; i++)
// //     cin >> num[i];
// //   int target;
// //   cout << "Enter target : ";
// //   cin >> target;
  
// //   // int ans;
// //   // if (num[n - 1] >= num[0])
// //   //   ans = n - 1;
// //   // else
// //   //   ans = findPeakInCyclicArray(num,0, n - 1);
// //   // cout << "ans = " << ans << endl;
// //   int ans;
// //   int peak=findPeakRotatedArray(num,0,n-1);
// //   cout<<"peak  = "<<peak<<endl;
// //   while(target!=0){
// //     if(num[peak]==target)ans=peak;
// //     else if(target>=num[0])ans=find(num,target,0,peak);
// //     else ans=find(num,target,peak+1,n-1);
// //     cout<<"Ans = "<<ans<<endl;
// //     cout<<"Enter another target : ";
// //     cin>>target;
// //   }
// // }

// //find peak in rotated array
// #include<iostream>
// using namespace std;
// // int findPeakInSortedArray(int*arr,int st,int end,int mid){
// //   if(st>=end){
// //     cout<<"st ="<<st<<" 7 end = "<<end<<endl;
// //     cout<<"Returning "<<st<<endl;
// //     return st;
// //   }
// //   if(arr[mid]>arr[mid+1]){
// //     cout<<"arr[mid] ="<<arr[mid]<<"  arr[mid+1] = "<<arr[mid+1]<<endl;
// //     cout<<"Returning "<<mid<<endl;
// //     return mid;
// //   }
// //   if(arr[mid]<=arr[st])end=mid-1;
// //   else st=mid;
// //   return findPeakInSortedArray(arr, st, end, st+(end-st)/2);
// // }
// int cnt=1;
// int findPeakRotatedRecursiveWithDuplicates(int*arr,int st,int end,int mid){

//   if((st>=end)||arr[mid]>arr[mid+1])return mid;
//   else if(arr[mid]==arr[st]&&arr[mid]==arr[end]){st++;end--;}    
//      //we also have to check   arr[mid] == arr[end]   because the peak might exist on left of mid or right of mid then its better to incr & reduce st & end and check again (ex - 3 9 9 3 3 3 3 3 or 3 3 3 3 3 3 9 3 3) if w dont check for end we might fail at situatiosn like these (2 2 2 2 2 2 8 9 ) 
//   else if(arr[mid]<arr[st])end=mid-1;
//   else st=mid+1;

//   return findPeakRotatedRecursiveWithDuplicates(arr,st,end,st+(end-st)/2);
// }
// int findPeakRotatedRecursive(int*arr,int st,int end,int mid){
 
//   if((st==end)||arr[mid]>arr[mid+1])return mid;
//   else if(arr[mid]<arr[st])end=mid-1;
//   else st=mid+1;
 
//   return findPeakRotatedRecursive(arr,st,end,st+(end-st)/2);
// }
// int findPeakRotatedIterative(int*arr,int st,int end){
//   int mid;
//   while(1){
//     mid=st+(end-st)/2;
//     if((st==end)||arr[mid]>arr[mid+1])return mid;
//     else if(arr[mid]<arr[st])end=mid-1;
//     else st=mid+1;
//   }
//   return -1;
// }
// int solution(int*num,int target,int st,int end,int mid){
//   // if(st==mid){if(num[st]==target)return st; else return 0;}
//   if(st>end)return -1;
//   if(num[mid]==target){cout<<"Found in "<<cnt<<"tries"<<endl;return mid;}
//   else {
//     int left=solution(num,target,st,mid-1,(st)+(mid-1-st)/2);
//     cnt++;
//     if(left!=-1  ){return left;}
//     else {cnt++;return solution(num,target,mid+1,end,(mid+1)+(end-(mid+1))/2);}
//   }
// }
// int findRecursive(int* arr,int target,int st,int end,int mid){
//   if(st>end)return -1;
//   if(arr[mid]==target)return mid;
//   else if(arr[mid]<target)st=mid+1;
//   else end=mid-1;
//   return findRecursive(arr,target,st,end,st+(end-st)/2);
// }

// int findIterative(int*arr,int target,int st,int end){
//   int mid;
//   while(st<=end){
//     mid=st+(end-st)/2;
//     if(arr[mid]==target)return mid;
//     else if(arr[mid]>target)end=mid-1;
//     else st=mid+1; 
//   }
//   return -1;
// }
// int main(){
//   int choice=1;
//   while(choice!=0){
//     int n,target,ans=-1,peak=-1,ch=-1;
//     cout<<"Enter n : ";
//     cin>>n;
//     int num[n];
//     for(int i=0;i<n;i++)cin>>num[i];
   
//     cout<<"Enter target : ";
//     cin>>target;
//     cout<<"How do you want top find answer ?\n1 : Recursive\n2 : Iterative\n3 : Recursive (1 function)\n4 : Find peak of Rotated array with duplicates\nYour choice : ";
//     cin>>ch;
//     if(ch==1){
//       peak=findPeakRotatedRecursive(num,0,n-1,(n-1)/2);
//       if(num[0]>target)ans=findRecursive(num,target,peak+1,n-1,(peak+1)+((n-1)-(peak+1))/2);  //(peak+1)+((n-1)-(peak+1))/2 this is st+(end-st)/2
//       else ans=findRecursive(num,target,0,peak,(peak)/2);
//     } else if(ch==2){
//       peak = findPeakRotatedIterative(num,0,n-1);
//       if(num[0]>target)ans=findIterative(num,target,peak+1,n-1);
//       else ans=findIterative(num,target,0,peak);
//     } else if(ch==3){
//       ans=solution(num,target,0,n-1,(n-1)/2);
//     } else if(ch==4){
//       peak=findPeakRotatedRecursiveWithDuplicates(num,0,(n-1),(n-2)/2);
//       cout<<"Peak of rotated array with duplicates : "<<peak<<endl;
//     }
//     cout<<"Peak found at position -> "<<peak<<endl;
//     if(ans!=-1)cout<<target<<"(target) found at position : "<<ans<<endl;
//     else cout<<target<<" not found"<<endl;
//     cout<<cnt<<endl;
//     cnt=0;
//     cout<<"Do you want to try again : ";
//     cin>>choice;
//   }
// }
