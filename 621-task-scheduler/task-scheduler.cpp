class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for(int i = 0; i<tasks.size() ;i++){
            freq[tasks[i] - 'A']++;
        }
        priority_queue<int>pq;
        for(int i = 0; i<26; i++){
            if(freq[i] > 0 ) pq.push(freq[i]);
        }
        int time = 0;
        while(!pq.empty()){
            vector<int>temp;
            int cycle = n+1;
            for(int i = 0; i<cycle; i++){
                if(!pq.empty()){
                    int f = pq.top(); pq.pop();
                    f--;
                    if(f > 0) temp.push_back(f);
                    time++;
                }
                else{
                    if(temp.empty()) break;
                    time++;
                }

            }
            for(int f:temp) pq.push(f);
        }
        return time ;
    }
}; 