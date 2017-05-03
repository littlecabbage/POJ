#include <cstdio>
const int black  = 1;
const int red = -1;
int G[25][25];
bool vis[25][25];
int sx,sy;
int w ,h;
int step;
void init(){
    step = 0;
    for(int i = 0 ; i < h; i++ )
        for(int j = 0 ; j < w ; j++){
            G[i][j] = 0;
            vis[i][j] = false;
        }
}
void dfs(int x , int y){
    step++;
    vis[x][y] = true;
    int next[][2] = {{-1,0},{0,1},{1,0},{0,-1}};

    for(int i = 0 ; i < 4 ; i++){
        int next_x = x + next[i][0];
        int next_y = y + next[i][1];
        if(next_x >= 0 && next_x < h && next_y >= 0 && next_y < w && !vis[next_x][next_y] && G[next_x][next_y] == black)
            dfs(next_x ,next_y);
    }
}
int main()
{
    while(scanf("%d%d",&w,&h)){
        if(w == 0 && h == 0) break;
        init();
        char s[25];
        for(int i = 0 ; i < h ; i++){
            scanf("%s",s);
            for(int j = 0 ; j < w ; j++)
            if(s[j] == '.') G[i][j]  = black;
            else if(s[j] == '#') G[i][j] = red;
            else {G[i][j] = black ; sx = i ; sy = j;}
        }
        dfs(sx,sy);
        printf("%d\n",step);
    }
}
