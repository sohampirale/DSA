// class Solution {
// public:
//     char nextGreatestLetter(vector<char>& letters, char target) {
//         int start=0,end=letters.size()-1;
//         if(target<letters[start]||letters[end]<target)return 0;
//         while(start<=end){
//             int mid=start+(end-start)/2;
//             if(target>=letters[mid])start=mid+1;
//             else if(target<letters[mid])end=mid-1;
//         }
//         return start; 
//     }
// };

// class Solution {
// public:
//     char nextGreatestLetter(vector<char>& letters, char target) {
//         int start=0,end=letters.size()-1;
//         if(target<letters[start]||letters[end]<target){cout<<"hi"<<endl;return letters[0];}
//         while(start<=end){
//             int mid=start+(end-start)/2;
//             if(target>=letters[mid])start=mid+1;
//             else if(target<letters[mid])end=mid-1;
//         }
//         return letters[start%letters.size()]; 
//     }
// };