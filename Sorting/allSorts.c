#include<stdio.h>
void bubbleSort(int* nums,int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(nums[j]>nums[j+1]){
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
}
void selectioSort(int*nums,int size){
    for(int i=0;i<size;i++){
        int minE=nums[i],minI=i;
        for(int j=i+1;j<size;j++){
            if(nums[j]<minE){
                minE=nums[j];
                minI=j;
            }
        }
        int temp=nums[minI];
        nums[minI]=nums[i];
        nums[i]=temp;
    }
}
void insertionSort(int* nums,int size){
    for(int i=1;i<size;i++){
        int j=i;
        while(j>0&&nums[j]<nums[j-1]){
            int temp=nums[j];
            nums[j]=nums[j-1];
            nums[j-1]=temp;
            j--;
        }
    }
}

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
        } else break;
    }
    nums[st]=nums[j];
    nums[j]=pivot;
    quickSort(nums,st,j-1);
    quickSort(nums,j+1,end);
}

void printArray(int* nums,int size){
    for(int i=0;i<size;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
}

int main(){
    int n,choice=1;
    printf("enter n : ");
    scanf("%d",&n);
    int nums[n],tempArr[n],DuppliArr[n];
    printf("Enter %d numbers : ",n);
    for(int i=0;i<n;i++)scanf("%d",&nums[i]);
    for(int i=0;i<n;i++)DuppliArr[i]=nums[i];

    while(choice){
        for(int i=0;i<n;i++)nums[i]=DuppliArr[i];
        printf("Enter your choice :\n1 : Bubble sort\'n2 : insertion sort\n3 : Selection sort\n4 : Merge sort\n5 : Quick sort\n6 : Display original array\nYour choice : ");
        scanf("%d",&choice);
        if(choice==1){
            bubbleSort(nums,n);
        } else if(choice==2){
            insertionSort(nums,n);
        } else if(choice==3){
            selectioSort(nums,n);
        } else if(choice==4){
            mergeSort2(nums,tempArr,0,n-1);
        } else if(choice==5){
            quickSort(nums,0,n-1);
        } else if(choice==6){
            printArray(nums,n);
        }
        printf("After doing sorting the array becomes : ");
        for(int i=0;i<n;i++)printf("%d ",nums[i]);
        printf("\n");
    }
}