class StockSpanner {
    stack<pair<int,int>> st;
    int i;
public:
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        while(!st.empty()){
            if(st.top().first<=price){
                st.pop();
            }else{
                break;
            }
        }
        int ind=-1;
        if(!st.empty()){
            ind=st.top().second;
        }
        st.push({price,i});
        i++;
        return i-1 -ind;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */