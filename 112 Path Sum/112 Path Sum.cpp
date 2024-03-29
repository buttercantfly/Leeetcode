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
    講義解答是用pair

improve:
    其實這個利用!root回傳false的情況就好了
    就不用那麼多if else if
    但構思的方式是好的 從複雜到精簡 不要追求精簡導致不知道問題在那
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        stack<TreeNode*> n_stk;
        stack<int> s_stk;
        n_stk.push(root);
        s_stk.push(root->val);

        while (!n_stk.empty())
        {
            TreeNode* cur = n_stk.top();
            int cur_s = s_stk.top();
            n_stk.pop();
            s_stk.pop();

            if (!cur->left && !cur->right && cur_s == targetSum) return true;
            
            if (cur->right)
            {
                n_stk.push(cur->right);
                s_stk.push(cur_s + cur->right->val);
            }
            if (cur->left)
            {
                n_stk.push(cur->left);
                s_stk.push(cur_s + cur->left->val);
            }
        }
        
        return false;
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