// codeforces  New Year and the Permutation Concatenation

#include <iostream>
#include <vector>

using namespace std;
int modMul(long long a,long long b){
    long long mod=1e9+7;
    return ((a%mod)*(b%mod))%mod;
}
int modAdd(long long a,long long b){
    long long mod=1e9+7;
    return ((a%mod)+(b%mod))%mod;

}

int modSub(long long a,long long b){
    long long mod=1e9+7;
    return ((a%mod)-(b%mod)+mod)%mod;
}

int main(){
    int n;
    cin>>n;
    int illegals=0;
    int curr=1;
    for(int i=1;i<n;i++){
        curr=modMul(curr,n-i+1);
        illegals=modAdd(illegals,modSub(curr,1));
    }

    int total= modAdd(modSub(modMul(curr,n),n),1);
    int ans= total-illegals;

    cout<<ans;
}