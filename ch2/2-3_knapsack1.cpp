#include <iostream>

using namespace std;

int n,W;
int w[101],v[101];

int rec(int num, int weight){
        int res;
        if(num == n) res = 0; //n個の品物調べ終わった
        else if(w[num] > weight) res = rec(num+1, weight); //num番目の品物の重さが入れられる重さ以上だった場合
        else res=max(rec(num+1, weight),rec(num+1, weight-w[num])+v[num]); //num番目の品物を入れた場合と入れなかった場合で価値が大きい場合を選ぶ
        return res;
}

int main(){
        int i;

        //入力
        cin >> n;
        for(i=0; i<n; i++) cin>>w[i]>>v[i];
        cin >> W;

        //出力
        cout<<rec(0,W)<<"\n";

        return 0;
}
