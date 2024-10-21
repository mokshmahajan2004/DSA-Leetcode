class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";
        
        for (char c : s) {
            // If result is not empty and the last character is the same as the current one, remove it
            if (!result.empty() && result.back() == c) {
                result.pop_back();
            } 
            // Otherwise, append the current character
            else {
                result.push_back(c);
            }
        }
        
        return result;
    }
};
