#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 20010;
int par[maxn];
int rank[maxn];
int m,n,sum;
struct E{
    int x;
    int y;
    int dist;
    bool operator < (const E b) const{
        return this->dist > b.dist;
    }
};
vector <E> e;
void init(){
    for(int i = 1; i <= n ; i ++ ){
        par[i] = i;
        rank[i] = 0;
    }
    sum = 0;
}

int find(int x){
    int s = x;
    while(s != par[s]){
        s =par[s];
    }

    while(s != par[x]){
        int t = par[x];
        par[x] = s;
        x = t;
    }

    return s;
}

void unite(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(rank[x] < rank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
    }
}

bool same(int x,int y){
    return find(x) == find(y);
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
    cin >> n >> m;
    init();
    E t;
    //int x , y , dist;
    for(int i = 0 ; i < m ;i++){
        cin >> t.x >> t.y >> t.dist;
        for(int i = 0; i < e.size() ; i++)
            if((t.x == e[i].x && t.y == e[i].y) || (t.x == e[i].y && t.y == e[i].x))
                t.dist = max(t.dist , e[i].dist);

        e.push_back(t);
    }

    sort(e.begin() , e.end());
    kruskal();
    int flag = -1;
    for(int i = 1 ; i <= n ; i++)
        if(par[i] == i) flag ++;
    
    //cout << sum <<endl;
    if(flag == 0) cout << sum << endl;
    else cout << "-1" <<endl;
}
