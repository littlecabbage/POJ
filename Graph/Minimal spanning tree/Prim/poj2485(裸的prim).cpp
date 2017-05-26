#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 510;
const int inf = 0x3f3f3f3f;
int d[maxn] , G[maxn][maxn],vis[maxn];
int n;
void prim(){
    int mind , u;
    d[0] = 0;
    while(1){
        u = -1;
        mind = inf;
        for(int i = 0 ; i < n ; i++)
        if(mind > d[i] && !vis[i]){
            u = i;
            mind = d[i];
        }

        if(u == -1) break;
        vis[u] = 1;

        for(int i = 0 ; i < n ; i ++){
            if(G[u][i] < d[i] && !vis[i])
                d[i] = G[u][i];
        }
    }
}
int main()
{
    int N;
    cin >> N;
    while(N--){
        cin >> n;
        memset(G, inf , sizeof(G));
        memset(vis , 0 , sizeof(vis));
        memset(d , inf , sizeof(d));
        for(int i = 0; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                cin >> G[i][j];

        prim();
        int maxnum = -1;
        for(int i = 0 ; i < n ; i++)
            if(maxnum < d[i]) maxnum = d[i];

        cout << maxnum << endl;
    }
}
