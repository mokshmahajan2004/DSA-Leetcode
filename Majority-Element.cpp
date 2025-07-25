class Solution {
public:
    //Moore Voting Algorithm
    //TC->O(N)+O(N)
            //This is done to check the majority element, if it is stated that there is 
            //always any majority element present then don't do this.
    //OC->O(1)
    int majorityElement(vector<int>& v) {
        int cnt=0;
        int el;
        for(int i=0;i<v.size();i++){
            if(cnt==0){
                cnt=1;
                el=v[i];
            }
            else if(v[i]==el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        int cnt1=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==el)cnt1++;
        }
        if(cnt1>(v.size()/2)){
            return el;
        }
        return -1;
    }
};