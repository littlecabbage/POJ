#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
bool isprime(double a){
    int i;
    for(i = 2  ;i <= sqrt(a) ; i++)
        if((int)a % i == 0) break;

    if(i > sqrt(a)) return true;
    return false;
}
int main()
{
    double a,b;
    while(scanf("%lf%lf",&a,&b) && a != -1 , b != -1){
        if(a < 2) a = 2;
        int sum = 0;
        for(int i = a ; i <= b; i++){
            if(isprime(i)) sum++;
        }

        cout << sum << endl;
    }
}
