class Solution {
public:
    //TC->O(N*Logn)if ordered map
    //TC->O(N*1)if unordered map
    //for unordered map worst time complexity is O(N)
    //SC->O(N)
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ls;
        map<int,int>mpp;
        int n=nums.size();
        int mini=(int)(n/3)+1;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]==mini){
                ls.push_back(nums[i]);
            }
            if(ls.size()==2) break;
        }
        sort(ls.begin(),ls.end());
        return ls;

    }
};