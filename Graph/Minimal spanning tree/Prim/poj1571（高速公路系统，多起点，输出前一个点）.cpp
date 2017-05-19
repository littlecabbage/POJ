

//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 800;
const int inf = 0x3f3f3f3f;
int x[maxn],y[maxn];
int d[maxn];
int G[maxn][maxn];
int pre[maxn];
int n;
void init(){
    memset(d , inf , sizeof(d));
    memset(pre , 0 , sizeof(pre));
}
void prim(){
    int mind = inf;
    int u;
    d[1] = 0;
    while(1){
        mind = inf;
        u = -1;
        for(int i = n ; i > 0 ; i--){
            if(mind > d[i] && pre[i] != -1){
                u = i;
                mind = d[i];
            }
        }

        if(mind == inf) break;
        if(pre[u] != 0 && G[u][pre[u]] != 0){
            cout << u << " " << pre[u] <<endl;
        }
        //cout << "u = " << u << endl;
        pre[u] = -1;

        for(int i = 1 ; i<= n ; i++){
            if(pre[i] != -1 && d[i] > G[u][i]){
                d[i] = G[u][i];
                pre[i] = u;
            }
        }
    }
}
int main()
{

    while(cin >> n){
        init();
        for(int i = 1 ; i <= n ; i++)
            cin >> x[i] >> y[i];

        for(int i = 1 ; i <= n ; i++){
          for(int j = 1 ; j <= n ; j++){
            G[i][j] = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
          }
        }

        int m , x, y;
        cin >> m ;
        for(int i = 0 ; i < m ; i++){
            cin >> x >> y;
            G[x][y] = 0;
            G[y][x] = 0;
            //d[x] = d[y] = 0;
        }
        prim();
        cout <<endl;
    }
}
