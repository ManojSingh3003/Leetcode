class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.length();
        vector<int> ans(n);
        int d=0;
        for(int i=0;i<n;i++){
            if(seq[i]=='(')d++;
            else d--;
            if(seq[i]=='(')ans[i]=d%2;
            else ans[i]=(d+1)%2;
        }
        return ans;
    }
};