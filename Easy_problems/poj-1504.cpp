#include <cstdio>
#include <string>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b,x = 0,y = 0;
        scanf("%d%d",&a,&b);
        while(a != 0){
            x = x * 10 +  a % 10;
            a /= 10;
        }
        while(b != 0){
            y = y * 10 +  b % 10;
            b /= 10;
        }
        x = x + y;
        y = 0;
        while(x != 0 ){
            y = y * 10 + x % 10;
            x /= 10;
        }
        printf("%d\n",y);
    }
}
