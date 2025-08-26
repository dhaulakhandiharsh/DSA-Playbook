class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count how many times each character appears
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }

        // Step 2: Put characters into buckets based on their frequency
        int n = s.size();
        vector<string> bucket(n + 1);
        for (auto &p : count) {
            char c = p.first;
            int freq = p.second;
            bucket[freq].append(freq, c); // repeat character freq times
        }

        // Step 3: Build the answer from high frequency to low frequency
        string result;
        for (int freq = n; freq > 0; freq--) {
            result += bucket[freq];
        }

        return result;
    }
};