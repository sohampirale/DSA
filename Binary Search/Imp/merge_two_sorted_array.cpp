#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&nums1,vector<int>&nums2){
    int st1=0,st2=0,end1=nums1.size()-1,end2=nums2.size()-1,mid1,mid2,test=0;
    while(!nums2.empty()){
        // mid1=st1+(end1-st1)/2;
        // mid2=st2+(end2-st2)/2;
        // cout<<"mid1 poitning at : "<<nums1[mid1]<<endl;
        // cout<<"mid2 poitning at : "<<nums2[mid2]<<endl;
        while(1){
            if(test==25)return;
            mid1=st1+(end1-st1)/2;
            mid2=st2+(end2-st2)/2;
            // cout<<"mid1 poitning at : "<<nums1[mid1]<<endl;
            // cout<<"mid2 poitning at : "<<nums2[mid2]<<endl;
            // cout<<"st1 = "<<st1<<" end1 = "<<end1<<endl<<" st2 = "<<st2<<" & end2  = "<<end2<<endl;
            if(nums2[mid2]>=nums1[mid1]){
                if(mid1!=nums1.size()&&nums2[mid2]<=nums1[mid1+1]){
                    // cout<<"Hey"<<endl;
                    nums1.insert(nums1.begin()+mid1+1,nums2[mid2]);
                    // cout<<nums2[mid2]<<" Inserted at posotion : "<<mid1+1<<endl;
                    nums2.erase(nums2.begin()+mid2);
                    st1=0;
                    end1=nums1.size()-1;
                    end2=nums2.size()-1;
                    // cout<<"Nums1 becomes : ";
                    // for(int i=0;i<nums1.size();i++){
                    //     cout<<nums1[i]<<" ";
                    // }
                    break;
                } else if(end1==mid1){
                    // cout<<"Hi"<<endl;
                    nums1.insert(nums1.begin()+mid1+1,nums2[mid2]);
                    // cout<<nums2[mid2]<<" Inserted at end : "<<mid1+1<<endl;
                    nums2.erase(nums2.begin()+mid2);
                    end2=nums2.size()-1;
                    st1=0;
                    end1=nums1.size()-1;
                    // test++;
                    break;
                } else {
                    st1=mid1+1;
                    // cout<<"Modified st = "<<st1<<endl;
                }
            } else if(nums2[mid2]<nums1[mid1]){
                end1=mid1-1;
                // cout<<"Modified end = "<<end1<<endl;
            }
            test++;
        }

    }
}
int main(){
    int n1,n2;
    cout<<"ENter size of array 1 : ";
    cin>>n1;
    cout<<"Enter size of array 2 : ";
    cin>>n2;
    cout<<"ENter "<<n1<<" numbers of array 1 : ";
    int temp;
    vector<int>nums1(n1,0);
    vector<int>nums2(n2,0);

    for(int i=0;i<n1;i++){
        cin>>nums1[i];
    }
    cout<<"ENter "<<n2<<" numbers of array 2 : ";
    for(int i=0;i<n1;i++){
        cin>>nums2[i];
    }
    merge(nums1,nums2);
    cout<<"After merging final array becomes : ";
    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }
}