class Solution {
public:
//TC->O(n)
//SC->O(n) for dp array
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1.0;
        if (n >= k - 1 + maxPts) return 1.0;

        // dp[i]: probability of ending with exactly i points
        // We only need dp up to n
        std::vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        double windowSum = 0.0;   // sum of dp[j] for j in [i - maxPts, i - 1] and j < k
        double result = 0.0;

        // Pre-fill window for i = 1: eligible j are [0] if 0 < k
        windowSum = (0 < k) ? dp[0] : 0.0;

        for (int i = 1; i <= n; ++i) {
            dp[i] = windowSum / maxPts;

            // If we haven't reached k yet at i, dp[i] can contribute to future draws' window
            if (i < k) {
                windowSum += dp[i];
            } else {
                // i >= k are terminal states; add to answer
                result += dp[i];
            }

            // Slide window: remove dp[i - maxPts] if it was within the window and < k
            int left = i - maxPts;
            if (left >= 0 && left < k) {
                windowSum -= dp[left];
            }
        }
        return result;
    }
};
