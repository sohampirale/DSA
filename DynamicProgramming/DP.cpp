#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<unordered_set>
#include<unordered_map>
#include<unistd.h>
#include<chrono>
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
        
        unordered_set<unsigned long long>visitedNums;
        unordered_set<unsigned long long>notPossible;

        double lastTime=0;
        chrono::time_point<std::chrono::high_resolution_clock> start;
        chrono::time_point<std::chrono::high_resolution_clock> end ;
        // pair<auto,auto>pair;
        // static auto start=nullptr;
        // static auto end=nullptr;;
        //unordered_map<unsigned long long,vector<vector<unsigned long long>>>noOfWaysHowSum;
        
        void startTime(){
            start=chrono::high_resolution_clock::now();
        }

        void endTime(){
            end=chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed = end - start;
            cout<<"Time required was : "<<elapsed.count()<<endl;
            if(lastTime!=0){
                cout<<"Current approach is faster than old approach by "<<lastTime/elapsed.count()<<" times"<<endl;
            } 
            lastTime=elapsed.count();
        }

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
            cnt++;
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
            // cout<<"Calculation no - "<<cnt<<endl;
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

        void ready(){
            cout<<"Ready?";
            cin.ignore();
            cin.get();
        }

        void gridTopLeftToBottomRightDynamic(){
            if(n==-1){
                // cout<<"noOfWays matrix needs to be created"<<endl;
                createMatrix();
            }
            noOfWays.assign(n,vector<unsigned long long>(n,0));
            noOfWays[targetX][targetY]=1;
            ready();
            startTime();
            dynamicTraverse(0,0);
            endTime();
            // cout<<"Saved total "<<savedCalculation<<" calculation from outside"<<endl;
            cout<<"Dynamically traversed from Top-Left to Bottom-Right"<<endl;
            cout<<"Total no of ways to reach destination are : "<<noOfWays[0][0]<<endl;
            cout<<"Total function calls = "<<cnt<<endl;
            cout<<"No. of saved calculations = "<<savedCalculation<<endl;
            savedCalculation=0;
            cnt=0;
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

            // cout<<"Curr = "<<curr<<endl;
            if(curr>target){
                notPossible.insert(curr);
                return false;
            } else if(notPossible.find(curr)!=notPossible.end()){
                savedCalculation++;
                return false;
            }
            else if(curr==target)return true;
            // cout<<"Curr = "<<curr<<endl;
            cnt++;
            // cout<<"Calculation no - "<<cnt<<endl;
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
            cout<<"Total calculations required = "<<cnt<<endl;
            cout<<"Total saved calculations dues to DP roughly : "<<savedCalculation<<endl;
            cnt=0;
            savedCalculation=0;
            return ans;
        }

        bool helper_canSum(unsigned long long curr,vector<unsigned long long>&nums,unsigned long long target){
            // cout<<"hey"<<endl;
            cnt++;
            // cout<<"Calculation no - "<<cnt<<endl;
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
            cout<<"Total calculations required = "<<cnt<<endl;
            cnt=0;
            return ans;
        }

        bool helper_canMultiplyDP(unsigned long long curr,vector<unsigned long long>&nums,unsigned long long & target){
            if(curr>target){
                notPossible.insert(curr);
                return false;
            }
            else if(notPossible.find(curr)!=notPossible.end()){
                savedCalculation++;
                return false;
            } else if(curr==target)return true;
            cnt++;
            for(int next : nums){
                if(helper_canMultiplyDP(curr*next,nums,target))return true;
            }
            notPossible.insert(curr);
            return false;
        }

        bool canMultiplyDP(){
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
            bool ans=helper_canMultiplyDP(1,nums,target);
            if(ans){
                cout<<"It is possibel to reach multiplication = "<<target<<" using the given numbers"<<endl;
            } else {
                cout<<"it is not possible to reach target with given numbers"<<endl;
            }
            cout<<"Total calculations required = "<<cnt<<endl;
            cout<<"Total saved calculations dues to DP roughly : "<<savedCalculation<<endl;
            cnt=0;
            savedCalculation=0;
            return ans;
        }

        bool helper_canMultiply(unsigned long long curr,vector<unsigned long long>&nums,unsigned long long &target){
            if(curr>target)return false;
            else if(curr==target)return true;
            // cout<<"curr = "<<curr<<endl;
            cnt++;
            for(int next:nums){
                if(helper_canMultiply(curr*next,nums,target))return true;
            }
            return false;
        }

        bool canMultiply(){
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
            bool ans=helper_canMultiply(1,nums,target);
            if(ans){
                cout<<"It is possibel to reach multiplication = "<<target<<" using the given numbers"<<endl;
            } else {
                cout<<"it is not possible to reach target with given numbers"<<endl;
            }
            cout<<"Total calculations required = "<<cnt<<endl;
            cnt=0;
            return ans;
        }

        bool helper_canSumNegNums(long long curr,vector< long long>&nums,long long & target){
            cout<<"curr = "<<curr<<endl;
            if(curr==target)return true;
            else if(curr>target||curr<(-target)||visitedNums.find(curr)!=visitedNums.end()){
                return false;
            }
            // similar to notPossible set used in other applications of canSum / howSum
            visitedNums.insert(curr);
            cnt++;
            for(int next:nums){
                // cout<<"doing +"<<next<<endl;
                if(helper_canSumNegNums(curr+next,nums,target))return true;
            }
            return false;
        }

        bool canSumNegNums(){
            long long target;
            int nNum;
            cout<<"ENter target : ";
            cin>>target;
            cout<<"How many number are in the vector : ";
            cin>>nNum;
            vector< long long>nums(nNum,0);
            cout<<"Enter "<<nNum<<" numbers of the vector"<<endl;
            for(int i=0;i<nNum;i++){
                cin>>nums[i];
            }
            bool ans=helper_canSumNegNums(0,nums,target);
            if(ans){
                cout<<"It is possibel to reach sum to : "<<target<<" using the given numbers"<<endl;
            } else {
                cout<<"it is not possible to reach target with given numbers"<<endl;
            }
            cout<<"Total calculations required = "<<cnt<<endl;
            cnt=0;
            return ans;
        }

        bool helper_canSumDecreasingFromTarget(long long curr,vector<long long>&nums){
            // cout<<"curr = "<<curr<<endl;
            if(curr==0){
                return true;
            } else if(curr<0){
                return false;
            } else if(notPossible.find(curr)!=notPossible.end()){
                savedCalculation++;
                return false;
            }
            cnt++;

            for(int next:nums){
                if(helper_canSumDecreasingFromTarget(curr-next,nums))return true;
            }

            notPossible.insert(curr);
            return false;
        }

        bool canSumDecreasingFromTarget(){
            long long target;
            int nNum;
            cout<<"ENter target : ";
            cin>>target;
            cout<<"How many number are in the vector : ";
            cin>>nNum;
            vector< long long>nums(nNum,0);
            cout<<"Enter "<<nNum<<" numbers of the vector"<<endl;
            for(int i=0;i<nNum;i++){
                cin>>nums[i];
            }
            bool ans=helper_canSumDecreasingFromTarget(target,nums);
            if(ans){
                cout<<"It is possibel to reach sum to : "<<target<<" using the given numbers"<<endl;
            } else {
                cout<<"it is not possible to reach target with given numbers"<<endl;
            }
            cout<<"Total calculations required = "<<cnt<<endl;
            cout<<"No of calculations saved roughly : "<<savedCalculation<<endl;
            savedCalculation=0;
            cnt=0;
            notPossible.clear();
            return ans;
        }

        unordered_map<unsigned long long,unsigned long long>noOfPossibleWays;

        unsigned long long helper_canSumNoOfWays(unsigned long long curr,vector<unsigned long long>&nums,unsigned long long & target){
            if(curr==target)return 1;
            else if(curr>target)return 0;
            else if(noOfPossibleWays.find(curr)!=noOfPossibleWays.end()){
                savedCalculation++;
                return noOfPossibleWays[curr];
            }

            //no need because if from one num it is not possible it will automatically becomes 0
            // else if(notPossible.find(curr)!=notPossible.end())return 0;

            for(unsigned long long next : nums){
                noOfPossibleWays[curr]+=helper_canSumNoOfWays(curr+next,nums,target);
            }
            return noOfPossibleWays[curr];
        }

        bool canSumNoOfWays(){
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
            bool ans=helper_canSumNoOfWays(0,nums,target);
            if(ans){
                cout<<"It is possibel to reach sum to : "<<target<<" using the given numbers"<<endl;
            } else {
                cout<<"it is not possible to reach target with given numbers"<<endl;
            }
            cout<<"Total calculations required = "<<cnt<<endl;
            cout<<"No of calculations saved roughly : "<<savedCalculation<<endl;
            savedCalculation=0;
            cnt=0;
            
            for(auto it:noOfPossibleWays){
                if(it.second!=0){
                    cout<<"From : "<<it.first<<" in "<<it.second<<" ways"<<endl;
                }
            }
            cout<<target<<" can be reached in "<<noOfPossibleWays[0]<<" ways"<<endl;
            notPossible.clear();
            noOfPossibleWays.clear();
            return ans;
        }

        bool helper_howSumRecursion(unsigned long long curr,vector<unsigned long long>&nums,vector<unsigned long long>&ansSum,unsigned long long target){
            if(curr==target){
                ansSum.push_back(target);
                return true;
            }
            else if(curr>target)return false;
            cnt++;
            for(unsigned long long next:nums){
                if(helper_howSumRecursion(curr+next,nums,ansSum,target)){
                    ansSum.push_back(curr);
                    return true;
                }
            }
            return false;
        }

        void howSumRecursion(){
            unsigned long long target;
            int nNum;
            cout<<"ENter target : ";
            cin>>target;
            cout<<"How many number are in the vector : ";
            cin>>nNum;
            vector<unsigned long long>nums(nNum,0),ansSum;
            cout<<"Enter "<<nNum<<" numbers of the vector"<<endl;
            for(int i=0;i<nNum;i++){
                cin>>nums[i];
            }
            bool ans=helper_howSumRecursion(0,nums,ansSum,target);
            if(ans){
                cout<<"It is possible to reach sum to : "<<target<<" using the given numbers"<<endl;
                cout<<"Ans : ";
                for(unsigned long long num:ansSum)cout<<num<<",";
                cout<<endl;
            } else {
                cout<<"it is not possible to reach target with given numbers"<<endl;
            }
            cout<<"Total calculations required = "<<cnt<<endl;
            cout<<"No of calculations saved roughly : "<<savedCalculation<<endl;
            savedCalculation=0;
            cnt=0;
        
        }

        bool helper_howSumDP(unsigned long long curr,vector<unsigned long long>&nums,vector<unsigned long long>&ansSum,unsigned long long& target){            
            if(curr==target){
                ansSum.push_back(curr);
                return true;
            } else if(curr>target) return false;
            else if(notPossible.find(curr)!=notPossible.end()){
                savedCalculation++;
                return false;
            }
            cnt++;
            for(unsigned long long next: nums){
                if(helper_howSumDP(curr+next,nums,ansSum,target)){
                    ansSum.push_back(curr);
                    return true;
                }
            }
            notPossible.insert(curr);
            return false;
        }

        void howSumDP(){
            unsigned long long target;
            int nNum;
            cout<<"ENter target : ";
            cin>>target;
            cout<<"How many number are in the vector : ";
            cin>>nNum;
            vector<unsigned long long>nums(nNum,0),ansSum;
            cout<<"Enter "<<nNum<<" numbers of the vector"<<endl;
            for(int i=0;i<nNum;i++){
                cin>>nums[i];
            }
            bool ans=helper_howSumDP(0,nums,ansSum,target);
            if(ans){
                cout<<"It is possible to reach sum to : "<<target<<" using the given numbers"<<endl;
                cout<<"Ans : ";
                for(unsigned long long num:ansSum)cout<<num<<",";
                cout<<endl;
            } else {
                cout<<"it is not possible to reach target with given numbers"<<endl;
            }
            cout<<"Total calculations required = "<<cnt<<endl;
            cout<<"No of calculations saved roughly : "<<savedCalculation<<endl;
            savedCalculation=0;
            cnt=0;
            notPossible.clear();
        }

        unordered_map<unsigned long long,vector<vector<unsigned long long>>>noOfWaysHowSum;

        //this method doen't work for large targets becuase the vector<vector becomes very large
        vector<vector<unsigned long long>> helper_howSumNoOfWays(unsigned long long curr,vector<unsigned long long>&nums,unsigned long long &target){
            //no need to check if(curr==target) becuase before 
            //calling helper function noOfWaysHowSum[target]={{target}} done
            cout<<"Curr = "<<curr<<endl;
            if(curr>target){
                return {};
            }
            else if(noOfWaysHowSum.find(curr)!=noOfWaysHowSum.end()){
                // savedCalculation++;
               return noOfWaysHowSum[curr];
            }
            
            // cnt++;

            
            for(unsigned long long next:nums){
                vector<vector<unsigned long long>>temp=helper_howSumNoOfWays(curr+next,nums,target);
                if(!temp.empty()&&!temp[0].empty()){
                    for(vector<unsigned long long>&it:temp){
                        it.push_back(curr);
                        noOfWaysHowSum[curr].push_back(it);
                    }
                } else {
                    cout<<"for "<<next+curr<<" empty found"<<endl;
                }
            }
            return noOfWaysHowSum[curr];
        }

        //Shows all possible ways to reach target via all numbers 
        void howSumNoOfWays(){
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
            cout<<"Lets start"<<endl;
            noOfWaysHowSum[target]={{target}};

            if(!helper_howSumNoOfWays(0,nums,target).empty()){
                cout<<"It is possible to reach sum to : "<<target<<" using the given numbers"<<endl;
                cout<<"Let's see from each no how many ways we can reach "<<target<<endl;
                for(auto it:noOfWaysHowSum){
                    if(!it.second.empty()){
                        cout<<"From "<<it.first<<endl;
                        for(unsigned long long i=0;i<it.second.size();i++){
                            for(unsigned long long j=0;j<it.second[i].size();j++){
                                cout<<it.second[i][j]<<",";
                            }
                            cout<<endl;
                        }
                    }
                }
            } else {
                cout<<"it is not possible to reach target with given numbers"<<endl;
            }
            cout<<"Total calculations required = "<<cnt<<endl;
            cout<<"No of calculations saved roughly : "<<savedCalculation<<endl;
            savedCalculation=0;
            cnt=0;
            noOfWaysHowSum.clear();
        }

        bool helper_howSumNoOfWaysBoolTry(unsigned long long curr,vector<unsigned long long>&nums,unsigned long long&target){
            if(curr>target)return false;
            else if(noOfWaysHowSum.find(curr)!=noOfWaysHowSum.end()){
                savedCalculation++;
                return true;
            }
            cnt++;
            bool found=false;
            for(unsigned long long& next:nums){
                if(helper_howSumNoOfWaysBoolTry(curr+next,nums,target)){
                    found=true;
                    for(auto it:noOfWaysHowSum[curr+next]){
                        it.push_back(curr);
                        noOfWaysHowSum[curr].push_back(it);
                    }
                }
            }
            if(found)return true;
            else return false;
        }

        // this also fails for big target as you can see with option '17' LARGE no of ways are possible to reach target so it takes large computing power to compute subsequent number vector<vector as we come up from bottom from trees
        void howSumNoOfWaysBoolTry(){
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
            cout<<"Lets start"<<endl;
            noOfWaysHowSum[target]={{target}};

            if(helper_howSumNoOfWaysBoolTry(0,nums,target)){
                cout<<"It is possible to reach sum to : "<<target<<" using the given numbers"<<endl;
                cout<<"Let's see from each no how many ways we can reach "<<target<<endl;
                // for(auto it:noOfWaysHowSum){
                //     if(!it.second.empty()){
                //         cout<<"From "<<it.first<<endl;
                //         for(unsigned long long i=0;i<it.second.size();i++){
                //             for(unsigned long long j=0;j<it.second[i].size();j++){
                //                 cout<<it.second[i][j]<<",";
                //             }
                //             cout<<endl;
                //         }
                //     }
                // }
            } else {
                cout<<"it is not possible to reach target with given numbers"<<endl;
            }
            cout<<"Total calculations required = "<<cnt<<endl;
            cout<<"No of calculations saved roughly : "<<savedCalculation<<endl;
            savedCalculation=0;
            cnt=0;
            noOfWaysHowSum.clear();
        }

        unordered_map<unsigned long long,vector<unsigned long long>>bestSumMap;

        bool helper_bestSum(unsigned long long curr,vector<unsigned long long>&nums,unsigned long long &target){
            if(bestSumMap.find(curr)!=bestSumMap.end()){
                savedCalculation++;
                return true;
            } else if(curr>target){
                return false;
            }
            cnt++;
            int minSize=INT_MAX;
            bool found=false;
            const auto it=nullptr;
            vector<unsigned long long>minSizeArr;
            for(unsigned long long& next:nums){
                if(helper_bestSum(curr+next,nums,target)){
                    if(!bestSumMap[curr+next].empty()){
                        found=true;
                        if(bestSumMap[curr+next].size()<minSize){
                            minSizeArr=bestSumMap[curr+next];
                            minSize=minSizeArr.size();
                        }
                    }
                }
            }
            if(!minSizeArr.empty()){
                minSizeArr.push_back(curr);
                bestSumMap[curr]=minSizeArr;
            }
            return found;
        }

        void bestSum(){
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
            cout<<"Lets start"<<endl;
            bestSumMap[target]={target};
            ready();
            startTime();
            bool ans=helper_bestSum(0,nums,target);
            endTime();
            if(ans){
                cout<<"It is possible to reach sum to : "<<target<<" using the given numbers"<<endl;
                cout<<"Best Path from 0-"<<target<<" is : ";
                for(int var:bestSumMap[0]){
                    cout<<var<<" ";
                }
                cout<<endl;
            } else {
                cout<<"it is not possible to reach target with given numbers"<<endl;
            }
            cout<<"Total calculations required = "<<cnt<<endl;
            cout<<"No of calculations saved roughly : "<<savedCalculation<<endl;
            savedCalculation=0;
            cnt=0;
            noOfWaysHowSum.clear();
            bestSumMap.clear();
        }
        
        unordered_map<string,int>countConstructMap;
        string finalStr;
        int size;

        //  finalStr - azzzzzzzzzzzza
        /// [z,b,a]

        // azzccddeeffgghhjjkkllmmnnzza
        //[ w x y t z n m l k j h g f e d c a d]
        
        bool helper_canConstructReursive(string curr,vector<string>&dict){
            if(curr==finalStr){
                return true;
            } else if(curr.size()>=finalStr.size()){
                return false;
            }
            // cout<<"cnt = "<<cnt<<endl;
            cnt++;
            for(string str:dict){
                if(helper_canConstructReursive(curr+str,dict))return true;
            }
            return false;
        }

        void canConstructRecursive(){
             int n;
            cout<<"Enter final string : ";
            cin>>this->finalStr;
            cout<<"How many strings are present in the dictionary : ";
            cin>>n;
            vector<string>dict(n);
            cout<<"Enter "<<n<<" string : "<<endl;
            for(int i=0;i<n;i++){
                cin>>dict[i];
            }
            bool possible=helper_canConstructReursive("",dict);
            if(possible){
                cout<<"it is possible to construct "<<finalStr<<" using given dictionary of words"<<endl;
            } else {
                cout<<"It is not possible to construct "<<finalStr<<" from given dictionary"<<endl;
            }
            cout<<"No of Function calls made : "<<cnt<<endl;
            cnt=0;
        }

        unordered_set<string>notPossiblecanConstruct;

        //in this DP used not checked-> whether curr is substring in finalStr or not and also the index at which the substring is present
        bool helper_canConstructDP1(string curr,vector<string>&dict){
            if(curr==finalStr)return true;
            else if(notPossiblecanConstruct.find(curr)!=notPossiblecanConstruct.end()){
                savedCalculation++;
                return false;
            } else if(curr.size()>=finalStr.size()){
                return false;
            }
            cnt++;
            for(string str:dict){
                if(helper_canConstructDP1(curr+str,dict)){
                    return true;
                }
            }
            notPossiblecanConstruct.insert(curr);
            return false;
        }

        void canConstructDP1(){
            int n;
            cout<<"Enter final string : ";
            cin>>this->finalStr;
            cout<<"How many strings are present in the dictionary : ";
            cin>>n;
            vector<string>dict(n);
            cout<<"Enter "<<n<<" string : "<<endl;
            for(int i=0;i<n;i++){
                cin>>dict[i];
            }
            countConstructMap[finalStr]=1;
            bool  possible=helper_canConstructDP1("",dict);
            if(possible){
                cout<<"it is possible to construct "<<finalStr<<" from given dictionary of words"<<endl;
            } else {
                cout<<"It is not possible to construct "<<finalStr<<" from given dictionary"<<endl;
            }
            cout<<"No of function calls made : "<<cnt<<endl;
            cout<<"Saved Calculations  : "<<savedCalculation<<endl;
            cnt=0;
            savedCalculation=0;
            notPossiblecanConstruct.clear();
        }
       
        unsigned long long notSubstringsavedCalculations=0;
        unsigned long long substringPresentButNotAtStart=0;

        bool helper_canConstructDP2(string curr,vector<string>&dict){
            if(curr==finalStr)return true;
            else if(notPossiblecanConstruct.find(curr)!=notPossiblecanConstruct.end()){
                savedCalculation++;
                return false;
            } else if(finalStr.find(curr,0)==string::npos){
                notSubstringsavedCalculations++;
                return false;
            }
            cnt++;
            for(string str:dict){
                if(helper_canConstructDP2(curr+str,dict))return true;
            }
            notPossiblecanConstruct.insert(curr);
            return false;
        }

        void canConstructDP2(){
            notSubstringsavedCalculations=0;
            int n;
            cout<<"Enter final string : ";
            cin>>this->finalStr;
            cout<<"How many strings are present in the dictionary : ";
            cin>>n;
            vector<string>dict(n);
            cout<<"Enter "<<n<<" string : "<<endl;
            for(int i=0;i<n;i++){
                cin>>dict[i];
            }
            countConstructMap[finalStr]=1;
            bool  possible=helper_canConstructDP2("",dict);
            if(possible){
                cout<<"it is possible to construct "<<finalStr<<" from given dictionary of words"<<endl;
            } else {
                cout<<"It is not possible to construct "<<finalStr<<" from given dictionary"<<endl;
            }
            cout<<"No of function calls made : "<<cnt<<endl;
            cout<<"Saved Calculations  : "<<savedCalculation<<endl;
            cout<<"no of calculations saved because curr is nto a substring of finalStr = "<<notSubstringsavedCalculations<<endl;
            cnt=0;
            savedCalculation=0;
            notSubstringsavedCalculations=0;
            notPossiblecanConstruct.clear();
        }

        bool helper_canConstructDP3(string curr,vector<string>&dict){
            if(curr==finalStr)return true;
            else if(notPossiblecanConstruct.find(curr)!=notPossiblecanConstruct.end()){
                savedCalculation++;
                return false;
            } else if(finalStr.find(curr,0)==string::npos){
                notSubstringsavedCalculations++;
                return false;
            } else if(finalStr.find(curr,0)!=0){
                substringPresentButNotAtStart++;
                return false;
            }
           
            cnt++;
            for(string str:dict){
                if(helper_canConstructDP3(curr+str,dict))return true;
            }
            notPossiblecanConstruct.insert(curr);
            return false;
        }

        void canConstructDP3(){
            notSubstringsavedCalculations=0;
            int n;
            cout<<"Enter final string : ";
            cin>>this->finalStr;
            cout<<"How many strings are present in the dictionary : ";
            cin>>n;
            vector<string>dict(n);
            cout<<"Enter "<<n<<" string : "<<endl;
            for(int i=0;i<n;i++){
                cin>>dict[i];
            }
            countConstructMap[finalStr]=1;
            bool  possible=helper_canConstructDP3("",dict);
            if(possible){
                cout<<"it is possible to construct "<<finalStr<<" from given dictionary of words"<<endl;
            } else {
                cout<<"It is not possible to construct "<<finalStr<<" from given dictionary"<<endl;
            }
            cout<<"No of function calls made : "<<cnt<<endl;
            cout<<"Saved Calculations  : "<<savedCalculation<<endl;
            cout<<"no of calculations saved because curr is nto a substring of finalStr = "<<notSubstringsavedCalculations<<endl;
            cout<<"No of calculations saved because substring was present but not at start = "<<substringPresentButNotAtStart<<endl;
            cnt=0;
            savedCalculation=0;
            notSubstringsavedCalculations=0;
            substringPresentButNotAtStart=0;
            notPossiblecanConstruct.clear();
        }

        int helper_countConstruct(string curr,vector<string>&dict){
            if(countConstructMap.find(curr)!=countConstructMap.end()){
                return countConstructMap[curr];
            } else if(curr.size()>=finalStr.size()||finalStr.find(curr)==string::npos){
                return countConstructMap[curr];
            }
            int count=0;
            for(string str:dict){
                count+=helper_countConstruct(curr+str,dict);
            }
            countConstructMap[curr]=count;
            return count; 
        }

        int countConstruct(){
            int n;
            cout<<"Enter final string : ";
            cin>>this->finalStr;
            cout<<"How many strings are present in the dictionary : ";
            cin>>n;
            vector<string>dict(n);
            cout<<"Enter "<<n<<" string : "<<endl;
            for(int i=0;i<n;i++){
                cin>>dict[i];
            }
            countConstructMap[finalStr]=1;
            int count=helper_countConstruct("",dict);
            if(count!=0){
                cout<<"No of ways to construct "<<finalStr<<" are "<<count<<endl;
            } else {
                cout<<"It is not possible to construct "<<finalStr<<" from given dictionary"<<endl;
            }
            countConstructMap.clear();
            return count;
        }

        unordered_set<string>howConstructMap_notPossible;

        bool helper_howConstruct(string curr,vector<string>&dict,vector<string>&ans){
            if(curr==finalStr)return true;
            else if(curr.size()>=finalStr.size()||howConstructMap_notPossible.find(curr)!=howConstructMap_notPossible.end()){
                return false;
            }

            for(string str:dict){
                if(helper_howConstruct(curr+str,dict,ans)){
                    ans.push_back(str);
                    return true;
                }
            }
            howConstructMap_notPossible.insert(curr);
            return false;
        }

        void howConstruct(){
            int n;
            cout<<"Enter final string : ";
            cin>>this->finalStr;
            cout<<"How many strings are present in the dictionary : ";
            cin>>n;
            vector<string>dict(n),ans;
            cout<<"Enter "<<n<<" string : "<<endl;
            for(int i=0;i<n;i++){
                cin>>dict[i];
            }
            bool possible=helper_howConstruct("",dict,ans);
            if(possible){
                cout<<"it is possible to construct "<<finalStr<<" using given dictionary of words"<<endl;
                for(string str:ans){
                    cout<<str<<",";
                }
                cout<<endl;
            } else {
                cout<<"It is not possible to construct "<<finalStr<<" from given dictionary"<<endl;
            }
            howConstructMap_notPossible.clear();
        }

        unordered_map<string,vector<vector<string>>>allConstructsMap;

        vector<vector<string>> helper_allConstructs(string curr,vector<string>&dict){
            // cout<<"curr = "<<curr<<endl;
            if(allConstructsMap.find(curr)!=allConstructsMap.end()){
                savedCalculation++;
                return allConstructsMap[curr];
            } else if(curr.size()>=size){
                return allConstructsMap[curr];
            } else if(finalStr.find(curr)==string::npos){
                // notSubstringsavedCalculations++;
                allConstructsMap[curr];
                return allConstructsMap[curr];
            } else if(finalStr.find(curr,0)!=0){
                substringPresentButNotAtStart++;
                // allConstructsMap[curr];
                return allConstructsMap[curr];
            } else cnt++;

            for(string str:dict){
                vector<vector<string>>temp=helper_allConstructs(curr+str,dict);
                if(!temp.empty()){
                    for(vector<string>& it:temp){
                        it.push_back(str);
                        allConstructsMap[curr].push_back(it);
                    }
                }
            }
            return allConstructsMap[curr];
        }

        void allConstructs(){
            int n;
            cout<<"Enter final string : ";
            cin>>this->finalStr;
            this->size=this->finalStr.size();
            cout<<"How many strings are present in the dictionary : ";
            cin>>n;
            vector<string>dict(n);
            cout<<"Enter "<<n<<" string : "<<endl;
            for(int i=0;i<n;i++){
                cin>>dict[i];
            }
            
            allConstructsMap[finalStr]={{}};
            ready();
            startTime();
            vector<vector<string>>ans=helper_allConstructs("",dict);
            endTime();
            if(!ans.empty()){
                cout<<"it is possible to construct "<<finalStr<<" using given dictionary of words in "<<allConstructsMap[""].size()<<" ways"<<endl;
                bool ask;
                cout<<"DO you want to print all possible ways : ";
                cin>>ask;
                if(ask){
                    for(vector<string> str:allConstructsMap[""]){
                        cout<<"[";
                        for(string str2:str){
                            cout<<str2<<",";
                        }
                        cout<<"]"<<endl;
                    }
                }
            } else {
                cout<<"It is not possible to construct "<<finalStr<<" from given dictionary"<<endl;
            }
            cout<<"Total function calls perfomed : "<<cnt<<endl;
            cout<<"No of recursive calls avoided rouhgly : "<<savedCalculation<<endl;
            cout<<"No of calculations saved due to formed string is nto a substring of the finalStr = "<<notSubstringsavedCalculations<<endl;
            cout<<"no of calculatiosn saved becuase substring is present in finalStr but not at start = "<<substringPresentButNotAtStart<<endl;
            savedCalculation=0;
            substringPresentButNotAtStart=0;
            notSubstringsavedCalculations=0;
            cnt=0;
            allConstructsMap.clear();
        }

        unsigned long long helper_fiboTabulation(unsigned long long num){
            vector<unsigned long long>vec(num+1,0);
            vec[1]=1;
            for(int i=1;i<num;i++){
                vec[i+1]+=vec[i];
                if(i!=num-1)vec[i+2]+=vec[i];
            }
            return vec.back();
        }

        void fiboTabulation(){
            unsigned long long num=1;
            while(num){
                cout<<"Enter n : ";
                cin>>num;
                cout<<"Fibonachi of "<<num<<" is : "<<helper_fiboTabulation(num)<<endl;
            }
        }

        unsigned long long helper_fiboDPWithoutArray(unsigned long long num){
            unsigned long long first=1,second=0,ans=0;
            for(int i=2;i<=num;i++){
                ans=first+second;
                second=first;
                first=ans;
            }
            return ans;
        }

        void fiboDPWithoutArray(){
            unsigned long long num=1;
            while(num){
                cout<<"Enter n : ";
                cin>>num;
                cout<<"Fibonachi of "<<num<<" is : "<<helper_fiboDPWithoutArray(num)<<endl;
            }
        }

        bool isSafeGridTraveller(int x,int y,vector<vector<int>>&matrix){
            return (x>=0&&y>=0);
        }
       
        unsigned long long helper_gridTraverllerTabulationReverse(int n){
            vector<vector<int>>matrix(n,vector<int>(n,0));
            vector<vector<bool>>visited(n,vector<bool>(n,false));
            queue<pair<int,int>>loc;
            matrix[n-1][n-1]=1;
            loc.push({n-1,n-1});
            while(!loc.empty()){
                int x=loc.front().first;
                int y=loc.front().second;
                loc.pop();
                if(visited[x][y])continue;
                else visited[x][y]=true;
                for(auto it:leftNup){
                    int nextX=x+it.first;
                    int nextY=y+it.second;
                    if(isSafeGridTraveller(nextX,nextY,matrix)){
                        matrix[nextX][nextY]+=matrix[x][y];
                        loc.push({nextX,nextY});
                    }
                }
            }
            return matrix[0][0];
        }

        void gridTraverllerTabulationReverse(){
            int n;
            cout<<"ENter size of matrix : ";
            cin>>n;
            cout<<" no of ways to reach Bottom-Right from Top-Left are : "<<helper_gridTraverllerTabulationReverse(n)<<endl;
        }

        bool isSafeGridTravellerTabulation(int x,int y,vector<vector<int>>&matrix){
            return (x<matrix.size()&&y<matrix[x].size());
        }

        //this can also be used for travelling the grid with obstacles
        unsigned long long helper_gridTravellerTabulation(int n,vector<vector<unsigned long long>>&matrix){
            if(n==1||n==0)return n;
            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[i].size();j++){
                    // for(auto it:downNright){
                    //     int nextX=i+it.first;
                    //     int nextY=j+it.second;
                    //     if(isSafeGridTravellerTabulation(nextX,nextY,matrix)){
                    //         matrix[nextX][nextY]+=matrix[i][j];
                    //     }
                    // }
                    if(j!=matrix[i].size()-1){
                        matrix[i][j+1]+=matrix[i][j];
                    }
                    if(i!=matrix.size()-1){
                        matrix[i+1][j]+=matrix[i][j];
                    }
                }
            }
            return matrix[n][n];
        }

        void gridTraverllerTabulation(){
            unsigned long long n;
            cout<<"ENter N : ";
            cin>>n;
            vector<vector<unsigned long long>>matrix(n+1,vector<unsigned long long>(n+1,0));
            matrix[1][1]=1;
            cout<<"Ready?"<<endl;
            cin.ignore();
            cin.get();
            cout<<"No of ways to go from Top-Left to Bottom-Right are = "<<helper_gridTravellerTabulation(n,matrix)<<endl;
        }

        vector<pair<int,pair<int,int>>>cubeDrxn={{1,{0,0}},{0,{1,0}},{0,{0,1}}};

        bool isSafeCubeTraveller(int x,int y,int z,int& size){
            return (x<size&&y<size&&z<size);
        }

        vector<vector<vector<unsigned long long>>>cube,memoizationCube;
        vector<vector<vector<vector<unsigned long long>>>>memoizationCube4D;
        vector<vector<vector<vector<vector<unsigned long long>>>>>memoizationCube5D;
        vector<vector<vector<vector<vector<vector<unsigned long long>>>>>>memoizationCube6D;

        int testVar=0;
        void helper_cubeTraveller(int x,int y,int z,int& target){
            // cout<<x<<","<<y<<","<<z<<endl;
            if(x==target&&y==target&&z==target){
                // cout<<"Condition hit"<<endl;
                cnt++;
                return;
            }

            if(x!=target){
                helper_cubeTraveller(x+1,y,z,target);
            }
            //  else {
            //     cout<<"x hit"<<endl;
            // }

            if(y!=target){
                helper_cubeTraveller(x,y+1,z,target);  
            }
            // else {
            //     cout<<"y hit"<<endl;
            // }

            
            if(z!=target){
                helper_cubeTraveller(x,y,z+1,target);  
            }
            // else {
            //     cout<<"z hit"<<endl;
            // }
            // for(auto it:cubeDrxn){

            //     int nextX=x+it.first;
            //     int nextY=y+it.second.first;
            //     int nextZ=z+it.second.second;
            //     if(isSafeCubeTraveller(nextX,nextY,nextY,size)){
            //         helper_cubeTraveller(nextX,nextY,nextZ,size,cube);
            //     }
            // }
        }

        void cubeTraveller(){
            int n;
            cout<<"Enter n : ";
            cin>>n;
            //there is no need in actual of the cube
            // cube.resize(n,vector<vector<unsigned long long>>(n,vector<unsigned long long>(n,0)));

            int target=n-1;
            cout<<"Cube created"<<endl;
            cnt=0;
            cout<<"Ready?";
            cin.ignore();
            cin.get();
            helper_cubeTraveller(0,0,0,target);
            cout<<"Traversal complete"<<endl;
            cout<<"NO of ways to reach from (0,0,0) to ("<<n-1<<","<<n-1<<","<<n-1<<") are : "<<cnt<<endl;
            cnt=0;
            // cube.clear();
            memoizationCube.clear();
        }

        unsigned long long helper_cubeTravellerDP(int x,int y,int z,int& target){
            if(memoizationCube[x][y][z]!=0)return memoizationCube[x][y][z];
            unsigned long long temp=0;
            if(x!=target){
                temp+=helper_cubeTravellerDP(x+1,y,z,target);
            }

            if(y!=target){
                temp+=helper_cubeTravellerDP(x,y+1,z,target);
            }
        
            if(z!=target){
                temp+=helper_cubeTravellerDP(x,y,z+1,target);
            }

            memoizationCube[x][y][z]=temp; //not using temp will give exact output but will more computation like very minor maybe
            return temp;
        }

        void cubeTravellerDP(){
            int n;
            cout<<"Enter n : ";
            cin>>n;

            // cube.resize(n,vector<vector<unsigned long long>>(n,vector<unsigned long long>(n,0)));
            memoizationCube.resize(n,vector<vector<unsigned long long>>(n,vector<unsigned long long>(n,0)));
            cout<<"Cube created"<<endl;

            int target=n-1;

            memoizationCube[target][target][target]=1;
            cout<<"Ready?";
            cin.ignore();
            cin.get();
            unsigned long long totalPossibleWays=helper_cubeTravellerDP(0,0,0,target);
            cout<<"Traversal complete"<<endl;
            cout<<"NO of ways to reach from (0,0,0) to ("<<n-1<<","<<n-1<<","<<n-1<<") are : "<<totalPossibleWays<<endl;
            cout<<"x 1 step : "<<memoizationCube[1][0][0]<<endl;
            cout<<"y 1 step : "<<memoizationCube[0][1][0]<<endl;
            cout<<"z 1 step : "<<memoizationCube[0][0][1]<<endl;
            // cube.clear();
            memoizationCube.clear();
        }

        unsigned long long helper_cubeTraveller4D(int x,int y,int z,int d4,int&target){
            if(memoizationCube4D[x][y][z][d4]!=0){
                return memoizationCube4D[x][y][z][d4];
            } 

            unsigned long long ret=0;
            if(x!=target){
                ret+=helper_cubeTraveller4D(x+1,y,z,d4,target);
            }

            if(y!=target){
                ret+=helper_cubeTraveller4D(x,y+1,z,d4,target);
            }

            if(z!=target){
                ret+=helper_cubeTraveller4D(x,y,z+1,d4,target);
            }

            if(d4!=target){
                ret+=helper_cubeTraveller4D(x,y,x,d4+1,target);
            }

            memoizationCube4D[x][y][z][d4]=ret;
            return ret;
        }

        void cubeTraveller4D(){
            int n;
            cout<<"Enter n :";
            cin>>n;
            int target=n-1;
            memoizationCube4D.resize(n,vector<vector<vector<unsigned long long>>>(n,vector<vector<unsigned long long>>(n,vector<unsigned long long>(n,0))));
            memoizationCube4D[target][target][target][target]=1;
            cout<<"Cube in 4D is created"<<endl;

            cout<<"Target is : ("<<target<<","<<target<<","<<target<<","<<target<<")"<<endl;
            unsigned long long totalPossibleWays=helper_cubeTraveller4D(0,0,0,0,target);
            if(totalPossibleWays!=0){
                cout<<"It is possible to travel from (0,0,0,0) to ("<<target<<","<<target<<","<<target<<","<<target<<") in : "<<totalPossibleWays<<" ways"<<endl;
                cout<<"x 1 step : "<<memoizationCube4D[1][0][0][0]<<endl;
                cout<<"y 1 step : "<<memoizationCube4D[0][1][0][0]<<endl;
                cout<<"z 1 step : "<<memoizationCube4D[0][0][1][0]<<endl;
                cout<<"d4 1 step : "<<memoizationCube4D[0][0][0][1]<<endl;
            } else {
                cout<<"It is not possibel to travel from (0,0,0,0) to ("<<target<<","<<target<<","<<target<<","<<target<<")"<<endl;
            }
            printPossibleWays4DCube(target);
            memoizationCube4D.clear();
        }

        unsigned long long helper_cubeTraveller5D(int x,int y,int z,int d4,int d5,int& target){
            if(memoizationCube5D[x][y][z][d4][d5]!=0){
                return memoizationCube5D[x][y][z][d4][d5];
            }
            unsigned long long ret=0;

            if(x!=target){
                ret+=helper_cubeTraveller5D(x+1,y,z,d4,d5,target);
            }

            if(y!=target){
                ret+=helper_cubeTraveller5D(x,y+1,z,d4,d5,target);
            }

            if(z!=target){
                ret+=helper_cubeTraveller5D(x,y,z+1,d4,d5,target);
            }

            if(d4!=target){
                ret+=helper_cubeTraveller5D(x,y,z,d4+1,d5,target);
            }

            if(d5!=target){
                ret+=helper_cubeTraveller5D(x,y,z,d4,d5+1,target);
            }
            memoizationCube5D[x][y][z][d4][d5]=ret;
            // cout<<"ret = "<<ret<<endl;
            return ret;
        }

        void printPossibleWays4DCube(int& target){
            int totalCells=0;
            for(int i=0;i<=target;i++){
                for(int j=0;j<=target;j++){
                    for(int k=0;k<=target;k++){
                        for(int l=0;l<=target;l++){
                            cout<<"from ("<<i<<","<<j<<","<<k<<","<<l<<") there are : "<<memoizationCube4D[i][j][k][l]<<" ways"<<endl;
                            totalCells++;
                        }
                    }
                }
            }
            cout<<"Total cells present are : "<<totalCells<<endl;
        }

        void printPossibleWays5DCube(int& target){
            int totalCells=0;

            for(int i=0;i<=target;i++){
                for(int j=0;j<=target;j++){
                    for(int k=0;k<=target;k++){
                        for(int l=0;l<=target;l++){
                            for(int m=0;m<=target;m++){
                                cout<<"from ("<<i<<","<<j<<","<<k<<","<<l<<","<<m<<") there are : "<<memoizationCube5D[i][j][k][l][m]<<" ways"<<endl;
                                totalCells++;
                            }
                        }
                    }
                }
            }
            cout<<"Total cells are : "<<totalCells<<endl;
        }

        void cubeTraveller5D(){
            int n;
            cout<<"Enter n :";
            cin>>n;
            int target=n-1;
            memoizationCube5D.resize(n,vector<vector<vector<vector<unsigned long long>>>>(n,vector<vector<vector<unsigned long long>>>(n,vector<vector<unsigned long long>>(n,vector<unsigned long long>(n,0)))));
            memoizationCube5D[target][target][target][target][target]=1;
            cout<<"Cube in 5D is created"<<endl;

            cout<<"Target is : ("<<target<<","<<target<<","<<target<<","<<target<<","<<target<<")"<<endl;

            unsigned long long totalPossibleWays=helper_cubeTraveller5D(0,0,0,0,0,target);
            if(totalPossibleWays!=0){
                cout<<"It is possible to travel from (0,0,0,0,0) to ("<<target<<","<<target<<","<<target<<","<<target<<","<<target<<") in : "<<totalPossibleWays<<" ways"<<endl;
                cout<<"x 1 step : "<<memoizationCube5D[1][0][0][0][0]<<endl;
                cout<<"y 1 step : "<<memoizationCube5D[0][1][0][0][0]<<endl;
                cout<<"z 1 step : "<<memoizationCube5D[0][0][1][0][0]<<endl;
                cout<<"d4 1 step : "<<memoizationCube5D[0][0][0][1][0]<<endl;
                cout<<"d5 1 step : "<<memoizationCube5D[0][0][0][0][1]<<endl;

            } else {
                cout<<"It is not possibel to travel from (0,0,0,0,0) to ("<<target<<","<<target<<","<<target<<","<<target<<","<<target<<")"<<endl;
            }
            printPossibleWays5DCube(target);
            memoizationCube5D.clear();
        }

        unsigned long long helper_cubeTraveller6D(int x,int y,int z,int d4,int d5,int d6,int&target){
            if(memoizationCube6D[x][y][z][d4][d5][d6]!=0){
                return memoizationCube6D[x][y][z][d4][d5][d6];
            }
            unsigned long long ret=0;
            if(x!=target){
                ret+=helper_cubeTraveller6D(x+1,y,z,d4,d5,d6,target);
            }

            if(y!=target){
                ret+=helper_cubeTraveller6D(x,y+1,z,d4,d5,d6,target);
            }

            if(z!=target){
                ret+=helper_cubeTraveller6D(x,y,z+1,d4,d5,d6,target);
            }

            if(d4!=target){
                ret+=helper_cubeTraveller6D(x,y,z,d4+1,d5,d6,target);
            }

            if(d5!=target){
                ret+=helper_cubeTraveller6D(x,y,z,d4,d5+1,d6,target);
            }

            if(d6!=target){
                ret+=helper_cubeTraveller6D(x,y,z,d4,d5,d6+1,target);
            }

            memoizationCube6D[x][y][z][d4][d5][d6]=ret;
            return ret;
        }

        void cubeTraveller6D(){
            int n;
            cout<<"Enter n :";
            cin>>n;
            int target=n-1;

            memoizationCube6D.resize(n,vector<vector<vector<vector<vector<unsigned long long>>>>>(n,vector<vector<vector<vector<unsigned long long>>>>(n,vector<vector<vector<unsigned long long>>>(n,vector<vector<unsigned long long>>(n,vector<unsigned long long>(n,0))))));
            memoizationCube6D[target][target][target][target][target][target]=1;

            cout<<"Cube in 6D is created"<<endl;

            cout<<"Target is : ("<<target<<","<<target<<","<<target<<","<<target<<","<<target<<","<<target<<")"<<endl;

            unsigned long long totalPossibleWays=helper_cubeTraveller6D(0,0,0,0,0,0,target);
            if(totalPossibleWays!=0){
                cout<<"It is possible to travel from (0,0,0,0,0,0) to ("<<target<<","<<target<<","<<target<<","<<target<<","<<target<<","<<target<<") in : "<<totalPossibleWays<<" ways"<<endl;
                cout<<"x 1 step : "<<memoizationCube6D[1][0][0][0][0][0]<<endl;
                cout<<"y 1 step : "<<memoizationCube6D[0][1][0][0][0][0]<<endl;
                cout<<"z 1 step : "<<memoizationCube6D[0][0][1][0][0][0]<<endl;
                cout<<"d4 1 step : "<<memoizationCube6D[0][0][0][1][0][0]<<endl;
                cout<<"d5 1 step : "<<memoizationCube6D[0][0][0][0][1][0]<<endl;
                cout<<"d6 1 step : "<<memoizationCube6D[0][0][0][0][0][1]<<endl;
            } else {
                cout<<"It is not possibel to travel from (0,0,0,0,0) to ("<<target<<","<<target<<","<<target<<","<<target<<","<<target<<")"<<endl;
            }
            memoizationCube6D.clear();
        }

        bool helper_canSumTabulation(unsigned long long target,vector<unsigned long long>&nums){
            queue<int>loc;
            for(int num:nums)loc.push(num);
            while(!loc.empty()){
                int curr=loc.front();
                if(curr*2==target)return true;
                loc.pop();
                queue<int>loc2;
                while(!loc.empty()){
                    int secondNum=loc.front();
                    loc.pop();
                    loc2.push(secondNum);
                    int next=curr+secondNum;
                    if(next==target)return true;
                    else if(next>target)continue;
                    loc.push(next);
                }
                while(!loc2.empty()){
                    loc.push(loc2.front());
                    loc2.pop();
                }
            }
            return false;
        }
        
        //slow -not DP
        void canSumTabulation(){
            unsigned long long target;
            int nNum;
            cout<<"Enter target : ";
            cin>>target;
            cout<<"How many number are in the vector : ";
            cin>>nNum;
            vector<unsigned long long>nums(nNum,0);
            cout<<"Enter "<<nNum<<" numbers of the vector"<<endl;
            for(int i=0;i<nNum;i++){
                cin>>nums[i];
            }
            cout<<"Ready?";
            cin.ignore();
            cin.get();
            if(helper_canSumTabulation(target,nums)){
                cout<<"It is possible to reach sum to : "<<target<<" using the given numbers"<<endl;
            } else {
                cout<<"it is not possible to reach target with given numbers"<<endl;
            }
            cout<<"Total calculations required = "<<cnt<<endl;
            cout<<"No of calculations saved roughly : "<<savedCalculation<<endl;
            savedCalculation=0;
            cnt=0;
            noOfWaysHowSum.clear();
        }

        unordered_set<unsigned long long>alreadyPushedCanSumTabulation;

        bool helper_canSumTabulationTry2(unsigned long long&target,vector<unsigned long long>&nums){
            stack<unsigned long long>loc;
            loc.push(0);
            while(!loc.empty()){
                int curr=loc.top();
                alreadyPushedCanSumTabulation.insert(curr);
                loc.pop();
                cnt++;
                for(unsigned long long& num:nums){
                    int next=curr+num;
                    if(next==target)return true;
                    else if(next<target ){
                        if(alreadyPushedCanSumTabulation.find(next)==alreadyPushedCanSumTabulation.end()){
                            loc.push(next);
                        } else savedCalculation++;
                    }
                }
            }
            return false;
        }

        void canSumTabulationTry2(){
            unsigned long long target;
            int nNum;
            cout<<"Enter target : ";
            cin>>target;
            cout<<"How many number are in the vector : ";
            cin>>nNum;
            vector<unsigned long long>nums(nNum,0);
            cout<<"Enter "<<nNum<<" numbers of the vector"<<endl;
            for(int i=0;i<nNum;i++){
                cin>>nums[i];
            }
            cout<<"Ready?";
            cin.ignore();
            cin.get();
            if(helper_canSumTabulationTry2(target,nums)){
                cout<<"It is possible to reach sum to : "<<target<<" using the given numbers"<<endl;
            } else {
                cout<<"it is not possible to reach target with given numbers"<<endl;
            }
            cout<<"Total calculations required = "<<cnt<<endl;
            cout<<"No of calculations saved roughly : "<<savedCalculation<<endl;
            savedCalculation=0;
            cnt=0;
            noOfWaysHowSum.clear();
        }

        bool helper_canSumTabulationTry3(unsigned long long & target,vector<unsigned long long>&nums,vector<bool>&possible){
            for(int i=0;i<=target;i++){
                if(possible[i]){
                    for(int num:nums){
                        cnt++;
                        int next=i+num;
                        if(next==target)return true;
                        else if(next<target){
                            possible[next]=true;
                        }
                    }
                }
            }
            return false;
        }

        //faster than Try2 as well as canSum DP Memoization
        void canSumTabulationTry3(){
            unsigned long long target;
            int nNum;
            cout<<"Enter target : ";
            cin>>target;
            vector<bool>possible(target+1,false);
            possible[0]=true;
            cout<<"How many number are in the vector : ";
            cin>>nNum;
            vector<unsigned long long>nums(nNum,0);
            cout<<"Enter "<<nNum<<" numbers of the vector"<<endl;
            for(int i=0;i<nNum;i++){
                cin>>nums[i];
            }
            //19999998 79999920
            cout<<"Ready?";
            cin.ignore();
            cin.get();
            if(helper_canSumTabulationTry3(target,nums,possible)){
                cout<<"It is possible to reach sum to : "<<target<<" using the given numbers"<<endl;
            } else {
                cout<<"it is not possible to reach target with given numbers"<<endl;
            }
            cout<<"Total calculations required = "<<cnt<<endl;
            cout<<"No of calculations saved roughly : "<<savedCalculation<<endl;
            savedCalculation=0;
            cnt=0;
            noOfWaysHowSum.clear();
        }

        void displayGivenMatrix(vector<vector<int>>&matrix){
            cout<<"Matrix is : "<<endl;
            for(int i=0;i<matrix.size();i++){
                if(!matrix[i].empty()){
                    for(int j=0;j<matrix[i].size();j++){
                        cout<<matrix[i][j]<<", ";
                    }
                } else {
                    cout<<"Empty";
                }
                cout<<endl;
            }
        }

        vector<int> helper_bestSumTabulationTry1(int& target,vector<int>&nums){
            vector<vector<int>>ways(target+1,vector<int>(0));
            for(int var:nums){
                if(var<target){
                    ways[var]={var};
                }
            }

            // cout<<"before starting the traversal "<<endl;
            // displayGivenMatrix(ways);
            // cout<<"Starting the traversal"<<endl;

            for(int i=0;i<=target;i++){
                // cout<<ways[i].size()<<endl;
                if(ways[i].size()!=0){
                    for(int var:nums){
                        int next=i+var;
                        if(next>target)continue;
                        else if(next==target){
                            vector<int>temp=ways[i];
                            temp.push_back(var);
                            return temp;
                        }
                        if(ways[next].empty()){
                            ways[next]=ways[i];
                            ways[next].push_back(var);
                        } else if(ways[next].size()>ways[i].size()+1){
                            ways[next]=ways[i];
                            ways[next].push_back(var);
                        } else {
                            // cout<<"ways["<<next<<"].size() = "<<ways[next].size()<<endl;
                        }
                    }
                }
            }

            // cout<<"traversal complete"<<endl;
            // displayGivenMatrix(ways);

           return ways[target];
        }

        // more space complexity as well as time 
        void bestSumTabulationTry1(){
            int target;
            cout<<"Enter target : ";
            cin>>target;
            int n;
            cout<<"How many numbers are in the array : ";
            cin>>n;
            vector<int>nums(n,0);
            cout<<"Enter "<<n<<" numbers : ";
            for(int i=0;i<n;i++)cin>>nums[i];
            ready();
            startTime();
            vector<int>ans=helper_bestSumTabulationTry1(target,nums);
            endTime();
            if(!ans.empty()){
                cout<<"Best way to reach target is : [";
                for(int var:ans){
                    cout<<var<<",";
                }
                cout<<"]"<<endl;
            } else {
                cout<<"not possible to reach target with given array of numbers"<<endl;
            }
        }

        // (m*m*n) time complexity 
        // (m*m)   space complexity
        //  m-target n-size of array of numbers

        vector<unsigned long long> helper_howSumTabulationTry1(vector<int>&nums,int& target){

            vector<vector<unsigned long long>>howSumMap(target+1,vector<unsigned long long>(0));
            for(unsigned long long var:nums){
                howSumMap[var]={var};
            }

            for(int i=0;i<=target;i++){
                if(!howSumMap[i].empty()){
                    for(int var:nums){
                        int next=i+var;
                        if(next==target){
                            vector<unsigned long long>temp=howSumMap[i];
                            temp.push_back(var);
                            return temp;
                        } else if(next<target){
                            howSumMap[next]=howSumMap[i];
                            howSumMap[next].push_back(var);
                        }
                    }
                }
            }
            return {};
        }

        void howSumTabulationTry1(){
            int target;
            cout<<"Enter target : ";
            cin>>target;
            int n;
            cout<<"How many numbers are in the array : ";
            cin>>n;
            vector<int>nums(n,0);
            cout<<"Enter "<<n<<" numbers : ";
            for(int i=0;i<n;i++)cin>>nums[i];
            startTime();
            vector<unsigned long long>ans=helper_howSumTabulationTry1(nums,target);
            endTime();
            if(!ans.empty()){
                cout<<"One way to reach target is : [";
                for(int var:ans){
                    cout<<var<<",";
                }
                cout<<"]"<<endl;
            } else {
                cout<<"not possible to reach target with given array of numbers"<<endl;
            }
        }

        vector<int> helper_bestSumTabulationTry2(int& target,vector<int>&nums){
            
            vector<int>table(target+1,INT_MAX);
            for(int& var:nums){
                if(var<=target){
                    table[var]=0;
                }
            }

            for(int i=0;i<=target;i++){
                if(table[i]!=INT_MAX){
                    for(int var:nums){
                        int next=i+var;
                        if(next<=target&&i<table[next]){
                            // cout<<"Next = "<<next<<endl;
                            table[next]=i;
                            // cout<<"table[next] = "<<table[next]<<endl;
                            // cout<<table.size()<<endl;
                        }
                    }
                }
            }

            vector<int>ans;
            int i=target,next;
            int count=0;
            if(table[target]==INT_MAX)return ans;
            while(i>0){
                count++;
                next=table[i];
                int added=(i-next);
                // cout<<"Pushing : "<<added<<endl;
                // cout<<"next = "<<next<<endl;
                // cout<<"i = "<<i<<endl;
                ans.push_back((added));
                i=next;
                // cout<<"After i = "<<i<<endl;
            }
            cout<<"Minimum no of steps required are : "<<count<<endl;
            return ans;
        }

        //fails for certain cases
        //target - 12, nums= 1 4 9 
        void bestSumTabulationTry2(){
            int target;
            cout<<"Enter target : ";
            cin>>target;
            int n;
            cout<<"How many numbers are in the array : ";
            cin>>n;
            vector<int>nums(n,0);
            cout<<"Enter "<<n<<" numbers : ";
            for(int i=0;i<n;i++)cin>>nums[i];
            ready();
            startTime();
            vector<int>ans=helper_bestSumTabulationTry2(target,nums);
            endTime();
            if(!ans.empty()){
                cout<<"Best way to reach target is : [";
                for(int var:ans){
                    cout<<var<<",";
                }
                cout<<"]"<<endl;
            } else {
                cout<<"not possible to reach target with given array of numbers"<<endl;
            }
        }

        unordered_set<string>dictionary;

        bool helper_canConstructTabulationTry1(){
            vector<bool>table(finalStr.size()+1,false);
            table[0]=true;
            for(int i=1;i<=finalStr.size();i++){
                string toCheck=finalStr.substr(0,i);
                if(dictionary.find(toCheck)!=dictionary.end()){
                    table[i]=true;
                    continue;
                }
                for(int j=i-1;j>=0;j--){
                    if(table[j]){
                        string substrFind=toCheck;
                        substrFind.erase(0,j);
                        if(dictionary.find(substrFind)!=dictionary.end()){
                            table[i]=true;
                            break;
                        }
                    }
                }
            }
            cout<<"Traversing completed"<<endl;
            cout<<"vector is : ";
            for(bool var:table)cout<<var<<" ";
            cout<<endl;
            return table.back();
        }

        void canConstructTabulationTry1(){
            int n;
            cout<<"Enter final string : ";
            cin>>this->finalStr;
            cout<<"How many strings are present in the dictionary : ";
            cin>>n;
            string str;
            cout<<"Enter "<<n<<" strings : ";
            for(int i=0;i<n;i++){
                cin>>str;
                dictionary.insert(str);
            }
            if(helper_canConstructTabulationTry1()){
                cout<<"It is possible to consturtc finalStr from given dictionary of words"<<endl;
            } else {
                cout<<"it is not possible to construct finalStr from given dictionary of words"<<endl;
            }
            dictionary.clear();
        }

        bool helper_canConstructTabulationTry2(vector<string>&dict){
            int target=finalStr.size();
            vector<bool>table(target+1,false);
            table[0]=true;
            for(int i=0;i<=target;i++){
                if(table[target])return true;
                if(table[i]){
                    string curr=finalStr.substr(0,i);
                    for(string str:dict){
                        string next=curr+str;
                        if(next.size()>target)continue;
                        string comp=finalStr.substr(0,next.size());
                        if((next)==comp){
                            table[next.size()]=true;
                        }
                    }
                }
            }
            return table[target];
        }

        void canConstructTabulationTry2(){
            int n;
            cout<<"Enter final string : ";
            cin>>this->finalStr;
            cout<<"How many strings are present in the dictionary : ";
            cin>>n;
            vector<string>dict(n);
            cout<<"Enter "<<n<<" strings : ";
            for(int i=0;i<n;i++){
                cin>>dict[i];
            }
            if(helper_canConstructTabulationTry2(dict)){
                cout<<"It is possible to consturtc finalStr from given dictionary of words"<<endl;
            } else {
                cout<<"Not possible to construct "<<finalStr<<" from given dictionary fo words"<<endl;
            }
        }

        vector<string> helper_bestConstructTabulationTry1(){
            int target=finalStr.size();
            vector<vector<string>>table(target+1,vector<string>(0));
            table[0]={""};
            for(int i=0;i<=target;i++){
                if(table[i].empty()){
                    string toFind=finalStr.substr(0,i);
                    if(dictionary.find(toFind)!=dictionary.end()){
                        table[i]={toFind};
                        continue;
                    } else {
                        cout<<"looking back for "<<toFind<<endl;
                    }
                    for(int j=i-1;j>=0;j--){
                        if(!table[j].empty()){
                            string extraNeeded=toFind.substr(j);
                            // extraNeeded.erase(0,j);
                            if(dictionary.find(extraNeeded)!=dictionary.end()){
                                if(table[i].empty()){
                                    table[i]=table[j];
                                    table[i].push_back(extraNeeded);
                                }else if(table[i].size()>table[j].size()+1){
                                    table[i]=table[j];
                                    table[i].push_back(extraNeeded);
                                }
                            }
                        }
                    }
                    cout<<"For "<<toFind<<" set vector is : [";
                    for(string str:table[i]){
                        cout<<str<<", ";
                    }
                    cout<<"]"<<endl;
                }
            }
            return table[target];
        }

        void bestConstructTabulationTry1(){
            int n;
            cout<<"Enter final string : ";
            cin>>this->finalStr;
            cout<<"How many strings are present in the dictionary : ";
            cin>>n;
            string str;
            cout<<"Enter "<<n<<" strings : ";
            for(int i=0;i<n;i++){
                cin>>str;
                dictionary.insert(str);
            }
            vector<string>bestConstruct=helper_bestConstructTabulationTry1();
            if(!bestConstruct.empty()){
                cout<<"It is possible to consturtc finalStr from given dictionary of words"<<endl;
                cout<<"Best possible way is : [";
                for(string str:bestConstruct){
                    cout<<str<<", ";
                }
                cout<<"]"<<endl;
            } else {
                cout<<"it is not possible to construct finalStr from given dictionary of words"<<endl;
            }
            dictionary.clear();
        }

        int helper_countConstructTabulationTry1(){
            int target=finalStr.size();
            vector<int>table(target+1,0);
            table[0]=1;
            for(int i=1;i<=target;i++){
                string toFind=finalStr.substr(0,i);
                for(int j=i-1;j>=0;j--){
                    if(table[j]==0)continue;
                    string extraNeeded=toFind.substr(j);
                    if(dictionary.find(extraNeeded)!=dictionary.end()){
                        table[i]+=table[j];
                    }
                }
            }

            return table[target];
        }
        
        //int his we are moving backward (m*m) + some o(1) operations everytime - useful when m is small but n(no of words in dictionary are LARGE);
        void countConstructTabulationTry1(){
            int n;
            cout<<"Enter final string : ";
            cin>>this->finalStr;
            cout<<"How many strings are present in the dictionary : ";
            cin>>n;
            cout<<"Enter "<<n<<" string : "<<endl;
            string str;
            for(int i=0;i<n;i++){
                cin>>str;
                dictionary.insert(str);
            }
            int count=helper_countConstructTabulationTry1();
            if(count!=0){
                cout<<"No of ways to construct "<<finalStr<<" are "<<count<<endl;
            } else {
                cout<<"It is not possible to construct "<<finalStr<<" from given dictionary"<<endl;
            }
        }

        int helper_countConstructTabulationTry2(){
            int target=finalStr.size();
            vector<int>table(target+1,0);
            table[0]=1;
            for(int i=0;i<target;i++){
                string curr=finalStr.substr(0,i);
                for(string str:dictionary){
                    if(finalStr.find(curr+str)==0){
                        table[curr.size()+str.size()]+=table[i];
                    }
                }
            }
            return table[target];
        }

        //in this emthod we check forard from current position Alvin's method (m*n) time complexity -useful when m can be LARGE but n(no of word sin dictionary) is small
        void countConstructTabulationTry2(){
            int n;
            cout<<"Enter final string : ";
            cin>>this->finalStr;
            cout<<"How many strings are present in the dictionary : ";
            cin>>n;
            cout<<"Enter "<<n<<" string : "<<endl;
            string str;
            for(int i=0;i<n;i++){
                cin>>str;
                dictionary.insert(str);
            }
            int count=helper_countConstructTabulationTry2();
            if(count!=0){
                cout<<"No of ways to construct "<<finalStr<<" are "<<count<<endl;
            } else {
                cout<<"It is not possible to construct "<<finalStr<<" from given dictionary"<<endl;
            }
        }

        unordered_map<int,vector<int>>possibleWay;

        bool helper_bestSumMemoizationTry2(unsigned long long& target,int curr,vector<int>&nums){
            if(curr==target){
                return true;
            } else if(curr>target){
                return false;
            } else if(notPossible.find(curr)!=notPossible.end()){
                return false;
            } else if(possibleWay.find(curr)!=possibleWay.end()){
                return true;
            }

            bool found=false;
            int minNeighbour=INT_MAX,minVec=INT_MAX,diff;
            for(int var:nums){
                int next=var+curr;
                if(helper_bestSumMemoizationTry2(target,next,nums)){
                    found=true;
                    if(possibleWay[next].size()<minVec){
                        minVec=possibleWay[next].size();
                        minNeighbour=next;
                        diff=var;
                    }
                
                }
            }
            if(found){
                if(minVec!=INT_MAX){
                    possibleWay[curr]=possibleWay[minNeighbour];
                    possibleWay[curr].push_back(diff);
                }
                return true;
            } else {
                notPossible.insert(curr);
                return false;
            }
        }

        void bestSumMemoizationTry2(){
            unsigned long long target;
            int nNum;
            cout<<"ENter target : ";
            cin>>target;
            cout<<"How many number are in the vector : ";
            cin>>nNum;
            vector<int>nums(nNum,0);
            cout<<"Enter "<<nNum<<" numbers of the vector"<<endl;
            for(int i=0;i<nNum;i++){
                cin>>nums[i];
            }
            possibleWay[target]={};
            ready();
            startTime();
            bool ans=helper_bestSumMemoizationTry2(target,0,nums);
            endTime();
            if(ans){
                cout<<"It is possible to reach sum to : "<<target<<" using the given numbers"<<endl;
                cout<<"Best Path from 0-"<<target<<" is : ";
                for(int var:possibleWay[0]){
                    cout<<var<<" ";
                }
                cout<<endl;
            } else {
                cout<<"it is not possible to reach target with given numbers"<<endl;
            }
            cout<<"Total calculations required = "<<cnt<<endl;
            cout<<"No of calculations saved roughly : "<<savedCalculation<<endl;
            savedCalculation=0;
            cnt=0;
            possibleWay.clear();
            notPossible.clear();
        }

        vector<vector<string>> helper_allConstructsTabulationTry1(){
            int target=finalStr.size();
            vector<vector<vector<string>>>table(target+1,vector<vector<string>>(0));
            table[0]={{}};
            for(int i=1;i<=target;i++){
                string toFind=finalStr.substr(0,i);
                for(int j=i-1;j>=0;j--){
                    string extraNeeded=toFind.substr(j,target);
                    if(dictionary.find(extraNeeded)!=dictionary.end()){
                        for(auto it:table[j]){
                            it.push_back(extraNeeded);
                            table[i].push_back(it);
                        }
                    }
                }
            }
            return table[target];
        }

        void allConstructsTabulationTry1(){
            int n;
            cout<<"Enter final string : ";
            cin>>this->finalStr;
            this->size=this->finalStr.size();
            cout<<"How many strings are present in the dictionary : ";
            cin>>n;
            string str;
            cout<<"Enter "<<n<<" string : "<<endl;
            for(int i=0;i<n;i++){
                cin>>str;
                dictionary.insert(str);
            }
            ready();
            startTime();
            vector<vector<string>>ans=helper_allConstructsTabulationTry1();
            endTime();

            if(!ans.empty()){
                cout<<"it is possible to construct "<<finalStr<<" using given dictionary of words in "<<ans.size()<<" ways"<<endl;
                bool ask;
                cout<<"Do you want to print all possible ways : ";
                cin>>ask;
                if(ask){
                    for(auto it:ans){
                        cout<<"[";
                        for(string str:it){
                            cout<<str<<", ";
                        }
                        cout<<"]"<<endl;
                    }
                }
            } else {
                cout<<"It is not possible to construct "<<finalStr<<" from given dictionary"<<endl;
            }
            cout<<"Total function calls perfomed : "<<cnt<<endl;
            cout<<"No of recursive calls avoided rouhgly : "<<savedCalculation<<endl;
            cout<<"No of calculations saved due to formed string is nto a substring of the finalStr = "<<notSubstringsavedCalculations<<endl;
            cout<<"no of calculatiosn saved becuase substring is present in finalStr but not at start = "<<substringPresentButNotAtStart<<endl;
            savedCalculation=0;
            substringPresentButNotAtStart=0;
            notSubstringsavedCalculations=0;
            cnt=0;
            allConstructsMap.clear();       
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
    cout<<"13 : Can multiply Recursion"<<endl;
    cout<<"14 : Can Multiply DP"<<endl;
    cout<<"15 : Can Sum Using Negative numbers"<<endl;
    cout<<"16 : can Sum +ve numbers only Decreasing from target"<<endl;
    cout<<"17 : can Sum no of possible way"<<endl;
    cout<<"18 : How sum Recursion"<<endl;
    cout<<"19 : How Sum DP"<<endl;
    cout<<"20 : How sum with path from each number"<<endl;
    cout<<"21 : How Sum with path from each number bool try"<<endl;
    cout<<"22 : Best Sum MEmoization Try1"<<endl;
    cout<<"23 : countConstruct"<<endl;
    cout<<"24 : How construct"<<endl;
    cout<<"25 : All Constructs"<<endl;
    cout<<"26 : can Construct Recursive"<<endl;
    cout<<"27 : can Construct DP1(curr substring of finalStr not checked)"<<endl;
    cout<<"28 : can Construct DP2 (checked whehter curr is substring of finalStr)"<<endl;
    cout<<"29 : can Construct DP3 (Checked whehter substring is present at index 0 or not)"<<endl;
    cout<<"30 : Fibonachi Tabulation Using Array"<<endl;
    cout<<"31 : Fibo Tabulation Without using Array"<<endl;
    cout<<"32 : Grid Traveller Tabulation (Reversing back-My Method) with Matrix"<<endl;
    cout<<"33 : Grid Traveller Tabulation With Matrix (Alvin)"<<endl;
    cout<<"34 : Cube traveller DFS"<<endl;
    cout<<"35 : Cube traveller DP"<<endl;
    cout<<"36 : Can Sum Tabulation"<<endl;
    cout<<"37 : Can Sum Tabulation Try2(stack)"<<endl;
    cout<<"38 : Can Sum Tabulation Try3 (using bool array)"<<endl;
    cout<<"39 : Cube traveller 4D"<<endl;
    cout<<"40 : Best Sum Tabulation Try1"<<endl;
    cout<<"41 : Cube traveller in 5D"<<endl;
    cout<<"42 : Cube Traveller in 6D"<<endl;
    cout<<"43 : How Sum Tabulation try1 (vector<vector< >> formed)"<<endl;
    cout<<"44 : Best sum Tabulation Try2 (fails for cartain cases)"<<endl;
    cout<<"45 : Can COnstruct Tabulation Try1(looking backward if false found)"<<endl;
    cout<<"46 : Can construct Tabulation Try2 (looking forward)"<<endl;
    cout<<"47 : Best Construct Tabulation Try1"<<endl;
    cout<<"48 : Count construct Tabulation Try1 (Moving backward for every index m*m) - my method"<<endl;
    cout<<"49 : Count COnstruct Tabulation Try2 (In this we check forward m*n)"<<endl;
    cout<<"50 : Best SUm Memoization Try2"<<endl;
    cout<<"51 : ALl Constructs Tabulation Try1"<<endl;
    cout<<"Your choice : ";
    cin>>choice;
    return choice;
}

