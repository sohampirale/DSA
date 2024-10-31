//without sorting

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main(){
//   int n;
//   cout<<"Enter how many numbers you have : ";
//   cin>>n;
//   vector<int>no(n);
//   for(int i=0;i<n;i++)cin>>no[i];
//   int ans=0;
//   for(int i=0;i<n;i++){
//     ans^=no[i];
//   }
//   cout<<"Ans = "<<ans<<endl;
// }
//via sorting
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main(){
//   int n;
//   cout<<"Enter how many numbers you have : ";
//   cin>>n;
//   vector<int>no(n);
//   for(int i=0;i<n;i++)cin>>no[i];
//   sort(no.begin(),no.end());
//   int ans=no[0];
//   for(int i=1;i<no.size();i++){
//     ans=ans^no[i];
//   }
//   cout<<"Ans = "<<ans<<endl;
// }