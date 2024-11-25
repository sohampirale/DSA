
// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
//   string str="";
//   int n=10;
//   int i=0;
//   while(i<9){
//     str=to_string((n>>i)&1)+str;
//     i++;
//   }
//   cout<<"n  = "<<n<<endl;
//   cout<<"Binary representtation of "<<n<<" beofre is : "<<str<<endl;
//   str="";
//   n=~(0)-10;
//   i=0;
//   while(i<9){
//     str=to_string((n>>i)&1)+str;
//     i++;
//   }
//   cout<<"After convertion binary representation of "<<n<<" is : "<<str<<endl;
//   str="";
//   i=0;
//   n=~(0)-10+1;

//   while(i<9){
//     str=to_string((n>>i)&1)+str;
//     i++;
//   }
//   cout<<"After convertion binary representation of "<<n<<" is : "<<str<<endl;
// }

// n  = 10
// Binary representtation of 10 beofre is : 000001010
// After convertion binary representation of -11 is : 111110101
// After convertion binary representation of -10 is : 111110110