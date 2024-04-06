#include <iostream>
#include <vector>

using namespace std;

// 問題: 為什麼bubble sort能確保optimal solution?

int bubbleSortSteps(vector<int>& vec) {
    int steps = 0;
    
    for (int i = vec.size()-1;i > 0;i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (vec[j] > vec[j+1])
            {
                swap(vec[j], vec[j+1]);
                steps++;
            }
        }
    }

    return steps;
}

int main() {
    int n, trL, tmp;
    string str;
    vector<int> vec;
    
    cin >> n;
    for (; n>0; n--)
    {
        cin >> trL;
        for (int i = 0; i < trL; i++)
        {
            cin >> tmp;
            vec.push_back(tmp);
        }
        cout << "Optimal train swapping takes " << bubbleSortSteps(vec) << " swaps.\n";
        vec.clear();
    }
    
    return 0;
}