class Solution {
    //Time Complexity: \U0001d442(\U0001d45e⋅log\U0001d45b)
    //Space Complexity: O(1)
public:
     long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            // For range [l, r], compute total required operations:
            // = (ops to reduce [1..r]  – ops to reduce [1..(l-1)]  + 1) / 2
            ans += (getOps(r) - getOps(l - 1) + 1) / 2;
        }
        return ans;
    }

private:
    // Computes total "division-by-4 steps" needed to reduce all numbers
    // in the range [1..n] down to zero.
    long long getOps(long long n) {
        long long res = 0;
        long long ops = 0;
        // For each powerOfFour = 1, 4, 16, 64, ... <= n:
        for (long long pw = 1; pw <= n; pw *= 4) {
            ++ops;
            long long l = pw;
            long long r = min(n, pw * 4 - 1);
            // Each number in [l..r] requires 'ops' steps.
            res += (r - l + 1) * ops;
        }
        return res;
    }
};