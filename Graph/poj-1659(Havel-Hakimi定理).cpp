/*Havel-Hakimi定理  《图论算法理论 实现 及应用》 P18
自认为自己写的没有错误。希望以后能找出来*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
vector <P> v;
const int maxn = 15;
int E[maxn][maxn];
bool cmp(P a , P b){
    return a.first > b.first;}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        v.clear();
        for(int i = 0 ; i < maxn ; i++)
            for(int j = 0 ; j < maxn ; j++)
                E[i][j] = 0;

        int n;scanf("%d",&n);
        int edge;
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&edge);
            v.push_back(make_pair(edge,i));
        }

        sort(v.begin() , v.end(),cmp);
        int temp = n;
        int flag = 1;
        for(int i = 0 ; i < n && flag; i++){
            if(v[i].first > temp - 1) {printf("NO\n");flag = 0;break;}

            for(int j = i + 1; j <= i + v[i].first ; j++){
                if(v[j].first <= 0) {printf("NO\n");flag = 0;}
                v[j].first--;
                int head = v[i].second , to = v[j].second;
                E[head][to] = 1 , E[to][head] = 1;
            }

            temp--;
            sort(v.begin() + i + 1, v.end(),cmp);
        }
        if(flag){
            printf("YES\n");
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(j)printf(" ");
                    printf("%d",E[i][j]);
                }
                printf("\n");
            }
        }
        if(T)printf("\n");
    }
}
