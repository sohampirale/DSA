#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        int data,height;
        node*left,*right,*next;
        node(int data){
            this->data=data;
            this->left=nullptr;
            this->right=nullptr;
            this->next=nullptr;
            this->height=0;
        }
        ~node(){
            cout<<"Deleting "<<this->data<<endl;
        }
};

class BFS{
    public:
        void printBFS(vector<node*>&loc){
            if(loc.empty()){
                // cout<<"Returnign because loc vector is empty"<<endl;
                return;
            }
            vector<node*>newloc;
            for(auto it : loc){
                cout<<it->data<<" ";
                addAddr(it,newloc);
            }
            cout<<endl;
            printBFS(newloc);
        }

        void printBFSUsingQueue(queue<node*>&loc){
            if(loc.empty()){
                // cout<<"Returnign because loc vector is empty"<<endl;
                return;
            }
            int size=loc.size();
            auto it=loc.front();
            for(int i=0;i<size;i++){
                it=loc.front();
                addAddrInQueue(it,loc);
                cout<<it->data<<" ";
                loc.pop();
            }
            cout<<endl;
            printBFSUsingQueue(loc);
        }

         void printBFSUsingQueueWhileLoop(queue<node*>&loc){
            if(loc.empty()){
                // cout<<"Returnign because loc vector is empty"<<endl;
                return;
            }
            int size=loc.size(),cnt=0;
            auto it=loc.front();
            while(!loc.empty()){
                it=loc.front();
                cout<<it->data<<" ";
                addAddrInQueue(it,loc);
                loc.pop();
                cnt++;
                if(cnt==size){
                    cout<<endl;
                    cnt=0;
                    size=loc.size();
                }
            }
        }

        void addAddrInQueue(node*& one_node,queue<node*>&loc){
            if(one_node->left){
                loc.push(one_node->left);
            }
            if(one_node->right){
                loc.push(one_node->right);
            }
        }

        void addAddr(node*&one_node,vector<node*>&newloc){
            if(one_node){
                if(one_node->left){
                    newloc.push_back(one_node->left);
                    // cout<<"Pushed "<<newloc.back()->data<<" into newloc vector"<<endl;    
                } 
                // else cout<<"Left side is null from "<<one_node->data<<" so not pushing it"<<endl;
                if(one_node->right){
                    newloc.push_back(one_node->right);
                    // cout<<"Pushed "<<newloc.back()->data<<" into newloc vector"<<endl;    
                } 
                // else cout<<"Right side is null from "<<one_node->data<<" so not pushing it"<<endl;
            } else {
                // cout<<"Pointing at nullptr so not pushing anything"<<endl;
            }
        }

        void findSumAtEveryLevel(vector<node*>&loc,vector<int>&SumAtEveryLevel){
            if(loc.empty()){
                // cout<<"Returnign because loc vector is empty"<<endl;
                return;
            }
            vector<node*>newloc;
            int sum=0;
            for(auto it : loc){
                sum+=it->data;
                addAddr(it,newloc);
            }
            SumAtEveryLevel.push_back(sum);
            findSumAtEveryLevel(newloc,SumAtEveryLevel);
        }

        void clearQueue(queue<node*>&loc){
            while(!loc.empty()){
                loc.pop();
            }
        }

        void findSumAtEveryLevelUsingQueue(queue<node*>&loc,vector<int>&SumAtEveryLevel){
            if(loc.empty()){
                // cout<<"Returnign because loc vector is empty"<<endl;
                return;
            }
            int size=loc.size(),sum=0;
            auto it=loc.front();
            for(int i=0;i<size;i++){
                it=loc.front();
                addAddrInQueue(it,loc);
                sum+=it->data;
                loc.pop();
            }
            SumAtEveryLevel.push_back(sum);
            printBFSUsingQueue(loc);
        }

        void levelOrderTraversal(queue<node*>&loc,vector<vector<int>>&answer){
            if(loc.empty()){
                return;
            }
            int size=loc.size();
            auto it=loc.front();
            vector<int>level;
            for(int i=0;i<size;i++){
                it=loc.front();
                addAddrInQueue(it,loc);
                level.push_back(it->data);
                loc.pop();
            }
            answer.push_back(level);
            levelOrderTraversal(loc,answer);
        }

