#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
using namespace std;
int main()
{
    int board_x = 100, board_y = 100, sx = 0, sy = 0, tx = 0, ty = 0;
    char road = ' ', wall = '#', target = '@', start = 'I';
    char map[board_x][board_y];
    bool book[board_x][board_y];
    memset(map, wall, sizeof(map));
    memset(book, 0, sizeof(book)); /*
    for (int i = 0; i < board_y; i++)
    {
        for (int j = 0; j < board_x; j++)
            printf("%c",book[i][j]);
        cout << endl;
    }
*/
    struct node
    {
        int x, y;
    } head;
    srand((unsigned int)time(NULL));
    sx = rand() % board_x;
    sy = rand() % board_y;
    cout << sx << " " << sy << endl;
    book[sx][sy] = true;
    head.x = sx, head.y = sy;
    queue<struct node> que;
    que.push(head);
    while (que.size())
    {
        const static int move[4][2] = {{0, 2}, {0, -2}, {-2, 0}, {2, 0}};
        head = que.front();
        que.pop();
        map[head.x][head.y] = road;
        for (int i = 0; i < 4; i++)
        {
            struct node temp;
            temp.x = head.x + move[i][0];
            temp.y = head.y + move[i][1];
            if (temp.x >= 0 && temp.x < board_x && temp.y >= 0 && temp.y < board_y && !book[temp.x][temp.y])
            {
                if (rand() % 8)
                {
                    que.push(temp);
                    map[head.x + move[i][0] / 2][head.y + move[i][1] / 2] = road;
                }
                book[temp.x][temp.y] = true;
            }
        }
    }

    while (!(map[tx][ty] == road && ((tx - sx) * (tx - sx) + (ty - sy) * (ty - sy)) >= 15000))
    {
        tx = rand() % board_x;
        ty = rand() % board_y;
    }
    map[sx][sy] = start;
    map[tx][ty] = target;
    ///*
    for (int i = 0; i < board_x; i++)
    {
        for (int j = 0; j < board_y; j++)
            printf("%c", map[i][j]);
        cout << endl;
    }
    cout << tx << " " << ty << endl;
    //*/
    return 0;
}