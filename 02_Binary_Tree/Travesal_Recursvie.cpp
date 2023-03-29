#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    首先設計[遞迴]必須要緊抓的三個要素
    1. parameters and return value
    => 什麼parameter會傳下去，以及傳下去後會return什麼

    2. terminate situation
    => 什麼時候會到底

    3. logic of single layer
    => 每次call function要做什麼

    設計traevsal的recursive function
    => 
    1. void traversal(TreeNode* cur, vector<int>& vec)
        => vec做為要寫入的vector

    2. if (cur == NULL) return;
        => 到底的時候停止

    3. Logic of Single Layer # 用子樹去想(或三個node去想)
        Review:
        preorder   中左右
        inorder    左中右
        postoerder 左右中

        a. preorder
            vec.push_back(cur->val);    // 中 寫入
            traversal(cur->left, vec);  // 左
            traversal(cur->right, vec); // 右

        b. inorder
            traversal(cur->left, vec);  // 左
            vec.push_back(cur->val);    // 中 寫入
            traversal(cur->right, vec); // 右

        c. postorder
            traversal(cur->left, vec);  // 左
            traversal(cur->right, vec); // 右
            vec.push_back(cur->val);    // 中 寫入

improve:
    
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Class Solution copy here
class PreorderSolution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);    // 中
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};


class InorderSolution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal(cur->left, vec);  // 左
        vec.push_back(cur->val);    // 中 寫入
        traversal(cur->right, vec); // 右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 中(HEAD of tree)一定是在最後 => 左右"中"
// 用這個想法出發
// 所以是先遍歷 左子樹 再 遍歷 右子樹 最後才寫入cur
class PostorderSolution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
        vec.push_back(cur->val);    // 中 寫入
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

// test function
int main(){

    return 0;
}