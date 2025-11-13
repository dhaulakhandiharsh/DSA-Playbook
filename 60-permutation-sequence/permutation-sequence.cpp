class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;
        
        // Create list [1, 2, ..., n] and compute n!
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
            fact *= i;
        }
        
        k--; // Convert k to 0-based index
        string result = "";
        
        for (int i = n; i >= 1; i--) {
            fact /= i;  // (i-1)!
            int index = k / fact;
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= fact;
        }
        
        return result;
    }
};