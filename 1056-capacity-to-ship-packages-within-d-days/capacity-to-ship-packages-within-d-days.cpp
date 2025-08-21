class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canShip(weights, days, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

private:
    bool canShip(vector<int>& weights, int days, int cap) {
        int usedDays = 1, load = 0;
        for (int w : weights) {
            if (load + w > cap) {
                usedDays++;
                load = 0;
            }
            load += w;
        }
        return usedDays <= days;
    }
};