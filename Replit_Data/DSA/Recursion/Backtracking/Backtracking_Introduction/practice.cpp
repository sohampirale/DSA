// //multiple obstacles 
// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;
// int horizontal(int sx,int sy,vector<int>&x,vector<int>&y);

// int n;
// int ex, ey;
// int hc,vc;
// int verticle(int sx,int sy,vector<int>&x,vector<int>&y){
//   int index;
//   // cout<<"sx = "<<sx<<" & sy = "<<sy;
//   vector<int>::iterator v;
//   v=find(x.begin(),x.end(),sx);
//   if(v==x.end()){
//     // cout<<"No obstacle present in this colomn & ";
//     if(sx==ex){
//       // cout<<"Destination is also present in this colomn so returning 1"<<endl;
//       return 1;
//     } else {
//       // cout<<" also Destination not present in this colomn so keep going so returning 2"<<endl;
//       return 2;
//     }
//   } else {
//     index=distance(x.begin(),v);
//     // cout<<"Obstacle present in this colomn & ";
//     if(sx==x[index]&&sy==y[index]){
//       // cout<<"Obstacle hit so retunring 0"<<endl;
//       return 0;
//     } else if(sx!=ex){
//       // cout<<" Destination is not present in this colomn so keep going returning 2"<<endl;
//       return 2;
//     } else if(sx==ex&&sy>y[index]){
//       // cout<<"sx > y["<<index<<"] so not possible retunrning 0 :("<<endl;
//       return 0;
//     } else if(sx==ex&&sy<y[index]){
//       // cout<<"sy<y["<<index<<"] so possible retunrning 1 :)"<<endl;
//       return 1;
//     } else {
//       // cout<<"No condition satisfied :|"<<endl;
//     }
//   }
//   // cout<<"This statement should not get satisfied except one time"<<endl;
//   return 5;
// }
// int horizontal(int sx,int sy,vector<int>&x,vector<int>&y){
//   // cout<<"sx = "<<sx<<" & sy = "<<sy;
//   int index;
//   vector<int>::iterator h;
//   h=find(y.begin(),y.end(),sy);
//   if(h==y.end()){
//     // cout<<"No obstacle present in this horizontal line & ";
//     if(sy==ey){
//       // cout<<"Destination present on the same horizontal level so returning 1"<<endl;
//       // test=1;
//       return 1;
//     } else {
//       // cout<<"No destination present as well in this horizontal level so keep going on returning 2"<<endl;
//       return 2;
//     }
//   } else {
//     // cout<<"Obstacle is present in this horizontal level & ";
//     index=distance(y.begin(),h);
//     // cout<<"Index is : "<<index<<endl;
//     if(sx==x[index]&&sy==y[index]){
//       // cout<<"Obstacle hit returning 0"<<endl;
//       return 0;
//     } else if(sy!=ey){
//       // cout<<"Destination is not present in this horizontal level so keep going on retunrning 2"<<endl;
//       return 2;
//     } else if(sy==ey&&sx>x[index]){
//       // cout<<"sx>x["<<index<<"] so not possible :( returning 0"<<endl;
//       return 0;
//     } else if(sy==ey&&sx<x[index]){
//       // cout<<"sx<x["<<index<<"] so possible :) retunring 1"<<endl;
//       return 1;
//     } else {
//       // cout<<"No condition got match "<<endl;
//     }
//   }
//   // cout<<"This statement should never be executed i think except one time "<<endl;
//   return 2;
// }
// int backtracking(int sx, int sy, vector<int> &x, vector<int> &y) {
//   int count=0,cnt1=0,cnt2=0;
//   if(sx==ex&&sy==ey){return 1;}//cout<<"Reached destination"<<endl;
//   else if(sx<ex||sy<ey){return 0;}//cout<<"Went ouside the maze"<<endl;
//   int t1=horizontal(sx,sy,x,y);
//   int t2=verticle(sx,sy,x,y);
//   if(t1==0||t2==0){
//     // cout<<"t1 or t2 saying not possible so retuning back "<<endl;
//     return 0;
//   } else if(t1==1||t2==1){
//     // cout<<"t1 or t2 is saying possible so retunring 1"<<endl;
//     return 1;
//   } 
//     cnt1=backtracking(sx-1,sy,x,y);
//     cnt2=backtracking(sx,sy-1,x,y);

//   return count+cnt1+cnt2;
// }

// int main() {
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


// // rows and colomns
 // #include<iostream>
 // using namespace std;
 // int backtracking(int sx=7,int sy=8,int ex=1,int ey=1){
 //   if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}
 //   else if(sx<1||sy<1){cout<<"Went outside the maze"<<endl;return 0;}
 //   int cnt=0;
 //   cnt+= backtracking(sx,sy-1,ex,ey);
 //   cnt+= backtracking(sx-1,sy,ex,ey);
 //   return cnt;
 // }
 // int main(){
 //   int ans=backtracking();
 //   cout<<"Number of ways to reach destination are : "<<ans<<endl;
 // }



// #include<iostream>
// using namespace std;
// int backtracking(int sx=4,int sy=4,int ex=2,int ey
// =1){
//   if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}
//   else if(sx<ex||sy<ey){cout<<"Went outside the maze"<<endl;return 0;}
//   int cnt = backtracking(sx,sy-1,ex,ey);
//   cnt+= backtracking(sx-1,sy,ex,ey);
//   return cnt;
// }
// int main(){
//   int ans=backtracking();
//   cout<<"Number of ways to reach destination are : "<<ans<<endl;
// }

// obstacle-long way
//  #include<iostream>
//  using namespace std;
//  int ox=3,oy=2;
//  int backtracking(int sx=4,int sy=4,int ex=2,int ey=1){
//    if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}
//    else if((sx<ex||sy<ey)){cout<<"Went outside the maze"<<endl;return 0;}
//    else if(sx==ox&&sy==oy){cout<<"Obstcale hit"<<endl;return 0;}
//    int cnt = backtracking(sx,sy-1,ex,ey);
//    cnt+= backtracking(sx-1,sy,ex,ey);
//    return cnt;
//  }
//  int main(){
//    int ans=backtracking();
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }

// obstcale-predifined
//  #include<iostream>
//  using namespace std;

// int ox=3,oy=1;
// int ex=1,ey=1;

// int backtracking(int sx=4,int sy=4){
//   if(sx==ox&&sy==oy){cout<<"Obstacle hit"<<endl;return 0;}
//   else if(sx==ex&&sx==ox&&sy>oy){cout<<"End of row reached but obstacle
//   stands in the way :("<<endl;return 0;} else
//   if(sx==ex&&sx==ox&&sy<oy){cout<<"Enter of row reached and the obstacle is
//   in the same row but above :)"<<endl;return 1;}
//     else if(sx==ox&&sx!=ox){cout<<"End of row reached ans obstcle is not in
//     the same colomn"<<endl;return 1;}
//   else if(sy==ey&&sy==oy&&sx>ox){cout<<"End of colomn reached but obstacle
//   stands in the way :("<<endl;return 0;} else
//   if(sy==ey&&sy==oy&&sx<ox){cout<<"End of colomn reached and the obstacle is
//   in the same row but stands back to it :)"<<endl;return 1;}
//     else if(sy==ey&&sy!=oy){cout<<"End of colomn reached but obstacle is not
//     in the same row"<<endl;return 1;}
//   else if(sx<ex||sy<ey){cout<<"Went ouside the maze"<<endl;return 0;}
//   int cnt=0;
//   cnt+=backtracking(sx-1,sy);
//   cnt+=backtracking(sx,sy-1);
//   return cnt;
// }
// int main(){
//   // cout<<"Enter the destination x & y co-ordinates : ";
//   // cin>>ex>>ey;
//   // cout<<"Enter obstacles x & y co-ordinates : ";
//   // cin>>ox>>oy;
//   int ans=backtracking();
//   cout<<"Number of ways to reach destination are : "<<ans<<endl;
// }

//  #include<iostream>
//  using namespace std;

// int ox=3,oy=1;
// int ex=1,ey=1;

// int backtracking(int sx=4,int sy=4){
//   if(sx==ox&&sy==oy){cout<<"Obstacle hit"<<endl;return 0;}
//   else if(sx==ex&&sx==ox&&sy>oy){cout<<"End of row reached but obstacle stands in the way :("<<endl;return 0;} else
//   if(sx==ex&&sx==ox&&sy<oy){cout<<"Enter of row reached and the obstacle is in the same row but above :)"<<endl;return 1;}
//     else if(sx==ox&&sx!=ox){cout<<"End of row reached ans obstcle is not in the same colomn"<<endl;return 1;}
//   else if(sy==ey&&sy==oy&&sx>ox){cout<<"End of colomn reached but obstacle stands in the way :("<<endl;return 0;} else
//   if(sy==ey&&sy==oy&&sx<ox){cout<<"End of colomn reached and the obstacle is in the same row but stands back to it :)"<<endl;return 1;}
//     else if(sy==ey&&sy!=oy){cout<<"End of colomn reached but obstacle is not in the same row"<<endl;return 1;}
//   else if(sx<ex||sy<ey){cout<<"Went ouside the maze"<<endl;return 0;}
//   int cnt=0;
//   cnt+=backtracking(sx-1,sy);
//   cnt+=backtracking(sx,sy-1);
//   return cnt;
// }
// int main(){
//   // cout<<"Enter the destination x & y co-ordinates : ";
//   // cin>>ex>>ey;
//   // cout<<"Enter obstacles x & y co-ordinates : ";
//   // cin>>ox>>oy;
//   int ans=backtracking();
//   cout<<"Number of ways to reach destination are : "<<ans<<endl;
// }

// #include <iostream>
// using namespace std;

// int ox, oy;
// int ex, ey;
// int sx, sy;

// int backtracking(int sx, int sy) {
//   if (sx == ox && sy == oy) {
//     cout << "Obstacle hit" << endl;
//     return 0;
//   } else if (sx == ex && sx == ox && sy > oy) {
//     cout<<"End of row reached but obstacle stands in the way :("<<endl;
//   return 0;
//   }
//   else if(sx==ex&&sx==ox&&sy<oy){cout<<"Enter of row reached and the obstacle
//   isin the same row but above :)"<<endl;return 1;} else if(sx==ox&&sx!=ox){
//     cout << "End of row reached ans obstcle is not inthe same colomn
//     "<<endl;return 1;
//   }
//   else if (sy == ey && sy == oy && sx > ox) {
//     cout<<"End of colomn reached but obstaclestands in the way
//     :("<<endl;return 0;
//   } else
//   if(sy==ey&&sy==oy&&sx<ox){
//     cout<<"End of colomn reached and the obstacle isin the same row but
//     stands back to it :)"<<endl;return 1;
//   }
//     else if(sy==ey&&sy!=oy){
//       cout << "End of colomn reached but obstacle is not in the same row
//       "<<endl;return 1;}
//     else if (sx < ex || sy < ey) {
//       cout << "Went ouside the maze" << endl;
//                 return 0;
//     }
//     int cnt = 0;
//       cnt += backtracking(sx - 1, sy);
//       cnt += backtracking(sx, sy - 1);
//       return cnt;
//   }
// int main() {
//   cout << "Enter the destination x & y co-ordinates : ";
//   cin >> ex >> ey;
//   cout << "Enter the strating x & yco-ordinates : ";
//   cin >> sx >> sy;
//   cout << "Enter obstacles x & y co-ordinates : ";
//    cin >> ox >> oy;
//   int ans = backtracking(sx, sy);
//   cout << "Number of ways to reach destination are : " << ans<< endl;
// }

