class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.length();
        int mod = 1e9 + 7;
        vector<int> last(26,0);
        int ans=1;
        for(int i=0;i<n;i++){
            int temp=ans;
            ans = ((temp*2)%mod - last[s[i]-'a'] + mod)%mod;
            last[s[i]-'a']=temp;
        }
        ans=(ans-1+mod)%mod;
        return ans;
    }
};