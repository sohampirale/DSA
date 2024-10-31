// #include<iostream>
// #include<vector>
// using namespace std;
// void display(vector<vector<int>>&board,int x=0,int y=0){
//   if(y==board.size())return;
//   else if(x==board.size()){cout<<endl;display(board,0,y+1);}
//   else { 
//    cout<<board[y][x]<<" |";
//    display(board,x+1,y);
//   }
// }
// // int safe(int num,int x,int y,vector<vector<int>>&board){
// //   for(int i=0;i<=y;i++){
// //     if(board[y][i]!=0)return 0;
// //   }
// //   int maxL=min(x,y);
// //   int temp=board.size()-1-x;
// //   int maxR=min(y,temp);
// //   for(int i=1;i<=maxL;i++){
// //     if(board[y-i][x-i]!=0)return 0;
// //   }
// //   for(int i=1;i<=maxR;i++){
// //     if(board[y-i][x+i]!=0)return 0;
// //   }
// //   return 1;
// // }
// int safe(vector<vector<int>>&board,int x,int y){
//   for(int i=0;i<=y;i++){
//     if(board[i][x]!=0)return 0;
//   }
//   int maxL=min(x,y);
//   int temp=board.size()-1-x;
//   int maxR=min(y,temp);
//   for(int i=1;i<=maxL;i++){
//     if(board[y-i][x-i]!=0)return 0;
//   }
//   for(int i=1;i<=maxR;i++){
//     if(board[y-i][x+i]!=0)return 0;
//   }
//   return 1;
// }
// int ans=0;
// void NQueens(vector<vector<int>>&board,int y=0,int p=1){
//   if(y==board.size()){
//     ans++;
//     cout<<"Answer found"<<endl;
//     display(board);
//     return;
//   } 
//   for(int i=0;i<board.size();i++){
//     if(safe(board,i,y)){
//       board[y][i]=p;
//       NQueens(board,y+1,p+1);
//       board[y][i]=0;
//     }
//   }
  
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   vector<vector<int>>board(n,vector<int>(n,0));
//   display(board);
//   NQueens(board);
//   cout<<"Number of answers possible are : "<<ans<<endl;
// }

// //praactice
// // in the safe function instead of making extra variables xd & yd we can run loop for x=1 to <=maxL & maxR and check for board[y-i][x-i] for ex diagonal left

// #include<iostream>
// #include<vector>
// #include<math.h>
// using namespace std;
// void display(vector<vector<int>>&board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board[i].size();j++){
//       cout<<board[i][j]<<" |";
//     }
//     cout<<endl;
//   }
// }
// int safe(vector<vector<int>>&board,int x,int y){
//   for(int i=0;i<=y;i++){
//     if(board[i][x]!=0)return 0;
//   }
//   int maxL = min(x,y);
//   int maxR = min(y,static_cast<int>(board.size()-1-x));
//   int xd=x,yd=y;
//   for(int i=0;i<maxL;i++){
//     xd--;
//     yd--;
//     if(board[yd][xd]!=0){
//       return 0;
//     }
//   }
//   xd=x;
//   yd=y;
//   for(int i=0;i<maxR;i++){
//     xd++;
//     yd--;
//     if(board[yd][xd]!=0){
//       return 0;
//     }
//   }

