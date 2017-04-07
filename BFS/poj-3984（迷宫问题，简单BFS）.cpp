 /*                                                                     迷宫问题
                                                    Time Limit: 1000MS		Memory Limit: 65536K
                                                    Total Submissions: 20675		Accepted: 12106
                                                    Description

定义一个二维数组： 

int maze[5][5] = {

	0, 1, 0, 0, 0,

	0, 1, 0, 1, 0,

	0, 0, 0, 0, 0,

	0, 1, 1, 1, 0,

	0, 0, 0, 1, 0,

};

它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。
Input

一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。
Output

左上角到右下角的最短路径，格式如样例所示。
Sample Input

0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
Sample Output

(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(2, 3)
(2, 4)
(3, 4)
(4, 4)
美好的一天从一道BFS水题开始23333
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
int a[5][5];
int vis[5][5];
pair<int ,int> pre[5][5];
void print_path(){
    stack<pair<int, int> > s;
    s.push(make_pair(4,4));
    while(s.top().first != 0 || s.top().second != 0 ){
        int nowx = s.top().first , nowy = s.top().second;
        s.push(pre[nowx][nowy]);
    }
    while(!s.empty()){
        printf("(%d, %d)\n",s.top().first , s.top().second);
        s.pop();
    }
}
int main()
{
    for(int i = 0 ; i < 5 ; i++)
        for(int j = 0 ; j < 5 ; j++){
            scanf("%d",&a[i][j]);
            vis[i][j] = 0;
            pre[i][j].first = -1;
            pre[i][j].second = -1;
        }

    queue<pair<int , int > > Q;
    Q.push(make_pair(0, 0));
    vis[0][0] = 1;
    while(!Q.empty()){
        int nowx = Q.front().first;
        int nowy = Q.front().second;
        vis[nowx][nowy] = 1;
        Q.pop();

        if(nowx == 4 && nowy == 4) {print_path();break;}
        int next[][2] = {{-1,0},{0,1},{1,0},{0,-1}};
        for(int i = 0 ; i < 4 ; i ++){
            int next_x = nowx + next[i][0];
            int next_y = nowy + next[i][1];

            if(next_x >= 0 && next_x < 5 && next_y >= 0 && next_y < 5 && !a[next_x][next_y] && !vis[next_x][next_y]){
                Q.push(make_pair(next_x,next_y));
                pre[next_x][next_y].first = nowx;
                pre[next_x][next_y].second = nowy;
            }
        }
    }
}
