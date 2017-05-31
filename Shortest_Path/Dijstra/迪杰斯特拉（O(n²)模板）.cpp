//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
//路径
#include <stack>
using namespace std;
const int maxn = 1000;
const int inf = 0x3f3f3f3f;//如果是double就会出错…

int vis[maxn];
int G[maxn][maxn];
int path[maxn];
int d[maxn];
int n,m;
void init(){

    memset(vis , 0 , sizeof(vis));
    memset(G , inf , sizeof(G));
    memset(d , inf , sizeof(d));
    for(int i = 0 ; i < n ; i++)
        path[i] = -1;

}
//Dij
void Dij(int v){
    d[v] = 0;
    int u , mind;
    for(int i  = 0 ; i < n - 1; i++){
        mind = inf;
        u = -1;
        for(int j  = 0 ; j < n ; j++){
            if(!vis[j] && mind > d[j]){
                u = j;
                mind = d[j];
            }
        }

        if(u == -1) break;
        vis[u] = 1;


        for(int j = 0 ; j < n ; j++){
            if(!vis[j] && d[j] > d[u] + G[u][j]){
                d[j] = d[u] + G[u][j];
                path[j] = u;
            }
        }
// print path_change
//        for(int i = 0 ; i < n ; i++)
//            cout << i <<" = " << path[i] << "\t";

        cout <<endl;
    }


}
int main()
{
    cin >> n ;
    init();

    int x,y,dist;
    while(cin >> x >> y >>dist){
        if(x == -1 && y == -1 && dist == -1) break;
        G[x][y] = dist;
    }

    Dij(0);

    //得到d数组

    for(int i = 1 ; i < n ; i++){
        cout << d[i] <<"\t";

        //path
        stack<int> p;
        int t = i;
        while(t != -1){
            p.push(t);
            t = path[t];
        }

        while(p.size() != 1){
            cout << p.top() << "->";
            p.pop();
        }
        cout << p.top() <<endl;
    }
    return 0;
}

