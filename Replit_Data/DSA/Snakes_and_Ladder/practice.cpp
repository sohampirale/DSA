// #include<iostream>
// #include<vector>
// using namespace std;
// int sx,sy,ex,ey,n,nl,ns;

// void display(vector<vector<int>>&board);
// void display_transport(vector<vector<int>>&transport);
// void board_setup(vector<vector<int>>&board,vector<vector<int>>&transport,int nl);
// void game(vector<vector<int>>&board,vector<vector<int>>&transport,vector<vector<int>>&back,int sx=0,int sy=0,int p=1);

// void display(vector<vector<int>>&board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board[i].size();j++){
//       cout<<board[i][j]<<" |";
//     }
//     cout<<endl;
//   }
// }
// void display_transport(vector<vector<int>>&transport){
//   for(int i=0;i<transport.size();i++){
//     cout<<"Ladder number"<<i+1<<" transport to : "<<endl;
//     cout<<"x = "<<transport[i][0]<<"& y = "<<transport[i][1]<<endl;
//   }
// }
// void display_back(vector<vector<int>>&back){
//   for(int i=0;i<back.size();i++){
//     cout<<"Snake number"<<i+1<<" transport to : "<<endl;
//     cout<<"x = "<<back[i][0]<<"& y = "<<back[i][1]<<endl;
//   }
// }
// void ladder_setup(vector<vector<int>>&board,vector<vector<int>>&transport,int nl){
//   int lsx,lsy,lex,ley;
//   for(int i=0;i<nl;i++){
//     cout<<"Enter the starting point of ladder "<<i+1<<" : ";
//     cin>>lsx>>lsy;
//     board[lsy][lsx]=2;
//     cout<<"Enter ending point of ladder "<<i+1<<" : ";
//     cin>>lex>>ley;
//     transport[i].push_back(lex);
//     transport[i].push_back(ley);
//   }
//   cout<<"Board after marking the starting point of the ladders become : "<<endl;
//   display(board);
//   display_transport(transport);
// }
// void snakes_setup(vector<vector<int>>&board,vector<vector<int>>&back,int ns){
//   int sx,sy,ex,ey;
//   for(int i=0;i<ns;i++){
//     cout<<"Enter co-ordinates of the mouth of the snake"<<i+1<<" : ";
//     cin>>sx>>sy;
//     cout<<"Enter the co-ordinates of tail of the snake"<<i+1<<" : ";
//     cin>>ex>>ey;
//     board[sy][sx]=-1;
//     back[i].push_back(ex);
//     back[i].push_back(ey);
//   }
//   display_back(back);
// }
// void game(vector<vector<int>>&board,vector<vector<int>>&transport,vector<vector<int>>&back,int sx,int sy,int p){
//   int move=0;
//   if(sy%2==1)move=1;  //left
//   if(sy%2==0)move=2;  //right

//   if(sx==board.size())game(board,transport,back,board.size()-1,sy+1,p);
//   else if(sx==-1)game(board,transport,back,0,sy+1,p);
//   else if(board[sy][sx]==1){
//     cout<<"Reached destination"<<endl;
//     board[sy][sx]=p;
//     display(board);
//     return ;
//   } else if(board[sy][sx]==2){
//     cout<<"Reached one ladder at x = "<<sx<<" & y = "<<sy<<endl;
//     board[sy][sx]=p;
//     // p++;
//     sx=transport[0][0];
//     sy=transport[0][1];
//     cout<<"Value of x & y changed to x = "<<sx<<" & y = "<<sy<<endl;
//     transport.erase(transport.begin());
//     game(board,transport,back,sx,sy,p+1);
//     return;
//   } else if(board[sy][sx]==-1){
//     cout<<"Reached at the snake at x = "<<sx<<" & y = "<<sy<<endl;
//     board[sy][sx]=p;
//     sx=back[0][0];
//     sy=back[0][1];
//     cout<<"x & changed to x = "<<sx<<" & y = "<<sy<<endl;
//     back.erase(back.begin());
//     game(board,transport,back,sx,sy,p+1);
//     return;
//   } 
//   else if(sy==board.size()){
//     cout<<"Destination couldn't be reached x = "<<endl;
//     return ;   
//   } else if(((sy%2==1)&&(ex>sx)&&sy==ey)){
//     move=2;    //making it move right
//   } else if((sy%2==0)&&(sy==ey)&&(ex<sx)){
//     move=1;    //making it move left
//   }

//   if(move==1){
//     board[sy][sx]=p;
//     game(board,transport,back,sx-1,sy,p+1);
//   } else if(move == 2){
//     board[sy][sx]=p;
//     game(board,transport,back,sx+1,sy,p+1);
//   }
  
// }

// int main(){
//   cout<<"Enter starting position : ";
//   cin>>sx>>sy;
//   cout<<"Enter the ending position : ";
//   cin>>ex>>ey;
//   cout<<"Enter N for NxN board : ";
//   cin>>n;
//   cout<<"Enter number of ladders you have : ";
//   cin>>nl;
//   cout<<"Enter number of snakes you have : ";
//   cin>>ns;
//   vector<vector<int>>board(n,vector<int>(n,0));
//   vector<vector<int>>transport(nl);
//   vector<vector<int>>back(ns);
//   board[ey][ex]=1;
//   display(board);
//   ladder_setup(board,transport,nl);
//   snakes_setup(board,back,ns);
//   cout<<"After setting up snakes & ladder board becomes : "<<endl;
//   display(board);
//   game(board,transport,back);
// }


// #include<iostream>
// #include<vector>
// using namespace std;
// int sx,sy,ex,ey,n,nl,ns;
// void display(vector<vector<int>>&board);
// void display_transport(vector<vector<int>>&transport);
// void board_setup(vector<vector<int>>&board,vector<vector<int>>&transport,int nl);
// void game(vector<vector<int>>&board,vector<vector<int>>&transport,vector<vector<int>>&back,int sx=0,int sy=0,int p=1);

// void display(vector<vector<int>>&board){
//   for(int i=0;i<board.size();i++){
//     for(int j=0;j<board[i].size();j++){
//       cout<<board[i][j]<<" |";
//     }
//     cout<<endl;
//   }
// }
// void display_transport(vector<vector<int>>&transport){
//   for(int i=0;i<transport.size();i++){
//     cout<<"Ladder number"<<i+1<<" transport to : "<<endl;
//     cout<<"x = "<<transport[i][0]<<"& y = "<<transport[i][1]<<endl;
//   }
// }
// void display_back(vector<vector<int>>&back){
//   for(int i=0;i<back.size();i++){
//     cout<<"Snake number"<<i+1<<" transport to : "<<endl;
//     cout<<"x = "<<back[i][0]<<"& y = "<<back[i][1]<<endl;
//   }
// }
// void ladder_setup(vector<vector<int>>&board,vector<vector<int>>&transport,int nl){
//   int lsx,lsy,lex,ley;
//   for(int i=0;i<nl;i++){
//     cout<<"Enter the starting point of ladder "<<i+1<<" : ";
//     cin>>lsx>>lsy;
//     board[lsy][lsx]=2;
//     cout<<"Enter ending point of ladder "<<i+1<<" : ";
//     cin>>lex>>ley;
//     transport[i].push_back(lex);
//     transport[i].push_back(ley);
//   }
//   cout<<"Board after marking the starting point of the ladders become : "<<endl;
//   display(board);
//   display_transport(transport);
// }
// void snakes_setup(vector<vector<int>>&board,vector<vector<int>>&back,int ns){
//   int sx,sy,ex,ey;
//   for(int i=0;i<ns;i++){
//     cout<<"Enter co-ordinates of the mouth of the snake"<<i+1<<" : ";
//     cin>>sx>>sy;
//     cout<<"Enter the co-ordinates of tail of the snake"<<i+1<<" : ";
//     cin>>ex>>ey;
//     board[sy][sx]=-1;
//     back[i].push_back(ex);
//     back[i].push_back(ey);
//   }
//   display_back(back);
// }
// int min_moves=n*n;

// void game(vector<vector<int>>&board,vector<vector<int>>&transport,vector<vector<int>>&back,int sx,int sy,int p){
//   int move=0;
//   if(sy%2==1)move=1;  //left
//   if(sy%2==0)move=2;  //right

//      if(sx==board.size())game(board,transport,back,board.size()-1,sy+1,p);
//     else if(sx==-1)game(board,transport,back,0,sy+1,p);
//     else if(board[sy][sx]==1){
//       if(p<min_moves)min_moves=p;
//       cout<<"Reached destination"<<endl;
//       board[sy][sx]=p;
//       display(board);
//       return ;
//     } else if(board[sy][sx]==2){
//       cout<<"Reached one ladder at x = "<<sx<<" & y = "<<sy<<endl;
//       board[sy][sx]=p;
//       // p++;
//       sx=transport[0][0];
//       sy=transport[0][1];
//       cout<<"Value of x & y changed to x = "<<sx<<" & y = "<<sy<<endl;
//       transport.erase(transport.begin());
//       game(board,transport,back,sx,sy,p+1);
//       return;
//     } else if(board[sy][sx]==-1){
//       cout<<"Reached at the snake at x = "<<sx<<" & y = "<<sy<<endl;
//       board[sy][sx]=p;
//       sx=back[0][0];
//       sy=back[0][1];
//       cout<<"x & changed to x = "<<sx<<" & y = "<<sy<<endl;
//       back.erase(back.begin());
//       game(board,transport,back,sx,sy,p+1);
//       return;
//     } 
//     else if(sy==board.size()){
//       cout<<"Destination couldn't be reached x = "<<endl;
//       return ;   
//     } else if(((sy%2==1)&&(ex>sx)&&sy==ey)){
//       move=2;    //making it move right
//     } else if((sy%2==0)&&(sy==ey)&&(ex<sx)){
//       move=1;    //making it move left
//     }

//   if(move==1){
//     board[sy][sx]=p;
//     // for(int i=6;i>=1;i--){
//     game(board,transport,back,sx-1,sy,p+1);
//     // }
//   } else if(move == 2){
//     board[sy][sx]=p;
//     // for(int i=6;i>=1;i--){
//     game(board,transport,back,sx+1,sy,p+1);
//     // }
//   }
// }

// int main(){
//   cout<<"Enter starting position : ";
//   cin>>sx>>sy;
//   cout<<"Enter the ending position : ";
//   cin>>ex>>ey;
//   cout<<"Enter N for NxN board : ";
//   cin>>n;
//   cout<<"Enter number of ladders you have : ";
//   cin>>nl;
//   cout<<"Enter number of snakes you have : ";
//   cin>>ns;
//   vector<vector<int>>board(n,vector<int>(n,0));
//   vector<vector<int>>transport(nl);
//   vector<vector<int>>back(ns);
//   board[ey][ex]=1;
//   display(board);
//   ladder_setup(board,transport,nl);
//   snakes_setup(board,back,ns);
//   cout<<"After setting up snakes & ladder board becomes : "<<endl;
//   display(board);
//   game(board,transport,back);
//   cout<<"It reached the destination with minimum moves as : "<<min_moves<<endl;
// }