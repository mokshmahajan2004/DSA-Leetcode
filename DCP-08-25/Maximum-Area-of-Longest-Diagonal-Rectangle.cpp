class Solution {
//Time Complexity: O(n) where n is number of rectangles
//Space Complexity: O(1)
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonalSq = 0;
        int maxArea = 0;
        
        for(int i = 0; i < dimensions.size(); i++) {
            int length = dimensions[i][0];
            int width = dimensions[i][1];
            
            int diagonalSq = length * length + width * width;
            int area = length * width;
            
            // First priority: longest diagonal
            // Second priority: if diagonals equal, choose larger area
            if(diagonalSq > maxDiagonalSq) {
                maxDiagonalSq = diagonalSq;
                maxArea = area;
            } else if(diagonalSq == maxDiagonalSq && area > maxArea) {
                maxArea = area;
            }
        }
        
        return maxArea;
    }
};
