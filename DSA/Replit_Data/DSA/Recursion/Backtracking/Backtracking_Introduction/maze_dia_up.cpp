//UP RIGHT AND DIA-UP

// #include<iostream>
//  using namespace std;
//  int backtracking(int sx=0,int sy=0,int ex=2,int ey=2){
//    if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}
//    else if(sx>ex||sy>ey){cout<<"Went outside the maze"<<endl;return 0;}
//    int cnt=0;
//    cnt+= backtracking(sx,sy+1,ex,ey);
//    cnt+= backtracking(sx+1,sy,ex,ey);
//    cnt+= backtracking(sx+1,sy+1,ex,ey);

//    return cnt;
//  }
//  int main(){
//    int ans=backtracking();
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }

//UP & RIGHT only

// #include<iostream>
//  using namespace std;
//  int backtracking(int sx=0,int sy=0,int ex=2,int ey=2){
//    if(sx==ex&&sy==ey){cout<<"Destination reached"<<endl;return 1;}
//    else if(sx>ex||sy>ey){cout<<"Went outside the maze"<<endl;return 0;}
//    int cnt=0;
//    cnt+= backtracking(sx,sy+1,ex,ey);
//    cnt+= backtracking(sx+1,sy,ex,ey);
//    return cnt;
//  }
//  int main(){
//    int ans=backtracking();
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//  }

// 