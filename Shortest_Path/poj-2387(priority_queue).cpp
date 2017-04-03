#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1005;
vector <pair<int , int> > E[maxn];
int t , n;
int d[maxn];
void init()
{
    for(int i = 0 ; i < maxn ; i++) E[i].clear();
    for(int i = 0 ; i < maxn ; i++) d[i] = 1e9;
}
int main()
{
    scanf("%d%d",&t,&n);
    init();
    int x,y,z;
    for(int i = 0 ; i < t ; i++){
        scanf("%d%d%d",&x,&y,&z);
        E[x].push_back(make_pair(y,z));
        E[y].push_back(make_pair(x,z));
    }

    priority_queue<pair<int ,int> > Q;
    d[1] = 0,Q.push(make_pair(0 , 1));
    while(!Q.empty()){
        int now = Q.top().second;
        Q.pop();

        for(int i =  0 ; i < E[now].size() ; i++){
            int v = E[now][i].first;
            if(d[v] > E[now][i].second + d[now]){
                d[v] = E[now][i].second + d[now];
                Q.push(make_pair(-d[v], v));
            }
        }
    }
    printf("%d\n",d[n]);
}
