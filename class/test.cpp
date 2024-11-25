// #include<iostream>
// #include<vector>

// using namespace std;
// class c1{
//     public:
//         string c1_name;
//         c1(){}
//         c1(string name):c1_name(name){}
// };

// class c2: public c1{
//     public:
//         string c2_name;
//         c2(string name):c2_name(name){}
//         c2(){}
// };

// c1& address_sender(c1& one_class){    
//     return one_class;
// }
// int main(){
//     // c1 obj1("obj1");
//     // c2 obj2("obj2");
//     // c1* ptr=&obj2;
//     // ptr->c1_name="changing name of obj1";
//     // cout<<obj2.c1_name<<endl;
//     // cout<<ptr->c1_name<<endl;
//     c1 obj1("obj1");
//     c1 obj2("obj2");

//     c1 &ref=address_sender(obj1);
//     c1* ptr1=&ref;
//     cout<<"ptr1 pointnig at : "<<ptr1->c1_name<<endl;
//     ref=address_sender(obj2);
//     c1*ptr2=&ref;
//     cout<<"ptr2 pointnig at : "<<ptr2->c1_name<<endl;
//         c1(){}
//         vector<int>num1;
//         vector<int>num2;
//         c1(string name,int num){
//             string temp;
//             if(name=="obj1"){
//                 temp="num1";
//             } else if(name=="obj2") temp="num2";

//             temp.push_back(num);

//             cout<<temp<<" : ";
//             for(int i=0;i<num1.size();i++)cout<<temp[i]<<" ";
//             cout<<endl;

//             cout<<"num1 : ";
//             for(int i=0;i<num1.size();i++)cout<<num1[i]<<" ";
//             cout<<endl;

//             cout<<"num2 : ";
//             for(int i=0;i<num2.size();i++)cout<<num2[i]<<" ";
//             cout<<endl;
//         }
//         void print(){
//             static int i=0;
//             cout<<i<<endl;
//             i++;
//         }
// };


// int main(){
//     c1* ptr1,*ptr2;
//     c1 obj1;
//     c1* obj2=new c1();
//     ptr1=&obj1;
//     ptr2=obj2;

//     delete ptr1;
//     delete ptr2;
// }