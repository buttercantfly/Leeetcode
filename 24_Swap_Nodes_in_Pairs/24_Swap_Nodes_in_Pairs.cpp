#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    三個步驟是對的
    但每次寫這個都很龐雜(node =0,1,2,3等等初始情況)
    有什麼能解決這種要設一堆邊界條件的想法嗎?

improve:
    不需要用recursive的方式，用iterative的方式就好
    其實我寫到這樣跟題解的邏輯一模一樣，用recursive還要傳遞mem導致時間/空間耗費
    
    ***當遇到subfunciton要弄一堆條件時就可以想是不是iterative更好***

*/

// Class Solution copy here


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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        
        ListNode* tmp = head;
        if(!tmp->next) return head;
        else if(!tmp->next->next) {
            head = tmp->next;
            swap(tmp, tmp->next, nullptr);
        }
        else{
            head = tmp->next;
            swap(tmp, tmp->next, tmp->next->next);
        }

        return head;
    }
    
    void swap(ListNode* left, ListNode* right, ListNode* mem){
        if(!mem){
            left->next = nullptr;
            right->next = left;
            return;
        }
        else if(!mem->next){
            left->next = mem;
            right->next = left;
            return;
        }
        else{
            left->next = right->next->next;
            right->next = left;
            swap(mem, mem->next, mem->next->next);
        }
    }
};


// test function
int main(){
    // given values
    vector<int> nums = {0};
    int target = 0;

    // call solution function
    Solution s;
    int ans = s.function("arguments");

    // print out answers 
    cout << ans;

    return 0;
}