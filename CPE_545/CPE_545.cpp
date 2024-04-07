#include<iostream>

using namespace std;

int main() {
    int n,m;
    cin >> m;
    while (m--)
    {
        cin >> n;
        int dec = n,hex = n;
        int b1 = 0,b2 = 0,tmp = 0;
        while (dec > 0)
        {
            b1 += dec%2;
            dec /= 2;
        }

        while (hex > 0)
        {
            tmp = hex%10;
            hex /= 10;
            while (tmp > 0)
            {
                b2 += tmp%2;
                tmp /= 2;
            }
        }

        cout << b1 << ' ' << b2 << "\n";
    }

    return 0;
}