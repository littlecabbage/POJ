/*        http://www.cnblogs.com/youxin/p/3405268.html 先放题解地址...还有一个二维最大子段和，To the max
第一个，最大字段和的公式很好推*/
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
            b = max(b + a[i] , a[i]);//到底b和sum谁才是真正的dp  还是看题意 在这里我需要最大值
            if(b > sum) sum = b;
            ans = max(sum + dp[i - 1] ,ans);
        }
        printf("%d\n",ans);
    }
}
