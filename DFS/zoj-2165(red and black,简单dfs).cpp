#include <bits/stdc++.h>
using namespace std;
const int maxn  = 25;
char G[maxn][maxn];
int vis[maxn][maxn];
int tot = 0 , w , h;
void dfs(int x , int y){
    vis[x][y] = 1;
    if(G[x][y] == '.') tot ++;

    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    for(int i = 0 ; i < 4 ; i ++){
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if(nextx >= 0 && nextx < h && nexty >= 0 && nexty < w && vis[nextx][nexty] == 0 && G[nextx][nexty] == '.'){
            dfs(nextx , nexty);
        }
    }
}
int main()
{
    while(cin >> w >> h){
        if(w == 0 && h == 0) break;
        memset(G, 0 , sizeof(G));
        memset(vis , 0 , sizeof(vis));
        for(int i = 0 ; i < h ; i++)
            scanf("%s",G[i]);

        int sx , sy;
        for(int i = 0 ; i < h ; i++)
            for(int j = 0 ; j < w ; j++)
                if(G[i][j] == '@'){
                    sx = i ;
                    sy = j;
                    break;
        }
        tot = 0;
        dfs(sx , sy);
        cout << tot  + 1<< endl;
    }
}
