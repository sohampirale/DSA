#include <iostream>
#include<unordered_map>
#include <unistd.h>
using namespace std;
class node{
    public:
        char data;
        node(char data):data(data){}
};

void createBoard(unordered_map<int,node*>&board){
    board[1]=new node(' ');
    board[2]=new node(' ');
    board[3]=new node(' ');
    board[4]=new node(' ');
    board[5]=new node(' ');
    board[6]=new node(' ');
    board[7]=new node(' ');
    board[8]=new node(' ');
    board[9]=new node(' ');
    cout<<"Board created"<<endl;
}

int horizontalCheck(unordered_map<int,node*>&board){
    bool flag=true;
    for(int i=0;i<3;i++){
        int cntX=0;
        for(int j=(i*3)+1;j<(i*3)+3;j++){
            if(board[j]->data=='O'){
                flag=false;
                break;
            }
            else if(board[j]->data=='X'){
                cntX++;
            }
        }
        if(flag&&cntX==2){
            return (i*3)+1;
        }
        flag=true;
    }
    return -1;
}

int verticalCheck(unordered_map<int,node*>&board){
    bool flag=true;
    for(int i=1;i<=3;i++){
        int cntX=0;
        for(int j=i;j<=9;j+=3){
            if(board[j]->data=='O'){
                flag=false;
                break;
            }
            else if(board[j]->data=='X'){
                cntX++;
            }
        }
        if(flag&&cntX==2)return i;
        flag=true;
    }
    return -1;
}

int diagonalCheck(unordered_map<int,node*>&board){
    int cntX=0;
    bool flag=false;
    for(int i=1;i<=9;i=i+4){
        if(board[i]->data=='O'){
            flag=true;
            break;
        }
        else if(board[i]->data=='X'){
            cntX++;  
        }
    }
    if(!flag&&cntX==2){
        return 1;
    }
    
    cntX=0;
    for(int i=3;i<=7;i=i+2){
        if(board[i]->data=='O')return -1;
        else if(board[i]->data=='X'){
                cntX++;
        }
    }
    if(cntX==2){
        return 2;
    }
    return -1;
}

void makeHorizontalMove(int row,unordered_map<int,node*>&board){
    for(int i=row;i<(row+3);i++){
        if(board[i]->data==' '){
            cout<<"AI made the move in the box no - "<<i<<endl;
            board[i]->data='O';
        }
    }
}

void makeVerticleMove(int col,unordered_map<int,node*>&board){
    for(int i=col;i<=9;i=i+3){
        if(board[i]->data==' '){
            cout<<"AI made the move in the box no - "<<i<<endl;
            board[i]->data='O';
            return;
        }
    }
}

void makeDiagonalMove(unordered_map<int,node*>&board,int diaCheck){
    if(diaCheck==1){
        for(int i=1;i<=9;i=i+4){
            if(board[i]->data==' '){
                cout<<"AI made the move in the box no - "<<i<<endl;
                board[i]->data='O';
                return;
            }
        }
    } else if(diaCheck==2){
        for(int i=3;i<=7;i=i+2){
            if(board[i]->data==' '){
                 cout<<"AI made the move in the box no - "<<i<<endl;
                board[i]->data='O';
                return;
            }
        }
    }
}

void AIMove(unordered_map<int,node*>&board){
    int horiCheck=horizontalCheck(board);
    if(horiCheck!=-1){
        cout<<"Horizontal alert"<<endl;
        makeHorizontalMove(horiCheck,board);
        return;
    }
    int vertCheck=verticalCheck(board);
    if(vertCheck!=-1){
        cout<<"vertCheck alert"<<endl;
        makeVerticleMove(vertCheck,board);
        return;
    }
    int diaCheck=diagonalCheck(board);
    cout<<"diaCheck = "<<diaCheck<<endl;
    if(diaCheck!=-1){
        cout<<"Diagonal alert"<<endl;
        makeDiagonalMove(board,diaCheck);
        return;
    }
    for(auto it=board.begin();it!=board.end();it++){
        if(it->second->data==' '){
            cout<<"AI NORMALLY made the move in the box no - "<<it->first<<endl;
            it->second->data='O';
            cout<<"At board["<<it->first<<"] = "<<board[it->first]->data<<endl;
            return;
        }
    }
    
}

void displayBoard(unordered_map<int,node*>&board){
    for(int i=0;i<3;i++){
        for(int j=1;j<=3;j++){
            cout<<board[(i*3)+j]->data<<"|";
        }
        cout<<endl;
    }
}

void deleteAllNodes(unordered_map<int,node*>&board){
    for(auto it=board.begin();it!=board.end();it++){
        delete it->second;
    }
}

int main() {
    unordered_map<int,node*>board;
    createBoard(board);
    bool turn=true;
    int move;
    int cnt=0;
    while(1){
        cnt++;
        if(cnt>=10)break;
        if(turn){
            cout<<"Enter your move (1-9) : ";
            cin>>move;
            if(board.find(move)==board.end()||board[move]->data!=' '){
                cout<<"Enter valid move"<<endl;
                continue;
            } else {
                turn=false;
                board[move]->data='X';
            }
            displayBoard(board);
            cout<<"AI will be mkaing a move in  Seconds"<<endl;
            // sleep(4);
        } else {
            AIMove(board);
            displayBoard(board);
            turn=true;
        }
    }
    deleteAllNodes(board);
    return 0;
}