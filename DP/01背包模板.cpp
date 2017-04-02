//问题描述  n个重量和价值分别为wi vi 的物品 从这些物品中挑选出总重量不超过W的物品 求所有挑选方案中价值最大的


//递归形式
//#include <iostream>
//using namespace std;
//int w[100],v[100];
//int n;
//int res(int i , int weight )
//{
//    int res_num = 0;
//    if(i == n) return res_num;
//    else {
//        if(weight < w[i]) return res(i + 1, weight);
//        else return max(res(i + 1 , weight),res(i + 1 , weight - w[i]) + v[i]);
//    }
//}
//
//int main()
//{
//    cin >> n;
//    for(int i = 0 ; i < n ; i++)
//        cin >> w[i] >> v[i];
//
//    cout << res(0,5);
//}
//记忆化数组

//本质上和上一个递归没有去什么区别  只是用一个dp数组保存了数据结果  一旦发现这个结果计算过  那么就直接返回他的数值

// if(dp >= 0) return dp[i][j]

//return dp[i][j] = res_num


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[100][100];
int w[100],v[100];
int n;
int res(int i , int j)
{
    if(dp[i][j] >= 0) return dp[i][j];
    else{
        int res_num = 0;
        if(i == n) res_num = 0;
        else{
            if(j < w[i]) res_num = res(i + 1 , j);
            else res_num = max(res(i + 1 , j) , res(i + 1 , j - w[i]) + v[i]);
        }

        return dp[i][j] = res_num;
    }
}


int main()
{
    cin >> n ;
    for(int i = 0 ; i < n ; i ++)
        cin >> w[i] >> v[i];
    memset(dp, -1 , sizeof(dp));
    cout << res(0,5);
}
