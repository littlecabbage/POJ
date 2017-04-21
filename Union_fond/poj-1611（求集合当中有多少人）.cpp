//给出若干个社团中学生的编号 求与0号同号有接触的同学的人数 这是一个求并查集人数的题目
#include <cstdio>
const int maxn = 3e4 + 10;
int par[maxn] , node[maxn],rank[maxn];
int n,m;
void init()
{
    for(int i = 0 ; i < n ; i++){
        node[i] = 1;
        par[i] = i;
        rank[i] = 1;//强迫自己写并查集模板的时候每次都要写 rank  路径压缩
    }
}
int find(int x){
    while(par[x] != x)
        x = par[x];

    return x;
}
void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return ;
    if(rank[x] < rank[y]){
        par[x] = y;
        node[y] += node[x];//直接保存在根节点当中 到最后只需要find（0）
    }else{
        par[y] = x;
        node[x] += node[y];
        if(rank[x] == rank[y]) rank[y]++;
    }
}
int main(){
        while(scanf("%d%d",&n,&m) && (n || m)){
        //printf("\nn = %d m = %d\n",n,m);
        init();
        int t,head,tail;
        for(int j = 0 ; j < m ; j++){

            scanf("%d",&t);
            scanf("%d",&head);
            //printf("t = %d\n",t);
            for(int i = 0 ; i < t -1 ; i++){
                scanf("%d",&tail);
                unite(head,tail);
            }
        }
        printf("%d\n",node[find(0)]);
    }
}
