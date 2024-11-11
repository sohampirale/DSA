// //Soham Sachin Pirale
// //Roll no - 2022

// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;
// class pump{

//   public:
//     int petrol,dist,index;
//     pump(int petrol,int dist,int index){
//       this->petrol=petrol;
//       this->dist=dist;
//       this->index=index;
//     }
// };
// int main(){
//   int n;
//   cout<<"ENter how many petrol pumps are htere : ";
//   cin>>n;
//   int tp,td;
//   deque<pump>pumps;
//   for(int i=0;i<n;i++){
//     cout<<"Enter petrol present at petrol pump "<<i+1<<" : ";
//     cin>>tp;
//     cout<<"Enter distance of next petrol pump : ";
//     cin>>td;
//     pump p(tp,td,i);
//     pumps.push_back(p);
//   }
//     int i=0;
//     int curr=0,test=0;
//     int j=pumps.front().index;
//     do{
//       curr+=pumps.front().petrol;
//       curr-=pumps.front().dist;
//       while(curr<0){
//         i++;
//         test=1;
//         cout<<"curr = "<<curr<<" & petrol pump at front is : "<<pumps.front().index<<endl;
//         curr=0;
//         j=pumps.front().index;
//         curr+=pumps.front().petrol;
//         curr-=pumps.front().dist;
//         if(i==n){
//           cout<<"Not possible"<<endl;
//           return 0;
//         }
//         pumps.push_back(pumps.front());
//         pumps.pop_front();
//       }
//       if(test==0){
//         pumps.push_back(pumps.front());
//         pumps.pop_front();
//       } else test=0;
//     }while(j!=pumps.front().index);
//     cout<<"It is possible from start = "<<j<<endl;
// }

// // //leetcode (https://leetcode.com/problems/gas-station/) -time limit exceeded at the second last case

// // class pump{

// //     public:
// //         int petrol,dist,index;
// //         pump(int petrol,int dist,int index){
// //             this->petrol=petrol;
// //             this->dist=dist;
// //             this->index=index;
// //         }
// // };

// // class Solution {
// // public:

// //     int ans(vector<int>&pumpss,vector<int>&dist,int n){
// //          deque<pump>pumps;
// //         for(int i=0;i<n;i++){
// //             pump p(pumpss[i],dist[i],i);
// //             pumps.push_back(p);
// //         }
// //             int i=0;
// //             int curr=0,test=0;
// //             int j=pumps.front().index;
// //             do{
// //             curr+=pumps.front().petrol;
// //             curr-=pumps.front().dist;
// //             while(curr<0){
// //                 i++;
// //                 test=1;
// //                 cout<<"curr = "<<curr<<" & petrol pump at front is : "<<pumps.front().index<<endl;
// //                 curr=0;
// //                 j=pumps.front().index;
// //                 curr+=pumps.front().petrol;
// //                 curr-=pumps.front().dist;
// //                 if(i==n+1){
// //                 cout<<"Not possible"<<endl;
// //                 return -1;
// //                 }
// //                 pumps.push_back(pumps.front());
// //                 pumps.pop_front();
// //             }
// //             if(test==0){
// //                 pumps.push_back(pumps.front());
// //                 pumps.pop_front();
// //             } else test=0;
// //             }while(j!=pumps.front().index);
// //             cout<<"It is possible start = "<<j<<endl;
// //             return j;
// //         }
// //     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
// //        return ans(gas,cost,gas.size());
// //     }
// // };