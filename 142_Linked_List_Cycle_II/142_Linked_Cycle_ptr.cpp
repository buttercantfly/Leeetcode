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
    2. 看解答QQ => 雙指針法
        (a) 確認是否有環 => slow, fast ptr 慢走一步 快走兩步
            *** 
            slow是走一步，其实相对于slow来说，
            fast是**一个节点一个节点**的靠近slow的，
            所以fast一定可以和slow重合。
            ***
            => 相遇時即可確認為有環

        (b) 接著從此點出發，再執行slow fast ptr
            ***
            下次相遇時即是環的起點
            ***
            => 詳見leetcode 142

    # 雙指針法能將演算法將低O(N)

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