// //my solution
// #include<iostream>
// #include<vector>
// using namespace std;
// vector<vector<string>>final_ans;
// int fill_test_hori(vector<string>&board,int y){
//   for(int i=0;i<9;i++)if(board[y][i]=='.')return 0;
//   return 1;
// }
// int fill_test(vector<string>&board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board.size();j++){
//       if(board[i][j]=='.')return 0;
//     }
//   }
//   return 1;
// }
// void display_final_ans(vector<string>&board){
//   for(int k=0;k<final_ans.size();k++){
//     cout<<"Answer no : "<<k+1<<endl;
//   for(int i=0;i<9;i++){
//     for(int j=0;j<9;j++){
//       cout<<final_ans[k][i][j]<<" |";
//     }
//     cout<<endl;
//   }
//   }
//   cout<<"Total number of ways we can solve this sudoku is : "<<final_ans.size()<<endl;
// }
// void display(vector<string>&board){
//   for(int i=0;i<9;i++){
//     for(int j=0;j<9;j++){
//       cout<<board[i][j]<<" |";
//     }
//     cout<<endl;
//   }
// }
// int verticle(vector<string>&board,int x,int y,char ch){
//   for(int i=0;i<9;i++){
//     if(board[i][x]==ch)return 0;
//   }
//   return 1;
// }
// int horizontal(vector<string>&board,int x,int y,char ch){
//   for(int i=0;i<9;i++){
//     if(board[y][i]==ch)return 0;
//   }
//   return 1;
// }
// int box(vector<string>&board,int x,int y,char ch){
//   int sx=x-(x%3),sy=y-(y%3);
//   for(int i=sy;i<sy+3;i++){
//     for(int j=sx;j<sx+3;j++){
//       if(board[i][j]==ch)return 0;
//     }
//   }
//   return 1;
// }
// int test(vector<string>&board,int x,int y,char ch){
//   int test1=verticle(board,x,y,ch);
//   int test2=horizontal(board,x,y,ch);
//   int test3=box(board,x,y,ch);
//   int ans=test1&&test2&&test3;
//   return ans;
// }
// void solver (vector<string>&board,int x=0,int y=0){
//   if(x==board.size()){
//     if(fill_test_hori(board,y)){
//       solver(board,0,y+1);
//       return;
//     } else return;
//   }
//   if(y==board.size()){
//     // while(1){
//     // cout<<"Answer found"<<endl;
//     // display(board);
//     final_ans.push_back(board);
//     // }
//     return;
//   }
//   if(board[y][x]=='.'){
//     for(int i=1;i<=9;i++){
//       char ch='0' + i;
//       // cout<<"Checking for char = "<<ch<<endl;
//     if(test(board,x,y,ch)){
//       board[y][x]=ch;
//       solver(board,x+1,y);
//       board[y][x]='.';
//     } else if(i==9)return;
//     }
//   } else solver(board,x+1,y);
// }
// int main(){
//     // vector<string>board={"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
//   // vector<string>board={"..9.7.8.1","...4.3..6","3.......9","1.9.....7","...7.4...","8.....5.3","6.......2","5..1.8...","4.3.6.7.."};
//   // vector<string> board = {//1 solution
//   //     "53..7....",
//   //     "6..195...",
//   //     ".98....6.",
//   //     "8...6...3",
//   //     "4..8.3..1",
//   //     "7...2...6",
//   //     ".6....28.",
//   //     "...419..5",
//   //     "....8..79"
//   // };
//   // vector<string> board = {
//   //     "4..2.3...",
//   //     ".3..1...6",
//   //     "5..6.....",
//   //     "7...2...1",
//   //     "6..5.4..9",
//   //     "1...9...8",
//   //     ".....2..3",
//   //     "2...3..5.",
//   //     "...7.1..4"
//   // };
//   // vector<string> board = {//no of solutions - 214391
//   //     "1.....2..",
//   //     "..3.4....",
//   //     "...5.6...",
//   //     "4.......5",
//   //     "..7...8..",
//   //     "6.......1",
//   //     "...8.7...",
//   //     "....1.4..",
//   //     ".2.....3."
//   // };
//     display(board);
//     solver(board);
//     display_final_ans(board);
// }





