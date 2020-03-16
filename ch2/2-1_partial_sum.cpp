#include <iostream>

using namespace std;

int n,k;
int a[21];

//深さ優先探索
bool dfs(int num, int sum){
        if(num == n) return sum == k;

        if(dfs(num+1, sum)) return true;
        if(dfs(num+1, sum+a[num])) return true;

        return false;
}

int main(){
        int i;

        //入力
        cin>>n;
        for(i=0; i<n; i++) cin>>a[i];
        cin>>k;

        //出力
        if(dfs(0,0)) cout << "Yes\n";
        else cout << "No\n";

        return 0;
}
