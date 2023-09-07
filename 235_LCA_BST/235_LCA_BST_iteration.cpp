#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <math.h>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
question:
note:
    本題解法利用"high<lca<high"的特性

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
    int low;
    int high;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;

        if (p->val > q->val)
        {
            high = p->val;
            low  = q->val;
        }
        else
        {
            low  = p->val;
            high = q->val;
        }
        
        while (cur->val > high || cur->val < low)
        {
            if (cur->val > high)
            {
                cur = cur->left;
            }
            if (cur->val < low)
            {
                cur = cur->right;
            }
            if (!cur) return nullptr;
        }
        
        return cur;
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

    vector<int> vec = {1, 2};
    Builder builder;
    TreeNode* root = builder.build_tree(vec, 1);
    
    preorder_print(root); 

    return 0;
}