// //multiple obstacles
// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;

// int n,cnt=0;
// int ex, ey;

// // if(sx==ox&&sy==oy){cout<<"Obstacle hit"<<endl;return 0;}


// int test_ver(int sx, int sy, vector<int> &x, vector<int> &y) {
//   vector<int>::iterator p;
//   int ret=0,index;
//   p = find(x.begin(), x.end(), sx);
//   index=distance(x.begin(),p);
//   if(sx==x[index]&&sy==y[index]&&(p!=x.end())){
//     cout<<"Obstacle hit so returning 0"<<endl;
//     ret=0;
//     return 0;
//   }
//   else if (p != x.end()&&sx==ex) {
//     cout << "Obstacle is in the same colomn as destination x co -ordinate, sx ="<<sx<<" & sy = "<<sy<<endl; 
//     if (sy > y[index]) {
//       cout << "sy > y[" << index << "] so returning 0 :(" << endl;
//       ret=0;
//       return ret;
//     } else if(sy<y[index]){
//       cout<<"sy < y["<<index<<"] so returning 1 :)"<<endl;
//       cnt+=1;
//       ret=1;
//       return ret;
//     } else if(sy==y[index]){
//       cout<<"Obstacle hit in test_ver so returning 0"<<endl;
//       ret=0;
//       return ret;
//     }else {cout<<"No condition found in test_ver this if else"<<endl;}
//   } else{
//     if(sx==ex&&sy==ey){
//       cout<<"Reached destination so retunring 1"<<endl;
//       ret=1;
//       return 1;
//     }  else if(p != x.end()&&sx!=ex){
//         cout<<"Obstacle present in the verticle path but no end destination is present so retunring 2"<<endl;
//         ret=2;
//         return 2;
//       } else if(p == x.end()&&sx==ex){
//         cout<<"Destination present in same verticle but obstacle not present so retunring 2"<<endl;
//         ret=2;
//         return ret;
//       } else if(p == x.end()&&sx!=ex){
//         cout<<"Nothing found in this verticle so retunring 2"<<endl;
//         ret=2;
//         return ret;
//       }  else {cout<<"No condition found in test_ver in last else"<<endl;}
//   } 
//   cout<<"Value returning from test_ver is : "<<ret<<endl;

//   return ret;
// }
// int test_hori(int sx, int sy, vector<int> &x, vector<int> &y) {
//   vector<int>::iterator ph;
//   ph = find(y.begin(), y.end(), sy);
//   int ret=1,index;
//   if(ph==y.end())cout<<"No obstacle found in this horizontal line"<<endl;
//    if(ph!=y.end())index=distance(y.begin(),ph);
//   if((ph!=y.end())&&(sx==x[index]) && (sy==y[index])){
//     cout<<"Obstacle hit in test_hori so returning 0"<<endl;
//     ret=0;
//     return 0;
//   }
//   else if (ph != y.end()&&(sy==ey)) {
//     cout << "Obstacle is in the same colomn as destination x co -ordinate, sx ="<<sx<<" & sy = "<<sy<<endl; 
//     if (sx > x[index]) {
//       cout << "sx > x[" << index << "] so returning 0 :(" << endl;
//       ret=0;
//       return ret;
//     } else if(sx<x[index]){
//       cout<<"sx < x["<<index<<"] so returning 1 :)"<<endl;
//       cnt+=1;
//       ret=1;
//       return ret;
//     } else if(sx==x[index]&&sy==y[index]){
//       cout<<"Obstacle hit returning 0"<<endl;
//       ret=0;
//       return ret;
//     } else {cout<<"No condition found in test_hori in second if else"<<endl;}
//   } else if (ph==y.end()){ 
//     if(sx==ex&&sy==ey){
//       cout<<"Reached destination so retunring 1"<<endl;
//       cnt++;
//       ret=1;
//       return ret;
//     }
//     else if(sy==ey){
//       cout<<"Object reacherd to horizontal level of destination which does not have obstacle in it so returning 1 "<<endl;
//       cnt++;
//       ret=1;
//       return ret;
//     }else if(sy!=ey){
//       cout<<"Nothing found so let's keep going(retunrnign 2)"<<endl;
//       ret=2;
//       return ret;
//     }else {cout<<"No condition found in test_hori in last else"<<endl;}
//   }
//   cout<<"Value returning from test_hori is : "<<ret<<endl;
//   return ret;
// }
// // int test=-1;
// int backtracking(int sx, int sy, vector<int> &x, vector<int> &y) {
//   if(sx==2&&sy==2)cout<<"Yes came here"<<endl;
//   // int cnt = 0;
//   int test1,test2;
//   if(sx<ex||sy<ey){cout<<"Went outside the maze"<<endl;return 0;}
//   test1=test_hori(sx,sy,x,y);
//   if(sy==ey&&test1==1){
//     cout<<"Reached at the last row and no obstcale is present ot retunring 1 hurrey horizontal test"<<endl;
//     return 1;
//   }
//   // if(test1==0||test1==1){return test1;}  //add this for test_y too return test1;
//   test2=test_ver(sx,sy,x,y);
//   if(sx==ex&&test2==1){
//     cout<<"Reached at the last colomn and no obstcale is present so returning 1 hurrey verticle test"<<endl;
//     return 1;
//   }
//   // if(test2==0||test2==1){return test2;}
  
