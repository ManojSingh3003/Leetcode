class Solution {
public:
    string s;
    int n;

    int rev(int ind){
        for(int i=ind+1;i<n;i++){
            if(s[i]==')'){
                reverse(s.begin()+ind+1,s.begin()+i);
                // cout<<s<<" "<<ind<<" "<<i<<endl;
                return i;
            }else if(s[i]=='('){
                i=rev(i);
            }
        }
        return n;
    }

    string reverseParentheses(string s1) {
        s=s1;
        n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                i=rev(i);
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]>='a'&& s[i]<='z')ans+=s[i];
        }
        return ans;
    }
};