//本来就是道很简单的并查集  ，看题目的时候三心二意，ACM就是要磨自己的性子不是吗？意识到总比没意识到要好，多多提醒自己，不要那么浮躁
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e3 + 10;
int flag[maxn];
int x[maxn] , y[maxn];
int par[maxn];
int n ,d;
int find(int x){
    while(x != par[x]) x= par[x];

    return x;
}
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return ;
    par[y] = x;
}
void dis(int a){
    flag[a] = 1;
    for(int i = 1 ; i <= n ; i++){
        if(flag[i]){
            int xx = (x[i] - x[a]);
            int yy = (y[i] - y[a]);
            if(xx * xx + yy * yy <= d * d){
                unite(a,i);
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&d);
    for(int i = 1 ; i <= n ; i++)
        scanf("%d%d",&x[i],&y[i]);

    for(int i = 1 ; i <= n ; i++)
        par[i] = i;

    char o;
    int a,b;
    while(cin >> o){
        if(o == 'O'){
            cin >> a;
            dis(a);
        }else{
            cin >> a >> b;
            if(find(a) == find(b)) cout << "SUCCESS" << endl;
            else cout << "FAIL" << endl;
        }
    }

}