        void levelOrderTraversalReverse(queue<node*>&loc,vector<vector<int>>&answer){
            if(loc.empty()){
                return;
            }
            int size=loc.size();
            auto it=loc.front();
            vector<int>level;
            for(int i=0;i<size;i++){
                it=loc.front();
                addAddrInQueue(it,loc);
                level.push_back(it->data);
                loc.pop();
            }
            answer.insert(answer.begin(),level);
            levelOrderTraversalReverse(loc,answer);
        }

        void avgOfLevels637(queue<node*>&loc,vector<float>&answer){
            if(loc.empty()){
                return;
            }
            int size=loc.size();
            float sum=0;
            auto it=loc.front();
            for(int i=0;i<size;i++){
                it=loc.front();
                addAddrInQueue(it,loc);
                sum+=it->data;
                loc.pop();
            }
            answer.push_back(sum/size);
            printBFSUsingQueue(loc);
        }

        node* findRightNextNode(queue<node*>&loc,int find){
            if(loc.empty()){
                return nullptr;
            }
            int size=loc.size();
            auto it=loc.front();
            for(int i=0;i<size;i++){
                it=loc.front();
                addAddrInQueue(it,loc);
                cout<<"checkign for "<<it->data<<endl;
                if(it->data==find){
                    loc.pop();
                    return loc.front();
                }
                loc.pop();
            }
            return findRightNextNode(loc,find);
        }

        node* findRightNextNode2(queue<node*>&loc,int find){
                if(loc.empty()){
                    return nullptr;
                }
               
        }

        vector<int> helper_ZigZagTraversal103(stack<node*>&loc,stack<node*>&newLoc,bool takeFromLeft){
            cout<<"hi"<<endl;
            vector<int>LevelAns;
            while(!loc.empty()){
                auto it=loc.top();
                if(takeFromLeft){
                    if(it->left){
                        LevelAns.push_back(it->left->data);
                        newLoc.push(it->left);
                    }
                    if(it->right){
                            LevelAns.push_back(it->right->data);
                            newLoc.push(it->right);
                    }
                } else {
                    if(it->right){
                            LevelAns.push_back(it->right->data);
                            newLoc.push(it->right);
                    }
                    if(it->left){
                        LevelAns.push_back(it->left->data);
                        newLoc.push(it->left);
                    }
                }
                loc.pop();
            }
            cout<<"LevelAns : ";
            for(int i : LevelAns)cout<<i<<" ";
            cout<<endl;
            return LevelAns;
        }

        vector<vector<int>> ZigZagTraversal103(stack<node*>&loc,vector<vector<int>>&answer,bool takeFromLeft){
                cout<<"hey"<<endl;
                if(loc.empty())return answer;
                stack<node*>newLoc;
                vector<int>LevelAns=helper_ZigZagTraversal103(loc,newLoc,takeFromLeft);
                answer.push_back(LevelAns);
                return ZigZagTraversal103(newLoc,answer,!takeFromLeft);
        }

        void addAddr_ZigZagTraversal(node*&one_node,queue<node*>&loc){
            if(one_node->left)loc.push(one_node->left);
            if(one_node->right)loc.push(one_node->right);
        }

        vector<vector<int>> ZigZagTraversal103_withQueue(queue<node*>&loc,vector<vector<int>>&answer,bool doReverse=false){
            cout<<"hi"<<endl;
            while(!loc.empty()){
                cout<<"hey"<<endl;
                vector<int>LevelAns;
                int size=loc.size();
                auto it=loc.front();
                for(int i=0;i<size;i++){
                    it=loc.front();
                    LevelAns.push_back(it->data);
                    addAddr_ZigZagTraversal(it,loc);
                    loc.pop();
                }
                if(doReverse){
                    reverse(LevelAns.begin(),LevelAns.end());
                }
                if(!LevelAns.empty()){
                    answer.push_back(LevelAns);
                }
                doReverse=!doReverse;
            }
            return answer;
        }

        void addAddre_ZigZagTraversalUsingDeque(node*&one_node,deque<node*>&loc,bool pushBack){
            if(pushBack){
                if(one_node->left)loc.push_back(one_node->left);
                if(one_node->right)loc.push_back(one_node->right);
            } else {
                if(one_node->right)loc.push_front(one_node->right);
                if(one_node->left)loc.push_front(one_node->left);
            }
        }
        
