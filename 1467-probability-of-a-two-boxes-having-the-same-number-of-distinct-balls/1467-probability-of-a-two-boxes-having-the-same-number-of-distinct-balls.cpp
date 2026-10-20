class Solution {
private:
    double ncr[50][50];
    double memo[8][25][9][9];

    double solve(int i,int b1,int d1,int d2,vector<int>& balls,int n){
        if(b1>n)return 0.0;

        if(i==balls.size()){
            if(b1==n && d1==d2){
                return 1.0;
            }else return 0.0;
        }

        if(memo[i][b1][d1][d2]!=-1.0)return memo[i][b1][d1][d2];

        double ans=0.0;
        for(int x=0;x<=balls[i];x++){
            double way= ncr[balls[i]][x];
            if(x==0) ans+= way*solve(i+1,b1+x,d1,d2+1,balls,n);
            else if(x==balls[i]) ans+= way*solve(i+1,b1+x,d1+1,d2,balls,n);
            else ans+= way*solve(i+1,b1+x,d1+1,d2+1,balls,n);
        }

        return memo[i][b1][d1][d2]=ans;
    }

public:
    double getProbability(vector<int>& balls) {
        int sum=0;
        for(int i=0;i<balls.size();i++){
            sum+=balls[i];
        }
        int n=sum/2;
        
        //ncr
        for(int i=0;i<50;i++){
            ncr[i][0]=1.0;
            for(int j=1;j<=i;j++){
                ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
            }
        }
        double total=ncr[sum][n];
        
        // memo;
        for(int i=0;i<8;i++)
            for(int j=0;j<25;j++)
                for(int k=0;k<9;k++)
                    for(int l=0;l<9;l++)
                        memo[i][j][k][l]=-1.0;

        double valid=solve(0,0,0,0,balls,n);

        return valid/total;
    }
};