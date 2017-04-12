#include <cstdio>
int n,k;
const int maxn = 10;
char G[maxn][maxn];
bool flag[maxn];
int c = 0;
void init(){
    for(int i = 0 ; i < maxn ; i++)
        flag[i] = false;
    for(int i = 0 ; i <  maxn ; i++)
        for(int j = 0 ; j < maxn ; j++)
            G[i][j] = 0;

        c = 0;
}
void dfs(int row , int k){
    if(k == 0){
        c++;
        return ;
    }
    if(row == n) return ;

    for(int i = 0 ; i < n ; i++){
        if(G[row][i] == '#' && !flag[i]){
            flag[i] = 1;
            dfs(row + 1 , k - 1);
            flag[i] = 0;
        }
    }
    dfs(row + 1, k);
}
int main()
{
    while(scanf("%d%d",&n,&k) && k != -1 && n != -1){
        getchar();
        init();
        for(int i = 0 ; i < n ; i++)
            scanf("%s",G[i]);

        dfs( 0 , k );
        printf("%d\n",c);
    }
}
