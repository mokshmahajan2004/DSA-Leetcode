class Solution {
public:
//TC->O(N^2)
//SC->O(1)
    int numberOfPairs(vector<vector<int>>& points) {
     int n = points.size();
        
        // Sort by x ascending, then by y descending
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];  // Same x: higher y first
            return a[0] < b[0];  // Different x: smaller x first
        });
        
        int count = 0;
        
        // Try each point as Alice (upper-left corner)
        for (int i = 0; i < n; i++) {
            int maxY = INT_MIN;  // Track the highest y we've seen so far
            
            // Try each point after i as Bob (lower-right corner)
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                // Check if this can form a valid rectangle
                // (Alice upper-left, Bob lower-right)
                if (x1 <= x2 && y1 >= y2) {
                    // If y2 is lower than any y we've processed so far,
                    // then no point lies between them vertically
                    if (y2 > maxY) {
                        count++;
                        maxY = y2;  // Update the boundary
                    }
                }
            }
        }
        
        return count;
    }
};
