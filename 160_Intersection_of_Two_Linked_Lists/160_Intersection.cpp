#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    Could you write a solution that runs in O(m + n) time and use only O(1) memory?
    => how?

    1. hash儲存A的ptrs 再用B的ptr找有沒有一樣的 
        => time O(m+n) but space O(m+n) too
    2. 想不出來

    ********************解答**********************
        利用「尾巴一定一樣長」的想法
        => 因為指到同一個node之後就都一樣了
        => 較短的推到尾巴貼其較長的
        => 從同樣長度的地方開始比較就好

improve:
    解答基本就是最佳解ㄌ
    可以進步的應該是一些小地方
    比如怎麼推到齊尾
    應該能減少一些非必要的變數

*/

/* Definition for singly-linked list.*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        
        int lengthA = 1; // head 本身就一個
        int lengthB = 1;
        
        ListNode* tmp = headA;
        while (tmp->next)
        {
            tmp = tmp->next;
            lengthA++;
        }

        tmp = headB;
        while (tmp->next)
        {
            tmp = tmp->next;
            lengthB++;
        }

        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        if(lengthA > lengthB)
        {
            int gap = lengthA - lengthB;
            for(int i = 0;i < gap;i++)
            {
                ptrA = ptrA->next;
            }
        }
        else
        {
            int gap = lengthB - lengthA;
            for(int i = 0;i < gap;i++)
            {
                ptrB = ptrB->next;
            }
        }

        while (ptrA->next)
        {
            if(ptrA == ptrB) return ptrA;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        if(ptrA == ptrB) return ptrA;
        
        return NULL;
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