#include <iostream>
using namespace std;

int main() {

    int numerator,denominator;
    cout<<"Enter numerator : ";
    cin>>numerator;
    cout<<"Enter denominator :";
    cin>>denominator;

    try {
        if(denominator==0){
            throw "0 cannot be a denominator";
        }
        int ans=numerator/denominator;
        cout<<"Ans : "<<ans<<endl;
    }catch(const string &e){
        cout<<"Errro occured : "<<e<<endl;
    } 
   
    cout<<"Remianning code"<<endl;

    return 0;
}








// if (y == 0) {
//             throw "Division by zero error"; // Throwing an exception
//         }
//         cout << "Result: " << a / b << endl;