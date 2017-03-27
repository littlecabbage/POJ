#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int max_time,min_time;
    int length,ant_num,pos;
    while(n--){
        scanf("%d%d",&length,&ant_num);
        max_time = -1;
        min_time = -1;
        for(int i = 0 ; i < ant_num ; i++){
            scanf("%d",&pos);
            max_time = max(max_time,max(pos,length - pos));
            min_time = max(min_time,min(pos,length - pos));
        }
        printf("%d %d\n",min_time , max_time);
    }
}
