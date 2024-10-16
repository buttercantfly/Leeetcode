#include <iostream>
#include <queue>
#include <vector>
#include <string>

#define pr pair<int, char>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string str = "";
        priority_queue<pr> maxHeap;
        maxHeap.push(pr(a,'a'));
        maxHeap.push(pr(b,'b'));
        maxHeap.push(pr(c,'c'));

        // aacaacaacaa

        pr lastMax(0,'x');
        pr curMax;
        
        while(true) {            
            curMax = maxHeap.top(); // 取得curMax
            if (curMax.first == 0) break; // 若能用的char為0就停止

            str += curMax.second;
            curMax.first--;
            maxHeap.pop(); // 將curMax pop out
            if (lastMax.second != 'x' && curMax.second != lastMax.second && lastMax.first > 0) maxHeap.push(lastMax); // 將前一個推回heap中
            
            if (curMax.second != lastMax.second) {
                maxHeap.push(pr(curMax.first,curMax.second));
            }
            lastMax = curMax;
        }

        return str;
    }
};