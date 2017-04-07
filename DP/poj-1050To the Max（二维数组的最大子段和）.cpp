/*  题目自己上poj看吧  这道题挺重要的  包含了最大子段和的求法 和 路径压缩  很有代表性  反正记住乐 千万别忘了*/
 #include <cstdio>
 #include <algorithm>
 #include <cstring>
 using namespace std;
 const int maxn  = 110;
 int dp[maxn];
 int n;
 int a[maxn][maxn];
 int temp[maxn];
 int lss(int *b , int n){
    int maxone = -128;
    for(int i = 0 ; i < n ; i++)
        dp[i] = -128;
    dp[0] = b[0];
    for(int i = 1 ; i < n; i ++){
        dp[i] = max(dp[i - 1] + b[i] , b[i]);
        maxone = max(dp[i],maxone);
    }

    return maxone;
 }
 int main()
 {
    int maxone = -128,maxall = -128;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            scanf("%d",&a[i][j]);

    for(int i = 0 ; i < n ; i++){//这种清新脱俗的压缩方法？二维数组遍历方法？不知道怎么叫，用的很爽  不过我也觉得很容易忘记
        memset(temp, 0 , sizeof(temp));
        for(int j = i ;  j < n; j++){
            for(int k = 0 ; k < n ; k++){
                temp[k] += a[j][k];
            }
            maxone = lss(temp,n);//求temp数组的最大子段和
            maxall = max(maxone , maxall);//留下最大的子段和
        }
    }
    printf("%d\n",maxall);
 }