//   return 1;
// }
// // int safe(vector<vector<int>>&board,int x,int y){
// //   // int test=1;
// //   for(int i=0;i<=y;i++){
// //     if(board[i][x]!=0)return 0;
// //   }
// //   cout<<"Verticle test passed"<<endl;
// //   int maxL = min(x,y);
// //   // int c=
// //   int maxR = min(y,static_cast<int>(board.size()-1-x));
// //   cout<<"maxL = "<<maxL<<" & maxR = "<<maxR<<endl;
// //   // int xd=x,yd=y;
// //   // cout<<"xd = "<<xd<<" & yd = "<<yd<<endl;
// //   for(int i=1;i<=maxL;i++){
// //     if(board[y-i][x-i]!=0){
// //       cout<<"Diagonal Left : Invalid position when x = "<<x<<" & y = "<<y<<endl;
// //       return 0;
// //     }
// //   }
// //   cout<<"Diagonal left test passed"<<endl;
// //   // xd=x;
// //   // yd=y;
// //   // cout<<"xd = "<<xd<<" & yd = "<<yd<<endl;
// //   for(int i=1;i<=maxR;i++){
// //     // xd++;
// //     // yd--;
// //     if(board[y-i][x+i]!=0){
// //       cout<<"Diagonal Right : Invalid position at x= "<<x<<" & y = "<<y<<endl;
// //       return 0;
// //     }
// //   }
// //   cout<<"DIagonal right test passed"<<endl;

// //   return 1;
// // }
// void Nqueens(vector<vector<int>>&board,int x=0,int y=0,int p=1){
//   if(y==board.size()){
//     // board[y][x]=p;//this was the reason code was not wokring
//     cout<<"Answer found"<<endl;    
//     display(board);
//     return;
//     // board[y][x]=0;
//   }
//   else if(x>board.size()-1)return;
  
//   if(safe(board,x,y)==1){
//     board[y][x]=p;
//     Nqueens(board,0,y+1,p+1);
//     board[y][x]=0;
//   }
//   Nqueens(board,x+1,y,p);
// }

// int main(){
//   int n;
//   cout<<"Enter a number : ";
//   cin>>n;
//   vector<vector<int>>board(n,vector<int>(n,0));
//   display(board);
//   Nqueens(board);
//   cout<<"Answer finished"<<endl;
// }

//Most efficient answer - (we only have to check verticle and diagonally up - 1.forward 2.backward)

//in this the diagonally forward and backward we can use a formula 

//Number of times we need to go diagonally up right = min(y,board.length()-1-x)
//number of times we need to go diagonally up left = min(y,x);

// #include<iostream>
// #include<vector>
// #include<unistd.h>
// using namespace std;
// int n,ans=0;

// void show_maze(vector<vector<int>>&board);
// void backtracking(vector<vector<int>>board,int x,int y,int p);
// void clear() ;
// int check_place(vector<vector<int>>&board,int x,int y);
// int check_verticle(vector<vector<int>>&board,int x,int y);
// // int check_horizontal(vector<vector<int>>&board,int x,int y);//un
// int check_diagonal(vector<vector<int>>&board,int x,int y);
// int forward(vector<vector<int>>&board,int x,int y);
// int backward(vector<vector<int>>&board,int x,int y);

// void clear() {
//   std::cout << "\033[2J\033[1;1H";
// }

// int backward(vector<vector<int>>&board,int x,int y){
//   // int test=0;
//   while(x>-1&&y>-1){
//     if(board[y][x]!=-1){
//       // test=1;break;
//       return 1;
//     }
//     x--;
//     y--;
//   }
//   // if(test==1)return 1;
//   // else return 0;
//   return 0;
// }

// int forward(vector<vector<int>>&board,int x,int y){
//   // int test=0;
//   while(x<n&&y>-1){
//     if(board[y][x]!=-1){return 1;}//test=1;break;
//     x++;
//     y--;
//   }
//   // if(test==1)return 1;
//   // else return 0;
//   return 0;
// }

// int check_diagonal(vector<vector<int>>&board,int x,int y){
//   int t1,t2;
//   t1=forward(board,x+1,y-1);

//   t2=backward(board,x-1,y-1);

//   return t1+t2;
// }

// int check_horizontal(vector<vector<int>>&board,int x,int y){
//   int test=0;
//   for(int i=0;i<n;i++){
//      if(board[y][i]!=-1){test=1;break;}
//   }
//   if(test==1)return 1;
//   else return 0;
// }
// int check_verticle(vector<vector<int>>&board,int x,int y){
//   // int test=0;
//   for(int i=0;i<n;i++){
//      if(board[i][x]!=-1){return 1;}      //test=1;break;
//   }
//   return 0;
//   // if(test==1)return 1;
//   // else return 0;
// }
// int check_place(vector<vector<int>>&board,int x,int y){
//   int test1,test2=0,test3;
//   test1=check_verticle(board,x,y);
//   // test2=check_horizontal(board,x,y);//un
//   test3=check_diagonal(board,x,y);
//   return test1+test2+test3;
// }
// void show_maze(vector<vector<int>>&board){
//   for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
//       if(board[i][j]>0)cout<<board[i][j]<<" | ";
//       else cout<<"x | ";
//     }
//     cout<<endl;
//   }
// }
// void backtracking(vector<vector<int>>board,int x,int y,int p){
//   if(x>n-1){return;}
//   else if(y>n-1){
//     if(p==n+1){
//       // cout<<"Answer found"<<endl;
//       ans++;
//       show_maze(board);
//       cout<<endl;
//     }        
//     return;
//   }

//   int te=check_place(board,x,y);
//   if(te==0){
//     board[y][x]=p;
//     backtracking(board,0,y+1,p+1);
//     board[y][x]=-1;
//   }
//   backtracking(board,x+1,y,p);
// }

// int main(){
//   cout<<"Enter number of queens : ";
//   cin>>n;
//   vector<vector<int>>board(n,vector<int>(n,-1));
//   //show_maze(board);    //maze before working on it
//   backtracking(board,0,0,1);
//   cout<<"Total answers possible are : "<<ans<<endl;
// }



//  Another Answer - (checked horizontally,and digonally down which is unncesary)

// #include<iostream>
// #include<vector>
// #include<unistd.h>
// using namespace std;
// int n,ans=0;

// void show_maze(vector<vector<int>>&board);
// void backtracking(vector<vector<int>>board,int x,int y,int p);
// int check_place(vector<vector<int>>&board,int x,int y);
// int check_verticle(vector<vector<int>>&board,int x,int y);
// int check_horizontal(vector<vector<int>>&board,int x,int y);
// int check_diagonal(vector<vector<int>>&board,int x,int y);
// int forward(vector<vector<int>>&board,int x,int y);
// int backward(vector<vector<int>>&board,int x,int y);
// void clear() ;

// void clear() {
//     std::cout << "\033[2J\033[1;1H";
// }

// int backward(vector<vector<int>>&board,int x,int y){
//   while(x<n&&y>0){
//     y--;
//     x++;
//   }
//   if(y<0||x==n){y++;x--;}
//   int test=0;
//   while(x>0&&y<n){
//     if(board[y][x]!=-1){
//       test=1;break;
//     }
//     x--;
//     y++;
//   }
//   if(test==1)return 1;
//   else return 0;
// }
// int forward(vector<vector<int>>&board,int x,int y){
//   while(x>0&&y>0){
//     x--;
//     y--;
//   }
//   if(x<0||y<0){x++;y++;}
//   int test=0;
//   while(x<n&&y<n){
//     if(board[y][x]!=-1){test=1;break;}
//     x++;
//     y++;
//   }
//   if(test==1)return 1;
//   else return 0;
// }

// int check_diagonal(vector<vector<int>>&board,int x,int y){
//   int t1,t2;
//   t1=forward(board,x,y);

//   t2=backward(board,x,y);

//   return t1+t2;
// }

