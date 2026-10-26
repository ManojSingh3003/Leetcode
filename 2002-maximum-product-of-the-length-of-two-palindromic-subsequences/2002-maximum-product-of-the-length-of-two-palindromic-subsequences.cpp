class Solution {
public:
    int ans=0;

    bool pali(string &a){
        int i=0,j=a.length()-1;
        while(i<j){
            if(a[i]!=a[j])return false;
            i++;j--;
        }
        return true;
    }

    void dp(string &s ,int i,string s1,string s2){
        if(i>=s.length()){
            if(pali(s1) && pali(s2)){
                ans=max(ans, (int)s1.length()*(int)s2.length() );
                
            }
            return;
        }

        dp(s,i+1,s1+s[i],s2);

        dp(s,i+1,s1,s2+s[i]);

        dp(s,i+1,s1,s2);
    }

    int maxProduct(string s) {
        string s1="",s2="";
        dp(s,0,s1,s2);
        return ans;
    }
};