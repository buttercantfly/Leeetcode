#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
note: 
    1. 用hash map存指標 O(N) memory
        => c++ 中使用unodered_map (使用雜湊表實現)
        => map 則是使用紅黑樹實現bst (非hash map)
    2. 
improve:
    
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
        if(!head) return nullptr;
        
        unordered_set<ListNode*> set;
        ListNode* tmp = head;
        
        while (tmp->next)
        {
            set.insert(tmp);
            if (set.count(tmp->next)) return tmp->next;
        }

        return nullptr;
    }
};

// test function
int main(){
    
}