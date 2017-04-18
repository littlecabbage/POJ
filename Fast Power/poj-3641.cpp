#include <cstdio>
#include <iostream>
using namespace std;
typedef long long int ll;
ll pow_mod(ll a, ll n, ll mod){
    ll res = 1;
    while(n > 0){
        if( n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
bool isprim(ll a){
    for(ll i = 2;  i * i <= a ; i++)
        if(a % i == 0) return false;

    return true;
}
int main()
{
    int p,a;
    while(cin >> p >> a){
            if(a == 0 && p == 0) break;
        if(!isprim(p) && (a == pow_mod(a,p,p)))
            printf("yes\n");

        else printf("no\n");

    }

}
