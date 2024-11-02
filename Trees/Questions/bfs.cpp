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
        vector<node*>extra;
        node* parent,*child,*grandchild;
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

        void addAddrIsCousins(node*&one_node,queue<node*>&loc,int x,int y,bool&found){
            if(one_node->left){
                loc.push(one_node->left);
                if(one_node->left->data==x){
                    found=true;
                    return;
                } else if(one_node->left->data==y){
                    found=true;
                    return;
                }
            } 
            if(one_node->right){
                if(one_node->right->data==x){
                    found=true;
                } else if(one_node->right->data==y){
                    found=true;
                }
                loc.push(one_node->right);
            }
        }

        bool isCousins993(queue<node*>&loc,int x,int y){
            if(loc.empty()){
                return false;
            }
            bool found=false,isCousins=false;
            while(!loc.empty()){
                int size=loc.size();
                auto it=loc.front();
                for(int i=0;i<size;i++){
                    // it=loc.front();
                    addAddrIsCousins(loc.front(),loc,x,y,found);
                    loc.pop();
                    if(found){
                        bool found2=false;
                        for(int j=i+1;j<size;j++){
                            addAddrIsCousins(loc.front(),loc,x,y,found2);
                            if(found2)return true;
                        }
                        return false;
                    }
                }
            }
            cout<<"hi"<<endl;
            return false;
        }

        void addAddrIsCousinsTry2(queue<node*>&loc,node*& one_node,int x,int y,int level,vector<int>&levels,vector<node*>&parents){
            if(!one_node)return;
            if(one_node->left){
                loc.push(one_node->left);
                if(one_node->left->data==x||one_node->left->data==y){
                    levels.push_back(level);
                    parents.push_back(one_node);
                }
            } 
            if(one_node->right){
                loc.push(one_node->right);
                if(one_node->right->data==x||one_node->right->data==y){
                    levels.push_back(level);
                    parents.push_back(one_node);
                }
            }
        }

        bool isCousins_try2(queue<node*>&loc,int x,int y){
            if(loc.front()->data==x&&loc.front()->data==y)return false;
            vector<int>levels;
            vector<node*>parents;
            int level=1;
            bool flag=false;
            while(!loc.empty()){
                int size=loc.size();
                for(int i=0;i<size;i++){
                    addAddrIsCousinsTry2(loc,loc.front(),x,y,level,levels,parents);
                    if(levels.size()==2){flag=true;break;}
                    loc.pop();
                }
                if(flag)break;
                level++;
            }
            if(levels.size()==2){
                if(levels[0]!=levels[1])return false;
                if(parents[0]==parents[1])return false;
                return true;
            } else return false;
        }
        
        void addAddrIsCousinsTry3(queue<node*>&loc,node*&one_node){
            if(!one_node)return;

            if(!one_node->left){
                one_node->left==new node(-10);
            }
            loc.push(one_node->left);

            if(!one_node->right){
                one_node->right=new node(-10);
            }
            loc.push(one_node->right);
        }
        
        bool isCousins_try3(queue<node*>&loc,int x,int y){
            if(loc.front()->data==x&&loc.front()->data==y)return false;
            bool flag=false;
            while(!loc.empty()){
                int size=loc.size();
                auto it=loc.front();
                for(int i=0;i<size;i++){
                    it=loc.front();
                    addAddrIsCousinsTry3(loc,it);
                    if(it->data==x||it->data==y){
                        if(flag)return true;
                        else {
                            i++;
                            loc.pop();
                            flag=true;
                        }
                    }
                    loc.pop();
                }
                if(flag){
                    return false;
                }
            }
            return false;
        }
        
        void addAddrIsCousinsTry4(queue<node*>&loc,node*&one_node){
            if(!one_node)return;
            if(one_node->data==-10)return;

            if(!one_node->left){
                one_node->left=new node(-10);
            }
            loc.push(one_node->left);

            if(!one_node->right){
                one_node->right=new node(-10);
            }
            loc.push(one_node->right);
            node*extra_node = new node(-10);
            loc.push(extra_node);
            extra.push_back(extra_node);
        }
        
        void delete_extra(vector<node*>&extra){
            for(int i=0;i<extra.size();i++){
                delete extra[i];
            }
        }
        
        bool isCousins_try4(queue<node*>&loc,int x,int y){
            if(loc.front()->data==x&&loc.front()->data==y){
                delete_extra(extra);
                return false;
            }
            bool flag=false;
            while(!loc.empty()){
                queue<node*>newloc;
                int size=loc.size();
                auto it=loc.front();
                while(!loc.empty()){
                    it=loc.front();
                    addAddrIsCousinsTry4(newloc,it);
                    cout<<"Checking for "<<it->data<<endl;
                    if((it->data==x||it->data==y)){
                        cout<<"found for "<<it->data<<endl;
                        if(flag){
                            delete_extra(extra);
                            return true;
                        }
                        else {
                            loc.pop();
                            loc.pop();
                            flag=true;
                            continue;
                        }
                    }
                    loc.pop();
                }
                if(flag){
                    delete_extra(extra);
                    return false;
                }
                loc=newloc;
            }
            delete_extra(extra);
            return false;
        }
        
        void addAddrIsSymmetricLeft(node*&one_node,deque<node*>&temp){
            if(!one_node)return;
            if(one_node->left){
                temp.push_front(one_node->left);
            }
            if(one_node->right){
                temp.push_front(one_node->right);
            }
        }

        void addAddrIsSymmetricRight(node*&one_node,deque<node*>&temp){
            if(!one_node)return;
            if(one_node->right){
                temp.push_back(one_node->right);
            }
            if(one_node->left){
                temp.push_back(one_node->left);
            }
        }

        bool isSymmetric(node*&root){
            if(!root->left&&!root->right){
                return true;
            } else if(!root->left||!root->right){
                return false;
            }

            deque<node*>answer,temp;
            answer.push_front(root->left);
            answer.push_back(root->right);
            while(!answer.empty()){
                int size=answer.size();
                auto left_it=answer.front(),right_it=answer.back();
                for(int i=0;i<size/2;i++){
                    left_it=answer.front();
                    right_it=answer.back();
                    if(left_it->data!=right_it->data){
                        return false;
                    }
                    addAddrIsSymmetricLeft(left_it,temp);
                    addAddrIsSymmetricRight(right_it,temp);
                    answer.pop_front();
                    answer.pop_back();
                }
                answer=temp;
                cout<<"deque is : "<<endl;
                while(!temp.empty()){
                    cout<<temp.front()->data<<" ";
                    temp.pop_front();
                }
                cout<<endl;
            }
            return true;
        }

        void rightShiftFromBFS(node*&one_node,node*&root){
            if(!one_node)return ;
            node*temp=one_node->left;
            one_node->left=temp->right;
            temp->right=one_node;
            if(one_node==parent&&parent==root)
                root=temp;
            else if(one_node==child) 
                parent->right=temp;
        }

        void leftShiftFromBFS(node*&one_node,node*&root){
            if(!one_node)return;
            node*temp=one_node->right;
            one_node->right=temp->left;
            temp->left=one_node;
            if(one_node==parent)
                root=temp;
            else 
                parent->left=temp;
        
        }

        void rotate(node*& one_node,node*&root,int left,int right){
            parent=one_node;
            bool left_child=false,left_grandchild=false;
            cout<<"Parent pointing at : "<<parent->data<<endl;
            if(left>right){
                child=one_node->left;
                left_child=true;
            }else child=one_node->right;

            int child_left=getHeight(child->left),child_right=getHeight(child->right);

            if(child_left>child_right){
                grandchild=child->left;
                left_grandchild=true;
            }
            else grandchild=child->right;

            if(left_child){
                if(left_grandchild){
                    cout<<"left left case"<<endl;
                    rightShiftFromBFS(parent,root);
                } else {
                    cout<<"left right case"<<endl;
                    leftShiftFromBFS(child,root);
                    rightShiftFromBFS(parent,root);
                }
            } else {
                if(left_grandchild){
                    cout<<"right left case"<<endl;
                    rightShiftFromBFS(child,root);
                    leftShiftFromBFS(parent,root);
                } else {
                    cout<<"right right case"<<endl;
                    leftShiftFromBFS(parent,root);
                }
            }
        }

        int setHeight(node*&one_node,node*&root){
            if(!one_node->left&&!one_node->right)return 0;
            int left=getHeight(one_node->left),right=getHeight(one_node->right);
            if(abs(right-left)>1){
                cout<<"We need to rearrange tree for "<<one_node->data<<endl;
                rotate(one_node,root,left,right);
                //after rearranging using AVL we need to check for right height and left height again
                return setHeight(one_node,root);
            }
            // if(left==0&&right==0)return 0; this cant be done because it will always keeps returning 0
            return max(left,right)+1;
        }

        void setHeightOfCreatingBSTWithReturningPtrAVL(node*&one_node){
            if(!one_node)return;
            cout<<"Setting height of "<<one_node->data<<endl;
            if(!one_node->left&&!one_node->right)one_node->height=0;
            int left=getHeight(one_node->left),right=getHeight(one_node->right);
            one_node->height=max(left,right)+1;
        }

        int getHeight(node*&one_node){
            if(!one_node)return 0;
            else return one_node->height;
        }

        void setGrandChild(node*&child){
            int left=getHeight(child->left),right=getHeight(child->right);
            if(left>right)grandchild=child->left;
            else grandchild=child->right;
        }

        node* leftShiftReturningPtr(node*&one_node){
            node*temp=one_node->right;
            one_node->right=temp->left;
            temp->left=one_node;
            return temp;
        }

        node* rightShiftReturningPtr(node*&one_node){
            node*temp=one_node->left;
            one_node->left=temp->right;
            temp->right=one_node;
            return temp;
        }
        
        node* rotateReturnPtr(node*&one_node){
            int left=getHeight(one_node->left),right=getHeight(one_node->right);
            cout<<"lefth = "<<left<<" & righth = "<<right<<endl;
            if(abs(left-right)>1){
                cout<<"tree is not balanced"<<endl;
                parent=one_node;
                if(left>right)child=parent->left;
                else child=parent->right;
                setGrandChild(child);
                cout<<"Parent : "<<parent->data<<endl;
                cout<<"Child : "<<child->data<<endl;
                cout<<"Grandchild : "<<grandchild->data<<endl;

                if(child==parent->left){

                    if(grandchild==child->left){
                        cout<<"Left left case"<<endl;
                        one_node = rightShiftReturningPtr(parent);
                    } else {
                        parent->left=leftShiftReturningPtr(child);
                        setHeightOfCreatingBSTWithReturningPtrAVL(child);
                        one_node = rightShiftReturningPtr(parent);
                    }

                } else {

                    if(grandchild==child->right){
                        cout<<"right right"<<endl;
                        one_node = leftShiftReturningPtr(parent);
                    } else {
                        parent->right = rightShiftReturningPtr(child);
                        setHeightOfCreatingBSTWithReturningPtrAVL(child);
                        one_node = leftShiftReturningPtr(parent);
                    }

                }
                setHeightOfCreatingBSTWithReturningPtrAVL(parent);
            }
            setHeightOfCreatingBSTWithReturningPtrAVL(parent);
            setHeightOfCreatingBSTWithReturningPtrAVL(grandchild);
            setHeightOfCreatingBSTWithReturningPtrAVL(child);

            return one_node;
        }

        node* createBSTWithBFSReturningPtr(stack<node*>&loc,int data){
            auto it=loc.top();
            if(data<=it->data){
                if(it->left){
                    loc.push(it->left);
                    it->left=createBSTWithBFSReturningPtr(loc,data);
                } else {
                    it->left=new node(data);
                    cout<<data<<" created"<<endl;
                    return it;
                }
            } else {
                if(it->right){
                    loc.push(it->right);
                    it->right=createBSTWithBFSReturningPtr(loc,data);
                } else {
                    it->right=new node(data);
                    cout<<data<<" created to the right of "<<it->data<<endl;
                    return it;
                }
            }
            return rotateReturnPtr(it);
        }
        
        void createBSTWithBFS(node*&root,int data){
            static int cnt=0;
            stack<node*>loc;
            loc.push(root);
            auto it=loc.top();
            while(!loc.empty()){
                it=loc.top();
                cnt++;
                if(cnt==40)break;
                if(data<it->data){
                    if(it->left){
                        cout<<"Pushing "<<it->left->data<<endl;
                        loc.push(it->left);
                        continue;
                    } else {
                        it->left=new node(data);
                        cout<<data<<" created to left of "<<it->data<<endl;
                        break;
                    }
                } else {
                    if(it->right){
                        cout<<"Pushing "<<it->right->data<<endl;
                        loc.push(it->right);
                        continue;
                    } else {
                        it->right=new node(data);
                        cout<<data<<" created to right of "<<it->data<<endl;
                        break;
                    }
                }
            }

            while(!loc.empty()){
                it=loc.top();
                cout<<"Height of "<<it->data<<" is modified from "<<it->height<<" to : ";
                it->height=setHeight(it,root);
                cout<<it->height<<endl;
                loc.pop();
            }

        }

};


