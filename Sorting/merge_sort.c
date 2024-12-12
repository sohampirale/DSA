#include<stdio.h>

void mergeSort(int* nums,int st,int end){
    if(st>=end)return;
    int mid=st+(end-st)/2;
    mergeSort(nums,st,mid);
    mergeSort(nums,mid+1,end);
    int tempSize=mid-st+1;
    int tempArr[tempSize];
    int i=0,j=st,k=st;
    while(i<tempSize){
        tempArr[i]=nums[j];
        j++;
        i++;
    }
    i=0,j=mid+1;
    while(i<tempSize&&j<=end){
        if(tempArr[i]<nums[j]){
            nums[k]=tempArr[i];
            i++;
        } else {
            nums[k]=nums[j];
            j++;
        }
        k++;
    }
    while(i<tempSize){
        nums[k]=tempArr[i];
        i++;
        k++;
    }
    while(j<=end){
        nums[k]=nums[j];
        j++;
        k++;
    }
}

void merge(int*nums,int*tempArr,int st,int mid,int end){
    int i=st,j=mid+1,k=st;
    while(i<=mid&&j<=end){
        if(nums[i]<nums[j]){
            tempArr[k]=nums[i];
            i++;
        } else {
            tempArr[k]=nums[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        tempArr[k]=nums[i];
        i++;
        k++;
    }
    while(j<=end){
        tempArr[j]=nums[j];
        j++;
        k++;
    }
    i=st;
    while(i<=end){
        nums[i]=tempArr[i];
        i++;
    }
}

void mergeSort2(int*nums,int* tempArr,int st,int end){
    if(st>=end)return;
    int mid=st+(end-st)/2;
    mergeSort2(nums,tempArr,st,mid);
    mergeSort2(nums,tempArr,mid+1,end);

    merge(nums,tempArr,st,mid,end);
}

int main(){
    int n;
    printf(":Enter n : ");
    scanf("%d",&n);
    int nums[n],tempArr[n];
    printf("Enter %d numbers : ",n);

    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    printf("Array before sorting : ");
    for(int i=0;i<n;i++)printf("%d ",nums[i]);
    printf("\n");
    // mergeSort(nums,0,n-1);
    mergeSort2(nums,tempArr,0,n-1);
    printf("Array after sorting : ");
    for(int i=0;i<n;i++)printf("%d ",nums[i]);
    printf("\n");

}