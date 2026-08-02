class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> x(2007);
        for(int i=0;i<arr.size();i++){
            x[arr[i]]=1;
        }
        int j=0;
        for(int i=1;i<2007;i++){
            if(x[i]==0){
                j++;
            }
            if(j==k){
                return i;
            }
        }
        return -1;
    }
};