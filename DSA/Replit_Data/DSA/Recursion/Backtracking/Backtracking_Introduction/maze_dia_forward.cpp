// #include<iostream>
//  using namespace std;
// int ub,lb;
//  int backtracking(int sx,int sy,int ex,int ey){
//    if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}
//    else if(sx>ex||(sy<lb)||(sy>ub)){cout<<"Went outside the maze"<<endl;return 0;}
//    int cnt=0;
//    cnt+=backtracking(sx+1,sy-1,ex,ey);
//    cnt+= backtracking(sx+1,sy+1,ex,ey);

//    return cnt;
//  }
//  int main(){
//    int sx,sy,ex,ey;
//    cout<<"Enter the destination of x & y co-ordinates : ";
//    cin>>ex>>ey;
//    cout<<"Enter the starting co-ordinates of x & y co-ordinates : ";
//    cin>>sx>>sy;
//    ub=ey+((ex-sx)/2);
//    lb=ey-((ex-sx)/2);
//    int ans=backtracking(sx,sy,ex,ey);
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }

//DIA-UP DIA-DOWN RIGHT

// #include<iostream>
//  using namespace std;
// int ub,lb;
//  int backtracking(int sx,int sy,int ex,int ey){
//    if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}
//    else if(sx>ex||(sy<lb)||(sy>ub)){cout<<"Went outside the maze"<<endl;return 0;}
//    int cnt=0;
//    cnt+=backtracking(sx+1,sy-1,ex,ey);
//    cnt+= backtracking(sx+1,sy+1,ex,ey);
//    cnt+=backtracking(sx+1,sy,ex,ey);
//    return cnt;
//  }
//  int main(){
//    int sx,sy,ex,ey;
//    cout<<"Enter the destination of x & y co-ordinates : ";
//    cin>>ex>>ey;
//    cout<<"Enter the starting co-ordinates of x & y co-ordinates : ";
//    cin>>sx>>sy;
//    ub=ey+((ex-sx)/2);
//    lb=ey-((ex-sx)/2);
//    int ans=backtracking(sx,sy,ex,ey);
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }


// #include<iostream>
//  using namespace std;
// int ub,lb;
// int ox,oy;
//  int sx,sy,ex,ey;

// void show(){
//   for(int i=0;i<=ex;i++){
//     for(int j=0;j<=ub;j++){
      
//     }
//   }
// }
//  int backtracking(int sx,int sy,int ex,int ey){
//    if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}
//      else if(sx==ox&&sy==oy){cout<<"Obstacle hit"<<endl;return 0;}
//    else if(sx>ex||(sy<lb)||(sy>ub)){cout<<"Went outside the maze"<<endl;return 0;}
//    int cnt=0;
//    cnt+=backtracking(sx+1,sy-1,ex,ey);
//    cnt+= backtracking(sx+1,sy+1,ex,ey);
//    cnt+=backtracking(sx+1,sy,ex,ey);
//    return cnt;
//  }
//  int main(){
//    cout<<"Enter the destination of x & y co-ordinates : ";
//    cin>>ex>>ey;
//    cout<<"Enter the starting co-ordinates of x & y co-ordinates : ";
//    cin>>sx>>sy;
//    cout<<"Enter x & y co-ordinates of obstacle : ";
//    cin>>ox>>oy;
//    ub=ey+((ex-sx)/2);
//    lb=ey-((ex-sx)/2);
//    int ans=backtracking(sx,sy,ex,ey);
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }

// #include<iostream>
// #include <unistd.h>
// using namespace std;
// int ub,lb;
// int ox,oy;
// int sx,sy,ex,ey;
// void clear() {
//   cout << "\033[2J\033[H";
// }
// void show(int sx,int sy){
//   cout<<"Next move"<<endl;
//   for(int i=ub;i>=lb;i--){
//     for(int j=0;j<=ex;j++){
//       if(j==sx&&i==sy)cout<<"o";
//       else cout<<" ";
//       if(j==ex&&i==ey)cout<<"[]";
//       else cout<<" ";
//       if(j==ox&&i==oy)cout<<"*";
//       else cout<<" ";
      
//       cout<<'|';
//     }
//   cout<<endl;
// }
//   cout<<"Moving to next way after 1 second"<<endl;
//   sleep(1);
//   clear();
// }
//  int backtracking(int sx,int sy,int ex,int ey){
//    show(sx,sy);
//    if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}
//     else if(sx==ox&&sy==oy){cout<<"Obstacle hit"<<endl;return 0;}
//    else if(sx>ex||(sy<lb)||(sy>ub)){cout<<"Went outside the maze"<<endl;return 0;}
//    int cnt=0;
//    cnt+=backtracking(sx+1,sy-1,ex,ey);
//    cnt+= backtracking(sx+1,sy+1,ex,ey);
//    cnt+=backtracking(sx+1,sy,ex,ey);
//    return cnt;
//  }
//  int main(){
//    cout<<"Enter the destination of x & y co-ordinates : ";
//    cin>>ex>>ey;
//    cout<<"Enter the starting co-ordinates of x & y co-ordinates : ";
//    cin>>sx>>sy;
//    cout<<"Enter x & y co-ordinates of obstacle : ";
//    cin>>ox>>oy;
//    ub=ey+((ex-sx)/2);
//    lb=ey-((ex-sx)/2);
//    int ans=backtracking(sx,sy,ex,ey);
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }
// #include<iostream>
// #include <unistd.h>
// using namespace std;
// int ub,lb;
// int ox,oy;
// int sx,sy,ex,ey;
// void clear() {
//   cout << "\033[2J\033[H";
// }
// void show(int sx,int sy){
//   cout<<"Next move"<<endl;
//   for(int i=ub;i>=lb;i--){
//     for(int j=0;j<=ex;j++){
//       if(j==sx&&i==sy)cout<<"o";
//       else cout<<" ";
//       if(j==ex&&i==ey)cout<<"[]";
//       else cout<<" ";
//       if(j==ox&&i==oy)cout<<"*";
//       else cout<<" ";

//       cout<<'|';
//     }
//   cout<<endl;
// }
//   cout<<"Moving to next way after 1 second"<<endl;
//   sleep(1);
//   clear();
// }
//  int backtracking(int sx,int sy,int ex,int ey){
//    show(sx,sy);
//    if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}
//     else if(sx==ox&&sy==oy){cout<<"Obstacle hit"<<endl;return 0;}
//    else if(sx>ex||(sy<lb)||(sy>ub)){cout<<"Went outside the maze"<<endl;return 0;}
//    int cnt=0;
//    cnt+=backtracking(sx+1,sy-1,ex,ey);
//    cnt+= backtracking(sx+1,sy+1,ex,ey);
//    cnt+=backtracking(sx+1,sy,ex,ey);
//    return cnt;
//  }
//  int main(){
//    bool a=-1;
  
//    a==true? cout<<true : cout<<false;
//    // cout<<b[0]<<endl;
//    // cout<<b[1]<<endl;
//  }




