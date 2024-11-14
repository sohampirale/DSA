#include<stdio.h>
int find(int* arr,int st,int end,int size){
    if(st>=size){
        return -1;
    } else if(end<=-1){
        return 0;
    }
    int mid=(st+end)/2;
    
    if(arr[mid]==1){
        if(arr[mid-1]==0)return mid;
        else {
            return   find(arr,st,mid-1,size);
        }
    } else {
        int temp= find(arr,mid+1,end,size);
        printf("I received = %d\n",temp);
        return temp;
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
    int ans=find(arr,0,n-1,n);
    printf("Ans = %d\n",ans);
}
