#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

/*
question:

note: 
    與stack結構FILO相關
    因為有檢驗[是否存在]
    因此選用unordered_map方便檢查

improve:
    實際上在做的時候最好用多個判斷式執行，在空間和速度上都較快

*/

// Class Solution copy here
class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        unordered_map<char, char> map;

        map.insert(pair<char, char>('(',' '));
        map.insert(pair<char, char>(')','('));
        map.insert(pair<char, char>('[',' '));
        map.insert(pair<char, char>(']','['));
        map.insert(pair<char, char>('{',' '));
        map.insert(pair<char, char>('}','{'));        
        
        for (char i:s)
        {
            if (map.count(i))
            {
                if (!str.empty() && map[i] == str.top()) str.pop();
                else str.push(i);
            }
        }

        return str.empty();
    }
};

// test function
int main(){
    // given values
    string s = "][][";

    // call solution function
    
    Solution sol;
    bool ans = sol.isValid(s);

    // print out answers 
    cout << ans;
    

    return 0;
}