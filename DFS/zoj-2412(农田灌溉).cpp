//先吐槽一下没有写 if(m + n < 0) break; 一直wa  这个不是应该超时或者什么东西的吗…

//这次的进步是  没有一直傻了吧唧的瞎几把改，当考虑到问题错在没有考虑下一个格子是否有连通管道的时候  及时修改了dfs的条件
//即判断一下下一个管道是否可以匹配当前的方向 （k + 2 )%4

#include <bits/stdc++.h>
using namespace std;
int m,n;
const int maxn = 55;
int G[maxn][maxn];
int vis[maxn][maxn];
char t[maxn][maxn];
int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};
int dir[11][4] = {{1,0,0,1},{1,1,0,0},{0,0,1,1},{0,1,1,0},
                  {1,0,1,0},{0,1,0,1},{1,1,0,1},{1,0,1,1},
                  {0,1,1,1},{1,1,1,0},{1,1,1,1}
};
 void dfs(int x , int y){
     //cout << "start" << endl;
    vis[x][y] = 1;

    int t = G[x][y];
    for(int i = 0 ; i < 4 ; i++){
        if(dir[t][i]){
            int nextx = x + dx[i];
            int nexty = y + dy[i];

            //printf("i = %d x = %d y = %d nextx = %d nexty = %d\n",i,x,y,nextx , nexty);
            if(nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && !vis[nextx][nexty]){
                int nextt = G[nextx][nexty];
                if(dir[nextt][(i+2)%4]) {
                   // cout << "digui" << endl;
                    dfs(nextx , nexty);
                }
            }
        }
    }
}
int main()
{
    while(cin >> m >> n){
        if(m + n < 0) break;
        memset(G, 0 , sizeof(G));
        memset(vis , 0 , sizeof(vis));
        memset(t, 0 , sizeof(t));
        for(int i = 0 ; i < m ; i++)
            scanf("%s",t[i]);

        for(int i = 0 ;  i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                G[i][j] = t[i][j] - 'A';

        int tot = 0;
        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j++)
            if(!vis[i][j]){
                tot++;
                dfs(i , j);
            }
        }
        cout << tot << endl;
    }
}
//grid[ s[i+dir[k][0] ][ j+dir[k][1]] ] [ (k+2)%4 ]
