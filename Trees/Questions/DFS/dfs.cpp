#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        int data,height,cnt=0;
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
        void invertTreeUsingBFS(node*&root){
            if(!root)return;
            queue<node*>loc;
            loc.push(root);
            while(!loc.empty()){
                int size=loc.size();
                for(int i=0;i<size;i++){
                    auto it=loc.front();
                    node*temp=it->left;
                    it->left=it->right;
                    it->right=temp;
                    addAddrInQueue(it,loc);
                    loc.pop();
                }
            }
        }

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
            //not correct
            if(!root->left&&!root->right){
                return true;
            } else if(!root->left||!root->right){
                return false;
            }

            deque<node*>answer,temp;
            answer.push_front(root->left);
            answer.push_back(root->right);
            while(!answer.empty()){
                deque<node*>newloc;
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

        bool isSymmetricCheck(node*&front,node*&back,deque<node*>&loc){
            auto front_left=front->left,front_right=front->right,back_left=back->left,back_right=back->right;
            if(front_left&&!back_right)return false;
            else if(!front_left&&back_right)return false;
            else if(front_left&&back_right){
                if(front_left->data!=back_right->data)return false;
                loc.push_front(front_left);
                loc.push_back(back_right);
            }
            if(front_right&&!back_left)return false;
            else if(!front_right&&back_left)return false;
            else if(front_right&&back_left){
                if(front_right->data!=back_left->data)return false;
                loc.push_front(front_right);
                loc.push_back(back_left);
            }
            return true;
        }

        bool isSymmetricRecursive(deque<node*>&loc){
            if(loc.empty())return true;
            int size=loc.size();
            deque<node*>newloc;
            for(int i=0;i<size/2;i++){
                if(!isSymmetricCheck(loc.front(),loc.back(),newloc)){
                    return false;
                }
                loc.pop_front();
                loc.pop_back();
            }
            return isSymmetricRecursive(newloc);
        }

        bool isSymmetricMethod2(node*&root){
            if(!root)return true;
            else if((!root->left&&root->right)||(root->left&&!root->right))return false;
            deque<node*>loc;
            loc.push_front(root->left);
            loc.push_back(root->right);
            return isSymmetricRecursive(loc);
        }

        int maxDepth(node* root) {
            if(!root)return 0;
            queue<node*>loc;
            loc.push(root);
            int height=0;
            while(!loc.empty()){
                height++;
                int size=loc.size();
                for(int i=0;i<size;i++){
                    addAddrInQueue(loc.front(),loc);
                    loc.pop();
                }
            }
            cout<<"Height = "<<height<<endl;
            return height;
        }

        bool isLeaf(node*&one_node,queue<node*>&loc){
            if(!one_node->left&&!one_node->right)return true;
            if(one_node->left)loc.push(one_node->left);
            if(one_node->right)loc.push(one_node->right);
            return false;
        }

        int minDepth(node* root) {
            if(!root)return 0;
            queue<node*>loc;
            loc.push(root);
            int height=0;
            while(!loc.empty()){
                height++;
                int size=loc.size();
                for(int i=0;i<size;i++){
                    if(isLeaf(loc.front(),loc))return height;
                    loc.pop();
                }
            }
            return -1;
        }

        bool isSumEqual(queue<node*>&loc,queue<int>&sum,int targetSum){
            auto it=loc.front();
            cout<<"Checking for "<<it->data<<endl;
            if(it->left){
                int nextSum=sum.front()+it->left->data;
                if(nextSum==targetSum&&!it->left->left&&!it->left->right)return true;
                sum.push(nextSum);
                loc.push(it->left);
            }

            if(it->right){
                int nextSum=sum.front()+it->right->data;
                if(nextSum==targetSum&&!it->right->left&&!it->right->right)return true;
                loc.push(it->right);
                sum.push(nextSum);
            }
            loc.pop();
            sum.pop();
            return false;
        }

        bool hasPathSum(node* root, int targetSum) {
            if(!root)return false;
            queue<node*>loc;
            queue<int>sum;
            sum.push(root->data);
            loc.push(root);
            while(!loc.empty()){
                int size=loc.size();
                for(int i=0;i<size;i++){
                    if(isSumEqual(loc,sum,targetSum))return true;
                }
            }
            return false;
        }

        void addAddrInQueueFromQueue(queue<node*>&loc){
            if(loc.empty())return;
            auto it=loc.front();
            if(it->left){
                loc.push(it->left);
            }
            if(it->right){
                loc.push(it->right);
            }
            loc.pop();
        }

        void tryPopulatingNextPointer2(queue<node*>&loc){
            if(loc.empty())return;
            while(!loc.empty()){
                int size=loc.size();
                auto it=loc.front();
                for(int i=0;i<size;i++){
                    it=loc.front();
                    addAddrInQueue(it,loc);
                    loc.pop();
                    if(i!=size-1)it->next=loc.front();
                }
            }
        }

        node* connect(node* root) {
            if(!root)return root;
            queue<node*>loc;
            loc.push(root);
            tryPopulatingNextPointer2(loc);
            return root;
        }
};


class DFS{
    public:
        void preorder(node*&one_node){
            if(!one_node)return;
            cout<<one_node->data<<" ";
            preorder(one_node->left);
            preorder(one_node->right);
        }

