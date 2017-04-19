#include <cstdio>
const int maxn = 50000 + 10;
int animal[maxn * 3];
int rank[maxn *3];
int n;
void init(){
    for(int i = 0 ; i <= n *  3 + 3 ; i++){
        animal[i] = i;
        rank[i] = 0;
    }
}
int find(int x){
    while(x != animal[x]) x = animal[x];
    return x;
}
void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return ;

    if(rank[x] < rank[y]){
        animal[x] = y;
    }else{
        animal[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
    }
}
bool same(int x , int y){
    return find(x) == find(y);
}
//并查集是维护“是否属于同一组”的数据结构，在这个问题中，
int main()
{
    int k;
    scanf("%d%d",&n,&k);
    int ans = 0, x,y,t;
    init();
    for(int i = 0 ; i < k ; i++){
        scanf("%d%d%d",&t,&x,&y);

        if(x > n || y > n || x < 1 || y < 1){ans++;continue;}

        if(t == 1){
            if(same(x, y + n) || same(x , y + 2 * n))ans++;
            else{
                unite(x,y);
                unite(x + n ,y +n);
                unite(x + 2 * n , y + 2 * n);
            }
        }
        if(t == 2){
            if(same(x , y) || same(x , y + 2 * n)) ans++;//
            else{
                unite(x, y + n);
                unite(x + n , y + 2 * n);
                unite(x + 2 * n , y);
            }
        }
    }
    printf("%d\n",ans);
}
