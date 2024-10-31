// #include<iostream>
// #include<algorithm>
// using namespace std;
// void test(string &str,string& cut,string & not_cut,int i=0){
//   if(i>=str.length())return;
//   string temp=str.substr(i,cut.length()+cut.length());
//   int ci=temp.find(cut),nci=temp.find(not_cut);
//   cout<<"temp = "<<temp<<endl;
//   cout<<"ci = "<<ci<<" nci = "<<nci<<endl;
//   if((ci>=0)&&(nci==-1)&&temp.length()>=cut.length()){
//     cout<<"Condition hit"<<endl;
//     str.erase(ci+i,cut.length());
//   } else if(nci>-1){
//     i+=not_cut.length();
//   }else i++;
//   test(str,cut,not_cut,i);
// }
// int main(){
//   string str,cut,not_cut;
//   cout<<"Enter string : ";
//   cin>>str;
//   cout<<"Enter substring which you want to remmove : ";
//   cin>>cut;
//   cout<<"Enter the substring which you don't want to remove : ";
//   cin>>not_cut;
//   // int i=str.find(cut);
//   // cout<<i<<endl;
//   test(str,cut,not_cut);
//   cout<<str<<endl;
// }


// #include<iostream>
// using namespace std;
// void remove_substr(string& str,string& substr,int i){
//   if(i==str.length())return;
//   if(str[i]==substr[0]){
//     string temp=str.substr(i,substr.length());
//     if(temp==substr){str.erase(i,substr.length());}
//   }
//   remove_substr(str,substr,i+1);
// }
// int main(){
//   string str,substr;
//   cout<<"Enter string : ";
//   cin>>str;
//   cout<<"Enter the substring you want to remove : ";
//   cin>>substr;
//   remove_substr(str,substr,0);
//   cout<<"After removing substring thr string becomes : "<<str<<endl;
// }

// Enter string : applebananaapplapplee
// Enter the substring you want to remove : apple
// After removing substring thr string becomes : bananaapple


// #include<iostream>
// #include<algorithm>
// using namespace std;
// void remove_substr(string& str,string& substr,int i){
//   if(i>=str.length())return;
//   if(tolower(str[i])==substr[0]||toupper(str[i])==substr[0]){
//     cout<<"Conditionn hit when str[i] = "<<str[i]<<endl;
//     string temp=str.substr(i,substr.length());
//     cout<<"Temp = "<<temp<<endl;
//     temp[0]=toupper(temp[0]);
//     if(temp==substr){
//       str.erase(i,substr.length());
//       remove_substr(str,substr,i);
//     } else {
//       temp[0]=tolower(temp[0]);
//       if(temp==substr){str.erase(i,substr.length());remove_substr(str,substr,i);}
//       else remove_substr(str,substr,i+1);
//     } 
//   } else remove_substr(str,substr,i+1);
// }
// int main(){
//   string str,substr;
//   cout<<"Enter string : ";
//   cin>>str;
//   cout<<"Enter the substring you want to remove : ";
//   cin>>substr;
//   remove_substr(str,substr,0);
//   cout<<"After removing substring thr string becomes : "<<str<<endl;
// }
// #include <iostream>
// #include <string>
// #include <algorithm>  // Include the algorithm header for std::equal

// using namespace std;

// bool startsWith(const string& str, const string& prefix) {
//     if (prefix.size() > str.size()) {
//         return false;  // If the prefix is longer than the string, it can't be a prefix.
//     }
//     return equal(prefix.begin(), prefix.end(), str.begin());  // Compare the prefix with the beginning of the string.
// }
// string str = "helloworld";
// string prefix = "world";
// int main() {
//     if (startsWith(str, prefix)) {
//         cout << "The string starts with the prefix." << endl;
//     } else {
//         cout << "The string does not start with the prefix." << endl;
//       // main();
//     }
//     return 0;
// }



// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//   string str;
//   cout<<"Enter a string : ";
//   cin>>str;
//   cout<<"Enter substring : ";
//   string substr;
//   cin>>substr;
//   int i=1;
//   bool ans=equal(substr.begin(),substr.end(),str.begin()+i);
// cout<<  (ans? "same" : "false");
//   // else cout<<"Different";
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// void remove_substr(string& str,string& substr,int i){
//   if(i>=str.length())return;
//   if(equal(substr.begin(),substr.end(),str.begin()+i)){str.erase(i,substr.length());remove_substr(str,substr,i);}
//   else remove_substr(str,substr,i+1);
// }
// int main(){
//  string str,substr;
//   cout<<"Enter string : ";
//   cin>>str;
//   cout<<"Enter Substring : ";
//   cin>>substr;
//   remove_substr(str,substr,0);
//   cout<<str<<endl;
// }