// #include<iostream>
// #include<vector>
// using namespace std;
// int fill_test_hori(vector<string>&board,int y){
//   for(int i=0;i<9;i++)if(board[y][i]=='.')return 0;
//   return 1;
// }
// int fill_test(vector<string>&board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board.size();j++){
//       if(board[i][j]=='.')return 0;
//     }
//   }
//   return 1;
// }
// void display(vector<string>&board){
//   for(int i=0;i<9;i++){
//     for(int j=0;j<9;j++){
//       cout<<board[i][j]<<" |";
//     }
//     cout<<endl;
//   }
// }
// int verticle(vector<string>&board,int x,int y,char ch){
//   for(int i=0;i<9;i++){
//     if(board[i][x]==ch)return 0;
//   }
//   return 1;
// }
// int horizontal(vector<string>&board,int x,int y,char ch){
//   for(int i=0;i<9;i++){
//     if(board[y][i]==ch)return 0;
//   }
//   return 1;
// }
// int box(vector<string>&board,int x,int y,char ch){
//   int sx=x-(x%3),sy=y-(y%3);
//   for(int i=sy;i<sy+3;i++){
//     for(int j=sx;j<sx+3;j++){
//       if(board[i][j]==ch)return 0;
//     }
//   }
//   return 1;
// }
// int test(vector<string>&board,int x,int y,char ch){
//   int test1=verticle(board,x,y,ch);
//   int test2=horizontal(board,x,y,ch);
//   int test3=box(board,x,y,ch);
//   int ans=test1&&test2&&test3;
//   return ans;
// }
// void solver (vector<string>&board,int x=0,int y=0){
//   if(x==board.size()){
//     if(fill_test_hori(board,y)){
//       solver(board,0,y+1);
//       return;
//     } else return;
//   }
//   if(y==board.size()){
//     while(1){      //because of not this adding infinite loop it was returing back ansd chekcing for other numbers as well and because of large screen output it was not easy to spot the answer found
//     cout<<"Answer found"<<endl;
//     display(board);
//     }
//     return;
//   }
//   if(board[y][x]=='.'){
//     for(int i=1;i<=9;i++){
//       char ch='0' + i;
//       cout<<"Checking for char = "<<ch<<endl;
//     if(test(board,x,y,ch)){
//       board[y][x]=ch;
//       solver(board,x+1,y);
//       board[y][x]='.';
//     } else if(i==9)return;
//     }
//   } else solver(board,x+1,y);
// }
// int main(){
//     vector<string>board={"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
//     display(board);
//     solver(board);

// }

//perplexity
// #include <iostream>
// #include <vector>

// using namespace std;

// const int N = 9;

// // Function to check if placing num in board[row][col] is valid
// bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
//     for (int x = 0; x < N; x++) {
//         if (board[row][x] == num || board[x][col] == num || board[3 * (row / 3) + x / 3][3 * (col / 3) + x % 3] == num) {
//             return false;
//         }
//     }
//     return true;
// }

// // Function to count solutions using backtracking
// int countSolutions(vector<vector<int>>& board) {
//     int row, col;
//     bool empty = true;

//     // Find an empty cell
//     for (row = 0; row < N; row++) {
//         for (col = 0; col < N; col++) {
//             if (board[row][col] == 0) { // 0 represents an empty cell
//                 empty = false;
//                 break;
//             }
//         }
//         if (!empty) break;
//     }

//     // If no empty cell is found, we found a solution
//     if (empty) return 1;

//     int count = 0;

//     // Try placing numbers 1 to 9
//     for (int num = 1; num <= 9; num++) {
//         if (isValid(board, row, col, num)) {
//             board[row][col] = num; // Place the number
//             count += countSolutions(board); // Recur
//             board[row][col] = 0; // Backtrack
//         }
//     }

