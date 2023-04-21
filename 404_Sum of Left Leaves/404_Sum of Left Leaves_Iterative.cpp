#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;

/*
question:
note:
    
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
// Recursive 
// 用父輩去計算value

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* cur;
        int sum = 0;
        while (!stk.empty())
        {
            cur = stk.top();
            stk.pop();
            if (cur->left) stk.push(cur->left);
            if (cur->right) stk.push(cur->right);
            if (cur->left && !cur->left->left && !cur->left->right) 
                sum += cur->left->val;
        }
        return sum;
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