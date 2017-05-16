//不能用scan printff啊
//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn  = 27;
int sum = 0;
struct E{
    int x ;
    int y;
    int dist;
    bool operator < (const E b) const{
        return this -> dist < b.dist;
    }
};
//vector<E> edges;
E edges[80];
int es;
int par[maxn];

void init()
{
    for(int i = 0 ; i < maxn ; i++){
        par[i] = i;
    }
    sum = 0;
}

int find(int x){
    int s = x;
    while(s != par[s]){
        s = par[s];
    }

    return s;
}

void unite(int x , int y){
    x = find(x);
    y = find(y);

    if(x == y) return ;

    par[x] = y;
}

bool same(int x , int y){
    return find(x) == find(y);
}

void kruskal(){
    for(int i = 0 ; i < es ; i++){
        if(!same(edges[i].x , edges[i].y)){
            unite(edges[i].x , edges[i].y);
            sum += edges[i].dist;
        }
    }
}
int main()
{
    int n;
    while(1){
    scanf("%d",&n);
    getchar();
    if(n == 0) break;
    init();
    char s , e;
    int temp,dist;
    E t;
    es = 0;
    for(int i = 0 ; i < n - 1; i++){
        //scanf("%c %d",&s , &temp);
        cin >> s >> temp ;
        //getchar();
        for(int j = 0 ; j < temp ; j++){
            scanf("%c %d",&e , &dist);
            cin >> e >> dist;
            //getchar();
            t.x = s - 'A';
            t.y = e - 'A';
            t.dist = dist;
            edges[es++] = t;
        }
    }
    sort(edges , edges + es);
    kruskal();
    //printf("%d\n",sum);
    cout << sum <<endl;
    }
}

