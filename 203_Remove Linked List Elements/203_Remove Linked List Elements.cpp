#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note:
    可以先設想執行一遍，去找出所以"問題點"，也可以說癥結點
    再用code一個一個組織解決方法。
    => 如此題就有兩個癥結點，
    第一個是如何刪除頭節點?第二個則是怎樣刪除中間節點而不刪到結點之間斷掉?

improve:
    查一下linked list是怎麼declare的，尤其是怎樣一次放入多個nodes

*/

// Definition for singly-linked list.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Class Solution copy here

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        //刪除頭結點
        while (head && head->val == val)
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        
        ListNode* cur_node = head;

        //刪除中間節點
        while(cur_node && cur_node->next)// while (head->next != NULL)
        {
            if(cur_node->next->val == val)
            {
                ListNode* tmp = cur_node->next;
                cur_node->next = cur_node->next->next;
                delete tmp;
            }
            else
            {
                cur_node = cur_node->next;
            }
        }

        return head;
    }
};

// test function

/************* 不知道怎麼寫test code = = 底下跑不動 *************/

int main()
{
    // given values
    vector<int> nums = {1,2,6,3,4,5,6};
    int val = 6;
    ListNode h = ListNode(nums[0]);
    ListNode* head = &h;
    ListNode* cur  = head;
    for(int i = 1;i < nums.size();i++){
        ListNode k = ListNode(nums[i]);
        cur->next = &k;
        cur = cur->next;
    }

    // call solution function
    Solution s;
    s.removeElements(head, val);

    cur = head;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }

    return 0;
}
