class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> mn(n,INT_MAX);
        int l=0;
        int sum=0;
        int best=INT_MAX;
        int ans=INT_MAX;
        for(int r=0;r<n;r++){
            sum+=arr[r];
            while(sum>target && l<=r){
                sum-=arr[l];
                l++;
            }
            if(sum==target){
                if(l>0 && mn[l-1]!=INT_MAX){
                    ans=min(ans , r-l+1 +mn[l-1]);
                }
                best=min(best,r-l+1);
            }
            mn[r]=best;
        }
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};