        void inorder(node*&one_node){
            if(!one_node)return;
            cout<<one_node->data<<" ";
            inorder(one_node->left);
            inorder(one_node->right);
        }

        void postorder(node*&one_node){
            if(!one_node)return;
            cout<<one_node->data<<" ";
            postorder(one_node->left);
            postorder(one_node->right);
        }

        int maxDiameterHelper(node*&one_node,int&d_max){
            if(!one_node)return 0;
            int d;
            int left = maxDiameterHelper(one_node->left,d_max);
            int right=maxDiameterHelper(one_node->right,d_max);
            d=left+right;
            if(d>d_max){
                d_max=d;
                cout<<"d_max modified to : "<<d_max<<" at "<<one_node->data<<endl;
            }
            return max(left,right)+1;
        }
        
        int maxDiameter(node*&root){
            int d_max=1;
            maxDiameterHelper(root,d_max);
            return d_max;
        }

        void invertTreeUsingDFSPostorder(node*&one_node){
            if(!one_node)return;
            invertTreeUsingDFSPostorder(one_node->left);
            invertTreeUsingDFSPostorder(one_node->right);
            if(one_node->left&&one_node->right)cout<<"Interchanging "<<one_node->left->data<<" with "<<one_node->right->data<<endl;
            node*temp=one_node->left;
            one_node->left=one_node->right;
            one_node->right=temp;
        }

        void invertTreeUsingDFSPreorder(node*&one_node){
            if(!one_node)return;
            if(one_node->left&&one_node->right)cout<<"Interchanging "<<one_node->left->data<<" with "<<one_node->right->data<<endl;
            node*temp=one_node->left;
            one_node->left=one_node->right;
            one_node->right=temp;
            invertTreeUsingDFSPreorder(one_node->left);
            invertTreeUsingDFSPreorder(one_node->right);
        }

        node* invertTreeUsingDFSPostorderReturningPtr(node*&one_node){
            if(!one_node)return nullptr;
            node*temp=one_node->right;
            one_node->right=invertTreeUsingDFSPostorderReturningPtr(one_node->left);
            one_node->left= invertTreeUsingDFSPostorderReturningPtr(temp);     
            // one_node->right=right;
            // one_node->left=left;
            return one_node;
        }

        void invertTreeUsingDFSInorder(node*&one_node){
            if(!one_node)return;
            invertTreeUsingDFSInorder(one_node->left);
            node*temp=one_node->left;
            one_node->left=one_node->right;
            one_node->right=temp;
            invertTreeUsingDFSInorder(one_node->left);
        } 

       node* invertTreeUsingDFSInorderReturningPtr(node*&one_node){
            if(!one_node)return nullptr;
            node*temp=one_node->right;
            one_node->right=invertTreeUsingDFSInorderReturningPtr(one_node->left);
            one_node->left=invertTreeUsingDFSInorderReturningPtr(temp);
            return one_node;
        } 

        void createBSTFromSortedArray(vector<int>&nums,int st,int end,node*&one_node,int cnt=0){
            if(st>end)return;
            int mid=st+(end-st)/2;
            if(!one_node){
                one_node=new node(nums[mid]);
                createBSTFromSortedArray(nums,st,mid-1,one_node,0);
                createBSTFromSortedArray(nums,mid+1,end,one_node,1);
                return;
            }
            else if(cnt==0) {
                cout<<"Created "<<nums[mid]<<" to the left of "<<one_node->data<<endl;
                one_node->left=new node(nums[mid]);
                createBSTFromSortedArray(nums,st,mid-1,one_node->left,0);
                createBSTFromSortedArray(nums,mid+1,end,one_node->left,1);
            }
            else if(cnt==1) {
                cout<<"Created "<<nums[mid]<<" to the right of "<<one_node->data<<endl;
                one_node->right=new node(nums[mid]);
                createBSTFromSortedArray(nums,st,mid-1,one_node->right,0);
                createBSTFromSortedArray(nums,mid+1,end,one_node->right,1);
            }
        }

        node* create_BST_From_Sorted_Array_Returning_Ptr(vector<int>&nums,int st,int end){
            if(st>end)return nullptr;
            int mid=st+(end-st)/2;
            node*one_node=new node(nums[mid]);
            one_node->left=create_BST_From_Sorted_Array_Returning_Ptr(nums,st,mid-1);
            one_node->right=create_BST_From_Sorted_Array_Returning_Ptr(nums,mid+1,end);
            return one_node;
        }

        node*ts=nullptr;
        void flattenTree(node*&t){
            if(!t)return;
            cout<<"Checkign for "<<t->data<<endl;
            node*t1=t->left,*t2=t->right;
            if(!t1&&!t2){
                ts=t;
                return;
            }
            flattenTree(t->left);
            if(ts&&t2){
                ts->right=t2;
                cout<<"ts("<<ts->data<<") pointing right to "<<ts->right->data<<endl;
                ts=nullptr;
            }
            else cout<<"ts if nullptr"<<endl;
            
            flattenTree(t->right);
            if(t1){
                t->right=t1;
                t->left=nullptr;
                cout<<t->data<<" pointing to right side : "<<t1->data<<endl;
            }
        }

