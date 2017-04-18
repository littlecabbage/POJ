#include <cstdio>
#include <iostream>
using namespace std;
typedef long long int ll;
ll pow_mod(ll x , ll n , ll mod)
{
    ll res = 1;
    while( n > 0){
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
int main()
{
    int z , n;
    ll m;
    cin >> z;
    while(z--){
        cin >> m >> n ;
        ll a,b,sum = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> a >> b;
            sum += pow_mod(a,b,m);
        }
        printf("%lld\n",sum % m);
    }
}
