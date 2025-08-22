class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        if(strs.empty()) return "";
        for(int i=0; i<strs.size(); i++){
            while(strs[i].find(prefix) != 0){
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};