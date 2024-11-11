// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main(){
//   int te,n,k;
//   cin>>te;
//   for(int t=0;t<te;t++){
//     cin>>n>>k;
//     long long no[n];
//     for(long long i=0;i<n;i++)cin>>no[i];
//     if(n==1){cout<<0<<endl;continue;}
//     sort(no,no+n);
//     long long l=1,maxl=0;
//     for(long long i=0;i<n-1;i++){
//       if((no[i+1]-no[i])<=k)l++;
//       else {
//         l=1;
//       }
//       if(l>maxl)maxl=l;
//     }
//     cout<<n-maxl<<endl;
//   }
// }