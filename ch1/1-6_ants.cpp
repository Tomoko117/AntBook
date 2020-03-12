#include <iostream>

using namespace std;

int main(){
        int l,n,i,min_time=0,max_time=0;
        int x[1000001];

        //入力
        cin>>l>>n;
        for(i=0; i<n; i++) cin>>x[i];

        //最小の時間
        for(i=0; i<n; i++) min_time=max(min_time,min(x[i],l-x[i]));

        //最大の時間
        for(i=0; i<n; i++) max_time=max(max_time,max(x[i],l-x[i]));

        //出力
        cout<<"min = "<<min_time<<"\n";
        cout<<"max = "<<max_time<<"\n";

        return 0;
}
