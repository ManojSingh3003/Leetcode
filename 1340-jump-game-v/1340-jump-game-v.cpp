class Solution {
private:
    vector<int> memo;

    int dp(int i,int& n,vector<int>& arr,int& d){   

        if(memo[i]!=-1)return memo[i];
        int ans=1;
        for(int j=i+1;j<=min(n-1,i+d);j++){
            if(arr[j]>=arr[i])break;

            ans =max(ans,1+ dp(j,n,arr,d));
        }
        for(int j=i-1;j>=max(0,i-d);j--){
            if(arr[j]>=arr[i])break;

            ans =max(ans,1+ dp(j,n,arr,d));
        } 
        return memo[i]=ans;       
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        memo.resize(n,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans, dp(i,n,arr,d));
        }
        return ans;
    }
};