class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            unordered_map<int, int> rank;

            int distinct = 0;
            int good = 0;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                if (!rank.count(x)) {
                    rank[x] = ++distinct;
                    freq[x] = 1;

                    if (distinct == 1) good++;
                } else {
                    int r = rank[x];

                    if (freq[x] == r) good--;

                    freq[x]++;

                    if (freq[x] == r) good++;
                }

                if (good == distinct) ans++;
            }
        }

        return ans;
    }
};