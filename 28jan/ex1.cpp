

int lcs(string &t1,string &t2,int n,int m,vector<vector<int>>& dp){
    if(i>=m || j>=m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(t1[i]==t2[j]){
        return dp[i][j]=1+lcs(t1,t2,i+1,j+1,dp);
    }
    else
        dp[i][j]=max(lcs(t1,t2,i+1,j,dp),lcs(t1,t2,i,j+1,dp));
    return dp[i][j];
    
}

int longestCommonSubsequence(string t1,string t2){
    int n=t1.size();
    int m=t2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return lcs(t1,t2,0,0,dp);
}