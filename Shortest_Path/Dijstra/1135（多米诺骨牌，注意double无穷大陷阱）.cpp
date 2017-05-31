//发挥想象力思考如何判断是哪种情况…
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 510;
const double inf = 100000000.0;
double d[maxn];
int vis[maxn];
double G[maxn][maxn];
int n,m;
void init(){
   for(int i = 0  ; i <= n ; i++)
        d[i] = inf;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++){
            if(i == j) G[i][j] = 0;
            else G[i][j] = inf;
        }
    memset(vis , 0 , sizeof(vis));
}
void Dij(){
    double mind ;
    int u;
    d[1] = 0;

    while(1){
        mind = inf,u = -1;
        for(int i = 1 ; i <= n ;i++)
            if(mind > d[i] && !vis[i]){
                mind = d[i];
                u = i;
            }

        if(u == -1) break;
        vis[u] = 1;


        for(int i = 1 ; i <= n ; i++){
            if(!vis[i] && G[u][i] + d[u] < d[i])
                d[i] = G[u][i] + d[u];
        }
    }
}
int main()
{
    int k = 0;
    while(cin >> n >> m){
        if(n == 0 && m == 0)break;
        init();
        int x ,y ;
        double dist;
        for(int i = 0 ; i < m ;i++){
            cin >> x >> y >> dist;
            G[x][y] = dist;
            G[y][x] = dist;
        }

        Dij();

        double md1 = -1.0;
        int mdu;
        for(int i = 1 ;i <= n ;i++){
            if(md1 < d[i]){
                md1 = d[i];
                mdu = i;
            }
        }


        double md2 = -1;
        int mdu1,mdu2;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1; j <= n ;j++){
                if(i == j || G[i][j] == inf) continue;
                double t = (d[i] + d[j] + G[i][j]) / 2.0;
                if(t > md2){
                    mdu1 = i;
                    mdu2 = j;
                    md2 = t;
                }
            }
        }

        if(md1 >= md2) {
            printf("System #%d\n" , ++k);
            printf("The last domino falls after %.1lf seconds, at key domino %d.\n",md1 , mdu);
        }
        else {
            printf("System #%d\n" , ++k);
            printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n",md2 , mdu1 , mdu2);
        }
        cout <<endl;
    }
}
