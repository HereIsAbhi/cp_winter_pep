#include <iostream>
using namespace std;

void func(int i,int j,int m,int n,int& cnt){
    cnt++;
    if(i==m && j==n) return;
    func(i+1,j,m,n,cnt);
    func(i,j+1,m,n,cnt);
}
int main(){
    int cnt=0;
    func(0,0,2,2,cnt);
    cout<<cnt<<endl;
    return 0;
}