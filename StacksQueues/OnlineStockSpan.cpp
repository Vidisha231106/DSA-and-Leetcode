// 901

class StockSpanner {
public:
    stack <pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=1;
        if (st.empty()!=true){
            while (st.empty()!=true && st.top().first<=price){
                count+=st.top().second;
                st.pop();
            }
        }
        st.push({price, count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */