//use two stacks, one store inputs, one store descending mins
class MinStack {
public:
    stack<int> st;
    stack<int> mins;
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if (mins.empty() || x <= mins.top()) mins.push(x);
    }
    
    void pop() {
        if (mins.top() == st.top()) mins.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

//use one stack, while meet new min, put cur min before the new num
//so that when we go back and meet the border, we know the old cur min
class MinStack {
public:
    stack<int> st;
    int curMin;
    MinStack() {
        curMin = INT_MAX;
    }
    
    void push(int x) {
        if (x <= curMin){
            st.push(curMin);
            curMin = x;
        }
        st.push(x);
    }
    
    void pop() {
        int t = st.top();
        st.pop();
        if (t == curMin){
            curMin = st.top();
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return curMin;
    }
};