        void putToRightMost(node*&one_node,node*&t2){
            if(!one_node->right){
                one_node->right=t2;
            } else putToRightMost(one_node->right,t2);
        }

        void flattenTreeMethod2(node*&root){
            node*t=root;
            while(t){
                if(t->left){
                    putToRightMost(t->left,t->right);
                    t->right=t->left;
                    t->left=nullptr;
                }
                t=t->right;
            }
            cout<<"Tree flattened"<<endl;
        }

        bool isNodeValid(node*&one_node){
            if(!one_node)return true;
            int curr_data=one_node->data;
            bool left=true,right=true;
            if(one_node->left){
                int left_data=one_node->left->data;
                left= left && left_data<curr_data;
                if(one_node->left->left){
                    int left_left_data=one_node->left->left->data;
                    left=left && left_left_data<left_data;
                }

                if(one_node->left->right){
                    int left_right_data=one_node->left->right->data;
                    left = left && left_right_data > left_data && left_right_data< curr_data;
                }
            }

            if(one_node->right){
                int right_data=one_node->right->data;
                right = right && right_data> curr_data;
                if(one_node->right->left){
                    int right_left_data=one_node->right->left->data;
                    right = right && right_left_data<right_data && right_left_data >curr_data;
                }
                if(one_node->right->right){
                    int right_right_data=one_node->right->right->data;
                    right = right && right_right_data>right_data;
                    // & right_right_data>curr_data
                }
            }
            return left && right;
        }

        //in question the answer is expecte to have only less than elements in the left 
        //and only greater than in the right
        bool isValid=true;
        vector<int>GiveMinMax(node*one_node){
            if(!one_node->left&&!one_node->right){
                vector<int>minmax;
                minmax.push_back(one_node->data);
                minmax.push_back(one_node->data);
                return minmax;
            }
            vector<int>returnMinMax(2);
            int curr=one_node->data;
            if(one_node->left){
                vector<int>LeftMinMax=GiveMinMax(one_node->left);
                int leftmin=LeftMinMax[0];
                int leftmax=LeftMinMax[1];
                if(!isValid){
                    // cout<<"isValid already found false for "<<one_node->data<<endl;
                }
                isValid =isValid && curr>=leftmin && curr>=leftmax;
                if(!isValid){
                    // cout<<"Invalid found for "<<one_node->data<<endl;
                    return LeftMinMax;
                }
                returnMinMax[0]=leftmin;
            } else {
                returnMinMax[0]=curr;
            }
            if(one_node->right){
                vector<int>RightMinMax=GiveMinMax(one_node->right);
                if(!isValid){
                    // cout<<"isValid already found false for "<<one_node->data<<endl;
                }
                int rightmin=RightMinMax[0];
                int rightmax=RightMinMax[1];
                isValid= isValid && curr<= rightmin && curr <= rightmax;
                if(!isValid){
                    // cout<<"Invalid found for "<<one_node->data<<endl;
                    return RightMinMax;
                }
                returnMinMax[1]=rightmax;
            } else {
                returnMinMax[1]=curr;
            }
            return returnMinMax;
        }

        bool isValidFind(node*&one_node){
           if(!one_node)return true;
           int curr=one_node->data;
            if(one_node->left){
                vector<int>LeftMinMax=GiveMinMax(one_node->left);
                int leftmin=LeftMinMax[0];
                int leftmax=LeftMinMax[1];
                if(!isValid){
                    // cout<<"isValid already found false for "<<one_node->data<<endl;
                }
                isValid =isValid && curr>=leftmin && curr>=leftmax;
                if(!isValid){
                    // cout<<"Returning false from main left"<<endl;
                    return false;
                }
            } 

            if(one_node->right){
                // cout<<"Hi"<<endl;
                vector<int>RightMinMax=GiveMinMax(one_node->right);
                if(!isValid){
                    // cout<<"isValid already found false for "<<one_node->data<<endl;
                } 
                int rightmin=RightMinMax[0];
                int rightmax=RightMinMax[1];
                // cout<<"Right side : "<<rightmin<<" & "<<rightmax;
                isValid= isValid && curr<= rightmin && curr <= rightmax;
                if(!isValid){
                    // cout<<"Returning false from right"<<endl;
                    return false;
                }
            } 
            // cout<<"Tree is valid"<<endl;
            return isValid;
        }

        bool helperisValild(node*&t1,node*&t2,int cnt=0){
            if(!t2)return true;
            bool curr=true;
            if(t1!=t2){
                
                if(cnt==0){
                    curr = curr && t2->data<t1->data;
                } else if(cnt==1){
                    curr = curr && t2->data>t1->data;
                }

                if(!curr){
                    cout<<"Tree not valid found at "<<t2->data<<" main check t1 = "<<t1->data<<endl;
                    return false;
                }

                if(t2->left){
                    if(cnt==0){
                        curr =curr && t2->left->data<t2->data;
                    } else if(cnt==1){
                        curr =curr && t2->left->data<t2->data && t2->left->data>t1->data;
                    }
                    if(!curr){
                        cout<<"Tree not valid found at "<<t2->data<<endl;
                        return false;
                    }
                }

                if(t2->right){
                    if(cnt==0){
                        curr =curr & t2->right->data > t2->data && t2->right->data<t1->data;
                    } else if(cnt==1){
                        curr= curr && t2->right->data>t2->data;
                    }
                    if(!curr){
                        cout<<"Tree not valid found at "<<t2->data<<endl;
                        return false;
                    }
                }
            }
            bool left= helperisValild(t2,t2->left,0);
            bool right = helperisValild(t2,t2->right,1);

            return left && right;
        }

