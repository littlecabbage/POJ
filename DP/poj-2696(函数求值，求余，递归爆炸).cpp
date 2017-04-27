//当一道题目摆在你的面前，没有人告诉你这是什么题型  你就会开始踩坑 
// 当你开始用递归的时候  你是否会考虑空间的问题？
//这道题顺便帮你理解一下什么叫做求余？  如果你的模是个负数  那么你就应该加上余数。。

#include <iostream>
using namespace std;
int a,b,c,d,e,f,g,h,ans;
const int maxn = 1000 + 10;
int val[maxn];
int mod(int x , int y){
    int t = x % y;
    if(t < 0) t += y;
    return t;
}
void init()
{
    val[0] = a;
    val[1] = b;
    val[2] = c;
    for(int i = 3 ; i <= ans ; i++){
        if( i % 2 == 1) val[i] = mod(d * val[i - 1] + e * val[i - 2] - f* val[i - 3] , g);
        else val[i] = mod(f * val[i - 1] - d * val[i - 2] + e * val[i - 3] , h);
    }
}
int main()
{
    int n;
    cin >> n;
    while(n --){
        cin >> a >> b >> c >> d >> e >> f >> g >> h >> ans;
        init();
        cout << val[ans] <<endl;
    }
}
