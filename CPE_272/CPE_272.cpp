#include <iostream>
using namespace std;

/*
note:
    把左雙引號(")變成
    =>``左雙引號
    以及右雙引號(")變成
    =>''右雙引號
*/
 
int main() {
    bool isLeft;
    string str;
    string strA;

    while (cin >> str)
    {
        isLeft = true;
        strA = "";
        
        for (char c:str)
        {
            if (c == '"' && isLeft)
            {
                strA += "``";
                isLeft = false;
            }
            else if (c == '"' && !isLeft)
            {
                strA += "''";
                isLeft = true;
            }
            else
            {
                strA += c;
            }
        }
        cout << strA << endl;
    }

    return 0;
}