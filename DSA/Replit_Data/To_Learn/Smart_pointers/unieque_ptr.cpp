// #include <iostream>
// #include <memory>  // For smart pointers

// using namespace std;

// class MyClass {
// public:
//   int data;
//     MyClass(int data) { 
//       this->data=data;
//       cout << "Resource Acquired (unique_ptr)\n"; 
//     }
//     ~MyClass() { cout << "Resource Released (unique_ptr)\n"; }
// };

// int main() {
//     // Create a unique_ptr managing a MyClass object
//   int data;
//   cout<<"Enter data : ";
//   cin>>data;
//     unique_ptr<MyClass> ptr = make_unique<MyClass>(data);
//     cout<<ptr->data<<endl;
//     // The resource is automatically released when ptr goes out of scope
//     return 0;
// }