        //not accepted
        bool isValidTry2(node*&one_node){
            if(!one_node)return true;
            bool ans=helperisValild(one_node,one_node,0);
            return ans;
        }

        bool helperisValidTry3(node*&one_node,int wheneverLeft,int wheneverRight){
            if(!one_node)return true;
            int curr=one_node->data;
            if((curr>=wheneverLeft||curr<=wheneverRight)){
                cout<<"Not valid found at "<<curr<<endl;
                return false;
            }
            bool left=helperisValidTry3(one_node->left,curr,wheneverRight);
            bool right=helperisValidTry3(one_node->right,wheneverLeft,curr);
            return left && right;
        }

        bool isValidTry3(node*&one_node){
            bool ans=helperisValidTry3(one_node,INT16_MAX,INT_MIN);
            return ans;
        }

        bool helperisValidTry4(node*&one_node,long long low,long long high){
            if(!one_node)return true;
            int curr=one_node->data;
            cout<<"For "<<curr<<" low = "<<low<<" & high = "<<high<<endl;
            if(curr<=low||curr>=high){
                cout<<"Not valid found "<<one_node->data<<endl;
                cout<<"low = "<<low<<" & high = "<<high<<endl;
                return false;
            }
            bool left=helperisValidTry4(one_node->left,low,curr);
            bool right=helperisValidTry4(one_node->right,curr,high);
            return left && right;
        }
        
        bool isValidTry4(node*&one_node){
            int low=INT16_MIN;
            int high=INT16_MAX;
            cout<<INT16_MIN<<endl;
            cout<<INT16_MAX<<endl;
            bool ans=helperisValidTry4(one_node,LLONG_MIN,LLONG_MAX);
            return ans;
        }

        node* findInTree(node*&one_node,int toFind){
            if(!one_node)return nullptr;
            if(one_node->data==toFind)return one_node;
            node* answer=findInTree(one_node->left,toFind);
            if(answer)return answer;
            answer=findInTree(one_node->right,toFind);
            return answer;
        }

        bool found1=false;
        node* foundNode=nullptr,*notFoundNode=nullptr,*answer=nullptr;
        bool isPresent(node*&one_node,node*&toFind){
            if(!one_node)return false;
            if(one_node==toFind)return true;
            return isPresent(one_node->left,toFind) || isPresent(one_node->right,toFind);
        }
       
        bool isPresent(node*&one_node,int toFind){
            if(!one_node)return false;
            if(one_node->data==toFind)return true;
            return isPresent(one_node->left,toFind) || isPresent(one_node->right,toFind);
        }
        void helperLowestAncestorFind(node*&one_node,node*&p,node*&q){
            if(!one_node)return;
            node*ans=nullptr;
            if(one_node==p){
                cout<<"found 1 is : "<<one_node->data<<endl;
                foundNode=p;
                notFoundNode=q;
                found1=true;
                return;
            }else if(one_node==q){
                cout<<"found 1 is : "<<one_node->data<<endl;
                foundNode=q;
                notFoundNode=p;
                found1=true;
                return;
            }
            helperLowestAncestorFind(one_node->left,p,q);
            if(!found1)helperLowestAncestorFind(one_node->right,p,q);
            if(answer)return;
            if(found1){
                bool right;
                if(notFoundNode==p){
                    right=isPresent(one_node->right,p);
                }else {
                    right=isPresent(one_node->right,q);
                }
                if(right){
                    answer=one_node;
                    cout<<"First answer found at : "<<answer->data<<endl;
                }
            }
        }

        node* lowestCommonAncestor(node*&root){
            if(!root)return root;
            found1=false;
            notFoundNode=nullptr;
            foundNode=nullptr;
            answer=nullptr;
            node*p,*q;
            int pd,qd;
            cout<<"Enter p : ";
            cin>>pd;
            p=findInTree(root,pd);
            cout<<"Enter q : ";
            cin>>qd;
            q=findInTree(root,qd);
            cout<<"p pointing at : "<<p->data<<endl;
            cout<<"q pointing at : "<<q->data<<endl;
            bool pfindq=isPresent(p,q);
            bool qfindp=isPresent(q,p);
            cout<<"Recursive back Search"<<endl;
            if(pfindq)return p;
            else if(qfindp)return q;
            helperLowestAncestorFind(root,p,q);
            if(answer)cout<<"Answer found as "<<answer->data<<endl;
            else cout<<"ANwer not found"<<endl;
            return answer;
        }

        node*helperLowestCommonAncestorTry3(node*&one_node,node*&p,node*&q){
            if(!one_node)return nullptr;
            if(one_node==p|one_node==q)return one_node;
            node* left=helperLowestCommonAncestorTry3(one_node->left,p,q);
            node*right=helperLowestCommonAncestorTry3(one_node->right,p,q);
            if(left&&right)return one_node;
            else if(left)return left;
            else return right;
        }

