//Sohan Sachin Pirale
//Rol no -2022

#include<iostream>
#include<vector>
using namespace std;
template <typename T>
void selection(vector<T>&nums){
    for(int i=0;i<nums.size()-1;i++){
        T selected=nums[i];
        T min=nums[i];
        int index=i;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]<min){
                min=nums[j];
                index=j;
            }
        }
        nums[i]=nums[index];
        nums[index]=selected;
    }
}

template <typename T>
void display(vector<T>&nums){
    cout<<"Nums : ";
    for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    cout<<endl;
}

int main(){
    int n;
    cout<<"ENetr size of aray : ";
    cin>>n;
    int ch;
    cout<<"WHich type of numbers you have :\n1 : int\n2 Float\n3 : Double\n4 : Strings\nYour choice : ";
    cin>>ch;
    if(ch==1){
        vector<int>nums(n);
        cout<<"Enter "<<n<<" numbers : ";
        for(int i=0;i<n;i++)cin>>nums[i];
        selection(nums);
        display(nums);
    } else if(ch==2){
        vector<float>nums(n);
        cout<<"Enter "<<n<<" numbers : ";
        for(int i=0;i<n;i++)cin>>nums[i];
        selection(nums);
        display(nums);
    } else if(ch==3){
        vector<double>nums(n);
        cout<<"Enter "<<n<<" numbers : ";
        for(int i=0;i<n;i++)cin>>nums[i];
        selection(nums);
        display(nums);
    } else if(ch==4){
        vector<string>nums(n);
        cout<<"Enter "<<n<<" strings : ";
        for(int i=0;i<n;i++)cin>>nums[i];
        selection(nums);
        display(nums);
    }
    
}


// ENetr size of aray : 6
// WHich type of numbers you have :
// 1 : int
// 2 Float
// 3 : Double
// 4 : Strings
// Your choice : 1
// Enter 6 numbers : 5 10 2 20 12 15
// Nums : 2 5 10 12 15 20 

// ENetr size of aray : 6
// WHich type of numbers you have :
// 1 : int
// 2 Float
// 3 : Double
// 4 : Strings
// Your choice : 2
// Enter 6 numbers : 4.5 0.2 1.2 3.4 2.2 6.4
// Nums : 0.2 1.2 2.2 3.4 4.5 6.4 