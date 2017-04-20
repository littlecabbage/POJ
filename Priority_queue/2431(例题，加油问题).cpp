//距离终点要经过n个加油站，可以装无限多的油，但是要次数最少
//这道题可以用来启发思维

//初始想法？总觉得很受限制，原因对象找错，如果你以油量为对象 又同时考虑下一个加油站的位置 那么就会受到限制 对象越少 思路越清晰 复杂度越低

//这道题单纯的以油量和距离为对象，忽略加还是不加这个因素，是的最后并没有什么影响，假设我每次都加了  但是我最后只要加最多的 这样才最少
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
bool cmp(P a, P b){
    return a.first > b.first;
}
const int maxn = 1e4 + 10;
P p[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d",&p[i].first,&p[i].second);
    }

    sort(p, p + n ,cmp);
    priority_queue<int> Q;
    int l,t;
    scanf("%d%d",&l,&t);
    p[n].first = 0, p[n].second = 0;
    n++;
    int res = 0,pos = l , tank = t;
    for(int i = 0 ; i < n ; i++){
        int d = pos - p[i].first;
        
        //
        while(tank < d){
            if(Q.empty()){puts("-1");return 0;}
            tank += Q.top();
            Q.pop();
            res++;
        }
        //不要只会用if判断
        
        tank -= d;
        pos = p[i].first;
        Q.push(p[i].second);
    }
    printf("%d\n",res);
}