        node*lowestCommonAncestorTry3(node*&root){
            node*p,*q;
            found1=false;
            notFoundNode=nullptr;
            foundNode=nullptr;
            answer=nullptr;
            int pd,qd;
            if(!root)return root;
            else {
                cout<<"Enter p : ";
                cin>>pd;
                p=findInTree(root,pd);
                cout<<"Enter q : ";
                cin>>qd;
                q=findInTree(root,qd);
                cout<<"p pointing at : "<<p->data<<endl;
                cout<<"q pointing at : "<<q->data<<endl;
            }
            return helperLowestCommonAncestorTry3(root,p,q);
        }

        bool discover1=false,discover2=false;

        void isBothPresent(node*&one_node,node*p,node*q){
            if(!one_node)return;
            if(one_node==p|| one_node==q){
                if(discover1){
                    discover2=true;
                    return;
                }
                else discover1=true;
            }
            isBothPresent(one_node->left,p,q);
            if(discover2)return;
            isBothPresent(one_node->right,p,q);
        }
        
        int helperisBothPresent(node*&one_node,node*p,node*q){
                discover1=false;
                discover2=false;
                isBothPresent(one_node,p,q);

                if(discover2)cout<<"Discover2 : true"<<endl;
                else cout<<"Discover2 : false"<<endl;
                if(discover1)cout<<"discover1 : true"<<endl;
                else cout<<"Discover1 : false"<<endl;

                if(discover2)return 2;
                else if(discover1)return 1;
                else return 0;
        }
        
        node* lowestCommonAncestorTry2(node*&root){
            if(!root)return root;
            found1=false;
            notFoundNode=nullptr;
            foundNode=nullptr;
            answer=nullptr;
            node*p,*q;
            int pd,qd;
            cout<<"Enter p : ";
            cin>>pd;
            p=findInTree(root,pd);
            cout<<"Enter q : ";
            cin>>qd;
            q=findInTree(root,qd);
            cout<<"p pointing at : "<<p->data<<endl;
            cout<<"q pointing at : "<<q->data<<endl;
            node*one_node = root;
            while(1){
                int leftcnt=helperisBothPresent(one_node->left,p,q);
                int rightcnt=helperisBothPresent(one_node->right,p,q);
                if(leftcnt==1&&rightcnt==1){return one_node;}
                else if(leftcnt==2&&rightcnt==0){
                    one_node=one_node->left;
                } else if(rightcnt==2&&leftcnt==0){
                    one_node=one_node->right;
                } else {
                    cout<<"leftcount = "<<leftcnt<<" & rightcount = "<<rightcnt<<" for "<<one_node->data<<endl;
                    return one_node;
                }
            }
        }

        void isBothPresent(node*&one_node,int k1,int k2){
            if(!one_node)return;
            if(one_node->data==k1||one_node->data==k2){
                // cout<<"Found "<<one_node->data<<endl;
                // cout<<"k1 = "<<k1<<endl;
                if(discover1){
                    discover2=true;
                    return;
                } else discover1=true;
            }
            if(discover2)return;
            isBothPresent(one_node->left,k1,k2);
            if(discover2)return;
            isBothPresent(one_node->right,k1,k2);
        }

        bool helperisBothPresent(node*&one_node,int k1,int k2){
            discover1=false;
            discover2=false;
            isBothPresent(one_node,k1,k2);
            if(discover2)return true;
            else return false;
        }

        bool TwoSums(node*&one_node,int k){
            for(int i=k-1;i>=k/2;i--){
              bool bothPresent=helperisBothPresent(one_node,i,k-i);
              if(bothPresent)return true;
            }
            return false;
        }

        void preOrderPlusSearch(node*&one_node,node*root,int k){
            if(!one_node)return;
            if(isPresent(root,k-one_node->data)){
                found=true;
                return;
            } 
            preOrderPlusSearch(one_node->left,root,k);
            if(found)return;
            preOrderPlusSearch(one_node,root,k);
        }
        bool found=false;
        //best time complexity
        bool twoSumsTry2(node*&root,int k){
            if(!root)return false;
            found=false;
            preOrderPlusSearch(root,root,k);
            return found;
        }
        // bool found=false;
        int helperKthSmallestElement(node*one_node,int &cnt,int k){
            if(!one_node)return 0;
            int ret=helperKthSmallestElement(one_node->left,cnt,k);
            if(found)return ret;
            cnt++;
            if(cnt==k){
                found=true;
                cout<<"Found "<<one_node->data<<" as the "<<cnt<<"th smallest element"<<endl;
                return one_node->data;
            }
            return helperKthSmallestElement(one_node->right,cnt,k);
        }
        
        node* helperKthSmallestElementReturnNode(node*one_node,int &cnt,int k){
            if(!one_node)return 0;
            node*ret=helperKthSmallestElementReturnNode(one_node->left,cnt,k);
            if(found)return ret;
            cnt++;
            if(cnt==k){
                found=true;
                cout<<"Found "<<one_node->data<<" as the "<<cnt<<"th smallest element"<<endl;
                return one_node;
            }
            return helperKthSmallestElementReturnNode(one_node->right,cnt,k);
        }

