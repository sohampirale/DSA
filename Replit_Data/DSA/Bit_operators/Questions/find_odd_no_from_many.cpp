// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//   int n;
//   cout<<"Enter how many numbers you ahve : ";
//   cin>>n;
//   vector<int>num(n);
//   for(int i=0;i<n;i++)cin>>num[i];
//   int test=0;
//   int t=num[0];
//   for(int i=1;i<num.size();i++){
//     if((t^num[i])==0){
//       // cout<<"Similar found at t ="<<t<<" & num[i] = "<<num[i]<<" & i = "<<i<<endl;
//       num.erase(num.begin()+i);
//       // cout<<"After erasing one element num vector becomes : ";
//       // for(int j=0;j<num.size();j++)cout<<num[j]<<" ";
//       test=1;
//       i--;
//     }
//     if(i==num.size()-1&&test==1){
//       num.erase(num.begin());
//       t=num[0];
//       test=0;
//       i=0;
//       // cout<<"Num vector is now : ";
//       // for(int j=0;j<num.size();j++)cout<<num[j]<<" ";
//     } else if(i==num.size()-1&&test==0){
//       // cout<<"Number found"<<endl;
//       cout<<"Number that's appearing only once is : "<<t<<endl;
//       // cout<<"Num vector now is : ";
//       // for(int j=0;j<num.size();j++)cout<<num[j]<<" ";
//       break;
//     }
//   }
//   cout<<"Number that is appearing onyl once is : "<<num[0]<<endl;
// }


//chta gpt
// #include<iostream>
// #include<vector>
// using namespace std;
// void solve(vector<int>&num,int k){
//   vector<int>bits(32,0);
//   for(int i=0;i<num.size();i++){
//     for(int j=0;j<32;j++){
//       if(num[i]&(1<<j)){
//         bits[j]++;
//       }
//     }
//   }
//   int ans=0;
//   for(int i=0;i<32;i++){
//     if(bits[i]%k!=0){
//       ans|=(1<<i);
//     }
//   }
//   cout<<"ans = "<<ans<<endl;
// }
// int main(){
//   int n;
//   cout<<"Enter how many numbers you have : ";
//   cin>>n;
//   vector<int>num(n);
//   for(int i=0;i<n;i++)cin>>num[i];
//   int k;
//   cout<<"How many times other numbers are repeating : ";
//   cin>>k;
//   solve(num,k);
// }