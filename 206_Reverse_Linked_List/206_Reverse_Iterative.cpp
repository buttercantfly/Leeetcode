#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    少了這行:
    cur_n->next = nullptr;
    忘記尾巴的next會是nullptr
    => 缺乏完全的資料結構概念
    
improve:
    Follow up: A linked list can be reversed either iteratively or recursively. 
    Could you implement both?
*/


// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head; // 空表格也回傳head
        if(!head->next) return head; // 單個node的list不須操作

        ListNode* cur_n = head;
        ListNode* next_n = head->next;
        ListNode* nnext_n;

        cur_n->next = nullptr;

        while(next_n->next)
        {
            nnext_n = next_n->next;
            next_n->next = cur_n;
            cur_n  = next_n;
            next_n = nnext_n;
        }

        next_n->next = cur_n;
        return next_n;
    }
};


// test function
int main(){
    // given values
    vector<int> nums = {0};
    int target = 0;

    // call solution function
    Solution s;
    int ans;// = s.function("arguments");

    // print out answers 
    cout << ans;

    return 0;
}