//   int cnt1 = backtracking(sx - 1, sy, x, y);
//   cout<<"hello"<<endl;
//   int cnt2 = backtracking(sx, sy - 1, x, y);
//   cout<<"came out"<<endl;
//   cout<<"Answer accumulated is : "<<cnt1+cnt2<<endl;
//   return cnt1+cnt2;
// }

// int main() {
//   // int ox, oy;
//   int sx, sy;
//   cout << "Enter the destination x & y co-ordinates : ";
//   cin >> ex >> ey;
//   cout << "Enter the strating x & yco-ordinates : ";
//   cin >> sx >> sy;
//   cout << "Enter how many obstcales you have : ";
//   cin >> n;
//   vector<int> x;
//   vector<int> y;
//   int temp;
//   for (int i = 0; i < n; i++) {
//     cout << "Enter x & y co-ordinates of obstacle-" << i + 1 << ": ";
//     cin>>temp;
//     x.push_back(temp);
//     cin>>temp;
//     y.push_back(temp);
//   }
//   cout<<"Finished saving"<<endl;
//   int ans = backtracking(sx, sy, x, y);
//   cout<<"cnt varibale = "<<cnt<<endl;
//   cout<<"ans varibale = "<<ans<<endl;

//   // cout << "Number of ways to reach destination are :" << ans << endl;
// }

// int test_ver(int sx, int sy, vector<int> &x, vector<int> &y) {
//   vector<int>::iterator p;
//   int ret=0,index;
//   p = find(x.begin(), x.end(), sx);
//   index=distance(x.begin(),p);
//   if(sx==x[index]&&sy==y[index]&&(p!=x.end())){
//     cout<<"Obstacle hit so returning 0"<<endl;
//     ret=0;
//     return 0;
//   }
//   else if (p != x.end()&&sx==ex) {
//     cout << "Obstacle is in the same colomn as destination x co -ordinate, sx ="<<sx<<" & sy = "<<sy<<endl; 
//     if (sy > y[index]) {
//       cout << "sy > y[" << index << "] so returning 0 :(" << endl;
//       ret=0;
//       return ret;
//     } else if(sy<y[index]){
//       cout<<"sy < y["<<index<<"] so returning 1 :)"<<endl;
//       ret=1;
//       return ret;
//     } else if(sy==y[index]){
//       cout<<"Obstacle hit in test_ver so returning 0"<<endl;
//       ret=0;
//       return ret;
//     }else {cout<<"No condition found in test_ver this if else"<<endl;}
//   } else{
//     if(sx==ex&&sy==ey){
//       cout<<"Reached destination so retunring 1"<<endl;
//       ret=1;
//       return 1;
//     }  else if(p != x.end()&&sx!=ex){
//         cout<<"Obstacle present in the verticle path but no end destination is present so retunring 2"<<endl;
//         ret=2;
//         return 2;
//       } else if(p == x.end()&&sx==ex){
//         cout<<"Destination present in same verticle but obstacle not present so retunring 2"<<endl;
//         ret=2;
//         return ret;
//       } else if(p == x.end()&&sx!=ex){
//         cout<<"Nothing found in this verticle so retunring 2"<<endl;
//         ret=2;
//         return ret;
//       }  else {cout<<"No condition found in test_ver in last else"<<endl;}
//   } 
//   cout<<"Value returning from test_ver is : "<<ret<<endl;

