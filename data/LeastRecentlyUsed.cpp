#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findLeastRecentlyUsed(vector<int>&inputString,int curr,vector<int>&buffer){
    vector<int>temp=buffer;
    int i=curr-1;
    while(temp.size()!=1&&i>=0){
        auto it=find(temp.begin(),temp.end(),inputString[i]);
        if(it!=temp.end()){
            // cout<<"Deleting "<<inputString[i]<<" from temp"<<endl;
            temp.erase(it);
        }
        i--;
    }
    return temp[0];
}

void LeastRcentlyUsed(vector<int>&inputString,vector<int>&buffer,int maxBufferSize){
    for(int i=0;i<inputString.size();i++){
        auto it=find(buffer.begin(),buffer.end(),inputString[i]);
        if(it!=buffer.end()){
            cout<<"Page hit for "<<inputString[i]<<endl;
        } else {
            if(buffer.size()==maxBufferSize){
                cout<<"Page miss but buffer is full"<<endl;
                int numberToRemove=findLeastRecentlyUsed(inputString,i,buffer);
                cout<<"numberToRemove = "<<numberToRemove<<endl;
                auto it=find(buffer.begin(),buffer.end(),numberToRemove);
                cout<<"Replacing "<<*it<<" with "<<inputString[i]<<endl;
                *it=inputString[i];
            } else {
                cout<<"Page miss and buffer not full"<<endl;
                buffer.push_back(inputString[i]);
                
            }
        }
    }
}

int main(){
    int n;
    cout<<"Enter size o finput string : ";
    cin>>n;
    vector<int>inputString(n);
    cout<<"ENter "<<n<<" page no's : ";
    for(int i=0;i<n;i++)cin>>inputString[i];
    int buffersize;
    cout<<"Enter size of the buffer : ";
    cin>>buffersize;
    vector<int>buffer;
    LeastRcentlyUsed(inputString,buffer,buffersize);
}