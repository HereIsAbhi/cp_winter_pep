//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int findSum(int n,vector<vector<int>>& mat,vector<int>& ans,int i){
        if(n==0) return 0;
        if(n==1) return max(mat[0][i],mat[1][i]);
        
        if(i>=n){
            return 0;
        }
        if(ans[i]!= -1){
            return ans[i];
        }
        
        ans[i]=max(max(mat[0][i],mat[1][i])+findSum(n,mat,ans,i+2),findSum(n,mat,ans,i+1));
        
        return ans[i];
    }
    int maxSum(int N, vector<vector<int>> mat)
    {
        // code here
        vector<int> ans(N,-1);
        return findSum(N,mat,ans,0);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> mat(2, vector<int>(N, 0));
        for(int i = 0;i < 2; i++){
            for(int j = 0; j < N; j++)
                cin>>mat[i][j];
        }
        
        Solution ob;
        cout<<ob.maxSum(N, mat)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends