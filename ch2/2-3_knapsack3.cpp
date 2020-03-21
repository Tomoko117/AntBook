#include <iostream>

using namespace std;

int main(){
        int i, j;
        int n,W;
        int w[101],v[101];
        int dp[101][10001]={0}; //DPテーブル

        //入力
        cin >> n;
        for(i=0; i<n; i++) cin>>w[i]>>v[i];
        cin >> W;

        //漸化式
        for(i=n-1; i>=0; i--){
                for(j=0; j<=W; j++){
                        if(w[i] > j) dp[i][j]=dp[i+1][j];
                        else dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
                }
        }

        //出力
        cout<<dp[0][W]<<"\n";

        return 0;
}
