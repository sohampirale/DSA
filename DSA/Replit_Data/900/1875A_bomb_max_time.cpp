// #include<iostream>
// using namespace std;
// int main(){
//   int te;
//   cin>>te;
//   for(int t=0;t<te;t++){
//     long long a,b,c;
//     cin>>a>>b>>c;
//     long long no[c];
//     for(int i=0;i<c;i++)cin>>no[i];
//     long long i=0,sec=0;
//     while(1){
//       if(b>1){
//         sec+=(b-1);
//         b=1;
//       }
//       if(b==1){
//         if(i==c){
//           sec+=b;
//           cout<<sec<<endl;
//           break;
//         } else {
//           b+=no[i];
//           if(b>a)b=a;
//           i++;
//         }
//       }
//     }
//   }
// }