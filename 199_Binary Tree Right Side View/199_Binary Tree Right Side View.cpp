#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

/*
question:

note: 
    還是有每層都遍歷過
    => 然後將每層的最右側(也就是最後放進每層的node)
    => 放進ret裡面即可

improve:
    不用一直更新rightest
    可以看i是不是size - 1(也就是最後一個)
    去抓數值就好
*/

// Class Solution copy here

// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);

        while (!que.empty())
        {
            int level_size = que.size();
            // int rightest;
            for (int i = 0; i < level_size; i++)
            {
                if (que.front()->left) que.push(que.front()->left);
                if (que.front()->right) que.push(que.front()->right);
                // rightest = que.front()->val;
                // 直接檢查是不是最後一個就好(last node is the rightest node)
                if (i == level_size - 1) ret.push_back(que.front()->val);
                que.pop();
            }
            // ret.push_back(rightest);
        }

        return ret;
    }
};

// test function
int main(){
    // given values
    vector<int> nums = {0};
    int target = 0;
    string s = "";

    // call solution function
    /*
    Solution sol;
    int ans = sol.function("arguments");

    // print out answers 
    cout << ans;
    */

    return 0;
}