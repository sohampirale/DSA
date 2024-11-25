// #include<iostream>
// using namespace std;
// int findCeiling(int*arr,int target,int start,int end){
//   if(arr[end]<target)return -1;
//   else if(arr[start]>target)return 0;
//   int mid=-1;
//   while(1){
//     mid=start+(end-start)/2;
//     if(target==arr[mid])return mid;
//     else if(mid==start)return end;
//     else if(target<arr[mid])end=mid;
//     else if(target>arr[mid])start=mid;
//   }
//   return -1;
// }
// int findCeiling2(int*arr,int target,int start,int end){
//   if(arr[end]<target)return -1;
//   else if(arr[start]>target)return 0;
//   int mid=-1;
//   while(start<=end){
//     mid=start+(end-start)/2;
//     if(target==arr[mid])return mid;
//     // else if(mid==start)return end;
//     else if(target<arr[mid])end=mid-1;
//     else if(target>arr[mid])start=mid+1;
//   }
//   return start;
//   // mid=start+(end-start)/2;
//   // if(arr[mid]==target)return mid;
//   // else return start+1;
//   // return -1;
// }
// int main(){
//   int n;
//   cout<<"Enter how many numbers you hav e: ";
//   cin>>n;
//   cout<<"Enter "<<n<<" numbers : ";
//   int num[n];
//   for(int i=0;i<n;i++)cin>>num[i];
//   int target;
//   cout<<"Enter the number you want to find ceiling of : ";
//   cin>>target;
//   int ans=findCeiling2(num,target,0,n-1);
//   cout<<ans<<endl;
// }