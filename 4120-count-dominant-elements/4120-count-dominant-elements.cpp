class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int i=0;i<n;i++){
            int x=0;
            int y=0;
            if(i>0){
                x+=nums[i-1];
                y+=nums[i];    
            }
            if(i<n-1){
                x+=nums[i+1];
                y+=nums[i];
            }
            if(y>=x){
                ans++;
            }
        }
        return ans;
    }
};