#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
const int maxn = 1e3 + 10;
using namespace std;
typedef pair<float ,float> P;
P p[maxn],c[maxn];
bool cmp(P a ,P b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}
int main()
{
    int n;
    float x,y,d;
    int k = 0;
    while(cin >> n >> d){
        if(n == 0 && d == 0) break;
        bool flag = 1;
        if(d <= 0) flag = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> x >> y;
            if(d * d < y * y) flag = 0;
            p[i].first = x - sqrt(d * d - y * y);
            p[i].second = x + sqrt(d * d - y * y);
        }
        sort(p, p + n , cmp);
        int ans = 1;
        for(int i = 1 ; i < n ; i++){
            if(p[i].first > p[i - 1].second){
                ans ++;
            }else{
                p[i].first = max(p[i].first,p[i-1].first);
                p[i].second = min(p[i].second, p[i-1].second);
            }
        }
        if(flag == 0) printf("Case %d: -1\n",++k);
        else printf("Case %d: %d\n",++k,ans);
    }
}
