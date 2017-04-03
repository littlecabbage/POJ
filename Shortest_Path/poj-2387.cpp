
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int max_num = 1010;
const int INF = 1e9;
int T ,N;
int G[max_num + 1][max_num + 1] ;
int d[max_num + 1];
bool used[max_num + 1];
void Dij()
{
    fill(d , d + N + 1 , INF);
    fill(used , used + N + 1 , false);
    d[1] = 0;
    while(1){
        int v = -1;
        for(int u = 1 ; u <= N ; u++){
            if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }

        if(v == -1) break;
        used[v] = true;

        for(int u = 1 ; u <= N ; u++)
            if(!used[u] && d[u] > d[v] + G[v][u]) d[u] = d[v] + G[v][u] ;//这里要检查一下
            //d[u] = min(d[u] , d[v] + G[v][u]);
    }
}
int main()
{
    scanf("%d%d",&T,&N);
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            G[i][j] = INF;

    for(int i = 0 ; i < T ; i++){
        int x , y , cost;
        scanf("%d%d%d",&x,&y,&cost);
        if(G[x][y] != INF) G[x][y] = min(G[x][y], cost);
        else G[x][y] = cost;
        G[y][x] = cost;
    }
    Dij();
    printf("%d ",d[N]);
}
