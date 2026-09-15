class Solution {
    vector<int> memo;

private:
    bool ispali(string  &s,int st,int ed){
        while(st<ed){
            if(s[st]!=s[ed])return false;
            st++;
            ed--;
        }
        return true;
    }

    int dp(int i,int &k,int& n,string& s){
        if(i>=n)return 0;

        if(memo[i]!=-1)return memo[i];

        int ans=dp(i+1,k,n,s);
        for(int j=i+k-1;j<n;j++){
            if(ispali(s,i,j)){
                ans=max(ans, 1+dp(j+1,k,n,s));
                break;
            }
        }
        return memo[i]=ans;
    }

public:
    int maxPalindromes(string s, int k) {
        int n=s.length();
        memo.assign(n+1,-1);

        int x=dp(0,k,n,s);
        return x;
    }
};