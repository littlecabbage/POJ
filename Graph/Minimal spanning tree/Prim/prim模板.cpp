#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;

//确定数据结构  图 vis  到集合的最短长度
int G[maxn][maxn];
int vis[maxn] , d[maxn] , p[maxn];

//inf设为0x3f3f3f = 1061109567
const int inf = 0x3f3f3f3f;

int m,n,ans,tail;
int f(int s){
    for(int i = 1 ; i <= m ; i++)
        if(p[i] == s) return i;
}

//每次选取最短的点进入集合
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

        for(int i = 1 ; i <= m ;i ++){
            if(G[u][i] < d[i] && !vis[i] && G[u][i] != inf){
                d[i] = G[u][i];
                p[i] = u;
            }
        }
    }
}

int main()
{
    
        memset(vis , 0 , sizeof(vis));
        memset(G , inf , sizeof(G));
        memset(d , inf , sizeof(d));
        memset(p , -1 , sizeof(p));
    
    
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
