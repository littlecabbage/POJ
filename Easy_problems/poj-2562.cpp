#include <cstdio>
int a[15],b[15];
int main()
{
    int x,y;
    while(scanf("%d%d",&x,&y)){
            if(x == 0 && y == 0) break;
            int i = 0;
            while(x > 0 || y > 0){
                a[i] = x % 10;
                b[i++] = y % 10;
                x /= 10;
                y /= 10;
            }
            int step = 0;
            for(int j = 0 ; j < i ; j++ ){
                a[j] = a[j] + b[j];
                if(a[j] >= 10) {
                    step++;
                    a[j + 1]++;
                    a[j] = a[j] % 10;
                }
            }

        if(step == 0) printf("No carry operation.\n");
        else printf("%d carry operations.\n",step);
    }
}
-
