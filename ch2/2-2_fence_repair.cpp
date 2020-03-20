#include <iostream>

using namespace std;

int main(){
        int n,i;
        long long ans;
        int l[20001];

        //入力
        cin >> n;
        for(i=0; i<n; i++) cin>>l[i];

        while(n>1){
                int mii1=0,mii2=1;

                //現状最も短い板とその次に短い板を探す
                if(l[mii1]>l[mii2]) swap(mii1,mii2);
                for(i=2; i<n; i++){
                        if(l[i]<l[mii1]){
                                mii2=mii1;
                                mii1=i;
                        }else if(l[i]<l[mii2]){
                                mii2=i;
                        }
                }

                //短い板とその次に短い板を1枚にする
                int add=l[mii1]+l[mii2];
                ans+=add; //コスト追加
                if(mii1 == n-1) swap(mii1,mii2); //n-1番目は1枚減らす操作で消えるため，2枚を1枚にした長さをmii2番目に記録するようにする
                l[mii1]=add; //1枚にしたときの長さを記録
                l[mii2]=l[n-1]; //2枚を1枚にしたため消す1枚の長さの代わりに，その時の配列の最後尾の長さを記録
                n--; //1枚減らす
        }

        //出力
        cout<<ans<<"\n";

        return 0;
}
