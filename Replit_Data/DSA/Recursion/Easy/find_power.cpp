// #include<iostream>
// #include<math.h>
// using namespace std;
// int find_x(int n,int a,int x,int cnt){
//   x*=a;
//   if(x==n)return cnt;
//   else if(x>n||a==0)return -1;
//   return find_x(n,a,x,cnt+1);
// }
// int main(){
//   int n,a;
//   cout<<"Enter n : ";
//   cin>>n;
//   cout<<"Enter a : ";
//   cin>>a;
//   int x;
//    if(a==0){cout<<"0 raised to power anything will be 0"<<endl;return 0;}
//   else if(a!=1&&n==1)x=0;
//   else x=find_x(n,a,1,1);
  
//   if(x!=-1)cout<<a<<" is raised to the power : "<<x<<endl;
//   else cout<<"Invalid input"<<endl;
// }

// // Enter n : 1
// // Enter a : 3
// // 3 is raised to the power : 0