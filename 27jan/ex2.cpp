// Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
// For example, if n=3, there are 4 ways:

// 1+1+1
// 1+2
// 2+1
// 3

// Input
// The only input line has an integer n.
// Output
// Print the number of ways modulo 10^9+7.
// Constraints

// 1 \le n \le 10^6

// Example
// Input:
// 3

// Output:
// 4

#include <iostream>
#include <vector>
#include <cmath>


using namespace std;



const int MOD=1e9+7;
int countWays(int n,vector<int>& ans){
    if(n==0) return 1;
    if(n<0) return 0;
    if(ans[n]!=-1) return ans[n];
    int ways=0;

    for(int j=1;j<=6;j++){
        if(n-j>=0) ways=(ways+countWays(n-j,ans))%MOD;
        
    }
    return ans[n]=ways;
        

    

}

int main(){
    int n;
    cin >> n;
    vector<int> ans(n+1,-1);
    cout << countWays(n,ans) << endl;
    return 0;
}


// int countWays(int n){
//     vector<int> dp(n+1, 0);
//     dp[0] = 1;
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= 6; j++){
//             if(j > i) break;
//             dp[i] = (dp[i] + dp[i-j]) % (int)(pow(10, 9) + 7);
//         }
//     }
//     return dp[n];
// }

// int main(){
//     int n;
//     cin >> n;
//     cout << countWays(n) << endl;
    
// }