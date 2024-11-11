// #include<iostream>
// #include<vector>
// #include<unistd.h>
// using namespace std;
// int n,ans=0;


// void show_maze(vector<vector<int>>&board);
// void backward(vector<vector<int>>&board,int x, int y);
// void forward(vector<vector<int>>&board,int x, int y);
// void diagonal_mark(vector<vector<int>>&board,int x,int y);
// void verticle_mark(vector<vector<int>>&board,int x, int y);
// void horizontal_mark(vector<vector<int>>&board,int x,int y);
// void mark(vector<vector<int>>&board,int x,int y);
// void check(vector<vector<int>>board,int x,int y,int p);
// void backtracking(vector<vector<int>>board,int x,int y,int p=1);
// void clear();


// void clear() {
//     // This will print the ANSI escape code for clearing the screen
//     std::cout << "\033[2J\033[1;1H";
// }
// void show_maze(vector<vector<int>>&board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board[i].size();j++){
//       cout<<board[i][j]<<" | ";
//     }
//     cout<<endl;
//   }
//   cout<<"Waiting for 5 seconds"<<endl;
//   // sleep(5);
//   // clear();
// }
// void backward(vector<vector<int>>&board,int x, int y){
// while(x>-1&&y<n){
//   if(board[y][x]==-1)board[y][x]=0;
//   x--;
//   y++;
// }
// cout<<"Backward Diagonal mark done for x = "<<x<<" & y = "<<y<<endl;
// }
// void forward(vector<vector<int>>&board,int x, int y){
//   while(x<n&&y<n){
//     if(board[y][x]==-1)board[y][x]=0;
//     x++;
//     y++;
//   }
//   cout<<"Forward Diagonal mark done for x = "<<x<<" & y = "<<y<<endl;
// }
// void diagonal_mark(vector<vector<int>>&board,int x,int y){
//   forward(board,x+1,y+1);
//   backward(board,x-1,y+1);
// }
// void verticle_mark(vector<vector<int>>&board,int x, int y){
//   for(int i=0;i<4;i++){
//     if(board[i][x]==-1)board[i][x]=0;
//   }
// }
// void horizontal_mark(vector<vector<int>>&board,int x,int y){
//   for(int i=0;i<4;i++){
//     if(board[y][i]==-1)board[y][i]=0;
//   }
// }
// void mark(vector<vector<int>>&board,int x,int y){
//   horizontal_mark(board,x,y);
//   cout<<"Horizontal mark done for x = "<<x<<" & y = "<<y<<endl;
//   verticle_mark(board,x,y);
//   cout<<"Verticle mark done for x = "<<x<<" & y = "<<y<<endl;
//   diagonal_mark(board,x,y);
//   // show_maze(board);
//   // sleep(100);
//   // return;
// }
// void check(vector<vector<int>>board,int x,int y,int p){
//   if(x>n-1){
//     // cout<<"Not possible to fit "<<n<<" queens like this"<<endl;
//     // show_maze(board);
//     return;
//   }
//   else if(board[y][x]==-1){
//     board[y][x]=p;
//     mark(board,x,y);
//     if(y>n-2&&board[y][x]==p){
//       cout<<"All "<<n<<" queens set"<<endl;
//       if(p==n)ans++;
//       show_maze(board);
//       return;
//     }
//     backtracking(board, 0, y+1,p+1);
//   } else if(board[y][x]!=-1){
//       check(board,x+1,y,p);
//   }
// }
// void backtracking(vector<vector<int>>board,int x,int y,int p){
//    for(int i=0;i<n;i++){
//      check(board,i,y,p);
//    }
// }

// //-1 not visited
// //>0 nth queen placed there
// //0 place covered by queen
// int main(){
//   cout<<"Enter number of queens : ";
//   cin>>n;
//   vector<vector<int>>board(n,vector<int>(n,-1));
//   show_maze(board);
//   backtracking(board,0,0);
//   cout<<"Total answers possible are : "<<ans<<endl;
// }



