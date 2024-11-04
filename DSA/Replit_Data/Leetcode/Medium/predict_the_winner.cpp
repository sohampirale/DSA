// #include<iostream>
// #include<vector>
// using namespace std;
// bool test=0;
// int turn=2;
// void testing(int p1,int p2){
//   test = test||(p1>p2);
// }
// bool solve(vector<int>nums,int p1=0,int p2=0){
//   if(test==true)return true;
//   vector<int>temp=nums;
//   int t;
//   if(turn==2)turn=1;
//   else if(turn==1)turn=2;
//   if(nums.size()==1){
//     if(turn==1)p1+=nums[0];
//     else if(turn==2)p2+=nums[0];
//     testing(p1,p2);
//     return test;
//   }
//   if(turn==1){
//     t=temp[0];
//     temp.erase(temp.begin());
//     solve(temp,p1+t,p2);
//     turn=1;
//     t=nums[nums.size()-1];
//     nums.pop_back();
//     solve(nums,p1+t,p2);
//   }else if(turn==2){
//     t=temp[0];
//     temp.erase(temp.begin());
//     solve(temp,p1,p2+t);
//     turn =2;
//     t=nums[nums.size()-1];
//     nums.pop_back();
//     solve(nums,p1,p2+t);
//   }
//   return test;
// }
// int main(){
//   int n;
//   cout<<"Enter how many numbers you have : ";
//   cin>>n;
//   vector<int>nums;
//   int t;
//   for(int i=0;i<n;i++){
//     cin>>t;
//     nums.push_back(t);
//   }
//   cout<<solve(nums);

// }