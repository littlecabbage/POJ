#include <cstdio>
const int maxn = 1e3;
//父亲节点，如果等于本身，说明为根节点
int par[maxn];

//rank数组  保存有多少个儿子
int rank[maxn];

//init
void init(){
    for(int i = 0 ; i < maxn ; i++)
        par[i] =  i;
        rank[i] = 0;
}

//递归或者循环
int find(int i){
    if(par[i] == i) return i;
    return find(par[i]);
}


int find(int i){
    while(par[i] != i) i = par[i];
    return i;
}

//包含压缩的并查集结合
void unite(int x ,int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    
    //rank存在三种情况  
    if(rank[x] < rank[y]) {
        par[x] = y;
    }else{
        par[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
    }
}
