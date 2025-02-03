// codeforces 1840D

#include<bits/stdc++.h>
using namespace std;

bool isFeasible(vector<int>& a,int T){
    int n=a.size();

    int segments=1;
    int start=a[0];

    for(int i=1;i<n;i++){
        if(a[i]-start>2*T){
            segments++;
            start=a[i];
        }
    }

    return segments<=3;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());

        int l=0, h=a[n-1]-a[0], result=-1;

        while(l<=h){
            int mid=(l+h)/2;
            if(isFeasible(a,mid)){
                result=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        cout<<result<<endl;
    }
}