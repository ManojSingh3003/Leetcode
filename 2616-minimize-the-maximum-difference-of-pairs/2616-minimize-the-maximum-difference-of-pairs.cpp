class Solution {
public:
    bool check(vector<int>& nums, int& p, int m){
        int c=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]<=m){
                c++;
                i++;
            }
            if(c>=p)return true;
        }
        return c>=p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int s=0,e=nums[n-1]-nums[0],ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(check(nums,p,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }

        return ans;
    }
};