// #include<iostream>
// using namespace std;
// class Solution {
// public:
//     double myPow(double x, int n) {
//         static int no=n;
//         if(n==0)return 1;
//         if(no>0)return x*myPow(x,n-1);
//         else return (1/x)*(1/myPow(x,n-1));
//     }
// };
// class Solution {
// public:
//     double myPow(double x, int n) {
//         static int no=n;
//         if(n==0)return 1;
//         if(no>0)return x*myPow(x,n-1);
//         else return (1/x)*(myPow(x,n+1));
//     }
// };
// class Solution {
//     double ans=1;
// public:
//     double myPow(double x, int n) {
//         static int no=n;
//         n=abs(n);
//         if(n==0)return 1;
//         ans*=x;
//         myPow(x,n-1);
//         if(no>0)return ans;
//         else return 1/ans;
//     }
// };

// class Solution {
//     int b=0,test=0;
//     double ans=1;
// public:
//     double myPow(double x, int n) {
//         if(b==0&&n<0){b=1;test=1;}
//         // static int no=n;
//         n=abs(n);
//         if(n==0)return 1;
//         ans*=x;
//         myPow(x,n-1);
//         if(test==0)return ans;
//         else return 1/ans;
//     }
// };

// int main(){
//     Solution s;
//     double ans=s.myPow(2.00000,-2);
//     cout<<ans<<endl;
// }