        int kthSmallestElementInBST(node*&root,int k){
            int cnt=0;
            if(!root)return -1;
            return helperKthSmallestElement(root,cnt,k);
        }

        node* helperCreateBTFromPreordeAndInorder(node*one_node,vector<int>preorder,vector<int>inorder){
            if(preorder.empty())return nullptr;
            one_node=new node(preorder.front());
            auto it=find(inorder.begin(),inorder.end(),preorder.front());
            int index=distance(inorder.begin(),it);
            vector<int>preorderLeft(preorder.begin()+1,preorder.begin()+1+index);
            vector<int>inorderLeft(inorder.begin(),inorder.begin()+index);
            one_node->left=helperCreateBTFromPreordeAndInorder(one_node->left,preorderLeft,inorderLeft);
            vector<int>preorderRight(preorder.begin()+1+index,preorder.end());
            vector<int>inorderRight(inorder.begin()+index+1,inorder.end());
            one_node->right=helperCreateBTFromPreordeAndInorder(one_node->right,preorderRight,inorderRight);
            return one_node;
        }

        node* createBTFromPreorderAndInorder(node*&root,vector<int>&preorder,vector<int>&inorder){
            root=helperCreateBTFromPreordeAndInorder(root,preorder,inorder);
            return root;
        }
        
        int cnt=0;
        node* helperCreateBTFromPostorderAndInorder(vector<int>postorder,vector<int>inorder){
            cnt++;
            if(cnt>=30)return nullptr;
            if(postorder.empty())return nullptr;
            node*one_node=new node(postorder.back());
            cout<<one_node->data<<" is created"<<endl;
            auto it=find(inorder.begin(),inorder.end(),postorder.back());
            int index=distance(inorder.begin(),it);
            vector<int>postorderLeft(postorder.begin(),postorder.begin()+index);
            vector<int>inorderLeft(inorder.begin(),inorder.begin()+index);
            one_node->left=helperCreateBTFromPostorderAndInorder(postorderLeft,inorderLeft);
            postorder.pop_back();
            vector<int>postorderRight(postorder.begin()+index,postorder.end());
            vector<int>inorderRight(inorder.begin()+index+1,inorder.end());
            one_node->right=helperCreateBTFromPostorderAndInorder(postorderRight,inorderRight);
            return one_node;
        }

        node* createBTFromPostorderAndInorder(vector<int>postorder,vector<int>inorder){
            if(postorder.empty())return nullptr;
            return helperCreateBTFromPostorderAndInorder(postorder,inorder);
        }
        int maxx=INT_MIN;
        int helperMaxPathSum(node*&one_node){
            if(!one_node)return 0;
            // if(!one_node->left&&!one_node->right){
            //     return one_node->val;
            // }
            int curr=one_node->data;
            int left=helperMaxPathSum(one_node->left);
            int right=helperMaxPathSum(one_node->right);
            if(left<0&&right<0){
                if(curr>maxx)maxx=curr;
                return curr;
            } else if(left<0){
                if((right+curr)>maxx)maxx=right+curr;
                return curr+right;
            } else if(right<0){
                if((left+curr)>maxx)maxx=left+curr;
                return curr+left;
            }
            else if((left+right+curr)>maxx)maxx=left+right+curr;
            return left>right? (left +curr): (right+curr);
        }

        int maxPathSum(node*&root){
            maxx=INT_MIN;
            int maxReceived=helperMaxPathSum(root);
            return maxx>maxReceived? maxx : maxReceived;
        }

        bool helperPathExists(node*&one_node,vector<int>path){
            if(!one_node)return false;
            if(one_node->data!=path.back())return false;
            path.pop_back();
            if(path.empty())return true;
            return helperPathExists(one_node->left,path) || helperPathExists(one_node->right,path);
        }
        
        bool helperPathExistsTry2(node*&one_node,vector<int>&path,int i=0){
            if(i==path.size())return true;
            if(!one_node)return false;
            if(one_node->data!=path[i])return false;
            // if(i=path.size()-1)return true;
            return helperPathExistsTry2(one_node->left,path,i+1) || helperPathExistsTry2(one_node->right,path,i+1);
        }
        
        bool pathExists(node*&root,vector<int>path){
            // reverse(path.begin(),path.end());
            return helperPathExistsTry2(root,path);
        }

        vector<string>allPaths;
        int nPathSums=0;
        int recursiveFindAllSums(int target,int st,vector<int>&nums,int sum){
            if(st>=nums.size())return 0;
            int cnt=0;
            sum+=nums[st];
            if(sum==target)cnt=1;
            cnt+=recursiveFindAllSums(target,st+1,nums,sum);
            return cnt;
        }
        
        int possibleWaysToGetTargetViaSum(int target,vector<int>nums,int sum=0){
            int cnt=0;
            for(int i=0;i<nums.size();i++){
                cnt+=recursiveFindAllSums(target,i,nums,0);
            }
            return cnt;
        }
        
