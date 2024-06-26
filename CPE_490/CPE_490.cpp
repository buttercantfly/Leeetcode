#include<iostream>
#include<vector>

using namespace std;

// improve: 可以在讀入string時就先監測最長的長度，這樣就不需要每個for迴圈都檢查一次

int main() {
    vector<string> vec;
    string str;

    while (getline(cin, str))
    {
        vec.push_back(str);
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = vec.size()-1; j >= 0; j--)
        {
            if (i < vec.at(j).size())
            {
                cout << vec.at(j)[i];
            }
            else
            {
                cout << ' ';
            }
        }
        
        int k = 0;
        while (i >= vec.at(k).size()-1)
        {
            k++;
            if (k == vec.size()) return 0;
        }

        cout << endl;
    }
    
    return 0;
}