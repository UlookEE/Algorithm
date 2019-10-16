#include <iostream>
#include <algorithm>

using namespace std;

int min_change = 0x7FFFFFFF;
int board[50][50];
int chess[8][8] = {{1, 0, 1, 0, 1, 0, 1, 0},
                   {0, 1, 0, 1, 0, 1, 0, 1},
                   {1, 0, 1, 0, 1, 0, 1, 0},
                   {0, 1, 0, 1, 0, 1, 0, 1},
                   {1, 0, 1, 0, 1, 0, 1, 0},
                   {0, 1, 0, 1, 0, 1, 0, 1},
                   {1, 0, 1, 0, 1, 0, 1, 0},
                   {0, 1, 0, 1, 0, 1, 0, 1}};

void compare(int start_i, int start_j)
{
    int count_1 = 0;
    int count_2 = 0;
    
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[start_i + i][start_j + j] == chess[i][j] ? count_1++ : count_2++; 

    if (min_change > count_1)
        min_change = count_1;
    if (min_change > count_2)
        min_change = count_2;
}
int main()
{
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char c; cin >> c;
            board[i][j] = c == 'W' ? 1 : 0;
        }
    }

    for (int i = 0; i < h - 7; i++)
        for (int j = 0; j < w - 7; j++)
            compare(i, j);

    cout << min_change << endl;
    return 0;
}