//     return count;
// }

// int main() {
//   vector<vector<int>> board = {        //1 answer
//       {5, 3, 0, 0, 7, 0, 0, 0, 0},
//       {6, 0, 0, 1, 9, 5, 0, 0, 0},
//       {0, 9, 8, 0, 0, 0, 0, 6, 0},
//       {8, 0, 0, 0, 6, 0, 0, 0, 3},
//       {4, 0, 0, 8, 0, 3, 0, 0, 1},
//       {7, 0, 0, 0, 2, 0, 0, 0, 6},
//       {0, 6, 0, 0, 0, 0, 2, 8, 0},
//       {0, 0, 0, 4, 1, 9, 0, 0, 5},
//       {0, 0, 0, 0, 8, 0, 0, 7, 9}
//   };
//   // vector<vector<int>> board = {
//   //     {0, 0, 0, 2, 0, 0, 0, 0, 0},
//   //     {0, 0, 0, 0, 0, 3, 0, 0, 2},
//   //     {0, 0, 1, 0, 0, 0, 0, 0, 5},
//   //     {0, 0, 0, 0, 0, 0, 0, 0, 0},
//   //     {0, 0, 4, 0, 0, 0, 1, 0, 0},
//   //     {0, 9, 0, 0, 0, 0, 0, 0, 0},
//   //     {5, 0, 0, 0, 0, 0, 0, 7, 0},
//   //     {0, 0, 7, 0, 0, 0, 0, 0, 0},
//   //     {0, 0, 0, 0, 0, 0, 3, 0, 0}
//   // };
//   // vector<vector<int>> board = {
//   //     {0, 0, 0, 2, 0, 0, 0, 0, 0},
//   //     {0, 0, 0, 0, 0, 3, 0, 0, 2},
//   //     {0, 0, 1, 0, 0, 0, 0, 0, 5},
//   //     {0, 0, 0, 0, 0, 0, 0, 0, 0},
//   //     {0, 0, 4, 0, 0, 0, 1, 0, 0},
//   //     {0, 9, 0, 0, 0, 0, 0, 0, 0},
//   //     {5, 0, 0, 0, 0, 0, 0, 7, 0},
//   //     {0, 0, 7, 0, 0, 0, 0, 0, 0},
//   //     {0, 0, 0, 0, 0, 0, 3, 0, 0}
//   // };
//     int solutionCount = countSolutions(board);
//     cout << "Number of solutions: " << solutionCount << endl;

//     return 0;
// }


