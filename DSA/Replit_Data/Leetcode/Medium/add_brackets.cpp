//divide and conquer q

// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int>final_ans;
// vector<string>char_present(string str){
//   string temp="";
//   vector<string>num_given;
//   while(!str.empty()){
//     if(str[0]<='9'&&str[0]>='0'){
//       // int n=str[0]-'0';
//       num_given.push_back(temp+str[0]);
//     } 
//     str.erase(0,1);
//   }
//   return num_given;
// }
// vector<string>sign_present(string str){
//   string temp="";
//   vector<string>sign_given;
//   while(!str.empty()){
//     if(str[0]>='9'||str[0]<='0'){
//       sign_given.push_back(temp+str[0]);
//     } 
//     str.erase(0,1);
//   }
//   return sign_given;
// }
// vector<int> solve(string str,string ans="("){
//   vector<int>test;
//   static vector<string>nums=char_present(str);
//   static vector<string>signs=sign_present(str);
//   static int n=signs.size() ;
//   for(int i=0;i<nums.size();i++){
//     for(int j=)
//   }
// }
// int main(){
//   string str;
//   cout<<"Enter expression : ";
//   cin>>str;
//   vector<int>ans= solve(str);
// }


// // cout<<"NUmbers given are : ";
// // for(int i=0;i<nums.size();i++)cout<<nums[i]<<endl;
// // cout<<"Signs given are : ";
// // for(int i=0;i<signs.size();i++)cout<<signs[i]<<endl;
// // return test;