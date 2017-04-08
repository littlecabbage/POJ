#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> v;
int main()
{
    string temp;
    while(getline(cin , temp)){
        for(int i = 0 ;  i < temp.size(); i++)
            if(temp[i] == 'y' && temp[i + 1] == 'o' && temp[i + 2] == 'u'){
                cout << "we" ;
                i = i + 2;
            }else{
                cout << temp[i];
            }
            cout << endl;
    }
}
