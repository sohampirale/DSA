// //even position = even
// //odd posiiton = prime
// #include<iostream>
// #include<vector>
// using namespace std;
// int isPrime(int n){
//   for(int i=2;i<=n/2;i++){
//     if(n==2||n==3)return 1;
//     if(n%i==0)return 0;
//   }
//   return 1;
// }
// int cnt=0;
// vector<string>final_ans;
// void solution(int n,vector<string>work,string ans="",int j=0){
//   if(j%2==0)j=0;
//   else j=1;
//   if(ans.length()==n){
//     cnt++;
//     final_ans.push_back(ans);
//     return;
//   }
//   for(int i=0;i<work[j].size();i++){
//     solution(n,work,ans+work[j][i],j+1);
//   }
// }
// using namespace std;
// int main(){
//   int n;
//   cout<<"Enter  anumber : ";
//   cin>>n;
//   vector<string>work={"02468","2357"};
//   solution(n,work);
//   cout<<"Number of good strings possible are : "<<cnt<<endl;
//   cout<<"Answers are : "<<endl;
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
// }