// #include<iostream>
// #include<vector>
// using namespace std;
// int s=0,e,m;
// int find_no(vector<int>no,int find){
//   m=(s+e)/2;
  
//   if(no[m]==find)return m;
//   // else if(no[s]==find)return s;//Not necessary
//   // else if(no[e]==find)return e;//Not necessary
//   else if(e<s)return -1;
//   if(no[s]<=no[m]){
//     if(find>no[s]&&find<no[m]){
//       e=m-1;
//     } else {
//       s=m+1;
//     }
//   } else {
//     if(find>no[s]&&find<no[m]){
//       e=m-1;
//     } else {
//       s=m+1;
//     }
//   }
//   return find_no(no,find);
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   e=n-1;
//   m=(s+e)/2;
//   vector<int>no(n);
//   cout<<"Enter "<<n<<" elements : ";
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   int ans=find_no(no,find);
//   if(ans!=-1)cout<<"Number "<<find<<" at the position "<<ans<<endl;
//   else cout<<"Number "<<find<<" not found"<<endl;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// int find_no(vector<int>&no,int find){
//   static int m=(no.size()-1)/2;
//   if(no)
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<int>no(n);
//   cout<<"Enter "<<n<<" numbers : ";
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the number you want to find : ";
//   cin>>find;
  
// }
// Enter n : 6
// Enter 6 elements : 6
// 7
// 8
// 9
// 1
// 2
// Enter the no you want to find : 2
// Number 2 at the position 5


  // Enter n : 9
  // Enter 9 elements : 7
  // 8
  // 9
  // 1
  // 2
  // 3
  // 4
  // 5
  // 6
  // Enter the no you want to find : 5
  // Number 5 at the position 7

// #include<iostream>
// #include<vector>
// using namespace std;
// int s=0,e,m;
// int find_no(vector<int>no,int find,int s,int e){
//   int m=(s+e)/2;

//   if(no[m]==find)return m;
//   // else if(no[s]==find)return s;//Not necessary
//   // else if(no[e]==find)return e;//Not necessary
//   else if(e<s)return -1;
//   if(no[s]<=no[m]){
//     if(find>no[s]&&find<no[m]){
//       return find_no(no,find,s,m-1);
//     } else {
//       return find_no(no,find,m+1,e);
//     }
//   } else {
//     if(find>no[s]&&find<no[m]){
//       return find_no(no,find,s,m-1);
//     } else {
//       return find_no(no,find,m+1,e);
//     }
//   }
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   e=n-1;
//   m=(s+e)/2;
//   vector<int>no(n);
//   cout<<"Enter "<<n<<" elements : ";
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   int ans=find_no(no,find,0,e);
//   if(ans!=-1)cout<<"Number "<<find<<" at the position "<<ans<<endl;
//   else cout<<"Number "<<find<<" not found"<<endl;
// }




// #include<iostream>
// #include<vector>
// using namespace std;
// int s=0,e,m;
// int find_no(vector<int>no,int find,int s,int e){
//    if(e<s)return -1;
//   m=(s+e)/2;
//   if(find==no[m])return m;
//   if(no[s]<=no[m]){
//     if(find>=no[s]&&find<=no[m]){
//       // e=m-1;
//       return find_no(no,find,s,m-1);
//     } else {
//       // s=m+1;
//       return find_no(no,find,m+1,e);

//     }
//   }
  
//   if(find>=no[m]&&find<=no[e]){  return find_no(no,find,m+1,e);}
//  return find_no(no,find,s,m-1);
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   e=n-1;
//   m=(s+e)/2;
//   vector<int>no(n);
//   cout<<"Enter "<<n<<" elements : ";
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   int ans=find_no(no,find,0,e);
//   if(ans!=-1)cout<<"Number "<<find<<" at the position "<<ans<<endl;
//   else cout<<"Number "<<find<<" not found"<<endl;
// }


//DW
// #include<iostream>
// #include<vector>
// using namespace std;
// int s=0,e,m;
// int find_no(vector<int>no,int find,int s,int e){
//    if(e<s)return -1;
//   m=(s+e)/2;
//   if(find==no[m])return m;
//   else if(find==no[s])return s;
//   else if(find==no[e])return e;
  
//     if(find>=no[s]&&find<=no[m]){
//       e=m-1;
//     } else if(find>=no[m]&&find<=no[e]){
//       s=m+1;
//     } else if(find<no[m]&&find<=no[e]){
//       s=m+1;
//     } else if(find>=no[m]&&find<=no[e]){
//       e=m-1;
//     }
//   return find_no(no,find,s,e);

// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   e=n-1;
//   m=(s+e)/2;
//   vector<int>no(n);
//   cout<<"Enter "<<n<<" elements : ";
//   for(int i=0;i<n;i++)cin>>no[i];
//   int find;
//   cout<<"Enter the no you want to find : ";
//   cin>>find;
//   int ans=find_no(no,find,0,e);
//   if(ans!=-1)cout<<"Number "<<find<<" at the position "<<ans<<endl;
//   else cout<<"Number "<<find<<" not found"<<endl;
// }