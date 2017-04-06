#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];
int dp[100010];
const int INF = -1e9;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i = 0 ; i < n ;i++){
            scanf("%d",&a[i]);
            dp[i] = INF;
        }
        dp[0] = a[0];
        for(int i = 1 ; i < n; i++)
            dp[i] = max(dp[i - 1] + a[i] , a[i]);

        int ans = INF,sum = INF,b = INF;
        for(int i = n - 1 ; i >= 1 ; i--){
            b = max(b + a[i] , a[i]);
            if(b > sum) sum = b;
            ans = max(sum + dp[i - 1] ,ans);
        }
        printf("%d\n",ans);
    }
}
