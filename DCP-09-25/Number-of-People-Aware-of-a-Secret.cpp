class Solution {
public:

//TC-> O(n)
//SC->O(n)
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0); // dp[i] = people who learn on day i
        vector<long long> share(n + 2, 0); // difference array for propagation
        
        dp[1] = 1; // day 1, one person knows
        share[1 + delay] += 1;      // they start sharing
        if (1 + forget <= n) share[1 + forget] -= 1; // they stop sharing

        long long activeSharers = 0;
        for (int day = 2; day <= n; day++) {
            activeSharers = (activeSharers + share[day]) % MOD; // how many are sharing today
            dp[day] = activeSharers; // these many new people learn today

            // update share ranges for new learners
            if (day + delay <= n) {
                share[day + delay] = (share[day + delay] + dp[day]) % MOD;
            }
            if (day + forget <= n) {
                share[day + forget] = (share[day + forget] - dp[day] + MOD) % MOD;
            }
        }

        // Sum people who still remember on day n
        long long ans = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if (day >= 1) ans = (ans + dp[day]) % MOD;
        }
        return ans;
    }
};
