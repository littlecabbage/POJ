//简单素数

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int a[1001];
int main()
{
    int n,c;
    vector<int> v;
    while(scanf("%d%d",&n,&c) != EOF){
        v.clear();
        memset(a , 1, sizeof(a));
        for(int i = 2 ; i * i <= n ; i++)
            for(int j = 2 * i ; j <= n ; j += i)
                a[j] =  0;


        for(int i = 0; i <= n ; i++)
            if(a[i])v.push_back(i);
        int s,e;
        if((v.size() - 1) % 2 == 0){//oushu
            int mid = (v.size() - 1) / 2;
            s = mid - c + 1;
            e = mid + c ;
        }else{
            int mid = v.size() / 2;
            s = mid - c + 1;
            e = mid + c - 1;
        }

        if(s < 1) s = 1;
        if(e >= v.size()) e = v.size() - 1;
        printf("%d %d:",n,c);
        for(int i = s ; i <= e ; i++)
            printf(" %d",v[i]);

        printf("\n\n");
    }
}
