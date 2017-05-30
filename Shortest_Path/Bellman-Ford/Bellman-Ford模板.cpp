 //#include <bits/stdc++.h>
 #include <iostream>
 #include <cstring>
 //path 头文件
 #include <stack>
using namespace std;
const int maxn = 1000;
const int inf = 0x3f3f3f3f;
int d[maxn];
int G[maxn][maxn];
int path[maxn];
int n , m;
void Bellman(int v0){
    for(int i = 0 ;i < n ; i++){
            d[i] = G[v0][i];//这里应该有一步将d[v0] 设为 0
            if(i != v0 && d[i] < inf) path[i] = v0;//i != v0
            else path[i] = -1;
    }

    for(int i = 2 ; i < n ;  i++){
        for(int j = 0 ; j < n ; j++){
            if(j == v0) continue;
            for(int k = 0 ; k < n ; k++){
                if(G[k][j] < inf && d[j] > d[k] + G[k][j]){
                     d[j] = d[k] + G[k][j];
                     path[j] = k;
                }
            }
        }
    }
}

int main()
{
    memset(G , inf , sizeof(G));
    memset(d , inf , sizeof(d));


//非必须步骤

//    for(int i = 0 ; i < n ; i++)
//        for(int j = 0 ; j < n ; j++)
//            if(i == j) G[i][j] = 0;

    cin >> n ;
    int x , y ,dist;
    while(cin >> x >> y >> dist){
        if(x == -1 && y == -1 && dist == -1) break;
        G[x][y] = dist;
    }
    Bellman(0);

    for(int i = 1 ; i < n ; i++){
        cout << d[i] << "\t";
        stack<int> s;
        int t = i;
        while(t != -1){
            s.push(t);
            t = path[t];
        }
        while(s.size() > 1){
            cout << s.top() << " -> " ;
            s.pop();
        }
        cout << s.top() << endl;
    }

    //cout << d[0] <<endl;
}
