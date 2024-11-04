// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//   int te;
//   cin >> te;
//   for (int t = 0; t < te; t++) {
//     int n, sno;
//     cin >> n;
//     vector<long long> no;
//     vector<long long> in_no;
//     for (int i = 0; i < n; i++) {
//       cin >> sno;
//       no.push_back(sno);
//     }
//     long long mx = no[0];
//     for (int i = 1; i < n; i++) {
//       if (no[i] < mx) {
//         in_no.push_back(mx - no[i]);
//       } else if (no[i] >= mx)
//         mx = no[i];
//     }
//     int l = in_no.size();
//     int ol = l;
//     sort(in_no.begin(), in_no.end());
//     long long cost = 0;
//     long long diff;
//     if (l == 1) {
//       cout << in_no[0] * 2 << endl;
//     } else {
//       for (int i = 0; i < ol - 1; i++) {
//         if (i == 0) {
//           cost += in_no[0] * (l + 1);
//         }
//         diff = in_no[i + 1] - in_no[i];
//         cost += (diff * l);
//         l--;
//       }
//       cout << cost << endl;
//     }
//   }
// }


// // //With int

// // #include<iostream>
// // #include<algorithm>
// // #include<vector>
// // using namespace std;
// // int main(){
// //   int te;
// //   cin>>te;
// //   for(int t=0;t<te;t++){
// //     int n,sno;
// //     cin>>n;
// //     vector<int>no;
// //     vector<int>in_no;
// //     for(int i=0;i<n;i++){

// //       cin>>sno;
// //       no.push_back(sno);
// //     }
// //     int mx=no[0];
// //     for(int i=1;i<n;i++){
// //       if(no[i]<mx){
// //         in_no.push_back(mx-no[i]);
// //       } else if(no[i]>=mx)mx=no[i];
// //     }
// //     int l=in_no.size();
// //     int ol=l;
// //     sort(in_no.begin(),in_no.end());
// //     int cost=0;
// //     int diff;
// //     if(l==1){cout<<2<<endl;continue;}
// //     for(int i=0;i<ol-1;i++){
// //       if(i==0){cost+=in_no[0]*(l+1);}
// //       diff=in_no[i+1]-in_no[i];
// //       cost+=(diff*l);
// //       l--;
// //     }
// //     cout<<cost<<endl;
// //     }
// // }
