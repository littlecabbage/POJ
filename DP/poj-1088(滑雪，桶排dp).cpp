#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e5;
vector<pair<int ,int> > E[maxn + 1];
int G[105][105];
int dp[105][105];
int ans = -1;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int maxn_num = -1;
    for(int i = 0 ; i < a ; i++)
        for(int j = 0 ; j < b ; j++){
            scanf("%d",&G[i][j]);
            dp[i][j] = 1;
            E[G[i][j]].push_back(make_pair(i,j));
            if(maxn_num < G[i][j]) maxn_num = G[i][j];
    }
    for(int i = 0 ; i <= maxn_num ; i++){
        for(int j = 0 ; j < E[i].size() ; j++){
            int now_x = E[i][j].first, now_y = E[i][j].second;
            int next[][2] = {{-1,0},{0,1},{1,0},{0,-1}};
            for(int i = 0 ; i < 4 ; i++){
                int next_x = now_x + next[i][0];
                int next_y = now_y + next[i][1];

                if(next_x >= 0 && next_x < a && next_y >= 0 && next_y < b && G[now_x][now_y] > G[next_x][next_y])
                    dp[now_x][now_y] = max(dp[now_x][now_y],dp[next_x][next_y] + 1);

                ans = max(ans , dp[now_x][now_y]);
            }
        }
    }
    printf("%d\n",ans); 
}
