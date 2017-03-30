/*                                                                Palindrome
                                                    Time Limit: 3000MS		Memory Limit: 65536K
                                                    Total Submissions: 62331		Accepted: 21714
Description

A palindrome is a symmetrical string, that is, a string read identically from left to right as well as from right to left. You are to write a program which, given a string, determines the minimal number of characters to be inserted into the string in order to obtain a palindrome. 

As an example, by inserting 2 characters, the string "Ab3bd" can be transformed into a palindrome ("dAb3bAd" or "Adb3bdA"). However, inserting fewer than 2 characters does not produce a palindrome. 
Input

Your program is to read from standard input. The first line contains one integer: the length of the input string N, 3 <= N <= 5000. The second line contains one string with length N. The string is formed from uppercase letters from 'A' to 'Z', lowercase letters from 'a' to 'z' and digits from '0' to '9'. Uppercase and lowercase letters are to be considered distinct.
Output

Your program is to write to standard output. The first line contains one integer, which is the desired minimal number.
Sample Input

5

Ab3bd
Sample Output

2

index:  lenth(string) - lcs(s,s');
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<char> s,s2;
int res[2][5001] = {0};
int n;
int main()
{
    scanf("%d",&n);
    getchar();
    s.resize(n + 1);
    s2.resize(n + 1);
    for(int i = 1 ; i <= n ; i++){
            scanf("%c",&s[i]);
            s2[n - i + 1] = s[i];
    }
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1; j <= n ; j++){
            if(s[i] == s2[j]) res[(i)% 2 ][j] = res[(i - 1) % 2][j - 1] + 1;
        else res[i % 2][j] = max(res[(i - 1) % 2][j] , res[(i) % 2][j - 1]);
    }
    printf("%d\n",n - res[n % 2][n]);
}
