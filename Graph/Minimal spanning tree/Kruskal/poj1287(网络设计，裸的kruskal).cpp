//一开始并查集写错了

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct E{
    int x;
    int y;
    int dist;
    bool operator < (const E b) const{
        return this -> dist < b.dist;
    }
};
int sum = 0;
const int maxn = 55;
int par[maxn];
int rank[maxn];
vector<E> e;
void init(){
    for(int i = 0 ; i < maxn; i++){
        par[i] = i;
        rank[i] = 0;
    }
    sum = 0;
    e.clear();
}

int find(int x){
    int s = x;
    while(s != par[s]){
        s = par[s];
    }

    while(x != s){
        int t  = par[x];
        par[x]  =s;
        x = t ;
    }

    return s;
}

void unite(int x , int y){
    x = find(x);
    y = find(y);
    if(x == y) return ;

    if(rank[x] < rank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
    }
}//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct E{
    int x;
    int y;
    int dist;
    bool operator < (const E b) const{
        return this -> dist < b.dist;
    }
};
int sum = 0;
const int maxn = 55;
int par[maxn];
int rank[maxn];
vector<E> e;
void init(){
    for(int i = 0 ; i < maxn; i++){
        par[i] = i;
        rank[i] = 0;
    }
    sum = 0;
    e.clear();
}

int find(int x){
    int s = x;
    while(s != par[s]){
        s = par[s];
    }

    while(x != s){
        int t  = par[x];
        par[x]  =s;
        x = t ;
    }

    return s;
}

void unite(int x , int y){
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
    return  find(x) == find(y);
}

void kruskal(){
    for(int i = 0 ; i < e.size() ; i++){
        if(!same(e[i].x , e[i].y)){
            unite(e[i].x , e[i].y);
            sum += e[i].dist;
        }
    }
}
int main()
{
    int p,r;
    while(cin >> p){
        if(p == 0) break;
        cin >> r;
        E t;
        init();
        for(int i = 0 ; i < r ; i++){
            cin >> t.x >> t .y >> t.dist ;
            e.push_back(t);
        }
        sort(e.begin() , e.end());
        kruskal();
        cout  << sum <<endl;
    }
}


bool same(int x , int y){
    return  find(x) == find(y);
}

void kruskal(){
    for(int i = 0 ; i < e.size() ; i++){
        if(!same(e[i].x , e[i].y)){
            unite(e[i].x , e[i].y);
            sum += e[i].dist;
        }
    }
}
int main()
{
    int p,r;
    while(cin >> p){
        if(p == 0) break;
        cin >> r;
        E t;
        init();
        for(int i = 0 ; i < r ; i++){
            cin >> t.x >> t .y >> t.dist ;
            e.push_back(t);
        }
        sort(e.begin() , e.end());
        kruskal();
        cout  << sum <<endl;
    }
}
