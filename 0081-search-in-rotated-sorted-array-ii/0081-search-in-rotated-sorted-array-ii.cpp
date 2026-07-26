class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(target==nums[mid]){
                return true;
            }

            if(nums[s] == nums[mid] && nums[mid] == nums[e]) {
                s++;
                e--;
            }
            else if(nums[mid]>=nums[s]){
                if(target<nums[mid]&&target>=nums[s]){
                    e=mid-1;
                }
                else{s=mid+1;}
                
            }
            else{
                if(target>nums[mid]&&target<=nums[e]){
                    s=mid+1;
                }
                else {e=mid-1;}
            }
            mid=s+(e-s)/2;
        }
        return false;
    }
};