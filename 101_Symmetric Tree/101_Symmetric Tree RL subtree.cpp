#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

/*
question:
note:
    兩種解法
    1. 分左右子樹 
        左子樹 中左右 
        右子樹 中右左
    
    2. level traversal
        去看每一層是不是都互為相反順序
        = = 不可行
        如果遇到 null 會出事
        如下 第三層 n 3 n 3 非對稱，但level會視為 3 3
        [1,2,2,null,3,null,3]

        把null當作int max呢? (node val沒那麼大)
    
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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // 等有空來寫ㄅ
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
        if (vec[position-1] == INT_MIN) return nullptr;
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

    vector<int> vec = {1,2,2,3,3,3,3};
    Builder builder;
    TreeNode* root = builder.build_tree(vec, 1);
    Solution sol;
    cout << sol.isSymmetric(root) << endl;

    preorder_print(root); 

    return 0;
}