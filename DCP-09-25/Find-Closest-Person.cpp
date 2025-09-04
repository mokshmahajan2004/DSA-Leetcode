class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xz=0,yz=0;
        if(x>z){
            xz=x-z;
        }
        else{
            xz=z-x;
        }
        if(y>z){
            yz=y-z;
        }
        else{
            yz=z-y;
        }
        if(yz>xz){
            return 1;
        }
        else if(yz<xz){
            return 2;
        }
        return 0;
        
    }
};