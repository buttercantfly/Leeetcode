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

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> ret;
        que.push(root);
        if(!root) return ret;
        while (!que.empty())
        {
            int level_size = que.size();
            int level_max  = INT_MIN;
            for (int i = 0; i < level_size; i++)
            {
                if(que.front()->left) que.push(que.front()->left);
                if(que.front()->right) que.push(que.front()->right);
                level_max = max(level_max, que.front()->val);
                que.pop();
            }
            ret.push_back(level_max);
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