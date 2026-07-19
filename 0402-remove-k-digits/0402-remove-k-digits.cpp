class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        
        if(k==n)return "0";
        string ans = "";
        
        for (int i = 0; i < n; i++) {
            char c = num[i];
            
            while (k > 0 && !ans.empty() && ans.back() > c) {
                ans.pop_back();
                k--;
            }
            if (ans.empty() && c == '0') {
                continue; 
            }
            ans += c;
        }

        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }

        if (ans.empty()) {
            return "0";
        } else {
            return ans;
        }
    }
};