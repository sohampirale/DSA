#include<iostream>
class Solution {
public:

    int reachNumber(int target) {
    	int sum=0,st=0;
        target=abs(target);
        while(sum<target||(sum-target)%2!=0){
            st++;;
            sum+=st;
        }
        return st;// i have looked up the solution so i wont submit it
        //return st;
    }
};