//   return ret;
// }
// cout<<n<<" Obstacles are present at the co-ordinates :"<<endl;
// for(int i=0;i<n;i++){
//   cout<<x[i]<<" "<<y[i]<<endl;
// }
// practice
// else if(sx==ex&&sx==ox&&sy>oy){cout<<"End of row reached but
// obstacle stands in the way :("<<endl;return 0;} else
// if(sx==ex&&sx==ox&&sy<oy){cout<<"Enter of row reached and the
// obstacle is in the same row but above :)"<<endl;return 1;}
//   else if(sx==ox&&sx!=ox){cout<<"End of row reached ans obstcle
//   is not in the same colomn"<<endl;return 1;}
// else if(sy==ey&&sy==oy&&sx>ox){cout<<"End of colomn reached but
// obstacle stands in the way :("<<endl;return 0;} else
// if(sy==ey&&sy==oy&&sx<ox){cout<<"End of colomn reached and the
// obstacle is in the same row but stands back to it
// :)"<<endl;return 1;}
//   else if(sy==ey&&sy!=oy){cout<<"End of colomn reached but
//   obstacle is not in the same row"<<endl;return 1;}
// else if(sx<ex||sy<ey){cout<<"Went ouside the maze"<<endl;return
// 0;}

// #include<iostream>
// using namespace std;
// int backtracking(int sx=3,int sy=3,int ex=1,int ey=1){
//   if(sx==1||sy==1){cout<<"end or row or colomn
//   reached"<<endl;return 1;} int cnt=0; cnt+=
//   backtracking(sx,sy-1,ex,ey); cnt+= backtracking(sx-1,sy,ex,ey);
//   return cnt;
// }
// int main(){
//   int ans=backtracking();
//   cout<<"Number of ways to reach destination are : "<<ans<<endl;
// }

// matrix

// #include<iostream>
// using namespace std;
// int backtracking(int sx=0,int sy=2,int ex=2,int ey=0){
//   if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}
//   else if(sx>2||sy<0){cout<<"Went outside the maze"<<endl;return
//   0;} int cnt=0; cnt+= backtracking(sx+1,sy,ex,ey); cnt+=
//   backtracking(sx,sy-1,ex,ey); return cnt;
// }
// int main(){
//   int ans=backtracking();
//   cout<<"Number of ways to reach destination are : "<<ans<<endl;
// }

// #include<iostream>
// using namespace std;
// int backtracking(int sx=0,int sy=2,int ex=2,int ey=0){
//   if(sx==2||sy==0){cout<<"End of colomn or row of maze
//   reached"<<endl;return 1;} int cnt=0; cnt+=
//   backtracking(sx+1,sy,ex,ey); cnt+= backtracking(sx,sy-1,ex,ey);
//   return cnt;
// }
// int main(){
//   int ans=backtracking();
//   cout<<"Number of ways to reach destination are : "<<ans<<endl;
// }
