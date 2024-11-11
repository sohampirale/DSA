// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// // vector<string>final_ans;
// vector<int>final_ans;

// void sets(string str,string ans){
//   if(str.length()==0){
//     // cout<<ans<<endl;
//     if(!ans.empty()){final_ans.push_back(stoi(ans));}
//     return;
//   }
//   char ch=str[0];
//   str.erase(0,1);
//   sets(str,ans+ch);
//   sets(str,ans);
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   sets(str,"");
//   sort(final_ans.begin(),final_ans.end());
//   cout<<"All possible sets are : "<<endl;
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// // vector<string>final_ans;
// vector<int>final_ans;

// void sets(string str,string ans){
//   if(str.length()==0){
//     // cout<<ans<<endl;
//     if(!ans.empty()){final_ans.push_back(stoi(ans));}
//     return;
//   }
//   char ch=str[0];
//   str.erase(0,1);
//   sets(str,ans+ch);
//   sets(str,ans);
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   sets(str,"");
//   // reverse(final_ans.begin(),final_ans.end());
//   // sort(final_ans.begin(),final_ans.end());
//   cout<<"All possible sets are : "<<endl;
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }

//if sets are made in revese order

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// // vector<string>final_ans;
// vector<int>final_ans;

// void sets(string str,string ans){
//   if(str.length()==0){
//     // cout<<ans<<endl;
//     if(!ans.empty()){final_ans.push_back(stoi(ans));}
//     return;
//   }
//   char ch=str[0];
//   str.erase(0,1);
//   sets(str,ch+ans);
//   sets(str,ans);
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   sets(str,"");
//   sort(final_ans.begin(),final_ans.end());
//   cout<<"All possible sets are : "<<endl;
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }


// #include<iostream>
// #include<vector>
// using namespace std;

// int i=0;
// void solution(string str,vector<string>&v1,vector<string>&v2){
//   if(str.length()==0)return;
//   for(int j=0;j<v2.size();j++)v2[j]+=str[0];
//   for(int i=0;i<v2.size();i++)v1.push_back(v2[i]);
//   // v1.insert(v1.end(),v2.begin(),v2.begin()+i);
//   v2=v1;
//   str.erase(0,1);
//   i++;
//   solution(str,v1,v2);
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   vector<string>v1(1,"");
//   vector<string>v2(1,"");
//   solution(str,v1,v2);
//   cout<<"All sets are : "<<endl;
//   for(int i=0;i<v1.size();i++)cout<<v1[i]<<endl;
//   // for(int i=0;i<v2.size();i++)cout<<v2[i]<<endl;//un
// }


//no duplicate sets

// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// void solution(string str,vector<vector<int>>&right,vector<vector<int>>&left){ 
//   if(str.length()==0)return;
//   for(int i=0;i<right.size();i++){
//     right[i].push_back((str[0]-'0'));
//     for(int j=0;j<left.size();j++){
//       if(left[j]==right[i]){
//         // right[i].clear();
//         right.erase(right.begin()+i);
//         i--;
//       }
//     }
//   }
//   for(int i=0;i<right.size();i++){
//     left.push_back(right[i]);
//   }
//   right=left;
//   str.erase(0,1);
//   solution(str,right,left);
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   vector<vector<int>>right(1);
//   vector<vector<int>>left(1);
//   solution(str,right,left);
//   cout<<"Sets are : "<<endl;
//   // for(int i=0;i<left.size();i++){for(int j=0;j<left[i].size();j++){cout<<left[i][j];}cout<<endl;}
//   // for(int i=0;i<left.size();i++){
//   //   for(int j=0;j<right.size();j++){
//   //     if(left[i]==right[j]){
//   //       // right.erase(j,right[j].size());
//   //     }
//   //   }
//   // }
//   for(int i=0;i<right.size();i++){for(int j=0;j<right[i].size();j++){cout<<right[i][j];}cout<<endl;}

