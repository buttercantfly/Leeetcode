#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main() {
    int N,C,tmp,n,num,tmpNum,minCost;
    int numCost[36]; // 0~35 num cost
    vector<int> minCostBases; // record min cost bases
    cin >> N;
    C = 1;
    while (C <= N)
    {
        cout << "Case " << C << ":\n";
        C++;

        // cost array
        for (int i = 0; i < 36; i++)
        {
            cin >> tmp;
            numCost[i] = tmp;
        }
        cin >> n;
        while (n--)
        {
            cin >> num;
            tmpNum = num;
            cout << "Cheapest base(s) for number " << num << ":";
            // bases test
            minCost = INT_MAX;
            minCostBases.clear();
            for (int b = 2; b <= 36; b++)
            {
                tmp = 0;
                tmpNum = num;
                while (tmpNum>0)
                {
                    tmp += numCost[tmpNum%b];
                    tmpNum /= b;
                }
                if (tmp < minCost)
                {
                    minCost = tmp;
                    minCostBases.clear();
                    minCostBases.push_back(b);
                }
                else if(tmp == minCost)
                {
                    minCostBases.push_back(b);
                }
                else continue;
            }
            
            for (int i:minCostBases) cout << " " << i;
            cout << endl;
        }

        cout << "\n";
    }

    return 0;
}