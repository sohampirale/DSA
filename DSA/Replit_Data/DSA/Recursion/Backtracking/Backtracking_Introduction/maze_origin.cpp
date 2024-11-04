// //  RIGHT AND DOWN
// #include<iostream>
//  using namespace std;

//  int backtracking(int sx=0,int sy=3,int ex=2,int ey=1){
//    if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}
//    else if(sx>ex||sy<ey){cout<<"Went outside the maze"<<endl;return 0;}
//    int cnt=0;
//    cnt+= backtracking(sx,sy-1,ex,ey);
//    cnt+= backtracking(sx+1,sy,ex,ey);
//    return cnt;
//  }
//  int main(){
   
//    int ans=backtracking();
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }


// #include<iostream>
// #include<algorithm>
// #include<vector>
//  using namespace std;

// int backtracking(int sx,int sy,int ex,int ey,vector<vector<bool>>&obs){
//    if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}
//    else if(obs[sy][sx]==0){
//      cout<<"Obstacle hit"<<endl;
//      cout<<"sx = "<<sx<<" sy = "<<sy<<endl;
//      return 0;
//    }
//    else if(sx>ex||sy<ey){cout<<"Went outside the maze"<<endl;return 0;}
//    int cnt=0;
//    cnt+= backtracking(sx,sy-1,ex,ey,obs);
//    cnt+= backtracking(sx+1,sy,ex,ey,obs);
//    return cnt;
//  }
// void show_bool(int length,int height,vector<vector<bool>>&obs){
//   for(int i=height;i>=0;i--){
//     for(int j=0;j<=length;j++){
//       cout<<obs[i][j]<<" ";
//     }
//     cout<<endl;
//   }
//   cout<<"Bool finished"<<endl;
// }
//  int main(){
//   int sx,sy,ex,ey,nobs,ox,oy; //
//    cout<<"Enter Starting point : ";
//    cin>>sx>>sy;
//    cout<<"Enter Ending point : ";
//    cin>>ex>>ey;
//    int height=max(ey,sy);
//    int length=max(ex,sx);
//     cout<<"Height = "<<height<<" length = "<<length<<endl;
//    vector<vector<bool>>obs((height+1),vector<bool>((length+1),true));
//    cout<<"Bool matrix before intialing obstacles is : "<<endl;
//     show_bool(length,height,obs);