// int check_horizontal(vector<vector<int>>&board,int x,int y){
//   int test=0;
//   for(int i=0;i<n;i++){
//      if(board[y][i]!=-1){test=1;break;}
//   }
//   if(test==1)return 1;
//   else return 0;
// }
// int check_verticle(vector<vector<int>>&board,int x,int y){
//   int test=0;
//   for(int i=0;i<n;i++){
//      if(board[i][x]!=-1){test=1;break;}
//   }
//   if(test==1)return 1;
//   else return 0;
// }
// int check_place(vector<vector<int>>&board,int x,int y){
//   int test1,test2,test3;
//   test1=check_verticle(board,x,y);
//   test2=check_horizontal(board,x,y);
//   test3=check_diagonal(board,x,y);
//   return test1+test2+test3;
// }
// void show_maze(vector<vector<int>>&board){
//   for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
//       if(board[i][j]>0)cout<<board[i][j]<<" | ";
//       else cout<<"* | ";
//     }
//     cout<<endl;
//   }
// }
// void backtracking(vector<vector<int>>board,int x,int y,int p){
//   if(x>n-1){return;}
//   else if(y>n-1){
//     if(p==n+1){
//       cout<<"Answer found"<<endl;
//       ans++;
//       show_maze(board);
//     }        
//     return;
//   }

//   int te=check_place(board,x,y);
//   if(te==0){
//     board[y][x]=p;
//     backtracking(board,0,y+1,p+1);
//     board[y][x]=-1;
//   }
//   backtracking(board,x+1,y,p);
// }

// int main(){
//   cout<<"Enter number of queens : ";
//   cin>>n;
//   vector<vector<int>>board(n,vector<int>(n,-1));
//   //show_maze(board);    //maze before working on it
//   backtracking(board,0,0,1);
//   cout<<"Total answers possible are : "<<ans<<endl;
// }

//  Answer ended


//lengthy method and now actual backtracking method is used

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
// void backtrack_n(vector<vector<int>>&board,int x,int y,int p);
// void check_n(vector<vector<int>>board,int x,int y,int p);
// void clear();

// vector<int>btn;
// void clear() {
//     std::cout << "\033[2J\033[1;1H";
// }
// //prints maze with queen no & zero
// // void show_maze(vector<vector<int>>&board){
// //   for(int i=0;i<board.size();i++){
// //     for(int j=0;j<board[i].size();j++){
// //       cout<<board[i][j]<<" | ";
// //     }
// //     cout<<endl;
// //   }
// //   // cout<<"waiting for 2 seconds"<<endl;
// //   // sleep(1);
// // }

// //prints maze with queen no & 0
// void show_maze(vector<vector<int>>&board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board[i].size();j++){
//       if(board[i][j]>0)cout<<board[i][j]<<" | ";
//       else cout<<"* | ";
//     }
//     cout<<endl;
//   }

// }
// void backward(vector<vector<int>>&board,int x, int y){
// while(x>-1&&y<n){
//   if(board[y][x]==-1)board[y][x]=0;
//   x--;
//   y++;
// }
// }
// void forward(vector<vector<int>>&board,int x, int y){
//   while(x<n&&y<n){
//     if(board[y][x]==-1)board[y][x]=0;
//     x++;
//     y++;
//   }
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
//   verticle_mark(board,x,y);
//   diagonal_mark(board,x,y);
// }
// void check(vector<vector<int>>board,int x,int y,int p){
//   if(y>n-1){
//     // cout<<"y went outside of the maze"<<endl;
//     return;
//   }
//   else if(x>n-1){
//     // cout<<"Line no "<<y<<" cheked "<<endl;
//     backtrack_n(board, x,  y, p);
//     return;
//   } 

//   else if(board[y][x]==-1){
//     btn.push_back(x);
//     check(board,x+1,y,p);
//   } 
//   else if(board[y][x]!=-1){
//     check(board,x+1,y,p);
//   }
// }

// void check_n(vector<vector<int>>board,int x,int y,int p){
//   board[y][x]=p;
//   mark(board,x,y);
//   // cout<<"Marking now"<<endl;
//   // show_maze(board);
//   // sleep(3);
//   if(y==n-1){
//     ans++;
//     cout<<"Answer found"<<endl;
//     show_maze(board);
//     return;
//   }
//   check(board, 0, y+1, p+1);
// }
// void backtrack_n(vector<vector<int>>&board,int x,int y,int p){
//   vector<int>temp=btn;          
//   btn.clear();
//   // cout<<endl;
//   // sleep(2);
//   for(int i=0;i<temp.size();i++){
//   check_n(board,temp[i],y,p);
//   }
//   // btn.clear();
// }
// void backtracking(vector<vector<int>>board,int x,int y,int p){
//    for(int i=0;i<n;i++){
//      check(board,i,y,p);
//    }
// }


