#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
// note

// input
// 1. board size (boundary_x,boundary_y)
// 2. sequence of robots information
//      a. start position (x,y) + facing direction (N/S/E/W)
//      b. sequence of actions L/R/F
//
// =>針對LRF三種動作進行狀態變化，每次F就偵測是否超出boundary即可
//
// output
//      對於每一個機器人，你都必須輸出其最後所在的坐標和面對的方向。
//      如果一個機器人會掉落出此世界外，你必須先輸出他在掉落前，
//      最後的所在位置和面對的方向，再多加一個字： LOST 。


// 目前還差棋盤的劃記（如果某處已經產生LOST則該位置忽略LOST動作）

// test function
int main(){
    // given values
    int bdry[2];
    cin >> bdry[0] >> bdry[1];
    int x;
    int y;
    int face;
    bool isLost = false;
    string str;
    while (cin >> x >> y >> face >> str)
    {
        for (char i:str)
        {
            if (i == 'L')
            {
                face++;
                face = face%4;
            }
            else if (i == 'R')
            {
                face--;
                face = face%4;
            }
            else if (i == 'F')
            {
                /* code */
                if (face == 0) x++;
                else if (face == 1) y--;
                else if (face == 2) x--;
                else y++; // need to check if face only = 0/1/2/3

                if (x>bdry[0]) x--; 
                else if(x<bdry[0]) x++;
                else if(y>bdry[1]) y--;
                else if(y<bdry[1]) y++;
                if (x>bdry[0] || x<bdry[0] || y>bdry[1] || y<bdry[1]) {
                    isLost == true;
                    break;
                }
            }
            else return -1;
        }
        cout << x << " " << y << " " << face << endl;
    }

    return 0;
}