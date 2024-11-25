// #include <iostream>
// #include <memory> // Include for smart pointers

// using namespace std;

// class student{
//     public:
//         string name;
//         int rollno;
//         long long URN;
//         int cnt;

//         student(string name,int rollno,long long URN):name(name),rollno(rollno),URN(URN),cnt(0){}

//         ~student(){
//             cout<<"Destructor when cnt = "<<this->cnt<<endl;
//         }
// };
// void func2(shared_ptr<student>&ptr){
//     shared_ptr<student>temp_ptr=ptr;
//     temp_ptr->cnt++;
//     cout<<temp_ptr.use_count()<<endl;
//     cout<<"Going back"<<endl;
// }
// void func(shared_ptr<student>&ptr){
//     shared_ptr<student>temp_ptr=ptr;
//     temp_ptr->cnt++;
//     cout<<temp_ptr.use_count()<<endl;
//     func2(ptr);
//     cout<<"IN func"<<endl;
// }
// int main() {
//     shared_ptr<student>ptr2=make_shared<student>("S2",2023,232323);
//     cout<<ptr2.use_count()<<endl;
//     func(ptr2);
//     cout<<"in main"<<endl;
//     cout<<ptr2->name<<" is still existing"<<endl;
//     return 0;
// }



#include <iostream>
#include <memory>

using namespace std;

class MyClass {
public:
    MyClass() { cout << "Constructor called" << endl; }
    ~MyClass() { cout << "Destructor called" << endl; }
};

int main() {
    MyClass obj; // Statically allocated object
    shared_ptr<MyClass> ptr = make_shared<MyClass>(obj); // Incorrect

    // This will lead to undefined behavior when ptr goes out of scope
    return 0;
}
