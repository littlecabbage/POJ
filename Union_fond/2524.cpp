#include <cstdio>
const int maxn = 5e4 + 10;
int par[maxn];
int n,m;
void init()
{
    for(int i = 1 ; i <= n ; i++)
        par[i] = i;
}
int find(int x){
    while(x != par[x]) x = par[x];

    return x;
}
int unite(int x ,int y){
    x = find(x);
    y = find(y);
    if(x == y) return 0;
    else {
        par[x] = y;
        return 1;
    }
}
int main()
{
    int Case = 0;
    while(scanf("%d%d",&n,&m) && n && m){
        //printf("n == %d m == %d\n",n,m);
        init();
        int x,y;
        int ans = n;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&x,&y);
            ans -= unite(x, y);
        }
        printf("Case %d: %d\n",++Case,ans);
    }
}
