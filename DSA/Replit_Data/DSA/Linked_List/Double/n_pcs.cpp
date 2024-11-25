// #include<iostream>
// #include<vector>
// using namespace std;
// class pc{
//   public:
//     int no;
//     vector<pc*>links;
//     pc(int no){
//       this->no=no;
//     }
//     void addLinks(int no,int n,vector<pc*>&pcs){
//       for(int i=0;i<n;i++){
//         if(i==no-1)continue;
//         links.push_back(pcs[i]);
//         cout<<"PC no-"<<no<<" connected with PC no-"<<pcs[i]->no<<endl;
//       }
//       cout<<n-1<<" pc's are connected with pc no-"<<no<<endl;
//     }
// };
// int main(){
//   int n;
//   cout<<"Enter how many PC's are in a lab : ";
//   cin>>n;
//   vector<pc*>pcs;
//   for(int i=1;i<=n;i++){
//     pc *temp=new pc(i);
//     cout<<"Pc no-"<<i<<" created"<<endl;
//     pcs.push_back(temp);
//     cout<<"Addres of pc no-"<<i<<" is added in pcs address vector"<<endl;
//   }
//   // cout<<"Let's see what we have stored"<<endl;
//   // for(int i=0;i<n;i++){
//   //   cout<<"PC no-"<<i+1<<" has no="<<pcs[i]->no<<endl;
//   // }
//   for(int i=0;i<n;i++){
//     pcs[i]->addLinks(i+1,n,pcs);
//   }
//   cout<<"came out"<<endl;
// }