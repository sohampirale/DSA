// #include<iostream>
// using namespace std;
// int test=0;
// int find(int*arr,int target,int st,int end,int mid){
//   if(st>end){test=1;return -1;}
//   if(target==arr[mid]){
//     return mid;
//   } else if(target>arr[mid]){
//     return find(arr,target,mid+1,end,(mid+1)+(end-(mid+1)/2));
//   } else {
//     return find(arr,target,st,mid-1,st+((mid-1)-st)/2);
//   }
// }
// int main(){
//   int n;
//   cout<<"How many numbers you have : ";
//   cin>>n;
//   cout<<"Enter "<<n<<" numbers : ";
//   int num[n];
//   for(int i=0;i<n;i++)cin>>num[i];
//   int target;
//   cout<<"Enter the number you want to search in the array : ";
//   cin>>target;
//   int ans=find(num,target,0,n-1,(n-1)/2);
//   cout<<ans<<endl;
// }