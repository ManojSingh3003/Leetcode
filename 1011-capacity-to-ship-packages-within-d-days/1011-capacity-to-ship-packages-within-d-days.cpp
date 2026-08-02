class Solution {
private:
    bool check(int mid,vector<int>& weights, int days){
        int c=0;
        int x=1;
         
        for(int i=0;i<weights.size();i++){
            if(c+weights[i]<=mid){
                c+=weights[i];
            }
            else{
                x++;
                c=weights[i];
            }
        }
        return x<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int st=*max_element(weights.begin(),weights.end()),ed=accumulate(weights.begin(),weights.end(),0);
        int ans=-1;
        while(st<=ed){
            int mid=st+(ed-st )/2;
            if(check(mid,weights,days)){
                ans=mid;
                ed=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};