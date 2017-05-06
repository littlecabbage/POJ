#include <bits/stdc++.h>
using namespace std;
const int maxn  = 105;
struct edge{
    int s;
    int e;
    double dist;
    bool operator < (const edge b) const {
        return this->dist < b.dist;
    }
};
vector<edge> E;
int n;
int par[maxn];
int rank[maxn];
void init(){
    for(int i = 0 ; i < maxn ; i++){
        par[i] = i;
        rank[i] = 0;
    }
    E.clear();
}

int find(int x){
    int s = x;
    while(s != par[s]){
         s = par[s];
    }

    while (x != s){
        int tmp = par[x];
        par[x] = s;
        x = tmp;
    }
    return s;
}

void unite(int x , int y){
    x = find(x);
    y = find(y);

    if(x == y ) return ;

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
double ans = 0;

void Kruskal(){
    for(int i = 0 ; i < E.size() ; i++){
        if(same(E[i].s , E[i].e)) continue;
        ans += E[i].dist;
        unite(E[i].s , E[i].e);
    }
}
pair<double , double> p[maxn];
int main()
{
    int m;
    int k = 0;
    while(cin >> n ,n){
        init();
        ans = 0;
        for(int i = 0 ; i < n  ; i++)
            cin >> p[i].first >> p[i].second;

    edge t;
    for(int i = 0 ; i < n ; i ++)
        for(int j = i + 1 ; j < n ; j++){
           t.s = i;
           t.e = j;
           double x = p[j].first - p[i].first;
           double y = p[j].second - p[i].second;
           t.dist = sqrt(x*x + y*y);
           E.push_back(t);
        }

        sort(E.begin() , E.end());
        Kruskal();
        if(k != 0) cout << endl;
        printf("Case #%d:\n",++k);
        printf("The minimal distance is: %.2lf\n",ans);
    }
}

