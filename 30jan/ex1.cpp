// codeforces 766c

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

long M=1e9+7;
struct Answer{
    int ways,max_len,min_splits;
};

Answer solve(int idx,string& s,vector<int>& limits, vector<Answer>& answers){
    if(idx==s.size()){
        Answer a;
        a.ways=1;
        a.max_len=0;
        a.min_splits=0;
        return a;
    }
    if(answers[idx].ways!=-1){
        return answers[idx];
    }

    int ways=0, max_len=-1,minsplits= INT_MAX;

    vector<bool> isPresent(26,false);

    for(int j=idx;j<s.size();j++){
        isPresent[s[j]-'a']=true;
        bool isAllowed=true;

        for(int k=0;k<26;k++){
            if(isPresent[k]&&limits[k]<(j-idx+1)){
                isAllowed=false;
                break;
            }
            if(!isAllowed){
                break;
            }
            Answer curr=solve(j+1,s,limits,answers);
            ways=(ways+curr.ways)%M;
            max_len=max(max_len,max((j-idx+1),curr.max_len));
            minsplits=min(minsplits,1+curr.min_splits);
        }
        Answer a;
        a.ways=ways;
        a.max_len=max_len;
        a.min_splits=minsplits;
        return answers[idx]=a;
    }


}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> limits(26);
    for(int i=0;i<26;i++){
        cin>>limits[i];
    }
    Answer def={-1,-1,-1};
    vector<Answer> answers(s.size(),def);
    Answer ans=solve(0,s,limits,answers);
    cout<<ans.ways<<endl;
    cout<<ans.max_len<<endl;
    cout<<ans.min_splits<<endl;
    return 0;
}