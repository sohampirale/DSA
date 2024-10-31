// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int num=0,min_cost;
// class lab;
// class pc;
// void clear(){
//   cout << "\033[2J\033[1;1H";
// }
// class pc{
// public:
// int mark=0;
//   string pc_name,msg;
//   vector<pc*>links;
//   vector<int>dist;
//   pc(string pc_name){
//     this->pc_name=pc_name;
//     cout<<"PC created with name : "<<this->pc_name<<endl;
//   }
//   void connect(vector<lab*>&labs){
//     clear();
//     cout<<"let's connect PC named : "<<pc_name<<" with ALL other PC's :"<<endl;
//     // for(int i=0;i<labs.size();i++){
//      // for(int j=0;j<labs[i]->pcs.size();j++) {}
//     // }
//   }
// };

// class lab{
// public:
// string lab_name;
// vector<pc*>pcs;
// lab(string lab_name,int p){
//   // clear();
//   this->lab_name=lab_name;
//   int ask=0;
//   cout<<"Do you want to give "<<p<<" PC's name Manually or Serially (from "<<num+1<<" to "<<num+p<<")\n1 : Manually\n2 : Serially(by default)\nYour choice : ";
//   cin>>ask;
//   string pc_name;
//   if(ask==2){
//   for(int i=num;i<num+p;i++){
//     pc*temp= new pc(to_string(i+1));
//     pcs.push_back(temp);
//   }
//     cout<<p<<" PC's created in Lab : "<<this->lab_name<<" named from "<<num+1<<" to "<<num+p<<endl;
//     num=p;
//     cout<<"num is changed to = "<<num<<endl;
//   } else if(ask==1){
//     for(int i=0;i<p;i++){
//       cout<<"Enter PC name for PC no - "<<i+1<<" : ";
//       cin>>pc_name;
//       pc*temp=new pc(pc_name);
//       pcs.push_back(temp);
//     }
//     cout<<p<<" PC's created in Lab : "<<this->lab_name<<" with given name"<<endl;
//   } else{
//     cout<<"Invalid input"<<endl;
//   }
// }
// };

// void connect_one_pc(vector<lab*>&labs,pc*one_pc){
//   clear();
//   cout<<"let's connect PC named : "<<one_pc->pc_name<<" with ALL other PC's :"<<endl;
//   int temp;
//   for(int i=0;i<labs.size();i++){
//     for(int j=0;j<labs[i]->pcs.size();j++) {
//       auto test=find(labs[i]->pcs[j]->links.begin(),labs[i]->pcs[j]->links.end(),one_pc);
//       int it=distance(labs[i]->pcs[j]->links.begin(),test);
//       if(one_pc==labs[i]->pcs[j])continue;
//        one_pc->links.push_back(labs[i]->pcs[j]);
//       if(test!=labs[i]->pcs[j]->links.end()){
//         clear();
//         cout<<"PC named : "<<labs[i]->pcs[j]->pc_name<<" is already connected with "<<one_pc->pc_name<<" Distance between them is : "<<labs[i]->pcs[j]->dist[it]<<endl;;
//         cout<<"it = "<<it<<endl;
//         one_pc->dist.push_back(labs[i]->pcs[j]->dist[it]);
//         clear();
//         cout<<"Distance set to : "<<one_pc->dist.back()<<endl;
//       }
//       else {
//       cout<<"Connectimng PC named : "<<one_pc->pc_name<<" with PC named : "<<labs[i]->pcs[j]->pc_name<<endl;
//       cout<<"Enter distance between them : ";
//       cin>>temp;
//       one_pc->dist.push_back(temp);
//       clear();
//       cout<<"Connection Established '"<<one_pc->pc_name<<"'->'"<<labs[i]->pcs[j]->pc_name<<"' Distance = "<<one_pc->dist.back()<<endl;
//       // cout<<"PC named : "<<one_pc->pc_name<<"is connected with PC named : "<<labs[i]->pcs[j]->pc_name<<" distance between them is : "<<temp<<endl;
//     }
//       cout<<"hey"<<endl;
//     }
//   }
// }


