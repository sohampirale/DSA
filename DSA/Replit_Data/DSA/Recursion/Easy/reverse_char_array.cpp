// #include<iostream>
// #include<vector>
// using namespace std;
// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//       static int st=0,e=s.size()-1;
//       if(st>=e)return;
//       char temp=s[st];
//       s[st]=s[e];
//       s[e]=temp;
//       st++;
//       e--;
//       reverseString(s);
//     }
// };
// int main(){
//   Solution S;
//   // int n;
//   // cout<<"Enter number of characters you have : ";
//   // cin>>n;
//   vector<char>s(6)={"H","a","n","n","a","h"};

//   // for(int i=0;i<n;i++)cin>>s[i];
//   S.reverseString(s);
//   cout<<"Answer is : ";
//   for(int i=0;i<s.size();i++)cout<<s[i];
// }