        vector<vector<int>> ZigZagTraversal103_withDeque(deque<node*>&loc,vector<vector<int>>&answer,bool pushBack=true){
            auto it=loc.front();
            while(!loc.empty()){
                int size=loc.size();
                vector<int>LevelAns;
                for(int i=0;i<size;i++){
                    if(pushBack)it=loc.front();
                    else it=loc.back();
                    LevelAns.push_back(it->data);
                    addAddre_ZigZagTraversalUsingDeque(it,loc,pushBack);
                    if(pushBack)loc.pop_front();
                    else loc.pop_back();
                }
                if(!LevelAns.empty())answer.push_back(LevelAns);
                pushBack=!pushBack;
            }
            return answer;
        }

        void populatingNextRightPointersInEachNode116(queue<node*>&loc){
            if(loc.empty())return;
            node*root=loc.front();
            while(!loc.empty()){
                int size=loc.size();
                auto it=loc.front();
                for(int i=0;i<size;i++){
                    it=loc.front();
                    loc.pop();
                    addAddrInQueue(it,loc);
                    if(i==size-1){
                        it->next=nullptr;
                    } else {
                        it->next=loc.front();
                    }
                }
            }
            // printNext(root);
        }

        void printNext(node*&one_node){
            if(!one_node)return;
            printNext(one_node->left);
            printNext(one_node->right);
            cout<<one_node->data<<"'s next -> ";
            if(one_node->next)cout<<one_node->next->data<<endl;
            else cout<<"nullptr"<<endl;
        }

        void goRight(node*t1,node*t2){
            if(!t1){
                cout<<"Retunring from goRight because t1 it nullptr"<<endl;
                return;
            } else if(!t2){
                cout<<"Retunring from goRight because t2 it nullptr"<<endl;
                return;
            }
            t1->next=t2->left;
            cout<<"Caling go left on "<<t1->data<<endl;
            goLeft(t1,t1);
            cout<<"Caling go left on "<<t2->data<<endl;
            goLeft(t2,t2);
        }

        void goLeft(node*t1,node*t2){
            if(t1==nullptr)return;
            if(t1!=t2)t1->next=t2->right;
            goLeft(t1->left,t1);
            cout<<"Calling goRIght from t1: "<<t1->data<<" & t2 : "<<t2->data<<endl;
            goRight(t1->next,t2->next);
        }

        void try2_populatingNextRightPointersInEachNode116(node*&root){
            //time limit exceeded 
            goLeft(root,root);
        }

        void try3_populatingNextRightPointersInEachNode116(node*&root){
            node*t2=root,*t1=root;
            while(t2->left){
                t1=t2;
                while(t1){
                    t1->left->next=t1->right;
                    if(t1->next){
                        t1->right->next=t1->next->left;
                    }
                    t1=t1->next;
                }
                t2=t2->left;
            }
            cout<<"Connected next node of every node"<<endl;
            printNext(root);
        }


};

void addNextAdd(node*& one_node,queue<node*>&loc){
    if(!one_node)return;
    loc.push(one_node->left);
    loc.push(one_node->right);
    cout<<"Pushed left right of "<<one_node->data<<endl;
}

void createNormalTree(queue<node*>&loc,int data){
    node*& one_node=loc.front();
    one_node=new node(data);
    addNextAdd(one_node,loc);
    loc.pop();
}

void printHeights(node*&one_node){
    if(!one_node)return;
    printHeights(one_node->left);
    printHeights(one_node->right);
    cout<<"Height of "<<one_node->data<<" : "<<one_node->height<<endl;
}

void preetyDisplayRight(node*&one_node,int level=0){
    if(!one_node)return;
    if(one_node->right)preetyDisplayRight(one_node->right,level+1);
    if(level!=0){
        for(int i=0;i<level-1;i++)cout<<"|\t";
        cout<<"|----->"<<one_node->data<<endl;
    } else cout<<one_node->data<<endl;
    if(one_node->left)preetyDisplayRight(one_node->left,level+1);
}

int getHeight(node*&one_node){
    if(!one_node)return 0;
    return one_node->height;
}

void setHeight(node*& one_node){
    cout<<"Height of "<<one_node->data<<" is changed from "<<one_node->height;
    one_node->height=max(getHeight(one_node->left),getHeight(one_node->right))+1;
    cout<<" to "<<one_node->height<<endl;
}

