// //Soham Sachin Pirale
// //Roll no - 2022

// #include<iostream>
// #include<deque>
// using namespace std;
// int main(){
//   int n;
//   cout<<"Enter n : ";
//   cin>>n;
//   deque<int>dequeue;
//   cout<<"Enter "<<n<<" numbers : ";
//   int temp;
//   for(int i=0;i<n;i++){
//     cin>>temp;
//     dequeue.push_back(temp);
//   }
//   int k;
//   cout<<"Enter k : ";
//   cin>>k;
//   deque<int>temp_dq;
//   // cout<<"deuque.size() = "<<dequeue.size()<<endl;
//   while(dequeue.size()>=k){
//     int test=0;
//     while(temp_dq.size()!=k){
//       int front=dequeue.front();
//       temp_dq.push_back(front);
//       dequeue.pop_front();
//       if(front<0){test=1;cout<<front<<" ";break;}
//     }
//     if(test==0)cout<<"0 ";
//     else {test=0;}  //cout<<"Resetting test = 0"<<endl;
    
//     if(!temp_dq.empty())temp_dq.pop_front();
//     while(!temp_dq.empty()){
//       dequeue.push_front(temp_dq.back());
//       temp_dq.pop_back();
//     }
//     if(dequeue.size()<k){
//       cout<<endl<<"Answer over"<<endl;
//       break;
//     }
//   }
// }

// // Enter n : 8
// // Enter 8 numbers : 12 -1 -7 8 -15 30 16 28
// // Enter k : 3
// // -1 -1 -7 -15 -15 0 
// // Answer over

// // Enter n : 5
// // Enter 5 numbers : -8 2 3 -6 10
// // Enter k : 2
// // -8 0 -6 -6 
// // Answer over