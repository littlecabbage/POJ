#include <bits/stdc++.h>
using namespace std;
char G[10][10];
int n,m,t;
int sx,sy,ex,ey;
int vis[10][10];
bool dfs(int cur , int x , int y){
    vis[x][y] = 1;
    if(x == ex && y == ey && cur == t) {
        return 1;
    }
    if(cur == t && (x != ex || y != ey)) return 0;
    if(x == ex && y == ey && cur != t) return 0;

    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};

    for(int i =  0 ; i < 4 ; i++){
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if(G[nextx][nexty] != 'X' && nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && vis[nextx][nexty] == 0){
            if(dfs(cur + 1 , nextx , nexty)) return 1;
            vis[nextx][nexty] = 0;
        }
    }
    return 0;
}
int main()
{
    while(cin >> n >> m >> t ){
        memset(G , 0 , sizeof(G));
        memset(vis , 0 , sizeof(vis));
        if(n == 0 && m == 0 && t == 0) break;
        for(int i = 0 ; i < n ; i ++)
            scanf("%s",G[i]);

        for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++){
            if(G[i][j] == 'S'){sx = i ; sy = j;}
            if(G[i][j] == 'D'){ex = i ; ey = j;}
        }

        if(dfs(0,sx,sy)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
