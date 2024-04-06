#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

// 先比較大小 再比較字元
bool compareMapValue(pair<char, int> l, pair<char, int> r) {
    if(l.second != r.second) return l.second > r.second;
    else return l.first < r.first;
}

int main() {
    int n;
    string str;
    map<char, int> mp;
    cin >> n;
    getline(cin, str); // 這邊是為了將\n換行符號弄掉
    while (n-- && getline(cin, str))
    {
        for (char c:str)
        {
            if (c < 91 && c > 64)
            {
                mp[c]++;
            }
            else if(c < 123 && c > 96)
            {
                mp[c-32]++;
            }
        }
    }

    vector<pair<char, int>> vec;

    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        vec.push_back(pair<char, int>(it->first, it->second));
    }
    
    sort(vec.begin(), vec.end(), compareMapValue);

    for (pair<char, int> pr:vec)
    {
        cout << pr.first << ' ' << pr.second << "\n";
    }

    return 0;
}