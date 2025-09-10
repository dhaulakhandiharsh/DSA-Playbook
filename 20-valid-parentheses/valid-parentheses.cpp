class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // If opening bracket, push onto stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                // If stack is empty → no match
                if (st.empty()) return false;
                
                char top = st.top();
                st.pop();
                
                // Check matching pair
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        
        // At the end, stack should be empty
        return st.empty();
    }
};