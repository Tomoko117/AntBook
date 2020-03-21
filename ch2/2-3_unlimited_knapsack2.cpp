#include <iostream>

using namespace std;

int main(){
        int n, W, i, j, k;
        int w[101],v[101];
        int dp[101][101]={0}; //DPテーブル

        //入力
        cin >> n;
        for(i=0; i<n; i++) cin>>w[i]>>v[i];
        cin>>W;

        //漸化式
        for(i=0; i<n; i++){
                for(j=0; j<=W; j++){
                        if(w[i]>j) dp[i+1][j]=dp[i][j];
                        else dp[i+1][j]=max(dp[i][j],dp[i+1][j-w[i]]+v[i]);
                }
        }

        //出力
        cout<<dp[n][W]<<"\n";

        return 0;
}
