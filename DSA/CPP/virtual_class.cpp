#include<iostream>
using namespace std;
class person{
    public:
        void print(){
            cout<<"I am print fucntion of class 'person'"<<endl;
        }
};
class father : public virtual person{
    public:
        father(){
            cout<<"Father constructor"<<endl;
        }
};
class mother: public virtual person{
    public:
        mother(){
            cout<<"Mother constructor"<<endl;
        }
};
class child: public father,public mother{
    public:
        child(){
            cout<<"Constructor of child"<<endl;
        }
};
int main(){
    child c;
    c.print();
}