        int possibleWaysToGetTargetViaSum2(int target,vector<int>nums){
            string path="";
            int cnt=0;
            int sum=0;
            for(int i=nums.size()-1;i>=0;i--){
                path="->"+to_string(nums[i])+path;
                sum+=nums[i];
                if(sum==target){
                    cnt++;
                    allPaths.push_back(path);
                }
            }
            return cnt;
        }
        
        int helperPathSumAny(node*&one_node,int target,vector<int>nums){
            if(!one_node)return 0;
            int cnt=0;
            // if(!one_node->left&&!one_node->right)
            cnt+=possibleWaysToGetTargetViaSum2(target,nums);
            cout<<"Found "<<cnt<<" for "<<one_node->data<<" nums : ";
            for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
            cout<<endl;
            if(one_node->left){
                nums.push_back(one_node->left->data);
                int cntleft=helperPathSumAny(one_node->left,target,nums);
                nums.pop_back();
                cnt+=cntleft;
            }
            if(one_node->right){
                nums.push_back(one_node->right->data);
                int cntright=helperPathSumAny(one_node->right,target,nums);
                nums.pop_back();
                cnt+=cntright;
            }
            return cnt;
        }

        int pathSumAnyPresent(node*&root,int target){
            nPathSums=0;
            vector<int>sums;
            sums.push_back(root->data);
            int total_possible_answers=helperPathSumAny(root,target,sums);
            cout<<"NUmber of solutions possibel are : "<<total_possible_answers<<endl;
            cout<<"ALl possible paths are : "<<endl;
            for(string str : allPaths){
                cout<<str<<endl;
            }
            return total_possible_answers;
        }

        void addAddrInStackForIterative(node*&one_node,stack<node*>&loc){
            if(!one_node)return;
            if(one_node->right)loc.push(one_node->right);
            if(one_node->left)loc.push(one_node->left);
        }

