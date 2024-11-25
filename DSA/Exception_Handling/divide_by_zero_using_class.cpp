#include <iostream>
#include <stdexcept> // For std::runtime_error
using namespace std;

class Divider {
public:
    double divide(double numerator, double denominator) {
        if (denominator == 0) {
            throw runtime_error("Error: Division by zero!"); 
        }
        return numerator / denominator; 
    }
};

int main() {
    Divider divider;
    double num, denom;

    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> denom;

    try {
        double result = divider.divide(num, denom); // Attempt division
        cout << "Result: " << result << endl;
    } catch (...){
        cout<<"Error occured"<<endl;
    }

    cout<<"Remianning code"<<endl;
    return 0;
}



















    // catch (const runtime_error& e) {
    //     cout << e.what() << endl; // Catching and displaying the exception message
    // }