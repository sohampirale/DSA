// #include<iostream>
// #include<vector>
// #include<math.h>
// using namespace std;
// vector<string>final_ans;
// int safe(int num){
//   string temp=to_string(num);
//   for(int i=1;i<temp.length();i++){
//     if(temp[i]<=temp[i-1])return 0;
//   }
//   return 1;
// }
// int cnt=0;
// void solution(int s,int e){
//   for(int i=s;i<=e;i++){
//     if(safe(i)){
//       cnt++;
//       final_ans.push_back(to_string(i));
//     }
//   }
// }
// int main(){
//   int n,s,e;
//   cout<<"Enter n : ";
//   cin>>n;
//   s=pow(10,n-1);
//   e=pow(10,n);
//   solution(s,e);
//   cout<<"Solutions are : "<<endl;
//   for(int i=0;i<final_ans.size();i++){
//     cout<<final_ans[i]<<endl;
//   }
//   cout<<"Number of solutions possible are : "<<cnt<<endl;
// }