class Solution {
public:
    int mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n=s.length();
        vector<int> freq(26);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        for(int i=0;i<t;i++){

            vector<int> freq1(26);
            for(int j=1;j<26;j++){
                freq1[j]=freq[j-1];
            }
            freq1[0]=(1LL*freq1[0]+freq[25])%mod;
            freq1[1]=(1LL*freq1[1]+freq[25])%mod;

            freq=freq1;
        }

        long long ans=0;
        for(int i=0;i<26;i++){
            ans=(ans+freq[i])%mod;
        }
        return ans;
    }
};