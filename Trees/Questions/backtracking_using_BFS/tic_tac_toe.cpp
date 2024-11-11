#include<iostream>
#include<vector>
using namespace std;
void display(vector<char>&board){
    for(int i=1;i<10;i++){
        cout<<"|"<<board[i]<<" ";
        if(i%3==0)cout<<"|"<<endl;
    }
}
int main(){
    vector<char>board(10,' ');
    display(board);
    string name;
    int move;
    cout<<"Enter your name : ";
    cin>>name;
    while(1){
        cout<<name<<" Enter your move : ";
        cin>>move;
        if(board[move]==0)board[move]='X';
        else {
            cout<<"Invalid enter again..."<<endl;
            continue;
        }
    }
}