class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int totalLeft = (m + n + 1) / 2;

        int left = 0, right = m;
        while (left <= right) {
            int i = (left + right) / 2;   // partition nums1
            int j = totalLeft - i;        // partition nums2

            int L1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int R1 = (i == m) ? INT_MAX : nums1[i];
            int L2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int R2 = (j == n) ? INT_MAX : nums2[j];

            if (L1 <= R2 && L2 <= R1) {
                if ((m + n) % 2 == 0) {
                    return (max(L1, L2) + min(R1, R2)) / 2.0;
                } else {
                    return max(L1, L2);
                }
            } else if (L1 > R2) {
                right = i - 1;  // move left
            } else {
                left = i + 1;   // move right
            }
        }
        return 0.0; // should never reach here
    }
};;