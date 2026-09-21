class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();

        vector<long long > res(k,0);
        vector<long long > prev(k,0);

        for(int i=0;i<n;i++){
            vector<long long > curr(k,0);
            curr[ nums[i]%k ]++;

            for(int r=0;r<k;r++){
                int nr=( (long long)r*(nums[i]%k) )%k;
                curr[nr]+=prev[r];
            }

            prev=move(curr);

            for(int r=0;r<k;r++)res[r]+=prev[r];
        }

        return res;
    }
};