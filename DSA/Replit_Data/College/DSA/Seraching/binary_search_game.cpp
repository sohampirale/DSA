// #include<iostream>
// #include<vector>
// using namespace std;
// int guess(int secretNo,vector<int>&nums,string player){
//   cout<<"Best of luck "<<player<<" you can only make 3 wrong guess!"<<endl;
//   int tries=3;
//   int st=0,end=nums.size(),mid,guess;
//   while(tries!=0){
//     mid=st+(end-st)/2;
//     if(nums[mid]==secretNo){
//       cout<<"Congrats "<<player<<" you found the secret number with : "<<tries<<" tries left"<<endl;
//       return tries;
//     }
//     cout<<"We are currently pointing at "<<nums[mid]<<endl<<"Make your guess :)\n"<<"1 : Go right\n2 : Go Left\nYour choice : ";
//     cin>>guess;
//     if(guess==1){
//       if(nums[mid]<secretNo){
//         cout<<"You made correct guess...Keep going "<<player<<endl;
//         st=mid+1;
//       } else {
//         cout<<"Wrong guess..."<<endl;
//         cout<<"You have only "<<--tries<<" left"<<endl;
//       }
//     } else if(guess==2){
//       if(nums[mid]>secretNo){
//         cout<<"You made right guess...keep going"<<endl;
//         end=mid-1;
//       } else {
//         cout<<"Wrong guess...You have only "<<--tries<<" left"<<endl;
//       }
//     }
//   }
//   return tries;
// }
// int main(){
//   int n;
//   cout<<"Welcome to Binary Search Game "<<endl<<endl;
//   cout<<"I made this a two player game"<<endl;
//   cout<<"One player will select a secret number between 1-n and other player will run BINARY search and tell whether to move RIGHT or LEFT and each player will have 3 tries only"<<endl;
//   string p1,p2;
//   cout<<"Enter name of player 1 : ";
//   cin>>p1;
//   cout<<"Enter name of player 2 : ";
//   cin>>p2;
//   cout<<"Enter N : ";
//   cin>>n;
//   vector<int>nums;
//   cout<<"Array is : ";
//   for(int i=1;i<=n;i++){
//     nums.push_back(i);
//     cout<<i<<" ";
//   }
//   cout<<endl;
//   int choice=1;
//   while(choice!=0){
//     int secretNum;
//     cout<<p2<<" select a  secret number (ranging between 0-"<<n<<"): ";
//     cin>>secretNum;
//     int player1_tries=guess(secretNum,nums,p1);
//     if(player1_tries!=0)cout<<p1<<" found th enumber in "<<3-player1_tries<<" attempts"<<endl;
//     else cout<<p1<<" couldn't find the secret number"<<endl;
//     cout<<"Now it's "<<p2<<"'s turn to guess"<<endl;
//     cout<<p1<<" enter a secret number between 1 - "<<n<<" : "<<endl;
//     cin>>secretNum;
//     int player2_tries=guess(secretNum,nums,p2);
//     if(player1_tries==player2_tries){
//       cout<<"DRAW! both requied same number of attempts"<<endl;
//     } else if(player1_tries>player2_tries){
//       cout<<p1<<" wins!"<<endl;
//     } else{
//       cout<<p2<<" wins!"<<endl;
//     }
//     cout<<"Do you wan tot playt he game again ?\n1 : Yes\n 0 :No\nYour choice : ";
//     cin>>choice;
//   }
// }


// // Welcome to Binary Search Game 

// // I made this a two player game
// // One player will select a secret number between 1-n and other player will run BINARY search and tell whether to move RIGHT or LEFT and each player will have 3 tries only
// // Enter name of player 1 : Soham
// // Enter name of player 2 : Sanvi
// // Enter N : 15
// // Array is : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
// // Sanvi select a  secret number (ranging between 0-15): 13
// // Best of luck Soham you can only make 3 wrong guess!
// // We are currently pointing at 8
// // Make your guess :)
// // 1 : Go right
// // 2 : Go Left
// // Your choice : 1
// // You made correct guess...Keep going Soham
// // We are currently pointing at 12
// // Make your guess :)
// // 1 : Go right
// // 2 : Go Left
// // Your choice : 2
// // Wrong guess...You have only 2 left
// // We are currently pointing at 12
// // Make your guess :)
// // 1 : Go right
// // 2 : Go Left
// // Your choice : 2
// // Wrong guess...You have only 1 left
// // We are currently pointing at 12
// // Make your guess :)
// // 1 : Go right
// // 2 : Go Left
// // Your choice : 1
// // You made correct guess...Keep going Soham
// // We are currently pointing at 14
// // Make your guess :)
// // 1 : Go right
// // 2 : Go Left
// // Your choice : 2
// // You made right guess...keep going
// // Congrats Soham you found the secret number with : 1 left
// // Soham found th enumber in 2 attempts
// // Now it's Sanvi's turn to guess
// // Soham enter a secret number between 1 - 15 : 
// // 2
// // Best of luck Sanvi you can only make 3 wrong guess!
// // We are currently pointing at 8
// // Make your guess :)
// // 1 : Go right
// // 2 : Go Left
// // Your choice : 2
// // You made right guess...keep going
// // We are currently pointing at 4
// // Make your guess :)
// // 1 : Go right
// // 2 : Go Left
// // Your choice : 2
// // You made right guess...keep going
// // Congrats Sanvi you found the secret number with : 3 left
// // Sanvi wins!
// // Do you wan tot playt he game again ?
// // 1 : Yes
// //  0 :No
// // Your choice : 