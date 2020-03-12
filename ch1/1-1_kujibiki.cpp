#include <iostream>

using namespace std;

int main(){
        int n,m,i,a,b,c,d;
        int x[51];

        //入力
        cin>>n>>m;
        for(i=0; i<n; i++)cin>>x[i];

        //組み合わせ全部試す
        for(a=0; a<n; a++){
                for(b=0; b<n; b++){
                        for(c=0; c<n; c++){
                                for(d=0; d<n; d++){
                                        if(x[a]+x[b]+x[c]+x[d]==m){
                                                //出力
                                                cout<<"Yes\n";
                                                return 0;
                                        }
                                }
                        }
                }
        }

        //出力
        cout<<"No\n";
        return 0;
}
