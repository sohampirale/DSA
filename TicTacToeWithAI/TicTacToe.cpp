#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        char mark=' ';
        node* up,*down,*right,*left,*ru,*rd,*lu,*ld;
        node(char mark=' '):mark(mark){}
        
        void connect(node* up,node* down,node* right,node* left,node* ru,node* rd,node* lu,node* ld){
            this->up=up;
            this->down=down;
            this->right=right;
            this->left=left;
            this->ru=ru;
            this->rd=rd;
            this->lu=lu;
            this->ld=ld;
        }

        ~node(){
            cout<<"deleting "<<mark<<endl;
        }
};

class PairHash {
public:
    std::size_t operator()(const std::pair<int, int>& p) const {
        // Combine the hashes of the two integers
        return std::hash<int>{}(p.first) ^ (std::hash<int>{}(p.second) << 1);
    }
};

unordered_map<pair<int,int>,node*,PairHash> createBoard(){
    unordered_map<pair<int,int>,node*,PairHash>board;
    board[{1,1}]=new node;
    return board;
}

int main(){
    auto board=createBoard();
    if(board.find({1,1})!=board.end()){
        cout<<"Present int he copy made"<<endl;
        delete board[{1,1}];
    }
    // while(1){

    // }

    return 0;
}
