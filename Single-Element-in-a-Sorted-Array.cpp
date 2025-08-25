class Solution {
public:
//TC->O(logn)
//SC->O(1)
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,high=nums.size()-2;
        while(low<=high){
            int mid=(low+high)>>1;
            if(nums[mid]==nums[mid^1]){
                low=mid+1;                
            }
            else{
                high=mid-1;
            }
        }
        return nums[low];
    }
};

//in order to check for the left half
//1st instance->even index
//2nd instance->odd index, I need to check on the left if the 1st instance of  that number is there or not