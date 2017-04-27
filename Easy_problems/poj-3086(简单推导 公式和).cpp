#include <iostream>
using namespace std;
const int maxn = 10010;
int T[maxn],W[maxn];
int main()
{
    T[0] = 0;
    for(int i = 1 ; i < maxn ; i++)
        T[i] = T[i - 1] + i;
    W[1] = 3;
    for(int i = 2 ; i < 310 ; i++)
        W[i] = i * T[i + 1] + W[i - 1];


    int n;
    cin >> n;
    int k = 0 ;
    while(n--){
        int t;
        cin >> t;
        cout <<  ++k <<" " << t <<" " << W[t] <<endl;
    }
}
