/*                                    Longest Ordered Subsequence
                            Time Limit: 2000MS		Memory Limit: 65536K
                            Total Submissions: 50678		Accepted: 22511
                            Description

A numeric sequence of ai is ordered if a1 < a2 < ... < aN. Let the subsequence of the given numeric sequence (a1, a2, ..., aN) be any sequence (ai1, ai2, ..., aiK), where 1 <= i1 < i2 < ... < iK <= N. For example, sequence (1, 7, 3, 5, 9, 4, 8) has ordered subsequences, e. g., (1, 7), (3, 4, 8) and many others. All longest ordered subsequences are of length 4, e. g., (1, 3, 5, 8).

Your program, when given the numeric sequence, must find the length of its longest ordered subsequence.
Input

The first line of input file contains the length of sequence N. The second line contains the elements of sequence - N integers in the range from 0 to 10000 each, separated by spaces. 1 <= N <= 1000
Output

Output file must contain a single integer - the length of the longest ordered subsequence of the given sequence.
Sample Input

7
1 7 3 5 9 4 8
Sample Output

4


index:最长公共子列模板题
*/

#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int max_num = 0;
    vector<int> a,dp;
    a.resize(n);
    dp.resize(n);
    for(int i = 0 ; i < n ; i++)
        scanf("%d",&a[i]);
    for(int i = 0 ; i < n ; i++)
        dp[i] = 1;
    int res = 0;
    for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j ++)
                if(a[i] > a[j]){
                    dp[i] = max(dp[j] + 1,dp[i]);
                }
            res = max(res,dp[i]);
    }
    printf("%d\n",res);
}
