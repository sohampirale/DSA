#include<iostream>
#include<vector>

using namespace std;
class c1{
    public:
        c1(){}
        vector<int>num1;
        vector<int>num2;
        c1(string name,int num){
            string temp;
            if(name=="obj1"){
                temp="num1";
            } else if(name=="obj2") temp="num2";

            temp.push_back(num);

            cout<<temp<<" : ";
            for(int i=0;i<num1.size();i++)cout<<temp[i]<<" ";
            cout<<endl;

            cout<<"num1 : ";
            for(int i=0;i<num1.size();i++)cout<<num1[i]<<" ";
            cout<<endl;

            cout<<"num2 : ";
            for(int i=0;i<num2.size();i++)cout<<num2[i]<<" ";
            cout<<endl;
        }
        void print(){
            static int i=0;
            cout<<i<<endl;
            i++;
        }
};


int main(){
    c1* ptr1,*ptr2;
    c1 obj1;
    c1* obj2=new c1();
    ptr1=&obj1;
    ptr2=obj2;

    delete ptr1;
    delete ptr2;
}