node* rightShift(node*one_node,node*&root){
    // cout<<"Doing right shift around "<<one_node->data<<endl;
    node* temp=(one_node->left);
    // cout<<"one_node : "<<one_node->data<<" & temp : "<<temp->data<<endl;
    // if(root==one_node){
    //     cout<<"root before : "<<root->data<<endl;
    //     root=temp;
    //     cout<<"Changing root to "<<root->data<<endl;
    // }
    one_node->left=temp->right;
    temp->right=one_node;
    setHeight(one_node);
    setHeight(temp);
    return temp;
}

node* leftShift(node*one_node,node*&root){
    // cout<<"Doing leftShift around "<<one_node->data<<endl;
    node*temp=(one_node->right);
    // cout<<"one_node : "<<one_node->data<<" & temp : "<<temp->data<<endl;
    // if(root==one_node){
    //     root=temp;
    //     cout<<"Changing root to "<<root->data<<endl;
    // }
    one_node->right=temp->left;
    temp->left=one_node;
    setHeight(one_node);
    setHeight(temp);
    return temp;
}

node* rotate(node*&one_node,node*&root){
    int righth=getHeight(one_node->right);
    int lefth=getHeight(one_node->left);
    // if(righth==-1)righth=0;
    // if(lefth==-1)lefth=0;
    if((righth-lefth)>1){
        if(getHeight(one_node->right->left) >getHeight(one_node->right->right)){
            cout<<"right left case"<<endl;
            one_node->right=rightShift(one_node->right,root);
            preetyDisplayRight(root);
            return leftShift(one_node,root);
        } else {
            cout<<"Right right case"<<endl;
            return leftShift(one_node,root);
        }
    } else if((lefth-righth) >1){
        if(getHeight(one_node->left->left) >getHeight(one_node->left->right)){
            cout<<"left left case"<<endl;
            return rightShift(one_node,root);
        } else {
            cout<<"left right case"<<endl;
            one_node->left=leftShift(one_node->left,root);
            preetyDisplayRight(root);
            return rightShift(one_node,root);
        }
    }
    // cout<<"No need to rotate for "<<one_node->data<<endl;
    return one_node;
}

node* add(node*one_node,node*&root,int data){
    if(!one_node){
        cout<<"Node "<<data<<" added"<<endl;
        return new node(data);
    }

    if(data<=one_node->data){
        one_node->left=add(one_node->left,root,data);
        // cout<<one_node->data<<" received left as : "<<one_node->left->data<<endl;
    }

    if(data>one_node->data){
        one_node->right=add(one_node->right,root,data);
        // cout<<one_node->data<<" received right as : "<<one_node->right->data<<endl;

    }
    // node*temp=one_node;
    // one_node=rotate(one_node,root);
    // cout<<"Rotate funciton gave one_node = "<<one_node->data<<" but original call was made from"<<temp->data<<endl;
    one_node->height=max(getHeight(one_node->right),getHeight(one_node->left))+1;
    return one_node;
}

void delete_nodes(node*&one_node){
    if(!one_node)return;
    delete_nodes(one_node->left);
    delete_nodes(one_node->right);
    delete one_node;
}

int getchoice(){
    int choice;
    cout<<"1 : Add node\n";
    cout<<"2 : Display\n";
    cout<<"3 : Print heights\n";
    cout<<"4 : Print BFS\n";
    cout<<"5 : Print BFS using Queue\n";
    cout<<"6 : Find sum at every level\n";
    cout<<"7 : Find rigth next to right node"<<endl;
    cout<<"8 : Print BFS using Queue using While loop"<<endl;
    cout<<"9 : Binary ZigZag level order traversal"<<endl;
    cout<<"10 : Get BFS in reverse level order"<<endl;
    cout<<"11 : Modify each node to point at right next node to it"<<endl;
    cout<<"12 : Modify each node to point at right next node to it  (Using Pointers)"<<endl;
    cout<<"13 : Modify each node to point at right next node to it (116) (Using Pointers)"<<endl;
    cout<<"20 : isSymmetric"<<endl;
    cout<<"Your choice : ";
    cin>>choice;
    return choice;
}


