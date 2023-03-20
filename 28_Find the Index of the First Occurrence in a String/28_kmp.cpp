#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

/*
note: 
    KMP 先從 brute force method去想
    其主要理念就是先觀察substring的prefix length
    以省去重複的檢查
    [abcdefgabcdggggg]
    [       abcd]

    難點其實就是在建立prefix table

    [aaabaaaaaaab]
    [012012333334]
    => 當prefix錯誤時要從2重新開始找?
    => 不斷的重找 => complexity會太大?
    [aaaaabaaaaaaaaaab]


    [abababckkkkkkabababababa]
    [001234000000012345656565]
    => 在後面字串ababa是與前面重複的
    => 我們可以把後面找prefix想成用前面的substring擴張

    [後面的string]
    [...........]
    [ababab] => [abab]
    [001234] prefix
    [012345] index
    => 如果斷在b4後面一個的話就表示前面abab1234=開頭1234
    => 等於可以拉到index = 4的地方繼續查

    ###############################################
    Z-Function or Rabin-Karp 也可以解決substring問題
    ###############################################

improve:
    
*/

// Class Solution copy here
class Solution {
public:
    int strStr(string haystack, string needle) {
        // first create prefix table

        int needle_size = needle.size();
        int haystack_size = haystack.size();

        vector<int> prefix_table(needle_size, 0);

        int count; // prefix length
        int j;     // 位移
        int tmp;   // 基準位
        
        // prefix table真的有夠麻煩 = =
        // i   為write index 和 初始基準位
        // tmp 為實際使用基準位 => tmp+j vs j
        
        for (int i = 1; i < needle_size; i++)
        {
            count = 0;
            j = 0;
            tmp = i;
            while (needle[tmp+j] == needle[j] && i < needle_size)
            {
                count++;
                prefix_table[i] = count;
                i++;
                j++;

                // 中斷時檢查是否有前綴
                if (needle[tmp+j] != needle[j] && prefix_table[i-1]!=0)
                {
                    count = prefix_table[j-1];
                    j = prefix_table[j-1]; // 將j移到對應的prefix index
                    tmp = i-j; // tmp同時往前移
                }
            }
        }

        // second run through haystack
        
        for (int i = 0; i < haystack_size; i++)
        {
            if (haystack_size - i < needle_size) break;

            if (haystack[i] == needle[0])
            {
                int j = 0;
                while (j < needle_size && haystack[i+j] == needle[j]) j++;

                if (j == needle_size) return i;
                else i += j - prefix_table[j-1] - 1; // i = 1 + 4 - 0 - 1
            }
        }

        return -1;
    }
};

// test function
int main(){
    // given values
    string haystack = "ababcaababcaabc";
    string needle = "ababcaabc";

    // call solution function
    
    Solution sol;
    int ans = sol.strStr(haystack, needle);

    // print out answers 
    cout << ans;
    

    return 0;
}