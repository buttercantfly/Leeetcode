#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <math.h>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
question:
note:
    用unordered_set去檢查是否遍歷過該node
    not a good way to do so

improve:
******************************************
    可以更往下跑一個node(到null)
    然後將往左探查這個行為每次操作都跑一次
    (若往左沒有則回到上一層)
    這樣能避免重複向右探查

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
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        stack<TreeNode*> stk;
        unordered_set<TreeNode*> set;
        stk.push(root);

        TreeNode* cur_node;
        int cur_sum = 0;

        while (!stk.empty())
        {
            cur_node = stk.top();
            if (cur_node->right && !set.count(cur_node->right))
            {
                stk.push(cur_node->right);
            }
            else
            {
                cur_sum += cur_node->val;
                cur_node->val = cur_sum;
                set.insert(cur_node);
                stk.pop();

                if (cur_node->left)
                {
                    stk.push(cur_node->left);
                }
            }
        }
        
        return root;
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