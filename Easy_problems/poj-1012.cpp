//今天又学习了一种加快速度方法  hhhhh
//区别于打表 只是计算好了之后 把结果保存起来  而不是每次输入都要计算一下
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 15 * 2;
int book[maxn] = {1};
vector<char> v;
int main()
{
    for(int k = 1 ; k < 14 ; k++){
        v.clear();
        for(int i = 0 ; i < k ; i++) v.push_back('g');
        for(int i = k ; i < 2 * k ; i++) v.push_back('b');
        vector<char> temp;
        int s = 0;
        //for(int i = k ; i >= 0 ; i--)if(book[i]){s = book[i]; break;}
        for(int i = k;  ; i++){
            temp.clear();
            for(int j = 0 ; j < 2 * k ; j++)
                temp.push_back(v[j]);
            int t = k;
            int pos = 0;
            while(t != 0){
                pos = (pos + i - 1) % temp.size();
                //if(pos == -1) pos = v.size() - 1;
                if(temp[pos] == 'g') break;
                else{
                    temp.erase(temp.begin() + pos);
                    t--;
                }
            }
            if(t == 0) {book[k] = i;break;}
        }
    }
    int k;
    while(scanf("%d",&k) && k != 0){
        printf("%d\n",book[k]);
    }

}
