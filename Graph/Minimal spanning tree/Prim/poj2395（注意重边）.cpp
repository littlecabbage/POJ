//注意重边，当有两条边起终点相同时  那么在G中保存权值小的一条边
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2010;
const int inf = 0x7fffffff;
int vis[maxn];
int d[maxn],G[maxn][maxn];
int n,m;
void prim(){
    int u , mind;
    d[1] = 0;
    while(1){
        u = -1;
        mind = inf;
        for(int i = 1 ; i <= n ; i++)
        if(mind > d[i] && !vis[i]){
            mind = d[i];
            u = i;
        }

        if(u == -1) break;
        vis[u] = 1;

        for(int i = 1 ; i <= n ; i++){
            if(G[u][i] < d[i] && !vis[i])
                d[i] = G[u][i];
        }
    }
}
int main()
{
    cin >> n >> m;
    int x , y ,dist;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j ++)
         G[i][j] = inf;
    for(int i = 1 ; i <= n ; i++)
        d[i] = inf;
    for(int i = 0 ; i < m ; i++){
        cin >> x >> y >> dist;
        G[x][y] = G[y][x] = min(dist , G[x][y]);
    }
    prim();
    sort(d + 1,  d + n + 1);
    cout << d[n] << endl;

}
