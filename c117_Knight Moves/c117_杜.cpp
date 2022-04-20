/*
 * Author: 余承諺
*/

#include <iostream>
#include <string>
#include <vector>

struct Pos {
    int x, y;
};

bool operator==(const Pos& a, const Pos& b) {
    return (a.x == b.x) && (a.y == b.y);
}

int depth[8][8];
std::vector<Pos> queue;

int del_x[]{ -1, -1, 1, 1, -2, -2, 2, 2 };
int del_y[]{ -2, 2, -2, 2, -1, 1, -1, 1 };

int F(Pos start, Pos end) {
    for (int i{ 0 }; i < 8; ++i) {
        for (int j{ 0 }; j < 8; ++j) { depth[i][j] = -1; }
    }

    queue.clear();
    queue.reserve(8 * 8);

    depth[start.x][start.y] = 0;
    queue.push_back(start);

    for (int i{ 0 }; i < queue.size(); ++i) {
        Pos pos{ queue[i] };

        if (pos == end) { return depth[pos.x][pos.y]; }

        for (int k{ 0 }; k < 8; ++k) {
            Pos next_pos{ pos.x + del_x[k], pos.y + del_y[k] };

            if (next_pos.x < 0 || 8 <= next_pos.x || next_pos.y < 0 ||
                8 <= next_pos.y) {
                continue;
            }

            if (depth[next_pos.x][next_pos.y] == -1) {
                depth[next_pos.x][next_pos.y] = depth[pos.x][pos.y] + 1;
                queue.push_back(next_pos);
            }
        }
    }

    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;

    while (getline(std::cin, str)) {
        int ans{ F(Pos{ str[0] - 'a', str[1] - '1' },
                   Pos{ str[3] - 'a', str[4] - '1' }) };

        std::cout << "To get from " << str[0] << str[1] << " to " << str[3]
                  << str[4] << " takes " << ans << " knight moves.\n";
    }

    return 0;
}