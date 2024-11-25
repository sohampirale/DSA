// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string> solution(vector<string>work,string ans="",int i=0){
//   static vector<string>final_ans;
//   if(i==work.size()){
//     final_ans.push_back(ans);
//     return final_ans;
//   }
//   for(int j=0;j<work[i].length();j++){
//     char ch=work[i][j];
//     return solution(work,ans+ch,i+1);
//   }
//   return final_ans;
// }
// int main(){
//   vector<string> charcaters={"","","abc","def","ghi","jkl","mnop","qrst","uvw","xyz"};
//   string input;
//   cout<<"Enter numbers : ";
//   cin>>input;
//   vector<string>work;
//   for(int i=0;i<input.length();i++){
//     work.push_back(charcaters[input[i]-'0']);
//   }
//   vector<string>ans=solution(work);
//   cout<<"Answer becomes :"<<endl;
//   for(int i=0;i<work.size();i++)cout<<ans[i]<<endl;
// }


// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string>final_ans;

// void solution(vector<string>&work,string ans="",int i=0){
//   if(i==work.size()){
//     final_ans.push_back(ans);
//     return;
//   }
//   char ch;
//   for(int j=0;j<work[i].length();j++){
//     ch=work[i][j];
//     solution(work,ans+ch,i+1);
//   }
// }
// int main(){
//   vector<string> charcaters={" "," ","abc","def","ghi","jkl","mnop","qrst","uvw","xyz"};
//   string input;
//   cout<<"Enter numbers : ";
//   cin>>input;
//   vector<string>work;
//   for(int i=0;i<input.length();i++){
//     work.push_back(charcaters[input[i]-'0']);
//   }
//   cout<<"Work becomes : "<<endl;
//   for(int i=0;i<work.size();i++){
//     cout<<work[i]<<endl;
//   }
//   solution(work);
//   cout<<"Answer becomes :"<<endl;
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
// }

//  All answers in 1 code

// #include<iostream>
// #include<vector>
// using namespace std;
// int test=0;
// int k=-1;


// //first method -(1st calculate done then later calculatiosn are call forth)-(call permutations fucntion from main)

// void permutations(vector<string>&work,vector<string>&final_ans,string ans,int i=-1,int j=0);
// void transform(vector<string>&work,vector<string>&final_ans,string ans,int i,int j);


// //My solution(no loops used)
// void solution1(vector<string>&work,vector<string>&final_ans,string ans,int i=-1,int j=0);
// void solutionHori1(vector<string>&work,vector<string>&final_ans,string ans,int i,int j);
// //using for loop
// void solution2(vector<string>&work,vector<string>&final_ans,string ans,int i=-1,int j=0);

// //using while loop
// void solution3(vector<string>&work,vector<string>&final_ans,string ans,int i=-1,int j=0);




// void transform(vector<string>&work,vector<string>&final_ans,string ans,int i,int j){
//   if(j<work[i].length()){permutations(work,final_ans,ans,i,j);j++;}
//   if(j<work[i].length())transform(work,final_ans,ans,i,j);
// }
// void permutations(vector<string>&work,vector<string>&final_ans,string ans,int i,int j){
//   if(test!=0){
//     ans.push_back(work[i][j]);
//   }
//   test=1;
//   if(i==work.size()-1){final_ans.push_back(ans);return;}
//   transform(work,final_ans,ans,i+1,0);
// }


// void solution3(vector<string>&work,vector<string>&final_ans,string ans,int i,int j){
//   if(k!=-1){
//       ans.push_back(work[i][j]);
//     }
//     k=0;
//     int l=0;
//     if(i==work.size()-1){final_ans.push_back(ans);return;}
//     while(l<work[i+1].size()){
//       solution3(work,final_ans,ans,i+1,l);
//       l++;
//     }
//   }



// void solution2(vector<string>&work,vector<string>&final_ans,string ans,int i,int j){
//   if(k!=-1){
//     ans.push_back(work[i][j]);
//   }
//   k=0;
//   if(i==work.size()-1){final_ans.push_back(ans);return;}
//   for(int l=0;l<work[i+1].size();l++){
//     solution2(work,final_ans,ans,i+1,l);
//   }
// }

// void solutionHori1(vector<string>&work,vector<string>&final_ans,string ans,int i,int j){
//   if(j<work[i].size()){solution1(work,final_ans,ans,i,j);j++;}
//   if(j<work[i].size())solutionHori1(work,final_ans,ans,i,j);
// }

// void solution1(vector<string>&work,vector<string>&final_ans,string ans,int i,int j){
//   if(test!=0){
//     ans.push_back(work[i][j]);
//   }
//   test=1;
//   if(i==work.size()-1){final_ans.push_back(ans);return;}
//   solution1(work,final_ans,ans,i+1,0);
//   solutionHori1(work,final_ans,ans,i+1,1);
// }

