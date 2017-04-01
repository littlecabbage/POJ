#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int a[101][101] = {0};
int main()
{
    string cmd;
    int n , x ,y , l;
    scanf("%d",&n);
    while(n--){
        cin >> cmd >> x >> y >> l;
        //cout << cmd << endl << x << endl << y << endl << l << endl;
        if(cmd == "BLACK"){
            for(int i = x ; i < x + l; i++)
                for(int j = y ; j < y + l ; j++)
                    a[i][j] = -1;
        }
        else if(cmd == "WHITE"){
            for(int i = x ; i < x + l; i++)
                for(int j = y ; j < y + l ; j++)
                    a[i][j] = 1;
        }
        else{
            int sum = 0;
            for(int  i = x ; i < x + l ; i++)
                for(int j = y; j < y + l ; j++)
                    if(a[i][j] == -1)
                        sum++;

            printf("%d\n",sum);
        }
    }
}
