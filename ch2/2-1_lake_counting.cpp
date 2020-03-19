#include <iostream>

using namespace std;

int n,m;
char map[101][101];

//深さ優先探索
void dfs(int y,int x ){
        int dx,dy;
        map[y][x] = '.';

        //8近傍を調べる
        for(dy=-1; dy<=1; dy++){
                for(dx=-1; dx<=1; dx++){
                        int nx=x+dx,ny=y+dy;

                        //調べた先がWだった場合
                        if((0<=ny)&&(ny<n)&&(0<=nx)&&(nx<m)&&(map[ny][nx]=='W')) dfs(ny,nx);
                }
        }
        return ;
}

int main(){
        int i,j,result=0;

        //入力
        cin>>n>>m;
        for(i=0; i<n; i++){
                for(j=0; j<m; j++){
                        cin>>map[i][j];
                }
        }

        //map全てを調べる
        for(i=0; i<n; i++){
                for(j=0; j<m; j++){
                        if(map[i][j] == 'W'){
                                dfs(i,j);
                                result++;
                        }
                }
        }

        //出力
        cout<<result<<"\n";

        return 0;
}
