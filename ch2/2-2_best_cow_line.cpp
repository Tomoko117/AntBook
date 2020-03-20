#include <iostream>

using namespace std;

int main(){
        int n,i,r,l;
        char S[2001];

        //入力
        cin >> n;
        for(i=0; i<n; i++) cin>>S[i];

        //SからTへの操作
        r=n-1;
        l=0;
        while(l<=r){
                bool left=false;

                //Sの両端を比較
                for(i=0; l+i<=r; i++){
                        if(S[l+i]<S[r-i]){
                                left=true;
                                break;
                        }else if(S[l+i]>S[r-i]){
                                break;
                        }
                }

                //Sの両端の辞書的に早い方を出力
                if(left) cout<<S[l++];
                else cout<<S[r--];
        }

        //出力
        cout<<"\n";

        return 0;
}
