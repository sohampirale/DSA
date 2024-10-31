// // Extend the above program to display the area of circles. This requires addition of a new derived class
// // ‘circle ‘that computes the area of a circle. Remember, for a circle we need only one value, its radius,
// // but the get_data() function in the base class requires two values to be passed. ( Hint: Make the second
// // argument of get_data() function as a default one with zero value.)

// //Name - Soham Sachin Pirale
// //Roll no - 2022
// //Batch - S2

// #include <iostream>
// using namespace std;

// class shape {
// public:
//     shape(){
//         cout<<"Constructor of shape"<<endl;
//     }
//     virtual void get_data(){
//         cout<<"Function of shape class"<<endl;
//     }
//     virtual void get_area(){
//       cout<<"Area function of shape class"<<endl;
//     }
// };

// class circle : public shape{
//         int radius;
//     public:
//         circle(int radius){
//             cout<<"Circle object constructor"<<endl;
//             this->radius=radius;
//         }
//         void get_data() override{
//             cout<<"Radius = "<<radius<<endl;
//         }
//         void get_area()override{
//           float area=3.14*radius*radius;
//           cout<<"Area of the circle is : "<<area<<endl;
//         }
// };

// int main() {
//     shape* ptr=nullptr;
//     circle c(2);
//     ptr=&c;
//     ptr->get_data();
//     ptr->get_area();
//     return 0;
// }
// // Constructor of shape
// // Circle object constructor
// // Radius = 2
// // Area of the circle is : 12.56

