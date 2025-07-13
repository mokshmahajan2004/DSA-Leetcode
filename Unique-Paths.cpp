class Solution {
public:
//GOOGLE interview problem
//TC->O(m-1)
//SC->O(1)
    int uniquePaths(int m, int n) {
       int N=n+m-2;
       int r=m-1;
       double res=1;

       for(int i=1;i<=r;i++){
        res=res*(N-r+i)/i;
      
       } 
         return (int)res;
    }
};