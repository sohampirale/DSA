// #include <iostream>
// using namespace std;

// class Box {
//   private:
//       int private_data; 
//   protected:
//     int protected_data; 
//   public:
//       Box(int priv_data,int protected_d)  {
//         private_data=priv_data;
//         protected_data=protected_d;
//         cout<<"Taken = "<<protected_d<<endl;
//         cout<<"Saved = "<<protected_data<<endl;
//       } 
//       friend void printLength(Box b);
// };

// void printLength(Box b) {
//     cout<<"Private data : "<<b.private_data<<endl;
//     cout<<"Protected data : "<<b.protected_data<<endl;
// }

// int main() {
//   string s ="20";
//   int a=stoi(s,nullptr,16);
//   cout<<a<<endl;
//   int t;
//     cout<<"ENter somethign : ";
//     cin>>t;
//     cout<<t<<endl;
//     Box b(10,0b1000);          
//     printLength(b);     
//     return 0;
// }

// //output
// // Private data : 10
// // Protected data : 20
