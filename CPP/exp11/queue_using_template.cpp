#include<iostream>
#include<vector>
using namespace std;
template <typename T>
class queue{
    public:
        vector<T>data;

        void enque(const T& data){
            this->data.push_back(data);
            cout<<data<<" is enqueued"<<endl;
        }

        void deque(){
            data.erase(data.begin());
        }

        T top(){
            if(!data.empty()){
                return data.front();
            } else {
                cout<<"Queue is empty"<<endl;
                return T();
            }
        }

        void display(){
            if(data.empty()){
                cout<<"Queue is empty"<<endl;
                return;
            }
            cout<<"Elements in Queue are : ";
            for(const T& val : data){
                cout<<val<<" ";
            }
            cout<<endl;
        }
};


int main(){
    int choice=1,type;
    queue<int>intqueue;
    queue<float>floatqueue;
    queue<double>doublequeue;
    queue<string>stringqueue;
    cout<<"WHich type of numbers you have :\n1 : int\n2 Float\n3 : Double\n4 : Strings\nYour choice : ";
    cin>>type;
    if(type==1){
        while(choice){
            cout<<"Enter your choice:\n1 : enque\n2 : deque\n3 : Top\n4 : Display\n0 : Exit\nYour choice : ";
            cin>>choice;
            if(choice==1){
                int data;
                cout<<"Enter data : ";
                cin>>data;
                intqueue.enque(data);
            } else if(choice==2){
                intqueue.deque();
            } else if(choice==3){
                int topmost=intqueue.top();
                cout<<topmost<<" is at the top"<<endl;
            } else if(choice==4){
                intqueue.display();
            }
        }
    } else if(type==2){
        while(choice){
            cout<<"Enter your choice:\n1 : enque\n2 : deque\n3 : Top\n4 : Display\n0 : Exit\nYour choice : ";
            cin>>choice;
            if(choice==1){
                float data;
                cout<<"Enter data : ";
                cin>>data;
                floatqueue.enque(data);
            } else if(choice==2){
                floatqueue.deque();
            } else if(choice==3){
                float topmost=floatqueue.top();
                cout<<topmost<<" is at the top"<<endl;
            } else if(choice==4){
                floatqueue.display();
            }
        }
    }   else if(type==3){
        while(choice){
            cout<<"Enter your choice:\n1 : enque\n2 : deque\n3 : Top\n4 : Display\n0 : Exit\nYour choice : ";
            cin>>choice;
            if(choice==1){
                double data;
                cout<<"Enter data : ";
                cin>>data;
                doublequeue.enque(data);
            } else if(choice==2){
                doublequeue.deque();
            } else if(choice==3){
                double topmost=doublequeue.top();
                cout<<topmost<<" is at the top"<<endl;
            } else if(choice==4){
                doublequeue.display();
            }
        }
    }   else if(type==4){
        while(choice){
            cout<<"Enter your choice:\n1 : enque\n2 : deque\n3 : Top\n4 : Display\n0 : Exit\nYour choice : ";
            cin>>choice;
            if(choice==1){
                string data;
                cout<<"Enter data : ";
                cin>>data;
                stringqueue.enque(data);
            } else if(choice==2){
                stringqueue.deque();
            } else if(choice==3){
                string topmost=stringqueue.top();
                cout<<topmost<<" is at the top"<<endl;
            } else if(choice==4){
                stringqueue.display();
            }
        }
    }
}


// WHich type of numbers you have :
// 1 : int
// 2 Float
// 3 : Double
// 4 : Strings
// Your choice : 1
// Enter your choice:
// 1 : enque
// 2 : deque
// 3 : Top
// 4 : Display
// 0 : Exit
// Your choice : 1
// Enter data : 1
// 1 is enqueued
// Enter your choice:
// 1 : enque
// 2 : deque
// 3 : Top
// 4 : Display
// 0 : Exit
// Your choice : 1
// Enter data : 2
// 2 is enqueued
// Enter your choice:
// 1 : enque
// 2 : deque
// 3 : Top
// 4 : Display
// 0 : Exit
// Your choice : 1
// Enter data : 3
// 3 is enqueued
// Enter your choice:
// 1 : enque
// 2 : deque
// 3 : Top
// 4 : Display
// 0 : Exit
// Your choice : 3
// 1 is at the top
// Enter your choice:
// 1 : enque
// 2 : deque
// 3 : Top
// 4 : Display
// 0 : Exit
// Your choice : 2
// Enter your choice:
// 1 : enque
// 2 : deque
// 3 : Top
// 4 : Display
// 0 : Exit
// Your choice : 3
// 2 is at the top
// Enter your choice:
// 1 : enque
// 2 : deque
// 3 : Top
// 4 : Display
// 0 : Exit
// Your choice : 4
// Elements in Queue are : 2 3 
// Enter your choice:
// 1 : enque
// 2 : deque
// 3 : Top
// 4 : Display
// 0 : Exit