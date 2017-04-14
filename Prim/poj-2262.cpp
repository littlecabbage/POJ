//练习一下素数筛了
#include <cstdio>
#include <cstring>
const int maxn = 1e6 + 5;
int is_prim[maxn];
int prim[maxn];
int main()
{
    memset(is_prim , 1 , sizeof(is_prim));
    is_prim[0] = 0, is_prim[1] = 0;
    int p = 0;
    for(int i = 2 ; i < maxn ; i++){
        if(is_prim[i]){
            for(int j = 2 * i ; j < maxn ; j += i)
                if(is_prim[j]) is_prim[j] = 0;

            prim[p++] = i;
        }
    }

    int n;
    while(scanf("%d",&n) && n != 0){
        int flag = 0;
        for(int i = 0 ; prim[i] <= n/2 ; i++){
            if(is_prim[n - prim[i]]){flag = 1;printf("%d = %d + %d\n",n,prim[i],n - prim[i]);break;}
        }
        if(!flag) printf("Goldbach's conjecture is wrong.\n");
    }
}
