class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& num) {
        stack<int> st;
        vector<int> nums=num;
        for(int i=0;i<num.size();i++)nums.push_back(num[i]);

        vector<int> ans(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }else{
                ans[i]=-1;
            }
            st.push(nums[i]);
        }
        vector<int> ans1;
        for(int  i=0;i<num.size();i++)ans1.push_back(ans[i]);
        return ans1;
    }
};