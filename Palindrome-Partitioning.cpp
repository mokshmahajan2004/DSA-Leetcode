class Solution {
    //TC->O(2^n*n^2)
    //SC->O(2^N*N)
    //Auxilary->O(n)+O(n) //first for path and second for reursion
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        func(0,s,path,res);
        return res;
    }
    void func(int index,string s,vector<string>&path,vector<vector<string>>&res){
        if(index==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=index;i<s.size();++i){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                func(i+1,s,path,res);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])
            return false;
        }
        return true;
    }
};