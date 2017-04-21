//读题看不懂 都是高级词汇 找份题解理解一下题意  尴尬癌都犯了
//做法同1703  不详细说了
#include <cstdio>
const int maxn = 2e3 + 10;
int par[maxn * 2],rank[maxn * 2];
int n;
void init()
{
    for(int i = 0 ; i <= 2 * n ; i++){
        rank[i] = 1;
        par[i] = i;
    }
}

int find(int x){
    while(x != par[x]) x = par[x];

    return x;
}

void unite(int x ,int y){
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
bool same(int x , int y){
    return find(x) == find(y);
}

int main()
{
    int t;
    scanf("%d",&t);
    int Case = 1;
    while(t--){
        int m;
        scanf("%d%d",&n,&m);
        init();
        int a,b;
        int flag = 0;
        for(int i = 0 ; i < m ;i ++){
            scanf("%d%d",&a,&b);
            if(same(a,b) && same(a + n , b + n)){
                flag = 1;
            }else{
                unite(a,b + n);
                unite(a + n ,b);
            }
        }

        if(flag == 0)printf("Scenario #%d:\nNo suspicious bugs found!\n",Case++);
        else printf("Scenario #%d:\nSuspicious bugs found!\n",Case++);
        puts("");
    }
}
