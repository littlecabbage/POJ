/*                                                         Cow Bowling
                                          Time Limit: 1000MS		Memory Limit: 65536K
                                          Total Submissions: 18659		Accepted: 12426
                                          Description

The cows don't use actual bowling balls when they go bowling. They each take a number (in the range 0..99), though, and line up in a standard bowling-pin-like triangle like this: 

          7



        3   8



      8   1   0



    2   7   4   4



  4   5   2   6   5
Then the other cows traverse the triangle starting from its tip and moving "down" to one of the two diagonally adjacent cows until the "bottom" row is reached. The cow's score is the sum of the numbers of the cows visited along the way. The cow with the highest score wins that frame. 

Given a triangle with N (1 <= N <= 350) rows, determine the highest possible sum achievable.
Input

Line 1: A single integer, N 

Lines 2..N+1: Line i+1 contains i space-separated integers that represent row i of the triangle.
Output

Line 1: The largest sum achievable using the traversal rules
Sample Input

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
Sample Output

30
Hint

Explanation of the sample: 

          7

         *

        3   8

       *

      8   1   0

       *

    2   7   4   4

       *

  4   5   2   6   5
The highest score is achievable by traversing the cows as shown above.*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 350;
int a[maxn][maxn];
int main()
{
    int n;scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j <= i ; j++)
            scanf("%d",&a[i][j]);

    for(int i = n - 2 ; i >= 0 ; i--)
        for(int j = 0 ; j <= i ; j++){
            a[i][j] = max(a[i + 1][j] + a[i][j], a[i + 1][j + 1] + a[i][j]);
    }

    printf("%d\n",a[0][0]);
}

