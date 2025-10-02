class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        map<int,int>freq;
        for(int num : hand){
            freq[num]++;
        }

        map<int, int> :: iterator it;
        for(it = freq.begin(); it != freq.end(); ++it) {
            int start = it->first;
            int count = it->second;

            if(count>0){
                for(int i=0; i<groupSize; i++){
                    if(freq[start + i] < count) return false;
                    freq[start + i] -= count;
                }
            }
        }
        return true;
    }
};