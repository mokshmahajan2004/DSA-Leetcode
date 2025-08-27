class Solution {
public:
//Time Complexity: O(m × n × max(m,n))
//Space Complexity: O(m × n)

    // Four diagonal directions: NE, SE, SW, NW (clockwise order)
    vector<vector<int>> dirs = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    
    // Memoization table: [row][col][turned][expectedValue][direction]
    int memo[500][500][2][2][4];
    
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // Initialize memoization array with -1
        memset(memo, -1, sizeof(memo));
        
        int maxLength = 0;
        
        // Try starting from every cell with value 1
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    // Try all 4 diagonal directions from this starting point
                    for(int d = 0; d < 4; d++) {
                        int nextRow = i + dirs[d][0];
                        int nextCol = j + dirs[d][1];
                        
                        // Start DFS: length=1 (current cell) + DFS result
                        int length = 1 + dfs(grid, nextRow, nextCol, false, 2, d);
                        maxLength = max(maxLength, length);
                    }
                }
            }
        }
        
        return maxLength;
    }
    
private:
    int dfs(vector<vector<int>>& grid, int row, int col, bool hasTurned, 
            int expectedValue, int direction) {
        int m = grid.size(), n = grid[0].size();
        
        // Check boundaries
        if(row < 0 || row >= m || col < 0 || col >= n) {
            return 0;
        }
        
        // Check if current cell matches expected value
        if(grid[row][col] != expectedValue) {
            return 0;
        }
        
        // Check memoization (map expectedValue: 2->1, 0->0 for indexing)
        int valueIdx = (expectedValue == 2) ? 1 : 0;
        if(memo[row][col][hasTurned ? 1 : 0][valueIdx][direction] != -1) {
            return memo[row][col][hasTurned ? 1 : 0][valueIdx][direction];
        }
        
        // Calculate next expected value in sequence (2 -> 0 -> 2 -> 0...)
        int nextExpectedValue = (expectedValue == 2) ? 0 : 2;
        
        // Option 1: Continue in same direction
        int nextRow = row + dirs[direction][0];
        int nextCol = col + dirs[direction][1];
        int result = 1 + dfs(grid, nextRow, nextCol, hasTurned, nextExpectedValue, direction);
        
        // Option 2: Make a clockwise turn (only if haven't turned yet)
        if(!hasTurned) {
            int newDirection = (direction + 1) % 4; // Clockwise 90-degree turn
            int turnRow = row + dirs[newDirection][0];
            int turnCol = col + dirs[newDirection][1];
            
            int turnResult = 1 + dfs(grid, turnRow, turnCol, true, nextExpectedValue, newDirection);
            result = max(result, turnResult);
        }
        
        // Store result in memoization table and return
        return memo[row][col][hasTurned ? 1 : 0][valueIdx][direction] = result;
    }
};
