#include <iostream>
using namespace std;

int main() {
    int num[]={10,20,30,40,50};

    try {
        int index;
        cout<<"Enter index : ";
        cin>>index;
        if(index>=5){
            throw "out of bounds";
        }
        cout<<"Element present at index ("<<index<<") = "<<num[index]<<endl;
    } catch(...){
        cout<<"\nError occured"<<endl;
        cout<<"Array out of bounds"<<endl<<endl;
    }

    cout<<"Remainning code"<<endl;
    return 0;
}













// cout<<"\nPrinting all nummbers of array : ";
//         for(int i=0;i<=10;i++){
//             cout<<num[i]<<" ";
//         }
//         cout<<endl<<endl;