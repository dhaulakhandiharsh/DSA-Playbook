class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        // Determine sign of result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert both numbers to long to avoid overflow and make them positive
        long long a = labs(dividend);
        long long b = labs(divisor);
        long long result = 0;

        
        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }

        // Apply sign
        if (negative) result = -result;

        // Clamp result within 32-bit range
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        return (int)result;
    }
};