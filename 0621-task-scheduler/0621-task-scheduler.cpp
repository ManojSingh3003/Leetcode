class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans=0;
        map<char,int> mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        vector<int> x;
        int mx=-1;
        int c=0;
        for(auto &it:mp){
            if(it.second>mx){
                mx=it.second;
                c=1;
            }else if(it.second==mx){
                c++;
            }
        }

        ans=(n+1)*(mx-1)+c;
        ans=max(ans,(int)tasks.size());
        return ans;
    }
};