
// #include<iostream>
// #include<vector>
// using namespace std;
// int n;
// vector<int> find_no(vector<int>no,int find,int i);
// int main(){
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>no(n);
//   cout<<"Enter "<<n<<" numbers : ";
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   vector<int>ans=find_no(no,find,0);
//   for(int i:ans)cout<<i<<" ";
// }
// vector<int> find_no(vector<int>no,int find,int i){
//   vector<int>ans;
//   if(i==no.size())return ans;
//   else if(no[i]==find)ans.push_back(i);
//   vector<int>temp=find_no(no,find,i+1);
//   for(int j=0;j<temp.size();j++){
//     ans.push_back(temp[j]);
//   }
//   return ans;
// }

//PRACTICE
// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> find_no(vector<int>&no,int find,int i=0){
//   static vector<int>ans;
//   if(no[i]==find)ans.push_back(i);
//   if(i==no.size())return ans;
//   return find_no(no,find,i+1);
// }
// int main(){
//   int n;
//   cout<<"Enter number of elments you have : ";
//   cin>>n;
//   vector<int>no(n);
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the number you want to find : ";
//   cin>>find;
//   vector<int>ans=find_no(no,find);
//   cout<<find<<" found at index : ";
//   for(int i=0;i<ans.size();i++){
//     cout<<ans[i]<<" ";
//   }
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){}
// #include<vector>
// #include<iostream>
// using namespace std;
// int i=0;
// int find_no(vector<int>&no,int find){
//   if(i==no.size())return -1;
//   else if(no[i]==find)return i;
//   i++;
//   return find_no(no,find);
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>no(n);
//   cout<<"Enter "<<n<<" elements in an array:";
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no. you want to find in an array : ";
//   cin>>find;
//   int ans=find_no(no,find);
//   if(ans!=-1)cout<<"Number : "<<find<<" is present at the position : "<<ans<<endl;
//   else cout<<"Number "<<find<<" is not present in the array"<<endl;
// }


// // #include<vector>
// // #include<iostream>
// // using namespace std;
// // int i=0;
// // int find_no(vector<int>&no,int find){
// //   if(i==no.size())return false;
// //   else if(no[i]==find)return true;
// //   i++;
// //   return find_no(no,find);
// // }
// // int main(){
// //   int n;
// //   cout<<"Enter n : ";
// //   cin>>n;
// //   vector<int>no(n);
// //   cout<<"Enter "<<n<<" elements in an array:";
// //   for(int i=0;i<n;i++)cin>>no[i];
// //   int find;
// //   cout<<"Enter the no. you want to find in an array : ";
// //   cin>>find;
// //   if(find_no(no,find))cout<<"Number "<<find<<" found at position : "<<i<<endl;
// //   else cout<<"Number "<<find<<" not found in the array"<<endl;
// // }


