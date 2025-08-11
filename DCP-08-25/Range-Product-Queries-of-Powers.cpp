class Solution {
public:
    //TC->O(Q*32)
    //SC->O(1)//We are using both arrays to store ans and required in question
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
       vector<int>powers;
       vector<int>result;
       for(int i=0;i<32;i++){
        //To Check whether ith bit is set or not
        if((n&(1<<i))!=0){
            powers.push_back(1<<i);
        }
       }

       for(auto &query: queries){ //TC->Q
        int start=query[0];
        int end=query[1];
        long product=1;
        int M=1e9+7;
        for(int i=start;i<=end;i++){//TC->O(32)
            product=(product*powers[i])%M;//Total TC->O(Q*32)
        }
        result.push_back(product);
       }
       return result;
    }
};