// //a bit modification

// // #include<iostream>
// // #include<vector>
// // using namespace std;
// // vector<string>final_ans;
// // int backtracking(int sx=3,int sy=3,int ex=1,int ey=1,string ans=""){
// //    if(sx==ex&&sy==ey){final_ans.push_back(ans);cout<<"Destination reached"<<endl;return 1;}
// //    // else if(sx<1||sy<1){cout<<"Went outside the maze"<<endl;return 0;}
// //    int cnt=0;
// //    if(sy>ey)cnt+= backtracking(sx,sy-1,ex,ey,ans+"D");
// //    if(sx>ex)cnt+= backtracking(sx-1,sy,ex,ey,ans+"R");
// //    return cnt;
// // }
// // int main(){
// //    int ans=backtracking();
// //    cout<<"Number of ways to reach destination are : "<<ans<<endl;
// //    cout<<"Ways we can reach destination are : "<<endl;
// //    for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
// // }


//diagonal movement

// #include<iostream>
// #include<vector>
// using namespace std;
// vector<string>final_ans;
// int backtracking(int sx=3,int sy=3,int ex=1,int ey=1,string ans=""){
//    if(sx==ex&&sy==ey){final_ans.push_back(ans);cout<<"Destination reached"<<endl;return 1;}
//    // else if(sx<1||sy<1){cout<<"Went outside the maze"<<endl;return 0;}
//    int cnt=0;
//    if(sy>ey)cnt+= backtracking(sx,sy-1,ex,ey,ans+"d");
//    if(sx>ex)cnt+= backtracking(sx-1,sy,ex,ey,ans+"r");
//    if(sx>ex&&sy>ey)cnt+=backtracking(sx-1,sy-1,ex,ey,ans+"D");
//    return cnt;
// }
// int main(){
//    int ans=backtracking();
//    cout<<"Number of ways to reach destination are : "<<ans<<endl;
//    cout<<"Ways we can reach destination are : "<<endl;
//    for(int i=0;i<final_ans.size();i++)cout<<final_ans[i]<<endl;
// }