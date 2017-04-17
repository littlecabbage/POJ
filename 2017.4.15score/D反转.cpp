                                              /*Face The Right Way
                                              Time Limit: 2000MS		Memory Limit: 65536K
                                              Total Submissions: 4888		Accepted: 2276
 Description

Farmer John has arranged his N (1 ≤ N ≤ 5,000) cows in a row and many of them are facing forward, like good cows. Some of them are facing backward, though, and he needs them all to face forward to make his life perfect.

Fortunately, FJ recently bought an automatic cow turning machine. Since he purchased the discount model, it must be irrevocably preset to turn K (1 ≤ K ≤ N) cows at once, and it can only turn cows that are all standing next to each other in line. Each time the machine is used, it reverses the facing direction of a contiguous group of K cows in the line (one cannot use it on fewer than K cows, e.g., at the either end of the line of cows). Each cow remains in the same *location* as before, but ends up facing the *opposite direction*. A cow that starts out facing forward will be turned backward by the machine and vice-versa.

Because FJ must pick a single, never-changing value of K, please help him determine the minimum value of K that minimizes the number of operations required by the machine to make all the cows face forward. Also determine M, the minimum number of machine operations required to get all the cows facing forward using that value of K.

Input

Line 1: A single integer: N 
Lines 2..N+1: Line i+1 contains a single character, F or B, indicating whether cow i is facing forward or backward.
Output

Line 1: Two space-separated integers: K and M
Sample Input

7
B
B
F
B
F
B
B
Sample Output

3 3
Hint

For K = 3, the machine must be operated three times: turn cows (1,2,3), (3,4,5), and finally (5,6,7)

这个题似乎已经很经典了……

我觉得我还是手敲一遍吧

*/

#include <cstdio>
#include <cstring>
const int maxn = 5000 + 10;
int f[maxn];
int dir[maxn];
int n;
int cal(int k){
	int res = 0;
	int sum = 0;
	memset(f, 0 , sizeof(f));
	for(int i = 0 ; i + k - 1 < n; i ++){
		if((sum + dir[i]) % 2 != 0){//核心算法  要用sum表示反转次数 用sum+dir{i}的奇偶来判断是否需要反转
			res ++;
			f[i] = 1;
		}
		sum += f[i];

		if(i - k  + 1 >= 0) sum -= f[i - k + 1];
	}

	for(int i = n - k + 1; i < n ; i++){
		if((sum + dir[i]) % 2 != 0) return -1;
		if(i - k + 1 >= 0) sum -= f[i -  k + 1];
	}

	return res;
}
int main()
{
	scanf("%d",&n);
	getchar();
	char temp;
	for(int i = 0 ; i < n ; i++){
		scanf("%c",&temp);
		getchar();
		if(temp == 'B') dir[i] = 1;
		else dir[i] = 0;
	}

	int K = n,M = 1;
	for(int i = 1 ; i <= n ; i++){
		int t = cal(i);
		if(t >= 0 && t < K){
			K = t;
			M = i;
		}
	}
	printf("%d  %d\n",M , K );
}
