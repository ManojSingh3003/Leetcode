class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int st=0,ed=n-1;
        int l_mx=h[st],r_mx=h[ed];

        int ans=0;

        while(st<ed){
            l_mx=max(l_mx,h[st]);
            r_mx=max(r_mx,h[ed]);
            if(l_mx>r_mx){
                ans+=(r_mx-h[ed]);
                ed--;
            }
            else {
                ans+=(l_mx-h[st]);
                st++;
            }
        }
        return ans;
    }
};