// int main(){
//   vector<string>characters={"","","abc","def","ghi","jkl","mno","pqrs","tuvw","xyz"};
//   string input;
//   cout<<"Enter input : ";
//   cin>>input;
//   vector<string>work;
//   vector<string>final_ans;
//   for(int i=0;i<input.length();i++){
//     string str=characters[input[i]-'0'];
//     work.push_back(str);
//   }
//   // cout<<"Work size = "<<work.size()<<endl;

//   // for(int i=0;i<work.size();i++){
//   //   cout<<work[i]<<endl;
//   // }
//   int choice;
//   cout<<"Enter which method you want to try : ";
//   cin>>choice;
//   switch(choice){
//     case 1 : solution1(work,final_ans,"");
//     break;
//     case 2 : solution2(work,final_ans,"" );
//     break;
//     case 3 : solution3(work,final_ans,"");
//     break;
//     case 4 : permutations(work,final_ans,"");
//     break;
//     default : cout<<"Enter between 1-4"<<endl;
//   }
//   for(int i=0;i<final_ans.size();i++){
//     cout<<final_ans[i]<<endl;
//   }
//   cout<<"Answer finished"<<endl;
// }



// #include<iostream>
// #include<vector>
// using namespace std;
// int test=0;
// void solution(vector<string>&work,vector<string>&final_ans,string ans,int i=-1,int j=0);
// void solutionHori(vector<string>&work,vector<string>&final_ans,string ans,int i,int j);

// void solutionHori(vector<string>&work,vector<string>&final_ans,string ans,int i,int j){
//   if(j<work[i].size()){solution(work,final_ans,ans,i,j);j++;}
//   if(j<work[i].size())solutionHori(work,final_ans,ans,i,j);
// }

// void solution(vector<string>&work,vector<string>&final_ans,string ans,int i,int j){
//   if(test!=0){
//     ans.push_back(work[i][j]);
//   }
//   test=1;
//   if(i==work.size()-1){final_ans.push_back(ans);return;}
//   solution(work,final_ans,ans,i+1,0);
//   solutionHori(work,final_ans,ans,i+1,1);
// }

// int main(){
//   vector<string>characters={"","","abc","def","ghi","jkl","mno","pqrs","tuvw","xyz"};
//   string input;
//   cout<<"Enter input : ";
//   cin>>input;
//   vector<string>work;
//   vector<string>final_ans;
//   for(int i=0;i<input.length();i++){
//     string str=characters[input[i]-'0'];
//     work.push_back(str);
//   }
//   // cout<<"Work size = "<<work.size()<<endl;
  
//   // for(int i=0;i<work.size();i++){
//   //   cout<<work[i]<<endl;
//   // }
//   solution(work,final_ans,"");
//   for(int i=0;i<final_ans.size();i++){
//     cout<<final_ans[i]<<endl;
//   }
//   cout<<"Answer finished"<<endl;
// }



// #include<iostream>
// #include<vector>
// using namespace std;
// int k=-1;
// void solution(vector<string>&work,vector<string>&final_ans,string ans,int i=-1,int j=0);


// void solution(vector<string>&work,vector<string>&final_ans,string ans,int i,int j){
//   if(k!=-1){
//     ans.push_back(work[i][j]);
//   }
//   k=0;
//   if(i==work.size()-1){cout<<"Reached here"<<endl;final_ans.push_back(ans);return;}
//   for(int l=0;l<work[i+1].size();l++){
//     solution(work,final_ans,ans,i+1,l);
//   }
// }

// //DW
// // void solution(vector<string>&work,vector<string>&final_ans,string ans,int i,int j){
// //   if(k!=-1){
// //     ans.push_back(work[i][j]);
// //   }
// //   k=0;
// //   if(i==work.size()-1){cout<<"Reached here"<<endl;final_ans.push_back(ans);return;}
// //   while(k<work[i+1].size()){
// //     solution(work,final_ans,ans,i+1,k);
// //     k++;
// //   }
// //   k=0;
// // }

// void solution(vector<string>&work,vector<string>&final_ans,string ans,int i,int j){
//   if(k!=-1){
//     ans.push_back(work[i][j]);
//   }
//   k=0;
//   int l=0;
//   if(i==work.size()-1){cout<<"Reached here"<<endl;final_ans.push_back(ans);return;}
//   while(l<work[i+1].size()){
//     solution(work,final_ans,ans,i+1,l);
//     l++;
//   }
//   // k=0;
// }

// int main(){
//   vector<string>characters={"","","abc","def","ghi","jkl","mno","pqrs","tuvw","xyz"};
//   string input;
//   cout<<"Enter input : ";
//   cin>>input;
//   vector<string>work;
//   vector<string>final_ans;
//   for(int i=0;i<input.length();i++){
//     string str=characters[input[i]-'0'];
//     work.push_back(str);
//   }
  
