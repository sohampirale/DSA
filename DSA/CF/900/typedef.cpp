#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<long long>vl;
int main(){
    vl v1;
    v1.push_back(3);
    v1.push_back(12);
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<endl;
    }
}