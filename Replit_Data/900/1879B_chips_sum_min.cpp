// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main(){
//   int te;
//   cin>>te;
//   for(int t=0;t<te;t++){
//     int n;
//     cin>>n;
//     int a[n],b[n];
//     for(int i=0;i<n;i++)cin>>a[i];
//     for(int i=0;i<n;i++)cin>>b[i];
//     int m1=*min_element(a,a+n);
//     int m2=*min_element(b,b+n);
//     int sum1=0,sum2=0;
//     for(int i=0;i<n;i++)sum1+=(m1+b[i]);
//     for(int i=0;i<n;i++)sum2+=(m2+a[i]);
//     if(sum1<sum2)cout<<sum1<<endl;
//     else cout<<sum2<<endl;
//   }
// }

// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main(){
//   int te;
//   cin>>te;
//   for(int t=0;t<te;t++){
//     long long n;
//     cin>>n;
//     long long a[n],b[n];
//     for(long long i=0;i<n;i++)cin>>a[i];
//     for(long long i=0;i<n;i++)cin>>b[i];
//     long long m1=*min_element(a,a+n);
//     long long m2=*min_element(b,b+n);
//     long long sum1=0,sum2=0;
//     for(long long i=0;i<n;i++)sum1+=(m1+b[i]);
//     for(long long i=0;i<n;i++)sum2+=(m2+a[i]);
//     if(sum1<sum2)cout<<sum1<<endl;
//     else cout<<sum2<<endl;
//   }
// }