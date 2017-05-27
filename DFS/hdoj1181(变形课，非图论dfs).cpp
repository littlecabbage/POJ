//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
vector<string> lib;
const int maxn = 10000;
int vis[maxn];
bool dfs(string s){
    
    int e = s.size() - 1;

    if(s[e] == 'm') {
        return true;
    }

    for(int i = 0 ; i < lib.size() ; i++){
     
        if(!vis[i] && lib[i][0] == s[e]){
             vis[i] = 1;
             if(dfs(lib[i])) return true;//非剪枝。需要将根节点判断返回
        }
    }
    
    return false;
}

int main()
{
    string s;
    while(cin >> s){
        if(s[0] == '0'){
            int flag = 0;
           
            for(int i = 0 ; i < lib.size() ; i++){
                if(lib[i][0] == 'b'){
                    memset(vis , 0 , sizeof(vis));
                    vis[i] = 1;
                    
                    if(dfs(lib[i])) flag = 1;
                }
            }

            if(flag == 1) cout << "Yes." <<endl;
            if(flag == 0) cout << "No." << endl;
            
            lib.clear();
         }
        
        else lib.push_back(s);
    }
    return 0;
}
