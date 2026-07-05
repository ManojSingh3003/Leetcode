class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int> bed;
        bed.push_back(0);
        for(int i=0;i<flowerbed.size();i++){
            bed.push_back(flowerbed[i]);
        }
        bed.push_back(0);
        int ans=0;
        for(int i=1;i<bed.size()-1;i++){
            if(bed[i]==0 && bed[i-1]==0 && bed[i+1]==0){
                bed[i]= 1;
                ans++;
            }
        }
        if(ans>=n)return true;
        return false;
    }
};