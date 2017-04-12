#include <cstdio>
int main()
{
    int h,m,s,speed = 0;
    int hh = 0,mm = 0,ss = 0;
    double dis = 0;
    char c;
    while(scanf("%d:%d:%d",&h,&m,&s) != EOF){
        dis += ( (h - hh) + (m - mm) / 60.0 + (s - ss) / 3600.0 ) * speed;
        hh = h ,mm = m ,ss = s;
        c = getchar();
        if(c == ' ') {scanf("%d",&speed);}
        else {
            printf("%02d:%02d:%02d %.2lf km\n",h,m,s,dis);
        }
    }
}
