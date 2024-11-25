// #include<iostream>
// using namespace std;
// int findMin(int*num,int st,int end){
//   if(num[0]<num[1])return 0;
//   if(num[end]<num[end-1])return end;
//   int mid,n=end+1;
//   while(st<=end){
//     mid=st+(end-st)/2;
//     if(mid==0){st=mid+1;continue;}
//     if(mid==n-1){end=mid-1;continue;}
//     if(num[mid]<num[mid-1]&&num[mid]<num[mid+1]){
//       return mid;
//     } else if(num[mid]>num[mid+1]&&num[mid]<num[mid-1])st=mid+1;
//     else if(num[mid]>num[mid-1]&&num[mid]<num[mid+1])end=mid-1;
//   }
//   return -1;
// }
// int findMin2(int*num,int st,int end){
//   int mid;
//   while(st!=end){
//     mid=st+(end-st)/2;
//     if(num[mid]>num[mid+1])st=mid+1;
//     else {
//       end=mid;
//     }
//   }
//   return st;
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   cout<<"Enter "<<n<<" numbers : ";
//   int num[n];
//   for(int i=0;i<n;i++)cin>>num[i];
//   int ans=findMin2(num,0,n-1);
//   cout<<ans<<endl;
//   ans=findMin(num,0,n-1);
//   cout<<ans<<endl;
// }