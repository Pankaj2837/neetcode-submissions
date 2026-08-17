class MinStack {
   private:
    std::vector<int> st;
    std::vector<int> min_st;

   public:
    MinStack() {}
    void push(int val) {
        st.push_back(val);
        if (min_st.empty() || val <= min_st.back()) {
            min_st.push_back(val);
        }
    }

    void pop() {
        if (st.back() == min_st.back()) {
            min_st.pop_back();
        }
        st.pop_back();
    }

    int top() { return st.back(); }

    int getMin() { return min_st.back(); }
};