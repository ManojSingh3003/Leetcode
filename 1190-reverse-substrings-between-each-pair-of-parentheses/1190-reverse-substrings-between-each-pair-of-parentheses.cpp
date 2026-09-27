class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                int ind=st.top();
                st.pop();
                reverse(s.begin()+ind+1,s.begin()+i);
            }
        }

        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]>='a'&& s[i]<='z')ans+=s[i];
        }
        return ans;
    }
};