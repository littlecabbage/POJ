#include <cstdio>
#include <cstring>
const int maxn  = 1e6 + 5;
int is_prim[maxn];
int main()
{
    memset(is_prim , 1 ,sizeof(is_prim));
    is_prim[0] = 0, is_prim[1] = 0;
    for(int i = 2 ; i < maxn ; i++){
        if(is_prim[i])for(int j = 2 * i ; j < maxn ; j += i) if(is_prim[j]) is_prim[j] = 0;
    }

    int a,d,n;
    while(scanf("%d%d%d",&a,&d,&n)){
        if(a == 0 && d == 0 && n == 0) break;
        for(int i = a ; ; i += d){
            if(is_prim[i]) n--;
            if(n == 0) {printf("%d\n",i); break;};
        }
    }
}
