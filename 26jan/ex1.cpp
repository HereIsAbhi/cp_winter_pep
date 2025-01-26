class solution{
    public:
    int maxSum(int i,int arr[],int n,vector<int>& ans){
        if(i>=n) return 0;
        if(ans[i] != -1) return ans[i];

        ans[i]=max(arr[i],maxSum(i+2,arr,n,ans),maxSum(i+1,arr,n,ans));

        return ans[i];
    }

    int FindMaxSum(int arr[],int n){
        vector<int> ans(n+1,-1);
        return maxSum(0,arr,n,ans);
    }
}