// void connect_pcs(vector<lab*>&labs){
//   // cout<<"Number of labs are : "<<labs.size()<<endl;
//   for(int i=0;i<labs.size();i++){
//     cout<<"Let's connect PC's of Lab : "<<labs[i]->lab_name<<" with ALL other PC's"<<endl;
//     // cout<<"Lab : "<<labs[i]->lab_name<<" has "<<labs[i]->pcs.size()<<" PC's"<<endl;
//     for(int j=0;j<labs[i]->pcs.size();j++){
//       connect_one_pc(labs,labs[i]->pcs[j]);
//       clear();
//       cout<<"Connection of PC named : "<<labs[i]->pcs[j]->pc_name<<" is established all other PC's"<<endl;
//     }
//   }
// }
// void display(vector<lab*>&labs){
//   for(int i=0;i<labs.size();i++){
//     cout<<"Lab no-"<<i+1<<" : "<<labs[i]->lab_name<<endl;
//     for(int j=0;j<labs[i]->pcs.size();j++){
//       cout<<j+1<<". "<<labs[i]->pcs[j]->pc_name<<endl;
//     }
//   }
// }
// void display_pcs_of_one_lab(lab*one_lab){
//   cout<<"Lab : "<<one_lab->lab_name<<endl;
//   for(int i=0;i<one_lab->pcs.size();i++){
//     cout<<i+1<<". "<<one_lab->pcs[i]->pc_name<<endl;
//   }
// }
// void display_distance(lab*&one_lab){
//   for(int i=0;i<one_lab->pcs.size();i++){
//     for(int j=0;j<one_lab->pcs[i]->links.size();j++){
//     cout<<one_lab->pcs[i]->pc_name<<"<-->"<<one_lab->pcs[i]->links[j]->pc_name<<" Distance : "<<one_lab->pcs[i]->dist[j]<<endl;
//       }
//   }
// }
// pc* choose_start(vector<lab*>&labs){
//   clear();
//   display(labs);
//   int l,p;
//   cout<<"Let's choose the starting PC :"<<endl;
//   cout<<"Enter Lab no : ";
//   cin>>l;
//   display_pcs_of_one_lab(labs[l-1]);
//   cout<<"Enter PC number : ";
//   cin>>p;
//   return labs[l-1]->pcs[p-1];
// }
// pc* choose_destination(vector<lab*>&labs){
//   clear();
//   display(labs);
//   int l,p;
//   cout<<"Let's choose the destination PC :"<<endl;
//   cout<<"Enter Lab no : ";
//   cin>>l;
//   display_pcs_of_one_lab(labs[l-1]);
//   cout<<"Enter PC number : ";
//   cin>>p;
//   return labs[l-1]->pcs[p-1];
// }
// string final_path="";
// void backtracking(vector<lab*>&labs,pc*curr,pc*&dest,string msg,string path,int cost=0,int cnt=1){
//   if(curr->mark!=0){
//     // cout<<"Already visited"<<endl;
//     return;
//   }
//   if(curr==dest){
//     // cout<<"Destination reached with cost : "<<cost<<endl;
   
//     if(cost<=min_cost){
//       min_cost=cost;
//       dest->msg=msg;
//       // cout<<"min cost required to reach destination is : "<<min_cost<<endl;
//       // cout<<"Path follwed is : "<<path<<endl;
//       final_path=path;
//     }
//     return;
//   }
//   curr->mark=cnt;
//   for(int i=0;i<curr->links.size();i++){
//     backtracking(labs,curr->links[i],dest,msg,path+"->"+curr->links[i]->pc_name,cost+curr->dist[i],cnt+1);
//   }
//   curr->mark=0;
// }
// int main(){
//   int n,p,choice=1;
//   pc*start,*dest;
//   string lab_name,msg;
//   cout<<"Enter how many labs are there : ";
//   cin>>n;
//   vector<lab*>labs;
  
//   for(int i=0;i<n;i++){
//     // clear();
//     cout<<"Enter name of lab no-"<<i+1<<" : ";
//     cin>>lab_name;
//     cout<<"How many PC's are there in Lab : "<<lab_name<<" : ";
//     cin>>p;
//     lab*temp=new lab(lab_name,p);
//     labs.push_back(temp);
//     // clear();
//   }
//   connect_pcs(labs);
//   // cout<<"Came out"<<endl;
//   clear();
//   cout<<"All PC's are interconnected now"<<endl;
//   display(labs);
//   display_distance(labs[0]);
//   cout<<"Let's play a game of sending message from one computer to another via shortest path :"<<endl;
//   cout<<"Ready?"<<endl;
//   cin>>choice;
//    while(choice!=0){
//        start=choose_start(labs);
//        dest=choose_destination(labs);
//        clear();
//        cout<<"We are starting from PC named : "<<start->pc_name<<endl;
//        cout<<"We have chosen destination PC named : "<<dest->pc_name<<endl;
//      min_cost=*max_element(start->dist.begin(),start->dist.end());
//      // cout<<"min_cost set to : "<<min_cost<<endl;
//      cout<<"Enter the message you want to send from "<<start->pc_name<<" to "<<dest->pc_name<<" : ";
//      cin>>msg;
//        backtracking(labs,start,dest,msg,start->pc_name);
//      // cout<<"came out"<<endl<<endl;
//      clear();
//      cout<<"Shortest path from "<<start->pc_name<<" to "<<dest->pc_name<<" is : "<<min_cost<<endl;
//      cout<<"Message Received by "<<dest->pc_name<<" is : "<<dest->msg<<endl;
//      cout<<"Path followed for shortest distance is : "<<final_path<<endl;
//      cout<<"Want to play again?\n1 : Yes\n0 : No\nYour choice : ";
//      cin>>choice;
//    } 
// }