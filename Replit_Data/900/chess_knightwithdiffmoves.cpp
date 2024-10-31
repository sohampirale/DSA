// #include<iostream>
// using namespace std;
// int main(){
//   int t,a,b,kx,ky,qx,qy,k[8][8],q[8][8];
//   cin>>t;
//   for(int  i=0;i<t;i++){
//     int cnt=0;
//     cin>>a>>b>>kx>>ky>>qx>>qy;
//     k[0][0]=kx+a;
//     k[0][1]=ky+b;
//     k[1][0]=kx+a;
//     k[1][1]=ky-b;
//     k[2][0]=kx-a;
//     k[2][1]=ky+b;
//     k[3][0]=kx-a;
//     k[3][1]=ky-b;
//     if(a!=b){
//     k[4][0]=kx+b;
//     k[4][1]=ky+a;
//     k[5][0]=kx+b;
//     k[5][1]=ky-a;
//     k[6][0]=kx-b;
//     k[6][1]=ky+a;
//     k[7][0]=kx-b;
//     k[7][1]=ky-a;
//     }

//     q[0][0]=qx+a;
//     q[0][1]=qy+b;
//     q[1][0]=qx+a;
//     q[1][1]=qy-b;
//     q[2][0]=qx-a;
//     q[2][1]=qy+b;
//     q[3][0]=qx-a;
//     q[3][1]=qy-b;
//     if(a!=b){
//     q[4][0]=qx+b;
//     q[4][1]=qy+a;
//     q[5][0]=qx+b;
//     q[5][1]=qy-a;
//     q[6][0]=qx-b;
//     q[6][1]=qy+a;
//     q[7][0]=qx-b;
//     q[7][1]=qy-a;
//     }
//     for(int i=0;i<8;i++){
//       for(int j=0;j<8;j++){
//       if(a==b&&i==4)break;
//       if(a==b&&j>3)continue;;
//       if((k[i][0]==q[j][0])&&(k[i][1]==q[j][1]))cnt++;
//     }
//   }
//     cout<<cnt<<endl;
//   }
// }