// #include<iostream>
// using namespace std;
// int i=0;
// void pattern(int n){
//   if(n==0)return;
//   if(i==n){
//     i=0;
//     cout<<endl;
//     pattern(n-1);
//   }
//   else {
//     cout<<"* ";
//     i++;
//     pattern(n);
//   }
// }
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   pattern(n);
// }

// #include<iostream>
// using namespace std;
// // int i=0;
// void pattern(int r,int c,int i){
//   if(r==0)return;
//   if(c==0){c=1;}
//   if(i==c){
//     i=0;
//     cout<<endl;
//     if(r>c)pattern(r-1,c,i);
//     else pattern(r-1,c-1,i);
//   }
//   else {
//     cout<<"* ";
//     i++;
//     pattern(r,c,i);
//   }
// }
// int main(){
//   int r,c;
//   cout<<"Enter rows : ";
//   cin>>r;
//   cout<<"Enter coloms : ";
//   cin>>c;
//   pattern(r,c,0);
// }

// Enter rows : 7
// Enter coloms : 3
// * * * 
// * * * 
// * * * 
// * * * 
// * * * 
// * * 
// * 

//   Enter rows : 3
//   Enter coloms : 7
//   * * * * * * * 
//   * * * * * * 
//   * * * * * 

// #include<iostream>
// using namespace std;
// int i=0,c,oc,t=1;
// void pattern(int r,int c,int i){
//   if(c==0&&t==1)c=1;
//   else if(c==-1&&t==2)c=0;
//   if(r==0)return;
//   if(i==c){
//     cout<<endl;
//     i=oc;
//     pattern(r-1,c-1,i);
//   } else {
//     cout<<"* ";
//     pattern(r,c,i-1);
//   }
// }
// int main(){
//   int r;
//   cout<<"Enter rows : ";
//   cin>>r;
//   cout<<"Enter coloms : ";
//   cin>>c;
//   oc=c+1;
//   if(c>r){c-=r;t=2;}
//   pattern(r,c,oc);
// }  


// #include<iostream>
// using namespace std;
// int i=0,r,c,oc,oro,t=1;
// void pattern(int ri,int ci,int i){
//   if(ri==oro&&ci==oc)return;
//   else if(ci==oc)ci--;
//   if(i==ci){
//     cout<<endl;
//     // i=-1;
//     pattern(ri+1,ci+1,-1);
//   } 
//   else {
//     cout<<"* ";
//     pattern(ri,ci,i+1);
//   }
// }
// int main(){
//   cout<<"Enter rows : ";
//   cin>>r;
//   cout<<"Enter coloms : ";
//   cin>>c;
//   oc=c;
//   oro=r;
//   if(c>r){c-=r;t=2;}
//   else c=0;
//   pattern(0,c,-1);
// }  

// Enter rows : 3
// Enter coloms : 5
// * * * 
// * * * * 
// * * * * * 
//   Enter rows : 5
//   Enter coloms : 3
//   * 
//   * * 
//   * * * 
//   * * * 
//   * * * 
