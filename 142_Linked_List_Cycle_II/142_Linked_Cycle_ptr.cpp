#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    1. 用hash map存指標 O(N) memory
        => c++ 中使用unodered_map (使用雜湊表實現)
        => map 則是使用紅黑樹實現bst (非hash map)
    2. 看解答QQ
        (a) 確認是否有環 => slow, fast ptr 慢走一步 快走兩步
        (b) 找到環的起點
            => 詳見leetcode 142

improve:
    還是要注意 nullptr access 的情況 (if檢查)
    
*/


// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        while (fastptr->next && fastptr->next->next) // fast走比較快，用來檢查有沒有結尾
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
            if(slowptr == fastptr) {
                slowptr = head;
                while (slowptr != fastptr)
                {
                    slowptr = slowptr->next;
                    fastptr = fastptr->next;
                }
                return slowptr;
            }
        }
        return nullptr;
    }
};

// test function
int main(){

}