int main(){

    DynamicProgramming DP(1);

    int choice=1;
    
    while(choice){
        choice=getChoice();
        if(choice==1){
            
            DP.gridTopLeftToBottomRightDynamic();
        } 
        else if(choice==2){
            DP.ready();
            DP.startTime();
            unsigned long long totalPossiblePaths=DP.matrixNormalTraverse(0,0);
            DP.endTime();
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
        else if(choice==13){
            DP.canMultiply();
        }
        else if(choice==14){
            DP.canMultiplyDP();
        }
        else if(choice==15){
            DP.canSumNegNums();
        }
        else if(choice==16){
            DP.canSumDecreasingFromTarget();
        }
        else if(choice==17){
            DP.canSumNoOfWays();
        }
        else if(choice==18){
            DP.howSumRecursion();
        }
        else if(choice==19){
            DP.howSumDP();
        }
        else if(choice==20){
            DP.howSumNoOfWays();
        }
        else if(choice==21){
            DP.howSumNoOfWaysBoolTry();
        }
        else if(choice==22){
            DP.bestSum();
        }
        else if(choice==23){
            DP.countConstruct();
        }
        else if(choice==24){
            DP.howConstruct();
        }
        else if(choice==25){
            DP.allConstructs();
        }
        else if(choice==26){
            DP.canConstructRecursive();
        }
        else if(choice==27){
            DP.canConstructDP1();
        }
        else if(choice==28){
            DP.canConstructDP2();
        }
        else if(choice==29){
            DP.canConstructDP3();
        }
        else if(choice==30){
            DP.fiboTabulation();
        }
        else if(choice==31){
            DP.fiboDPWithoutArray();
        }
        else if(choice==32){
            DP.gridTraverllerTabulationReverse();
        }
        else if(choice==33){
            DP.gridTraverllerTabulation();
        }
        else if(choice==34){
            DP.cubeTraveller();
        }
        else if(choice==35){
            DP.cubeTravellerDP();
        }
        else if(choice==36){
            DP.canSumTabulation();
        }
        else if(choice==37){
            DP.canSumTabulationTry2();
        }
        else if(choice==38){
            DP.canSumTabulationTry3();
        }
        else if(choice==39){
            DP.cubeTraveller4D();
        }
        else if(choice==40){
            DP.bestSumTabulationTry1();
        }
        else if(choice==41){
            DP.cubeTraveller5D();
        }
        else if(choice==42){
            DP.cubeTraveller6D();
        }
        else if(choice==43){
            DP.howSumTabulationTry1();
        }
        else if(choice==44){
            DP.bestSumTabulationTry2();
        }
        else if(choice==45){
            DP.canConstructTabulationTry1();
        }
        else if(choice==46){
            DP.canConstructTabulationTry2();
        }
        else if(choice==47){
            DP.bestConstructTabulationTry1();
        }
        else if(choice==48){
            DP.countConstructTabulationTry1();
        }
        else if(choice==49){
            DP.countConstructTabulationTry2();
        }
        else if(choice==50){
            DP.bestSumMemoizationTry2();
        }
        else if(choice==51){
            DP.allConstructsTabulationTry1();
        }
        sleep(2);
    }
}

// 2399309444331282944
// 8998663545468580096