// int main(){
//   cout<<"Enter number of queens : ";
//   cin>>n;
//   vector<vector<int>>board(n,vector<int>(n,-1));
//   check(board,0 ,0 ,1);
//   cout<<"Total answers possible are : "<<ans<<endl;
// }


// backtrack_1(board, x+1, y,p);
// board[y][x]=p;
// mark(board,x,y);

// if(y>n-2){
//   cout<<"All "<<n<<" queens set"<<endl;
//   ans++;
//   show_maze(board);
//   cout<<"Returning now when x= "<<x<<" & y = "<<y<<endl;
//   return;
// }
// // backtracking(board, 0, y+1,p+1);//this might be the cause of repeated answers
// check(board,0,y+1,p+1);
// // backtracking(board, 0, y+1,p+1);



//  Actual answer but has extra lines used for debugging

// #include<iostream>
// #include<vector>
// #include<unistd.h>
// using namespace std;
// int n,ans=0;

// void show_maze(vector<vector<int>>&board);

// vector<int>btn;
// void clear() {
//     std::cout << "\033[2J\033[1;1H";
// }
// //prints maze with queen no & zero
// // void show_maze(vector<vector<int>>&board){
// //   for(int i=0;i<board.size();i++){
// //     for(int j=0;j<board[i].size();j++){
// //       cout<<board[i][j]<<" | ";
// //     }
// //     cout<<endl;
// //   }
// //   // cout<<"waiting for 2 seconds"<<endl;
// //   // sleep(1);
// // }



// //prints maze with queen no & 0
// int backward(vector<vector<int>>&board,int x,int y){
//   while(x<n&&y>0){
//     y--;
//     x++;
//   }
//   if(y<0||x==n){y++;x--;}
//   cout<<"x & y modified to x = "<<x<<" & y = "<<y<<" in backward test before starting the test"<<endl;
//   int test=0;
//   while(x>0&&y<n){
//     if(board[y][x]!=-1){
//       cout<<"Queen present at x "<<x<<" & y = "<<y<<endl;
//       test=1;break;
//     }
//     x--;
//     y++;
//   }
//   if(test==1)return 1;
//   else return 0;
// }
// int forward(vector<vector<int>>&board,int x,int y){
//   while(x>0&&y>0){
//     x--;
//     y--;
//   }
//   if(x<0||y<0){x++;y++;}
//   cout<<"x & y modified to x = "<<x<<" & y = "<<y<<" in forward test before starting the test"<<endl;
//   int test=0;
//   while(x<n&&y<n){
//     if(board[y][x]!=-1){test=1;break;}
//     x++;
//     y++;
//   }
//   if(test==1)return 1;
//   else return 0;
// }

// int check_diagonal(vector<vector<int>>&board,int x,int y){
//   int t1,t2;
//   t1=forward(board,x,y);
//   cout<<"Forward Diagonal check = "<<t1<<endl;

//   t2=backward(board,x,y);
//   cout<<"Backward diagonal check = "<<t2<<endl;

//   return t1+t2;
// }