// #include<vector>
// #include<iostream>
// using namespace std;
// int i;
// int find_no(vector<int>&no,int find){
//   if(i==-1)return false;
//   else if(no[i]==find)return true;
//   i--;
//   return find_no(no,find);
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   i=n-1;
//   vector<int>no(n);
//   cout<<"Enter "<<n<<" elements in an array:";
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no. you want to find in an array : ";
//   cin>>find;
//   if(find_no(no,find))cout<<"Number "<<find<<" found at position : "<<i<<endl;
//   else cout<<"Number "<<find<<" not found in the array"<<endl;
// }

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main(){
//   int n,find_no;
//   cout<<"Enter n: ";
//   cin>>n;
//   vector<int>no(n);
//   cout<<"Enter "<<n<<"numbers : ";
//   for(int i=0;i<n;i++)cin>>no[i];
//   cout<<"Enter the no.ou want to find : ";
//   cin>>find_no;
//   auto it=find(no.begin(),no.end(),find_no);;
//   int ans=distance(no.begin(),it);
//   if(ans!=n)cout<<"Number found at the position :"<<ans<<endl;
//   else cout<<"Number "<<find_no<<" not found in the array"<<endl;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int>ans(0);
// int i=0;
// void find_no(vector<int>&no,int find){
//   if(i==no.size())return;
//   else if(no[i]==find){
//     ans.push_back(i);
//   }
//   i++;
//   find_no(no,find);
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>no(n);
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   find_no(no,find);
//   if(ans.empty())cout<<"Number "<<find<<" not found"<<endl;
//   else {
//     cout<<"Number "<<find<<" found at positions : ";
//     for(int i=0;i<ans.size();i++){
//       cout<<ans[i]<<" ";
//     }
//   }
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// int i=0;
// vector<int> find_no(vector<int>&no,int find){
//   static vector<int>ans;
//   if(i==no.size())return ans;
//   else if(no[i]==find){
//     ans.push_back(i);
//   }
//   i++;
//   return find_no(no,find);
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>no(n);
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   vector<int>final_ans=find_no(no,find);
//   if(final_ans.empty())cout<<"Number "<<find<<" not found"<<endl;
//   else {
//     cout<<"Number "<<find<<" found at positions : ";
//     for(int i=0;i<final_ans.size();i++){
//       cout<<final_ans[i]<<" ";
//     }
//   }
// }



// #include<iostream>
// #include<vector>
// using namespace std;
// int i=0;
// vector<int> find_no(vector<int>&no,int find){
//   static vector<int>ans;
//   if(i==no.size())return ans;
//   else if(no[i]==find){
//     ans.push_back(i);
//   }
//   i++;
//    return find_no(no,find);
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>no(n);
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   vector<int>final_ans=find_no(no,find);
//   if(final_ans.empty())cout<<"Number "<<find<<" not found"<<endl;
//   else {
//     cout<<"Number "<<find<<" found at positions : ";
//     for(int i:final_ans)cout<<i<<" ";
//     // for(int i=0;i<final_ans.size();i++){
//       // cout<<final_ans[0]<<" ";
//     // }
//   }
// }


//DW
// #include<iostream>
// #include<vector>
// using namespace std;
// int i=0;
// vector<int> find_no(vector<int>&no,int find){
//   static vector<int>ans;
//   if(i==no.size())return ans;
//   else if(no[i]==find){
//     ans.push_back(i);
//   }
//   i++;
//    return find_no(no,find);
//   if(ans.size()==0)cout<<"Number "<<find<<" not found"<<endl;
//   else {
//     cout<<"Number "<<find<<" found at : ";
//     for(int j:ans)cout<<j<<" ";
//   }
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>no(n);
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   vector<int>final_ans=find_no(no,find);
  // if(final_ans.empty())cout<<"Number "<<find<<" not found"<<endl;
  // else {
  //   cout<<"Number "<<find<<" found at positions : ";
  //   for(int i:final_ans)cout<<i<<" ";
  //   // for(int i=0;i<final_ans.size();i++){
  //     // cout<<final_ans[0]<<" ";
  //   // }
  // }
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> find_no(vector<int>no,int find,int i);
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>no(n);
//   cout<<"Enter "<<n<<" numbers : ";
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   vector<int>ans=find_no(no,find,0);
//   for(int i:ans)cout<<i<<" ";
// }
// // int i=0;
// vector<int> find_no(vector<int>no,int find,int i){
//   vector<int>ans;
//   if(i==no.size())return ans;
//   else if(no[i]==find)ans.push_back(i);

//   vector<int>temp=find_no(no,find,i+1);
//   ans.insert(ans.end(),temp.begin(),temp.end());
//   return ans;
// }


//Avoid global variale declaration
// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> find_no(vector<int>no,int find);
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>no(n);
//   cout<<"Enter "<<n<<" numbers : ";
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   vector<int>ans=find_no(no,find);
//   for(int i:ans)cout<<i<<" ";
// }
// int i=0;
// vector<int> find_no(vector<int>no,int find){
//   vector<int>ans;
//   if(i==no.size())return ans;
//   else if(no[i]==find)ans.push_back(i);
//   i++;
//   vector<int>temp=find_no(no,find);
//   ans.insert(ans.end(),temp.begin(),temp.end());
//   return ans;
// }


// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> find_no(vector<int>&no,int find,int i){
//   static vector<int>ans;
//   if(i==no.size())return ans;
//   else if(no[i]==find){
//     ans.push_back(i);
//   }
//     find_no(no,find,i+1);
//   if(i==0){
//     if(ans.empty())cout<<"Number "<<find<<" not found"<<endl;
//     else {
//       cout<<"Number "<<find<<" found at places : ";
//       for(int i:ans)cout<<i<<" ";
//     }
//   }
//   return ans;
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>no(n);
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   vector<int>final_ans=find_no(no,find,0);
//   // if(final_ans.empty())cout<<"Number "<<find<<" not found"<<endl;
//   // else {
//   //   cout<<"Number "<<find<<" found at positions : ";
//   //   for(int i:final_ans)cout<<i<<" ";
//   //   // for(int i=0;i<final_ans.size();i++){
//   //     // cout<<final_ans[0]<<" ";
//   //   // }
//   // }
// }


// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> find_no(vector<int>&no,int find,int i){
//   static vector<int>ans;
//   if(i==no.size())return ans;
//   else if(no[i]==find){
//     ans.push_back(i);
//   }
//   i++;
//     find_no(no,find,i);
//   if(i==1){
//     if(ans.empty())cout<<"Number "<<find<<" not found"<<endl;
//     else {
//       cout<<"Number "<<find<<" found at places : ";
//       for(int i:ans)cout<<i<<" ";
//     }
//   }
//   return ans;
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>no(n);
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   vector<int>final_ans=find_no(no,find,0);
//   // if(final_ans.empty())cout<<"Number "<<find<<" not found"<<endl;
//   // else {
//   //   cout<<"Number "<<find<<" found at positions : ";
//   //   for(int i:final_ans)cout<<i<<" ";
//   //   // for(int i=0;i<final_ans.size();i++){
//   //     // cout<<final_ans[0]<<" ";
//   //   // }
//   // }
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// int l=0;
// vector<int> find_no(vector<int>&no,int find,int i=0){
//   if(i==no.size())return no;
//   if(no[i]!=find){l++;no.erase(no.begin()+i);return find_no(no,find,i);}
//   else {
//     no[i]=l+i;
//     return find_no(no,find,i+1);
//   }
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>no(n);
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   vector<int>final_ans=find_no(no,find);
//   for(int i:no)cout<<i<<" ";
// }


//We cannot concatenate teo vectors like we do with string str=str1+str2;
//we have to use insert v1.insert(v1.end(),v2.begin(),v2.end());
// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> find_no(vector<int>no,int find,int i);
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>no(n);
//   cout<<"Enter "<<n<<" numbers : ";
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   vector<int>ans=find_no(no,find,0);
//   for(int i:ans)cout<<i<<" ";
// }
// // int i=0;
// vector<int> find_no(vector<int>no,int find,int i){
//   vector<int>ans;
//   if(i==no.size())return ans;
//   else if(no[i]==find)ans.push_back(i);

//   vector<int>temp=find_no(no,find,i+1);
//  ans.insert(ans.end(),temp.begin(),temp.end());
// // ans=ans+temp; //DW
//   return ans;
// }



// #include<iostream>
// #include<vector>
// using namespace std;
// int n;
// vector<int> find_no(vector<int>no,int find,int i);
// int main(){
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>no(n);
//   cout<<"Enter "<<n<<" numbers : ";
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   vector<int>ans=find_no(no,find,0);
//   for(int i:ans)cout<<i<<" ";
// }
// // int i=0;
// vector<int> find_no(vector<int>no,int find,int i){
//   vector<int>ans(n);
//   if(i==no.size())return ans;
//   else if(no[i]==find)ans.push_back(i);

//   // return (ans.insert(ans.end(),find_no(no,find,i+1).begin(),find_no(no,find,i+1).end()));
//   vector<int>temp=find_no(no,find,i+1);
//   // int j=0;
//   for(int j=ans.size();j<temp.size()+ans.size();j++){
//     ans[j]=temp[j-ans.size()];
//   }
// //ans=ans+temp; //DW
//   return ans;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// int n;
// vector<int> find_no(vector<int>no,int find,int i);
// int main(){
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>no(n);
//   cout<<"Enter "<<n<<" numbers : ";
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   vector<int>ans=find_no(no,find,0);
//   for(int i:ans)cout<<i<<" ";
// }
// vector<int> find_no(vector<int>no,int find,int i){
//   vector<int>ans;
//   if(i==no.size())return ans;
//   else if(no[i]==find)ans.push_back(i);
//   vector<int>temp=find_no(no,find,i+1);
//   for(int j=0;j<temp.size();j++){
//     ans.push_back(temp[j]);
//   }
//   return ans;
// }