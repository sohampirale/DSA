#include<vector>
class Solution {
public:
    int max=0,max_gp=0,max_prev;
    vector<vector<int>>ans;
    vector<vector<int>> group;
    void find(vector<int>&weights,int days,int i=0,int cnt=0){
        if(i==weights.size()) {
            if(cnt==days-1){
                int sum_of_each_group=0,max_sum_among_all_groups=0;
                cout<<cnt<<" Groups are made "<<endl;
                for(int i=0;i<days-1;i++){
                    for(int j=0;j<group[i].size();j++){
                        sum_of_each_group+=group[i][j];
                        cout<<group[i][j]<<" ";
                    }
                    if(sum_of_each_group>max_sum_among_all_groups)
                        max_sum_among_all_groups=sum_of_each_group;
                    sum_of_each_group=0;
                    cout<<endl;
                }
                if(max_sum_among_all_groups<max_prev){
                    cout<<"Erasing the previous answer because this answer has max capacity : "<<max_sum_among_all_groups<<endl;
                    max_prev=max_sum_among_all_groups;
                    ans.erase();
                    for(int i=0;i<days-1;i++){
                        ans.push_back(group[i]);
                    }
                    group.erase();
                    return;
                }
                cout<<"Group ended"<<endl;
            }
            return;
        }
        group[cnt].push_back(weights[i]);
        find(weights,days,i+1,cnt);
        find(weights,days,i+1,cnt+1);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        find(weights,days);
    }
};