#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    把句子中的字序翻轉
    1. 找到字序
    2. reverse

    * at least one word in s

    => 雙指針法 (四指針?)
    1. 兩個指針找頭尾的字
    2. 過程中紀錄頭尾字起始的位置
    3. swap
    NO 太複雜

    難點: 
    1. 只能用O(1) extra space
    => 拓展格子? 
    2. 前面的word要怎麼擺

    => 直接全部reverse後再將字符翻轉並且去掉空格
    BINGO GOOD JOB

improve:
    
    **************************************************
    erase在string中的複雜度很高(每次都要遍歷)O(n)不能亂用
    **************************************************

*/

// Class Solution copy here
class Solution {
public:
    string reverseWords(string s) {
        int or_size = s.size(); // original size of s
        
        // 整個字串翻轉
        for (int i = 0; i < or_size/2; i++)
        {
            swap(s[i], s[or_size - 1 - i]);
        }

        // 找字+翻轉
        int count = 0;
        while (count < or_size)
        {
            if(s[count] != ' ')
            {
                int start = count;
                while (s[count] != ' ' && count < or_size) count++;
                
                for (int i = 0; i < (count - start)/2; i++)
                {
                    swap(s[start + i], s[count - 1 - i]);
                }
            }
            
            count++;
        }

        // 去空白 two pointer method
        int slow = 0; // 確定的位置
        int fast = 0; // 找字符

        while (fast < or_size && slow < or_size)
        {
            while (s[fast] == ' ' && fast < or_size) 
            {
                fast++;
            }

            while (s[fast] != ' ' && fast < or_size)
            {
                swap(s[slow], s[fast]);
                slow++;
                fast++;

                if(s[fast] == ' ' || fast >= or_size)
                {
                    s[slow] = ' ';
                    slow++;
                }
            }
        }

        s.resize(slow - 1);
        
        return s;
    }
};

// test function
int main(){
    // given values
    string s = "  hello world  ";

    // call solution function
    Solution sol;
    string ans = sol.reverseWords(s);

    // print out answers 
    cout << ans << "/";

    return 0;
}