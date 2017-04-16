//一开始没有注意字符串中有空格
#include<bits/stdc++.h>
using namespace std;
int main()

    string s;
    while(getline(cin,s)){
        for(auto i=s.begin();i!=s.end();++i){
            if(isupper(*i)){ //其实比赛的时候忘记isupper函数了  写成了is_upper 
                s.erase(i);
                --i;  //学习一下这个例程中的--i
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
