#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    recursive 其實簡單想
    就是「不斷地執行同樣的操作」
    => 不斷call 同個funciton/method

improve:
    Follow up: A linked list can be reversed either iteratively or recursively. 
    Could you implement both?

    => iterative 快 但code比較複雜
    => recursive 慢 但code比較簡單
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
        if (!head) return head;
        
        return reverse(nullptr, head);
    }

    ListNode* tmp;

    ListNode* reverse(ListNode* cur_n, ListNode* next_n) {
        tmp = next_n->next;
        next_n->next = cur_n;

        if(!tmp) return next_n;
        else return reverse(next_n, tmp);
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