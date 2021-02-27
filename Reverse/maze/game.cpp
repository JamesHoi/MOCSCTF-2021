#include <cstdio>
#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;
int main()
{
    char map[101][101] = {
        "####################################################################################################",
        "# # #   #   # # # #   # # # # # # # # # # # ### # #   ###       # # # # # # # # # # # # # # # # # # ",
        "# # # ### ### # # # ### # # # # # # # # # # ### # # ##### ### ### # # # # # # # # # # # # # # # # #@",
        "# # # ### ###   #   ### # # # # # # # #   # # # # # ### # ### # # # # # # # # # # # # #   # # #   # ",
        "# # # ### ##### # ##### # # # # # # # # ### # # # # ### # ##### # # # # # # # # # # # # ### # # ### ",
        "# # # #   ##### # ###   #   # #   #   # ### # # # # #       ###   # # # # # # # # # # # ### # # ### ",
        "# # # # ####### # ##### # ### # ### ### ### # # # # # ### # ##### # # # # # # # # # # # ### # # ### ",
        "# # #   ### # #   # ### # ### # ### ###   # #     #   ### # ##### # # # # # # # # #   # # # # # # # ",
        "# # # ##### # # ### ### # ### # ### ### ### # ##### ############# # # # # # # # # # ### # # # # # # ",
        "#     ### # # # ### ### # # # # ### ### ### # ##### ### ###     # # #   #     # # # ### # # #       ",
        "##### ### # # # ### ### # # # # ### ### ### # ##### ### ####### # # # ### ##### # # ### # # # ##### ",
        "##### #   # # #   # # #   # # # ### # # ###   # # # ### # ##### #     ### ##### # # #   #     ##### ",
        "##### # ### # # ### # # ### # # ### # # ### ### # # ### # ##### # ### ### ##### # # # ### ######### ",
        "# #   # ###   # ### # # ### # #   # # # # # ### # # #   # # # # # ### ### #   # #   # ### ##### ### ",
        "# # ### ##### # ### # # ### # # ### # # # # ### # # # ### # # # # ####### # ### # ### ### ##### ####",
        "# # ###   ### # # # # # #     # ### # # # # # # #   # ### #   # # # ### # # ### # ###   # # # # # ##",
        "# # ##### ### # # # # # # ##### ### # # # # # # # ### ### # ### # # ### # # ### # ### ### # # # # ##",
        "# # # ### # # # # # # #   ###   # # #   #     # # ### # # # ### #   # #         # #   ### # # # # # ",
        "# # # ### # # # # # # # ####### # # # ### ##### # ### # # # ### # ### # ######### # ##### # # # # # ",
        "#   # # # #   # # # # # ### ### # # # ### ###   # # # # # #   # # ### # ######### # ### #     #   # ",
        "### # # # # ### # # # # ### ### # # # ### ##### # # # # # # ### # ### # ######### # ### # ##### ### ",
        "### # # #   ### #     #     # # # # # # # # ### # # # # #   ### #   # # # # # # # #   # # ###   ### ",
        "### # # # ##### # ##### ##### # # # # # # # ### # # # # # ##### # ### # # # # # # # ### # ##### ### ",
        "# # # #   ### # # ###   ###   # # # #   # # # # # # # # # ### # # ### # # #   #   # ### # # ### ### ",
        "# # # # ##### # # ##### ##### # # # # ### # # # # # # # # ### # # ### # # # ### ### ### # # ### ### ",
        "# #   # #####     ##### # ### # # # # ###   # # # # # # # # #   # #     # # ### ### #   # # # # # # ",
        "# ### # ##### ######### # ### # # # # ### ### # # # # # # # # ### # ##### # ### ### # ### # # # # # ",
        "# ### # # # # ##### # # # #   # # # # # # ###   # # # # # # # ### # ### # # ### # # # ### # # # #   ",
        "# ### # # # # ##### # # # # ### # # # # # ### ### # # # # # # ### # ### # # ### # # # ### # # # # ##",
        "# #       # #   # #   # # # ### # #   # #   # ###         # # # # # ###   # # # # # # # # # # # # ##",
        "# ### ##### # ### # ### # # ### # # ### # ### ### ##### ### # # # # ##### # # # # # # # # # # # # ##",
        "# ### ###   # ### # ### # # # # # # ### # ###   # ##### #   # # # # # ### #     #   # # #   # # # # ",
        "# ### ##### # ### # ### # # # # # # ### # ### ### ######### # # # # # ### # ##### ### # # ### # # # ",
        "# #   # ### # # # # # # # # # # #   # # #   # ### # ####### # # # # # # #   ##### ###   # ### # #   ",
        "# ### # ### # # # # # # # # # # # ### # # ### ### # ####### # # # # # # # ####### ### ### ### # # ##",
        "# ### # # # # # # # # #   # # # # ### # # ### # # # ### # # # # # # # # # ### # # # # ### # # # # ##",
        "# ### # # # # # # # # # ### # # # ### # # ### # # # ### # # # # # # # # # ### # # # # ### # # # # ##",
        "# # # # # # # #   # # # ### # # # # # # # # # # # # # # # # #   # # # # # # #   # # # #   # # # # # ",
        "# # # # # # # # ### # # ### # # # # # # # # # # # # # # # # # ### # # # # # # ### # # # ### # # # # ",
        "# # # # # # #   ### # # # # # # # # # # # # # # # # # # #     ### # # # # # # ### # # # ### # # # # ",
        "# # # # # # # ##### # # # # # # # # # # # # # # # # # # # ####### # # # # # # ### # # # ### # # # # ",
        "# # #         ##### # # #   # # # # #   # # #     # # # # ##### # # # # # # # # # # # # ### #   #   ",
        "# # # ### ######### # # # ### # # # # ### # # ##### # # # ##### # # # # # # # # # # # # ### # ### ##",
        "#     ### ##### # # # # # ### # # # # ### # # ###   # # # # ###   # # #   # # # # #   # # # # ### ##",
        "# ### ######### # # # # # ### # # # # ### # # ##### # # # # ### ### # # ### # # # # ### # # # ### ##",
        "# ### # ### ### # #   # # ###   #   # # # # # # ### #   #     # ### # # ### # # # # ### # # # # #   ",
        "##### # ### ### # # ### # ### ### ### # # # # # ### # ### ##### ### # # ### # # # # ### # # # # # ##",
        "### # #   # # # # # ### # # # ### ### # #   # # # # # ### ##### # # # # # # # # # # # # # # # # # ##",
        "### # # ### # # # # ### # # # ### ### # # ### # # # # ### ##### # # # # # # # # # # # # # # # # # ##",
        "#     # ### # # # #   # # # # # # # #   # ### # # # #   # # # # # # # # # # # # #   # # # # # # # # ",
        "# ### # ### # # # # ### # # # # # # # ### ### # # # # ### # # # # # # # # # # # # ### # # # # # # # ",
        "# ### #   # # # # # ### # # # # # # # ### ### # # # # ### # # # # # # # # # # # # ###   # # # # # # ",
        "# ### # ### # # # # ### # # # # # # # ### ### # # # # ### # # # # # # # # # # # # ### ### # # # # # ",
        "# ###   ### # #   # # # #   # # # # # #   ### #   # # ### # # #   # # # # # # # # # # ### # # # # # ",
        "##### ##### # # ### # # # ### # # # # # ##### # ### # ### # # # ### # # # # # # # # # ### # # # # # ",
        "### # ##### # # ### # # # ### # # #     ### # # ### #   # # # # ### # # # # #   # # # #   # #   # # ",
        "### # ##### # # ### # # # ### # # # ####### # # ### # ### # # # ### # # # # # ### # # # ### # ### # ",
        "# # # # # # # #   # # # # # # # # # ###   # # # # #   ### # # # # # # #       ###   # # ### # ### # ",
        "# # # # # # # # ### # # # # # # # # ##### # # # # # ##### # # # # # # # ######### ### # ### # ### # ",
        "# # # # # # # # ### # #       # # #   ### #     # # ###     # # # # #   ####### # ###               ",
        "# # # # # # # # ### # # ### ### # # ##### # ##### # ##### ### # # # # ######### # ### ######### ####",
        "#     # # # # # # # # # ### #   #   ###   # ##### # # ### ### # # # # ### # # # # # # ######### #   ",
        "# ##### # # # # # # # # ####### # ####### # ##### # # ### ### # # # # ### # # # # # # ########### ##",
        "# ### # # # # # # #       ##### # ### ### # # # # # # # # # # # # # # ### # # # # # # # #     ### ##",
        "# ### # # # # # # # ### ####### # ### ### # # # # # # # # # # # # # # ### # # # # # # # # ### ### ##",
        "# ###   # # # #   # ### ##### # # # # # # # # # # # # # #                                 ###       ",
        "# ##### # # # # ### ######### # # # # # # # # # # # # # # ### # # # # # # # # # # # # # # ##########",
        "# # ### # # #   ###   ##### # # # # # # # # # # # #       ### # # # # # # # # # # # # # #         ##",
        "# # ### # # # ##### ####### # # # # # # # # # # # # ### ####################### ####################",
        "# # # # # # # ### # ##### # # # # #     # # # # #   ### ### # # ### ### #   ### ### # # # # ##### # ",
        "# # # # # # # ### # ##### # # # # # ##### # # # # ######### # # ### ### # ######### # # # # ##### # ",
        "# # # # # # # # # # # # # # # # # # #####         ### # # # # # # # # # # ### ### # # # # # # # # # ",
        "# # # # # # # # # # # # # # # # # # ##### ### # ##### # # # # # # # # # # ### ### # # # # # # # # # ",
        "# # # # # # #                             ### # ### #                                               ",
        "# # # # # # # ### # # ### # ### # # # # # ######### # ### # # # ### # # # # # # # # # # # # # # # # ",
        "# # # # # # # ### # # ### # ### # # # # #             ### # # # ### # # # # # # # # # # # # # # # # ",
        "# # # # # # # ############# ### # # # # # # # # ##### ### # ### ### # # ##### # # ##### # # # # # # ",
        "#I            ### # ### ###   # # # # # # # # # ##### ### # ###   # # # ##### # # ##### # # # # # # ",
        "# # # # # # # ### # ### ### # # # # # # # # # ####### ##############################################",
        "# # # # # # #       ### # # # # # # # # # # # ##### #   ### # # #                                   ",
        "# # # ### # # # ####### # ######################### ####### # # # ### ##### # # # # # # ### # # # # ",
        "# # # ### # # # #####                                             ### ##### # # # # # # ### # # # # ",
        "# # # ##### # # ##### ### # ### # # # # # ### # # # # # # # # # # ########### ### # # # ### # # ### ",
        "# # #   ### # #       ### # ### # # # # # ### # # # # # # # # # #         ### ### # # #   # # # ### ",
        "# ### # ### # # ### # ############################### # # ### # # # # # # ######### # # # # # ##### ",
        "# ### #   # # # ### #                             ### # # ### # # # # # #       ### # # # # # ##### ",
        "# ##### # # # # ### # ##### # # # # # # # ### # ##### # # ### # # # # # # # ### ####################",
        "# ##### # # # #   # # ##### # # # # # # # ### # ##### # #   # # # # # # # # ###                     ",
        "# ##### # # # # # # # ##### # ### # # # # ### # ##### # # ### # # # # # # # ### # # # # # # ### ####",
        "# ###   # # # # # # #     # # ### # # # #   # # ###   # # ### # # # # # # #   # # # # # # # ### ####",
        "# ##### # # # # # # # # ##### ### # # # # # ### ### # # # ### # # # # # # # # # # ### # # # ### ####",
        "#     # # # # # # # # # #####   # # # # # # ### ### # # #   # # # # # # # # # # # ### # # #   #     ",
        "# # ##### # # # ### # # ####### # # # # ### ### ##### # # # # ##### # # # # # # # ### # # # # # # # ",
        "# # ##### # # # ### # #     ### # # # # ###   #   ### # # # # ##### # # # # # # #   # # # # # # # # ",
        "# # ##### # # # ### # # # # ### # # # # ##### # # ##### # # # ##### # ### # ### # # # # # # ### # # ",
        "# #     # # # #   # # # # #   # # # # #   ### # #   ### # # #     # # ### # ### # # # # # # ### # # ",
        "# # # # # # # # # # # # # # # ### # # # # ### ### # ##### # # # # # # ##### ### # # ### ### ### # # ",
        "# # # # # # # # # # # # # # # ### # # # #   # ### #   ### # # # # # #   ###   # # # ### ###   # # # ",
        "# # # ### # # # # # # # # # # ##### # # # # # ### # # ####### # # # # # ####### # # ### ### # # # # ",
        "# # # ### # # # # # # # # # #   ### # # # # #   # # #     ### # # # # #   ##### # #   #   # # # # # "};

    int board_x = 100, board_y = 100, sx = 77, sy = 1, tx = 2, ty = 99;
    int x = sx, y = sy;
    bool book[100][100];
    memset(book, 0, sizeof(book));
    cout << "Welcome to MOCSCTF!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    cout << "Please input your flag:" << endl;
    system("pause");
    system("cls");
    while (x != tx || y != ty)
    {
        char key;
        key = getch();
        switch (key)
        {
        case 'a':
        case 'A':
        {
            int nx = x;
            int ny = y - 1;
            if (nx < 0 || nx >= board_x || ny < 0 || ny >= board_y || map[nx][ny] == '#' || map[nx][ny] == '*')
                continue;
            map[nx][ny] = 'I';
            map[x][y] = '*';
            x = nx;
            y = ny;
            system("cls");
            break;
        }
        case 'd':
        case 'D':
        {
            int nx = x;
            int ny = y + 1;
            if (nx < 0 || nx >= board_x || ny < 0 || ny >= board_y || map[nx][ny] == '#' || map[nx][ny] == '*')
                continue;
            map[nx][ny] = 'I';
            map[x][y] = '*';
            x = nx;
            y = ny;
            system("cls");
            break;
        }
        case 'w':
        case 'W':
        {
            int nx = x - 1;
            int ny = y;
            if (nx < 0 || nx >= board_x || ny < 0 || ny >= board_y || map[nx][ny] == '#' || map[nx][ny] == '*')
                continue;
            map[nx][ny] = 'I';
            map[x][y] = '*';
            x = nx;
            y = ny;
            system("cls");
            break;
        }
        case 's':
        case 'S':
        {
            int nx = x + 1;
            int ny = y;
            if (nx < 0 || nx >= board_x || ny < 0 || ny >= board_y || map[nx][ny] == '#' || map[nx][ny] == '*')
                continue;
            map[nx][ny] = 'I';
            map[x][y] = '*';
            x = nx;
            y = ny;
            system("cls");
            break;
        }
        default:
            system("cls");
        }
    }
    system("cls");
    cout << "Congratulation!!! flag = MOCSCTF{(md5 32 lowercase of best input)}";
    return 0;
}
