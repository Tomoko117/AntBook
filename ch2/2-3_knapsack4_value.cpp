#include <iostream>

using namespace std;

int main(){
        int n, W, i, j, k, ans=0;
        int w[101],v[101];
        const int INF = 100000000;
        int dp[101][100*100+1]={0}; //DPテーブル

        //入力
        cin >> n;
        for(i=0; i<n; i++) cin>>w[i]>>v[i];
        cin>>W;

        //DPテーブル初期化
        fill(dp[0], dp[0]+100*100+1, INF);
        dp[0][0]=0;

        //漸化式
        for(i=0; i<n; i++){
                for(j=0; j<=100*100; j++){
                        if(j<v[i]) dp[i+1][j]=dp[i][j];
                        else dp[i+1][j]=min(dp[i][j],dp[i][j-v[i]]+w[i]);
                }
        }

        //n個の品物から価値の総和がjとなるように選んだ時,d[n][j]<=Wを満たす最大のjを探す
        for(j=0; j<=100*100; j++) if(dp[n][j]<=W) ans = j;

        //出力
        cout<<ans<<"\n";

        return 0;
}
