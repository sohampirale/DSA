#include<iostream>
#include<vector>
using namespace std;
class c1{
    public:
        string c1_name;
        c1(){
            this->c1_name="c1_name";
        }
};

class c2:public c1{
    public:
        string c2_name;
        c2(){
            this->c2_name="c2_name";
            this->c1_name="default";
        }
};
int main(){
    vector<c1>temp1;
    vector<c2>temp2;

    c1 obj1;
    c2 obj2;
    
    temp2.push_back(obj1);
    temp2.push_back(obj2);

    cout<<"Both pushed suceessfully"<<endl;
}