#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    移除"倒數"第n個node
    => 速度? one pass?

    1. 建一個n+1的queue，不斷塞node進去，直到到尾八，就把queue的最後第二個node刪除
        => 耗費大量空間
    2. 雙指標法
        一個紀錄倒數第n+1個node
        一個不斷向前直到尾巴
    
    Problem occur:
        當刪到head node時非常麻煩
        => 解法: 多加一個dummy head方便刪除

    => 冷靜下來一個一個想 不要一直瘋狂try run去試 很容易越搞越亂
improve:

    memory使用較多?
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummyhead = new ListNode(0, head);
        ListNode* Nth = dummyhead;
        ListNode* last = head;
        int count = 1;
        while (last->next && count < n)
        {
            last = last->next;
            count++;
        }

        while (last->next)
        {
            last = last->next;
            Nth  = Nth->next;
        }

        if(Nth->next){
            ListNode* tmp = Nth->next->next;
            delete Nth->next;
            Nth->next = tmp;            
        }
        else{
            delete Nth->next;
            Nth->next = nullptr;
        }

        return dummyhead->next;
    }
};