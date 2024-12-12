#include<iostream>
#include<vector>
using namespace std;
void quickSort(vector<int>&nums,int st,int end){
    if(st>=end)return;
    int mid=st+(end-st)/2;
    int pivot=nums[mid];
    int i=st,j=end;
    while(i<=j)
    {
        while(nums[i]<pivot)i++;
        while(nums[j]>pivot)j--;
        if(i<j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        } else break;
        i++;
        j--;
    }
    quickSort(nums,st,j);
    quickSort(nums,i,end);
    
}

void quickSort2(vector<int>&nums,int st,int end){
    if(st>=end)return;
    int mid=st+(end-st)/2;
    int pivot=nums[mid];
    int i=st,j=end;
    while(i<=j){
        while(nums[i]<pivot)i++;
        while(nums[j]>pivot)j--;
        if(i<j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
        i++;
        j--;
    }
    quickSort2(nums,st,j);
    quickSort2(nums,i,end);
}

void quickSort3(vector<int>&nums,int st,int end){
    if(st>=end)return;
    int pivot=nums[st];
    int i=st+1,j=end;
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
    // if(nums[j]<pivot){
        // nums[st]=nums[j];
        // nums[j]=pivot;
        int temp=nums[st];
        nums[st]=nums[j];
        nums[j]=temp;
    // }
    cout<<"Array till now is : ";
    for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    cout<<endl;
    quickSort3(nums,st,j-1);
    quickSort3(nums,j+1,end);
}

// void quickSort3(vector<int>& nums, int st, int end) {
//     if (st >= end) return;  // Base case: If there's only one element or invalid range

//     int pivot = nums[st];  // Choose the first element as the pivot
//     int i = st + 1, j = end;

//     // Partition the array around the pivot
//     while (i <= j) {
//         // Move i to the right until nums[i] > pivot
//         while (i <= end && nums[i] <= pivot) i++;
//         // Move j to the left until nums[j] < pivot
//         while (j >= st && nums[j] >= pivot) j--;
        
//         // If i < j, swap nums[i] with nums[j]
//         if (i < j) {
//             int temp = nums[i];
//             nums[i] = nums[j];
//             nums[j] = temp;
//         }
//     }

//     // Swap the pivot into its correct position
//     // Now place the pivot at the correct position (nums[j])
//     int temp = nums[st];
//     nums[st] = nums[j];
//     nums[j] = temp;

//     // Print the array for debugging
//     cout << "Array till now is: ";
//     for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
//     cout << endl;

//     // Recursively sort the two subarrays
//     quickSort3(nums, st, j - 1);  // Left subarray
//     quickSort3(nums, j + 1, end);  // Right subarray
// }


int main(){
    int n;
    cout<<"How many numbers you have : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter "<<n<<" numbers ; ";
    for(int i=0;i<n;i++)cin>>nums[i];
    cout<<"Array before sorting is : ";
    for(int i=0;i<n;i++)cout<<nums[i]<<" ";
    cout<<endl;
    quickSort3(nums,0,n-1);
    cout<<"Array after sorting is : ";
    for(int i=0;i<n;i++)cout<<nums[i]<<" ";
    cout<<endl;
}