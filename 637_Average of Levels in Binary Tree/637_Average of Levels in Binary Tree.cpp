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
    有點慢?
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        vector<double> ret;
        que.push(root);
        if(root != NULL) TreeNode* cur = root;
        else return ret;
        while (!que.empty())
        {
            double level_size = que.size();
            double level_sum  = 0.0;
            for (double i = 0; i < level_size; i++)
            {
                if(que.front()->left) que.push(que.front()->left);
                if(que.front()->right) que.push(que.front()->right);
                level_sum += que.front()->val;
                que.pop();
            }
            ret.push_back(level_sum/level_size);
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