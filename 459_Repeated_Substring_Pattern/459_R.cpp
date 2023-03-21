#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    xxxxxxx
    1. 一個一個檢查substring
    [aaa]
    [ababab]
    [abcabcabc]
    => 組合都是由開頭的substring重複複製 (不會有多一個或怎樣的字符在前面)
    => 問題簡化為檢查1~n/2長度的substring是否有符合題意重複?
    xxxxxxx

    2. 用prefix table來做
    [aaa]
    [012]
    [ababab]
    [001234]
    [abcabcabc]
    [000123456]
    => prefix table 都會長成這樣?
    => no

    [aaabaaabaaab]
    [012012345678]
    => 標記最後一個出現的零 (substring的結尾) => no
    => 可以得到substring長度 (結尾index+1)
    => 檢查是否是12345...67
    => 並且last num可以被substring長度整除

    [aaabaa aaabaa aaab a a ]
    [012012 333456 789101112]
    [ababa  ababa ababa ]
    [00123  12345 678910]

    [aaabaaabaaab]
    [012012345678]
    [aaabaaaaba]
    [0120123345]
    [ababbababb]
    [0012012345]
    => what are the same? 
    => 尾巴的數字能被substring length 整除
    => 且尾巴的數字要是最大的
    [ababbabb ababbabb]
    [00120120]

    

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // first create prefix table

        int s_size = s.size();

        vector<int> prefix_table(s_size, 0);

        int count; // prefix length
        int j;     // 位移
        int tmp;   // 基準位
        
        // prefix table真的有夠麻煩 = =
        // i   為write index 和 初始基準位
        // tmp 為實際使用基準位 => tmp+j vs j
        
        for (int i = 1; i < s_size; i++)
        {
            count = 0;
            j = 0;
            tmp = i;
            while (s[tmp+j] == s[j] && i < s_size)
            {
                count++;
                prefix_table[i] = count;
                i++;
                j++;

                // 中斷時檢查是否有前綴
                if (s[tmp+j] != s[j] && prefix_table[i-1]!=0)
                {
                    count = prefix_table[j-1];
                    j = prefix_table[j-1]; // 將j移到對應的prefix index
                    tmp = i-j; // tmp同時往前移
                    
                    // 問題：此跳會導致少檢查i位置上與0位置的比較
                    if (s[tmp+j] != s[j] && s[i] == s[0]) // 若跳過去還是錯誤，則檢查是否可以從頭計算
                    {
                        count = 0;
                        tmp   = tmp + j;
                        j     = 0;
                    }
                }
            }
        }

        int max  = prefix_table.back();
        int subl = s_size - max;
        if (max%subl != 0 || max == 0) return false;
        else return true;
    }
};

// test function
int main(){
    // given values
    string s = "ababababababaababababababaababababababa";

    // call solution function
    
    Solution sol;
    int ans = sol.repeatedSubstringPattern(s);

    // print out answers 
    cout << ans;

    return 0;
}