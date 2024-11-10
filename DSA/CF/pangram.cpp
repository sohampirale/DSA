#include<iostream>
#include<vector>
using namespace std;
string pangram(string s){
    vector<bool>present(26,false);
    for(int i=0;i<s.length();i++){
        if(s[i]==' ')continue;
        if(s[i]>=65&&s[i]<=90){
            present[s[i]-65]=true;
        } else if(s[i]>=97&&s[i]<=122){
            present[s[i]-97]=true;
        }
    }   
    for(int i=0;i<26;i++){
        if(!present[i]){
            // cout<<static_cast<char>(i)
            cout<<static_cast<char>(i+97)<<" not present"<<endl;
            return "not pangram";

        }
    }
    return "pangram"; 
}
int main(){
    string s;
    cout<<"Enter string : ";
    getline(cin,s);
    // cin>>s;
    cout<<pangram(s)<<endl;
}