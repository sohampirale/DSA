// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
//   int n,next;
//   cout<<"Enter a number : ";
//   cin>>n;
//   next=n;
//   string t;
//   while(next!=1){
//     next=0;
//     t=to_string(n);
//     for(int i=0;i<t.length();i++){
//       next+=(pow((t[i]-'0'),2));
//     }
//     n=next;
//     if(next==37){
//       cout<<"Not a happy number"<<endl;
//       return 0;
//     }
//     t.clear();
//   }
//   cout<<"Entered number is a happy number"<<endl;
// }






// // #include<iostream>
// // #include<string>
// // #include<math.h>
// // #include<vector>
// // #include<algorithm>
// // using namespace std;
// // class node{
// // public :
// // int no;
// // node*next;
// // node(int data) : no(data){}
// // };
// // bool ans(int n,vector<int>&nos){
// //   node*start=new node(n);
// //   nos.push_back(n);
// //   node*temp=start,*one_node;
// //   int next=0;
// //   while(1){
// //   string t=to_string(temp->no);
// //   for(int i=0;i<t.length();i++){
// //     next+=(pow(t[i],2));
// //   }
// //   if(next==1)return true;
// //   else{
// //     one_node=new node(next);
// //     if(nos.begin(),nos.end(),next)return false;
// //     temp->next=one_node;
// //     temp=one_node;
// //     addr.push_back(one_node);
// //     next=0;
// //   }
// //   }
// // }
// // int main(){
// //   vector<int>nos;
// //   int n;
// //   cout<<"Enter a number : ";
// //   cin>>n;
// //   bool solution=ans(n,nos);
// //   if(solution)cout<<"You have entered a happy number"<<endl;
// //   else cout<<"Not a happy number"<<endl;
// // }