#include<iostream>
#include<limits>
using namespace std;
int main(){
        double num1,num2;
        double ans;
    while(1){
        try{
            cout<<"ENter num1 : ";
            cin>>num1;
            if (std::cin.fail()) 
                throw "Wrong input given";
            cout<<"Enter num2 : ";
            cin>>num2;
            if (std::cin.fail()) 
                throw "Wrong input given";
            break;
        } catch (const char*e){
                cout<<"Error occured : "<<e<<endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Invalid input. Please enter a valid number: ";
        }
    }
    cout<<"Input taken successfully"<<endl;
    cout<<"NUm1 : "<<num1<<endl;
    cout<<"Num2 : "<<num2<<endl;
    try{
        if(num2==0){
            throw string("Canot divide by 0");
        } else ans=num1/num2;
        cout<<"Division of "<<num1<<" & "<<num2<<" is : "<<ans<<endl;
    } catch(const string& e){
        cout<<"Error occured : "<<e<<endl;
    }
     catch(...){
        cout<<"Error occured"<<endl;
    }

}

// ENter num1 : 23
// Enter num2 : ds
// Error occured : Wrong input given
// Invalid input. Please enter a valid number: ENter num1 : 12
// Enter num2 : sd
// Error occured : Wrong input given
// Invalid input. Please enter a valid number: ENter num1 : 12
// Enter num2 : 0
// Input taken successfully
// NUm1 : 12
// Num2 : 0
// Error occured : Canot divide by 0


// ENter num1 : as
// Invalid input. Please enter a valid number: ENter num1 : ds
// Invalid input. Please enter a valid number: ENter num1 : 23
// Enter num2 : sdd
// Invalid input. Please enter a valid number: ENter num1 : 3223
// Enter num2 : 122.2323
// Input taken successfully
// soham@soham-Inspiron-20-Mod

// ENter num1 : as
// Invalid input. Please enter a valid number: ENter num1 : ds
// Invalid input. Please enter a valid number: ENter num1 : 23
// Enter num2 : sdd
// Invalid input. Please enter a valid number: ENter num1 : 3223
// Enter num2 : 122.2323
// Input taken successfully