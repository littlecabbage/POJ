#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 25;
const int inf = 0x3f3f3f3f;
int n;
int G[maxn][maxn];
int d[maxn];
int vis[maxn];
int path[maxn];
struct ans{
    int org ,dest ,time;
    stack<int> p;
    bool operator < (const ans b) const{
        return this -> time < b.time;
    }
};
vector <ans> a;
void init(){
    memset(d , inf , sizeof(d));
    memset(G, inf ,sizeof(G));
    memset(vis , 0 , sizeof(vis));
    for(int i = 1 ; i <= n ; i++)
        path[i] = -1;
}

void dij(int v){
    d[v] = 0;
    int mind ,u;
    while(1){
        mind = inf , u = -1;
        for(int i  = 1 ;i <= n ; i++){
            if(mind > d[i] && !vis[i]){
                u = i;
                mind = d[i];
            }
        }
        if(u == -1) break;
        vis[u] = 1;

        for(int i = 1 ; i <= n ; i++){
            if(!vis[i] && d[i] > d[u] + G[u][i]){
                d[i] = d[u] + G[u][i];
                path[i] = u;
            }
        }
    }
}

int main()
{
    while(cin >> n){
        init();
        int x;
        for(int i = 1 ; i <= n ; i++)
        for(int j = 1; j <= n ; j++){
            cin  >> x;
            if(x == -1) continue;
            G[i][j] = x;
        }

        int dest;
        cin >> dest;

        cout << "Org\tDest\tTime\tPath" << endl;
        int org;
        while(cin >> org){
            memset(d , inf , sizeof(d));
            memset(vis , 0 , sizeof(vis));
            for(int i = 1 ; i <= n ; i++)
                path[i] = -1;
            dij(org);
            ans tt;
            tt.dest = dest , tt.org = org , tt.time = d[dest];
            int t = dest;
            while(t != -1){
                tt.p.push(t);
                t = path[t];
            }
            a.push_back(tt);
        }
        sort(a.begin() , a.end());
        for(int i = 0 ; i < a.size() ; i++){
            cout << a[i].org << "\t" << a[i].dest << "\t"  << a[i].time << "\t";
            while(a[i].p.size() > 1){
                cout << a[i].p.top() << "\t" ;
                a[i].p.pop();
            }
            cout << a[i].p.top() << endl;
        }
    }
}
