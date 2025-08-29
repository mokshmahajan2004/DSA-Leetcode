class Solution {
public:
//TC->O(1)
//SC->O(1)
    long long flowerGame(int n, int m) {
       long long oddX = (n + 1) / 2;
        long long evenX = n / 2;
        long long oddY = (m + 1) / 2;
        long long evenY = m / 2;
        
        return oddX * evenY + evenX * oddY; 
    }
};