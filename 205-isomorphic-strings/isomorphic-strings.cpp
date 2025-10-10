#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        array<int, 256> ms; ms.fill(-1);
        array<int, 256> mt; mt.fill(-1);
        for(size_t i = 0; i < s.size(); ++i){
            unsigned char cs = s[i];
            unsigned char ct = t[i];
            if(ms[cs] == -1 && mt[ct] == -1){
                ms[cs] = ct;
                mt[ct] = cs;
            } else {
                if(ms[cs] != ct || mt[ct] != cs) return false;
            }
        }
        return true;
    }
};