//1A
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 110;
const int inf = 0x3f3f3f3f;
int d[maxn],vis[maxn];
int G[maxn][maxn];
int n;
int sum = 0;
void prim()
{
    int u ,mind ;
    d[0] = 0;
    while(1){
        mind = inf;
        u = -1;
        for(int i = 0 ; i < n ; i++){
            if(d[i] < mind && !vis[i]){
                mind = d[i];
                u = i;
            }
        }

        if(u == -1) break;
        vis[u] = 1;
        sum += mind ;
        for(int i = 0 ; i < n ; i++){
            if(G[u][i] < d[i] && ! vis[i]){
                d[i] = G[u][i];
            }
        }
    }
}

int main()
{
    while(cin >> n){
        sum = 0;
        memset(d , inf ,sizeof(d));
        memset(vis , 0 , sizeof(vis));
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j++)
                //cin >>  G[i][j];
                scanf("%d",&G[i][j]);
        }

        prim();
        printf("%d\n",sum);
    }
}
