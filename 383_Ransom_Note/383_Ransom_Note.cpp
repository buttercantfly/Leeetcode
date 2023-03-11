#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
note: 
    把magazine中的每個字元加入map<string, int> values為magazine中有幾個key
    再go through ransomnote一遍，每個字value--

improve:
    速度有點久?
    => 因為使用的是map而不是手做array，因此會耗費較多時間(不過空間會比較少)
*/

// Class Solution copy here
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for(char c: magazine) {
            map[c]++;
        }

        for(char d: ransomNote) {
            map[d]--;
            if(map[d] < 0) return false;
        }

        return true;
    }
};