// //practice
// #include<iostream>
// #include<vector>
// using namespace std;
// int sx,sy,ex,ey;
// void display(vector<vector<int>>&board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board[i].size();j++){
//       // if(board[i][j]!=0)cout<<board[i][j]<<" |";
//       // else cout<<"  |";
//       cout<<board[i][j]<<" |";
//     }
//     cout<<endl;
//   }
// }
// int cnt=0;
// void backtracking(vector<vector<int>>&board,int sx,int sy,int p=1){
//   // int cnt=0;
//   if(sx>ex+1||sy>ey+1||sx<0||sy<0)return ;
//   else if(board[sy][sx]!=0)return ;
//   else if(sx==ex&&sy==ey){
//     cnt++;
//     board[sy][sx]=p;
//     cout<<"Destination found"<<endl;
//     display(board);
//     board[sy][sx]=0;
//     return ;
//   }
//   board[sy][sx]=p;
//   backtracking(board,sx+1,sy,p+1);
//   backtracking(board,sx-1,sy,p+1);
//   backtracking(board,sx,sy+1,p+1);
//   backtracking(board,sx,sy-1,p+1);
//   board[sy][sx]=0;

// }
// int main(){
//   cout<<"Enter starting point : ";
//   cin>>sx>>sy;
//   cout<<"Enter Destination point : ";
//   cin>>ex>>ey;
//   vector<vector<int>>board(ey+1+1,vector<int>(ex+1+1,0));
//   cout<<"Board made"<<endl;
//   display(board);
//   backtracking(board,sx,sy);
//   cout<<"Possible ways are : "<<cnt<<endl;
// }


//in this example the matrix is exactly upside down
//  0 1 2 3 4 5
// 0
// 1
// 2
// 3
//in this program th eplayer can go one row below & one colomn behind  and come up or come back to the destination 
// (added +1 again in the intiolilzation of bool matrix in height and length and updated the condition to sy>ey+1 // & sx>ex+1 for going outside the maze)

// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<unistd.h>
//  using namespace std;
// int height;
//  int length;
// int ex,ey;
// void print_maze(vector<vector<bool>>&obs){
//   for(int i=0;i<obs.size();i++){
//     for(int j=0;j<obs[i].size();j++){
//       if(obs[i][j]==false)cout<<'o';
//       else if(i==ey&&j==ex)cout<<"[]";
//       else cout<<" ";
//       cout<<'|';
//   }
//     cout<<endl;
//   }
//   usleep(500);
// }
// void show_bool(int length,int height,vector<vector<bool>>&obs,int sx,int sy){
//   for(int i=0;i<=height;i++){
//     cout<<"row no-"<<i<<" : ";
//     for(int j=0;j<=length;j++){
//       if(j==sx&&i==sy)cout<<"o";
//       cout<<obs[i][j]<<" ";
//     }
//     cout<<endl;
//   }
//   cout<<"Bool finished"<<endl;
// }
// int backtracking(int sx,int sy,int ex,int ey,vector<vector<bool>>&obs){
//    cout<<"sx = "<<sx<<" & sy = "<<sy<<endl;
//    if(sx>ex+1||sy>ey+1||sx<0||sy<0){cout<<"Went outside the maze"<<endl;return 0;}
//    if(obs[sy][sx]==false)return 0;
//    if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}

//    obs[sy][sx]=false;
//    int up= backtracking(sx,sy-1,ex,ey,obs);
//    int right= backtracking(sx+1,sy,ex,ey,obs);
//    int down= backtracking(sx,sy+1,ex,ey,obs);
//    int left= backtracking(sx-1,sy,ex,ey,obs);
//    if(obs[0][0]==true)cout<<"I guess this is will ne true until it is about to be returned to main"<<endl;
//    obs[sy][sx]=true;
//    if(obs[0][0]==true)cout<<"Was I right"<<endl;


//    return up+right+down+left;
//  }

//  int main(){
//   int sx,sy; //,nobs,ox,oy
//    cout<<"Enter Starting point : ";
//    cin>>sx>>sy;
//    cout<<"Enter Ending point : ";
//    cin>>ex>>ey;
//    height=max(ey,sy);
//    length=max(ex,sx);
//    cout<<"Height = "<<height<<" length = "<<length<<endl;
//    vector<vector<bool>> obs(height+1+1,vector<bool>(length+1+1,1));
//    cout<<"Bool matrix before intilizing obstacles is : "<<endl;
//    show_bool(length,height,obs,-1,-1);
//    // cout<<"Enter number of obstacles you have : ";
//    // cin>>nobs;
//    // for(int i=0;i<nobs;i++){
//    //   cin>>ox>>oy;
//    //   obs[oy][ox]=0;         //must maybe
//    // }
//    // show_bool(length,height,obs,-1,-1);
//    int ans=backtracking(sx,sy,ex,ey,obs);
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }


//printing maze as well

// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<unistd.h>
//  using namespace std;
// int height;
//  int length;
// int sx,sy,ex,ey;
// void clear() {
//   cout << "\033[2J\033[1;1H";
// }

// void print_maze(vector<vector<int>>&obs,int sx,int sy){
//   int test=0;
//   if(sx==ex&&sy==ey)test=1;
//   for(int i=0;i<obs.size();i++){
//     for(int j=0;j<obs[i].size();j++){
//       if(j==ex&&i==ey&&j==sx&&i==sy){
//         cout<<" ["<<obs[i][j]<<"]";
//         if(obs[i][j]<10)cout<<"  ";
//         // else cout<<"  ";
//       }
//       else if(j==ex&&i==ey){
//         cout<<" [ ] ";
//       }
//       else if(obs[i][j]!=-1){
//         cout<<"  "<<obs[i][j];
//         if(obs[i][j]>10)cout<<" ";
//         else cout<<"  ";
//       } else cout<<"     ";
//       cout<<'|';
//     }
//     cout<<endl;
//   }
//   if(test==1)cout<<"Destination Reached :)"<<endl;
//   if(obs[sy][sx]>9)sleep(1);
//   else usleep(500000);
//   clear();
//  }

// void show_bool(int length,int height,vector<vector<int>>&obs,int sx,int sy){
//   for(int i=0;i<=height;i++){
//     // cout<<"row no-"<<i<<" : ";
//     for(int j=0;j<=length;j++){
//       if(j==sx&&i==sy)cout<<"o";
//       cout<<obs[i][j]<<" ";
//     }
//     cout<<endl;
//   }
//   // cout<<"Bool finished"<<endl;
// }

// int backtracking(int sx,int sy,int ex,int ey,vector<vector<int>>&obs,int k){
//   // cout<<"hello"<<endl;
//    if(sx>ex+1||sy>ey+1||sx<0||sy<0){return 0;}  //cout<<"Went outside the maze"<<endl;
//    if(obs[sy][sx]!=-1)return 0;
//    obs[sy][sx]=k;

//     print_maze(obs,sx,sy);
//     if(sx==ex&&sy==ey){
//       obs[sy][sx]=-1;
//       return 1;
//     }                //cout<<"Destination reached"<<endl;

//    // print_maze(obs,sx,sy);
//    int up= backtracking(sx,sy-1,ex,ey,obs,k+1);
//    int right= backtracking(sx+1,sy,ex,ey,obs,k+1);
//    int down= backtracking(sx,sy+1,ex,ey,obs,k+1);
//    int left= backtracking(sx-1,sy,ex,ey,obs,k+1);
//    obs[sy][sx]=-1;


//    return up+right+down+left;
//  }

//  int main(){
//    //,nobs,ox,oy
//    cout<<"Enter Starting point : ";
//    cin>>sx>>sy;
//    cout<<"Enter Ending point : ";
//    cin>>ex>>ey;
//    height=max(ey,sy);
//    length=max(ex,sx);
//    cout<<"Height = "<<height<<" length = "<<length<<endl;
//    vector<vector<int>> obs(height+1+1,vector<int>(length+1+1,-1));
//    cout<<"Bool matrix before intilizing obstacles is : "<<endl;
//    show_bool(length+1,height+1,obs,-1,-1);
//    // cout<<"Enter number of obstacles you have : ";
//    // cin>>nobs;
//    // for(int i=0;i<nobs;i++){
//    //   cin>>ox>>oy;
//    //   obs[oy][ox]=0;         //must maybe
//    // }
//    // show_bool(length,height,obs,-1,-1);
//    int ans=backtracking(sx,sy,ex,ey,obs,1);
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }


//        multi obstacles

// #include<iostream>
// #include<algorithm>
// #include<vector>
//  using namespace std;
// int height;
//  int length;

// void show_bool(int length,int height,vector<vector<bool>>&obs,int sx,int sy){
//   for(int i=0;i<=height;i++){
//     cout<<"row no-"<<i<<" : ";
//     for(int j=0;j<=length;j++){
//       if(j==sx&&i==sy)cout<<"o";
//       cout<<obs[i][j]<<" ";
//     }
//     cout<<endl;
//   }
//   cout<<"Bool finished"<<endl;
// }
// int backtracking(int sx,int sy,int ex,int ey,vector<vector<bool>>&obs){
//    cout<<"sx = "<<sx<<" & sy = "<<sy<<endl;
//    if(sx>ex+1||sy>ey+1||sx<0||sy<0){cout<<"Went outside the maze"<<endl;return 0;}
//    if(obs[sy][sx]==false)return 0;
//    if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}
//    // else if(obs[sy][sx]==false){
//    //   cout<<"Obstacle hit"<<endl;
//    //   cout<<"sx = "<<sx<<" sy = "<<sy<<endl;
//    //   show_bool(length,height,obs,sx,sy);
//    //   return 0;
//    // }
//    // int cnt=0;
//    obs[sy][sx]=false;
//    int up= backtracking(sx,sy-1,ex,ey,obs);
//    int right= backtracking(sx+1,sy,ex,ey,obs);
//    int down= backtracking(sx,sy+1,ex,ey,obs);
//    int left= backtracking(sx-1,sy,ex,ey,obs);
//    if(obs[0][0]==true)cout<<"I guess this is will ne true until it is about to be returned to main"<<endl;
//    obs[sy][sx]=true;
//    if(obs[0][0]==true)cout<<"Was I right"<<endl;


//    return up+right+down+left;
//  }

//  int main(){
//   int sx,sy,ex,ey,nobs,ox,oy; //
//    cout<<"Enter Starting point : ";
//    cin>>sx>>sy;
//    cout<<"Enter Ending point : ";
//    cin>>ex>>ey;
//    height=max(ey,sy);
//    length=max(ex,sx);
//    cout<<"Height = "<<height<<" length = "<<length<<endl;
//    vector<vector<bool>> obs(height+1+1,vector<bool>(length+1+1,1));
//    cout<<"Bool matrix before intilizing obstacles is : "<<endl;
//    show_bool(length,height,obs,-1,-1);
//    cout<<"Enter number of obstacles you have : ";
//    cin>>nobs;
//    for(int i=0;i<nobs;i++){
//      cin>>ox>>oy;
//      obs[oy][ox]=0;         //must maybe
//    }
//    show_bool(length,height,obs,-1,-1);
//    int ans=backtracking(sx,sy,ex,ey,obs);
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }



// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<unistd.h>
// using namespace std;
// int height;
// int length;
// int sx,sy,ex,ey,nobs,ox,oy; //

// void clear() {
//   cout << "\033[2J\033[1;1H";
// }

// void print_maze(vector<vector<int>>&obs,int sx,int sy){
//   int test=0;
//   if(sx==ex&&sy==ey)test=1;
//   for(int i=0;i<obs.size();i++){
//     for(int j=0;j<obs[i].size();j++){
//       if(j==ex&&i==ey&&j==sx&&i==sy){
//         cout<<" ["<<obs[i][j]<<"] ";
//       }
//       else if(j==ex&&i==ey){
//         cout<<" [ ] ";
//       }
//       else if(obs[i][j]==-2){
//         cout<<"  *  ";
//       }
//       else if(obs[i][j]!=-1){
//         cout<<"  "<<obs[i][j]<<"  ";
//       } else cout<<"     ";
//       cout<<'|';
//     }
//     cout<<endl;
//   }
//   if(test==1)cout<<"Destination Reached :)"<<endl;
//   if(obs[sy][sx]>9)sleep(1);
//   else usleep(500000);
//   clear();
//  }
// void show_bool(int length,int height,vector<vector<int>>&obs,int sx,int sy){
//   for(int i=0;i<=height;i++){
//     cout<<"row no-"<<i<<" : ";
//     for(int j=0;j<=length;j++){
//       if(j==sx&&i==sy)cout<<"o";
//       cout<<obs[i][j]<<" ";
//     }
//     cout<<endl;
//   }
//   cout<<"Bool finished"<<endl;
// }
// int backtracking(int sx,int sy,int ex,int ey,vector<vector<int>>&obs,int k){
//    // cout<<"sx = "<<sx<<" & sy = "<<sy<<endl;
//    if(sx>ex+1||sy>ey+1||sx<0||sy<0){return 0;}//cout<<"Went outside the maze"<<endl;
//    if(obs[sy][sx]!=-1||obs[sy][sx]==-2)return 0;
//    obs[sy][sx]=k;
//    print_maze(obs,sx,sy);
//    if(sx==ex&&sy==ey){obs[sy][sx]=-1;return 1;}//cout<<"Destination reached"<<endl;
//    // else if(obs[sy][sx]==false){
//    //   cout<<"Obstacle hit"<<endl;
//    //   cout<<"sx = "<<sx<<" sy = "<<sy<<endl;
//    //   show_bool(length,height,obs,sx,sy);
//    //   return 0;
//    // }
//    // int cnt=0;
//    int up= backtracking(sx,sy-1,ex,ey,obs,k+1);
//    int right= backtracking(sx+1,sy,ex,ey,obs,k+1);
//    int down= backtracking(sx,sy+1,ex,ey,obs,k+1);
//    int left= backtracking(sx-1,sy,ex,ey,obs,k+1);
//    obs[sy][sx]=-1;


//    return up+right+down+left;
//  }

