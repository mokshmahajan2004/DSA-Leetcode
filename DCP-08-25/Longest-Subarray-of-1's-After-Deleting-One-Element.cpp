class Solution {
public:
//TC->O(N)
//SC->O(1)
    int longestSubarray(vector<int>& nums) {
        int left=0;
        int right=0;
        bool isDeleted=false;
        int ans=0;
        while(right<nums.size()){
            int num=nums[right];
            if(num==1)
            {
                ans=isDeleted?max(ans,right-left):max(ans,right-left+1);
            }else{
                if(isDeleted){
                    while(nums[left]==1){
                        left+=1;
                    }
                    left+=1;
                }
                else{
                isDeleted=true;
                }
            }
            right+=1;
        }
     return isDeleted?ans:ans-1;   
    }
};