//Soham Sachin Pirale
//2022

#include<iostream>
#include<vector>
using namespace std;
template <typename T>
void bubblesort(vector<T>&nums){
    for(int i=0;i<nums.size()-1;i++){
        for(int j=0;j<nums.size()-1;j++){
            if(nums[j]>nums[j+1]){
                T temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
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
        bubblesort(nums);
        display(nums);
    } else if(ch==2){
        vector<float>nums(n);
        cout<<"Enter "<<n<<" numbers : ";
        for(int i=0;i<n;i++)cin>>nums[i];
        bubblesort(nums);
        display(nums);
    } else if(ch==3){
        vector<double>nums(n);
        cout<<"Enter "<<n<<" numbers : ";
        for(int i=0;i<n;i++)cin>>nums[i];
        bubblesort(nums);
        display(nums);
    } else if(ch==4){
        vector<string>nums(n);
        cout<<"Enter "<<n<<" strings : ";
        for(int i=0;i<n;i++)cin>>nums[i];
        bubblesort(nums);
        display(nums);
    }
    
}
// soham@soham-Inspiron-20-Model-3048:~/Coding/DSA/CPP/exp10$ ./a.out
// ENetr size of aray : 
// 6  
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
// Enter 6 numbers : 2.3 5.2 0.5 5.8 3.2 0.12
// Nums : 0.12 0.5 2.3 3.2 5.2 5.8 

// ENetr size of aray : 6
// WHich type of numbers you have :
// 1 : int
// 2 Float
// 3 : Double
// 4 : Strings
// Your choice : 4
// Enter 6 strings : aab aaz zac aaa bbb abc
// Nums : aaa aab aaz abc bbb zac 