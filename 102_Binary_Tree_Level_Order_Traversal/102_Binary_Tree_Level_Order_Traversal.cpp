#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

/*
question:
    Given the root of a binary tree,
    return the level order traversal of its nodes' values.
    (i.e., from left to right, level by level).
note:
    簡單講就是一層一個vector
    => 簡單用FIFO(queue)處理就好

    ***怎麼處理層數的問題?***
    用雙層的迴圈去處理
    外層代表層數 (一次一個vector)
    裡層處理每層的push pop push_back等

    重點就是層數 其他還好

improve:

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

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ret;
        queue<TreeNode*> que;
        int level = 0;
        if(root != NULL) que.push(root);
        while (!que.empty())
        {
            int size = que.size(); 
            vector<int> vec;

            for (int i = 0; i < size; i++)
            {
                if (que.front()->left) que.push(que.front()->left);
                if (que.front()->right) que.push(que.front()->right);
                vec.push_back(que.front()->val);
                que.pop();
            }
            
            ret.push_back(vec);
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};

// test function
int main()
{
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