//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int ans[20];
int vis[20];
int N;
bool isprime(int x){
    for(int i = 2 ; i < x ; i++){
        if(x % i == 0) return 0;
    }
    return 1;
}
bool dfs(int n, int *ans){
    if(n == N){
        if(! isprime(ans[n-1] + ans[0])) return 0;
        for(int i = 0 ; i < N ; i++){
            if(i > 0) cout << " " ;
            cout << ans[i];
         }
         cout << endl;
         return 1;
    }

    for(int i = 2; i <= N ; i++){
        if(!vis[i] && isprime(i + ans[n - 1])){
            vis[i] = 1;
            ans[n] = i;
            dfs(n + 1 , ans);
            vis[i] = 0;
        }
    }
    return 0;
}
int main()
{
    int k = 0;
    while(cin >> N){
        ans[0] = 1;
        vis[1] = 1;
        cout << "Case " << ++k << ":\n";
        dfs(1,ans);
        cout <<endl;
    }
}
