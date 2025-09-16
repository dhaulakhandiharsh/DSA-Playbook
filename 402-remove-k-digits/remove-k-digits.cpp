#include <string>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for(char c: num) {
            while(k>0 && !st.empty() && st.back() > c) {
                st.pop_back();
                --k;
            }
            st.push_back(c);
        }
        if(k>0) {
            if(k >= (int)st.size()) return "0";
            st.resize(st.size() - k);
        }
        int i = 0;
        while(i < (int)st.size() && st[i] == '0') ++i;
        string res = st.substr(i);
        if(res.empty()) return "0";
        return res;
    }
};