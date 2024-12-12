#include<stdio.h>
void quickSort(int* nums,int st,int end){
    if(st>=end)return;
    int mid=st+(end-st)/2;
    int pivot=nums[st],i=st+1,j=end;
    while(i<=j){
        while(i<=end&&nums[i]<pivot)i++;

        while(j>=0&&nums[j]>pivot)j--;

        if(i<j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j--;
        }
    }
    if(j>=0){
        nums[st]=nums[j];
        nums[j]=pivot;
    }
    quickSort(nums,st,j);
    quickSort(nums,j+1,end);
}

int main(){
    int n;
    printf("enter n : ");
    scanf("%d",&n);
    int nums[n];
    printf("enter %d numbers : ",n);
    for(int i=0;i<n;i++)scanf("%d",&nums[i]);
    quickSort(nums,0,n-1);
    printf("Array after sortign becomes : ");
    for(int i=0;i<n;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
}