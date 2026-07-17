class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);
        vector<int> left1(n,-1);
        vector<int> right1(n,n);

        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();

            if(!st.empty())left[i]=st.top();

            st.push(i);
        }    
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();

            if(!st.empty())right[i]=st.top();

            st.push(i);
        } 
        while(!st.empty())st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();

            if(!st.empty())left1[i]=st.top();

            st.push(i);
        }    
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<arr[i]) st.pop();

            if(!st.empty())right1[i]=st.top();

            st.push(i);
        } 


        long long  ans=0;
        long long ans1=0;

        for(int i=0;i<n;i++){
            long long x= (((1LL*arr[i]*1LL*(i-left[i])))*1LL*(right[i]-i));
            ans=(ans+x);
            long long y= (((1LL*arr[i]*1LL*(i-left1[i])))*1LL*(right1[i]-i));
            ans1=(ans1+y);
        }
        return ans1-ans;
    }
};