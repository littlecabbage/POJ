//c++ 有毒啊  我这么依赖stl是不是不太好……
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<string> name;
int a[70];
int main()
{
    int n;
    cin >> n;
    int t = n + 1;
    name.resize(t);
    string temps;
    for(int i = 1 ; i <= n ;i++){
        cin >> temps;
        name[i] = temps;
        a[i] = 1;
    }
bu tai hao
    int s,l;
    scanf("%d,%d",&s,&l);
    int k = 0;
    int temp = n;
    for(int i = s ;temp > 0; i++){
        if(i > n) i = 1;
        if(a[i]){
            k++;
            if(k == l){
                a[i] = 0;
                k = 0;
                temps = name[i];
                cout << temps << endl;
                temp--;
            }
        }
    }
}