void addNextAdd(node*& one_node,queue<node*>&loc){
    if(!one_node)return;
    loc.push(one_node->left);
    loc.push(one_node->right);
    cout<<"Pushed left right of "<<one_node->data<<endl;
}

void createNormalTree(queue<node*>&parent,int data){
    static int cnt=0;
    node*one_node=new node(data);
    cout<<"cnt = "<<cnt<<endl;
    if(cnt==0){
        parent.front()->left=one_node;
        cnt++;
    } else if(cnt==1){
        parent.front()->right=one_node;
        cnt=0;
        parent.pop();
    }
    parent.push(one_node);
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

void preetyDisplayRightHeights(node*&one_node,int level=0){
    if(!one_node)return;
    if(one_node->right)preetyDisplayRightHeights(one_node->right,level+1);
    if(level!=0){
        for(int i=0;i<level-1;i++)cout<<"|\t";
        cout<<"|----->"<<one_node->height<<endl;
    } else cout<<one_node->height<<endl;
    if(one_node->left)preetyDisplayRightHeights(one_node->left,level+1);
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

void create_BST(queue<node*>loc,int data){
    auto it=loc.front();
    while(1){
        cout<<"it : "<<it->data<<endl;
        if(it->data==45)break;
        it++;
    }
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
    cout<<"14 : Create BST"<<endl;
    cout<<"15 : isCoursins"<<endl;
    cout<<"16 : is symmetric"<<endl;
    cout<<"17 : Create BST with BFS"<<endl;
    cout<<"18 : Print heights using preetyDisplay"<<endl;
    cout<<"19 : create BST using returning ptr and BFS"<<endl;
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
        //
        while(choice){
            choice=getchoice();
            if(choice==1){
                cout<<"Enter data : ";
                cin>>data;

                int m=1;
                if(m==1){
                    if(!root){
                        root=new node(data);
                        loc.push(root);
                        continue;
                    }
                    createNormalTree(loc,data);
                } else if(m==2){
                    try{
                        if(!root)root=new node(data);
                        else root=add(root,root,data);
                        cout<<"Root pointing at : "<<root->data<<endl;
                    } catch(...){
                        cout<<"Error occured"<<endl;
                    }
                }  

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
            else if(choice==14){
                // create_BST()
            }
            else if(choice==15){
                int x,y;
                cout<<"Enter x : ";
                cin>>x;
                cout<<"Enter y : ";
                cin>>y;
                bfs.clearQueue(loc);
                loc.push(root);
                bool isCousins=bfs.isCousins_try4(loc,x,y);
                if(isCousins)cout<<x<<" & "<<y<<" are cousins"<<endl;
                else cout<<x<<" & "<<y<<" are not cousins"<<endl;
            }
            else if(choice==16){
                bfs.clearQueue(loc);
                bool isSymmetric=bfs.isSymmetric(root);
                if(isSymmetric)cout<<"Tree is symmetric"<<endl;
                else cout<<"Tree is not symmetric"<<endl;
                cout<<"Came out"<<endl;
            }
            else if(choice==17){
                cout<<"Enter data : ";
                cin>>data;
                if(!root){
                    root=new node(data);
                    cout<<"First node cerated in BST"<<endl;
                } else {
                    bfs.createBSTWithBFS(root,data);
                    cout<<"Came out"<<endl;
                }
            }
            else if(choice==18){
                preetyDisplayRightHeights(root);
            } 
            else if(choice==19){
                cout<<"Enter data : ";
                cin>>data;
                if(!root){
                    root=new node(data);
                    cout<<"First node created"<<endl;
                    continue;
                }
                stack<node*>loc;
                loc.push(root);
                root=bfs.createBSTWithBFSReturningPtr(loc,data);
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



// typedef struct TreeNode node;
// class Solution {
// public:
//     void addAddrIsSymmetricLeft(node*&one_node,deque<node*>&temp){
//             if(!one_node)return;
//             if(one_node->left){
//                 temp.push_front(one_node->left);
//             }
//             if(one_node->right){
//                 temp.push_front(one_node->right);
//             }
//         }

//         void addAddrIsSymmetricRight(node*&one_node,deque<node*>&temp){
//             if(!one_node)return;
//             if(one_node->right){
//                 temp.push_back(one_node->right);
//             }
//             if(one_node->left){
//                 temp.push_back(one_node->left);
//             }
//         }

//         bool isSymettric_helper(node*&root){
//             if(!root->left&&!root->right){
//                 return true;
//             } else if(!root->left||!root->right){
//                 return false;
//             }
//             deque<node*>answer,temp;
//             answer.push_front(root->left);
//             answer.push_back(root->right);
//             while(!answer.empty()){
//                 int size=answer.size();
//                 auto left_it=answer.front(),right_it=answer.back();
//                 for(int i=0;i<size/2;i++){
//                     left_it=answer.front();
//                     right_it=answer.back();
//                     if(left_it->val!=right_it->val){
//                         return false;
//                     }
//                     addAddrIsSymmetricLeft(left_it,temp);
//                     addAddrIsSymmetricRight(right_it,temp);
//                     answer.pop_front();
//                     answer.pop_back();
//                 }
//                 answer=temp;
//                 cout<<"deque is : "<<endl;
//                 while(!temp.empty()){
//                     cout<<temp.front()->val<<" ";
//                     temp.pop_front();
//                 }
//                 cout<<endl;
//             }
//             return true;
//         }

//     bool isSymmetric(TreeNode* root) {
//         return isSymettric_helper(root);
//     }
// };