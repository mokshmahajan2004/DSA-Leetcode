class Solution {
public:
//TC → O(n×m + d×k×log(k))
// n×m: Iterating through all matrix elements and inserting into map
// d: Number of diagonals (which is n+m-1)
// k: Average elements per diagonal
// log(k): Cost of reverse operation per diagonal

//SC->O(nxm)
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        map<int,vector<int>>mp;
        vector<int>result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        bool flip=true;
        for(auto & it:mp){
            if(flip){
                //it.second ko reverse kardo 
                reverse(it.second.begin(),it.second.end());
            }

            for(int &num:it.second){
                result.push_back(num);
            }
            flip=!flip;
        }
        return result;

    }
};