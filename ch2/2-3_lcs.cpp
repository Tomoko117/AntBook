#include <iostream>

using namespace std;

int main(){
        int n, m, i, j;
        char s[1001],t[1001];
        int dp[1001][1001]={0}; //DPテーブル

        //入力
        cin >> n >>m;
        for(i=0; i<n; i++) cin>>s[i];
        for(i=0; i<m; i++) cin>>t[i];

        //漸化式
        for(i=0; i<n; i++){
                for(j=0; j<m; j++){
                        if(s[i] == t[j]) dp[i+1][j+1]=dp[i][j]+1;
                        else dp[i+1][j+1]=max(dp[i+1][j], dp[i][j+1]);
                }
        }

        //出力
        cout<<dp[n][m]<<"\n";

        return 0;
}
