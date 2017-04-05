#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100050;
int a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++)
        scanf("%d",&a[i]);

    sort(a + 1 ,a + n + 1);
    char s[100];
    scanf("%s",a);
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t ; i++){
        int temp;
        scanf("%d",&temp);
        printf("%d\n",a[temp ]);
    }
}
//水题~
