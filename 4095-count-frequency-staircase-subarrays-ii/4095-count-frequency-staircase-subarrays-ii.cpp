class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        
        int max_val = 0;
        for (int x : nums) {
            if (x > max_val) max_val = x;
        }
        
        vector<int> freq(max_val + 1, 0);
        vector<int> req(max_val + 1, 0);
        long long ans = 0;
        
        for (int L = 0; L < n; ++L) {
            int count = 0; 
            int R = L;
            
            for (; R < n; ++R) {
                int x = nums[R];
                
                if (freq[x] == 0) {
                    count++;
                    
                    if (1LL * count * (count + 1) / 2 > n - L) {
                        break; 
                    }
                    
                    req[x] = count;
                }
                
                freq[x]++;
                
                if (freq[x] > req[x]) {
                    break;
                }
                
                int len = R - L + 1;
                int required_len = count * (count + 1) / 2;
                
                if (len == required_len) {
                    ans++;
                }
            }
            
            for (int p = L; p <= R && p < n; ++p) {
                freq[nums[p]] = 0;
            }
        }
        
        return ans;
    }
};