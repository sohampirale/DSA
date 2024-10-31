// //Practice
// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string>final_ans;
// void solution(int n,int sum=0,string ans=""){
//   if(sum==n){
//     final_ans.push_back(ans);
//     return;
//   }
//   for(int i=1;i<=n-sum&&i<=6;i++){
//     string temp=ans+to_string(i);
//     solution(n,sum+i,temp);
//   }
            
// }
// int main(){
//   int n;
//   cout<<"Enter a number : ";
//   cin>>n;
//   solution(n);
//   cout<<"Answer becomes : "<<endl;
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;

// }


//Most efficient

// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string>final_ans;
// void dice(int n,int tn,string ans,int i);
// //i traversing
// int test=-1;
// void dice(int n,int tn,string ans,int i){
//   if(n==0){
//     final_ans.push_back(ans);
//     return;
//   }
//   for(int j=1;j<=6&&j<=n;j++){
//     string temp=to_string(j);
//     dice(n-j,tn,ans+temp,j);
//   }
// }
// int main(){
//   int n,tn;
//   cout<<"Enter a number between 1-6 : ";
//   cin>>n;
//   if(n>6)tn=6;
//   else tn=n;
//   // int no[]={0,1,2,3,4,5,6};
//   dice(n,tn,"",0);
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }


//  More efficient 

// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string>final_ans;
// void dice(int n,int tn,string ans,int i);

// //i traversing

// int test=-1;
// void dice(int n,int tn,string ans,int i){

//   if(n<0)return;
//   if(n==0){
//     final_ans.push_back(ans);
//     return;
//   }
//   for(int j=1;j<=tn-i;j++){
//     string temp=to_string(j);
//     dice(n-j,tn,ans+temp,j);
//   }
// }
// int main(){
//   int n,tn;
//   cout<<"Enter a number between 1-6 : ";
//   cin>>n;
//   if(n>6)tn=6;
//   else tn=n;
//   // int no[]={0,1,2,3,4,5,6};
//   dice(n,tn,"",0);
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }




//  My answer - less efficient first try
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
//     traverse(n,no,sum+no[i],ans+temp,6,j);
//     traverse(n,no,sum,ans,i-1,j);
//   } else {
//     traverse(n,no,sum,ans,i-1,j);
//   }
// }
// //i traversing

// int test=-1;
// void dice(int n,int* no,int sum,string ans,int i){
//   for(int l=6;l>0;l--){
//     if(n>=l)traverse(n,no,no[l],to_string(no[l]),6);
//   }
// }
// int main(){
//   int n;
//   cout<<"Enter a number between 1-6 : ";
//   cin>>n;
//   int no[]={0,1,2,3,4,5,6};
//   dice(n,no,0,"",6);
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }

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


// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string>final_ans;
// void dice(int n,int tn,string ans,int i);

// //i traversing

// int test=-1;
// void dice(int n,int tn,string ans,int i){

//   if(n<0)return;
//   if(n==0){
//     final_ans.push_back(ans);
//     return;
//   }
//   for(int j=1;j<=tn-i;j++){
//     string temp=to_string(j);
//     dice(n-j,tn,ans+temp,j);
//   }
// }
// int main(){
//   int n,tn;
//   cout<<"Enter a number between 1-6 : ";
//   cin>>n;
//   if(n>6)tn=6;
//   else tn=n;
//   // int no[]={0,1,2,3,4,5,6};
//   dice(n,tn,"",0);
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string>final_ans;
// void dice(int n,int tn,string ans,int i);
// //i traversing
// int test=-1;
// void dice(int n,int tn,string ans,int i){
//   if(n==0){
//     final_ans.push_back(ans);
//     return;
//   }
//   for(int j=1;j<=6&&j<=n;j++){
//     string temp=to_string(j);
//     dice(n-j,tn,ans+temp,j);
//   }
// }
// int main(){
//   int n,tn;
//   cout<<"Enter a number between 1-6 : ";
//   cin>>n;
//   if(n>6)tn=6;
//   else tn=n;
//   // int no[]={0,1,2,3,4,5,6};
//   dice(n,tn,"",0);
//   for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
//   cout<<"Answer finished"<<endl;
// }



// #include<iostream>
// #include<vector>
// using namespace std;

// vector<vector<string>> final_ans;
// vector<string> level;

// void dice(int n, int tn, string ans, int i) {
//     if (n < 0) return;
//     if (n == 0) {
//         level.push_back(ans);
//         final_ans.push_back(level);
//         level.clear();
//         return;
//     }
//     for (int j = 1; j <= tn - i; j++) {
//         string temp = to_string(j);
//         dice(n - j, tn, ans + temp, j);
//     }
// }

// int main() {
//     int n, tn;
//     cout << "Enter a number between 1-6 : ";
//     cin >> n;
//     tn = (n > 6) ? 6 : n;
//     dice(n, tn, "", 0);
//     for (int i = 0; i < final_ans.size(); i++) {
//         for (int j = 0; j < final_ans[i].size(); j++) {
//             cout << final_ans[i][j] << " ";
//         }
//         // cout << endl;
//     }
//     cout << "Answer finished" << endl;
//     return 0;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// vector<vector<string>>final_ans;
// vector<string>level;
// void dice(int n,int tn,string ans,int i);

// //i traversing

// int test=-1;
// void dice(int n,int tn,string ans,int i){

//   if(n<0)return;
//   if(n==0){
//     level.push_back(ans);
//     return;
//   }
//   for(int j=1;j<=tn-i;j++){
//     string temp=to_string(j);
//     dice(n-j,tn,ans+temp,j);
//     final_ans.push_back(level);
//     level.clear();
//   }
// }
// int main(){
//   int n,tn;
//   cout<<"Enter a number between 1-6 : ";
//   cin>>n;
//   if(n>6)tn=6;
//   else tn=n;
//   dice(n,tn,"",0);
//   for(int i=0;i<final_ans.size();i++){
//     for(int j=0;j<final_ans[i].size();j++){
//       cout<<final_ans[i][j]<<" ";
//     }
//     // cout<<endl;
//   }
//   cout<<"Answer finished"<<endl;
// }