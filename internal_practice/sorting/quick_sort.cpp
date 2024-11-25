#include<iostream>
#include<vector>
using namespace std;
void quick_sort(int*num,int size,int st,int end){
    if(st>=end)return;  
    int i=st,j=end;
    int mid=i+(j-i)/2;
    int pivot=num[mid];
    while(i<=j){
        while(num[i]<pivot)i++;
        while(num[j]>pivot)j--;
        if(i<=j){
            int temp=num[i];
            num[i]=num[j];
            num[j]=temp;
            i++;
            j--;
        }
        for(int i=0;i<size;i++)cout<<num[i]<<" ";
        cout<<endl;
    }
    quick_sort(num,size,st,j);
    quick_sort(num,size,i,end);
}

int main(){
    int n;
    cout<<"Enter size of array ; ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0;i<n;i++)cin>>arr[i];
    quick_sort(arr,n,0,n-1);
    cout<<"After sorting fucntion array becomes : ";
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
}