class Solution {
public:
    int mod = 1e9+7;
    int n;
    vector<vector<int>> memo;
    vector<vector<int>> memo2;

    int dp(int i, int j, vector<string>& board){
        if(i==n-1 && j==n-1) return memo[i][j] = 0;

        if(memo[i][j]!=-1)return memo[i][j];

        int ans=-1e9;
        if(i+1<n && j+1<n && board[i+1][j+1]!='X')ans=max(ans, (dp(i+1,j+1,board)+(board[i][j]-'0')) );
        if(i+1<n && board[i+1][j]!='X')ans=max(ans, (dp(i+1,j,board)+(board[i][j]-'0')) );
        if(j+1<n && board[i][j+1]!='X')ans=max(ans, (dp(i,j+1,board)+(board[i][j]-'0')) );

        return memo[i][j]=ans;
    }

    int dp2(int i, int j, vector<string>& board){
        if(board[i][j]=='X')return 0;
        if(i==n-1 && j==n-1) return 1;

        if(memo2[i][j]!=-1)return memo2[i][j];

        long long ans=0;
        
        if(i+1<n && j+1<n && memo[i+1][j+1] != -1e9 &&(memo[i][j]==(memo[i+1][j+1]+(board[i][j]-'0'))) )ans = (ans + dp2(i+1,j+1,board) )%mod;
        if(i+1<n &&memo[i+1][j] != -1e9 && ( memo[i][j]==(memo[i+1][j]+(board[i][j]-'0'))))ans = (ans + dp2(i+1,j,board) )%mod;
        if(j+1<n &&memo[i][j+1] != -1e9 &&  (memo[i][j]==(memo[i][j+1]+(board[i][j]-'0'))))ans = (ans + dp2(i,j+1,board) )%mod;

        return memo2[i][j]=ans;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        memo.assign(n+1,vector<int>(n+1,-1));
        
        board[0][0]='0';
        int mx=dp(0,0,board);

        if(mx<0)return {0,0};

        memo2.assign(n+1,vector<int>(n+1,-1));

        int paths=dp2(0,0,board);

        return {mx,paths};
    }
};