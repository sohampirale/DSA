// // //practice
// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string>final_ans;
// void solution(int n,int nfaces,int sum=0,string ans=""){
//   if(sum==n){
//     final_ans.push_back(ans);
//     return;
//   }
//   for(int i=1;i<=n-sum&&i<=nfaces;i++){
//     string temp=ans+to_string(i);
//     solution(n,nfaces,sum+i,temp);
//   }

// }
// int main(){
//   int n,nfaces;
//   cout<<"Enter a number : ";
//   cin>>n;
//   cout<<"Enter number of faces your dice has : ";
//   cin>>nfaces;
//   solution(n,nfaces);
//   cout<<"Answer becomes : "<<endl;
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;

// }


//Less efficient

// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string>final_ans;
// void dice(int n,int* no,int sum,string ans,int i);
// void traverse(int n,int* no,int sum,string ans,int i,int j=-1){
//   if(i==0){
//     int temp_sum=0;
//     int num=stoi(ans);
//     while(num!=0){
//       temp_sum+=(num%10);
//       num/=10;
//     }
//     if(temp_sum==n)final_ans.push_back(ans);
//     return;
//   }
//   if(sum+no[i]<=n){
//     j=i-1;
//     string temp=to_string(no[i]);
//     traverse(n,no,sum+no[i],ans+temp,i,j);
//     traverse(n,no,sum,ans,i-1,j);
//   } else {
//     traverse(n,no,sum,ans,i-1,j);
//   }
// }
// //i traversing

// int test=-1;
// void dice(int n,int* no,int sum,string ans,int i){
//   for(int l=i;l>0;l--){
//     if(n>=l)traverse(n,no,no[l],to_string(no[l]),i);
//   }
// }
// int main(){
//   int n;
//   cout<<"Enter a number between 1-6 : ";
//   cin>>n;
//   int nfaces;
//   cout<<"Enter number of faces your dice has : ";
//   cin>>nfaces;
//   int no[nfaces];
//   for(int i=1;i<=nfaces;i++)no[i]=i;
//   dice(n,no,0,"",nfaces);
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }

//  More efficient

// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string>final_ans;
// void dice(int n,int nfaces,string ans,int i);
// //i traversing
// int test=-1;
// void dice(int n,int nfaces,string ans,int i){
//   if(n==0){
//     final_ans.push_back(ans);
//     return;
//   }
//   for(int j=1;j<=nfaces&&j<=n;j++){
//     string temp=to_string(j);
//     dice(n-j,nfaces,ans+temp,j);
//   }
// }
// int main(){
//   int n,nfaces;
//   cout<<"Enter a number between 1-6 : ";
//   cin>>n;
//   cout<<"Enter number of faces your dice has : ";
//   cin>>nfaces;
//   dice(n,nfaces,"",0);
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }



// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string>final_ans;
// void dice(int n,int tn,string ans,int i);

// //i traversing

// void dice(int n,int nfaces,string ans,int i){

//   if(n<0)return;
//   if(n==0){
//     final_ans.push_back(ans);
//     return;
//   }
//   for(int j=1;j<=n&&j<=nfaces;j++){
//     string temp=to_string(j);
//     dice(n-j,nfaces,ans+temp,j);
//   }
// }
// int main(){
//   int n,nfaces;
//   cout<<"Enter a number between 1-6 : ";
//   cin>>n;
//   cout<<"Enter number of faces your dice has : ";
//   cin>>nfaces;
//   dice(n,nfaces,"",0);
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }