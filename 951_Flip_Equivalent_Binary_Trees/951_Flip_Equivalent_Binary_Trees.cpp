#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    recursive
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return checker(root1, root2);
    }

private:
    bool checker(TreeNode* node1, TreeNode* node2) {
        if (!node1 && !node2) return true;
        // 這個檢驗nulltpr的方式可以記一下 先檢查就可以比value了
        if (!node1 || !node2 || node1->val != node2->val) return false;

        return (checker(node1->left, node2->left) || checker(node1->left, node2->right)) &&
               (checker(node1->right, node2->right) || checker(node1->right, node2->left));
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