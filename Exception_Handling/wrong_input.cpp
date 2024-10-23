#include <iostream>

using namespace std;

int main() {
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    try {
        int num;
        cout<<"Enter a number : ";
        cin>>num;

        if(cin.fail()){
            throw "Not a number";
        }
        
    }catch(...){
        cout<<"Error occured"<<endl;
        cout<<"You did not enter a number"<<endl;
    } 

    cout<<"Remainning code"<<endl;

    return 0;
}
