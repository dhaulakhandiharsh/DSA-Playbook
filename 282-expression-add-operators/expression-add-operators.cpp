class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        backtrack(num, target, 0, 0, 0, "", res);
        return res;
    }

    void backtrack(string &num, int target, int pos, long currVal, long prevNum, string expr, vector<string> &res) {
        if (pos == num.size()) {
            if (currVal == target)
                res.push_back(expr);
            return;
        }

        for (int i = pos; i < num.size(); i++) {
            // avoid numbers with leading zeros
            if (i != pos && num[pos] == '0') break;
            
            string currStr = num.substr(pos, i - pos + 1);
            long currNum = stol(currStr);

            if (pos == 0) {
                // first number, no operator
                backtrack(num, target, i + 1, currNum, currNum, currStr, res);
            } else {
                backtrack(num, target, i + 1, currVal + currNum, currNum, expr + "+" + currStr, res);
                backtrack(num, target, i + 1, currVal - currNum, -currNum, expr + "-" + currStr, res);
                backtrack(num, target, i + 1, currVal - prevNum + prevNum * currNum, prevNum * currNum, expr + "*" + currStr, res);
            }
        }
    }
};