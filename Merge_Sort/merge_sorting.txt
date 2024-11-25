#include<iostream>
#include<vector>
using namespace std;
template <typename T>
vector<T> merge_sort(vector<T>&nums,int st,int end){
    if(st==end){
        vector<T>temp(1,nums[st]);
        return temp;
    }
    T mid=st+(end-st)/2;
    vector<T>left=merge_sort(nums,st,mid);
    vector<T>right=merge_sort(nums,mid+1,end);
    vector<T>temp;
    T i=0,j=0;
    while(i<left.size()&&j<right.size()){
        if(left[i]<right[j]){
            temp.push_back(left[i]);
            i++;
        } else {
            temp.push_back(right[j]);
            j++;
        }
    }
    if(i==left.size()){
        temp.insert(temp.end(),right.begin()+j,right.end());
    } else if(j==right.size()){
        temp.insert(temp.end(),left.begin()+i,left.end());
    }

    return temp;
}
int main(){
    vector<int>nums={10,20,15,45,34,50};
    vector<int>ans=merge_sort(nums,0,5);
    cout<<"Sorted array is : ";
    for(int i=0;i<6;i++)cout<<ans[i]<<" ";
    cout<<endl;
}