//一开始没读懂题意 题意是：找到这个数的上界素数 和 下界素数 然后输出差值  如果这个数是素数那么这个差值肯定是0了
//练习一下素数筛…

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1299710;
bool is_prim[maxn];
int prim[maxn];
int main()
{
    memset(is_prim, true , sizeof(is_prim));
    is_prim[0] = false , is_prim[1] = false;
    int p = 0;
    for(int i = 2 ;  i <= maxn ; i++)
        if(is_prim[i]){
            for(int j = 2 * i ; j <= maxn ; j += i) is_prim[j] = false;
            prim[p++] = i;
        }

    int n;
    while(scanf("%d",&n) && n != 0){
        if(is_prim[n]) printf("0\n");
        else{
            int s = lower_bound(prim , prim + p , n) - prim ;
            int t = s  - 1;
            printf("%d\n",prim[s] - prim[t]);
        }
    }
}
