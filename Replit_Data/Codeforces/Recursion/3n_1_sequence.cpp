// #include<iostream>
// #include<vector>
// using namespace std;
// int solve(int n,vector<string>ans){
//   char ch='0'+n;
//   if(n==1)return ans.size()+1;
//   else if(n%2==0){
//     // ch='0'+ n ;
//     ans.push_back(to_string(ch));
//     return solve(n/2,ans);
//   } else {
//     // ch= '0'+n;
//     ans.push_back(to_string(ch));
//     return solve((3*n)+1,ans);
//   }
// }
// int main(){
//   int n;
//   cin>>n;
//   vector<string>ans;
//   cout<<solve(n,ans);
// }