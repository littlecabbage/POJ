//简单并查集 需要考虑多种不是树的情况
//1.空树是一棵树
//2.两个节点不能在同一个集合当中  否则就会形成回路
//3.你所要连接的节点应该是第一次被连接，否则就会有两个入度
//满足这三个条件就能A了
#include <cstdio>
const int maxn = 1e6;
int par[maxn],flag[maxn];
void init(){
    for(int i = 0 ; i < maxn; i ++){
        par[i] = i;
        flag[i] = 0;
    }
}
int find(int x){
    while(x != par[x]) x = par[x];
    return x;
}
void unite(int x,int y){
    par[y] = x;
}

int main()
{
    int a,b;
    int  k = 0;
    while(scanf("%d%d",&a,&b) != EOF){
        init();
        bool tree = true;
        if(a == -1 && b == -1) break;
        if(a == 0 && b ==0) {
            printf("Case %d is a tree.\n",++k);
            continue;
        }else{
            flag[a] = 1;
            flag[b] =1;
            if(a == b) tree = false;
            else unite(a ,b);
            while(scanf("%d%d",&a,&b) && a != 0){
                if(par[b] != b) tree = false;
                if(find(b) == find(a)) tree = false;
                unite(a,b);
                flag[a] = 1;
                flag[b] = 1;
            }
        }
        int t = 0;
        for(int i = 0 ; i < maxn ; i++)
         if(flag[i] && par[i] == i) t++;

        if(t > 1 || tree == false) printf("Case %d is not a tree.\n",++k);
        else printf("Case %d is a tree.\n",++k);
    }
}
