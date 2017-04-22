// 技巧  复杂度降低到O（n）

#include <cstdio>
typedef long long ll;
int main()
{
    ll n,k;
    while(scanf("%lld%lld",&n,&k) && n + k){

        ll ans = 1;
        if(k > n- k) k = n - k;
        for(ll i = 1 ; i <= k ;i++)
            ans = ans * (n - i + 1) / i;

        printf("%lld\n",ans);
    }
}

