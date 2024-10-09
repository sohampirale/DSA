class Solution {
public:
    int find(int target){
        int st=0,end=1,cnt=0;
        while(end!=target||end+1!=target){
            int temp=end;
            end=end+(end-st+1);
            st=temp;
            cnt++;
        }
        if(end==target)return cnt;
        else return cnt+2;
    }
    int reachNumber(int target) {
        return find(target);
    }
};