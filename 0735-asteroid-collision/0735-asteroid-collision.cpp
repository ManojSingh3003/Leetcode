class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n=a.size();
        stack<int> st;

        for(int i=0;i<n;i++){
            int x=a[i];
            bool alive=1;

            
            while(!st.empty() && st.top()>0 && x<0){
                if(abs(x)==abs(st.top())){
                    st.pop();
                    alive=0;
                    break;
                }else if(abs(x)>abs(st.top())){
                    st.pop();
                }else {
                    alive=0;
                    break;
                }
            }
            if(alive)st.push(x);
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};