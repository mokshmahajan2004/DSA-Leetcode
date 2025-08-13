class Solution {
public:
//TC->O(log3(n))
//SC->O(1)
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        while(n%3==0){
         n/=3;
        }
        return n==1;
        
    }
};