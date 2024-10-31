// #include<iostream>
// #include<vector>
// using namespace std;
// int i=0;
// bool check_sorted(vector<int>&no){
//   i++;
//   if(i==no.size())return true;
//   return (no[i-1]<=no[i])&&(check_sorted(no));
// }
// bool check_sorted(vector<int>&no){
//   if(i==no.size()-1)return true;
//   bool c=(no[i]<=no[i+1]);
//   i++;
//   return c&&(check_sorted(no));
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>no(n);
//   for(int i=0;i<n;i++)cin>>no[i];
//   if(check_sorted(no))cout<<"Sorted";
//   else cout<<"Not sorted";
// }