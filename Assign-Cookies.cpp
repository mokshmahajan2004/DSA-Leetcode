class Solution {
public:

//TC->(2nlogn+2mlogm+m or n)
//SC->O(1)
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=g.size();
        int n=s.size();
        int l=0,r=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(l<m && r<n){
          if(g[l]<=s[r]){
            r=r++;
            l++;
          }  
          r++;
        }
        return l;
    }
};