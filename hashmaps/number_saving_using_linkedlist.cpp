#include<iostream>
#include<vector>
#include<list>
using namespace std;
class student{
    public:
        string name;
        int rollno;
        student(int rollno,string name):name(name),rollno(rollno){}

        student():name("Demo student"),rollno(-1){}

        ~student(){}
};

void save(vector<list<student>>&lists,string name,int rollno){
    lists[rollno%10].push_back(student(rollno,name));
}
int cnt=0;
student& retrive(vector<list<student>>&lists,int rollno){
    cnt=0;
    int index=rollno%10;
    auto it=lists[index].begin();
    auto end=lists[index].end();
    while(it!=end){
        // cout<<"Pointing at : "<<(*it).name<<endl;
        cnt++;
        if((*it).rollno==rollno){
            return *it;
        }
        it++;
    }
    static student temp;
    return temp;
}
int main(){
    vector<list<student>>lists(10);
    int choice=1,rollno;
    string name;
    while(choice){
        cout<<"Enter your choice :\n1 : Store\n2 : Retrive\nYour choice : ";
        cin>>choice;
        if(choice==1){
            cout<<"Enter rollno : ";
            cin>>rollno;
            cout<<"Enter name : ";
            cin>>name;
            save(lists,name,rollno);
        } else if(choice==2){
            cout<<"Enter rollno you want to retrive : ";
            cin>>rollno;
            student one_student=retrive(lists,rollno);
            if(one_student.rollno!=-1){
                cout<<"Data of retrived student -> Name : "<<one_student.name<<" Rollno : "<<one_student.rollno<<endl;
                cout<<"Student retrived in "<<cnt<<" tries"<<endl;
            } else{
                cout<<"Student with rollno : "<<rollno<<" not found"<<endl;
            }
        }
    }
}