// #include<iostream>
// #include<vector>
// using namespace std;
// void remove_substr(string& str,string& substr,int i){
//   if(i>=str.length())return;
//   if(toupper(str[i])==substr[0]||tolower(str[i])==substr[0]){if(equal(substr.begin(),substr.end(),str.begin()+i)){str.erase(i,substr.length());remove_substr(str,substr,i);} 
// else remove_substr(str,substr,i+1);}
//   else remove_substr(str,substr,i+1);
// }
// int main(){
//  string str,substr;
//   cout<<"Enter string : ";
//   cin>>str;
//   cout<<"Enter Substring : ";
//   cin>>substr;
//   remove_substr(str,substr,0);
//   cout<<str<<endl;
// }

// #include<iostream>
// #include<algorithm>
// using namespace std;
// void test(string &str,string& cut,string & not_cut,int i=0){
//   if(i>=str.length())return;
//   if(equal(not_cut.begin(),not_cut.end(),str.begin()+i)){
//     test(str,cut,not_cut,i+not_cut.length());
//   } else if(equal(cut.begin(),cut.end(),str.begin()+i)){
//     str=str.erase(i,cut.length());
//     test(str,cut,not_cut,i);
//   } else test(str,cut,not_cut,i+1);
// }
// int main(){
//   string str,cut,not_cut;
//   cout<<"Enter string : ";
//   cin>>str;
//   cout<<"Enter substring which you want to remmove : ";
//   cin>>cut;
//   cout<<"Enter the substring which you don't want to remove : ";
//   cin>>not_cut;
//   test(str,cut,not_cut);
//   cout<<str<<endl;
// }

// #include<iostream>
// #include<algorithm>
// using namespace std;
// void test(string &str,string& cut,string & not_cut,int i=0){
//   if(i>=str.length())return;
//   if(equal(not_cut.begin(),not_cut.end(),str.begin()+i)){
//     i+=not_cut.length();
//   } else if(equal(cut.begin(),cut.end(),str.begin()+i)){
//     str=str.erase(i,cut.length());
//   } else i++;
//   test(str,cut,not_cut,i);
// }
// int main(){
//   string str,cut,not_cut;
//   cout<<"Enter string : ";
//   cin>>str;
//   cout<<"Enter substring which you want to remmove : ";
//   cin>>cut;
//   cout<<"Enter the substring which you don't want to remove : ";
//   cin>>not_cut;
//   test(str,cut,not_cut);
//   cout<<str<<endl;
// }


// #include<iostream>
// #include<algorithm>
// using namespace std;
// void test(string &str,string& cut,string & not_cut,int i=0){
//   if(i>=str.length())return;
//   string temp=str.substr(i,cut.length()+(not_cut.length()-cut.length()+1));
//   int ci=temp.find(cut),nci=temp.find(not_cut);
//   cout<<"temp = "<<temp<<endl;
//   cout<<"ci = "<<ci<<" nci = "<<nci<<endl;
//   if((ci>=0)&&(nci==-1)&&temp.length()>=cut.length()){
//     cout<<"Condition hit"<<endl;
//     str.erase(ci+i,cut.length());
//   } else if(nci>-1){
//     i+=not_cut.length();
//   }else i++;
//   test(str,cut,not_cut,i);
// }
// int main(){
//   string str,cut,not_cut;
//   cout<<"Enter string : ";
//   cin>>str;
//   cout<<"Enter substring which you want to remmove : ";
//   cin>>cut;
//   cout<<"Enter the substring which you don't want to remove : ";
//   cin>>not_cut;
//   // int i=str.find(cut);
//   // cout<<i<<endl;
//   test(str,cut,not_cut);
//   cout<<str<<endl;
// }


// #include<iostream>
// #include<algorithm>
// using namespace std;
// void test(string &str,string& cut,string & not_cut,int i=0){
//   if(i>=str.length())return;
//   string temp=str.substr(i,cut.length()+cut.length());
//   int ci=temp.find(cut),nci=temp.find(not_cut);
//   cout<<"temp = "<<temp<<endl;
//   cout<<"ci = "<<ci<<" nci = "<<nci<<endl;
//   if((ci>=0)&&(nci==-1)&&temp.length()>=cut.length()){
//     cout<<"Condition hit"<<endl;
//     str.erase(ci+i,cut.length());
//   } else if(nci>-1){
//     i+=not_cut.length();
//   }else i++;
//   test(str,cut,not_cut,i);
// }
// int main(){
//   string str,cut,not_cut;
//   cout<<"Enter string : ";
//   cin>>str;
//   cout<<"Enter substring which you want to remmove : ";
//   cin>>cut;
//   cout<<"Enter the substring which you don't want to remove : ";
//   cin>>not_cut;
//   // int i=str.find(cut);
//   // cout<<i<<endl;
//   test(str,cut,not_cut);
//   cout<<str<<endl;
// }
