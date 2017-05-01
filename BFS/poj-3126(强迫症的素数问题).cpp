#include <stdio.h>
#include <queue>
#include <iostream>
#include <string.h>
using namespace std;
int isp[10000];
int vis[10000];
struct p{
    int x;
    int step;
};
void bfs(int s , int e){
    queue<p> q;
    p t;
    t.x = s;
    t.step = 0;
    q.push(t);

    while(!q.empty()){
        int top = q.front().x;
        int ts = q.front().step;
        q.pop();
        //cout << top <<endl;
        vis[top] = 1;
        if(top == e){
            cout << ts << endl;;
            return ;
        }
        int next ;
        for(int i = 0 ; i < 4 ; i++){
            for(int j = 0 ; j <= 9 ;j++)
                if(i == 0){next = top / 10 * 10 + j; if(isp[next] && !vis[next]) {t.x = next ;t.step = ts + 1; q.push(t); }}
                else if(i == 1){next = top - (top / 10 % 10 * 10) + j * 10; if(isp[next] && !vis[next]) {t.x = next ;t.step = ts + 1; q.push(t); }}
                else if(i == 2){next = top - (top / 100 % 10 * 100) + j * 100; if(isp[next] && !vis[next]) {t.x = next ;t.step = ts + 1; q.push(t); } }
                else if(i == 3){if(j == 0) continue ; next = top - (top / 1000 % 10 * 1000) + j * 1000; if(isp[next] && !vis[next]) {t.x = next ;t.step = ts + 1; q.push(t); }}
        }
    }
}
int main()
{
    memset(isp, 1 , sizeof(isp));
    isp[0] = 0, isp[1] = 0;
    for(int i = 2 ; i < 10000 ; i++){
        if(isp[i]){
            for(int j  = 2 * i ; j < 10000 ; j += i)
                if(isp[j])  isp[j] = 0;
        }
    }

    int n;
    cin >> n;
    int s,e;
    while(n--){
        memset(vis , 0 , sizeof(vis));
        cin >> s >> e;
        bfs(s ,e);
    }
}