// }


// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// int j=1,l,lc=0;
// char ch;
// void solution(string str,vector<vector<int>>&right,vector<vector<int>>&left){ 
//   if(str.length()==0)return;
//   if(str[0]!=ch){for(int i=0;i<right.size();i++){
//     right[i].push_back((str[0]-'0'));
//   }}
//   else {
//     cout<<"else condiiron hit"<<endl;
//     cout<<"ch = "<<ch<<endl;
//     lc+=(right.size()/2);
//     for(int k=0;k<lc;k++)right[k].clear();
//     for(int i=lc;i<right.size();i++){
//       right[i].push_back((str[0]-'0'));
//   }
//   }
//   for(int i=0;i<right.size();i++){
//     left.push_back(right[i]);
//   }
//   right=left;
//   ch=str[0];
//   str.erase(0,1);
//   j++;
//   solution(str,right,left);
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   ch='z';
//   l=str.length();
//   vector<vector<int>>right(1);
//   vector<vector<int>>left(1);
//   solution(str,right,left);
//   cout<<"Sets are : "<<endl;
//   for(int i=0;i<right.size();i++){for(int j=0;j<right[i].size();j++){if(!right[i].empty())cout<<right[i][j];}if(!right[i].empty())cout<<endl;}//empty answers are not printed

// }

// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// int j=0,l,lc=0;
// char ch;
// void solution(string str,vector<vector<int>>&right,vector<vector<int>>&left){ 
//   if(j==str.length())return;
//   if(j>0&&str[j]!=str[j-1]){for(int i=0;i<right.size();i++){
//     right[i].push_back((str[j]-'0'));
//   }}
//   else {
//     cout<<"else condition hit"<<endl;
//     cout<<"ch = "<<ch<<endl;
//     lc+=(right.size()/2);
//     for(int k=0;k<lc;k++)right[k].clear();
//     for(int i=lc;i<right.size();i++){
//       right[i].push_back((str[j]-'0'));
//   }
//   } 
//   for(int i=0;i<right.size();i++){
//     left.push_back(right[i]);
//   }
//   right=left;
//   // ch=str[0];
//   // str.erase(0,1);
//   j++;
//   solution(str,right,left);
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   ch='z';
//   l=str.length();
//   vector<vector<int>>right(1);
//   vector<vector<int>>left(1);
//   solution(str,right,left);
//   cout<<"Sets are : "<<endl;
//   for(int i=0;i<right.size();i++){for(int j=0;j<right[i].size();j++){if(!right[i].empty())cout<<right[i][j];}if(!right[i].empty())cout<<endl;}//empty answers are not printed

// }

//NW (Erase)
// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// int j=1,l,lc=0;
// char ch;
// void solution(string str,vector<vector<int>>&right,vector<vector<int>>&left){ 
//   if(str.length()==0)return;
//   if(str[0]!=ch){for(int i=0;i<right.size();i++){
//     right[i].push_back((str[0]-'0'));
//   }}
//   else {
//     cout<<"else condiiron hit"<<endl;
//     cout<<"ch = "<<ch<<endl;
//     lc=(left.size()/2);
//     for(int k=0;k<lc;k++)right.erase(right.begin()+lc);
//     for(int i=0;i<right.size();i++){
//       right[i].push_back((str[0]-'0'));
//   }
//   }
//   for(int i=0;i<right.size();i++){
//     left.push_back(right[i]);
//   }
//   right=left;
//   ch=str[0];
//   str.erase(0,1);
//   j++;
//   solution(str,right,left);
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   ch='z';
//   l=str.length();
//   vector<vector<int>>right(1);
//   vector<vector<int>>left(1);
//   solution(str,right,left);
//   cout<<"Sets are : "<<endl;
//   for(int i=0;i<right.size();i++){for(int j=0;j<right[i].size();j++){cout<<right[i][j];}cout<<endl;}

// }