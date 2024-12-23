#include<iostream>
#include<vector>
#include<memory>
using namespace std;
class test{
    public:
    int var;
    test(){
        cout<<"Object Created"<<endl;
        var=-1;
    }
    test(int var):var(var){
        cout<<"Custome constructor"<<endl;
    }
    ~test(){
        cout<<"object deleted var = "<<var<<endl;
    }
};
int main(){
    shared_ptr<test>ptr1=make_shared<test>();
    shared_ptr<test>ptr2=make_shared<test>(20);
    test* one_node=ptr2.get();
    cout<<one_node->var<<endl;
}