class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int st=0,ed=nums.size()-1;
        while(st<=ed){
            int mid=st+(ed-st)/2;
            if(nums[mid]>=target){
                ed=mid-1;
                if(nums[mid]==target)ans[0]=mid;
            }else{
                st=mid+1;
            }
        }
        st=0;
        ed=nums.size()-1;
        while(st<=ed){
            int mid=st+(ed-st)/2;
            if(nums[mid]<=target){
                st=mid+1;
                if(nums[mid]==target)ans[1]=mid;
            }else{
                ed=mid-1;
            }
        }
        return ans;
    }
};