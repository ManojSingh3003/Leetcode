class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        char mx='a',mn='z';
        for(int i=0;i<n;i++){
            mx=max(mx,s[i]);
            mn=min(mn,s[i]);
        }
        string s1=s;
        sort(s1.begin(),s1.end());
        if(s1==s){
            return 0;
        }
        if(n==2)return -1;
        if(s[0]==mn || s[n-1]==mx)return 1;
        for(int i=1;i<n-1;i++){
            if(s[i]==mn || s[i]==mx)return 2;
        }
        return 3;
    }
};