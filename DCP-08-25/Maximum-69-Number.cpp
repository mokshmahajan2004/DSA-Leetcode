class Solution {
public:
//Interview Approach
//Time Complexity = O(d) ≈ O(1)
//(Since digits are bounded by problem constraints).
//Space Complexity=O(1)
    int maximum69Number (int num) {
        int placeValue=0;
        int placeValueSix=-1;
        
        int temp=num;
        while(temp>0){
            int remain=temp%10;

            if(remain==6)
             placeValueSix=placeValue;
            
            temp=temp/10;
            placeValue++;
        }
        if(placeValueSix==-1) //we never got 6
            return num;

        return num+3*pow(10,placeValueSix); 
    }
};