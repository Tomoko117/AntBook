#include <iostream>

using namespace std;

int main(){
        int n,i,j,k,ans=0;
        int a[100];

        //入力
        cin>>n;
        for(int i=0; i<n; i++) cin>>a[i];

        //全ての組み合わせ試す
        for(i=0; i<n-2; i++){
                for(j=i+1; j<n-1; j++){
                        for(k=j+1; k<n; k++){
                                int len = a[i]+a[j]+a[k];
                                int maxlen = max(a[i],max(a[j],a[k]));
                                int checklen = len-maxlen;

                                if(maxlen<checklen) ans=max(ans,len);
                        }
                }
        }

        //出力
        cout<<ans<<"\n";

        return 0;
}
