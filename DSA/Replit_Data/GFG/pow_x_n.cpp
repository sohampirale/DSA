// #include<iostream>
// #include<iomanip>
// using namespace std;
// double solution(double x,int n,double ans,int i=1){
//   if(i==n)return ans;
//   ans*=x;
//   return solution(x,n,ans,i+1);
// }
// int main(){
//   int n;
//   double x;
//   cout<<"Enter x & n : ";
//   cin>>x>>n;
//   double ans=solution(x,n,x);
//   cout << fixed << setprecision(5);
//   cout<<"Answer is : "<<ans<<endl;
// }