//  int main(){
//    cout<<"Enter Starting point : ";
//    cin>>sx>>sy;
//    cout<<"Enter Ending point : ";
//    cin>>ex>>ey;
//    height=max(ey,sy);
//    length=max(ex,sx);
//    cout<<"Height = "<<height<<" length = "<<length<<endl;
//    vector<vector<int>> obs(height+1+1,vector<int>(length+1+1,-1));
//    cout<<"Bool matrix before intilizing obstacles is : "<<endl;
//    show_bool(length,height,obs,-1,-1);
//    cout<<"Enter number of obstacles you have : ";
//    cin>>nobs;
//    for(int i=0;i<nobs;i++){
//      cin>>ox>>oy;
//      obs[oy][ox]=-2;         //must maybe
//    }
//    show_bool(length,height,obs,-1,-1);
//    int ans=backtracking(sx,sy,ex,ey,obs,1);
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }



// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<unistd.h>
// using namespace std;
// int height;
// int length;
// int sx,sy,ex,ey,nobs,ox,oy; //

// void clear() {
//   cout << "\033[2J\033[1;1H";
// }

// void print_maze(vector<vector<int>>&obs,int sx,int sy){
//   int test=0;
//   if(sx==ex&&sy==ey)test=1;
//   for(int i=0;i<obs.size();i++){
//     for(int j=0;j<obs[i].size();j++){
//       if(j==ex&&i==ey&&j==sx&&i==sy){
//         cout<<" ["<<obs[i][j]<<"] ";
//       }
//       else if(j==ex&&i==ey){
//         cout<<" [ ] ";
//       }
//       else if(obs[i][j]==-2){
//         cout<<"  *  ";
//       }
//       else if(obs[i][j]!=-1){
//         cout<<"  "<<obs[i][j]<<"  ";
//       } else cout<<"     ";
//       cout<<'|';
//     }
//     cout<<endl;
//   }
//   if(test==1)cout<<"Destination Reached :)"<<endl;
//   if(obs[sy][sx]>9)sleep(1);
//   // else sleep(5);
//   cout<<"Moving to next path"<<endl;
//   // clear();
//  }
// void show_bool(int length,int height,vector<vector<int>>&obs,int sx,int sy){
//   for(int i=0;i<=height;i++){
//     cout<<"row no-"<<i<<" : ";
//     for(int j=0;j<=length;j++){
//       if(j==sx&&i==sy)cout<<"o";
//       cout<<obs[i][j]<<" ";
//     }
//     cout<<endl;
//   }
//   cout<<"Bool finished"<<endl;
// }
// int backtracking(int sx,int sy,int ex,int ey,vector<vector<int>>&obs,int k){
//    // cout<<"sx = "<<sx<<" & sy = "<<sy<<endl;
//    if(sx>ex+1||sy>ey+1||sx<0||sy<0){return 0;}//cout<<"Went outside the maze"<<endl;
//    if(obs[sy][sx]!=-1||obs[sy][sx]==-2)return 0;
//    obs[sy][sx]=k;
//    // print_maze(obs,sx,sy);
//    if(sx==ex&&sy==ey){print_maze(obs,sx,sy);
// obs[sy][sx]=-1;return 1;}//cout<<"Destination reached"<<endl;
//    // else if(obs[sy][sx]==false){
//    //   cout<<"Obstacle hit"<<endl;
//    //   cout<<"sx = "<<sx<<" sy = "<<sy<<endl;
//    //   show_bool(length,height,obs,sx,sy);
//    //   return 0;
//    // }
//    // int cnt=0;
//    int up= backtracking(sx,sy-1,ex,ey,obs,k+1);
//    int right= backtracking(sx+1,sy,ex,ey,obs,k+1);
//    int down= backtracking(sx,sy+1,ex,ey,obs,k+1);
//    int left= backtracking(sx-1,sy,ex,ey,obs,k+1);
//    obs[sy][sx]=-1;


//    return up+right+down+left;
//  }

//  int main(){
//    cout<<"Enter Starting point : ";
//    cin>>sx>>sy;
//    cout<<"Enter Ending point : ";
//    cin>>ex>>ey;
//    height=max(ey,sy);
//    length=max(ex,sx);
//    cout<<"Height = "<<height<<" length = "<<length<<endl;
//    vector<vector<int>> obs(height+1+1,vector<int>(length+1+1,-1));
//    cout<<"Bool matrix before intilizing obstacles is : "<<endl;
//    show_bool(length,height,obs,-1,-1);
//    cout<<"Enter number of obstacles you have : ";
//    cin>>nobs;
//    for(int i=0;i<nobs;i++){
//      cin>>ox>>oy;
//      obs[oy][ox]=-2;         //must maybe
//    }
//    show_bool(length,height,obs,-1,-1);
//    int ans=backtracking(sx,sy,ex,ey,obs,1);
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }
