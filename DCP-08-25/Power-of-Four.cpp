class Solution {
public:
//TC->O(log4(n))
//SC->O(1)
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        if(n>=1){
            while(n%4==0){
            n=n/4;
            }
        }
        return n==1;


    }
};