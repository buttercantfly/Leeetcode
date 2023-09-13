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
    Start:
    TreeNode* convertBST(TreeNode* root) 

    End:
    if !root return nullptr;

    Process:
    if(root->left) {
        root->val += convertBST(TreeNode* root->left)->val;
    }
    
    if(root->right) {
        root->val += convertBST(TreeNode* root->right)->val;
    }

    return root;

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
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        converter(root, 0);
        return root;
    }
    int converter(TreeNode* node, int last_val) {
        if (!node) return 0;
        if (node->right) node->val += converter(node->right, last_val);
        else node->val += last_val;
        
        if (node->left) return converter(node->left, node->val);
        else return node->val;
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