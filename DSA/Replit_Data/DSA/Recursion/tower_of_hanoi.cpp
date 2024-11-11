// #include<iostream>
// using namespace std;
// int cnt=0;
// void toh(int n,int source=1,int helper=2,int destination=3){
//   if(n==0)return;
//   toh(n-1,source,destination,helper);
//   cout<<"Moving disk no-"<<n<<"from"<<source<<" to "<<destination<<endl;
//   cnt++;
//   toh(n-1,helper,source,destination);
// }
// int main(){
//   int n;
//   cout<<"Enter no. of disks : ";
//   cin>>n;
//   toh(n);
//   cout<<"Number of steps required are : "<<cnt<<endl;
// }