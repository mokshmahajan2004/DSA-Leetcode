class Solution {
    //TC->O(N)
    //SC->O(1)
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return (i+1);
    }
};