#include<bits/stdc++.h>
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //transpose 
        //o(N/2*N/2)
        for(int i=0; i<n-1;i++){
            for(int j=i+1; j<n; j++){
            swap(matrix[i][j],matrix[j][i]);
            
        }
    }
    //reverse
    //o(N*N/2)
    for (int i=0; i<n;i++){
        //row is mat[i]
        reverse(matrix[i].begin(),matrix[i].end());
    }
    }
};