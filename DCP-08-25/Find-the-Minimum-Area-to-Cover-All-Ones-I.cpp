class Solution {
public:
//Time Complexity: O(R × C)
//Space Complexity:O(1)
    int minimumArea(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int minRow = rows, maxRow = -1;
        int minCol = cols, maxCol = -1;

        // Traverse the grid to find bounds of rectangle
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    minRow = min(minRow, r);
                    maxRow = max(maxRow, r);
                    minCol = min(minCol, c);
                    maxCol = max(maxCol, c);
                }
            }
        }

        // If no 1s found, return 0
        if (maxRow == -1) return 0;

        int height = maxRow - minRow + 1;
        int width = maxCol - minCol + 1;
        return height * width;
    }
};