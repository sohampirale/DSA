//Not accepted

// #include<iostream>
// using namespace std;
// int main(){
//   int T;
//   cin>>T;
//   for(int t=0;t<T;t++){
//     int n;
//     cin>>n;
//     int a1[n],a2[n],n1a1=0,nm1a1=0,n1a2=0,nm1a2=0,m1=0,m2=0;
//     for(int i=0;i<n;i++){
//       cin>>a1[i];
//       if(a1[i]==1)n1a1++;
//       else if(a1[i]==-1)nm1a1++;
//     }
//     for(int i=0;i<n;i++){
//       cin>>a2[i];
//       if(a2[i]==1)n1a2++;
//       else if(a2[i]==-1)nm1a2++;
//     }
//     for(int i=0;i<n;i++){
//        if(a1[i]>a2[i]&&a1[i]==1)m1++;
//       else if(a1[i]<a2[i]&&a2[i]==1)m2++;
//       else if(a1[i]==a2[i]){
//         if(a1[i]==1&&a2[i]==1){
//           if(nm1a1>nm1a2)m1++;
//           else if(nm1a1<nm1a2)m2++;
//           else if(nm1a1==nm1a2){
//             if(m1>m2)m2++;
//             else if(m1<m2)m1++;
//             else if(m1==m2){
//               if(n1a1>n1a2)m2++;
//               else if(n1a1<n1a2)m1++;
//               else if(n1a1==n1a2){m1++;}  //hi case yayla nhi pahije tehcnically
//             }
//           }
//         } else if(a1[i]==-1&&a2[i]==-1){
//           if(n1a1>n1a2)m1--;
//           else if(n1a1<n1a2)m2--;
//           else if(n1a1==n1a2){
//             if(m1>m2)m1--;
//             else if(m1<m2)m2--;
//             else if(m1==m2){
//               if(nm1a1>nm1a2)m2--;
//               else if(nm1a1<nm1a2)m1--;
//               else if(nm1a1==nm1a2){m1--;}
//             }
//           }
//         }
        
//       }
//       }
//     int ans=min(m1,m2);
//     cout<<ans<<endl;
//     }
//   }