        void inorderUsingStack(node*&root){
            if(!root)return;
            stack<node*>loc;
            loc.push(root);
            auto it=loc.top();
            while(!loc.empty()){
                it=loc.top();
                cout<<it->data<<" ";
                loc.pop();
                addAddrInStackForIterative(it,loc);
            }
            cout<<endl;
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
    node*one_node;
    if(data==-5)one_node=nullptr;
    else one_node=new node(data);
    cout<<"cnt = "<<cnt<<endl;
    if(cnt==0){
        parent.front()->left=one_node;
        cnt++;
    } else if(cnt==1){
        parent.front()->right=one_node;
        cnt=0;
        parent.pop();
    }
    if(data!=-5)parent.push(one_node);
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
    cout<<"4 : preorder"<<endl;
    cout<<"5 : inorder"<<endl;
    cout<<"6 : postorder"<<endl;
    cout<<"7 : "<<endl;
    cout<<"8 : Invert BT using DFS"<<endl;
    cout<<"9 : Invert a tree BFS"<<endl;
    cout<<"10 : create BT using sorted array"<<endl;
    cout<<"11 : Flatten the tree"<<endl;
    cout<<"12 : is Tree Valid"<<endl;
    cout<<"13 : Find Lowest Common Ancestor"<<endl;
    cout<<"14 : Two sum equal to given number"<<endl;
    cout<<"15 : Create BT from Preorder and Inorder"<<endl;
    cout<<"16 : Create BT from postorder and inorder"<<endl;
    cout<<"17 : Maximum Path Sum"<<endl;
    cout<<"18 : Path Exists"<<endl;
    cout<<"19 : Path sums any"<<endl;
    cout<<"20 : Inorder using Stack"<<endl;
    cout<<"Your choice : ";
    cin>>choice;
    return choice;
}

int main(){
   
    int choice=1,data;
    node*root=nullptr;
    DFS dfs;
    BFS bfs;
    queue<node*>loc;
    try{
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

            } 
            else if(choice==2){
                if(!root){
                    cout<<"Tree is empty"<<endl;
                    continue;    
                }
                try{
                    preetyDisplayRight(root);
                } catch(...){
                    cout<<"Error occured"<<endl;
                }
            } 
            else if(choice==4){
                dfs.preorder(root);
            } 
            else if(choice==5){
                dfs.inorder(root);
            } 
            else if(choice==6){
                dfs.postorder(root);
            }
            else if(choice==7){
                int d_max=dfs.maxDiameter(root);
                cout<<"Maximum diameter possible : "<<d_max<<endl;
            }
            else if(choice==8){
                int m;
                cout<<"Whcih method to use for inverting BT :\n1 : preorder\n2 : post-order\n3 : Inorder\n4 : Post-order returning ptr\n6 : Inorde returning ptr\nYour choice : ";
                cin>>m;
                if(m==1){
                    dfs.invertTreeUsingDFSPreorder(root);
                } else if(m==2){
                    dfs.invertTreeUsingDFSPostorder(root);
                } else if(m==3){
                    dfs.invertTreeUsingDFSInorder(root);
                } else if(m==4){
                    root=dfs.invertTreeUsingDFSPostorderReturningPtr(root);
                } else if(m==6){
                    root=dfs.invertTreeUsingDFSInorderReturningPtr(root);
                }
                cout<<"After inverting tree loks like : "<<endl;
                preetyDisplayRight(root);
            }
            else if(choice==9){
                bfs.invertTreeUsingBFS(root);
                cout<<"After inverting tree loks like : "<<endl;
                preetyDisplayRight(root);
            }
            else if(choice==10){
                int n;
                cout<<"Enter size of the array : ";
                cin>>n;
                vector<int>nums(n);
                cout<<"Enter "<<n<<" numbers : "<<endl;
                for(int i=0;i<n;i++)cin>>nums[i];
                int m;
                cout<<"Create BST from sorted array using\n1 : vboid type function\n2 : Returning ptr\nYour choice : ";
                cin>>m;
                if(m==1){
                    dfs.createBSTFromSortedArray(nums,0,n-1,root,0);
                } else if(m==2){
                    root=dfs.create_BST_From_Sorted_Array_Returning_Ptr(nums,0,n-1);
                }
                cout<<"Created BST from sorted array looks like :"<<endl;
                preetyDisplayRight(root);
            }
            else if(choice==11){
                int m;
                cout<<"Enter which method to use\n1 : Postorder method used\n2 : Preorder method used(first modified then went right)\nYour choice : ";
                cin>>m;
                if(m==1){
                    dfs.flattenTree(root);
                } else if(m==2){
                    dfs.flattenTreeMethod2(root);
                }
                cout<<"After flattenignt he tree looks like :"<<endl;
                preetyDisplayRight(root);
            }
            else if(choice==12){
                int m;
                cout<<"Which method to use\n1 : Method-1\n2 : Methond-2\n3 : Method-3\n4 : Method-4\nYour choice : ";
                cin>>m;
                bool ans=true;
                if(m==1){
                    dfs.isValid=true;
                    ans=dfs.isValidFind(root);
                } else if(m==2){
                    ans=dfs.isValidTry2(root);
                } else if(m==3){
                    ans=dfs.isValidTry3(root);
                } else if(m==4){
                    ans=dfs.isValidTry4(root);
                }
                if(ans)cout<<"Tree is valid"<<endl;
                else cout<<"Tree not valid"<<endl;
            }
            else if(choice==13){
                int m;
                cout<<"Enter which method you want to apply\n1 : Method-1\n2 : MEthod-2\n3 : Kunal sir's method\nYour choice : ";
                cin>>m;
                node*lowestCommonAncestor;
                if(m==1){
                    lowestCommonAncestor=dfs.lowestCommonAncestor(root);
                } else if(m==2){
                    lowestCommonAncestor=dfs.lowestCommonAncestorTry2(root);
                } else if(m==3){
                    lowestCommonAncestor=dfs.lowestCommonAncestorTry3(root);
                }
                if(lowestCommonAncestor)cout<<"Answer received in main : "<<lowestCommonAncestor->data<<endl;
                else cout<<"Answer not receievd in main"<<endl;
            }
            else if(choice==14){
                int k;
                cout<<"Enter the targe : ";
                cin>>k;
                bool ans=dfs.TwoSums(root,k);
                if(ans)cout<<"Possible"<<endl;
                else cout<<"Not possible"<<endl;
            }
            else if(choice==15){
                int n;
                cout<<"Enter size of arrays : ";
                cin>>n;
                vector<int>preorder(n),inorder(n);
                cout<<"Enter "<<n<<" numbers in preorder manner"<<endl;
                for(int i=0;i<n;i++)cin>>preorder[i];
                cout<<"Enter "<<n<<" numbers for inorder array : ";
                for(int i=0;i<n;i++)cin>>inorder[i];
                root=dfs.createBTFromPreorderAndInorder(root,preorder,inorder);
                cout<<"AFter creating the tree looks like : "<<endl;
                preetyDisplayRight(root);
            }
            else if(choice==16){
                int n;
                cout<<"Enter size of the array : ";
                cin>>n;
                vector<int>postorder(n),inorder(n);
                cout<<"Enter "<<n<<" nuymbers for postorder array : ";
                for(int i=0;i<n;i++)cin>>postorder[i];
                cout<<"Enter "<<n<<" numbers for inOrder array"<<endl;
                for(int i=0;i<n;i++)cin>>inorder[i];
                root=dfs.createBTFromPostorderAndInorder(postorder,inorder);
                cout<<"AFter creating the tree looks like : "<<endl;
                preetyDisplayRight(root);
            }   
            else if(choice==17){
                int ans=dfs.maxPathSum(root);
                cout<<"Ans = "<<ans<<endl;
            }
            else if(choice==18){
                int n;
                cout<<"ENter size of array path : ";
                cin>>n;
                vector<int>path(n);
                cout<<"Enter path data one by one : ";
                for(int i=0;i<n;i++)cin>>path[i];
                bool ans=dfs.pathExists(root,path);
                if(ans)cout<<"Exists"<<endl;
                else cout<<"Does not exists"<<endl;
            }
            else if(choice==19){
                int target;
                cout<<"Enter target : ";
                cin>>target;
                int total_possible=dfs.pathSumAnyPresent(root,target);
                cout<<"Total_possible = "<<total_possible<<endl;
            }
            else if(choice==20){
                stack<node*>loc;
                loc.push(root);
                dfs.inorderUsingStack(root);
            }
        }

    } catch(...){
        cout<<"Error occured"<<endl;
    }
    cout<<"Came out"<<endl;
    delete_nodes(root);
}    
