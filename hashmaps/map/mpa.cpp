#include<iostream>
#include<map>
using namespace std;
void print(map<int,int>&m){
    for(auto& it : m){
        cout<<it.first<<" ";
    }
    cout<<endl;
}
int main(){
    map<int,int>m;
    m[10]=1;
    m[20]=1;
    m[5]=1;
    m[15]=1;

    m.erase(10);
    print(m);
    m.erase(25);
    print(m);
    cout<<"Hello";
}


//erase
//we cannot give any iterator which does not point to a pair other error will be thrown
// map.erase(34) -> this it okay
//,ap.erase(it)  -> NOT okay if it does not points to a valid pairor points to the map.end()