int main(){
    int choice=1,data;
    node*root=nullptr;
    BFS bfs;
    queue<node*>loc;
    try{
        while(choice){
            choice=getchoice();
            if(choice==1){
                cout<<"Enter data : ";
                cin>>data;
                
                // if(!root){
                //     root=new node(0);
                //     loc.push(root);
                // }
                if(loc.empty())loc.push(root);
                createNormalTree(loc,data);

                // try{
                //     if(!root)root=new node(data);
                //     else root=add(root,root,data);
                //     cout<<"Root pointing at : "<<root->data<<endl;
                // } catch(...){
                //     cout<<"Error occured"<<endl;
                // }
            } else if(choice==2){
                if(!root){
                    cout<<"Tree is empty"<<endl;
                    continue;    
                }
                try{
                    preetyDisplayRight(root);
                } catch(...){
                    cout<<"Error occured"<<endl;
                }
            } else if(choice==3){
                printHeights(root);
            }else if(choice==4){
                vector<node*>loc={root};
                bfs.printBFS(loc);
            } else if(choice==5){
                bfs.clearQueue(loc);
                loc.push(root);
                bfs.printBFSUsingQueue(loc);
            }else if(choice==6){
                vector<node*>loc={root};
                vector<int>SumAtEveryLevel;
                bfs.findSumAtEveryLevel(loc,SumAtEveryLevel);
                cout<<"Sums at every level are : ";
                for(int i : SumAtEveryLevel)cout<<i<<" ";
                cout<<endl;
            }
            else if(choice==7){
                int find;
                bfs.clearQueue(loc);
                loc.push(root);
                cout<<"ENter the data to find rigth next node from : ";
                cin>>find;
                node* answer=bfs.findRightNextNode(loc,find);
                if(answer)cout<<"Answer received : "<<answer->data<<endl;
                else cout<<"node with data "<<find<<" not found"<<endl;
            }    
            else if(choice==8){
                bfs.clearQueue(loc);
                loc.push(root);
                bfs.printBFSUsingQueueWhileLoop(loc);
            }
            else if(choice==9){
                vector<vector<int>>answer;
             
                int methodChoice;
                cout<<"WHich method to use\n1 : Using stack\n2 : USing queue3 : Using Dequeue\nYour choice : ";
                cin>>methodChoice;
                if(methodChoice==1){
                    vector<int>temp;
                    temp.push_back(root->data);
                    answer.push_back(temp);
                    stack<node*>loc;
                    loc.push(root);
                    answer=bfs.ZigZagTraversal103(loc,answer,false);
                } else if(methodChoice==2){
                    queue<node*>loc;
                    loc.push(root);
                    answer=bfs.ZigZagTraversal103_withQueue(loc,answer,false);
                } else if(methodChoice==3){
                    deque<node*>loc;
                    loc.push_back(root);
                    answer=bfs.ZigZagTraversal103_withDeque(loc,answer,true);
                }
                cout<<"Answer receievd from ZigZag traversal is : "<<endl;
                for(int i=0;i<answer.size();i++){
                    for(int j=0;j<answer[i].size();j++){
                        cout<<answer[i][j]<<" ";
                    }
                    cout<<endl;
                }
            }
            else if(choice==10){
                bfs.clearQueue(loc);
                loc.push(root);
                vector<vector<int>>answer;
                bfs.levelOrderTraversalReverse(loc,answer);
                cout<<"Answer receievd from levelOrderTraversalReverse is : "<<endl;
                for(int i=0;i<answer.size();i++){
                    for(int j=0;j<answer[i].size();j++){
                        cout<<answer[i][j]<<" ";
                    }
                    cout<<endl;
                }
            }
            else if(choice==11){
                bfs.clearQueue(loc);
                loc.push(root);
                bfs.populatingNextRightPointersInEachNode116(loc);
            }
            else if(choice==12){
                bfs.try2_populatingNextRightPointersInEachNode116(root);
                bfs.printNext(root);
            } else if(choice==13){
                bfs.try3_populatingNextRightPointersInEachNode116(root);
            }
            else if(choice==20){
                bool ans=bfs.isSymmetric(root);
                if(ans)cout<<"Symmetric"<<endl;
                else cout<<"Not symmetric"<<endl;
            }
        }

    } catch(...){
        cout<<"Error occured"<<endl;
    }
    cout<<"Came out"<<endl;
   delete_nodes(root);
}    



   
    // root=new node(1);
    // int n;
    // cout<<"Enter how many numbers you want to insert : ";
    // cin>>n;
    // for(int i=0;i<n;i++)root=add(root,root,i);
    // cout<<"Added "<<n<<endl;
    // sleep(2);
    // for(int i=-1;i>-n;i--)root=add(root,root,i);

    // preetyDisplayRight(root);
    // cout<<"HEight of the tree with "<<n<<" nodes is : "<<root->height<<endl;
    // return 0;