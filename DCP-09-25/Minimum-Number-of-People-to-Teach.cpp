class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> knows(m + 1);
        
        // Store languages per user
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                knows[i + 1].insert(lang);
            }
        }

        // Step 1: Find users involved in friendships with no common language
        unordered_set<int> candidates;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            for (int lang : knows[u]) {
                if (knows[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                candidates.insert(u);
                candidates.insert(v);
            }
        }

        if (candidates.empty()) return 0; // Already all can communicate

        // Step 2: Try teaching each language and minimize
        int answer = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int count = 0;
            for (int user : candidates) {
                if (!knows[user].count(lang)) {
                    count++;
                }
            }
            answer = min(answer, count);
        }

        return answer;
    }
};