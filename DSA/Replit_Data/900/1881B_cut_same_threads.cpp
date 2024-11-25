// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main(){
//   int te;
//   cin>>te;
//   for(int t=0;t<te;t++){
//     long long no[3];
//     cin>>no[0]>>no[1]>>no[2];
//     long long m=min({no[0],no[1],no[2]});
//     int cnt=3,b=0;
//     for(int i=0;i<3;i++){
//       if(no[i]>m){
//         no[i]=no[i]-m;
//         cnt--;
//         b=1;
//       } 
//       if(i==2&&b==1){
//         i=-1;
//         b=0;
//       } else if(i==2&&b==0){
//         if(no[0]==no[1]&&no[1]==no[2]){
//           cout<<"YES"<<endl;
//           break;
//         } else {
//           cout<<"NO"<<endl;
//           break;
//         }  
//       }
//       if(cnt==0){
//         if(no[0]==no[1]&&no[1]==no[2]){
//           cout<<"YES"<<endl;
//           break;
//         } else {
//           cout<<"NO"<<endl;
//           break;
//         }  
//       }
//     }
//   }
// }