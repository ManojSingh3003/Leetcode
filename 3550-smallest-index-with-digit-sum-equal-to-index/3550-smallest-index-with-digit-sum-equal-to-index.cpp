class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int sum=0;
            while(x){
                int d=x%10;
                sum+=d;
                x/=10;
            }
            if(sum==i)return i;
        }
        return -1;
    }
};