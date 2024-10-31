// #include<iostream>
// #include<algorithm>
// #include<vector>
//  using namespace std;
// int height;
//  int length;
// void show_bool(int length,int height,vector<vector<bool>>&obs,int sx,int sy){
//   for(int i=height;i>=0;i--){
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
//    if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}
//    else if(sx>ex||sy<ey){cout<<"Went outside the maze"<<endl;return 0;}
//    else if(obs[sy][sx]==false){
//      cout<<"Obstacle hit"<<endl;
//      cout<<"sx = "<<sx<<" sy = "<<sy<<endl;
//      show_bool(length,height,obs,sx,sy);
//      return 0;
//    }

//    int cnt=0;
//    cnt+= backtracking(sx,sy-1,ex,ey,obs);
//    cnt+= backtracking(sx+1,sy,ex,ey,obs);
//    return cnt;
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
//    vector<vector<bool>> obs(height+1,vector<bool>(length+1,1));
//    cout<<"Bool matrix before intilizing obstacles is : "<<endl;
//    show_bool(length,height,obs,-1,-1);
//    cout<<"Enter number of obstacles you have : ";
//    cin>>nobs;
//    for(int i=0;i<nobs;i++){
//      cin>>ox>>oy;
//      obs[oy][ox]=0;
//    }
//    show_bool(length,height,obs,-1,-1);
//    int ans=backtracking(sx,sy,ex,ey,obs);
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }
