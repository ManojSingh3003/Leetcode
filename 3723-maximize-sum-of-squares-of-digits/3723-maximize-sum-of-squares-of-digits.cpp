class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s="";
        for(int i=1;i<=num;i++){
            char d;
            if(sum>9){d='0'+9;sum-=9;}
            else {d='0'+sum;sum=0;}
            s+=d;
        }
        if(sum!=0)s="";
        return s;
    }
};