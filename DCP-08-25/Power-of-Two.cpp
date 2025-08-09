class Solution {
public:
//TC->O(logn)
//SC->O(1)
    bool isPowerOfTwo(int num) {
        if (num == 1) return true;
        if (num <= 0) return false;
        if (num % 2 == 0) return isPowerOfTwo(num / 2);
        return false;
    }
};
