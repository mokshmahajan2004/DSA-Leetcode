class Solution {
public:
    //Overall TC->O(NlogN)+O(N)
    //SC->O(N)  If every element is unique
    int majorityElement(vector<int>& nums) {
      unordered_map<int,int>mpp; //unordered map
      //TC->N Log N (In case of unordered map, in best case and avg case this log N is removed and in worst case, it takes O(N) itself)
      for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
      }
      //TC->O(N)
        for(auto it:mpp){
            if(it.second>(nums.size()/2)){
                return it.first;
            }
        }
     return -1;  
    }
};