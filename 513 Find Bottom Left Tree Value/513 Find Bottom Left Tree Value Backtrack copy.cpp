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
    重點是找到最底層 然後再看最左
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
// 層序遍歷?
// bfs => recursive
// 如果把層數當作參數呢？

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ret;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            int level_size = que.size();
            ret = que.front()->val;
            for (int i = 0; i < level_size; i++)
            {
                TreeNode* tmp = que.front();
                if (tmp->left)  que.push(tmp->left);
                if (tmp->right) que.push(tmp->right);
                que.pop();
            }
        }
        return ret;
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