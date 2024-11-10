// #include<iostream>
// using namespace std;
// int main(){
//   int n,i,on;
//   cout<<"Enter a number : ";
//   cin>>n;
//   on=n;
//   cout<<"Enter which place bit you want to see : ";
//   cin>>i;
//   // M1
//   // int ans=(n>>i)&1;
//   // cout<<"Ans = "<<ans;
//   // M2
//   // int ans=((1<<i)&n)>>(i);
//   // cout<<"Ans = "<<ans;
// }

//BRUTE FORCE
// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<math.h>
// using namespace std;
// int main(){
//   int n,i,on;
//   cout<<"Enter a number : ";
//   cin>>n;
//   on=n;
//   cout<<"Enter which place bit you want to see : ";
//   cin>>i;
//   string str="";
//   for(int j=n/2;j>=0;j--){
//     if(pow(2,j)<=n){
//       str='1'+str;
//       n-=pow(2,j);
//     } else {
//       str='0'+str;
//     }
//   }
//   cout<<"i th bit in the binary representation of "<<n<<" is : "<<str[i]<<endl<<"Binary representation in reverse order is : "<<str<<endl;
// }


// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<math.h>
// using namespace std;
// int main(){
//   int n,i,on;
//   cout<<"Enter a number : ";
//   cin>>n;
//   on=n;
//   cout<<"Enter which place bit you want to see : ";
//   cin>>i;
//   int div=pow(2,i);
//   int ans=((17&div)>>i);
//   cout<<"Ans = "<<ans;
// }


