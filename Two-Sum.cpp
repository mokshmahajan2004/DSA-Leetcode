class Solution {
public:
    //TC->O(N*LOGN)
    //OR O(N)  UNORDERD MAP OR IN WORST CASE O(N2)
    //SC->O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int a=nums[i];
            int more=target-a;
            if(mpp.find(more)!=mpp.end()){
                return {mpp[more],i};
            }
            mpp[a]=i;
        }
        return {-1,-1};
    }
};