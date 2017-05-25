#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2010;
char a[maxn][7];
int G[maxn][maxn];
int d[maxn];
int vis[maxn];
int n;
const int inf = 0x3f3f3f3f;
int c(char *a , char *b){
    int sum = 0;
    for(int i = 0 ; i < 7 ; i++){
        if(a[i] != b[i])sum ++;
    }

    return sum;
}

void prim(){
    int mind ,u;
    d[0] = 0;
    while(1){
        mind = inf;
        u = -1;
        for(int i = 0 ; i < n ; i++){
            if(mind > d[i] && !vis[i]){
                mind = d[i];
                u = i;
            }
        }

        if(u == -1) break;
        vis[u] = 1;

        for(int i = 0 ; i < n ; i++){
            if(G[u][i] < d[i] && !vis[i]){
                d[i] = G[u][i];
            }
        }
    }
}
int main(){
    while(cin >> n){
        if(n == 0) break;
        memset(d , inf , sizeof(d));
        memset(vis , 0 , sizeof(vis));
        for(int i = 0 ; i < n ; i++)
            scanf("%s",a[i]);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++)
                G[i][j] = c(a[i] , a[j]);
        }

        prim();
        int sum = 0;
        for(int i = 0 ; i < n ;i ++)
            sum += d[i];

        printf("The highest possible quality is 1/%d.\n",sum);
    }
}
