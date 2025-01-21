#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class DynamicProgramming{
    public:
        int n=-1;
        DynamicProgramming(int n):n(n){
            // cout<<"inside constructor"<<endl;
            createMatrix(n);
        }
        vector<vector<int>>matrix;
        vector<vector<unsigned long long>>noOfWays;
        vector<vector<bool>>visited,pushed;
        int targetX,targetY;
        unsigned long long cnt=0,savedCalculation=0;
        vector<pair<int,int>>downNright={{1,0},{0,1}};
        vector<pair<int,int>>leftNup={{-1,0},{0,-1}};
        vector<pair<int,int>>downNleftNright={{0,-1},{1,0},{0,1}};
        vector<pair<int,int>>downNrightNdia={{1,0},{0,1},{1,1}};
        
        unordered_set<unsigned long long>notPossible;
        bool isSafe(int x,int y){
            return (x>=0&&y>=0&&x<noOfWays.size()&&y<noOfWays[x].size());
        }

        void traverse(queue<pair<int,int>>&loc){
            if(loc.empty())return;
            int size=loc.size();
            while(size--){
                int x=loc.front().first;
                int y=loc.front().second;
                loc.pop();
                if(x==targetX&&y==targetY){
                    cout<<"Reached target"<<endl;
                    continue;
                }
                cout<<"From "<<x<<","<<y<<endl;
                for(auto it:downNright){
                    int nextX=x+it.first,nextY=y+it.second;
                    if(isSafe(nextX,nextY)){
                        matrix[nextX][nextY]++;
                        loc.push({nextX,nextY});
                        cout<<"\tPushing "<<nextX<<","<<nextY<<endl;
                    }
                }
                int diaX=x+1,diaY=y+1;
                if(isSafe(diaX,diaY)){
                    matrix[diaX][diaY]++;
                    loc.push({diaX,diaY});
                    cout<<"\tPushing "<<diaX<<","<<diaY<<endl;
                }
            }
            traverse(loc);
        }

        unsigned long long dynamicTraverse(int x,int y){
        if(noOfWays[x][y]!=0){
            savedCalculation++;
            return noOfWays[x][y];
        }
        // cnt++;
        // cout<<"Calculation no - "<<cnt<<endl;
        for(auto it:downNright){
            int nextX=x+it.first;
            int nextY=y+it.second;
            if(isSafe(nextX,nextY)){
                noOfWays[x][y]+=dynamicTraverse(nextX,nextY);
            }
        }
        return noOfWays[x][y];
        }

        unsigned long long matrixNormalTraverse(int x,int y){
            cnt++;
            cout<<"Calculation no - "<<cnt<<endl;
            if(x==targetX&&y==targetY)return 1;
            unsigned long long ret=0;

            for(auto it:downNright){
                int nextX=x+it.first;
                int nextY=y+it.second;
                if(isSafe(nextX,nextY)){
                    ret+=matrixNormalTraverse(nextX,nextY);
                }
            }
            return ret;
        }

        unsigned long long dynamicTraverseWithObstacles(int x,int y){
            if(noOfWays[x][y]==INT_MAX){
                return 0;
            }
            else if(noOfWays[x][y]!=0){
                return noOfWays[x][y];
            }

            for(auto it:downNright){
                int nextX=x+it.first;
                int nextY=y+it.second;
                if(isSafe(nextX,nextY)){
                    noOfWays[x][y]+= dynamicTraverseWithObstacles(nextX,nextY);
                }
            }

            return noOfWays[x][y]; 
        }

        void displayMatrix(){
            cout<<"noOfWays Matrix is : "<<endl;
            for(int i=0;i<noOfWays.size();i++){
                for(int j=0;j<noOfWays[i].size();j++){
                    cout<<noOfWays[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        void gridTopLeftToBottomRightDynamic(){
            if(n==-1){
                // cout<<"noOfWays matrix needs to be created"<<endl;
                createMatrix();
            }
            noOfWays.assign(n,vector<unsigned long long>(n,0));
            noOfWays[targetX][targetY]=1;
            dynamicTraverse(0,0);
            // cout<<"Saved total "<<savedCalculation<<" calculation from outside"<<endl;
            savedCalculation=0;
            cnt=0;
            savedCalculation=0;
            cout<<"Dynamically traversed from Top-Left to Bottom-Right"<<endl;
            cout<<"Total no of ways to reach destination are : "<<noOfWays[0][0]<<endl;
        }

        void createMatrix(int n=-1){
            if(n==-1){
                cout<<"Enter N : ";
                cin>>n;
            }
            cout<<"Creating noOfWays matrix"<<endl;
            this->n=n;
            noOfWays.clear();
            noOfWays.resize(n,vector<unsigned long long>(n,0));
            visited.resize(n,vector<bool>(n,false));
            targetX=n-1;
            targetY=n-1; 
        }

        void matrixTopLeftToBottomRightWithObstacles(){
            noOfWays.assign(n,vector<unsigned long long>(n,0));
            noOfWays[targetX][targetY]=1;
            int nObs,obsX,obsY;
            cout<<"How many obstacles are there : ";
            cin>>nObs;
            for(int i=0;i<nObs;i++){
                cout<<"Enter X & Y co-ordinates of obstacle no "<<i+1<<" : ";
                cin>>obsX>>obsY;
                if(isSafe(obsX,obsY)){
                    noOfWays[obsX][obsY]=INT_MAX;
                } else {
                    cout<<"Invalid indexes enetere...enter again"<<endl;
                    i--;
                }
            }
            unsigned long long ans=dynamicTraverseWithObstacles(0,0);
            cout<<"Dynamically traversed from Top-Left to Bottom-Right With "<<nObs<<" obstacles"<<endl;
            cout<<"Total no of ways to reach destination are : "<<ans<<endl;
        }

        void showTarget(){
            cout<<"TARGET = {"<<targetX<<","<<targetY<<"}"<<endl;
        }

        void helperBottomRightToTopLeftBFS(queue<pair<int,int>>&loc){
            while(!loc.empty()){
                int x=loc.front().first;
                int y=loc.front().second;
                loc.pop();
                for(auto it:leftNup){
                    int nextX=x+it.first;
                    int nextY=y+it.second;
                    if(isSafe(nextX,nextY)){
                        noOfWays[nextX][nextY]+=noOfWays[x][y];
                        if(!pushed[nextX][nextY]){
                            loc.push({nextX,nextY});
                            pushed[nextX][nextY]=true;
                        }
                    }
                }
            }
           
        }

        void matrixBottomRightToTopLeft_BFS(){
            queue<pair<int,int>>loc;
            loc.push({targetX,targetY});
            showTarget();
            noOfWays.assign(n,vector<unsigned long long>(n,0));
            pushed.assign(n,vector<bool>(n,false));
            noOfWays[targetX][targetY]=1;
            helperBottomRightToTopLeftBFS(loc);
            cout<<"Traversal complete from Bottom Right To Top Left"<<endl;
            displayMatrix();
            cout<<"No of ways to reach TARGET from {0,0} are : "<<noOfWays[0][0]<<endl;
        }

        void test(){
            int x=2,y=2;
            for(auto it:downNleftNright){
                int nextX=x+it.first;
                int nextY=y+it.second;
                cout<<nextX<<" & "<<nextY<<endl;
            }
        }

        void displayVisitedMatrix(){
            for(int i=0;i<visited.size();i++){
                for(int j=0;j<visited[i].size();j++){
                    cout<<visited[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        unsigned long long helper_matrixThreeDrxnTopLeftToBottomRight(int x,int y){
            if(noOfWays[x][y]!=0){
                // cout<<"Returning "<<noOfWays[x][y]<<" from "<<x<<" & "<<y<<endl;
                return noOfWays[x][y];
            }
            visited[x][y]=true;
            cout<<"Going through "<<x<<" & "<<y<<endl;
            displayVisitedMatrix();
            for(auto it:downNleftNright){
                int nextX=x+it.first;
                int nextY=y+it.second;
                if(isSafe(nextX,nextY)&&!visited[nextX][nextY]){
                    int temp=helper_matrixThreeDrxnTopLeftToBottomRight(nextX,nextY);
                    noOfWays[x][y]+=temp;
                    cout<<"Received "<<temp<<" from "<<nextX<<" & "<<nextY<<endl;
                    visited[nextX][nextY]=false;
                } else {
                    cout<<nextX<<" & "<<nextY<<" not allowed"<<endl;
                }
            }
            return noOfWays[x][y];
        }

        void matrixThreeDrxnTopLeftToBottomRight(){
            noOfWays.assign(n,vector<unsigned long long>(n,0));
            noOfWays[targetX][targetY]=1;
            showTarget();
            helper_matrixThreeDrxnTopLeftToBottomRight(0,0);
            cout<<"three sides traversal complete from Top Left to Bottom Right"<<endl;
            cout<<"No of ways to reach TARGET are : "<<noOfWays[0][0]<<endl;
            cout<<" visited cells are : "<<endl;
            displayVisitedMatrix();
        }

        unsigned long long helper_matrixTopLeftToBottomRightAlvin(int x,int y){
            if(x==0 || y==0)return 0;
            else if(noOfWays[x][y]!=0)return noOfWays[x][y];

            for(auto it: downNright){
                int nextX=x+it.first;
                int nextY=y+it.second;
                noOfWays[x][y]+=helper_matrixTopLeftToBottomRightAlvin(nextX,nextY);
            }

            return noOfWays[x][y];
        }

        void matrixTopLeftToBottomRightAlvin(){
            // unsigned long long totalPossibleWays=helper_matrixTopLeftToBottomRightAlvin(0,);
            // cou
        }

        unsigned long long helper_matrixTopLeftToBottomRight_RightDownDia(int x,int y){
            if(noOfWays[x][y]!=0){
                return noOfWays[x][y];
            }
            cnt++;
            cout<<"Calculation no - "<<cnt<<endl;
            for(auto it:downNrightNdia){
                int nextX=x+it.first;
                int nextY=y+it.second;
                if(isSafe(nextX,nextY)){
                    noOfWays[x][y]+=helper_matrixTopLeftToBottomRight_RightDownDia(nextX,nextY);
                }
            }
            return noOfWays[x][y];
        }

        void matrixTopLeftToBottomRight_RightDownDia(){
            noOfWays.assign(n,vector<unsigned long long>(n,0));
            noOfWays[targetX][targetY]=1;
            int totalPossibleWays=helper_matrixTopLeftToBottomRight_RightDownDia(0,0);
            cout<<"Traversal perfomed from Top Left to Bottom Right while moving(Right,Down & Diagonally) in : "<<totalPossibleWays<<endl;
        }

        unsigned long long helper_matrixTopLeftToBottomRight_invertIndexMarking(int x,int y){
            if(noOfWays[x][y]!=0){
                return noOfWays[x][y];
            }
            // cnt++;
            // cout<<"Calculation no - "<<cnt<<endl;
            for(auto it:downNright){
                int nextX=x+it.first;
                int nextY=y+it.second;
                if(isSafe(nextX,nextY)){
                    noOfWays[x][y]+=helper_matrixTopLeftToBottomRight_invertIndexMarking(nextX,nextY);
                }
            }
            if(isSafe(y,x)){
                noOfWays[y][x]=noOfWays[x][y];
            }
            return noOfWays[x][y];
        }

        void matrixTopLeftToBottomRight_invertIndexMarking(){
            cnt=0;
            noOfWays.assign(n,vector<unsigned long long>(n,0));
            noOfWays[targetX][targetY]=1;
            unsigned long long totalPossibleWays=helper_matrixTopLeftToBottomRight_invertIndexMarking(0,0);
            cout<<"TRaversing complete from Top Left to Bottom Right using Marking the [y][x] after finding noOfWays[x][y] (Alvin)"<<endl;
            cout<<"No of possible path from Top Left to Bottom Right are : "<<totalPossibleWays<<endl;
            cnt=0;
        }

        bool helper_canSumDP(unsigned long long curr,vector<unsigned long long>&nums,unsigned long long target){
            cout<<"Curr = "<<curr<<endl;
            if(curr>target||notPossible.find(curr)!=notPossible.end()){
                notPossible.insert(curr);
                return false;
            }
            else if(curr==target)return true;
            for(unsigned long long &next:nums){
                if(helper_canSumDP(curr+next,nums,target))return true;
            }
            notPossible.insert(curr);
            return false;
        }

        bool canSumDP(){
            notPossible.clear();
            unsigned long long target;
            int nNum;
            cout<<"ENter target : ";
            cin>>target;
            cout<<"How many number are in the vector : ";
            cin>>nNum;
            vector<unsigned long long>nums(nNum,0);
            cout<<"Enter "<<nNum<<" numbers of the vector"<<endl;
            for(int i=0;i<nNum;i++){
                cin>>nums[i];
            }
            bool ans=helper_canSumDP(0,nums,target);
            if(ans){
                cout<<"It is possibel to reach sum = "<<target<<" using the vector"<<endl;
            } else {
                cout<<"it is not possibel to reach target with given numbers"<<endl;
            }
            return ans;
        }

        bool helper_canSum(unsigned long long curr,vector<unsigned long long>&nums,unsigned long long target){
            cout<<"hey"<<endl;
            if(curr==target)return true;
            else if(curr>target)return false;
            bool ret=false;
            for(int next:nums){
                if(helper_canSum(curr+next,nums,target))return true;
            }
            return false;
        }

        bool canSum(){
            unsigned long long target;
            int nNum;
            cout<<"ENter target : ";
            cin>>target;
            cout<<"How many number are in the vector : ";
            cin>>nNum;
            vector<unsigned long long>nums(nNum,0);
            cout<<"Enter "<<nNum<<" numbers of the vector"<<endl;
            for(int i=0;i<nNum;i++){
                cin>>nums[i];
            }
            bool ans=helper_canSum(0,nums,target);
            if(ans){
                cout<<"It is possibel to reach sum = "<<target<<" using the vector"<<endl;
            } else {
                cout<<"it is not possibel to reach target with given numbers"<<endl;
            }
            return ans;
        }
};

int getChoice(){
    int choice;
    cout<<"1 : Go from top-left to bottom-right Dynamically"<<endl;
    cout<<"2 : Go from top-left to bottom-right DFS"<<endl;
    cout<<"3 : Check how many paths go through a specific cell"<<endl;
    cout<<"4 : Create matrix again"<<endl;
    cout<<"5 : Go from Top-Left to Bottom-Right With Obstacles Dynamically"<<endl;
    cout<<"6 : Display noOfWays matrix"<<endl;
    cout<<"7 : No of ways finding From Bottom Right to TOp Left Coming back"<<endl;
    cout<<"8 : From Top Left to Right Bottom using DP (Three Drxn-down,left,right)"<<endl;
    cout<<"9 : Matrix from Top Left to Right Bottom In Right,Down & Diagonal Way"<<endl;
    cout<<"10 : From Top Left to Bottom Right while marking [y][x] when noOfWays[x][y] found"<<endl;
    cout<<"11 : Can Sum Recursion"<<endl;
    cout<<"12 : Can Sum using DP"<<endl;
    cout<<"Your choice : ";
    cin>>choice;
    return choice;
}

int main(){
    int n;
    cout<<"Enter N : ";
    cin>>n;
    DynamicProgramming DP(n);
    int choice=1;
    while(choice){
        choice=getChoice();
        if(choice==1){
            DP.gridTopLeftToBottomRightDynamic();
        } 
        else if(choice==2){
            unsigned long long totalPossiblePaths=DP.matrixNormalTraverse(0,0);
            cout<<"DFS traversal done from Top-Left to Bottom-Right"<<endl;
            cout<<"Total no of possible paths are : "<<totalPossiblePaths<<endl;
        }
        else if(choice==3){
            int checkX,checkY;
            cout<<"Enter X & Y co-ordinates : ";
            cin>>checkX>>checkY;
            if(DP.isSafe(checkX,checkY)){
                cout<<"No of paths wents from start to end are : "<<DP.noOfWays[checkX][checkY]<<endl;
            }
        }
        else if(choice==4){
            DP.createMatrix();
        }
        else if(choice==5){
            DP.matrixTopLeftToBottomRightWithObstacles();
        }
        else if(choice==6){
            DP.displayMatrix();
        }
        else if(choice==7){
            DP.matrixBottomRightToTopLeft_BFS();
        }
        else if(choice==8){
            DP.matrixThreeDrxnTopLeftToBottomRight();
        }
        else if(choice==9){
            DP.matrixTopLeftToBottomRight_RightDownDia();
        }
        else if(choice==10){
            DP.matrixTopLeftToBottomRight_invertIndexMarking();
        }
        else if(choice==11){
            DP.canSum();
        }
        else if(choice==12){
            DP.canSumDP();
        }
    }while(choice);
}

// 2399309444331282944
// 8998663545468580096