//    cout<<"Enter no. of obstacles : ";
//    cin>>nobs;
//    for(int i=0;i<nobs;i++){
//      cout<<"Enter co-ordinates of obstacle-"<<i+1<<" : ";
//      cin>>ox>>oy;
//      obs[oy][ox]=false;
//    }   
//    cout<<"Obstacles stored"<<endl;
//    show_bool(length,height,obs);
//    int ans=backtracking(sx,sy,ex,ey,obs);
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }

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

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int backtracking(int sx, int sy, int ex, int ey, vector<vector<bool>>& obs) {
//     // Check if out of bounds
//     if (sx < 0 || sx >= obs[0].size() || sy < 0 || sy >= obs.size()) {
//         return 0; // Out of bounds, no valid path
//     }
//     // Check if destination is reached
//     if (sx == ex && sy == ey) {
//         return 1; // Reached destination
//     }
//     // Check if cell is an obstacle or already visited
//     if (!obs[sy][sx]) {
//         return 0; // Obstacle or already visited cell
//     }

//     // Mark the cell as visited
//     obs[sy][sx] = false;

//     int cnt = 0;
//     // Move right
//     cnt += backtracking(sx + 1, sy, ex, ey, obs);
//     // Move down
//     cnt += backtracking(sx, sy + 1, ex, ey, obs);

//     // Unmark the cell after exploring (backtrack)
//     obs[sy][sx] = true;

//     return cnt;
// }

// void show_bool(int length, int height, const vector<vector<bool>>& obs) {
//     for (int i = 0; i < height; ++i) {
//         for (int j = 0; j < length; ++j) {
//             cout << obs[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << "Bool finished" << endl;
// }

// int main() {
//     int sx, sy, ex, ey, nobs, ox, oy;
//     cout << "Enter Starting point: ";
//     cin >> sx >> sy;
//     cout << "Enter Ending point: ";
//     cin >> ex >> ey;

//     // Ensure valid starting and ending points
//     if (sx < 0 || sy < 0 || ex < 0 || ey < 0) {
//         cout << "Invalid coordinates" << endl;
//         return 1;
//     }

//     int height = max(ey, sy) + 1; // Adjust for 0-based indexing
//     int length = max(ex, sx) + 1; // Adjust for 0-based indexing

//     cout << "Height = " << height << " Length = " << length << endl;

//     vector<vector<bool>> obs(height, vector<bool>(length, true));

//     cout << "Bool matrix before initializing obstacles is:" << endl;
//     show_bool(length, height, obs);

//     cout << "Enter number of obstacles: ";
//     cin >> nobs;
//     for (int i = 0; i < nobs; ++i) {
//         cout << "Enter coordinates of obstacle-" << i + 1 << ": ";
//         cin >> ox >> oy;
//         if (oy >= 0 && oy < height && ox >= 0 && ox < length) {
//             obs[oy][ox] = false;
//         } else {
//             cout << "Obstacle coordinates out of bounds" << endl;
//         }
//     }

//     cout << "Obstacles stored" << endl;
//     show_bool(length, height, obs);

//     int ans = backtracking(sx, sy, ex, ey, obs);
//     cout << "Number of ways to reach destination are: " << ans << endl;

//     return 0;
// }
// Enter Starting point: 0 4
// Enter Ending point: 3 0
// Height = 5 Length = 4
// Bool matrix before initializing obstacles is:
// 1 1 1 1 
// 1 1 1 1 
// 1 1 1 1 
// 1 1 1 1 
// 1 1 1 1 
// Bool finished
// Enter number of obstacles: 2
// Enter coordinates of obstacle-1: 0 2
// Enter coordinates of obstacle-2: 2 3
// Obstacles stored
// 1 1 1 1 
// 1 1 1 1 
// 0 1 1 1 
// 1 1 0 1 
// 1 1 1 1 
// Bool finished


//multiple obstacles lengthy way
//LEFT and RIGHT movement included
//diagonal movement not included

// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;
// int horizontal(int sx,int sy,vector<int>&x,vector<int>&y);
// int verticle(int sx,int sy,vector<int>&x,vector<int>&y);

// int ex, ey;

// int verticle(int sx,int sy,vector<int>&x,vector<int>&y){
//   int index;
//   vector<int>::iterator v;
//   v=find(x.begin(),x.end(),sx);
//   if(v==x.end()){
//     if(sx==ex){
//       return 1;
//     } else {
//       return 2;
//     }
//   } else {
//     index=distance(x.begin(),v);
//     if(sx==x[index]&&sy==y[index]){
//       return 0;
//     } else if(sx!=ex){
//       return 2;
//     } else if(sx==ex&&sy>y[index]){
//       return 0;
//     } else if(sx==ex&&sy<y[index]){
//       return 1;
//     } else {
//     }
//   }
//   return 5;
// }
// int horizontal(int sx,int sy,vector<int>&x,vector<int>&y){
//   int index;
//   vector<int>::iterator h;
//   h=find(y.begin(),y.end(),sy);
//   if(h==y.end()){
//     if(sy==ey){
//       return 1;
//     } else {
//       return 2;
//     }
//   } else {
//     index=distance(y.begin(),h);
//     if(sx==x[index]&&sy==y[index]){
//       return 0;
//     } else if(sy!=ey){
//       return 2;
//     } else if(sy==ey&&sx<x[index]){
//       return 0;
//     } else if(sy==ey&&sx>x[index]){
//       return 1;
//     } else {
//     }
//   }
//   return 2;
// }
// int backtracking(int sx, int sy, vector<int> &x, vector<int> &y) {

//   int count=0,cnt1=0,cnt2=0,cnt3=0;
//   if(sx==ex&&sy==ey){return 1;}//cout<<"Reached destination"<<endl;
//   else if(sx>ex||sy<ey||sy>2){return 0;}//cout<<"Went ouside the maze"<<endl;
//   int t1=horizontal(sx,sy,x,y);
//   int t2=verticle(sx,sy,x,y);
//   if(t1==0||t2==0){
//     return 0;
//   } else if(t1==1||t2==1){
//     return 1;
//   } 
//     cnt1=backtracking(sx+1,sy,x,y);
//     cnt2=backtracking(sx,sy-1,x,y);
//    // cnt3=backtracking(sx,sy+1,x,y);
//   return count+cnt1+cnt2+cnt3;
// }

// int main() {
//   int n;
//   int sx, sy;
//   cout << "Enter the destination x & y co-ordinates : ";
//   cin >> ex >> ey;
//   cout << "Enter the strating x & yco-ordinates : ";
//   cin >> sx >> sy;
//   cout << "Enter how many obstcales you have : ";
//   cin >> n;
//   vector<int> x(n);
//   vector<int> y(n);
//   for (int i = 0; i < n; i++) {
//     cout << "Enter x & y co-ordinates of obstacle-" << i + 1 << ": ";
//     cin >> x[i];
//     cin >> y[i];
//   }
//   int ans = backtracking(sx, sy, x, y);
//   cout << "Number of ways to reach destination are :" << ans << endl;
// }


// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;
// int horizontal(int sx,int sy,vector<int>&x,vector<int>&y);
// int verticle(int sx,int sy,vector<int>&x,vector<int>&y);

// int ex, ey;

// int verticle(int sx,int sy,vector<int>&x,vector<int>&y){
//   int index;
//   vector<int>::iterator v;
//    v=find(x.begin(),x.end(),sx);
//    index=distance(x.begin(),v);
// if(v==x.end()){
//     if(sx==ex){
//       return 1;
//     } else if(sx==x[index]&&sy==y[index]){
//        return 0;
//     }
//     else {
//       return 2;
//     }
//   } 
//   else {
//     if(sx==x[index]&&sy==y[index]){
//       return 0;
//     } else if(sx!=ex){
//       return 2;
//     } else if(sx==ex&&sy>y[index]){
//       return 0;
//     } else if(sx==ex&&sy<y[index]){
//       return 1;
//     } else {
//     }
//   }
//   return 2;
// }
// int horizontal(int sx,int sy,vector<int>&x,vector<int>&y){
//   int index;
//   vector<int>::iterator h;
//   h=find(y.begin(),y.end(),sy);
//   index=distance(y.begin(),h);
//   if(h==y.end()){
//     if(sy==ey){
//       return 1;
//     } else if(sx==x[index]&&sy==y[index]){
//        return 0;
//     }
//     else {
//       return 2;
//     }
//   } 
//   else {
//     if(sx==x[index]&&sy==y[index]){
//       return 0;
//     } else if(sy!=ey){
//       return 2;
//     } else if(sy==ey&&sx<x[index]){
//       return 0;
//     } else if(sy==ey&&sx>x[index]){
//       return 1;
//     } else {
//     }
//   }
//   return 2;
// }
// int backtracking(int sx, int sy, vector<int> &x, vector<int> &y) {

//   int count=0,cnt1=0,cnt2=0,cnt3=0;
//   if(sx==ex&&sy==ey){return 1;}//cout<<"Reached destination"<<endl;
//   else if(sx>ex||sy<ey){return 0;}//cout<<"Went ouside the maze"<<endl;
//   int t1=horizontal(sx,sy,x,y);
//   int t2=verticle(sx,sy,x,y);
//   if(t1==0||t2==0){
//     return 0;
//   } else if(t1==1||t2==1){
//     return 1;
//   } 
//     cnt1=backtracking(sx+1,sy,x,y);
//     cnt2=backtracking(sx,sy-1,x,y);
//    cnt3=backtracking(sx+1,sy-1,x,y);
//   return count+cnt1+cnt2+cnt3;
// }

// int main() {
//   int n;
//   int sx, sy;
//   cout << "Enter the destination x & y co-ordinates : ";
//   cin >> ex >> ey;
//   cout << "Enter the strating x & yco-ordinates : ";
//   cin >> sx >> sy;
//   cout << "Enter how many obstcales you have : ";
//   cin >> n;
//   vector<int> x(n);
//   vector<int> y(n);
//   for (int i = 0; i < n; i++) {
//     cout << "Enter x & y co-ordinates of obstacle-" << i + 1 << ": ";
//     cin >> x[i];
//     cin >> y[i];
//   }
//   int ans = backtracking(sx, sy, x, y);
//   cout << "Number of ways to reach destination are :" << ans << endl;
// }