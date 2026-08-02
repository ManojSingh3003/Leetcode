class Solution {
 private:
     bool check(int mid,vector<int>& nums, int th){
         int c=0;
         
        for(int i=0;i<nums.size();i++){
            c+=nums[i]/mid;
            if(nums[i]%mid)c++;
        }
     return c<=th;
     }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int st=1,ed=1e9;
        int ans=-1;
        while(st<=ed){
            int mid=st+(ed-st )/2;
            if(check(mid,nums,threshold)){
                ans=mid;
                ed=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};