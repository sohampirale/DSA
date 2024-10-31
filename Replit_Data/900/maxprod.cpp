// #include <iostream>
// #include <cmath>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         unsigned long long x, y;
//         cin >> x >> y;
//         unsigned long long n = x, i = 0;
//         while (n != 0) {
//             n /= 10;
//             i++;
//         }
//         unsigned long long newp, oldp = x * y;
//       unsigned long long j;
//         for (j = i - 1; j >= 0; j--) {
//             unsigned long long t1, t2, d1, d2, a, b, n1 = x, n2 = y, di1 = pow(10, j), di2 = pow(10, j);
//             d1 = n1 % di1;
//             d2 = n2 % di2;
//             t1 = n1 / di1;
//             t2 = n2 / di2;
//             n1 = t1 / 10;
//             n2 = t2 / 10;
//             a = t1 % 10;
//             b = t2 % 10;
//             n1 = (((n1 * 10) + b) * di1) + d1;
//             n2 = (((n2 * 10) + a) * di2) + d2;
//             newp = n1 * n2;
//             if (newp >= oldp) {
//                 oldp = newp;
//                 x = n1;
//                 y = n2;
//             }
//         }
//         cout << x << endl << y << endl;
//     }
//     return 0;
// }



// #include<iostream>
// #include<cmath>
// using namespace std;
// int main(){
//   int t;
//   cin>>t;
//   while(t!=0){
//    long long x,y;
//     cin>>x>>y;
//     long long n=x,i=0;
//    while(n!=0){
//       n/=10;
//       i++;
//     }
//     long long newp,oldp=x*y;
//     long long j;
//     for(j=i-1;j>=0;j--){
//       long long t1,t2,d1,d2,a,b,n1=x,n2=y,di1=pow(10,j),di2=pow(10,j);
//       d1=n1%di1;
//       d2=n2%di2;
//       t1=n1/di1;
//       t2=n2/di2;
//       n1=t1/10;
//       n2=t2/10;
//       a=t1%10;
//       b=t2%10;
//       n1=(((n1*10)+b)*di1)+d1;
//       n2=(((n2*10)+a)*di2)+d2;
//       newp=n1*n2;
//       if(newp>=oldp){
//         oldp=newp;
//         x=n1;
//         y=n2;
//       }
//     }
//     cout<<x<<endl<<y<<endl;
//     t--;
//   }
// }
// #include<iostream>
// #include<cmath>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         unsigned long long x, y; // Use unsigned long long for product calculation
//         cin >> x >> y;
//         long long n = x, i = 0;
//         while (n != 0) {
//             n /= 10;
//             i++;
//         }
//         unsigned long long newp, oldp = x * y; // Use unsigned long long for product calculation
//         for (long long j = i - 1; j >= 0; j--) {
//             long long t1, t2, d1, d2, a, b, n1 = x, n2 = y;
//             unsigned long long di1 = pow(10, j), di2 = pow(10, j); // Use unsigned long long for power calculation
//             d1 = n1 % di1;
//             d2 = n2 % di2;
//             t1 = n1 / di1;
//             t2 = n2 / di2;
//             n1 = t1 / 10;
//             n2 = t2 / 10;
//             a = t1 % 10;
//             b = t2 % 10;
//             n1 = (((n1 * 10) + b) * di1) + d1;
//             n2 = (((n2 * 10) + a) * di2) + d2;
//             newp = n1 * n2;
//             if (newp >= oldp) {
//                 oldp = newp;
//                 x = n1;
//                 y = n2;
//             }
//         }
//         cout << x << endl << y << endl;
//     }
//     return 0;
// }


// #include<iostream>
// #include<cmath>
// using namespace std;
// int main(){
//   int t;
//   cin>>t;
//   while(t!=0){
//    long long x,y;
//     cin>>x>>y;
//     long long n=x,i=0;
//    while(n!=0){
//       n/=10;
//       i++;
//     }
//     long long newp,oldp=x*y;
//     long long j;
//     for(j=i-1;j>=0;j--){
//       long long t1,t2,d1,d2,a,b,n1=x,n2=y,di1=pow(10,j),di2=pow(10,j);
//       d1=n1%di1;
//       d2=n2%di2;
//       t1=n1/pow(10,j);
//       t2=n2/pow(10,j);
//       n1=t1/10;
//       n2=t2/10;
//       a=t1%10;
//       b=t2%10;
//       n1=(((n1*10)+b)*(pow(10,j)))+d1;
//       n2=(((n2*10)+a)*pow(10,j))+d2;
//       newp=n1*n2;
//       if(newp>oldp){
//         oldp=newp;
//         x=n1;
//         y=n2;
//       }
//     }
//     cout<<x<<endl<<y<<endl;
//     t--;
//   }
// }

// #include<iostream>
// #include<cmath>
// using namespace std;
// int main(){
//   int t;
//   cin>>t;
//   while(t!=0){
//     int x,y;
//     cin>>x>>y;
//     int n=x,i=0;
//    while(n!=0){
//       n/=10;
//       i++;
//     }
//     int newp,oldp=x*y;
//     for(int j=i-1;j>=0;j--){
//       int t1,t2,d1,d2,a,b,n1=x,n2=y,di1=pow(10,j),di2=pow(10,j);
//       d1=n1%di1;
//       d2=n2%di2;
//       t1=n1/pow(10,j);
//       t2=n2/pow(10,j);
//       n1=t1/10;
//       n2=t2/10;
//       a=t1%10;
//       b=t2%10;
//       n1=(((n1*10)+b)*(pow(10,j)))+d1;
//       n2=(((n2*10)+a)*pow(10,j))+d2;
//       newp=n1*n2;
//       if(newp>oldp){
//         oldp=newp;
//         x=n1;
//         y=n2;
//       }
//     }
//     cout<<x<<endl<<y<<endl;
//     t--;
//   }
// }
// // 422545136
// // 587753881

// // Output
// // 582545136
// // 427753881

// // Answer
// // 522543131
// // 487755886