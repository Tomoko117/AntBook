#include <iostream>
#include <algorithm>

using namespace std;

int main(){
        int n,r,i,dist,count=0,ans=0;
        int x[1001];

        //入力
        cin >> n >> r;
        for(i=0; i<n; i++) cin>>x[i];

        //距離が違い順にソート
        sort(x,x+n);

        //最も左端にある点の位置
        dist=x[0];

        while(count<n){
                //左端の点から距離r以内の点までcountを進める
                while((count<n)&&(x[count]<=dist+r))count++;
                //左端の点から距離r以内の点の内最も右端にある点（印をつける点）の位置
                dist = x[count-1];
                //印カウント
                ans++;
                //印をつけた点から距離r以内の点までcountを進める
                while((count<n)&&(x[count]<=dist+r))count++;
                //印をつけた点から距離rに含まれなかった点のうち最も左にある点の位置（次の範囲のスタート）
                dist=x[count+1];
        }

        //出力
        cout<<ans<<"\n";

        return 0;
}
