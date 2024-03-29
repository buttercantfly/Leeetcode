#include <iostream>
#include <string>
#include <vector>
#include <deque>
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return minD(root);
    }

    int minD(TreeNode* root) {
        if (root == nullptr) return INT_MAX/2; 
        // 如果丟null 進minD 意味這邊不是leaf => 排除在所有的最小路徑中
        // 這邊使用的是INT_MAX/2 (/2是怕overflow的狀況)
        else if (root->left == nullptr && root->right == nullptr) return 1; // 到葉子回傳
        
        return min(minD(root->left)+1, minD(root->right)+1);
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