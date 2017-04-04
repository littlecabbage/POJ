 /*                                                             Wooden Sticks
                                                Time Limit: 1000MS		Memory Limit: 10000K
                                                Total Submissions: 22997		Accepted: 9871
Description

There is a pile of n wooden sticks. The length and weight of each stick are known in advance. The sticks are to be processed by a woodworking machine in one by one fashion. It needs some time, called setup time, for the machine to prepare processing a stick. The setup times are associated with cleaning operations and changing tools and shapes in the machine. The setup times of the woodworking machine are given as follows: 
(a) The setup time for the first wooden stick is 1 minute. 
(b) Right after processing a stick of length l and weight w , the machine will need no setup time for a stick of length l' and weight w' if l <= l' and w <= w'. Otherwise, it will need 1 minute for setup. 
You are to find the minimum setup time to process a given pile of n wooden sticks. For example, if you have five sticks whose pairs of length and weight are ( 9 , 4 ) , ( 2 , 5 ) , ( 1 , 2 ) , ( 5 , 3 ) , and ( 4 , 1 ) , then the minimum setup time should be 2 minutes since there is a sequence of pairs ( 4 , 1 ) , ( 5 , 3 ) , ( 9 , 4 ) , ( 1 , 2 ) , ( 2 , 5 ) .
Input

The input consists of T test cases. The number of test cases (T) is given in the first line of the input file. Each test case consists of two lines: The first line has an integer n , 1 <= n <= 5000 , that represents the number of wooden sticks in the test case, and the second line contains 2n positive integers l1 , w1 , l2 , w2 ,..., ln , wn , each of magnitude at most 10000 , where li and wi are the length and weight of the i th wooden stick, respectively. The 2n integers are delimited by one or more spaces.
Output

The output should contain the minimum setup time in minutes, one per line.
Sample Input

3 
5 
4 9 5 2 2 1 3 5 1 4 
3 
2 2 1 1 2 2 
3 
1 3 2 2 3 1 
Sample Output

2
1
3*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 5005;
struct P{
    int x;
    int y;
};
bool cmp(P a ,P b){
    if(a.x == b.x){
        return a.y < b.y;
    }
    return a.x < b.x;
}
vector <P> ans[maxn] , a;
int n;
void init(){
    for(int i = 0 ; i <  n ; i++) ans[i].clear();
    a.clear();
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d",&n);
        int x,y;
        P temp;
        for(int i = 0 ; i < n ; i++){
            scanf("%d%d",&temp.x,&temp.y);
            a.push_back(temp);
        }
        sort(a.begin() , a.end(),cmp);
        int i = 0 ;
        ans[i].push_back(a[0]);

        for(int j = 1 ; j < n ; j++){
            int flag = 0;

            for(int k = 0 ; k <= i ; k++){
                        if(a[j].y >= ans[k][ (ans[k].size() - 1) ].y) {ans[k].push_back(a[j]);flag = 1;break;}
            }

            if(flag == 0){i ++ ;ans[i].push_back(a[j]);}
        }
        printf("%d\n",i + 1);
    }
}

