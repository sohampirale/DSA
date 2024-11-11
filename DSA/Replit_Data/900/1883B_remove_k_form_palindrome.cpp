// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main(){
//   int te;
//   cin>>te;
//   for(int t=0;t<te;t++){
//     int k,n;
//     int b=0;
//     string str;
//     cin>>n>>k;
//     cin>>str;
//     int no_of[n];
//     sort(str.begin(),str.end());
//     no_of[0]=1;
//     int cnt=0;
//     for(int i=1;i<n;i++){
//       if(str[i]==str[i-1])no_of[cnt]++;
//       else {
//         cnt++;
//         no_of[cnt]=1;
//       }
//     }
//     int odd_no[cnt+1];
//     for(int i=0;i<=cnt;i++)odd_no[i]=0;
//     int odd_cnt=0;
//     for(int i=0;i<=cnt;i++){
//       if(no_of[i]%2==1){
//         odd_no[odd_cnt]=no_of[i];
//         odd_cnt++;
//       } 
//     }
//     if(odd_cnt==1||odd_cnt==0){
//       cout<<"YES"<<endl;
//       continue;
//     }
//     sort(odd_no,odd_no+odd_cnt);
//       int k2=k;
//     for(int i=0;i<odd_cnt;i++){
//       if(odd_no[i]%2==1&&k2>0){
//         odd_no[i]--;
//         k2--;
//         b=1;
//       }
//       if(k2<1){
//         if(odd_no[odd_cnt-2]%2==0){
//           cout<<"YES"<<endl;
//           break;
//         }  else {
//           cout<<"NO"<<endl;
//           break;
//         }
//       }
//       if(i==odd_cnt-1&&b==1){
//         i=-1;
//         b=0;
//       } else if(i==odd_cnt-1&&b==0){
//         cout<<"YES"<<endl;
//         break;
//       }     
//     }
  
//   }
// }


// while(1){
//   int temp=odd_no[i];
//   odd_no[i]=k2-temp;
//   k2=k2-temp;
//   if(k2<1){
//     if(i==odd_cnt-1){
//       cout<<"YES"<<endl;
//         break;
//     } else if(odd_no[i]%2==0&&i==odd_cnt-2){
//       cout<<"YES"<<endl;
//       break;
//     } else if(i<odd_cnt-2) {
//       cout<<"NO"<<endl;
//       break;
//     }
//   } else if(k2>0&&i==odd_cnt-1){
//     cout<<"YES"<<endl;
//     break;
//   }
//   i++;
// }