// #include<iostream>
// #include<vector>
// #include<unistd.h>
// using namespace std;
// int n,ans=0;


// void show_maze(vector<vector<int>>&board);
// void backward(vector<vector<int>>&board,int x, int y);
// void forward(vector<vector<int>>&board,int x, int y);
// void diagonal_mark(vector<vector<int>>&board,int x,int y);
// void verticle_mark(vector<vector<int>>&board,int x, int y);
// void horizontal_mark(vector<vector<int>>&board,int x,int y);
// void mark(vector<vector<int>>&board,int x,int y);
// void check(vector<vector<int>>board,int x,int y,int p);
// void backtracking(vector<vector<int>>board,int x,int y,int p=1);
// void backtrack_1(vector<vector<int>>board,int x,int y,int p);
// void clear();

// vector<int>bt1;
// void clear() {
//     // This will print the ANSI escape code for clearing the screen
//     std::cout << "\033[2J\033[1;1H";
// }
// void show_maze(vector<vector<int>>&board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board[i].size();j++){
//       cout<<board[i][j]<<" | ";
//     }
//     cout<<endl;
//   }
//   cout<<"Waiting for 5 seconds"<<endl;
//   // sleep(5);
//   // clear();
// }
// void backward(vector<vector<int>>&board,int x, int y){
// while(x>-1&&y<n){
//   if(board[y][x]==-1)board[y][x]=0;
//   x--;
//   y++;
// }
// // cout<<"Backward Diagonal mark done for x = "<<x<<" & y = "<<y<<endl;
// }
// void forward(vector<vector<int>>&board,int x, int y){
//   while(x<n&&y<n){
//     if(board[y][x]==-1)board[y][x]=0;
//     x++;
//     y++;
//   }
//   // cout<<"Forward Diagonal mark done for x = "<<x<<" & y = "<<y<<endl;
// }
// void diagonal_mark(vector<vector<int>>&board,int x,int y){
//   forward(board,x+1,y+1);
//   backward(board,x-1,y+1);
// }
// void verticle_mark(vector<vector<int>>&board,int x, int y){
//   for(int i=0;i<n;i++){
//     if(board[i][x]==-1)board[i][x]=0;
//   }
// }
// void horizontal_mark(vector<vector<int>>&board,int x,int y){
//   for(int i=0;i<n;i++){
//     if(board[y][i]==-1)board[y][i]=0;
//   }
// }
// void mark(vector<vector<int>>&board,int x,int y){
//   horizontal_mark(board,x,y);
//   // cout<<"Horizontal mark done for x = "<<x<<" & y = "<<y<<endl;
//   verticle_mark(board,x,y);
//   // cout<<"Verticle mark done for x = "<<x<<" & y = "<<y<<endl;
//   diagonal_mark(board,x,y);
//   // show_maze(board);
//   // sleep(100);
//   // return;
// }
// void check(vector<vector<int>>board,int x,int y,int p){
//   if(y>n-1){
//     cout<<"y went outside of the maze"<<endl;
//     return;
//   }
//   else if(x>n-1){
//     // cout<<"Not possible to fit "<<n<<" queens like this"<<endl;
//     // show_maze(board);
//     return;
//   } 
//     // check(board,x+1,y,p);  //  randomly added 

//   else if(board[y][x]==-1){
//     backtrack_1(board, x+1, y,p);
//     board[y][x]=p;
//     mark(board,x,y);
    
//     if(y>n-2){
//       cout<<"All "<<n<<" queens set"<<endl;
//       ans++;
//       show_maze(board);
//       cout<<"Returning now when x= "<<x<<" & y = "<<y<<endl;
//       return;
//     }
//     // backtracking(board, 0, y+1,p+1);//this might be the cause of repeated answers
//     check(board,0,y+1,p+1);
//     // backtracking(board, 0, y+1,p+1);
//   } 
//   else if(board[y][x]!=-1){
//     check(board,x+1,y,p);
//   }
// }
// void backtrack_1(vector<vector<int>>board,int x,int y,int p){
//   check(board,x,y,p);
// }
// void backtracking(vector<vector<int>>board,int x,int y,int p){
//    for(int i=0;i<n;i++){
//      check(board,i,y,p);
//    }
// }