// #include<iostream>
// #include<vector>
// using namespace std;
// vector<vector<string>>final_ans;
// int fill_test_hori(vector<string>&board,int y){
//   for(int i=0;i<9;i++)if(board[y][i]=='.')return 0;
//   return 1;
// }
// int fill_test(vector<string>&board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board.size();j++){
//       if(board[i][j]=='.')return 0;
//     }
//   }
//   return 1;
// }
// void display_final_ans(vector<string>&board){
//   for(int k=0;k<final_ans.size();k++){
//     cout<<"Answer no : "<<k+1<<endl;
//   for(int i=0;i<9;i++){
//     for(int j=0;j<9;j++){
//       cout<<final_ans[k][i][j]<<" |";
//     }
//     cout<<endl;
//   }
//   }
//   cout<<"Total number of ways we can solve this sudoku is : "<<final_ans.size()<<endl;
// }
// void display(vector<string>&board){
//   for(int i=0;i<9;i++){
//     for(int j=0;j<9;j++){
//       cout<<board[i][j]<<" |";
//     }
//     cout<<endl;
//   }
// }
// int verticle(vector<string>&board,int x,int y,char ch){
//   for(int i=0;i<9;i++){
//     if(board[i][x]==ch)return 0;
//   }
//   return 1;
// }
// int horizontal(vector<string>&board,int x,int y,char ch){
//   for(int i=0;i<9;i++){
//     if(board[y][i]==ch)return 0;
//   }
//   return 1;
// }
// int box(vector<string>&board,int x,int y,char ch){
//   int sx=x-(x%3),sy=y-(y%3);
//   for(int i=sy;i<sy+3;i++){
//     for(int j=sx;j<sx+3;j++){
//       if(board[i][j]==ch)return 0;
//     }
//   }
//   return 1;
// }
// int test(vector<string>&board,int x,int y,char ch){
//   int test1=verticle(board,x,y,ch);
//   int test2=horizontal(board,x,y,ch);
//   int test3=box(board,x,y,ch);
//   int ans=test1&&test2&&test3;
//   return ans;
// }
// void solver (vector<string>&board,int x=0,int y=0){
//   if(x==board.size()){
//     if(fill_test_hori(board,y)){
//       solver(board,0,y+1);
//       return;
//     } else return;
//   }
//   if(y==board.size()){
//     // while(1){
//     // cout<<"Answer found"<<endl;
//     // display(board);
//     final_ans.push_back(board);
//     // }
//     return;
//   }
//   if(board[y][x]=='.'){
//     for(int i=1;i<=9;i++){
//       char ch='0' + i;
//       // cout<<"Checking for char = "<<ch<<endl;
//     if(test(board,x,y,ch)){
//       board[y][x]=ch;
//       solver(board,x+1,y);
//       board[y][x]='.';
//     } else if(i==9)return;
//     }
//   } else solver(board,x+1,y);
// }
// int main(){
//     // vector<string>board={"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
//   // vector<string>board={"..9.7.8.1","...4.3..6","3.......9","1.9.....7","...7.4...","8.....5.3","6.......2","5..1.8...","4.3.6.7.."};
//   vector<string> board = {
//       "53..7....",
//       "6..195...",
//       ".98....6.",
//       "8...6...3",
//       "4..8.3..1",
//       "7...2...6",
//       ".6....28.",
//       "...419..5",
//       "....8..79"
//   };
//     display(board);
//     solver(board);
//     display_final_ans(board);
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// void display(vector<string>&board){
//   for(int i=0;i<9;i++){
//     for(int j=0;j<9;j++){
//       cout<<board[i][j]<<" |";
//     }
//     cout<<endl;
//   }
// }
// int verticle(vector<string>&board,int x,int y,char ch){
//   for(int i=0;i<9;i++){
//     if(board[i][x]==ch)return 0;
//   }
//   return 1;
// }
// int horizontal(vector<string>&board,int x,int y,char ch){
//   for(int i=0;i<9;i++){
//     if(board[y][i]==ch)return 0;
//   }
//   return 1;
// }
// int box(vector<string>&board,int x,int y,char ch){
//   int sx=x-(x%3),sy=y-(y%3);
//   for(int i=sy;i<sy+3;i++){
//     for(int j=sx;j<sx+3;j++){
//       if(board[i][j]==ch)return 0;
//     }
//   }
//   return 1;
// }
// int test(vector<string>&board,int x,int y,char ch){
//   int test1=verticle(board,x,y,ch);
//   int test2=horizontal(board,x,y,ch);
//   int test3=box(board,x,y,ch);
//   int ans=test1&&test2&&test3;
//   return ans;
// }
// int cnt=0;
// void solver(vector<string>&board,int x=0,int y=0){
//   // cout<<"Entered here"<<endl;
//   if(x==board.size()){cout<<"End of line reached x = "<<x<<" & y = "<<y<<endl;solver(board,0,y+1);return;}
//   else if(y==board.size()){
//     cout<<"End of the maze reached"<<endl;
//     display(board);
//     return;
//   }
//   for(int i=1;i<=9;i++){
//     if(board[y][x]<'0'||board[y][x]>'9'){
//       cout<<". exists at x = "<<x<<" & y = "<<y<<" going to check for i = "<<i<<endl;
//       char ch='0'+i;
//       if(test(board,x,y,ch)){
//         board[y][x]=ch;
//         cout<<ch<<" placed at x = "<<x<<" & y = "<<y<<endl;
//         display(board);
//         solver(board,x+1,y);
//         board[y][x]='.';
//       }
//     } else solver(board,x+1,y);

