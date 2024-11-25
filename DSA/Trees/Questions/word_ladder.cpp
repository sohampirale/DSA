#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<string>wordList={"s1","s2","s3","s4"};
    for(auto it : wordList){
       if(it=="s2"){
        wordList.erase(wordList.begin()+);
       }
    }
    // for(auto it = wordList.begin();it!=wordList.end();){
    //     cout<<"CHecking "<<*it<<endl;
    //     if(*it=="s2"){
    //         wordList.erase(it);
    //     } else it++;
    // }
    // for(auto it : wordList){
    //     if(it=="s2"){
    //         wordList.erase(wordList.begin()+it);
    //     }
    // }

    cout<<"After : ";
    for(auto it : wordList){
        cout<<it<<endl;
    }
    // int j=10;
    // vector<int>nums(10);
    // for(int i=0;i<nums.size();i++){
    //     cout<<i<<endl;
    //     nums.pop_back();
    // }
}