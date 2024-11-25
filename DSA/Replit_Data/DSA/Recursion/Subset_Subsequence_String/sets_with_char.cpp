// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   string print;
//   for(int k=0;k<str.length()-1;k++){//first-char
//     print=str[k];
//     cout<<print<<endl;
//   for(int i=k;i<str.length()-1;i++){//concatenate
//     for(int j=i+1;j<str.length();j++){//jump
//       // if(j==i)cout<<"condition "<<print<<endl;
//       cout<<print<<str[j]<<endl;
//     }
//     print+=str[i+1];
//   }
//   }
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string>final_ans;
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   string print;
//   for(int k=0;k<str.length()-1;k++){//first-char
//     print=str[k];
//     // cout<<print<<endl;
//     final_ans.push_back(print);
//   for(int i=k;i<str.length()-1;i++){//concatenate
//     for(int j=i+1;j<str.length();j++){//jump
//       // if(j==i)cout<<"condition "<<print<<endl;
//       // cout<<print<<str[j]<<endl;
//       final_ans.push_back(print+str[j]);
//     }
//     print+=str[i+1];
//   }
//   }
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
// }

//  Not correct
// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//   string str;
//   vector<string>ans;
//   cout<<"Enter string : ";
//   cin>>str;
//   string print;
//   int add;
//   for(int k=0;k<str.length()-1;k++){//first-char
//     print=str[k];
//     add=static_cast<int>(str[k]);
//     ans.push_back(print);
//     // cout<<print<<endl;
//   for(int i=k;i<str.length()-1;i++){//concatenate
//     for(int j=i+1;j<str.length();j++){//jump
//       // if(j==i)cout<<"condition "<<print<<endl;
//       ans.push_back(print+str[j]);
//       ans.push_back(print+to_string(static_cast<int>(str[j])));
//       ans.push_back(to_string(add)+str[j]);
//       ans.push_back(to_string(add)+to_string(static_cast<int>(str[j])));
//       // cout<<print<<str[j]<<endl;
//     }
//     print+=str[i+1];
//   }
//   }
//   cout<<"All the sets from "<<str<<" are : "<<endl;
//   for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
// }


// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// vector<string>final_ans;
// void print_set(string &str,int i,int j,int k,string print){
//   // if(i==str.length()-1)return;
//   // j=i;
//   // k=j+1;
//   // if(k==str.length()){print+=str[j+1];}
// }
// // string consider(string str){
// //   string ans1,ans2;
// //   if(str.length()==1){
// //     ans1=str[0];
// //     return ans1;
// //   }
// //   str.pop_back();
// //   string temp1=consider(str);
// //   string temp2=consider(str);
// // }
// // string not_consider(string str){
// //   string ans1,ans2;
// //   if(str.length()==1){
// //     ans2="";
// //     return ans2;
// //   }

// string consider(string str){
//   string ans1,ans2;
//   if(str.length()==1){
//     ans1=str[0];
//     return ans1;
//   }
//   str.pop_back();
//   string temp1=consider(str);
//   string temp2=consider(str);
// }
// string not_consider(string str){
//   string ans1,ans2;
//   if(str.length()==1){
//     ans2="";
//     return ans2;
//   }
//   str.pop_back();
//   string temp1=consider(str);
//   string temp2=consider(str);
//   if(str.length()==0)return;
// }
// string set(string str){
//   consider(str);
//   not_consider(str);
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   string print;
//   reverse(str.begin(),str.end());
//   set(str);
//   cout<<"All the sets from "<<str<<" are : "<<endl;
//   for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
// }

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// vector<string>final_ans;
// void consider(string str,string ans);
// void not_consider(string str,string ans);
// void set(string str,string ans);

// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   set(str,"");
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
// }

// void set(string str,string ans){
//   consider(str,ans);
//   not_consider(str,ans);
// }
// void consider(string str,string ans){

//   ans.push_back(str[0]);
//   final_ans.push_back(ans);
//   if(str.length()==1)return ;
//   // str.pop_back();
//   str.erase(0,1);
//   consider(str,ans);
//   not_consider(str,ans);
// }
// void not_consider(string str,string ans){
//   // str.pop_back();
//   // final_ans.push_back(ans);
//   if(str.length()==1)return;
//   str.erase(0,1);
//   consider(str,ans);
//   not_consider(str,ans);
// }

//with 3 functions

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// vector<string>final_ans;
// void consider(string str,string ans);
// void not_consider(string str,string ans);
// void set(string str,string ans);

// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   set(str,"");
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   final_ans.clear();
//   cout<<"after claring"<<endl;
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
// }

// void set(string str,string ans){
//   consider(str,ans);
//   not_consider(str,ans);
// }

// void consider(string str,string ans){
//   ans.push_back(str[0]);
//   str.erase(0,1);
//   if(str.length()==0){final_ans.push_back(ans);return ;}
//   consider(str,ans);
//   not_consider(str,ans);
// }

// void not_consider(string str,string ans){
//   str.erase(0,1);
//   if(str.length()==0){final_ans.push_back(ans);return;}
//   consider(str,ans);
//   not_consider(str,ans);
// }

//with one fucntion

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// vector<string>final_ans;
// void consider(string str,string ans);
// void not_consider(string str,string ans);
// void set(string str,string ans,int i);

// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   set(str,"",1);
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   final_ans.clear();
//   cout<<"after claring"<<endl;
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
// }

// void set(string str,string ans,int i){
//   if(str.length()==0){final_ans.push_back(ans);return ;}
//   char ch=str[0];
//   str.erase(0,1);
//   set(str,ans+ch,1);
//   set(str,ans,2);
// }


//ASCII valued inlucded sets

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// vector<string>final_ans;
// void consider(string str,string ans);
// void not_consider(string str,string ans);
// void set(string str,string ans,int i);

// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   set(str,"",1);
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   final_ans.clear();
//   cout<<"after clearing"<<endl;
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
// }

// void set(string str,string ans,int i){
//   if(str.length()==0){if(!ans.empty())final_ans.push_back(ans);return ;}
//   char ch=str[0];
//   str.erase(0,1);
//   set(str,ans+ch,1);
//   set(str,ans+" "+to_string(ch+0),3);
//   set(str,ans,2);
//   // int a=static_cast<int>(ch);
//   // set(str,ans+" "+to_string(static_cast<int>(ch)),3);
// }
