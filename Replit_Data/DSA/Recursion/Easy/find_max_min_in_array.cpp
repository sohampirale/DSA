// #include<iostream>
// using namespace std;
// void find_max_min(int* no,int* ans,int i=0){
//   if(i==ans[2])return;
//   if(no[i]<ans[0])ans[0]=no[i];
//   if(no[i]>ans[1])ans[1]=no[i];
//   find_max_min(no,ans,i+1);
// }
// int main(){
//   int n;
//   cout<<"Enter number of elements you have : ";
//   cin>>n;
//   int no[n];
//   cout<<"Enter "<<n<<" elements : ";
//   for(int i=0;i<n;i++)cin>>no[i];
//   int ans[3]={no[0],no[0],n};
//   find_max_min(no,ans);
//   cout<<"Maximum element in the array is : "<<ans[1]<<endl;
//   cout<<"Minimum element in the array is : "<<ans[0]<<endl;
// }