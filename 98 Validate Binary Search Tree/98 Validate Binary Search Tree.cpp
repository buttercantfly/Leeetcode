#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

/*
question:
note:
    iterative: 用中序左中右

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
// 中序遍例 => 直接確認結果
// TLE
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        TreeNode* pre = NULL; // 用來比較的node
        while (cur|| !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;  // 左
            } else { // 進到else就會pop一個 => 可以存pre作為比較
                cur = stk.top();  // 中
                stk.pop();
                if (pre != NULL && cur->val <= pre->val) return false; // 確認節點是否符合規則
                pre = cur; //保存前一个访问的结点
                cur = cur->right;  // 右
            }
        }
        return true;
    }
};

// test function
class Builder
{
private:
    /* data */
public:
    TreeNode* build_tree(vector<int>& vec, int position)
    {
        if(position > vec.size()) return nullptr;
        TreeNode* root = new TreeNode(vec[position - 1]);
        root->left  = build_tree(vec, position*2);     
        root->right = build_tree(vec, position*2+1);

        return root;
    }
};

// preorder print
void preorder_print(TreeNode* root){
    cout << root->val;
    if(root->left) preorder_print(root->left);
    if(root->right) preorder_print(root->right);
}

int main(){

    vector<int> vec = {1,2,3,4,5,6,7};
    Builder builder;
    TreeNode* root = builder.build_tree(vec, 1);
    
    preorder_print(root); 

    return 0;
}