//   // cout<<"Work size = "<<work.size()<<endl;
//   // for(int i=0;i<work.size();i++){
//   //   cout<<work[i]<<endl;
//   // }
  
//   solution(work,final_ans,"");
//   cout<<"Answer : "<<endl;
//   for(int i=0;i<final_ans.size();i++){
//     cout<<final_ans[i]<<endl;
//   }
//   cout<<"Answer finished"<<endl;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// int test=0;
// void permutations(vector<string>&work,vector<string>&final_ans,string ans,int i,int j);
// void transform(vector<string>&work,vector<string>&final_ans,string ans,int i,int j);

// void transform(vector<string>&work,vector<string>&final_ans,string ans,int i,int j){
//   if(j<work[i].length()){permutations(work,final_ans,ans,i,j);j++;}
//   if(j<work[i].length())transform(work,final_ans,ans,i,j);
// }
// void permutations(vector<string>&work,vector<string>&final_ans,string ans,int i,int j){
//   if(test!=0){
//     ans.push_back(work[i][j]);
//   }
//   test=1;
//   if(i==work.size()-1){final_ans.push_back(ans);return;}
//   transform(work,final_ans,ans,i+1,0);
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   vector<string>final_ans;
//   vector<string>characters={"","","abc","def","ghi","jkl","mno","pqrt","tuvw","xyz"};
//   vector<string>work;
//   for(int i=0;i<str.length();i++){
//     work.push_back(characters[str[i]-'0']);
//   }
//   cout<<"Size of work is : "<<work.size()<<endl;
//   for(int i=0;i<work.size();i++)cout<<work[i]<<endl;
//   permutations(work,final_ans,"",-1,0);
//   cout<<"All the permutations are : "<<endl;
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// int test=0,cnt=0;
// void solution(vector<string>&work,vector<string>&final_ans,string ans,int i=-1,int j=0);
// void solutionHori(vector<string>&work,vector<string>&final_ans,string ans,int i,int j);

// void solutionHori(vector<string>&work,vector<string>&final_ans,string ans,int i,int j){
//   if(j<work[i].size()){solution(work,final_ans,ans,i,j);j++;}
//   if(j<work[i].size())solutionHori(work,final_ans,ans,i,j);
// }
// void solution(vector<string>&work,vector<string>&final_ans,string ans,int i,int j){
//   if(test!=0){
//     ans.push_back(work[i][j]);
//   }
//   test=1;
//   if(i==work.size()-1){cnt++;return;}
//   solution(work,final_ans,ans,i+1,0);
//   solutionHori(work,final_ans,ans,i+1,1);
// }
// int main(){
//   vector<string>characters={"","","abc","def","ghi","jkl","mno","pqrs","tuvw","xyz"};
//   string input;
//   cout<<"Enter input : ";
//   cin>>input;
//   vector<string>work;
//   vector<string>final_ans;
//   for(int i=0;i<input.length();i++){
//     string str=characters[input[i]-'0'];
//     work.push_back(str);
//   }
//   // cout<<"Work size = "<<work.size()<<endl;

//   // for(int i=0;i<work.size();i++){
//   //   cout<<work[i]<<endl;
//   // }
//   solution(work,final_ans,"");
//   cout<<"Number of possible ways are : "<<cnt<<endl;
//   // for(int i=0;i<final_ans.size();i++){
//   //   cout<<final_ans[i]<<endl;
//   // }
//   cout<<"Answer finished"<<endl;
// }

// #include <iostream>
// #include <vector>
// #include <string>
// #include <stack>

// using namespace std;

// struct State {
//     string ans;
//     int index;
// };

// int main() {
//     vector<string> characters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuvw", "xyz"};
//     string input;
//     cout << "Enter input: ";
//     cin >> input;

//     vector<string> work;
//     for (char c : input) {
//         if (isdigit(c) && c != '0' && c != '1') {
//             work.push_back(characters[c - '0']);
//         }
//     }

//     if (work.empty()) {
//         cout << "No valid input." << endl;
//         return 0;
//     }

//     stack<State> stk;
//     stk.push({"", 0});

//     int cnt = 0;
//     vector<string> final_ans;

//     while (!stk.empty()) {
//         State current = stk.top();
//         stk.pop();

//         if (current.index == work.size()) {
//             final_ans.push_back(current.ans);
//             cnt++;
//             continue;
//         }

//         for (char c : work[current.index]) {
//             stk.push({current.ans + c, current.index + 1});
//         }
//     }

//     cout << "Number of possible ways are: " << cnt << endl;
//     cout << "Answer finished" << endl;
//     return 0;
// }
