#include <iostream>

using namespace std;

int main(){
        int A,i,ans=0;
        int C[6];
        int money[6]={1, 5, 10, 50, 100, 500};

        //入力
        for(i=0; i<6; i++) cin >>C[i];
        cin>>A;

        //金額の高いコインから使う
        for(i=5; i>=0; i--){
                int num=min(A/money[i],C[i]);
                A-=num*money[i];
                ans+=num;
                if(A<=0) break;
        }

        //出力
        cout<<ans<<"\n";

        return 0;
}
