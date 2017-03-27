#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
    vector<char> s1,ans;
    int n;
    scanf("%d",&n);
    getchar();
    s1.resize(n);
    char ch;
    for(int i = 0; i < n ; i ++){
        scanf("%c",&ch);
        getchar();
        s1[i] = ch;
    }
    int a = 0 ,b = n - 1;
    while(a <= b){
        int flag = 0;
        for(int i = 0 ;a + i < b - i ; i ++ ){
            if(s1[a + i] <  s1[b - i]) {
                flag = 1;
                break;
            }
            else if(s1[a + i] > s1[b - i]) {
                flag = 0;
                break;
            }
        }

        if(flag == 1) ans.push_back(s1[a++]);
        else ans.push_back(s1[b--]);
    }
    for(int i = 0 ; i < n ; i ++){
        printf("%c",ans[i]);
        if((i + 1) % 80 == 0 )printf("\n");
    }

    printf("\n");
}
