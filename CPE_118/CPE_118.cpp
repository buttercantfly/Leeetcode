#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
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
int board[55][55]; // board for lost information (max size is 55x55)

// test function
int main(){
    int bx, by; // board boundary
    cin >> bx >> by;

    int x, y; // start point 
    char face; // start facing
    int intf; // tmp int for facing
    string str; // actions

    // 讀一個action的過程應該如何比較好?
    // 1. 判斷為前進還是轉向
    //      a. 前進則根據當前face去做判斷，根據bx by 檢查是否超出範圍
    //          a1. 如果沒超出範圍則移動(更改x y)並繼續下個動作
    //          a2. 若超出則檢查board是否為1(已經有機器掉下去過)
    //              a21. 若為1則忽略此動作並繼續下個動作
    //              a22. 若為0則將此處改為1並結束動作回傳LOST
    //      b. 轉向就直接轉就好(根據LR)

    pair<int,int> dr[4] = {pair<int,int>(1,0),pair<int,int>(0,-1),pair<int,int>(-1,0),pair<int,int>(0,1)}; // ESWN
    
    map<char,int> mp_ctoi;
    map<int, char> mp_itoc;
    mp_ctoi['E'] = 0; mp_itoc[0] = 'E';
    mp_ctoi['S'] = 1; mp_itoc[1] = 'S';
    mp_ctoi['W'] = 2; mp_itoc[2] = 'W';
    mp_ctoi['N'] = 3; mp_itoc[3] = 'N';

    bool isLost = false;

    while (cin >> x >> y >> face >> str)
    {
        for (char act:str)
        {
            if (act == 'F')
            {
                intf = mp_ctoi[face];
                // out of bound
                if (x+dr[intf].first  > bx || x+dr[intf].first  < 0 ||
                    y+dr[intf].second > by || y+dr[intf].second < 0)
                {
                    if (board[x][y] == 1) continue;
                    else
                    {
                        board[x][y] = 1;
                        cout << x << " " << y << " " << face << " LOST" << endl;
                        isLost = true;
                        break;
                    }
                }
                // in area
                else
                {
                    x += dr[intf].first;
                    y += dr[intf].second;
                }
            }
            else
            {
                intf = mp_ctoi[face];
                if      (act == 'R') intf++;
                else if (act == 'L') intf--;
                else return -1;
                intf = (intf+4) % 4;
                face = mp_itoc[intf];
            }
        }
        if(!isLost) cout << x << " " << y << " " << face << endl;
        else isLost = false;
    }

    return 0;
}