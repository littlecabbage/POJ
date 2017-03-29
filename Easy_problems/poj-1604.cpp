#include <cstdio>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n)){
        int temp = 1;
        for(int i = 2 ; i <= n ; i++){
            temp *= i;
            while(temp % 10 == 0){
                temp /=10;
            }
            temp = temp % 100000;
        }
        printf("%5d -> %d\n",n,temp % 10);
    }
}
