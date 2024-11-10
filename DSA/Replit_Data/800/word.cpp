// #include<iostream>
// #include<string.h>
// using namespace std;
// int main(){
//   int s=0,c=0;
//   char word[1000];
//   cin>>word;
//   int l=strlen(word);
//   for(int i=0;i<l;i++){
//     if(word[i]>='a'&&word[i]<='b') s++;
//     else if(word[i]>='A'&&word[i]<='Z')c++;
//   }
//   if(s>=c){
//     for(int i=0;i<l;i++){
//       if(word[i]>='A'&&word[i]<='Z')word[i]+=32;
//     }
//   } 
//   else if (c>s){
//     for(int i=0;i<l;i++){
//       if(word[i]>='a'&&word[i]<='z')word[i]-=32;
//     }
//   }
//   cout<<word;
// }