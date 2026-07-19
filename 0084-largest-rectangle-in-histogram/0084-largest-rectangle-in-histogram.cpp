class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);

        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]>=h[i]) st.pop();

            if(!st.empty())left[i]=st.top();

            st.push(i);
        }    
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>h[i]) st.pop();

            if(!st.empty())right[i]=st.top();

            st.push(i);
        } 

        int ans=0;
        for(int i=0;i<n;i++){
            int area=h[i]*(right[i]-left[i]-1);
            ans=max(ans,area);
        }
        return ans;
    }
};