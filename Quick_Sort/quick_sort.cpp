#include<iostream>
#include<vector>
using namespace std;

void quick_sort_pivot_at_end(vector<int>&nums,int low,int high){
    if(low>=high)return;
    int pivot=nums[high];
    int st=low,end=high;//gg
    // cout<<"low = "<<low<<" & high = "<<high<<endl;
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
    // cout<<"Array modified to : ";
    // for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    // cout<<endl;
    quick_sort_pivot_at_end(nums,low,end);
    quick_sort_pivot_at_end(nums,st,high);
}

void quick_sort_pivot_at_mid(vector<int>&nums,int low,int high){
    if(low>high)return;
    if(low==high){
        // cout<<"low = "<<low<<" & high = "<<high<<endl;
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
        // cout<<"Array modified to : ";
        // for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
        // cout<<endl;
    }
    // cout<<"Came out at st = "<<st<<" & end = "<<end<<endl;
    quick_sort_pivot_at_mid(nums,low,end);
    quick_sort_pivot_at_mid(nums,st,high);
}

//in this the st<end is kept and if st becomes > end then no prb that is the original approch
// to split recursiove calls but if st becomes equal to end then the loop  braks and fucntion cann change from
//  low-end  and  st-high   (where st==end)
void quick_sort_pivot_at_mid_removed_equal_to_check(vector<int>&nums,int low,int high){
    if(low>high)return;
    if(low==high){
        // cout<<"low = "<<low<<" & high = "<<high<<endl;
        return;
    }
    int st=low,end=high;
    int mid=st+(end-st)/2;
    int pivot=nums[mid];
    while(st<end){
        while(nums[st]<pivot){
            st++;
        }
        while(nums[end]>pivot)
            end--;
        if(st<end){
            int temp=nums[st];
            nums[st]=nums[end];
            nums[end]=temp;
            st++;
            end--;
        } 
        // cout<<"Array modified to : ";
        // for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
        // cout<<endl;
    }
    // cout<<"Came out at st = "<<st<<" & end = "<<end<<endl;
    quick_sort_pivot_at_mid(nums,low,end);
    quick_sort_pivot_at_mid(nums,st,high);
}

//j moving forward comparing with the pivot (th element at the nums[high])
void quick_sort_brocode(vector<int>&nums,int low,int high){
    if(low>=high)return;
    int i=low-1,j=low;
    int pivot=nums[high];
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
    int choice;
    cout<<"How do you want to use quick sort?\nTaking pivot at : \n1 : At front\n2 : At middle\n3   At end\nYour choice : ";
    cin>>choice;
    if(choice==1){
        quick_sort_brocode(nums,0,n-1);
    } else if(choice==2){
        cout<<"Calling method where st<=end used";
        quick_sort_pivot_at_mid(nums,0,n-1);
    } else if(choice==3){
        quick_sort_pivot_at_end(nums,0,n-1);
    }


    
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