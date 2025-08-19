class Solution {
public:
//TC->O(n^3)
//SC->O(n+totalDictsize)
    unordered_set<string> st;
    int n;
    int t[301];

    bool solve(int idx, string &s) {
        if (idx == n) return true;  // reached end
        if (t[idx] != -1) return t[idx];

        for (int l = 1; l <= n - idx; l++) {
            string temp = s.substr(idx, l);
            if (st.find(temp) != st.end() && solve(idx + l, s)) {
                return t[idx] = true;
            }
        }
        return t[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();  // assign to class member
        memset(t, -1, sizeof(t));
        for (string &word : wordDict) {
            st.insert(word);
        }
        return solve(0, s);
    }
};
