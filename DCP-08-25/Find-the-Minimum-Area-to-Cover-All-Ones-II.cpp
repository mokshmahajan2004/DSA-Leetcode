class Solution {
public:
    //TC->O((C2+R2+R⋅C)⋅(R+C))
    //SC->O(R⋅C)
    int minimumSum(vector<vector<int>>& grid) {
       int R = grid.size();
        if (R == 0) return 0;
        int C = grid[0].size();

        // Fast check: if there are no 1s, area is 0 (we can split empty area without cost).
        int totalOnes = 0;
        for (auto &row : grid) for (int v : row) totalOnes += v;
        if (totalOnes == 0) return 0;

        // Build row-wise and column-wise prefix sums of ones
        // rowPref[r][c] = number of ones in row r in columns [0..c-1]
        vector<vector<int>> rowPref(R, vector<int>(C + 1, 0));
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) rowPref[r][c + 1] = rowPref[r][c] + grid[r][c];
        }
        // colPref[c][r] = number of ones in column c in rows [0..r-1]
        vector<vector<int>> colPref(C, vector<int>(R + 1, 0));
        for (int c = 0; c < C; ++c) {
            for (int r = 0; r < R; ++r) colPref[c][r + 1] = colPref[c][r] + grid[r][c];
        }

        auto hasOnesInRowBand = [&](int r, int c1, int c2) -> bool {
            if (c1 > c2) return false;
            return rowPref[r][c2 + 1] - rowPref[r][c1] > 0;
        };
        auto hasOnesInColBand = [&](int c, int r1, int r2) -> bool {
            if (r1 > r2) return false;
            return colPref[c][r2 + 1] - colPref[c][r1] > 0;
        };

        // Compute tight bounding rectangle area of ones in submatrix [r1..r2] x [c1..c2]
        auto areaOfRegion = [&](int r1, int r2, int c1, int c2) -> int {
            if (r1 > r2 || c1 > c2) return 0;
            int minR = INT_MAX, maxR = -1;
            for (int r = r1; r <= r2; ++r) {
                if (hasOnesInRowBand(r, c1, c2)) {
                    minR = min(minR, r);
                    maxR = max(maxR, r);
                }
            }
            if (maxR == -1) return 0; // no ones here
            int minC = INT_MAX, maxC = -1;
            for (int c = c1; c <= c2; ++c) {
                if (hasOnesInColBand(c, minR, maxR)) {
                    minC = min(minC, c);
                    maxC = max(maxC, c);
                }
            }
            return (maxR - minR + 1) * (maxC - minC + 1);
        };

        long long best = LLONG_MAX;

        // --- Case A: two vertical cuts => three vertical bands
        for (int c1 = 0; c1 + 1 < C; ++c1) {
            for (int c2 = c1 + 1; c2 + 0 < C; ++c2) {
                long long s = 0;
                s += areaOfRegion(0, R - 1, 0, c1);
                s += areaOfRegion(0, R - 1, c1 + 1, c2);
                s += areaOfRegion(0, R - 1, c2 + 1, C - 1);
                best = min(best, s);
            }
        }

        // --- Case B: two horizontal cuts => three horizontal bands
        for (int r1 = 0; r1 + 1 < R; ++r1) {
            for (int r2 = r1 + 1; r2 + 0 < R; ++r2) {
                long long s = 0;
                s += areaOfRegion(0, r1, 0, C - 1);
                s += areaOfRegion(r1 + 1, r2, 0, C - 1);
                s += areaOfRegion(r2 + 1, R - 1, 0, C - 1);
                best = min(best, s);
            }
        }

        // --- Case C: one vertical cut, then split LEFT side horizontally
        for (int c = 0; c + 0 < C; ++c) {
            for (int r = 0; r + 0 < R; ++r) {
                long long s = 0;
                s += areaOfRegion(0, r, 0, c);
                s += areaOfRegion(r + 1, R - 1, 0, c);
                s += areaOfRegion(0, R - 1, c + 1, C - 1);
                best = min(best, s);
            }
        }

        // --- Case D: one vertical cut, then split RIGHT side horizontally
        for (int c = 0; c + 0 < C; ++c) {
            for (int r = 0; r + 0 < R; ++r) {
                long long s = 0;
                s += areaOfRegion(0, R - 1, 0, c);
                s += areaOfRegion(0, r, c + 1, C - 1);
                s += areaOfRegion(r + 1, R - 1, c + 1, C - 1);
                best = min(best, s);
            }
        }

        // --- Case E: one horizontal cut, then split TOP side vertically
        for (int r = 0; r + 0 < R; ++r) {
            for (int c = 0; c + 0 < C; ++c) {
                long long s = 0;
                s += areaOfRegion(0, r, 0, c);
                s += areaOfRegion(0, r, c + 1, C - 1);
                s += areaOfRegion(r + 1, R - 1, 0, C - 1);
                best = min(best, s);
            }
        }

        // --- Case F: one horizontal cut, then split BOTTOM side vertically
        for (int r = 0; r + 0 < R; ++r) {
            for (int c = 0; c + 0 < C; ++c) {
                long long s = 0;
                s += areaOfRegion(0, r, 0, C - 1);
                s += areaOfRegion(r + 1, R - 1, 0, c);
                s += areaOfRegion(r + 1, R - 1, c + 1, C - 1);
                best = min(best, s);
            }
        }

        return (int)best;
    }
};