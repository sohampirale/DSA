// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   int i=0;
//   while(1){
//     if((n&(1<<i))>0){        //if could have been done if((n>>i)&1)==1 answer found
//       cout<<"First set bit found at index "<<i<<endl;
//       cout<<"Calculation = "<<(n&(1<<i))<<endl;
//       break;
//     }
//     i++;
//   }
//   string binary="";
//   i=0;
//   while(pow(2,i)<=n){
//     binary=to_string((n>>i)&1)+binary;
//     i++;
//   }
//   cout<<"Binary representation of "<<n<<" is : "<<binary<<endl;
// }

//finding first 0 bit
// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   int i=0;
//   while(1){
//     if((n&(1<<i))==0){
//       cout<<"First zero bit found at index "<<i<<endl;
//       cout<<"Calculation = "<<(n&(1<<i))<<endl;
//       break;
//     }
//     i++;
//   }
//   string binary="";
  // i=0;
  // while(pow(2,i)<=n){
  //   binary=to_string((n>>i)&1)+binary;
  //   i++;
  // }
  // cout<<"Binary representation of "<<n<<" is : "<<binary<<endl;
// }

// #include<iostream>
// using namespace std;
// int main(){
//   int n=-2147483647;
//   cout<<n;
//   string str="";
//   int i=0;
//   while(i<33){
//     str=to_string((n>>i)&1)+str;
//     i++;
//   }
//   cout<<"Binary representation of "<<n<<" is : "<<str<<endl;
// }
// 110000000000000000000000000000001
