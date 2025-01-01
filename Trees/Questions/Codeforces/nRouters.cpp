#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

string path=" ";

// unordered_map<int,unordered_set<int>>map;
vector<bool>visited;
vector<vector<int>>map;
int target;

bool traverse(int curr){
    visited[curr]=true;
    if(curr==target){
        path=to_string(curr)+" "+path;
        return true;
    }
    for(int neighbour: map[curr]){
        if(!visited[neighbour]&&traverse(neighbour)){
            path=to_string(curr)+" "+path;
            return true;
        }
    }
    return false;
}
// 200000
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

int main(){
    int n;
    cin>>n;
    map.resize(n+1,vector<int>(0));
    visited.resize(n+1,false);
    target=n;
    // for(int i=1;i<=n;i++){
    //     map[i];
    // }
    vector<int>vec(n);
    for(int i=0;i<n-1;i++){
        cin>>vec[i];
        map[vec[i]].push_back(i+2);
        // cout<<"Pushed "<<i+1<<" to map["<<vec[i]<<"]"<<endl;
    }
    traverse(1);
    cout<<path;
    return 0;
}   
