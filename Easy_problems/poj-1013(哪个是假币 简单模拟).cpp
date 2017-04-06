#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int mark = 999;
int ans[12];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
            memset(ans,0,sizeof(ans));
            char a[100],b[100],c[100];
            for(int i = 0 ; i < 3 ; i++){
               scanf("%s%s%s",a,b,c) ;
               if(strcmp(c,"even") == 0){
                    for(int i = 0 ; i < strlen(a) ; i++)
                        ans[a[i] - 'A'] = mark;
                    for(int i = 0 ; i < strlen(b); i++)
                        ans[b[i] - 'A'] = mark;
                }else if(strcmp(c,"up") == 0){
                        for(int i = 0 ; i < strlen(a) ; i++)
                            if(ans[a[i] - 'A'] != mark) ans[a[i] - 'A']++;
                        for(int i = 0 ; i < strlen(b) ; i++)
                            if(ans[b[i] - 'A'] != mark)
                                        ans[b[i] - 'A']--;
                }else{
                        for(int i = 0 ; i < strlen(a) ; i++)
                            if(ans[a[i] - 'A'] != mark)
                                        ans[a[i] - 'A']--;
                        for(int i = 0 ; i < strlen(b) ; i++)
                            if(ans[b[i] - 'A'] != mark)
                                    ans[b[i] - 'A']++;
                }
        }
        int maxn = 0;
        int maxi = -1;
        for(int i = 0 ; i < 12 ; i++){
                if(ans[i] != mark && ans[i] != 0){
                    if(maxn < abs(ans[i])){
                        maxn = abs(ans[i]);
                        maxi = i;
                    }
                }
        }
        if(ans[maxi] < 0) printf("%c is the counterfeit coin and it is light. \n",'A' + maxi);
        else printf("%c is the counterfeit coin and it is heavy. \n",'A' + maxi);
    }
}

