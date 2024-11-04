// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
//   int n,i=0;
//   string str="";
//   cout<<"ENter a number : ";
//   cin>>n;
//   while(pow(2,i)<=n){
//     str=to_string((n>>i)&1)+str;
//     i++;
//   }
//   cout<<"Binary representation of "<<n<<" is : "<<str<<endl;
//   int s;
//   cout<<"Enter the position of bit you want to set : ";
//   cin>>s;
//   cout<<"n = "<<n<<endl;
//   int ans=n|(1<<s);
//   cout<<"ans = "<<ans<<endl;
//   string final_ans="";
//   i=0;
//   while(pow(2,i)<=ans){
//     final_ans=to_string((ans>>i)&1)+final_ans;
//     i++;
//   }
//   cout<<"After setting the "<<s<<" th bit the number becomes : "<<ans<<" & it's binary representation is : "<<final_ans<<endl;
// }

//changing ith bit from 0->1 or 1->0
// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
//   int n,i=0;
//   string str="";
//   cout<<"ENter a number : ";
//   cin>>n;
//   while(pow(2,i)<=n){
//     str=to_string((n>>i)&1)+str;
//     i++;
//   }
//   cout<<"Binary representation of "<<n<<" is : "<<str<<endl;
//   int s;
//   cout<<"Enter the position of bit you want to change : ";
//   cin>>s;
//   cout<<"n = "<<n<<endl;
//   int ans=n^(1<<s);
//   cout<<"ans = "<<ans<<endl;
//   string final_ans="";
//   i=0;
//   while(pow(2,i)<=ans){
//     final_ans=to_string((ans>>i)&1)+final_ans;
//     i++;
//   }
//   cout<<"After setting the "<<s<<" th bit the number becomes : "<<ans<<" & it's binary representation is : "<<final_ans<<endl;
// }

//converting 1->0 & 0->0 as well
// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
  
//   int n,i=0;
//   string str="";
//   cout<<"ENter a number : ";
//   cin>>n;
//   while(pow(2,i)<=n){
//     str=to_string((n>>i)&1)+str;
//     i++;
//   }
//   cout<<"Binary representation of "<<n<<" is : "<<str<<endl;
//   int s;
//   cout<<"Enter the position of bit you want to change : ";
//   cin>>s;
//   cout<<"n = "<<n<<endl;
//   int ans=n&~(1<<s);
//   cout<<"ans = "<<ans<<endl;
//   string final_ans="";
  // i=0;
  // while(pow(2,i)<=ans){
  //   final_ans=to_string((ans>>i)&1)+final_ans;
  //   i++;
  // }
//   cout<<"After setting the "<<s<<" th bit the number becomes : "<<ans<<" & it's binary representation is : "<<final_ans<<endl;
// }