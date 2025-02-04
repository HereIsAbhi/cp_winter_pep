#include <iostream>
#include <vector>

using namespace std;

int countSubsequences(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
   
    if (j < 0) return 1;  
    if (i < 0) return 0;  

   
    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == t[j]) {
        dp[i][j] = countSubsequences(s, t, i - 1, j - 1, dp) + countSubsequences(s, t, i - 1, j, dp);
    } else {
        dp[i][j] = countSubsequences(s, t, i - 1, j, dp);
    }

    return dp[i][j];
}

int numDistinct(string s, string t) {
    int m = s.length(), n = t.length();
    vector<vector<int>> dp(m, vector<int>(n, -1)); // Memoization table
    return countSubsequences(s, t, m - 1, n - 1, dp);
}

int main() {
    string s = "rabbbit", t = "rabbit";
    cout << "Distinct Subsequences: " << numDistinct(s, t) << endl;
    return 0;
}
