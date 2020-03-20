#include <iostream>
#include <algorithm>

using namespace std;

int main(){
        int n,i,time=0,ans=0;
        int s[100001],t[100001];
        pair<int, int> sort_time[100001];

        //入力
        cin >> n;
        for(i=0; i<n; i++) cin>>s[i];
        for(i=0; i<n; i++) cin>>t[i];

        //終了時間が早い順にソート
        for(i=0; i<n; i++){
                sort_time[i].first=t[i];
                sort_time[i].second=s[i];
        }
        sort(sort_time,sort_time+n);

        //終了時間が早い順に選んでいく
        for(i=0; i<n; i++){
                if(time<sort_time[i].second){
                        ans++;
                        time=sort_time[i].first;
                }
        }

        //出力
        cout<<ans<<"\n";

        return 0;
}