// //-1 not visited
// //>0 nth queen placed there
// //0 place covered by queen
// int main(){
//   cout<<"Enter number of queens : ";
//   cin>>n;
//   vector<vector<int>>board(n,vector<int>(n,-1));
//   show_maze(board);
//   backtracking(board,0,0);
//   cout<<"Total answers possible are : "<<ans<<endl;
// }

// #include<iostream>
// #include<vector>
// #include<unistd.h>
// using namespace std;
// int n,ans=0;


// void show_maze(vector<vector<int>>board);
// void backward(vector<vector<int>>board,int x, int y);
// void forward(vector<vector<int>>board,int x, int y);
// void diagonal_mark(vector<vector<int>>board,int x,int y);
// void verticle_mark(vector<vector<int>>board,int x, int y);
// void horizontal_mark(vector<vector<int>>board,int x,int y);
// void mark(vector<vector<int>>board,int x,int y);
// void check(vector<vector<int>>board,int x,int y,int p);
// void backtracking(vector<vector<int>>board,int x,int y,int p=1);
// void clear();


// void clear() {
//     // This will print the ANSI escape code for clearing the screen
//     std::cout << "\033[2J\033[1;1H";
// }
// void show_maze(vector<vector<int>>board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board[i].size();j++){
//       cout<<board[i][j]<<" | ";
//     }
//     cout<<endl;
//   }
//   cout<<"Waiting for 2 seconds"<<endl;
//   sleep(2);
//   // clear();
// }
// void backward(vector<vector<int>>board,int x, int y){
// while(x>0&&y>0){
//   if(board[y][x]==-1)board[y][x]=0;
// }
// }
// void forward(vector<vector<int>>board,int x, int y){
//   while(x<n&&y<n){
//     if(board[y][x]==-1)board[y][x]=0;
//     x++;
//     y++;
//   }
// }
// void diagonal_mark(vector<vector<int>>board,int x,int y){
//   forward(board,x-1,y-1);
//   backward(board,x,y);
// }
// void verticle_mark(vector<vector<int>>board,int x, int y){
//   for(int i=0;i<board.size();i++){
//     if(board[i][x]==-1)board[i][x]=0;
//   }
// }
// void horizontal_mark(vector<vector<int>>board,int x,int y){
//   for(int i=0;i<board[y].size();i++){
//     if(board[y][i]==-1)board[y][i]=0;
//   }
// }
// void mark(vector<vector<int>>board,int x,int y){
//   horizontal_mark(board,x,y);
//   verticle_mark(board,x,y);
//   diagonal_mark(board,x,y);
//   show_maze(board);
//   // sleep(100);
//   // return;
// }
// void check(vector<vector<int>>board,int x,int y,int p){
//   if(x>n-1){
//     return;
//   }
//   else if(board[y][x]==-1){
//     board[y][x]=p;
//     mark(board,x,y);
//     if(y>n-1){
//       cout<<"All "<<n<<" queens set"<<endl;
//       ans++;
//       show_maze(board);
//       return;
//     }
//     backtracking(board, 0, y+1,p+1);
//   } else if(board[y][x]!=-1){
//       check(board,x+1,y,p);
//   }
// }
// void backtracking(vector<vector<int>>board,int x,int y,int p){
//    for(int i=0;i<n;i++){
//      check(board,i,y,p);
//    }
// }

// //-1 not visited
// //>0 nth queen placed there
// //0 place covered by queen
// int main(){
//   cout<<"Enter number of queens : ";
//   cin>>n;
//   vector<vector<int>>board(n,vector<int>(n,-1));
//   show_maze(board);
//   backtracking(board,0,0);
// }