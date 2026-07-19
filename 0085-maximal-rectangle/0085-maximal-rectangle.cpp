class Solution {
private:
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> p(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    p[i][j]=matrix[i][j]-'0';
                }else{
                    if(matrix[i][j]=='1'){
                        p[i][j]=p[i-1][j]+1;
                    }else{
                        p[i][j]=0;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,largestRectangleArea(p[i]));
        }
        return ans;
    }
};