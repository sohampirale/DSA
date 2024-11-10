// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<unistd.h>
//  using namespace std;
// int sx,sy,ex,ey; 
// vector<int>x_path(1,0);
// vector<int>y_path(1,0);
// vector<int>seq(1,0);

// int height;
// int length;

// void clear() {
//     std::cout << "\033[2J\033[1;1H";
// }

//  void print_maze(vector<vector<int>>&obs,int sx,int sy){
//   int test=0;
//   if(sx==ex&&sy==ey)test=1;
//   for(int i=0;i<obs.size();i++){
//     for(int j=0;j<obs[i].size();j++){
//       if(j==ex&&i==ey&&j==sx&&i==sy){
//         cout<<"["<<obs[i][j]<<"] ";
//       }
//       else if(j==ex&&i==ey){
//         cout<<" [] ";
//       }
//       else if(obs[i][j]!=-1){
//         cout<<"  "<<obs[i][j]<<" ";
//       } else cout<<"    ";
//       cout<<'|';
//     }
//     cout<<endl;
//   }
//   if(test==1)cout<<"Destination Reached :)"<<endl;
//   sleep(1);
//    clear();
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

// int backtracking(int sx,int sy,int ex,int ey,vector<vector<int>>&obs,int k=0){
//    if(sx>ex||sy>ey||sx<0||sy<0){return 0;}    //cout<<"Went outside the maze"<<endl;
//    if(obs[sy][sx]!=-1)return 0;     //hit obstcale or revisit same tile
//    obs[sy][sx]=k;
//    print_maze(obs, sx, sy);
//    if(sx==ex&&sy==ey){obs[sy][sx]=-1;return 1;}    //cout<<"Destination reached"<<endl;

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
//    vector<vector<int>> obs(height+1,vector<int>(length+1,-1));
//    cout<<"Bool matrix before intilizing obstacles is : "<<endl;
//    show_bool(length,height,obs,-1,-1);
//    // // cout<<"Enter number of obstacles you have : ";
//    // // cin>>nobs;
//    // // for(int i=0;i<nobs;i++){
//    // //   cin>>ox>>oy;
//    // //   obs[oy][ox]=0;         //must maybe
//    // // }
//    // // show_bool(length,height,obs,-1,-1);
//    int ans=backtracking(sx,sy,ex,ey,obs);
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }