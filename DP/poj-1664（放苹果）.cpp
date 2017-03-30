/*                                 放苹果
                  Time Limit: 1000MS		Memory Limit: 10000K
                  Total Submissions: 33574		Accepted: 20783
Description

把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
Input

第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
Output

对输入的每组数据M和N，用一行输出相应的K。
Sample Input

1
7 3
Sample Output

8

index: 设计递推状态方程
*/
// code
#include <cstdio>
#include <cstring>
using namespace std;
int x,y;
int main()
{
    int a[11][11];
    memset(a, 1 , sizeof(a));
    for(int i = 1 ; i < 11 ; i++)
    for(int j = 1 ; j < 11; j++){
        if(i == 1 || j == 1) a[i][j] = 1;
        else{
            if(j > i) a[i][j] = a[i][i];
            else if(i == j) a[i][j] = a[i][j - 1] + 1;
            else{
                a[i][j] = a[i][j - 1] + a[i - j][j];
            }
        }
    }

    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&x,&y);
        printf("%d\n",a[x][y]);
    }
}
