#include<iostream>
#include<vector>
using namespace std;
template <typename T>
class stack{
    public:
        vector<T>data;

        void push(const T& data){
            this->data.push_back(data);
            cout<<data<<" is pushed"<<endl;
        }

        void pop(){
            this->data.pop_back();
        }

        T top(){
            if(!data.empty()){
                return data.back();
            } else {
                cout<<"Stack is empty"<<endl;
                return T();
            }
        }

        void display(){
            if(data.empty()){
                cout<<"Stack is empty"<<endl;
                return;
            }
            cout<<"Elements in stack are : ";
            for(const T& val : data){
                cout<<val<<" ";
            }
            cout<<endl;
        }
};


int main(){
    int choice=1,type;
    stack<int>intStack;
    stack<float>floatStack;
    stack<double>doubleStack;
    stack<string>stringStack;
    cout<<"WHich type of numbers you have :\n1 : int\n2 Float\n3 : Double\n4 : Strings\nYour choice : ";
    cin>>type;
    if(type==1){
        while(choice){
            cout<<"Enter your choice:\n1 : Push\n2 : Pop\n3 : Top\n4 : Display\n Exit\nYour choice : ";
            cin>>choice;
            if(choice==1){
                int data;
                cout<<"Enter data : ";
                cin>>data;
                intStack.push(data);
            } else if(choice==2){
                intStack.pop();
            } else if(choice==3){
                int topmost=intStack.top();
                cout<<topmost<<" is at the top"<<endl;
            } else if(choice==4){
                intStack.display();
            }
        }
    } else if(type==2){
        while(choice){
            cout<<"Enter your choice:\n1 : Push\n2 : Pop\n3 : Top\n4 : Display\n Exit\nYour choice : ";
            cin>>choice;
            if(choice==1){
                float data;
                cout<<"Enter data : ";
                cin>>data;
                floatStack.push(data);
            } else if(choice==2){
                floatStack.pop();
            } else if(choice==3){
                float topmost=floatStack.top();
                cout<<topmost<<" is at the top"<<endl;
            } else if(choice==4){
                floatStack.display();
            }
        }
    }   else if(type==3){
        while(choice){
            cout<<"Enter your choice:\n1 : Push\n2 : Pop\n3 : Top\n4 : Display\n Exit\nYour choice : ";
            cin>>choice;
            if(choice==1){
                double data;
                cout<<"Enter data : ";
                cin>>data;
                doubleStack.push(data);
            } else if(choice==2){
                doubleStack.pop();
            } else if(choice==3){
                double topmost=doubleStack.top();
                cout<<topmost<<" is at the top"<<endl;
            } else if(choice==4){
                doubleStack.display();
            }
        }
    }   else if(type==4){
        while(choice){
            cout<<"Enter your choice:\n1 : Push\n2 : Pop\n3 : Top\n4 : Display\n Exit\nYour choice : ";
            cin>>choice;
            if(choice==1){
                string data;
                cout<<"Enter data : ";
                cin>>data;
                stringStack.push(data);
            } else if(choice==2){
                stringStack.pop();
            } else if(choice==3){
                string topmost=stringStack.top();
                cout<<topmost<<" is at the top"<<endl;
            } else if(choice==4){
                stringStack.display();
            }
        }
    }
}


// WHich type of numbers you have :
// 1 : int
// 2 Float
// 3 : Double
// 4 : Strings
// Your choice : 4
// Enter your choice:
// 1 : Push
// 2 : Pop
// 3 : Top
// 4 : Display
//  Exit
// Your choice : 1
// Enter data : first
// first is pushed
// Enter your choice:
// 1 : Push
// 2 : Pop
// 3 : Top
// 4 : Display
//  Exit
// Your choice : 1
// Enter data : second_line
// second_line is pushed
// Enter your choice:
// 1 : Push
// 2 : Pop
// 3 : Top
// 4 : Display
//  Exit
// Your choice : 4
// Elements in stack are : first second_line 
// Enter your choice:
// 1 : Push
// 2 : Pop
// 3 : Top
// 4 : Display
//  Exit
// Your choice : 3
// second_line is at the top
// Enter your choice:
// 1 : Push
// 2 : Pop
// 3 : Top
// 4 : Display
//  Exit
// Your choice : 2
// Enter your choice:
// 1 : Push
// 2 : Pop
// 3 : Top
// 4 : Display
//  Exit
// Your choice : 3
// first is at the top
// Enter your choice:
// 1 : Push
// 2 : Pop
// 3 : Top
// 4 : Display
//  Exit
// Your choice : 4
// Elements in stack are : first 