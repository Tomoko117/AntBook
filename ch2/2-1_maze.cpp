#include <iostream>
#include<queue>

using namespace std;

const int INF = 100000000;

typedef pair<int, int> P;

int n,m;
char map[101][101];

int sx,sy,gx,gy;

//深さ優先探索
int bfs(){
        int i,j;
        int res_map[101][101]; //距離記録
        int dx[4] = {1,0,-1,0}, dy[4]={0,1,0,-1};
        queue<P> que;

        //距離記録配列の初期化
        for(i=0; i<n; i++){
                for(j=0; j<m; j++){
                        res_map[i][j]=INF;
                }
        }

        //スタート地点についての処理
        que.push(P(sy,sx));
        res_map[sy][sx]=0;

        //キューが空になるまで調べる
        while(que.size()){
                P point = que.front();
                que.pop();

                //ゴールの場合終了
                if((point.first==gy)&&(point.second==gx)) break;

                //4方向を調べる
                for(i=0; i<4; i++){
                        int ny = point.first+dy[i],nx=point.second+dx[i];

                        if((0<=ny)&&(ny<n)&&(0<=nx)&&(nx<m)&&(map[ny][nx]!='#')&&(res_map[ny][nx]==INF)){
                                que.push(P(ny,nx));
                                res_map[ny][nx] = res_map[point.first][point.second]+1;
                        }
                }
        }

        return res_map[gy][gx];
}

int main(){
        int i,j,ans;

        //入力
        cin>>n>>m;
        for(i=0; i<n; i++){
                for(j=0; j<m; j++){
                        cin>>map[i][j];
                        if(map[i][j]=='S'){
                                sy=i;
                                sx=j;
                        }else if(map[i][j]=='G'){
                                gy=i;
                                gx=j;
                        }
                }
        }

        ans=bfs();

        //出力
        cout<<ans<<"\n";

        return 0;
}
