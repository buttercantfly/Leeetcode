#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <math.h>
#include <algorithm>
using namespace std;

/*
question:
note:
    
improve:
    本題跟解答稍不同
    採用判斷式處理 不宣告造成時間下降記憶體增加(尤其是用遞迴方式做的情況之下)

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
// Recursive 
// 用父輩去計算value

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        // 原本是宣告一個int 儲存左leaf值，但在遞迴中宣告會使時間跟記憶體都變高不少
        // 因此改成用判斷式去處理
        if (root->left && !root->left->left && !root->left->right) 
            return root->left->val + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
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