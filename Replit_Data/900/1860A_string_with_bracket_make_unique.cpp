// #include<iostream>
// using namespace std;
// void out_sym(int l);
// void in_sym(int l);
// int main(){
//   int te;
//   cin>>te;
//   for(int t=0;t<te;t++){
//     string s;
//     cin>>s;
//     int l=s.length();
//     if(l!=2){
//       int oppo=0,same=0,t=0;
//       for(int i=1;i<l;i++){
//         if(s[i-1]==s[i])same++;
//         else oppo++;
//         if(same==1){
//           t=1;
//           break;
//         }
//       }
//       if(t==1){
//         out_sym(2*l);
//       } else in_sym(2*l);
//     } else {
//       if(s[1]==s[0]){out_sym(4);}
//       else if(s[0]=='('&&s[1]==')'){
//         cout<<"NO"<<endl;
//         continue;
//       } else if(s[0]==')'&&s[1]=='(')
//       in_sym(4);
//     }
//   }
// }

// void out_sym(int l){
//   cout<<"YES"<<endl;
//   for(int i=0;i<l;i++){
//     if(i%2==0)cout<<"(";
//     else cout<<")";
//   }
//   cout<<endl;
// }
// void in_sym(int l){
//   cout<<"YES"<<endl;
//   for(int i=0;i<l;i++){
//     if(i<l/2)cout<<'(';
//     else cout<<')';
//   }
//   cout<<endl;
// }