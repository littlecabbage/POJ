#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
int G[maxn][maxn];
int vis[maxn] , d[maxn] , p[maxn];
const int inf = 1 << 21;
int m,n,ans,tail;
int f(int s){
    for(int i = 1 ; i <= m ; i++)
        if(p[i] == s) return i;
}
void prim(){
    d[1] = 0;
    while(1){
        int mind = inf;
        int u = -1;
        for(int i = 1 ; i <= m ; i++){
            if(mind > d[i] && !vis[i]){
                mind = d[i];
                u = i;
            }
        }

        if(u == -1) break;
        vis[u] = 1;
        ans += d[u];
        tail = u;

        for(int i = 1 ; i <= m ;i ++)
        for(int j = 1 ; j <= m ; j++){
            if(G[u][i] < d[i] && !vis[i] && G[u][i] != inf){
                d[i] = G[u][i];
                p[i] = u;
            }
        }
    }
}
int main()
{
    while(cin >> m >> n){
        for(int i = 0 ; i < maxn ; i++){
            vis[i] = 0;
            d[i] = inf;
            p[i] = -1;
        }

        for(int i = 0  ; i <= m ; i++)
            for(int j = 0 ; j <= m ; j++)
                G[i][j]= inf;
        int a , b, dist;
        for(int i = 0 ; i < n ; i++){
            cin >> a >> b >> dist ;
            G[a][b] = G[b][a] = dist;
        }

        ans = 0;
        prim();
        cout << ans <<endl;

        int t = 0;
        int s =1;
        while(t != m-1){
            cout << s << " " << f(s) << " " << G[s][f(s)] << endl;
            s = f(s);
            t++;
        }
    }
}
