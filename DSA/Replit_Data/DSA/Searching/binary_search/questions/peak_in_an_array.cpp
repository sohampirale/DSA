// // //this is an array but it is not rotated or cyclic

// #include<iostream>
// using namespace std;
// int findRecursive(int* arr,int target,int st,int end,int mid){
//   if(st>end)return -1;
//   if(arr[mid]==target)return mid;
//   else if(arr[mid]<target)st=mid+1;
//   else end=mid-1;
//   return findRecursive(arr,target,st,end,st+(end-st)/2);
// }
// int findPeakInNormalArrayRightMost(int* num,int st,int end,int mid,int cnt=1){
//   if(st==end){
//     cout<<"Retunring "<<st<<endl;
//     return st;
//   }
//   if(num[mid]<=num[mid+1]){        
//     //by putting <= to sign in the condiiton we can get the right most elemnt in the peak in the arr for exmaple 1 2 3 4 4 4 4 4 2 1  we can get the index of the third last element that is "4" in the array
//     st=mid+1;
//     mid=st+(end-st)/2;
//     return findPeakInNormalArrayRightMost(num,st,end,mid,cnt+1);
//     cout<<"hi"<<endl;
//   } else {
//     end=mid;
//     mid=st+(end-st)/2;
//     return findPeakInNormalArrayRightMost(num,st,end,mid,cnt+1); 
//   }
// }

// //if we dont use the = sign in the if(num[mid]<num[mid+1]){ then it gives us the leftmost peak element
// //ex 1 2 3 4 4 4 4 2 1 
// //returns index 3

// int findPeakInNormalArrayLeftMost(int* num,int st,int end,int mid,int cnt=1){
//   if(st==end){
//     cout<<"Retunring "<<st<<endl;
//     return st;
//   }
//   if(num[mid]<num[mid+1]){
//     st=mid+1;
//     mid=st+(end-st)/2;
//     return findPeakInNormalArrayLeftMost(num,st,end,mid,cnt+1);
//     cout<<"hi"<<endl;
//   } else {
//     end=mid;
//     mid=st+(end-st)/2;
//     return findPeakInNormalArrayLeftMost(num,st,end,mid,cnt+1); 
//   }
// }

// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   int num[n];
//   for(int i=0;i<n;i++)cin>>num[i];
//   int choice=1,ans;
//   ans=findRecursive(num,4,0,n-1,(n-1)/2);
//   cout<<"Ans = "<<ans<<endl;
  
//   cout<<"Enter your choice\n1 : Find peak that will be rightmost\n2 : Find peak that will be left most\nYour choice : ";
//   cin>>choice;
  
//   if(choice==1)ans=findPeakInNormalArrayRightMost(num,0,n-1,(n-1)/2);
//   else ans=findPeakInNormalArrayLeftMost(num,0,n-1,(n-1)/2);

//   cout<<"Peak found at index = "<<ans<<endl;
// }





// // // #include<iostream>
// // // using namespace std;
// // // int findPeak(int*num,int st,int end){
// // //   int mid,n=end+1;
// // //   while(st<=end){
// // //     mid=st+(end-st)/2;
// // //     if(mid==0){st=mid+1;continue;}
// // //     if(mid==n-1){end=mid-1;continue;}
// // //     if(num[mid]>num[mid-1]&&num[mid]>num[mid+1]){
// // //       return mid;
// // //     } else if(num[mid]>num[mid+1]&&num[mid]<num[mid-1])end=mid-1;
// // //     else if(num[mid]>num[mid-1]&&num[mid]<num[mid+1])st=mid+1;
// // //   }
// // //   return -1;
// // // }
// // // int findPeak2(int*num,int st,int end){
// // //   int mid;
// // //   while(st!=end){
// // //     mid=st+(end-st)/2;
// // //     if(num[mid]<num[mid+1])st=mid+1;
// // //     else {
// // //       end=mid;
// // //     }
// // //   }
// // //   return st;
// // // }
// // // int main(){
// // //   int n;
// // //   cout<<"Enter n : ";
// // //   cin>>n;
// // //   cout<<"Enter "<<n<<" numbers : ";
// // //   int num[n];
// // //   for(int i=0;i<n;i++)cin>>num[i];
// // //   int ans=findPeak2(num,0,n-1);
// // //   cout<<ans<<endl;
// // //   ans=findPeak(num,0,n-1);
// // //   cout<<ans<<endl;

// // // }
