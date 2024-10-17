#include<iostream>
#include<vector>
using namespace std;
//wokring
void quick_sort_pivot_at_end(vector<int>&nums,int low,int high){
    if(low>=high)return;
    int pivot=nums[high];
    int st=low,end=high;
    cout<<"low = "<<low<<" & high = "<<high<<endl;
    while(st<=end){
        while(nums[st]<pivot){
            st++;
        }
        while(nums[end]>pivot){
            end--;
        }
        if(st>end)break;
        int temp=nums[st];
        nums[st]=nums[end];
        nums[end]=temp;
        end--;
        // cout<<"Array modified to : ";
        for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
        cout<<endl;
    }
    cout<<"Array modified to : ";
    for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    cout<<endl;
    quick_sort_pivot_at_end(nums,low,end);
    quick_sort_pivot_at_end(nums,st,high);
}

void quick_sort_pivot_at_mid(vector<int>&nums,int low,int high){
    if(low>high)return;
    if(low==high){
        cout<<"low = "<<low<<" & high = "<<high<<endl;
        return;
    }
    int st=low,end=high;
    int mid=st+(end-st)/2;
    int pivot=nums[mid];
    while(st<=end){
        while(nums[st]<pivot){
            st++;
        }
        while(nums[end]>pivot)
            end--;
        if(st<=end){
            int temp=nums[st];
            nums[st]=nums[end];
            nums[end]=temp;
            st++;
            end--;
        }
        cout<<"Array modified to : ";
        for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
        cout<<endl;
    }
    cout<<"Came out at st = "<<st<<" & end = "<<end<<endl;
    quick_sort_pivot_at_mid(nums,low,end);
    quick_sort_pivot_at_mid(nums,st,high);
}

//j moving forward comparing with the pivot (th element at the nums[high])
void quick_sort_brocode(vector<int>&nums,int low,int high){
    if(low>=high)return;
    int i=low-1,j=low;
    cout<<"hi"<<endl;
    int pivot=nums[high];
    cout<<"hi"<<endl;
    while(j!=high){
       if(nums[j]<pivot){
        int temp=nums[j];
        i++;
        nums[j]=nums[i];
        nums[i]=temp;
       }
       j++;
    }
    i++;
    nums[high]=nums[i];
    nums[i]=pivot;
    quick_sort_brocode(nums,low,i-1);
    quick_sort_brocode(nums,i+1,high);
}
int main(){

    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0;i<n;i++)cin>>nums[i];
    quick_sort_brocode(nums,0,n-1);
    cout<<"After calling the quick sort fucntion the original array becomes : ";
    for(int i=0;i<n;i++)cout<<nums[i]<<" ";
}

//not working
// void quick_sort(vector<int>&nums,int low,int high){
//     if(low>high)return;
//     if(low==high){
//         cout<<"low = "<<low<<" & high = "<<high<<endl;
//         return;
//     }
//     int st=low,end=high;
//     // int pivot=nums[low];
//     while(st<end){
//         int pivot=nums[st];
//         while(nums[st]<pivot){
//             st++;
//             cout<<"This will never be in action"<<endl;
//         }
        
//         while(nums[end]>pivot)
//             end--;

//         if(st<end){
//             int temp=nums[st];
//             nums[st]=nums[end];
//             nums[end]=temp;
//               st++;
//              end--;
//         }
//      
//         cout<<"Array modified to : ";
//         for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
//         cout<<endl;
//     }
//     cout<<"Came out at st = "<<st<<" & end = "<<end<<endl;
//     quick_sort(nums,low,end);
//     quick_sort(nums,st,high);
// }