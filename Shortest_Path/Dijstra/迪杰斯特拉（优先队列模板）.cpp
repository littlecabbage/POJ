//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
//路径
#include <stack>
#include <queue>
using namespace std;

const int maxn = 1000;
const int inf = 0x3f3f3f;
struct E{
    int v;
    int dist;
    bool operator < (const E b) const{
     return this -> dist > b.dist;
    }
};
vector<E> e[maxn];

int d[maxn];
int path[maxn];
int n;

void init(){
    memset(d , inf , sizeof(d));
    for(int i = 0 ; i < n ; i++)
        e[i].clear();
    for(int i = 0 ; i < n ; i++)
        path[i] = -1;
}

void Dij(){
    priority_queue<E> Q;
    d[0] = 0;
    E t; t.v = 0; t.dist = d[0];
    Q.push(t);
    
    while(!Q.empty()){//队列非空
        int u = Q.top().v;
        Q.pop();
        for(int i = 0 ; i < e[u].size() ; i++){
            int v = e[u][i].v;
            if(d[v] > d[u] + e[u][i].dist){
                d[v] = d[u]+ e[u][i].dist;
                path[v] = u;
                t.v = v;
                t.dist = d[v];
                Q.push(t);
            }
        }
    }
}

int main()
{
        cin >> n ;
        int x , y , dist;
        init();//切记初始化 ，每次没有初始化 都直接用的是d[i] = 0
        while(cin >> x >> y >> dist){
            if(x == -1 && y == -1 && dist == -1) break;
            E t;
            t.v = y,t.dist = dist;
            e[x].push_back(t);
        }
        Dij();
        for(int i = 1 ; i< n ; i++){
            cout << d[i] <<"\t";


            int t = i;
            stack<int> p;
            while(t != -1){
                p.push(t);
                t= path[t];
            }

            while(p.size() > 1){
                cout << p.top() << "\t";
                p.pop();
            }
            cout << p.top() << endl;
        }
}
