// #include <iostream>
// using namespace std;

// class Teacher;

// class Student {
//     private:
//         int rollno;
    
//     protected:
//         char div;
//     public:
//         Student(int roll, char d) {
//             cout<<"Student constructor"<<endl;
//             rollno=roll;
//             div=d;
//         }
    
//     friend class Teacher;
// };

// class Teacher {
//     public:
//         void displayStudentDetails(Student s) {
//             cout<<"Roll number(private) : "<<s.rollno<<endl;
//             cout<<"Division of student (protected) : "<<s.div<<endl;
//         }
// };

// int main() {
//     Student s("Alice", 20); 
//     Teacher t;               
//     t.displayStudentDetails(s);  
//     return 0;
// }











// // Teacher{
// //     cout<<"Teacher constructor"<<endl;
// // };