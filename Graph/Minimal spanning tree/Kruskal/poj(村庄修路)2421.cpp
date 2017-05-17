//#include <bits/stdc++.h>  1A
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn  = 110;
int par[maxn];
int rank[maxn];
int sum = 0;
struct E{
    int x;
    int y;
    int dist;
    bool operator < (const E b) const{
        return this -> dist < b.dist;
    }
};
vector<E> e;
void init(){
    for(int i = 0 ; i < maxn ; i++){
        par[i]= i;
        rank[i] = 0;
    }
    sum = 0;
    e.clear();
}

int find(int x){
    int s = x;
    while(s != par[s]) s = par[s];

    while(s != x){
        int t = par[x];
        par[x] = s;
        x = t;
    }

    return s;
}

void unite(int x,int y){
    x = find(x);
    y = find(y);

    if(x == y) return ;

    if(rank[x] < rank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(rank[x] == rank[y]) rank[x] ++;
    }
}

bool same(int x , int y){
    return find(x) == find(y);
}

void kruskal(){
    for(int i = 0; i < e.size() ; i++){
        if(! same(e[i].x , e[i].y)){
            sum += e[i].dist;
            unite(e[i].x , e[i].y);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    E t;
    init();
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
           t.x = i;
           t.y = j;
           cin >> t.dist;
           e.push_back(t) ;
        }
    }

    int temp;
    cin >> temp;
    int x,y;
    for(int i = 0 ; i < temp ; i++){
        cin >> x >> y;
        for(int i = 0 ; i < e.size() ; i++){
            if((e[i].x == x && e[i].y == y) || (e[i].x == y && e[i].y == x)){
                e[i].dist = 0;
            }
        }
    }
    sort(e.begin(), e.end());
    kruskal();
    cout << sum <<endl;
}