//   }
// }
// int main(){
//   vector<string>board={"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
//   display(board);
//   solver(board);

// }

// #include<iostream>
// #include<vector>
// using namespace std;
// int fill_test_hori(vector<string>&board,int y){
//   for(int i=0;i<9;i++)if(board[y][i]=='.')return 0;
//   return 1;
// }
// int fill_test(vector<string>&board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board.size();j++){
//       if(board[i][j]=='.')return 0;
//     }
//   }
//   return 1;
// }
// void display(vector<string>&board){
//   for(int i=0;i<9;i++){
//     for(int j=0;j<9;j++){
//       cout<<board[i][j]<<" |";
//     }
//     cout<<endl;
//   }
// }
// int verticle(vector<string>&board,int x,int y,char ch){
//   for(int i=0;i<9;i++){
//     if(board[i][x]==ch)return 0;
//   }
//   return 1;
// }
// int horizontal(vector<string>&board,int x,int y,char ch){
//   for(int i=0;i<9;i++){
//     if(board[y][i]==ch)return 0;
//   }
//   return 1;
// }
// int box(vector<string>&board,int x,int y,char ch){
//   int sx=x-(x%3),sy=y-(y%3);
//   for(int i=sy;i<sy+3;i++){
//     for(int j=sx;j<sx+3;j++){
//       if(board[i][j]==ch)return 0;
//     }
//   }
//   return 1;
// }
// int test(vector<string>&board,int x,int y,char ch){
//   int test1=verticle(board,x,y,ch);
//   int test2=horizontal(board,x,y,ch);
//   int test3=box(board,x,y,ch);
//   int ans=test1&&test2&&test3;
//   return ans;
// }
// int cnt=0;
// void solver(vector<string>&board,int x=0,int y=0){
//   if(y==5)cout<<"y = 5 & x= "<<x<<" was given"<<endl;
//   if(y==8)cout<<"y = 8 was given"<<endl;

//   // cout<<"Entered here"<<endl;
//    if(y==board.size()){
//     // if(fill_test(board)){
//     cout<<"End of the maze reached"<<endl;
//     display(board);
//     // }
//     return;
//   }
//   else if(x==board.size()){
//     if(fill_test(board)){
//       cout<<"Board filled completely"<<endl;
//       display(board);
//       return;
//     }
//     else if(fill_test_hori(board,y)){
//       cout<<"Board is filled horizontally at x = "<<x<<" & y = "<<y<<endl;
//       display(board);
//       solver(board,0,y+1);
//       return;
//     }
//     // else return;
//   }//cout<<"End of line reached x = "<<x<<" & y = "<<y<<endl;

//   if(board[y][x]=='.'){
//   if(y==5)cout<<". is present here"<<endl;
//     int testing=0;
//   for(int i=1;i<=9;i++){
//       // cout<<". exists at x = "<<x<<" & y = "<<y<<" going to check for i = "<<i<<endl;
//       char ch='0'+i;
//       if(test(board,x,y,ch)){
//         testing=1;
//         if(y==5)cout<<"Test is passed for x = "<<x<<" & y = "<<y<<endl;
//         board[y][x]=ch;
//         if(y==5)cout<<ch<<" placed"<<endl;
//         if(y==5)display(board);
//         // cout<<ch<<" placed at x = "<<x<<" & y = "<<y<<endl;
//         // display(board);
//         solver(board,x+1,y);
//         board[y][x]='.';
//       } 
//     if(i==9&&testing==0){
//         return;
//       }
//     //if(!test(board,x,y,ch)&&i==9)return;
//     } 
//   }else solver(board,x+1,y);
// }
// int main(){
//   vector<string>board={"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
//   display(board);
//   solver(board);

// }