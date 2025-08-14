class Solution {
public:
//TC->O(n)
//SC->O(1)
    string largestGoodInteger(string num) {
        string ans="";
        for(int i=2;i<num.size();i++){
            if(num[i]==num[i-1]&&num[i]==num[i-2]){
                string curr = num.substr(i-2, 3);
                if(curr>ans) ans=curr;
            }
        }
        return ans;

    }
};