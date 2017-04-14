#include <cstdio>
#include <cstring>
const int maxn = 32768 + 10;
int is_prim[maxn];
int prim[maxn];
int main()
{
    memset(is_prim , 1 , sizeof(is_prim));
    is_prim[0] = 0 , is_prim[1] = 0;
    int p = 0;
    for(int i = 2 ; i < maxn ; i++){
        if(is_prim[i]) {
            for(int j = 2 * i ; j < maxn ; j += i) if(is_prim[j]) is_prim[j] = 0;
            prim[p++] = i;
        }
    }

    
    int n;
    while(scanf("%d",&n) && n != 0){
        int sum = 0;
        for(int i = 0 ; prim[i] <= n/2 ; i++)
            if(is_prim[n - prim[i]]) sum++;

        printf("%d\n",sum);
 }
}
