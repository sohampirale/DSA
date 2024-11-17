#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,string>map;
    int choice=1,key;
    map["1"]="ex1";
    map["3"]="ex2";

    int bucketno=map.bucket("1");
    cout<<"Bucket no = "<<bucketno<<endl;
    bucketno=map.bucket("3");
    cout<<"Bucket no = "<<bucketno<<endl;
    cout<<"Bucket count = "<<map.bucket_count()<<endl;
    cout<<"Bucket size = "<<map.bucket_size(9)<<endl;

}

 