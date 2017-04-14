//想起来校赛那题  跟这题类似
//原来我当年推得时候用到了o（n^2）怪不得错了  还是人家的公式牛逼  我自己也推了一下 恩……这个数学归纳法很强
//s[n]-s[i]-s[i-1]-(n-2*i+1)*a[i]
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
long long a[11000];
int main()
{
    int n=1;
   long long sum,s[11000];
   while(cin>>n&&n)
    {
       sum=0;
       for(int i=1;i<=n;i++)
       {
           cin>>a[i];
       }
       sort(a+1,a+n+1);
       s[0]=0;
       for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
       for(int i=1;i<=n;i++)
       {
           sum+=s[n]-s[i]-s[i-1]-(n-2*i+1)*a[i];
       }
       cout<<sum<<endl;

    }
   return 0;
}
