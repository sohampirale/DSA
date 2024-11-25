 //Accepted
// class Solution {
// public:
//     int l;
//     int findPeak(MountainArray &mountainArr,int target,int st,int end){
//       int mid;
//       cout<<"hey"<<endl;
//       while(st!=end){
//         cout<<"hey"<<endl;
//         mid=st+(end-st)/2;
//         int midEle=mountainArr.get(mid);
//         if(midEle<mountainArr.get(mid+1))st=mid+1;
//         else {
//           end=mid;
//         }
//       }

//       cout<<"Peak found at : st = "<<st<<endl;
//       int left=findLeft(mountainArr,target,0,st);
//       int right=findRight(mountainArr,target,st,l-1);
//       cout<<"left = "<<left<<" & right = "<<right<<endl;
//       if(left==-1)return right;
//       else return left;
//     }

//     int findRight(MountainArray &mountainArr,int target,int st,int end){
//       int mid;
//         while(st<=end){
//             mid=st+(end-st)/2;
//             int midEle=mountainArr.get(mid);
//             if(midEle==target)return mid;
//             else if(midEle>target)st=mid+1;
//             else if(midEle<target)end=mid-1;
//         }
//       return -1;
//     }

//     int findLeft(MountainArray &mountainArr,int target,int st,int end){
//       int mid;
//         while(st<=end){
//             mid=st+(end-st)/2;
//             int midEle=mountainArr.get(mid);
//             if(midEle==target)return mid;
//             else if(midEle<target)st=mid+1;
//             else if(midEle>target)end=mid-1;
//         }
//       return -1;
//     }

//     int findInMountainArray(int target, MountainArray &mountainArr) {
//         cout<<"hi"<<endl;
//         l=mountainArr.length();
//         return findPeak(mountainArr,target,0,l-1);
//     }
// };