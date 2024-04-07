#include<iostream>

using namespace std;

// note:注意一些布林值的計算 不要隨便寫 到時候要debug更久

int main() {
    int a,b,carry,inCarry;
    cin >> a >> b;
    while (a!=0 || b!=0)
    {
        carry = 0;
        inCarry = 0;
        while (a>0 || b>0)
        {
            inCarry = (a%10 + b%10 + inCarry)/10;
            if (inCarry > 0) carry++;
            a/=10;
            b/=10;
        }

        if (carry == 1) cout << carry << " carry operation.\n";
        else if(carry > 1) cout << carry << " carry operations.\n";
        else cout << "No carry operation.\n";

        cin >> a >> b;
    }

    return 0;
}