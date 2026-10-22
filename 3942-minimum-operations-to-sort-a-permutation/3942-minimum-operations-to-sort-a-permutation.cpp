class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int st=-1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini=nums[i];
                st=i;
            }
        }

        //front
        bool front=true;
        int steps=n-1;
        int curr_ind=st;
        while(steps--){
            int next_ind=(curr_ind+1)%n;
            if(nums[curr_ind]>nums[next_ind]){
                front=false;
                break;
            }
            curr_ind=next_ind;
        }

        //back
        bool back=true;
        steps=n-1;
        curr_ind=st;
        while(steps--){
            int next_ind=(curr_ind-1+n)%n;
            if(nums[curr_ind]>nums[next_ind]){
                back=false;
                break;
            }
            curr_ind=next_ind;
        }
        if(front||back){
            int ans=INT_MAX;
            if(front){
                ans=min(ans,min(st,n-st+2));
            }
            if(back){
                ans=min(ans,min(n-st,st+2));
            }
            
            return ans;
        }else{
            return -1;
        }
    }
};