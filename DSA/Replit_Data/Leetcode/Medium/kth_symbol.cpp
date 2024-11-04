// #include<iostream>
// using namespace std;
// class Solution {
//     string ans="0";
//     int j=2;
// public:
//     int kthGrammar(int n, int k) {
//       cout<<"Entered here"<<endl;
//         if(j==n+1){
//             int a=ans[k-1]-'0';
//             return a; 
//         }
//         int l=ans.length();
//         for(int i=0;i<l;i++){
//             if(ans[i]=='0')ans.insert(i+1,"1");
//             else if(ans[i]=='1')ans.insert(i,"0");
//         }
//         j++;
//         return kthGrammar(n,k);
//     }
// };
// int main(){
//   int n,k;
//   cout<<"Enter n & k : ";
//   cin>>n>>k;
//   Solution s1;
//   int ans=s1.kthGrammar(n, k);
//   cout<<"Answer is : "<<ans<<endl;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// void display(vector<vector<string>>&board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board.size();j++){
//       cout<<board[i][j]<<" ";
//     }
//     cout<<endl;
//   }
// }
// void Solution(vector<vector<string>>&board,int n,int y=1){
//   if(y==board.size()){
//     display(board);
//     return;
//   }
//   for(int i=0;i<board.size();i++){
//     if(board[y-1][i]=="0")board[y][i]+="1";
//     else if(board[y-1][i]=="1")board[y][i]="10";
//   }
//   Solution(board,n,y+1);
// }
// int main(){
//   int n;
//   cin>>n;
//   vector<vector<string>>board(n,vector<string>(n,"0"));
//   display(board);
//   Solution(board , n);
// }