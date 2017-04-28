#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
string a;
double judge(int dir , int i,int n){
    if(i < 0 || i >= n ||a[i] == '.' ) return 1.0;
    else if(dir != 0 && a[i] != '_') return 0;
    else if(a[i] == '/') return judge(-1 , i - 1,n);
    else if(a[i] == '\\') return judge(1 , i + 1,n);
    else if(a[i] == '|') return (judge(1 , i + 1,n) + judge(-1 ,i - 1,n)) / 2.0;
    else{
        if(dir == 1) return judge(1 , i + 1 , n);
        else if(dir == 0) return 0.0;
        else if(dir == -1) return judge(-1 , i - 1 , n);
    }
}
int main()
{

    while(cin >> a){
        if(a[0] == '#') break;
        double p = 0, n = 0;
        for(int i = 0 ; i < a.size() ; i++){
            p += judge(0,i , a.size());
            n++;
        }
        cout <<  (int)(p * 100.0/ n) << endl;
    }
}
