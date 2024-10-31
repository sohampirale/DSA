// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// int main(){
//   string str;
//   cin>>str;
//   reverse(str.begin(),str.end());
//   int no=stoi(str);
//   vector<int>nos(10,0);
//   vector<int>ans;
//   while(no!=0){
//     int n=no%10;
//     // cout<<"n here is : "<<n<<endl;
//     if(nos[n]==0){
//       nos[n]++;
//       ans.push_back(n);
//     }
//     no/=10;
//   }
//   for(int i=0;i<ans.size();i++){
//     cout<<ans[i];
//     if(i!=ans.size()-1)cout<<',';
//   }
// }
