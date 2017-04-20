//
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
        //
        
        tank -= d;
        pos = p[i].first;
        Q.push(p[i].second);
    }
    printf("%d\n",res);
}
