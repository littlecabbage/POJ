//简单食物链的那道题吧 没想到1A了23333
#include <cstdio>
const int maxn = 1e5 +10;
int par[maxn * 2], rank[maxn * 2];
int n;
void init(){
    for(int i = 1 ; i <= 2 * n ; i++){
        rank[i] = 1;
        par[i] = i;
    }
}

int find(int x){
    while(x != par[x]) x = par[x];

    return x;
}

void unite(int x,int y){
    x = find(x);
    y = find(y);

    if(x == y) return ;
    if(rank[x] < rank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
    }
}
bool same(int x, int y){
    return find(x) == find(y);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int m,a,b;
        scanf("%d%d",&n,&m);
        getchar();
        init();
        char temp;
        for(int i = 0 ; i < m ; i++){
            scanf("%c %d%d",&temp,&a,&b);
            getchar();

            if(temp == 'D'){
                unite(a , b + n);
                unite(a + n ,b);
            }else{
                if(same(a,b) && same(a + n , b + n)) puts("In the same gang.");
                else if(same(a,b + n) && same(a +n ,b)) puts("In different gangs.");
                else puts("Not sure yet.");
            }
        }
    }
}
