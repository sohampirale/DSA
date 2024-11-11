// #include<iostream>
// using namespace std;
// long long tribonachi(long long n){

//   if(n<3)return n==0? 0 : 1;
//   return tribonachi(n-1)+tribonachi(n-2)+tribonachi(n-3);
// }
// int main(){
//   long long n;
//   cin>>n;
//   cout<<tribonachi(n)<<endl;
// }

// #include<iostream>
// using namespace std;
// int temp,cnt=2;
// int solve(int n,int* ans){
//   if(n<3)return n==0? 0 : 1;
//   if(cnt==n)return ans[2];
//   temp=ans[2]+ans[1]+ans[0];
//   ans[0]=ans[1];
//   ans[1]=ans[2];
//   ans[2]=temp;
//   cnt++;
//   return solve(n,ans);
// }
// int main(){
//   int n,ans[3]={0,1,1};
//   cin>>n;
//   cout<<solve(n,ans);
// }