#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<char,char> key;
    char temp;
    for(int i = 0 ; i < 26 ; i++){
        scanf("%c",&temp);
        key['a' + i] = temp;
    }
    getchar();
    string s;
    getline( cin , s);
    for(int i = 0 ; i < s.size() ; i++){
        if(isupper(s[i])) {
            printf("%c",'A' - 'a' + key[s[i] - 'A' + 'a']);
        }else if(s[i] == ' ') printf(" ");
        else printf("%c",key[s[i]]);
    }
}
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<char,char> key;
    char temp;
    for(int i = 0 ; i < 26 ; i++){
        scanf("%c",&temp);
        key['a' + i] = temp;
    }
    getchar();
    string s;
    getline( cin , s);
    for(int i = 0 ; i < s.size() ; i++){
        if(isupper(s[i])) {
            printf("%c",'A' - 'a' + key[s[i] - 'A' + 'a']);
        }else if(s[i] == ' ') printf(" ");
        else printf("%c",key[s[i]]);
    }
}
