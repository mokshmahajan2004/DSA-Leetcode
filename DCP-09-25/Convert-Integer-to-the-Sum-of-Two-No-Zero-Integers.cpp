class Solution {
public:
    // helper to check if number contains '0'
    bool isContainZero(int n) {
        while (n > 0) {
            if (n % 10 == 0) return true;
            n /= 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int b = n - i;
            if (!isContainZero(i) && !isContainZero(b)) {
                return {i, b};
            }
        }
        return {}; // just for safety, problem guarantees a solution exists
    }
};
