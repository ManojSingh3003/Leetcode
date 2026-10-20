class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        vector<bool> opened(n,false);
        vector<bool> key(n,false);
        vector<bool> box(n,false);
        
        int ans=0;
        queue<int> q;

        for(int i=0;i<initialBoxes.size();i++){
            box[initialBoxes[i]]=1;
            if(status[initialBoxes[i]]==1){
                opened[initialBoxes[i]]=1;
                q.push(initialBoxes[i]);
            }
        }

        while(!q.empty()){
            int cur=q.front();
            q.pop();

            ans+=candies[cur];

            for(int k:keys[cur]){
                key[k]=1;
                if(box[k] && !opened[k]){
                    q.push(k);
                    opened[k]=1;
                }
            }

            for(int b:containedBoxes[cur]){
                box[b]=1;
                if((status[b]==1 || key[b]) && (!opened[b])){
                    q.push(b);
                    opened[b]=1;
                }
            }
        }
        return ans;
    }
};