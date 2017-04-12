//别那么着急  慢慢写嘛  简单模拟题
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        int lenth;scanf("%d",&lenth);
        vector<char> paren;
        int p1 = 0, p2 = 0;
        for(int i = 0 ; i < lenth ; i++){
                scanf("%d",&p2);
                for(int i = 0 ; i < p2 - p1 ; i++)
                    paren.push_back('l');
                p1 = p2;
                paren.push_back('r');
                int sum = 1;
                for(int j = paren.size() - 2 ; j >= 0 ; j-- ){
                    if(paren[j] == 'l') {
                        paren[j] = 'm';
                        //*paren.end() = sum;
                        break;
                    }else if(paren[j] =='m') sum++;
                }
//                for(int j = 0 ; j < paren.size() ; j++)
//                    printf("%c ",paren[j]);
//                printf(" sum = %d\n",sum);
                  printf("%d ",sum);
        }
        printf("\n");
    }
}
