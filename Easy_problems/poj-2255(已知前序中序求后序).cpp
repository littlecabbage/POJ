//题目大意不说了，最近发现下面description看不见啊  谁能告诉在哪看？我原来的程序思路都放里面hhhhh
//所以在这里说一下错误吧  第五行一开始写的是 if( n == 1) {printf(a[0]);return}  一看没有毛病 如果只剩下一个了那就直接输出咯  画完图之后发现
//这种情况应该只能发生在一颗完全二叉树上  也就是说如果这棵树没有左子树或者右子树就要报错了 hhh#include <cstdio>



#include <cstring>
void findroot(int n ,char *a,char *b){
    //递归结束操作
    if(n == 0) return ;//第一次徒手写的时候没有写这行 以后记住了 没有结束操作你写个粑粑递归
    
    int  p = strchr(b,a[0]) - b;
    findroot(p , a + 1 , b);
    findroot(n - p - 1 ,a + p + 1 , b + p + 1);

    printf("%c",a[0]);
}
int main()
{
    char a[100],b[100];
    while(scanf("%s %s",a,b) != EOF){
        getchar();
        findroot(strlen(b) , a , b);
        printf("\n");
    }
}
