//Name - Soham Sachin Pirale
//Roll no - 2022

//Question - We are given an array conatinning only 0's & 1's and in sorted manner (ex - [0,0,0,1,1])
//      To find - Find the 'index' at which 'first' occurance of 1 is found in the array
//      If No 0 is present return 0
//      If No 1 is present return -1 



#include<stdio.h>

//this function uses recursive + binary search approach to find the first occurace of 1
int find(int* arr,int st,int end,int size){

    if(st>end)return -1;    //this check is 'only' necessary if the input given by user is not sorted or out of range numbers entered

    int mid=st+(end-st)/2; //to avoid interger overflow  
    
    if(arr[mid]==1){
        //checking whether the curent found 1 is first occurance in array
        //Edge case of array out of bounds is handled in the main function

        if(arr[mid-1]==0){
            return mid;
        }
        else {
            //if currently found 1 is not the first occurance -> go towards left
            return find(arr,st,mid-1,size);
        }
    } else {
        //is 0 is found -> go towards right
        return find(arr,mid+1,end,size);
    }
}

int main(){
    int n;
    printf("Enter size of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d numbers : ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    if(arr[0]==1){
        //edge case (all 1's present in the array)
        printf("Ans = 0\n");
    } else if(arr[n-1]==0){
        //edge case - all 0's present in the array
        printf("Ans = -1\n");
    } else {
        int ans=find(arr,0,n-1,n);
        printf("Ans = %d\n",ans);
    }
}


//Time Complexity - O(log n) (worst case)  
//      This approach uses binary search in order to find the first occurance of 1

//Depending upon the number present at mid 
//  1.If arr[mid]==1 we check :
//          1.Whether the number present at arr[mid-1]==1
//                  if yes : Move toward left else : We found the first occurance at index : mid

//  2.Else if arr[mid] == 0
//      then : Move towards right

//As we are dividing array in half everytime we move left or right time complexity for the worst case becomes : O(log n)

//Different Approach
//      Another approach that could be used is iterating through the array from start until we find th efirst occurance of 1
//      Time Complexitity of this approach in worst case would be - O(n) 

//O(log n) time complexity is better than O(n)