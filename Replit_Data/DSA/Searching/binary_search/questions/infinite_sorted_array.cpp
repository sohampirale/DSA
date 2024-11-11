// #include<iostream>
// #include<vector>
// using namespace std;
// int binarySearch(int*arr,int target,int st,int end){
//   int mid=st+(end-st)/2;
//   while(st<=end){
//     cout<<"hey"<<endl;
//     mid=st+(end-st)/2;
//     if(arr[mid]==target)return mid;
//     else if(arr[mid]>target)end=mid-1;
//     else if(arr[mid]<target)st=mid+1;
//   }
//   return -1;
// }
// int findRange(int*arr,int target){
//   int st=0,end=1;
//   while(arr[end]<target){
//     cout<<"hi"<<endl;
//     int temp=end+1;
//     end=end+(end-st+1)*2;
//     st=temp;
//   }
//   cout<<"Found the range between "<<st<<" & "<<end<<endl;
//   return binarySearch(arr,target,st,end);
// }
// int main(){
//   int num[]={1,2,3,4,5,6,7,8,9,10,11};
//   int ans=findRange(num,10);
//   cout<<ans<<endl;
// }