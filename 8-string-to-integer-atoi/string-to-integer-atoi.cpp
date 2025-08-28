class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i;

        // Step 1: Skip leading spaces
        for (i = 0; i < n && s[i] == ' '; i++);

        // Step 2: Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits
        long result = 0;
        for (; i < n && s[i] >= '0' && s[i] <= '9'; i++) {
            int digit = s[i] - '0';

            // Step 4: Overflow check
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
        }

        // Step 5: Apply sign
        return (int)(sign * result);
    }
};