// int check_horizontal(vector<vector<int>>&board,int x,int y){
//   int test=0;
//   for(int i=0;i<n;i++){
//      if(board[y][i]!=-1){test=1;break;}
//   }
//   if(test==1)return 1;
//   else return 0;
// }
// int check_verticle(vector<vector<int>>&board,int x,int y){
//   int test=0;
//   for(int i=0;i<n;i++){
//      if(board[i][x]!=-1){test=1;break;}
//   }
//   if(test==1)return 1;
//   else return 0;
// }
// int check_place(vector<vector<int>>&board,int x,int y){
//   int test1,test2,test3;
//   test1=check_verticle(board,x,y);
//   cout<<"verticle check = "<<test1<<endl;
//   test2=check_horizontal(board,x,y);
//   cout<<"Horizontal check = "<<test2<<endl;
//   test3=check_diagonal(board,x,y);
//   cout<<"Diagonal check = "<<test3<<endl;
//   cout<<"x = "<<x<<" & y = "<<y<<endl;
//   // show_maze(board);
//   return test1+test2+test3;
// }
// void show_maze(vector<vector<int>>&board){
//   for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
//       if(board[i][j]>0)cout<<board[i][j]<<" | ";
//       else cout<<"* | ";
//     }
//     cout<<endl;
//   }
// }
// void backtracking(vector<vector<int>>board,int x,int y,int p){
//   if(x>n-1){return;}
//   else if(y>n-1){
//     if(p==n+1){
//       cout<<"Answer found"<<endl;
//       ans++;
//       show_maze(board);
//     } else {cout<<"Cannot fit "<<n<<" queens in it"<<endl;}  //show_maze(board);
//     return;
//   }
//   // if(board[y][x]==-1){
  
//   int te=check_place(board,x,y);
//   if(te==0){
//     board[y][x]=p;
//     cout<<"Queen placed"<<endl;
//     // show_maze(board);
//     backtracking(board,0,y+1,p+1);
//     board[y][x]=-1;
//     cout<<"Queen unmarked"<<endl;
//     // show_maze(board);
//   }
//   // }
//   backtracking(board,x+1,y,p);
// }

// int main(){
//   cout<<"Enter number of queens : ";
//   cin>>n;
//   vector<vector<int>>board(n,vector<int>(n,-1));
//   show_maze(board);
//   backtracking(board,0,0,1);
//   // check(board,0 ,0 ,1);
//   cout<<"Total answers possible are : "<<ans<<endl;
// }
//  answer comlete


// void backward(vector<vector<int>>&board,int x, int y){
// while(x>-1&&y<n){
//   if(board[y][x]==-1)board[y][x]=0;
//   x--;
//   y++;
// }
// }
// void forward(vector<vector<int>>&board,int x, int y){
//   while(x<n&&y<n){
//     if(board[y][x]==-1)board[y][x]=0;
//     x++;
//     y++;
//   }
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
//   verticle_mark(board,x,y);
//   diagonal_mark(board,x,y);
// }
// void check(vector<vector<int>>board,int x,int y,int p){
//   if(y>n-1){
//     // cout<<"y went outside of the maze"<<endl;
//     return;
//   }
//   else if(x>n-1){
//     // cout<<"Line no "<<y<<" cheked "<<endl;
//     backtrack_n(board, x,  y, p);
//     return;
//   } 

//   else if(board[y][x]==-1){
//     btn.push_back(x);
//     check(board,x+1,y,p);
//   } 
//   else if(board[y][x]!=-1){
//     check(board,x+1,y,p);
//   }
// }

// void check_n(vector<vector<int>>board,int x,int y,int p){
//   board[y][x]=p;
//   mark(board,x,y);
//   // cout<<"Marking now"<<endl;
//   // show_maze(board);
//   // sleep(3);
//   if(y==n-1){
//     ans++;
//     cout<<"Answer found"<<endl;
//     show_maze(board);
//     return;
//   }
//   check(board, 0, y+1, p+1);
// }
// void backtrack_n(vector<vector<int>>&board,int x,int y,int p){
//   vector<int>temp=btn;          
//   btn.clear();
//   // cout<<endl;
//   // sleep(2);
//   for(int i=0;i<temp.size();i++){
//   check_n(board,temp[i],y,p);
//   }
//   // btn.clear();
// }
// void backtracking(vector<vector<int>>board,int x,int y,int p){
//    for(int i=0;i<n;i++){
//      check(board,i,y,p);
//    }
// }
