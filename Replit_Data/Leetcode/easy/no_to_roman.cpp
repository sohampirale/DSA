// // #include<iostream>
// // #include<math.h>
// // #include<string>
// // using namespace std;
// // class Solution {
// // int b=0;
// // public:
// //     string romanToInt(string s) {
// //         int l=s.length();
// //         string ans;
// //         int number=stoi(s);
// //         int so[l],i=0;
// //         while(number!=0){
// //             int div=pow(10,l-1-i);
// //             so[i]=number/div;
// //             number%=div;
// //             i++;
// //         }
// //         cout<<"no's stored in so are : ";
// //         for(int i=0;i<l;i++)cout<<so[i]<<" ";
// //         cout<<endl;
// //         int no[]={1000,500,100,50,10,5,1};
// //         char ch[]={'M','D','C','L','X','V','I'};
// //         int num[l];
// //         cout<<"No stored as place value are : ";
// //         for(int i=0;i<l;i++){num[i]=((so[i])*(pow(10,l-i-1)));cout<<num[i]<<" ";}
        
// //         int m=0,test;
// //         for(int i=0;i<7;i++){
// //             // if(m==2)cout<<"m reached 2\n";
// //             if((num[m]/pow(10,l-m-1))==4||(num[m]/pow(10,l-m-1))==9){    
// //                 for(int j=i-1;j<7;j++){
// //                     // if(j==test+1)cout<<"iteration is happening"<<endl;
// //                     for(int k=j;k<7;k++){
// //                         if(no[j]-no[k]==num[m]){
// //                             // if(m==2)cout<<"condition found when m==2"<<endl;
// //                             ans.push_back(ch[k]);
// //                             ans.push_back(ch[j]);
// //                             // cout<<ch[k]<<ch[j];
// //                             i=j;
// //                             m++;
// //                             b=1;
// //                             break;
// //                         }
// //                     }
// //                     test=j;
// //                 if(b==1){b=0;break;}
// //                 }
// //             } else {
// //                 while(1){
// //                     if(num[m]<no[i]&&num[m]==0)break;
// //                     else if(num[m]<no[i]&&num[m]!=0){m--;break;}

// //                     ans.push_back(ch[i]);
// //                     // cout<<ch[i];
// //                     num[m]-=no[i];
// //                 }
// //                 m++;
// //             }
// //             if(m==l)break;
// //         }
// //         return ans;
// //     }
// // };
// // int main(){
// //     string str;
// //     cout<<"Enter a no : ";
// //     cin>>str;
// //     Solution s;
// //     string ans=s.romanToInt(str);
// //     cout<<ans<<endl;
// // }


// #include<iostream>
// #include<math.h>
// #include<string>
// using namespace std;
// class Solution {
// int b=0;
// public:
//     string intToRoman(int num) {
//         int l=s.length();
//         string ans;
//         int number=stoi(s);
//         int so[l],i=0;
//         while(number!=0){
//             int div=pow(10,l-1-i);
//             so[i]=number/div;
//             number%=div;
//             i++;
//         }
//         cout<<"no's stored in so are : ";
//         for(int i=0;i<l;i++)cout<<so[i]<<" ";
//         cout<<endl;
//         int no[]={1000,500,100,50,10,5,1};
//         char ch[]={'M','D','C','L','X','V','I'};
//         int num[l];
//         for(int i=0;i<l;i++){num[i]=((so[i])*(pow(10,l-i-1)));}
//         int m=0,test;
//         for(int i=0;i<7;i++){
//             if((num[m]/pow(10,l-m-1))==4||(num[m]/pow(10,l-m-1))==9){    
//                 for(int j=i-1;j<7;j++){
//                     for(int k=j;k<7;k++){
//                         if(no[j]-no[k]==num[m]){
//                             ans.push_back(ch[k]);
//                             ans.push_back(ch[j]);
//                             i=j;
//                             m++;
//                             b=1;
//                             break;
//                         }
//                     }
//                     test=j;
//                 if(b==1){b=0;break;}
//                 }
//             } else {
//                 while(1){
//                     if(num[m]<no[i]&&num[m]==0)break;
//                     else if(num[m]<no[i]&&num[m]!=0){m--;break;}
//                     ans.push_back(ch[i]);
//                     num[m]-=no[i];
//                 }
//                 m++;
//             }
//             if(m==l)break;
//         }
//         return ans;
//     }
// };
// int main(){
//     string str;
//     cout<<"Enter a no : ";
//     cin>>str;
//     Solution s;
//     string ans=s.romanToInt(str);
//     cout<<ans<<endl;
// }