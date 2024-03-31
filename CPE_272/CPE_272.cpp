#include <iostream>
using namespace std;

bool isLeft;
string str;

int main() {
    isLeft = true;

    while (getline(cin, str))
    {
        for (char c:str)
        {
            if (c == '\"' && isLeft)
            {
                cout << "``";
                isLeft = false;
            }
            else if (c == '\"' && !isLeft)
            {
                cout << "''";
                isLeft = true;
            }
            else cout << c;
        }
        cout << "\n";
    }

    return 0;
}