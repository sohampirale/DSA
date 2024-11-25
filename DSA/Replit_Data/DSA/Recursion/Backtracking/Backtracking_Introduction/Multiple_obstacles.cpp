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
//     } else if(sy==ey&&sx>x[index]){
//       return 0;
//     } else if(sy==ey&&sx<x[index]){
//       return 1;
//     } else {
//     }
//   }
//   return 2;
// }
// int backtracking(int sx, int sy, vector<int> &x, vector<int> &y) {
  
//   int count=0,cnt1=0,cnt2=0;
//   if(sx==ex&&sy==ey){return 1;}//cout<<"Reached destination"<<endl;
//   else if(sx<ex||sy<ey){return 0;}//cout<<"Went ouside the maze"<<endl;
//   int t1=horizontal(sx,sy,x,y);
//   int t2=verticle(sx,sy,x,y);
//   if(t1==0||t2==0){
//     return 0;
//   } else if(t1==1||t2==1){
//     return 1;
//   } 
//     cnt1=backtracking(sx-1,sy,x,y);
//     cnt2=backtracking(sx,sy-1,x,y);
//   return count+cnt1+cnt2;
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