class Solution {
private:
    bool check(int mid,vector<int>& piles, int h){
        long long x=0;
        for(int i=0;i<piles.size();i++){
            x+=piles[i]/mid;
            if(piles[i]%mid)x++;
        }
        return x<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1,e=*max_element(piles.begin(),piles.end());
        int ans=e;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(check(mid,piles,h)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};