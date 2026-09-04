class Solution {
public:
    string shortestPalindrome(string s1) {
        string rev_s1=s1;
        reverse(rev_s1.begin(),rev_s1.end());

        string s=s1+'#'+rev_s1;

        int n=s.length();
        vector<int> LPS(n,0);
        int len=0;
        int i=1;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                LPS[i]=len;
                i++;
            }else{
                if(len==0){
                    LPS[i]=0;
                    i++;
                }else{
                    len=LPS[len-1];
                }
            }
        }

        string ans=rev_s1.substr(0,rev_s1.length()-LPS[n-1])+s1;
        return ans;
    }
};