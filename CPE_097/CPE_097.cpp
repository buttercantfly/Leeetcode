#include<iostream>
#include<unordered_set>

using namespace std;

// Jolly Jumpers
// note: 檔案近來會是完整的一個file，所以使用cin處理的時候不要隨便break，反而會產生錯誤
//      !!!請先完成基本的code再做優化加速等等!!!

int main() {
    int size;
    while (cin >> size)
    {
        int arr[size] = {0};
        int prev, pres, d;
        bool isJolly = true;
        cin >> prev;
        for (int i = 0; i < size-1; i++)
        {
            cin >> pres;
            d = abs(pres - prev) - 1;
            if (d >= size || ++arr[d] > 1)
            {
                isJolly = false;
            }
            prev = pres;
        }
        
        if (isJolly) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }

    return 0;
}