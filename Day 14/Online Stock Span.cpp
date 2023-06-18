class StockSpanner {
public:
    stack<pair<int,int>>st;
    int curr=0;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int curr=1;
        while(!st.empty() && price >= st.top().first){
            curr += st.top().second;
            st.pop();
        }
        
        st.push({price,curr});
        
        return curr;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
