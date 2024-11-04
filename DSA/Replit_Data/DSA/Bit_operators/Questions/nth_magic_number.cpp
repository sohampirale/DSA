// #include<iostream>
// #include<algorithm>
// #include<math.h>
// using namespace std;
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   string ans="";
//   int i=0;
//   while(pow(2,i)<=n){
//     if(((n>>i)&1)==1){
//       ans='1'+ans;
//     } else {
//       ans='0'+ans;
//     }
//     i++;
//   }
//   int result=0;
//   cout<<"Binary representation of "<<n<<" is : "<<ans<<endl;
//   reverse(ans.begin(),ans.end());
//   for(int i=0;i<ans.length();i++){
//     result+=(pow(5,i+1)*(ans[i]-'0'));
//     // cout<<" result  = "<<result<<endl;
//   }
//   cout<<"Result = "<<result<<endl;
// // }

// #include<iostream>
// #include<algorithm>
// #include<math.h>
// using namespace std;
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   int i=0,ans=0;
//   while(n!=0){
//     cout<<"n = "<<n<<endl;
//     if((n&1)==1){
//       cout<<"Set bit found at i ="<<i<<" & n = "<<n<<endl;
//       ans+=(pow(5,i+1));
//     }
//     n=(n>>1);
//     i++;
//   }
//   cout<<"Ans = "<<ans<<endl;
// }

// }

// #include<iostream>
// #include<algorithm>
// #include<math.h>
// using namespace std;
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   int i=1,ans=0;
//   while(n!=0){
//     int a=n&1;
//     ans+=a*pow(5,i);
//     n=n>>1;
//     i++;
//   }
//   cout<<"Ans = "<<ans<<endl;
// }
