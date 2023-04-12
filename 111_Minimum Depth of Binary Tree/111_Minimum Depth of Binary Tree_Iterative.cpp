#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

/*
question:

note: 
    當找到leaf node就可以停了

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
    int minDepth(TreeNode* root) {
        int minD = 1;
        queue<TreeNode*> que;
        if (root == nullptr) return 0;
        
        que.push(root);
        while (!que.empty())
        {
            int level_size = que.size();
            
            for (int i = 0; i < level_size; i++)
            {
                if (!que.front()->left && !que.front()->right)
                {
                    return minD + 1;
                }
                
                if (que.front()->left) que.push(que.front()->left);
                if (que.front()->right) que.push(que.front()->right);
                
                que.pop();
            }

            minD++;
        }
        return minD;
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