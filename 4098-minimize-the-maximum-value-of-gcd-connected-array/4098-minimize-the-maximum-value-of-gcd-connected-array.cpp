class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(value==1)return -1;

        int sp=2;
        bool q=true;
        if(value%2){
            for(int i=3;i*i<=value;i++){
                if(value%i == 0){
                    sp=i;
                    q=false;
                    break;
                }
            }
            if(q)sp=value;
        }

        long long  left=value-sp,right=value+sp;
        if(index-1 > 0)left-=2LL*(index-1);
        if(index+1  < n-1) right+=2LL*(n-1-index-1);

        if(left<=0 && index > 0)return -1;
        else if(index < n-1)return right; 
        return value;

    }
};