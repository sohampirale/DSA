// //practice
// #include<iostream>
// #include<vector>
// using namespace std;
// int cnt=0;
// void display(vector<vector<int>>&board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board.size();j++){
//       cout<<board[i][j]<<" |";
//     }
//     cout<<endl;
//   }
// }
// int safe(vector<vector<int>>&board,int x,int y){
//   if(x>1&&y>0)if(board[y-1][x-2]!=0)return 0;
//   if(x<board.size()-2&&y>0)if(board[y-1][x+2]!=0)return 0;
//   if(x>0&&y>1)if(board[y-2][x-1]!=0)return 0;
//   if(x<board.size()-1&&y>1)if(board[y-2][x+1]!=0)return 0;
//   return 1;
// }
// void solution(vector<vector<int>>&board,int n,int x=0,int y=0){
//   if(n==0){
//     cout<<"All "<<board.size()-1<<" knights placed"<<endl;
//     cnt++;
//     cout<<"Count = "<<cnt<<endl;
//     display(board);
//     return;
//   }
//   else if(x==board.size()){
//     solution(board,n,0,y+1);
//     return;
//   }
//   else if(y==board.size()){
//       cout<<"All "<<board.size()-1<<" knights couldn't be placed"<<endl;
//     display(board);
//     return;
//   }
//   if(safe(board,x,y)){
//     board[y][x]=n;
//     solution(board,n-1,x+1,y);
//     board[y][x]=0;
//   }
//   solution(board,n,x+1,y);
// }

// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<vector<int>>board(n,vector<int>(n,0));
//   display(board);
//   solution(board,n);
//   cout<<"Total number of possible solutions are : "<<cnt<<endl;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// void display(vector<vector<int>>&board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board.size();j++){
//       cout<<board[i][j]<<" |";
//     }
//     cout<<endl;
//   }
// }
// int ans=0;
// int safe(vector<vector<int>>&board,int x,int y){
//   if(y>0&&x>1)if(board[y-1][x-2]!=0)return 0;
//   if(y>0&&x<board.size()-2)if(board[y-1][x+2]!=0)return 0;
//   if(y>1&&x>0)if(board[y-2][x-1]!=0)return 0;
//   if(y>1&&x<board.size()-1)if(board[y-2][x+1]!=0)return 0;
//   return 1;
// } 
// void Nknights(vector<vector<int>>&board,int n,int x=0,int y=0){
//   if(n==0){
//     cout<<"All knights placed"<<endl;
//     cout<<"x = "<<x<<" & y = "<<y<<endl;
//     display(board);
//     return;
//   }
//   if(y==board.size()){
//     ans++;
//     cout<<ans<<" knights placed"<<endl;
//     display(board);
//     return;
//   }
//   if(x>=board.size()){
//     Nknights(board,n,0,y+1);
//     cout<<"After coming out of that function call x = "<<x<<" & y = "<<y<<endl;
//     return;
//   }
//   // for(int i=0;i<board.size();i++){
//   if(safe(board,x,y)){
//     // cout<<"i = "<<i<<" & y = "<<y<<endl;
//     board[y][x]=n;
//       Nknights(board,n-1,x+1,y);
//     board[y][x]=0;
//   }
//   Nknights(board,n,x+1,y);
//   // }
// }
// int main(){
//   int n;
//   cout<<"Enter a number for NxN board : ";
//   cin>>n;
//   vector<vector<int>>board(n,vector<int>(n,0));
//   display(board);
//   Nknights(board,n);
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// int ans=0;
// void display(vector<vector<int>>&board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board.size();j++){
//       cout<<board[i][j]<<" |";
//     }
//     cout<<endl;
//   }
// }
// int safe(vector<vector<int>>&board,int x,int y){
//   if(y>0&&x>1)if(board[y-1][x-2]!=0)return 0;
//   if(y>0&&x<board.size()-2)if(board[y-1][x+2]!=0)return 0;
//   if(y>1&&x>0)if(board[y-2][x-1]!=0)return 0;
//   if(y>1&&x<board.size()-1)if(board[y-2][x+1]!=0)return 0;
//   return 1;
// } 
// void Nknights(vector<vector<int>>&board,int n,int x=0,int y=0){
//   if(n==0){
//     ans++;
//     cout<<"n == 0 for x= "<<x<<" & y = "<<y<<endl;
//     display(board);
//     return;
//   } else if(x==board.size()){
//     Nknights(board,n,0,y+1);
//     return;
//   }
//   else if(y==board.size()){
//     cout<<"All knights not placed"<<endl;
//     display(board);
//     return;
//   }
//   else if(safe(board,x,y)){
//     board[y][x]=n;
//     Nknights(board,n-1,x+1,y);
//     board[y][x]=0;
//   } 
//   Nknights(board,n,x+1,y);
// }
// // if(safe(board,x,y)){
// //   board[y][x]=n;
// //   Nknights(board,n-1,x+1,y);
// //   board[y][x]=0;
// // }

// // Nknights(board,n,x+1,y);
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<vector<int>>board(n,vector<int>(n,0));
//   Nknights(board,n);
//   cout<<"Number of answers possible are : "<<ans<<endl;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// void display(vector<vector<int>>&board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board.size();j++){
//       cout<<board[i][j]<<" |";
//     }
//     cout<<endl;
//   }
// }
// int safe(vector<vector<int>>&board,int x,int y){
//   if(y>0&&x>1)if(board[y-1][x-2]!=0)return 0;
//   if(y>0&&x<board.size()-2)if(board[y-1][x+2]!=0)return 0;
//   if(y>1&&x>0)if(board[y-2][x-1]!=0)return 0;
//   if(y>1&&x<board.size()-1)if(board[y-2][x+1]!=0)return 0;
//   return 1;
// } 
// void Nknights(vector<vector<int>>&board,int n,int x=0,int y=0){
//   if(n==0){
//     cout<<"n == 0 for x= "<<x<<" & y = "<<y<<endl;
//     display(board);
//     return;
//   } else if(x==board.size()){
//     Nknights(board,n,0,y+1);
//     return;
//   }else if(y==board.size()){
//     cout<<"All knights not placed"<<endl;
//     display(board);
//     return;
//   }
//   else if(safe(board,x,y)){
//     board[y][x]=n;
//     Nknights(board,n-1,x+1,y);
//     board[y][x]=0;
//     // if(x!=board.size()-1&&y!=board.size()-1)Nknights(board,n,x+1,y);
//   } 
//   Nknights(board,n,x+1,y);
// }
// // if(safe(board,x,y)){
// //   board[y][x]=n;
// //   Nknights(board,n-1,x+1,y);
// //   board[y][x]=0;
// // }

// // Nknights(board,n,x+1,y);
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<vector<int>>board(n,vector<int>(n,0));
//   Nknights(board,n);
// }