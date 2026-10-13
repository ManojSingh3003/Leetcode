class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)nums[i]=abs(nums[i]);
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<n;i++){
            if(i<(n+1)/2){
                ans+=(nums[i]*nums[i]);
            }else{
                ans-=(nums[i]*nums[i]);
            }
        }
        return ans;
    }
};