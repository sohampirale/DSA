// #include<iostream>
// #include<vector>
// using namespace std;

// int find_heap(vector<int>&no,int st,int end){
//   int mid=st+(end-st)/2;
//   while(st!=end){
//     mid=st+(end-st)/2;
//     if(no[mid]<no[mid+1]){
//       st=mid+1;
//     } else{
//       end=mid;
//     }
//   }
//   cout<<"Peak found at : "<<st<<endl;
//   return st;
// }

// int find_change(vector<int>&no,int st,int end){
//   while(no[st]>no[end]&&end<=no.size()){
//     int temp=end;
//     end=end+(end-st+1);
//     st=temp;
//   }
//   // cout<<"FIrst change stopped at end = "<<end<<endl;
//   if(end>no.size()){
//     cout<<"End went outside the raneg of no so made the end=no.size()"<<endl;
//     end=no.size();
//     return end;
//   } else if(no[end]>no[end+1]) {
//     return find_change(no,st,st+1);
//   } else if(no[end]<no[end+1]){
//     return end;
//   } else{
//     cout<<"This shouldn't arise"<<endl;
//     return end;
//   }
// }

// int decreasing_first(vector<int>&no){
//   int change=find_change(no,0,1);
//   cout<<"Change spotted at index = "<<change<<endl;
//   int peak=find_heap(no,change,no.size()-1);
//   cout<<"Peak found by specific function is : "<<peak<<endl;
//   return peak;
// }
// int find_change2(vector<int>&no,int st,int end){
//   int last=st;
//   while(no[st]<no[end]&&end<+no.size()){
//     last=st;
//     int temp=end;
//     end=end+(end-st+1);
//     st=temp;
//   }
//   if(end>no.size()){
//     cout<<"end became greater than no.size() so setting end = no.size()"<<endl;
//     end=no.size();
//     return no.size();
//   } else if(no[end]>no[end+1]){
//     int ans=find_heap(no,last,end);
//     cout<<"Peak found by specific funciton is : "<<ans<<endl;
//     return ans;
//   } else if(no[end]<no[end+1]){
//     return find_change2(no,last,last+1);
//   } else {
//     cout<<"I think this will never arrise"<<endl;
//     return -1;
//   }
// }
// int increasing_first(vector<int>&no){
//  int ans=find_change2(no,0,1);
//   return ans;
// }
// int main(){
//   int n,temp;
//   cout<<"ENter hwo many numbers you ahve : ";
//   cin>>n;
//   vector<int>no;
//   cout<<"Enter "<<n<<" numbers : ";
//   for(int i=0;i<n;i++){
//     cin>>temp;
//     no.push_back(temp);
//   }
//   if(no[0]>no[1]){
//     int ans=decreasing_first(no);
//     cout<<"Ans = "<<ans<<endl;
//   } else if(no[0]<no[1]){
//     int ans=increasing_first(no);
//     cout<<"Ans recieved is : "<<ans<<endl;
//   }
//   int heap=find_heap(no,0,n-1);
//   cout<<"Peak found at : "<<heap<<endl;
// }


