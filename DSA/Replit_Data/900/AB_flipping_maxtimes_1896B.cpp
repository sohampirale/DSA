// #include<iostream>
// using namespace std;
// int main(){
//   int t,l;
//   cin>>t;
//   for(int i=0;i<t;i++){
//     int cnt=0;
//     cin>>l;
//     char str[l];
//     cin>>str;
//     int e=l-1;
//     for(int j=l-1;j>=0;j--){
//       if(str[j]=='A'){
//        cnt+=(e-j);
//         if(e-j!=0)e=j;
//         else e=j-1;
//       }
//     }
//     cout<<cnt<<endl;
//     }
  
// }

// #include<iostream>
// using namespace std;
// int main(){
//   int t,l;
//   cin>>t;
//   for(int i=0;i<t;i++){
//     cin>>l;
//     int used[l];
//     char str[l];
//     cin>>str;
//     int na=0,cnt=0;
//     for(int k=0;k<l;k++)if(str[k]=='A')na++;
//     for(int k=0;k<na;k++){
//     for(int j=0;j<l;j++){
//       if(str[j]=='A'&&str[j+1]=='B'&&used[j]!=1){
//         used[j]=1;
//         cnt++;
//         char temp=str[j];
//         str[j]=str[j+1];
//         str[j+1]=temp;
//       } 
//       }
//       } 
//       cout<<cnt<<endl;
//     }
// }