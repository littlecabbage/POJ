#include <bits/stdc++.h>
using namespace std;
char G[110][110];
int m , n;
void dfs(int x , int y){
    G[x][y] = '*';
    int dx[] = {0,0,-1,1,-1,1,-1,1};
    int dy[] = {-1, 1 , 0 , 0, -1 , -1 , 1,1,};
    for(int i = 0 ; i < 8 ; i++){
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if(nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && G[nextx][nexty] == '@')
            dfs(nextx , nexty);
    }
}
int main()
{
    while(cin >> m >> n){
        if(m == 0 && n == 0) break;
        memset(G,0,sizeof(G));
        for(int i = 0 ; i < m ; i++)
            scanf("%s",G[i]);

        int sum = 0;
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                if(G[i][j] == '@') {
                    dfs(i,j);
                    sum++;
            }

        cout << sum << endl;
    }
}
