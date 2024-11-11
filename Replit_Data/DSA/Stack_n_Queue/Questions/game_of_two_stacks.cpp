// #include<iostream>
// #include<vector>
// using namespace std;
// int max_moves=0;
// void answer(vector<int>num1,vector<int>num2,int k,int sum=0,int cnt=-1){        
//   if(sum>k||num1.empty()||num2.empty()){
//     cout<<"cnt = "<<cnt<<" & sum = "<<sum<<endl; 
//     if(cnt>max_moves)max_moves=cnt;
//     return;
//   }
//   vector<int>temp1=num1;
//   vector<int>temp2=num2;
//   temp1.pop_back();
//   answer(temp1,num2,k,sum+num1.back(),cnt+1);
//   temp2.pop_back();
//   answer(num1,temp2,k,sum+num2.back(),cnt+1);
// }
// int main(){
//   vector<int>num1,num2;
//   int n1,n2,temp;
//   cout<<"Enter n1 & n2 : ";
//   cin>>n1>>n2;
//   cout<<"Enter "<<n1<<" elements : "<<endl;
//   for(int i=0;i<n1;i++){
//     cin>>temp;
//     num1.push_back(temp);
//   }
//   cout<<"Enter "<<n2<<" elements : "<<endl;
//   for(int i=0;i<n2;i++){
//     cin>>temp;
//     num2.push_back(temp);
//   }
//   int k;
//   cout<<"Enter k : ";
//   cin>>k;
//   answer(num1,num2,k);
//   cout<<"max moves are : "<<max_moves<<endl;
// }