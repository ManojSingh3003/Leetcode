class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=accumulate(nums.begin(),nums.end(),0LL);
        vector<int> diff(n);
        for(int i=0;i<n;i++){
            int x=nums[i];
            vector<int> z(10);
            while(x){
                z[x%10]++;
                x/=10;
            }
            long long y=0;
            long long j=1;
            for(int d=0;d<10;d++){
                while(z[d]--){
                    y+=j*d;
                    j*=10;
                }
            }
            diff[i]=y-nums[i];
        }
        sort(diff.rbegin(),diff.rend());
        ans+=accumulate(diff.begin(),diff.begin()+k,0LL);
        return ans;
    }
};