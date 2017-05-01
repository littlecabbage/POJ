#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int vis[2][9][10];
int area[3][3][10];
int G[9][9];
char t[9][9];
bool dfs(int x , int y)
{
    if(x == 9){
        for(int i = 0 ; i  < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++)
                cout << G[i][j];

            cout << endl;
        }
        return 1;
    }

    int nextx = x,nexty = y + 1;
    if(nexty == 9){nextx ++ ; nexty =0;}
    if(G[x][y] == 0){
        for(int i = 1 ; i <= 9 ; i++){
            if(!vis[0][x][i] && !vis[1][y][i] && !area[x / 3][y / 3][i]){
                G[x][y]  = i;
                vis[0][x][i] = 1;
                vis[1][y][i] = 1;
                area[x / 3][y / 3][i] = 1;
                if(dfs(nextx , nexty)) return 1;
                G[x][y]  = 0;
                vis[0][x][i] = 0;
                vis[1][y][i] = 0;
                area[x / 3][y / 3][i] = 0;
            }
        }
        return 0;
    }
    dfs(nextx , nexty);
}
int main()
{
    int n;
    cin >> n;
    while(n--){
        memset(vis , 0 , sizeof(vis));
        memset(t , 0 , sizeof(t));
        memset(area , 0 , sizeof(area));
        memset(G , 0 ,sizeof(G));

        for(int i = 0 ; i < 9 ; i ++)
        scanf("%s",t[i]);

        for(int i = 0 ; i < 9 ; i++)
            for(int j = 0 ; j < 9 ; j++){
                int tt = t[i][j] - '0';
                G[i][j] = tt;
                if(t != 0){
                 vis[0][i][ tt ] = 1;
                 vis[1][j][ tt ] = 1;
                 area[i / 3 ][ j / 3 ][ tt ] = 1;
             }
        }
        dfs(0,0);
    }
}
