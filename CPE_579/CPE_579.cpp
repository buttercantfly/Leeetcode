#include<iostream>
#include<vector>

using namespace std;

/*
    1. N = 模擬天數
    2. P = party number
    3. pi = i政黨的h

    起始天一定是星期天
    假設在每週的假日(星期五和星期六)不會有任何罷會情形。

    先用naive，一天一天看
    a. 當天若是fri or sat(mod7 = 6或0)則直接跳過(不會罷會)
    b. 當天如果屬於任一pi的倍數則為罷會(count++)
*/

int main() {
    int T,N,P,tmp,cnt; // days, current date, parties
    vector<int> pi;
    
    cin >> T;
    while (T--)
    {
        cin >> N >> P;
        while (P--)
        {
            cin >> tmp;
            pi.push_back(tmp);
        }
        
        cnt = 0;
        for (int i = 1; i < N+1; i++)
        {
            for (int j:pi)
            {
                if (i % 7 == 6 || i % 7 == 0) break;
                else if (i % j == 0)
                {
                    cnt++;
                    break;
                }
                else;
            }
        }

        pi.clear();
        cout << cnt << endl;
    }
    // naive

    return 0;
}