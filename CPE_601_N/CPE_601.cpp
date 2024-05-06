#include<iostream>
#include<vector>

using namespace std;

// legal: the movement does not need to step on each other's position
// allow: the movement does not step on the blocks next to each other

/*
    row = num % 8;
    col = num / 8;
*/

// 本題為苦功題 思路基本上沒啥問題就不寫了

int main() {
    int kp, qp, qnp;
    while (true)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> kp >> qp >> qnp;
        }

        if (kp == qp) {
            cout << "Illegal state\n";
            continue;
        }
        if (kp == qnp)
        {
            cout << "blah blah blah\n";
        }
    }
    

    return 0;
}