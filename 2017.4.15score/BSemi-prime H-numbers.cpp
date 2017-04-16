/*poj 3292 Semi-prime H-numbers

Description

This problem is based on an exercise of David Hilbert, who pedagogically suggested that one study the theory of 4n+1 numbers. Here, we do only a bit of that.

An H-number is a positive number which is one more than a multiple of four: 1, 5, 9, 13, 17, 21,... are the H-numbers. For this problem we pretend that these are the only numbers. The H-numbers are closed under multiplication.

As with regular integers, we partition the H-numbers into units, H-primes, and H-composites. 1 is the only unit. An H-number h is H-prime if it is not the unit, and is the product of two H-numbers in only one way: 1 × h. The rest of the numbers are H-composite.

For examples, the first few H-composites are: 5 × 5 = 25, 5 × 9 = 45, 5 × 13 = 65, 9 × 9 = 81, 5 × 17 = 85.

Your task is to count the number of H-semi-primes. An H-semi-prime is an H-number which is the product of exactly two H-primes. The two H-primes may be equal or different. In the example above, all five numbers are H-semi-primes. 125 = 5 × 5 × 5 is not an H-semi-prime, because it's the product of three H-primes.

Input

Each line of input contains an H-number ≤ 1,000,001. The last line of input contains 0 and this line should not be processed.

Output

For each inputted H-number h, print a line stating h and the number of H-semi-primes between 1 and h inclusive, separated by one space in the format shown in the sample.

Sample Input

21 
85
789
0
Sample Output

21 0
85 5
789 62*/

#include <cstdio>
#include <cstring>
const int maxn = 1e6 + 10;
int h[maxn];
int p[maxn];
int isp[maxn];
int main()
{
    memset(isp, 0 , sizeof(isp));
    for(int i = 1 ; i < maxn ; i += 4)
        isp[i] = 1;
    isp[1] = 0 ;
    //printf("done0\n");
    int t = 0;
    for(int i = 5 ; i < maxn ; i += 4){
        if(isp[i]){
            for(int j = 2 * i ; j < maxn ; j += i)
                if(isp[j]) isp[j] = 0;

            p[t++] = i;
        }
    }

    //printf("done1\n");
    memset(h , 0 , sizeof(h));
    int sum = 0;
    for(int i = 25 ; i < maxn ; i += 4){
        for(int j = 0 ; j < t && p[j] * p[j] <= i ; j++){
            if(!(i % p[j]) && isp[i / p[j]]) {
                sum++;
                h[i] = sum;
                break;
            }
        }
    }

    //printf("done2\n");
    int n;
    while(scanf("%d",&n) && n){
        int flag  = 1;
        for(int i = n ; i >= 0 ; i--){
            if(h[i]){
                 printf("%d %d\n",n,h[i]);
                 flag = 0;
                 break;
            }
        }
    if(flag) printf("%d 0\n",n);
    }
}

