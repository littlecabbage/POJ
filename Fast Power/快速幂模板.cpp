#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sp_mod(ll x ,ll n ,ll mod){
    ll ans = 1;
    while(n > 0){
        if(n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}
