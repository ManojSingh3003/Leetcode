class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int ans=1e9;
        for(int i=0;i<nums.size();i+=2){
            int x=nums[i],y=nums[i+1];
            int y1=y;
            int d=1;
            while(y1){
                d*=10;
                y1/=10;
            }
            ans=min(ans,x*d+y);
        }
        return ans;
    }
};