/* 第一次使用了优先队列 以到每个点的dist为键值  但是发现这样是不对的  还是应该一个m[][]数组维护到每个节点的时间
  
*/
#include <bits/stdc++.h>
using namespace std;
struct P{
    int x;
    int y;
};
const int maxn = 210;
char G[maxn][maxn];
int mm[maxn][maxn];
int n,m;
int sx , sy , ex , ey;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void bfs(int x , int y){
    queue<P> Q;
    P t;
    t.x = x;
    t.y = y;
    mm[x][y] = 0;
    Q.push(t);
    while(!Q.empty()){
        P top = Q.front();
        Q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nextx = top.x + dx[i];
            int nexty = top.y + dy[i];

            if(nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && G[nextx][nexty] != '#'){
                t.x = nextx;
                t.y = nexty;
                int tm;
                if(G[nextx][nexty] == 'x')  tm = mm[top.x][top.y] + 2;
                else tm = mm[top.x][top.y] + 1;
                if(mm[nextx][nexty] == -1 || tm < mm[nextx][nexty]) {
                    mm[nextx][nexty] = tm;
                    Q.push(t);
                }
            }
        }
    }
}
int main()
{
    while(cin >> n >> m){
        memset(G , 0 , sizeof(G));
        memset(mm , -1 , sizeof(mm));
        for(int i = 0 ; i < n ; i++)
            scanf("%s",G[i]);

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++){
                if(G[i][j] == 'r') {
                    ex = i;
                    ey = j;
                }
                if(G[i][j] == 'a'){
                    sx = i;
                    sy = j;
                }
            }

            bfs(sx , sy);
            if(mm[ex][ey] > 0) cout << mm[ex][ey] <<endl;
            else cout << "Poor ANGEL has to stay in the prison all his life." << endl;
    }
}

