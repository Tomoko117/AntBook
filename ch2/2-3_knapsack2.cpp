#include <iostream>

using namespace std;

int n,W;
int w[101],v[101];
int dp[101][10001]; //メモ化テーブル

int rec(int num, int weight){
        int res;
        if(dp[num][weight] != -1) return dp[num][weight]; //既に計算済みだった場合
        if(num == n) res = 0; //n個の品物調べ終わった
        else if(w[num] > weight) res = rec(num+1, weight); //num番目の品物の重さが入れられる重さ以上だった場合
        else res=max(rec(num+1, weight),rec(num+1, weight-w[num])+v[num]); //num番目の品物を入れた場合と入れなかった場合で価値が大きい場合を選ぶ
        return dp[num][weight]=res;
}

int main(){
        int i;

        //入力
        cin >> n;
        for(i=0; i<n; i++) cin>>w[i]>>v[i];
        cin >> W;

        //メモ化テーブルの初期化(未使用を示すー1)
        memset(dp,-1,sizeof(dp));

        //出力
        cout<<rec(0,W)<<"\n";

        return 0;
}
