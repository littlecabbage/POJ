#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int ,int >P;
const int maxn = 1e6 + 10;
int a[maxn];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 0 ; i < n ; i++)
        scanf("%d",&a[i]);

    priority_queue <P> q1,q2;
    for(int i = 0 ; i < k ; i++)
        q2.push(make_pair(-a[i],i));

    printf("%d",-q2.top().first);
    for(int i = k ; i < n ; i++){
        q2.push(make_pair(-a[i],i));
        while(q2.top().second < i - k + 1)
            q2.pop();

        printf(" %d",-q2.top().first);
    }

    puts("");

    for(int i = 0 ; i < k ; i++)
        q1.push(make_pair(a[i] , i));

    printf("%d",q1.top().first);
    for(int i = k; i < n ; i++){
            q1.push(make_pair(a[i],i));
            while(q1.top().second < i - k  + 1)
                q1.pop();
            printf(" %d",q1.top().first);
    }
}
