#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int inf = 0x3f3f3f3f;
double d[maxn];
int vis[maxn];
double G[maxn][maxn];
double x[maxn],y[maxn];
int s,p;
double sum;
void prim(){
    d[0] = 0;
    int u , mind;
    while(1){
        mind = inf;
        u = -1;
        for(int i = 0 ; i < p ; i++){
            if(mind > d[i] && !vis[i]){
                mind = d[i];
                u = i;
            }
        }

        if(u == -1) break;
        sum += d[u];
        vis[u] = 1;

        for(int i = 0 ; i < p ; i++){
            if(G[u][i] < d[i] && !vis[i])
                d[i] = G[u][i];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    while(n--){
        sum = 0;
        memset(vis , 0 , sizeof(vis));
        //memset(d , inf , sizeof(d))
        cin >> s >> p;
        for(int i = 0 ; i < p ; i++)
            d[i] = 20000;
        for(int i = 0; i < p ; i++)
            cin >> x[i] >> y[i];

        for(int i = 0 ; i < p ; i++)
            for(int j = 0 ; j < p ; j++){
                double xx = (x[i] - x[j]) * (x[i] - x[j]);
                double yy = (y[i] - y[j]) * (y[i] - y[j]);

                G[i][j] = sqrt(xx + yy);
            }

            prim();
            sort(d, d + p);
            for(int i = 1 ; i < s ; i++)
                d[p- i] = 0;
            sort(d, d +p);
            double maxnum = -1;
            for(int i = 0 ; i < p ; i++)
                if(maxnum < d[i]) maxnum = d[i];

            //cout << maxnum << endl;
            printf("%.2f\n",maxnum);
    }
}
