//Name  - Soham Sachin Pirale
//Roll no - 2022

//Question - We are given an array where first element are in increasing order later they are in decreasing order
//To find - The greatest element that is present in the array (i.e. - Pivot)



#include<stdio.h>
#include<stdbool.h>

//leftCheck and rightCheck are the function which help in determining :
//  1. Whehter the current element at mid is pivot
//  2. Does pivot lies in right/left side

// here "=" is used which is useful in case of duplicate numbers in the array (ex- 10,20,30,30,5)

bool leftCheck(int* arr,int mid){
    if(mid==0)return true;           //check for edge cases(ex - pivot exist at 0 th index)
    return arr[mid]>=arr[mid-1]? true : false;
}
bool rightCheck(int* arr,int mid,int size){
    if(mid==size-1)return true;      //check for edge cases(ex - pivot exist at the last position)
    return arr[mid]>=arr[mid+1]? true : false;
}

//This functions uses binary search recursive approch to move towards pivot

int findPeak(int* arr,int st,int end,int size){
    int mid=st+(end-st)/2;  //this is used instead of(st+end)/2 in order to overcome integer overflow situations in case of large inputs

    bool left=leftCheck(arr,mid),right=rightCheck(arr,mid,size);
     
    if(left&&right){
        //pivot found
        return arr[mid];
    } else if(left){
        //pivot exist toward the right side of the arr[mid]
        return findPeak(arr,mid+1,end,size);
    } else if(right){
        //pivot exist toward the left side of the arr[mid]
        return findPeak(arr,st,mid-1,size);
    }
}

int main(){
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter %d numbers : ",size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int maxElement=findPeak(arr,0,size-1,size);
    printf("Greatest Element Present in the array = %d\n",maxElement);
    return 0;
}


//Time Complexity - O(log n)
//      This approach uses binary search to find the pivot depending upon the previous and further element present in the array we determine towards which side pivot exist
//      in this approch we split the array in two every time pivot is nto found 

//      hence time complexity is O(log n)

//Approach :
//      Pivot : Elements present int he array after pivot are less than pivot
//      if arr[mid]>arr[mid-1] : either arr[mid] can be pivot or pivot lies in the right side of the array
//      if arr[mid]>arr[mid+1] : either arr[mid] can be pivot or pivot lies in the left side of the array

//Using these 3 logics we check in every recursive functions call whehter arr[mid] is pivot and move toward left/right until we find the pivot

//  We also need to handle edge cases 
//      1:strictly increasing array (pivot at end) 
//      2:Strictly decreasing array (pivot at start)
//      3 : If any duplicates are present

//Different appraoch that could be used
//time complexity of another approach - O(n)
//approach - we iterate thorugh each element in the array and maintain a varible to find out the greatest number present in the array
//since we need to iterate through complete array of n elements so the time complexity becomes O(n);

//O(log n) time complexity is better than O(n)
