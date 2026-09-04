class Solution {
public:
    int minAddToMakeValid(string s) {
        int x=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')ans++;
            else ans--;
            if(ans<0){
                ans=0;
                x++;
            }
        }
        if(ans>0)x+=ans;
        return x;
    }
};