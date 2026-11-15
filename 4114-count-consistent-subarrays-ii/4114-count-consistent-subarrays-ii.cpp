class Solution {
public:
    long long countConsistent(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n),right(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && ((nums[st.top()]&nums[i])==nums[i]) && nums[st.top()]>nums[i] ){
                st.pop();
            }
            if(st.empty()){
                left[i]=-1;
            }else{
                left[i]=st.top();
            }
            st.push(i);
        }

        while(!st.empty())st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && ((nums[st.top()]&nums[i])==nums[i]) ){
                st.pop();
            }
            if(st.empty()){
                right[i]=n;
            }else{
                right[i]=st.top();
            }
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=1LL*(i-left[i])*(right[i]-i);
        }

        return ans;
    }
};