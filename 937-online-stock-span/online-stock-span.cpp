class StockSpanner {
public:
    StockSpanner() {
       
        
    }
     stack<pair<int,int>>st;
        int idx =0;
    
    int next(int price) {
        idx++;
        while(!st.empty()&& st.top().first<=price){
            st.pop();
        }
        int ans= st.empty() ? idx:idx-st.top().second;
        st.push({price,idx});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */