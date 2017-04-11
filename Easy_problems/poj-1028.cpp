//啥也不想说了  ignored  Ignored  我有毒   还有啥 英语四级 看懂跟着题目走…

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string cmd , current_page = "http://www.acm.org/";
    stack<string> forward_stack ,backward_stack;
    while(cin >> cmd){
        if(cmd == "QUIT") break;
        else if(cmd == "BACK"){
            if(backward_stack.empty()) printf("Ignored\n");
            else{
                forward_stack.push(current_page);
                current_page = backward_stack.top();
                backward_stack.pop();
                cout << current_page << endl;
            }
        }
        else if(cmd == "FORWARD"){
            if(forward_stack.empty()) printf("Ignored\n");
            else{
                backward_stack.push(current_page);
                current_page = forward_stack.top();
                forward_stack.pop();
                cout << current_page << endl;
            }
        }
        else if(cmd == "VISIT"){
            backward_stack.push(current_page);
            cin >> current_page;
            cout << current_page << endl;
            while(!forward_stack.empty()){
                forward_stack.pop();
            }
        }
    }
}
