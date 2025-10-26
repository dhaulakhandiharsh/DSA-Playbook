class SummaryRanges {
    map<int, int> intervals; // key = start, value = end
public:
    SummaryRanges() {}

    void addNum(int val) {
        if (intervals.empty()) {
            intervals[val] = val;
            return;
        }

        // Find the first interval with start > val
        auto it = intervals.upper_bound(val);
        int start = val, end = val;

        // Check if val can be merged with previous interval
        if (it != intervals.begin()) {
            auto prev = it;
            --prev;
            if (prev->second >= val) return;               // Already covered
            if (prev->second + 1 == val) start = prev->first;
        }

        // Merge with next interval if adjacent
        if (it != intervals.end() && it->first == val + 1) {
            end = it->second;
            intervals.erase(it);
        }

        // Merge with previous interval if adjacent
        if (start != val) {
            auto prev = intervals.lower_bound(start);
            --prev;
            if (prev->second + 1 >= val) {
                end = max(end, prev->second);
                start = prev->first;
                intervals.erase(prev);
            }
        }

        intervals[start] = end;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto &p : intervals) {
            res.push_back({p.first, p.second});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */