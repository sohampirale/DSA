// //  Practice

// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string>final_ans;
// int permutations(string str,string ans=""){
//   int cnt=0;
//   if(str.empty()){
//     final_ans.push_back(ans);
//     return 1;
//   }
//   for(int i=0;i<str.length();i++){
//     string temp=str;
//     temp.erase(i,1);
//     cnt+=permutations(temp,ans+str[i]);
//     // cnt+=permutations(temp,ans);        //for sets+permutations
//   }
//   return cnt;
// }

// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   int ans=permutations(str);
//   cout<<"Number of permutations possible are : "<<ans<<endl;
//   cout<<"Permutations are : "<<endl;
//   for(int i=0;i<final_ans.size();i++){
//     cout<<final_ans[i]<<endl;
//   }
// }

// // #include<iostream>
// #include<vector>
// using namespace std;
// // No for loop used 
// void permutations(string str,vector<string>&final_ans,string ans,int i=0,int j=0);
// void transform(string str,vector<string>&final_ans,string ans,int i);
// //for loop used
// void permutations_forloop(string str,string ans,vector<string>&final_ans,int i);
// //no of permutations possible int 
// int permutations_cnt(string str,string ans,int i=0);



// int permutations_cnt(string str,string ans,int i){
//     ans.insert(ans.begin()+i,(str[0]));
//     str.erase(0,1);
//     if(str.length()==0){return 1;}
//     int cnt=0;
//     for(int j=0;j<=ans.length();j++){
//     cnt+=permutations_cnt(str,ans,j);
//     }
//   return cnt;
// }
// void transform(string str,vector<string>&final_ans,string ans,int i){
//   if(i<=ans.length()){permutations(str,final_ans,ans,i);i++;}
//   if(i<=ans.length())transform(str,final_ans,ans,i);
// }

// void permutations(string str,vector<string>&final_ans,string ans,int i,int j){
//     ans.insert(ans.begin()+i,str[0]);
//     str.erase(0,1);
//   if(str.length()==0){final_ans.push_back(ans);return;}
//   transform(str,final_ans,ans,0);
// }

// void permutations_forloop(string str,string ans,vector<string>&final_ans,int i){
//     ans.insert(ans.begin()+i,(str[0]));
//     str.erase(0,1);
//     if(str.length()==0){final_ans.push_back(ans);return;}
//     for(int j=0;j<=ans.length();j++){
//     permutations_forloop(str,ans,final_ans,j);
//     }
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   vector<string>final_ans(1,"");
//   permutations(str,final_ans,"");
//   cout<<"Answer is : "<<endl;
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }























//Shortest answer
// #include<iostream>
// #include<vector>
// using namespace std;

// void permutations(string str,string ans,vector<string>&final_ans,int i=0);
// void transfer(string str,string ans,vector<string>&final_ans,int i);
// int test=0;

// void permutations(string str,string ans,vector<string>&final_ans,int i){
//     ans.insert(ans.begin()+i,(str[0]));
//     str.erase(0,1);
//     if(str.length()==0){final_ans.push_back(ans);return;}
//     for(int j=0;j<=ans.length();j++){
//     permutations(str,ans,final_ans,j);
//     }
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   vector<string>final_ans;
//   permutations(str,"",final_ans);
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }

//no. of permutations


// #include<iostream>
// #include<vector>
// #include<string>
// using namespace std;

// int permutations_cnt(string str,string ans,int i=0);
// int permutations_cnt(string str,string ans,int i){
//     ans.insert(ans.begin()+i,(str[0]));
//     str.erase(0,1);
//     if(str.length()==0){return 1;}
//     int cnt=0;
//     for(int j=0;j<=ans.length();j++){
//     cnt+=permutations_cnt(str,ans,j);
//     }
//   return cnt;
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   vector<int>final_ans(1,0);
//   cout<<"No. of permutations are : "<<permutations_cnt(str,"")<<endl;
// }

// #include<iostream>
// #include<vector>
// #include<string>
// using namespace std;

// void permutations(string str,string ans,vector<int>&final_ans,int i=0);
// int test=0;

// void permutations(string str,string ans,vector<int>&final_ans,int i){
//   cout<<"hey"<<endl;
//     ans.insert(ans.begin()+i,(str[0]));
//     str.erase(0,1);
//     if(str.length()==0){cout<<"here";int a=stoi(ans);final_ans.push_back(a);cout<<"saved";return;}
//     for(int j=0;j<=ans.length();j++){
//     permutations(str,ans,final_ans,j);
//     }
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   vector<int>final_ans(1,0);
//   permutations(str,"",final_ans);
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }

//lengthy soln
// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string>final_ans;
// int test=0;
// void permutations(string str,string ans="",int i=0);
// void transfer(string str,string ans,int &i,int &j);
// int main(){
//   string str;
//   cout<<"Enter a string : ";
//   cin>>str;
//   permutations(str,"",0);
//   for(int i=0;i<final_ans.size();i++) cout<<final_ans[i]<<endl;
//   cout<<"answer finished"<<endl;
// }
// void transfer(string str,string ans,int &i,int &j){
//   if(i==0){i++;j++;permutations(str,ans,i);  
//   }
//     else {
//       j++;
//       // if(str=="abc")cout<<"J = "<<j<<endl;
//       i++;
//       // if(j==2)cout<<"ja became 2"<<endl;
//       permutations(str,ans,j);
//     }
//   if(j!=str.length())transfer(str,ans,i,j);
// }
// void permutations(string str,string ans,int i){
//   if(i>=str.length()){return;}
//   if(test!=0){
//     ans.push_back(str[i]);
//     str.erase(i,1);
//   }
//   // if(ans=="c")cout<<"c case reached"<<endl;
//   test=1; 
//   if(str.length()==0){final_ans.push_back(ans);return;}
//   int j=0;
//   permutations(str,ans,j);
//   transfer(str,ans,i,j);
  
// }

//  // 2 fucntions used soln (no for loop used)

// #include<iostream>
// #include<vector>
// using namespace std;

// void permutations(string str,string ans,vector<string>&final_ans,int i=0);
// void transfer(string str,string ans,vector<string>&final_ans,int i);
// // int test=0;
// void transfer(string str,string ans,vector<string>&final_ans,int i){
//   permutations(str,ans,final_ans,i);
//   i++;
//   if(i<=ans.length())transfer(str,ans,final_ans,i);
// }
// void permutations(string str,string ans,vector<string>&final_ans,int i){
//   // if(test!=0){    //this is not needed in this example 
//     ans.insert(ans.begin()+i,(str[0]));
//     str.erase(0,1);
//   // }
//   // test=1;
//   if(str.length()==0){final_ans.push_back(ans);return;}
//   // permutations(str,ans,final_ans,i);
//   transfer(str,ans,final_ans,0);
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   vector<string>final_ans;
//   permutations(str,"",final_ans);
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }


// #include<iostream>
// #include<vector>
// using namespace std;

// void permutations(string str,string ans,vector<string>&final_ans,int i=0);
// void transfer(string str,string ans,vector<string>&final_ans,int i);
// int test=0;

// void permutations(string str,string ans,vector<string>&final_ans,int i){
//     ans.insert(ans.begin()+i,(str[0]));
//     str.erase(0,1);
//     if(str.length()==0){final_ans.push_back(ans);return;}
//     for(int j=0;j<=ans.length();j++){
//     permutations(str,ans,final_ans,j);
//     }
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   vector<string>final_ans;
//   permutations(str,"",final_ans);
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }