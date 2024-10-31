// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/Y

// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string>final_ans;
// int solve(string str,int e,string ans=""){
//   int cnt=0;
//   if(str.length()==0){
//     if(ans[ans.length()-1]=='0'+e){
//       final_ans.push_back(ans);
//       return 1;
//     }
//     else return 0 ;
//   }
//   char ch=str[0];
//   cnt+=solve(str.substr(1,str.length()),e,ans+ch);
//   cnt+=solve(str.substr(1,str.length()),e,ans);
//   return cnt;
// }
// int main(){
//   int s,e;
//   cin>>s>>e;
//   string str="";
//   for(int i=s+1;i<=e;i++){
//     str+=to_string(i);
//   }
//   cout<<solve(str,e,to_string(s));
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string>final_ans;
// long long solve(string str,int e,string ans=""){
//   long long cnt=0;
//   if(str.length()==0){
//     if(ans[ans.length()-1]=='0'+e){
//       final_ans.push_back(ans);
//       return 1;
//     }
//     else return 0 ;
//   }
//   char ch=str[0];
//   cnt+=solve(str.substr(1,str.length()),e,ans+ch);
//   cnt+=solve(str.substr(1,str.length()),e,ans);
//   return cnt;
// }
// int main(){
//   long long s,e;
//   cin>>s>>e;
//   string str="";
//   for(int i=s+1;i<=e;i++){
//     str+=to_string(i);
//   }
//   cout<<solve(str,e,to_string(s));
// }