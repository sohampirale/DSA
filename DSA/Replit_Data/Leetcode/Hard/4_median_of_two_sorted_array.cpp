// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         double med;
//         int m=nums1.size(),n=nums2.size();
//         int t=m+n,p,no[2],pt=0;
//         if(t%2==0){
//             p=(t/2)-1;
//         } else p=(t/2);
//         if(m==0){
//             if(t%2==0){
//                 med=(static_cast<double>(nums2[p+1])+static_cast<double>(nums2[p]))/2;
//                 return med;
//             } else {
//                 return nums2[p];
//             }
//         } else if(n==0){
//             if(t%2==0){
//                 med=(static_cast<double>(nums1[p+1])+static_cast<double>(nums1[p]))/2;
//                 return med;
//             } else {
//                 return nums1[p];
//             }
//         }
//         int i=0,j=0,cnt=-1;
//         while(p!=-1){
//             if(nums1[i]==nums2[j]){
//                 cnt++;
//                 if(cnt==p){
//                     no[pt]=nums1[i];
//                     pt++;
//                 }
//                 i++;
//                 if(i==m){
//                     i--;
//                     nums1[i]=2147483647;
//                 }
//             } else if(nums1[i]<nums2[j]){
//                 cnt++;
//                 if(cnt==p){
//                     no[pt]=nums1[i];
//                     pt++;
//                 }
//                 i++;
//                 if(i==m){
//                     i--;
//                     nums1[i]=2147483647;
//                 }
//             } else if(nums2[j]<nums1[i]){
//                 cnt++;
//                 if(cnt==p){
//                    no[pt]=nums2[j];
//                     pt++;
//                 }
//                 j++;
//                 if(j==n){
//                     j--;
//                     nums2[j]=2147483647;
//                 }
//             }
//             if(t%2==0&&pt==1)p++;
//             if(pt>1&&t%2==0)p=-1;
//             else if(pt>0&&t%2==1)p=-1;
//         }
//         if(t%2==0) med =(static_cast<double>(no[0])+static_cast<double>(no[1]))/2;
//         else med=no[0];
//         return med;
//     }
// };
// int main(){
//     vector<int>nums1;
//     vector<int>nums2;
//     int m,n,no;
//     cin>>m>>n;
//     cout<<"Enter "<<m<<" elements of vector 1 : ";
//     for(int i=0;i<m;i++){
//         cin>>no;
//         nums1.push_back(no);
//     }
//     cout<<"Enter "<<n<<" elements of vector 2 : ";
//     for(int i=0;i<n;i++){
//         cin>>no;
//         nums2.push_back(no);
//     }
//     Solution s;
//     double med=s.findMedianSortedArrays(nums1, nums2);
//     cout<<med<<endl;
// }

// // #include<iostream>
// // #include<algorithm>
// // #include<vector>
// // using namespace std;
// // class Solution {
// // public:
// //     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
// //         // cout<<"Entered function : ";
// //         double med;
// //         int m=nums1.size(),n=nums2.size();
// //         int t=m+n,p,no[2],pt=0;
// //         if(t%2==0){
// //             p=(t/2)-1;
// //         } else p=(t/2);
// //         int i=0,j=0,cnt=-1;
// //         while(p!=0){
// //             if(nums1[i]==nums2[j]){
// //                 cnt++;
// //                 if(cnt==p){
// //                     no[pt]=nums1[i];
// //                     pt++;
// //                 }
// //                 i++;
// //                 if(i==m){
// //                     i--;
// //                     nums1[i]=2147483647;
// //                 }
// //             } else if(nums1[i]<nums2[j]){
// //                 cnt++;
// //                 if(cnt==p){
// //                     no[pt]=nums1[i];
// //                     pt++;
// //                 }
// //                 i++;
// //                 if(i==m){
// //                     i--;
// //                     nums1[i]=2147483647;
// //                 }
// //             } else if(nums2[j]<nums1[i]){
// //                 cnt++;
// //                 if(cnt==p){
// //                    no[pt]=nums2[j];
// //                     pt++;
// //                 }
// //                 j++;
// //                 if(j==n){
// //                     j--;
// //                     nums2[j]=2147483647;
// //                 }
// //             }
// //             if(t%2==0&&pt==1)p++;
// //             if(pt>1&&t%2==0)p=0;
// //             else if(pt>0&&t%2==1)p=0;
// //         }
// //         // cout<<"Median is : ";
// //         // if(t%2==0)cout<<static_cast<double>(no[0]+no[1])/2;
// //         // else cout<<no[0];
// //         if(t%2==0) med =(static_cast<double>(no[0])+static_cast<double>(no[1]))/2;
// //         else med=no[0];
// //         // cout<<"value or no[0] is : "<<static_cast<double>(no[0])<<"\nValue of no[1] is : "<<static_cast<double>(no[1])<<endl;
// //         return med;
// //     }
// // };
// // int main(){
// //     vector<int>nums1;
// //     vector<int>nums2;
// //     int m,n,no;
// //     cin>>m>>n;
// //     cout<<"Enter "<<m<<" elements of vector 1 : ";
// //     for(int i=0;i<m;i++){
// //         cin>>no;
// //         nums1.push_back(no);
// //     }
// //     cout<<"Enter "<<n<<" elements of vector 2 : ";
// //     for(int i=0;i<n;i++){
// //         cin>>no;
// //         nums2.push_back(no);
// //     }
// //     Solution s;
// //     double med=s.findMedianSortedArrays(nums1, nums2);
// //     cout<<med<<endl;
// // }