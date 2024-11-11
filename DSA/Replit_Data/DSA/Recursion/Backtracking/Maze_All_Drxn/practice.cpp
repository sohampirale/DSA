// #include<iostream>
//  using namespace std;
// int ub=3;
//  int backtracking(int sx=0,int sy=3,int ex=2,int ey=1){
//    if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}
//    else if(sx>ex||sy<0||sx<0||sy>ub){cout<<"Went outside the maze"<<endl;return 0;}
//    // int cnt=0;
//    int down= backtracking(sx,sy-1,ex,ey);
//    int right= backtracking(sx+1,sy,ex,ey);
//    int up= backtracking(sx,sy+1,ex,ey);
//    int left= backtracking(sx-1,sy,ex,ey);

//    return up+down+right+left;
//  }
//  int main(){

//    int ans=backtracking();
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }


//in this example the matrix is exactly upside down
//  0 1 2 3 4 5
// 0
// 1
// 2
// 3

//in this program player cannot go row below the destination row (sy>ey not allowed)
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
//    if(sx>ex||sy>ey||sx<0||sy<0){cout<<"Went outside the maze"<<endl;return 0;}
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
//   int sx,sy,ex,ey; //,nobs,ox,oy
//    cout<<"Enter Starting point : ";
//    cin>>sx>>sy;
//    cout<<"Enter Ending point : ";
//    cin>>ex>>ey;
//    height=max(ey,sy);
//    length=max(ex,sx);
//    cout<<"Height = "<<height<<" length = "<<length<<endl;
//    vector<vector<bool>> obs(height+1,vector<bool>(length+1,1));
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


//in this program th eplayer can go one row below i and come up 
// (added +1 again in the intiolilzation of bool matrix in 'height' section and updated the condition to sy>ey+1 for going outside the maze)
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
//    if(sx>ex||sy>ey+1||sx<0||sy<0){cout<<"Went outside the maze"<<endl;return 0;}
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
//   int sx,sy,ex,ey; //,nobs,ox,oy
//    cout<<"Enter Starting point : ";
//    cin>>sx>>sy;
//    cout<<"Enter Ending point : ";
//    cin>>ex>>ey;
//    height=max(ey,sy);
//    length=max(ex,sx);
//    cout<<"Height = "<<height<<" length = "<<length<<endl;
//    vector<vector<bool>> obs(height+1+1,vector<bool>(length+1,1));
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

//in this program th eplayer can go one row below & one colomn behind  and come up or come back to the destination 
// (added +1 again in the intiolilzation of bool matrix in height and length and updated the condition to sy>ey+1 // & sx>ex+1 for going outside the maze)

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
//   int sx,sy,ex,ey; //,nobs,ox,oy
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
