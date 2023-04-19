#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <math.h>
#include <algorithm>
using namespace std;

/*
question:
    確認樹是否為平衡二元樹

note:
    找

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

// 用深度去做是錯的
// => balanced tree是看高度
/*
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        pair<int, int> result = height(root);
        if (result.second - result.first > 1) return false;
        else return true;
    }

    pair<int, int> height(TreeNode* root) {
        if (!root) return pair<int, int>(0,0);
        
        pair<int, int> ret;
        ret.first  = 1 + min(height(root->left).first, height(root->right).first);
        ret.second = 1 + max(height(root->left).second, height(root->right).second);
        return ret;
    }
};
*/

class Solution {
public:
    int getHeight(TreeNode* node) {
        if (!node) return 0;
        int l = getHeight(node->left);
        int r = getHeight(node->right);
        if (l == -1 || r == -1 || abs(l-r) > 1) return -1;
        else return 1 + max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (getHeight(root) == -1) return false;
        else return true;
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