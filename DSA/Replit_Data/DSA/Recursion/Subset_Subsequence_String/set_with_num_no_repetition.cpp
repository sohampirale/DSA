// //PRACTICE

// #include<iostream>
// #include<vector>
// #include<string>
// using namespace std;

// void sets(string str,char ch,vector<string>&left,vector<string>&right){
//   // left.push_back(right);
//   for(int i=0;i<right.size();i++)left.push_back(right[i]);
  
  
//   if(str.empty()){
//     // right=left;
//     return;
//   }
  
//   if(str[0]!=ch)right=left;
  
//   for(int i=0;i<right.size();i++){
//     right[i]+=str[0];
//     // right[i].push_back(str[0]);
//   }
//   ch=str[0];
//   str.erase(0,1);
//   sets(str,ch,left,right);
// }
// int main(){
//   vector<string>left(1);
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   vector<string>right(1,string(1,str[0]));
//   char ch=str[0];
//   str.erase(0,1);
//   sets(str,ch,left,right);
//   cout<<"All the sets possible without repitition are :"<<endl;
//   for(int i=0;i<left.size();i++)cout<<left[i]<<endl;
// }



// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<string>
// using namespace std;
// vector<char>existing;


// void show_left(vector<string>&left){
//   for(int k=0;k<left.size();k++){
//     cout<<left[k]<<endl;
//   }
//   cout<<"left complete"<<endl;
// }
// // void solution(string str,vector<vector<string>>&right,vector<vector<string>>&left,int j=0){ 
// //  for(int i=0;i<right[j].size();i++){
// //    left[j].push_back(right[j][i]);
// //  }
// //   if(str.length()==0)return;
// //   char ch=str[0];
// //   if(find(existing.begin(),existing.end(),ch)==existing.end()){
// //     existing.push_back(ch);
// //     right=left;
// //   }
// //   for(int i=0;i<right[j].size();i++){
// //     right[j][i].push_back(str[0]);
// //   }
// //   str.erase(1,0);
// //   solution(str,right,left);
// // }
// void solution(string str,vector<string>&right,vector<string>&left){ 
//  for(int i=0;i<right.size();i++){
//    left.push_back(right[i]);
//  }
//   // show_left(left);
  
//   if(str.length()==0)return;
//   char ch=str[0];
//   if(find(existing.begin(),existing.end(),ch)==existing.end()){
//     existing.push_back(ch);
//     right=left;
//   }
//   for(int i=0;i<right.size();i++){
//     right[i].push_back(str[0]);
//   }
//   str.erase(0,1);
//   cout<<"length of str = "<<str.length()<<endl;
//   solution(str,right,left);
// }
// int main(){
//   string str;
//   cout<<"Enter string : ";
//   cin>>str;
//   vector<string>right(1,"");
//   vector<string>left(1,"");
//   right[0]=str[0];
//   left[0]="";
//   existing.push_back(str[0]);
//   str.erase(0,1);
//   solution(str,right,left);
//   cout<<"Solution is : "<<endl;
//   for(int i=0;i<left.size();i++)cout<<left[i]<<endl;
//   cout<<"Answer finished"<<endl;
//   return 0;
// }