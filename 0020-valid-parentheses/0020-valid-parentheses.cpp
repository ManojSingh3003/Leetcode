class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                q.push(s[i]);
            }else{
                if(q.empty())return false;
                char t=q.top();
            if(t=='('&& s[i]==')'){
                q.pop();
            }
            else if(t=='['&& s[i]==']'){
                q.pop();
            }
            else if(t=='{'&& s[i]=='}'){
                q.pop();
            }
            else{
                return false;
            }
            }
        }
        if(q.empty())return true;
        return false;
    }
};