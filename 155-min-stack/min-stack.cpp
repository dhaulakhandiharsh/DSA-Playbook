class MinStack {
private:
    stack<long long> st;
    long long mn;

public:
    MinStack() {
        mn = 1e9;
    }
    
    void push(int val) {
        if(st.empty()){
            mn = val;
            st.push(val);
        } else{
            if(val >= mn) st.push(val);
            else{
                st.push(2LL * val - mn);
                mn = val;
            }     
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x < mn){
            mn = 2 * mn - x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long x = st.top();
        if(x >= mn) return (int)x;
        return (int)mn;
    }
    
    int getMin() {
        return (int)mn;
    }
};